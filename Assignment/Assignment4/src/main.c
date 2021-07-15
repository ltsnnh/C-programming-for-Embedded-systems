#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib.h"

/********************************************************************
 * Definitions
********************************************************************/
/* Define character commits which math with function */
enum 
{
    print_list = 'p',
    insert_student = 'i',
    remove_student = 'r',
    find_student = 'f',
    sort_score = 's',
    sort_name = 'n',
    exit_program = 'e',
};

/********************************************************************
 * Variables
********************************************************************/
/* Initialize original info of students */
student_t man[16] =
{
    {1, "Tran Quang Huy", "HuyTQ53", 9.0},
    {2, "Do Minh Hieu", "HieuDM5", 8.9},
    {3, "Tran Xuan Khanh", "KhanhTX3", 8.8},
    {4, "Nguyen Duc Thanh", "ThanhND73", 8.7},
    {5, "Le Duc Hau", "HauLD3", 8.6},
    {6, "Nguyen Quang Huy", "HuyNQ103", 8.5},
    {7, "Vi Thi Trang", "TrangVT22", 8.4},
    {8, "Le Manh Hung", "HungLM16", 8.3},
    {9, "Ngo Sy Toan", "ToanNS4", 8.3},
    {10, "Vu Ngoc Long", "LongLV7", 8.4},
    {11, "Le Tuan Anh", "AnhLT88", 8.5},
    {12, "Nguyen Duc Tai", "TaiND18", 8.6},
    {13, "Nguyen Van Chien", "ChienNV17", 8.7},
    {14, "Luu Dinh Minh", "MinhLD12", 8.8},
    {15, "Bui Thai Trung", "TrungBT1", 8.9},
    {16, "Le Quang Thanh", "ThanhLQ7", 9.0},
};

/********************************************************************
 * Prototypes
********************************************************************/
/**
 * @brief Function to delete the entire linked list
 *
 * @param Pointer to head of linked list
 * @return void
 */
static void deleteList(node_t **head_ref)
{
   /* head_ref to get the real head */
   node_t *current = *head_ref;
   node_t *next = NULL;

    /* free pointer from head to tail */
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   /* head_ref to affect the real head back in the caller */
   *head_ref = NULL;

   return;
}

/**
 * @brief Function to show menu of program
 *
 * @param void
 * @return void
 */
 static void menu(void)
 {
    printf("\t\t*************************************************************\n");
    printf("\t\t*----------CT quan ly thong tin lop fresher_emb_03----------*\n");
    printf("\t\t*     Nhap 'p' de in danh sach                              *\n");
    printf("\t\t*     Nhap 'i' de them 1 hoc vien                           *\n");
    printf("\t\t*     Nhap 'r' de xoa 1 hoc vien                            *\n");
    printf("\t\t*     Nhap 'f' de tim 1 hoc vien                            *\n");
    printf("\t\t*     Nhap 's' de sap xep danh sach theo diem so            *\n");
    printf("\t\t*     Nhap 'n' de sap xep danh sach theo ten                *\n");
    printf("\t\t*     Nhap 'e' de thoat chuong trinh                        *\n");
    printf("\t\t*************************************************************\n");

    return;
 }

/********************************************************************
 * Code
********************************************************************/
int main(void)
{
    /* Array of nodes. each node is an element of original linked list */
    node_t *node[16] = {NULL};
    /* Pointer head -> first element of linked list */
    node_t *head = NULL;
    /* Number of student */
    uint8_t num_student = sizeof(man) / sizeof(student_t);
    /* Variable i for counting purposes */
    uint8_t i = 0;
    /* commit to get command from user, clear_stdin is temporary var to clear stdin */
    int8_t commit = 0;
    int8_t clear_stdin = 0;
    /* Variable position */
    uint8_t position = 0;
    /* Variable temporary */
    uint32_t temp = 0;

    /* Dinamic allocate for each node */
    for(i = 0; i < num_student; i++)
    {
        node[i] = (node_t*)malloc(sizeof(node_t));
    }
    /* Init data of original linked list */
    for(i = 0; i < num_student; i++)
    {
        node[i]->student = man[i];
        node[i]->next = NULL;
        if(i > 0)
        {
            node[i - 1]->next = node[i];
        }
    }
    /* head -> first node */
    head = node[0];

    /* Menu */
    menu();
    /* Take orders and execute */
    do
    {
        printf("Nhap lenh: ");
        commit = getchar();
        /* fflush(stdin); */
        if(commit != '\n')
        {
            do
            {
                clear_stdin = getchar();
            } while(clear_stdin != '\n');
        }
        /* Check commit -> run executable */
        switch(commit)
        {
            /* Print list */
            case print_list:
            printList(head);
            break;

            /* Insert a student */
            case insert_student:
            do
            {
                printf("Nhap vi tri muon them phan tu (<=%hhu)\n", num_student + 1);
                scanf("%u%*c", &temp);
            } while( temp < 1 || temp > (num_student + 1));
            position = (uint8_t)temp;
            if(position == 1)
            {
                pushNode(&head); /* Insert element to the begin of the linked list */
            }
            else if(position == (num_student + 1))
            {
                appendNode(&head); /* Insert element to the end of the linked list */
            }
            else
            {
                insertNode(head, position); /* Insert element to the middle of the linked list */
            }
            num_student += 1;
            break;

            /* Remove a student */
            case remove_student:
            do
            {
                printf("Nhap vi tri muon xoa phan tu (<=%hhu)\n", num_student);
                scanf("%u%*c", &temp);
            } while( temp < 1 || temp > (num_student));
            position = (uint8_t)temp;
            deleteNode(&head, position);
            num_student -= 1;
            break;

            /* Find a student */
            case find_student:
            findStudent(head);
            break;

            /* Sort list by score */
            case sort_score:
            sortScore(head);
            break;

            /* Sort list by name */
            case sort_name:
            sortName(head);
            break;

            /* Exit program */
            case exit_program:
            break;

            /* Wrong commit */
            default:
            printf("Lenh nhap sai!");
        }
    } while(commit != exit_program);

    /* Free all node of linked list */
    deleteList(&head);

    return 0;
}
