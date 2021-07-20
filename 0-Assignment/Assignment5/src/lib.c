#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "lib.h"

/********************************************************************
 * Definitions
********************************************************************/
/* Structure node_t define type of node what is the part of linked list */
typedef struct ll
{
    uint8_t data;
    struct ll *next;
} node_t; /* sizeof = 8 bytes */

/********************************************************************
 * Prototypes
********************************************************************/
static bool rm_element_array(uint8_t value);

/********************************************************************
 * Variables
********************************************************************/
uint8_t assignment4[20] = {};
node_t node[20] = {};
node_t *head = NULL;

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief Function initialize Array[20]
 *
 * @param   void
 * @return  void
 */
void lib_initArray(void)
{
    /* Variable i for counting purposes */
    uint8_t i = 0;

    for(i = 0; i < 20; i++)
    {
        assignment4[i] = 0xFFu;
    }

    return;
}

/**
 * @brief Function import element
 *
 * @param   value, position
 * @return  STATUS_CODE refer to define lib_importError_enum_t
 */
lib_importError_enum_t lib_importElement(uint8_t value, uint8_t position)
{
    /* Variable for return purposes */
    lib_importError_enum_t STATUS = IMPORT_SUCCESS;
    /* Variable for counting purposes */
    uint8_t i = 0;
    /* Variable indicates position node will be insert to linked list (auto sort low to high) */
    uint8_t countPos = 0;
    /* Variable will point to previous node */
    node_t *preNode = head;

    if(position > 19)
    {
        STATUS = ERROR_IMPORT_LOCATION_OUT;
    }
    else if(value > 100)
    {
        STATUS = ERROR_IMPORT_VALUE_OUT;
    }
    else if(assignment4[position] != 0xFFu)
    {
        STATUS = ERROR_IMPORT_LOCATION_IMPORTED;
    }
    else
    {
        for(i = 0; i < 20 && STATUS != ERROR_IMPORT_VALUE_EXIST; i++)
        {
            if(assignment4[i] == value)
            {
                STATUS = ERROR_IMPORT_VALUE_EXIST;
            }
            else if(assignment4[i] < value)
            {
                countPos++; /* indicate position = number element-in-array < value (auto sort low to high) */
            }
        }
    }

    if(STATUS == IMPORT_SUCCESS) /* if value and position satisfy the condition */
    {
        assignment4[position] = value;
        node[position].data = assignment4[position];
        if(head == NULL) /* if linked list not created yet */
        {
            head = &node[position];
            node[position].next = NULL;
        }
        else if(countPos == 0) /* insert to begin of linked list */
        {
            node[position].next = head;
            head = &node[position];
        }
        else /* insert to any position in linked list */
        {
            for(i = 1; i < countPos; i++)
            {
                preNode = preNode->next; /* indicate previous node */
            }
            node[position].next = preNode->next; /* relink */
            preNode->next = &node[position];     /* relink */
        }
    }

    return(STATUS);
}

/**
 * @brief Function remove element
 *
 * @param   value
 * @return  STATUS_CODE refer to define lib_removeError_enum_t
 */
lib_removeError_enum_t lib_removeElement(uint8_t value)
{
    /* Variable for return purposes */
    lib_removeError_enum_t STATUS = ERROR_REMOVE_VALUE_EXIST;
    /* Variable will point to previous node */
    node_t *preNode = head;
    /* Variable will point to remove Node */
    node_t *rmNode = NULL;

    if(value > 100)
    {
        STATUS = ERROR_REMOVE_VALUE_OUT;
    }
    else if(head == NULL)
    {
        STATUS = ERROR_REMOVE_EMPTY_ARRAY;
    }
    else if(head->data == value) /* remove first Node */
    {
        head = head->next;
        preNode->next = NULL;
        if(rm_element_array(value)) /* remove value in Array */
        {
            STATUS = REMOVE_SUCCESS;
        }
    }
    else
    {
        while(preNode->next != NULL && STATUS != REMOVE_SUCCESS) /* remove Node in middle lisked list */
        {
            if(preNode->next->data == value)
            {
                rmNode = preNode->next;         /* relink */
                preNode->next = rmNode->next;   /* relink */
                rmNode->next = NULL;
                if(rm_element_array(value)) /* remove value in Array */
                {
                    STATUS = REMOVE_SUCCESS;
                }
            }
            preNode = preNode->next;
            /* Case: Node is deleted is last Node */
            /* now preNode = NULL => Segmentation fault in next While() */
            if(preNode == NULL)
            {
                return(STATUS); /* I'm looking for an alternative */
            }
        }
    }

    return(STATUS);
}

/**
 * @brief Function print elements unsorted
 *
 * @param   void
 * @return  void
 */
void lib_print_Unsorted(void)
{
    /* Variable for counting purposes */
    uint8_t i = 0;

    for(i = 0; i < 20; i++)
    {
        if(assignment4[i] != 0xFFu)
        {
            printf("%hhu\t", assignment4[i]);
        }
    }
    printf("\n");

    return;
}

/**
 * @brief Function print elements sorted
 *
 * @param   void
 * @return  void
 */
void lib_print_Sorted(void)
{
    /* current point from first node to last node */
    node_t *curNode = head;

    while(curNode != NULL)
    {
        printf("%hhu\t", curNode->data);
        curNode = curNode->next;
    }
    printf("\n");

    return;
}

/**
 * @brief Function remove element in array
 *
 * @param   value
 * @return  STATUS_CODE: true = remove success / false
 */
 bool rm_element_array(uint8_t value)
 {
    /* Variable for return purposes */
    bool STATUS = false;
    /* Variable for counting purposes */
    uint8_t i = 0;

    for(i = 0; i < 20; i++)
    {
        if(assignment4[i] == value)
        {
            assignment4[i] = 0xFFu;
            STATUS = true;
        }
    }

    return(STATUS);
 }
