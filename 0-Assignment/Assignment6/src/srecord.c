#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "srecord.h"

/********************************************************************
 * Definitions
********************************************************************/

/********************************************************************
 * Prototypes
********************************************************************/
static bool check_miss_ascii(SRecord *srec);
static bool check_start(void);
static bool check_type(SRecord *srec);
static bool check_syntax(SRecord *srec);
static bool convert2CharToDec(uint16_t i, uint8_t *dec);
static bool check_byte_count(SRecord *srec);
static bool check_sum(SRecord *srec);
static bool check_s5_s6(SRecord *srec);
static bool check_line_count(SRecord *srec);

/********************************************************************
 * Variables
********************************************************************/
char recordBuff[SRECORD_RECORD_BUFF_SIZE]; /* Enough buffer to contain a line SREC format */
uint16_t asciiLength; /* Number ascii char in buffer */
uint32_t count_line; /* Indicate number of current line */

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief   Function check error srecord line by line
 *
 * @param   (SRecord*), (FILR*)
 * @return  error-code
 */
int32_t srecord_parseSREC(SRecord *srec, FILE *fp)
{
    int32_t status = SRECORD_OK;

    fgets(recordBuff, SRECORD_RECORD_BUFF_SIZE, fp);    /* also get <CR> <LF> */
    if(feof(fp))    /* Check last line */
    {
        status = SRECORD_EOF;
    }
    else if(check_miss_ascii(srec))
    {
        status = SRECORD_ERROR_MISS_ASCII;
    }
    else if(check_start())
    {
        status = SRECORD_ERROR_START;
    }
    else if(check_type(srec))
    {
        status = SRECORD_ERROR_TYPE;
    }
    else if(check_syntax(srec))
    {
        status = SRECORD_ERROR_SYNTAX;
    }
    else if(check_byte_count(srec))
    {
        status = SRECORD_ERROR_BYTE_COUNT;
    }
    else if(check_sum(srec))
    {
        status = SRECORD_ERROR_CHECK_SUM;
    }
    else if(check_s5_s6(srec))
    {
        status = SRECORD_ERROR_S5_S6;
    }
    else if(check_line_count(srec))
    {
        status = SRECORD_ERROR_LINE_COUNT;
    }

    return(status);
}

/**
 * @brief   Print information current line if type of it is S1/S2/S3
 *
 * @param   (SRecord*)
 * @return  void
 */
 void srecord_printSREC(SRecord *srec)
 {
    uint8_t i = 0; /* Variable i for counting purposes */

    if((srec->type == (uint8_t)SRECORD_TYPE_S1)
        || (srec->type == (uint8_t)SRECORD_TYPE_S2)
        || (srec->type == (uint8_t)SRECORD_TYPE_S3))
    {
        printf("Address: ");
        for(i = 0; i <= srec->type; i++) /* The number of address bytes = SRECORD_TYPE_S? + 1 */
        {
            printf("%02hhx", srec->data[i]);
        }
        printf("\nValue: "); /* The number of value bytes = byte_count - address - check_sum (byte) */
        for(i = srec->type + 1; i < srec->byte_count - 1; i++)
        {
            printf("%02hhx", srec->data[i]);
        }
        printf("\n");
    }

    return;
 }

/**
 * @brief   Function check: Number ascii char in buffer is even (never is odd), and too little (always >= SRECORD_MIN_LEN)
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_miss_ascii(SRecord *srec)
 {
    bool stt = false;

    asciiLength = strcspn(recordBuff, "\r\n");
    recordBuff[asciiLength] = '\0'; /* Replace '\r' '\n' by '\0' */
    count_line++; /* Count line increases even if the line is not valid */
    srec->current_line = count_line;
    if(asciiLength < (uint16_t)SRECORD_MIN_LEN || asciiLength % 2)
    {
        stt = true;
    }

    return(stt);
 }

/**
 * @brief   Function check start character ('S')
 *
 * @param   void
 * @return  true = error | false if not
 */
 static bool check_start(void)
 {
    bool stt = false;

    if(recordBuff[SRECORD_START_CODE_OFFSET] != SRECORD_START_CODE)
    {
        stt = true;
    }

    return(stt);
 }

/**
 * @brief   Function check type of srec (S1-S9)
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_type(SRecord *srec)
 {
    bool stt = false;
    uint8_t type = recordBuff[SRECORD_TYPE_OFFSET] - 48; /* 48 = offset char >> int (same shape)(0-9) */

    if(type < 0 || type > 9)
    {
        stt = true;
    }
    else
    {
        srec->type = type;
    }

    return(stt);
 }

