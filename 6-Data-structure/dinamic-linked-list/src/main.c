#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "common.h"

typedef struct ll
{
    uint8_t data;
    struct ll *next;
} node_t;

void printList(node_t *currentNode);
void insertNode(node_t **head_ref, uint8_t data, uint8_t position);
void deleteNode(node_t **head_ref, uint8_t position);
void switch2Node(node_t **head_ref, uint8_t position);

int main(void)
{
    uint8_t position = 0;
    uint8_t data = 0;

    /* initialization 3 node */
    node_t *head = (node_t*)malloc(sizeof(node_t));
    node_t *second = (node_t*)malloc(sizeof(node_t));
    node_t *third = (node_t*)malloc(sizeof(node_t));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    /* first print 3 node */
    printList(head);

    do
    {
        printf("add Node: Position(100 to exit), data = ");
        scanf("%hhu%hhu%*c", &position, &data);
        /* Inserts a new node into the list */
        insertNode(&head, data, position);
        /* print list */
        printList(head);

        printf("delete Node: Position(100 to exit) = ");
        scanf("%hhu%*c", &position);
        /* Delete node from the list */
        deleteNode(&head, position);
        /* print list */
        printList(head);

        printf("switch 2 Node: Position(100 to exit) = ");
        scanf("%hhu%*c", &position);
        /* Switch 2 node in the list */
        switch2Node(&head, position);
        /* print list */
        printList(head);

    } while(position < 100);

    printf("Exiting...!\n");

    return 0;
}

void printList(node_t *currentNode)
{
    if(currentNode == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while(currentNode != NULL)
        {
            printf("%hhu\t", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }

    return;
}

void insertNode(node_t **head_ref, uint8_t data, uint8_t position)
{
    uint8_t numNode = 0;
    node_t *currentNode = *head_ref;
    node_t *newNode = NULL;
    uint8_t i = 1;

    if(currentNode == NULL)
    {
        numNode = 0;
    }
    else
    {
        while(currentNode != NULL)
        {
            numNode += 1;
            currentNode = currentNode->next;
        }
    }

    if(position > numNode)
    {
        printf("Position out of the list\n");
    }
    else
    {
        if(position == 0) /* inserts a new node on the front of the list */
        {
            /* 1. allocate new node */
            newNode = (node_t*)malloc(sizeof(node_t));
            /* 2. fill data into Node */
            newNode->data = data;
            /* 3. make next of new node as HEAD */
            newNode->next = *head_ref;
            /* 4. mode the HEAD to point to the new Node */
            *head_ref = newNode;
        }
        else /* appends a new node at the end */ /* && */ /* insert a new node after the given prev_node */
        {
            /* 1. allocate new node */
            newNode = (node_t*)malloc(sizeof(node_t));
            /* 2. fill data into Node */
            newNode->data = data;
            /* 3. indicate prev_node */
            currentNode = *head_ref; /* i = 1 */
            while(i != position)
            {
                currentNode = currentNode->next;
                i++;
            }
            /* 4. relink */
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    return;
}

void deleteNode(node_t **head_ref, uint8_t position)
{
    uint8_t numNode = 0;
    node_t *currentNode = *head_ref;
    node_t *deleteNode = NULL;
    uint8_t i = 0;

    if(currentNode == NULL)
    {
        numNode = 0;
    }
    else
    {
        while(currentNode != NULL)
        {
            numNode += 1;
            currentNode = currentNode->next;
        }
    }

    if(numNode == 0)
    {
        printf("Empty Node!\n");
    }
    else if(position > numNode - 1) /* position start at 0 */
    {
        printf("Position out of the list\n");
    }
    else
    {
        if(position == 0) /* delete node on the front of the list */
        {
            /* 1. indicate delete Node */
            deleteNode = *head_ref;
            /* 2. relink */
            *head_ref = deleteNode->next;
            /* 3. free */
            free(deleteNode);
        }
        else /* delete at the end */ /* && */ /* delete node after the given prev_node */
        {
            /* 1. indicate prev_node */
            currentNode = *head_ref; /* i = 0 */
            while(i != (position - 1))
            {
                currentNode = currentNode->next;
                i++;
            }
            deleteNode = currentNode->next;
            /* 2. relink */
            currentNode->next = deleteNode->next;
            /* 3. free */
            free(deleteNode);
        }
    }

    return;
}

void switch2Node(node_t **head_ref, uint8_t position)
{
    uint8_t numNode = 0;
    node_t *currentNode = *head_ref;
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    uint8_t i = 0;

    if(currentNode == NULL)
    {
        numNode = 0;
    }
    else
    {
        while(currentNode != NULL)
        {
            numNode += 1;
            currentNode = currentNode->next;
        }
    }

    if(numNode < 2 )
    {
        printf("Can not switch 2 Node!\n");
    }
    else if(position > numNode - 2) /* position start at 0 */
    {
        printf("Position out of the list\n");
    }
    else
    {
        if(position == 0)
        {
            /* 1. indicate 2 node */
            node1 = *head_ref;
            node2 = node1->next;
            /* 2. relink */
            *head_ref = node2;
            node1->next = node2->next;
            node2->next = node1;
        }
        else
        {
            /* 1. indicate prev_node */
            currentNode = *head_ref; /* i = 0 */
            while(i != (position - 1))
            {
                currentNode = currentNode->next;
                i++;
            }
            node1 = currentNode->next;
            node2 = node1->next;
            /* 2. relink */
            currentNode->next = node2;
            node1->next = node2->next;
            node2->next = node1;
        }
    }

    return;
}

