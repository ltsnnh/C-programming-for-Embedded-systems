#ifndef __LIB_H__
#define __LIB_H__

/********************************************************************
 * Definitions
********************************************************************/
/* Structure student_t contain student information */
typedef struct
{
    uint8_t code;
    char name[28];
    char account[12];
    float score;
} student_t; /* sizeof = 48 bytes */

/* Structure node_t define type of node what is the part of linked list */
typedef struct ll
{
    student_t student;
    struct ll *next;
} node_t; /* sizeof = 56 bytes */

/********************************************************************
 * API
********************************************************************/
void printList(node_t *current);
void pushNode(node_t **head_ref);
void appendNode(node_t **head_ref);
void insertNode(node_t *current, uint8_t position);
void deleteNode(node_t **head_ref, uint8_t position);
void findStudent(node_t *current);
void sortScore(node_t *current);
void sortName(node_t *current);

#endif /* __LIB_H__ */