/**
 * @brief   Function check syntax (inside hex characters)
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_syntax(SRecord *srec)
 {
    bool stt = false;
    uint8_t dec = 0;
    uint16_t i = 0;

    for(i = SRECORD_COUNT_OFFSET; i < asciiLength; i += SRECORD_ASCII_TO_BYTE) /* if 2 ascii char belong byte count field */
    {
        if(i == SRECORD_COUNT_OFFSET)
        {
            stt = convert2CharToDec(i, &dec);
            if(stt)
            {
                return(stt);
            }
            srec->byte_count = dec;
        }
        else if(i == asciiLength - SRECORD_CHECKSUM_LEN) /* if 2 ascii char belong check sum field */
        {
            stt = convert2CharToDec(i, &dec);
            if(stt)
            {
                return(stt);
            }
            srec->checksum = dec;
        }
        else
        {
            stt = convert2CharToDec(i, &dec); /* 2 ascii char belong address field and data field */
            if(stt)
            {
                return(stt);
            }
            srec->data[(i - SRECORD_ADDRESS_OFFSET)/SRECORD_ASCII_TO_BYTE] = dec;
        }
    }

    return(stt);
 }

/**
 * @brief   Function check byte count
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_byte_count(SRecord *srec)
 {
    bool stt = false;

    if(srec->byte_count != (asciiLength - SRECORD_ADDRESS_OFFSET)/SRECORD_ASCII_TO_BYTE)
    {
        stt = true;
    }

    return(stt);
 }

/**
 * @brief   Function check sum
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_sum(SRecord *srec)
 {
    bool stt = false;
    uint16_t sum = (uint16_t)srec->byte_count;
    uint8_t i = 0;

    for(i = 0; i < srec->byte_count - (SRECORD_CHECKSUM_LEN/SRECORD_ASCII_TO_BYTE); i++)
    {
        sum += (uint16_t)srec->data[i];
    }

    if((uint8_t)(~sum) != srec->checksum)
    {
        stt = true;
    }

    return(stt);
 }

/**
 * @brief   Function check S5 or S6
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_s5_s6(SRecord *srec)
 {
    bool stt = false;

    if(((count_line > 0xFFFF)&&(srec->type == (uint8_t)SRECORD_TYPE_S5)) /* S5 record is used if the record count is less than or equal to 65,535 (0xFFFF) */
        || ((count_line < 0xFFFF)&&(srec->type == (uint8_t)SRECORD_TYPE_S6))) /* S6 record is used if the record count is more than or equal to 65,535 (0xFFFF) */
    {
        stt = true;
    }
    else if(((srec->type == SRECORD_TYPE_S5)&&(srec->byte_count != (SRECORD_DATA_S5/SRECORD_ASCII_TO_BYTE + SRECORD_CHECKSUM_LEN/SRECORD_ASCII_TO_BYTE)))
        || ((srec->type == SRECORD_TYPE_S6)&&(srec->byte_count != (SRECORD_DATA_S6/SRECORD_ASCII_TO_BYTE + SRECORD_CHECKSUM_LEN/SRECORD_ASCII_TO_BYTE))))
        /* S5: byte count = 3 = data(2 bytes) + check sum(1 byte) */
        /* S6: byte count = 4 = data(3 bytes) + check sum(1 byte) */
    {
        stt = true;
    }

    return(stt);
 }

/**
 * @brief   Function check line count
 *
 * @param   (SRecord*)
 * @return  true = error | false if not
 */
 static bool check_line_count(SRecord *srec)
 {
    bool stt = false;

    /* 2 = 1 line(S0) + 1 line(current line) */
    if(srec->type == (uint8_t)SRECORD_TYPE_S5)
    {
        if(count_line - 2 != ((srec->data[0] << 8) | srec->data[1])) /* S5: data[0], data[1] belong line count field (16 bits) */
        {
            stt = true;
            return(stt);
        }
    }
    else if(srec->type == (uint8_t)SRECORD_TYPE_S6)
    {
        if(count_line - 2 != ((srec->data[0] << 16) | ((srec->data[1] << 8) | srec->data[2]))) /* S6: data[0], data[1], data[2] belong line count field (24 bits) */
        {
            stt = true;
            return(stt);
        }
    }

    return(stt);
 }

/**
 * @brief   Function convert 2 char to 1 dec (1 byte hex format )
 *
 * @param   i (position), (SRecord*)
 * @return  true = error | false if not
 */
 static bool convert2CharToDec(uint16_t i, uint8_t *dec)
 {
    bool stt = false;
    char a = recordBuff[i];
    char b = recordBuff[i + 1];

    if('0' <= a && a <= '9')
    {
        a = a - 48; /* 48 = offset char >> int (same shape)(0-9) */
    }
    else if('A' <= a && a <= 'F')
    {
        a = a - 55; /* 55 = offset char >> int (same shape)(A-F) */
    }
    else
    {
        stt = true;
        return(stt);
    }

    if('0' <= b && b <= '9')
    {
        b = b - 48; /* 48 = offset char >> int (same shape)(0-9) */
    }
    else if('A' <= b && b <= 'F')
    {
        b = b - 55; /* 55 = offset char >> int (same shape)(A-F) */
    }
    else
    {
        stt = true;
        return(stt);
    }

    *dec = (a << 4) | b; /* convert 2 dec (0-F) to 1 dec (0-FF) */

    return(stt);
 }
