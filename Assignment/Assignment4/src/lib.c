#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief Function to compare first character of first name student
 * 
 * @param Pointer to current node, pointer to next node
 * @return true if current > index, false if current < index
 */
static bool sortFirstName(node_t *current, node_t *index)
{
    bool result = false;
    char cur = 0;
    char ind = 0;
    uint8_t i = 0;
    for(i = 0; i < 27; i++)
    {
        if(current->student.name[i] == ' ' && current->student.name[i + 1] != ' ')
        {
            cur = current->student.name[i + 1];
        }
        if(index->student.name[i] == ' ' && index->student.name[i + 1] != ' ')
        {
            ind = index->student.name[i + 1];
        }
    }
    if(cur > ind)
    {
        result = true;
    }

    return(result);
}

/**
 * @brief Function to check duplicate already exist code of student
 * 
 * @param Pointer to first node of linked list, code
 * @return true if duplicate / false if not
 */
static bool checkDuplicateCode(node_t *current, uint8_t code)
{
    bool result = false;
    while(current != NULL)
    {
        if(code == current->student.code)
        {
            result = true;
        }
        current = current->next;
    }

    return(result);
}

/**
 * @brief Function to print the entire linked list
 * 
 * @param Pointer to first node of linked list
 * @return void
 */
void printList(node_t *current)
{
    /* current point from first node to last node */
    while(current != NULL)
    {
        printf("%-5hhd%-25s%-15s\t%.2f\n", \
            current->student.code, current->student.name, current->student.account, current->student.score);
        current = current->next;
    }

    return;
}

/**
 * @brief Function to insert element to the begin of the linked list
 *
 * @param Pointer to head of linked list
 * @return void
 */
void pushNode(node_t **head_ref)
{
    uint32_t temp = 0;
    /* allocate node */
    node_t *new_node = (node_t*) malloc(sizeof(node_t));

    /* put in the data */
    do
    {
        printf("Nhap code: ");
        scanf("%u%*c", &temp);
        new_node->student.code = (uint8_t)temp;
    } while(checkDuplicateCode(*head_ref, new_node->student.code));
    printf("Nhap name: ");
    scanf("%s%*c", new_node->student.name);
    printf("Nhap account: ");
    scanf("%s%*c", new_node->student.account);
    printf("Nhap score: ");
    scanf("%f%*c", &new_node->student.score);
    /* make next of new node as head */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;

    return;
}

/**
 * @brief Function to insert element to the end of the linked list
 *
 * @param Pointer to head of linked list
 * @return void
 */
void appendNode(node_t **head_ref)
{
    uint32_t temp = 0;
    /* allocate node */
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    node_t *last = *head_ref;  /* used in step (*) */

    /* put in the data */
    do
    {
        printf("Nhap code: ");
        scanf("%u%*c", &temp);
        new_node->student.code = (uint8_t)temp;
    } while(checkDuplicateCode(*head_ref, new_node->student.code));
    printf("Nhap name: ");
    scanf("%s%*c", new_node->student.name);
    printf("Nhap account: ");
    scanf("%s%*c", new_node->student.account);
    printf("Nhap score: ");
    scanf("%f%*c", &new_node->student.score);
    /* this new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;
    /* if the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
    }
    else
    {
        /* (*) : else traverse till the last node */
        while (last->next != NULL)
        {
            last = last->next;
        }
        /* change the next of last node */
        last->next = new_node;
    }

    return;
}

/**
 * @brief Function to insert element to the middle of the linked list
 *
 * @param Pointer to first node of linked list, position
 * @return void
 */
void insertNode(node_t *current, uint8_t position)
{
    uint32_t temp = 0;
    uint8_t i = 0;
    /* allocate node */
    node_t *new_node = (node_t*) malloc(sizeof(node_t));

    /* put in the data */
    do
    {
        printf("Nhap code: ");
        scanf("%u%*c", &temp);
        new_node->student.code = (uint8_t)temp;
    } while(checkDuplicateCode(current, new_node->student.code));
    printf("Nhap name: ");
    scanf("%s%*c", new_node->student.name);
    printf("Nhap account: ");
    scanf("%s%*c", new_node->student.account);
    printf("Nhap score: ");
    scanf("%f%*c", &new_node->student.score);
    /* given a node current, insert a new node after the given current */
    for(i = 0; i < (position - 2) ; i++)
    {
        current = current->next;
    }
    /* make next of new node as next of current */
    new_node->next = current->next;
    /* move the next of current as new_node */
    current->next = new_node;

    return;
}

/**
 * @brief Function to delete element of the linked list
 *
 * @param Pointer to head of linked list, position
 * @return void
 */
void deleteNode(node_t **head_ref, uint8_t position)
{
    uint8_t i = 0;
    /* Store head node */
    node_t *temp = *head_ref;
    /* Store next node */
    node_t *nexttemp = NULL;

    /* If head needs to be removed */
    if(position == 1)
    {
        *head_ref = temp->next;   /* Change head */
        free(temp);               /* Free old head */
    }
    else
    {
        /* Find previous node of the node to be deleted */
        for(i = 0; temp != NULL && i < position - 2; i++)
        {
            temp = temp->next;
        }
        /* Node temp->next is the node to be deleted */
        /* Store pointer to the next of node to be deleted */
        nexttemp = temp->next->next;
        /* Unlink the node from linked list */
        free(temp->next);
        /* Relink list */
        temp->next = nexttemp;
    }

     return;
}

/**
 * @brief Function to find element of the linked list
 *
 * @param Pointer to first node of linked list
 * @return void
 */
void findStudent(node_t *current)
{
    /* Status find: be found = 1 / not found = 0 */
    uint8_t stt = 0;
    char name[28] = {};

    /* fflush(stdin); */
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s%*c", name);
    while(stt != 1 && current != NULL)
    {
        if(strcmp(name, current->student.name) == 0) /* string compare: match = 0 / unmatch = 1 */
        {
            stt = 1;
            printf("%2hhd\t%s\t%s\t%.1f\n", \
                current->student.code, current->student.name, current->student.account, current->student.score);
        }
        current = current->next;
    }

    return;
}

/**
 * @brief Function to sort elements of linked list by score
 * 
 * @param Pointer to first node of linked list
 * @return void
 */
void sortScore(node_t *current)
{
    node_t *index; /* index is next current node */
    student_t temp;

    /* Bubble sort */
    while(current != NULL)
    {
        index = current->next;
        while(index != NULL) /* index = NULL means this is last element */
        {
            if(current->student.score < index->student.score)
            {
                temp = current->student;
                current->student = index->student;
                index->student = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    return;
}

/**
 * @brief Function to sort elements of linked list by first name
 * 
 * @param Pointer to head of linked list
 * @return void
 */
void sortName(node_t *current)
{
    node_t *index; /* index is next current node */
    student_t temp;

    /* Bubble sort */
    while(current != NULL)
    {
        index = current->next;
        while(index != NULL) /* index = NULL means this is last element */
        {
            if(sortFirstName(current, index)) /* compare first character of first name */
            {
                temp = current->student;
                current->student = index->student;
                index->student = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    return;
}
