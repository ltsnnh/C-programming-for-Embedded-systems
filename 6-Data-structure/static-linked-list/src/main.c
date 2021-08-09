#include <stdio.h>
#include <stdint.h>
#include "common.h"

#define N   10

typedef struct ll
{
    uint8_t data;
    struct ll *next;
} node_t;

void printList(node_t *head);

int main(void)
{
    uint8_t i = 0;
    node_t node[N];

    for(i = 0; i < 10; i++)
    {
        node[i].data = i;
        node[i].next = NULL;
        if(i > 0)
        {
            node[i - 1].next = &node[i];
        }
    }

    printList(node);

    return 0;
}

void printList(node_t *currentNode)
{
    while(currentNode)
    {
        printf("%hhu\t", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");

    return;
}
