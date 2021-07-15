#include <stdio.h>
#include <stdint.h>
#include "menu.h"
#include "lib.h"

/********************************************************************
 * Definitions
********************************************************************/
/* Define user commit code in main menu */
enum menu_commitCode
{
    IMPORT_ELEMENT  = '1',   /* Import an element */
    REMOVE_ELEMENT  = '2',   /* Remove an element */
    PRINT_ARRAY     = '3',   /* Print array */
    EXIT_PROGRAM    = '4'    /* Exit program */
};

/* Define print commit code in print menu */
enum menu_commitPrint
{
    PRINT_UNSORTED  = '1',   /* Print unsorted array */
    PRINT_SORTED    = '2'    /* Print sorted array */
};

/********************************************************************
 * Prototypes
********************************************************************/
static void show_menu(void);
static int8_t get_commit(void);
static void show_print_menu(void);
static int8_t get_commit_printf(void);

/********************************************************************
 * Variables
********************************************************************/
lib_importError_enum_t importERROR = IMPORT_SUCCESS;
lib_removeError_enum_t removeERROR = REMOVE_SUCCESS;

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief Function menu
 *
 * @param   void
 * @return  void
 */
void menu(void)
{
    /* Variable to get user commit */
    int8_t commit = 0;
    /* Variable to get value */
    uint8_t value = 0;
    /* Variable to get position */
    uint8_t position = 0;
    /* Variable to get temp (from function scanf) */
    uint32_t temp = 0;
    /* Variable to get user print commit */
    int8_t commitPrint = 0;

    /* Initialize Array[20] */
    lib_initArray();
    /* Print menu program */
    show_menu();
    /* Take commit and execute */
    do
    {
        commit = get_commit();
        switch(commit)
        {
            /* Import an element */
            case IMPORT_ELEMENT:
            printf("\tEnter value (0 - 100): ");
            scanf("%u%*c", &temp);
            value = (uint8_t)(temp);
            printf("\tEnter position (0 - 19): ");
            scanf("%u%*c", &temp);
            position = (uint8_t)(temp);
            importERROR = lib_importElement(value, position);
            switch(importERROR)
            {
                case ERROR_IMPORT_LOCATION_OUT:
                printf("\t! User-selected position out of range 0 to 19\n");
                break;
                case ERROR_IMPORT_LOCATION_IMPORTED:
                printf("\t! User-selected position has already been entered\n");
                break;
                case ERROR_IMPORT_VALUE_OUT:
                printf("\t! User-selected value out of range 0 to 100\n");
                break;
                case ERROR_IMPORT_VALUE_EXIST:
                printf("\t! User-selected value already exists in array\n");
                break;
                case IMPORT_SUCCESS:
                printf("\tImport element success!\n");
                break;
            }
            break;

            /* Remove an element */
            case REMOVE_ELEMENT:
            printf("\tEnter value (0 - 100): ");
            scanf("%u%*c", &temp);
            value = (uint8_t)(temp);
            removeERROR = lib_removeElement(value);
            switch(removeERROR)
            {
                case ERROR_REMOVE_VALUE_OUT:
                printf("\t! User-selected value out of range 0 to 100\n");
                break;
                case ERROR_REMOVE_VALUE_EXIST:
                printf("\t! User-selected value does not exist\n");
                break;
                case ERROR_REMOVE_EMPTY_ARRAY:
                printf("\t! Array does not exist - none element\n");
                break;
                case REMOVE_SUCCESS:
                printf("\tRemove element success!\n");
                break;
            }
            break;

            /* Print array */
            case PRINT_ARRAY:
            show_print_menu();
            commitPrint = get_commit_printf();
            switch(commitPrint)
            {
                case PRINT_UNSORTED:
                lib_print_Unsorted();
                break;
                case PRINT_SORTED:
                lib_print_Sorted();
                break;
            }
            break;

            /* Exit program */
            case EXIT_PROGRAM:
            printf("!!!Program is exiting...\n");
            break;
        }
    }while(commit != EXIT_PROGRAM);

    return;
}

/**
 * @brief Function show menu (can show repeat)
 *
 * @param   void
 * @return  void
 */
void show_menu(void)
{
    printf("\t\t******************************************************\n");
    printf("\t\t*----------Program manage 20-elements array----------*\n");
    printf("\t\t*    Press '1' to enter an element                   *\n");
    printf("\t\t*    Press '2' to remove an element                  *\n");
    printf("\t\t*    Press '3' to print current elements             *\n");
    printf("\t\t*    Press '4' to exit program                       *\n");
    printf("\t\t******************************************************\n");

    return;
}

/**
 * @brief Function get user commit and filter the correct value
 *
 * @param   void
 * @return  (uint8) user-commit
 */
int8_t get_commit(void)
{
    /* Variable to get user commit */
    int8_t commit = 0;
    /* Variable to clear stdin */
    int8_t clear_stdin = 0;

    do
    {
        printf("Press commit (1-2-3-4): ");
        commit = getchar();
        /* fflush(stdin); */
        if(commit != '\n')
        {
            do
            {
                clear_stdin = getchar();
            }while(clear_stdin != '\n');
        }
    }while(commit != IMPORT_ELEMENT && commit != REMOVE_ELEMENT && commit != PRINT_ARRAY && commit != EXIT_PROGRAM);

    return(commit);
}

/**
 * @brief Function show option print menu
 *
 * @param   void
 * @return  void
 */
 void show_print_menu(void)
 {
    printf("\t\t*************************************\n");
    printf("\t\t*-------Sub-menu print option-------*\n");
    printf("\t\t* Press '1' to print array unsorted *\n");
    printf("\t\t* Press '2' to print sorted array   *\n");
    printf("\t\t*       (low to high)               *\n");
    printf("\t\t*************************************\n");

    return;
 }

 /**
 * @brief Function get user commit and filter the correct value
 *
 * @param   void
 * @return  (uint8) print-option
 */
int8_t get_commit_printf(void)
{
    /* Variable to get user commit */
    int8_t commit = 0;
    /* Variable to clear stdin */
    int8_t clear_stdin = 0;

    do
    {
        printf("Press print commit (1-2): ");
        commit = getchar();
        /* fflush(stdin); */
        if(commit != '\n')
        {
            do
            {
                clear_stdin = getchar();
            }while(clear_stdin != '\n');
        }
    }while(commit != PRINT_UNSORTED && commit != PRINT_SORTED);

    return(commit);
}
