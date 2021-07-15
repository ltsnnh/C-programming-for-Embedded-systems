#ifndef __LIB_H__
#define __LIB_H__

/********************************************************************
 * Definitions
********************************************************************/
/* Define STATUS code is returned by function import */
typedef enum
{
    IMPORT_SUCCESS,                     /* IMPORT SUCCESS */
    ERROR_IMPORT_LOCATION_OUT,          /* LOCATION OUT OF THE SPACE */
    ERROR_IMPORT_LOCATION_IMPORTED,     /* LOCATION HAS BEEN IMPORTED */
    ERROR_IMPORT_VALUE_OUT,             /* VALUE OUT OF THE SPACE */
    ERROR_IMPORT_VALUE_EXIST            /* VALUE ALREADY EXIST */
} lib_importError_enum_t;

/* Define STATUS code is returned by function remove */
typedef enum
{
    REMOVE_SUCCESS,                     /* REMOVE SUCCESS */
    ERROR_REMOVE_VALUE_OUT,             /* VALUE OUT OF THE SPACE */
    ERROR_REMOVE_VALUE_EXIST,           /* VALUE DOES NOT EXIST */
    ERROR_REMOVE_EMPTY_ARRAY            /* EMPTY ARRAY */
} lib_removeError_enum_t;

/********************************************************************
 * API
********************************************************************/
void lib_initArray(void);
lib_importError_enum_t lib_importElement(uint8_t value, uint8_t position);
lib_removeError_enum_t lib_removeElement(uint8_t value);
void lib_print_Unsorted(void);
void lib_print_Sorted(void);

#endif  /* __LIB_H__ */
