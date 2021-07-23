#ifndef __SRECORD_H__
#define __SRECORD_H__

/********************************************************************
 * Definitions
********************************************************************/
/* General definition of the S-Record specification */
enum _SRecordDefinitions {
    /* 518 bytes are enough to read in an S-Record */
    SRECORD_RECORD_BUFF_SIZE = 518, /* 255(max_bytecount)*2 + 2(byte_count) + 2(type) + 2(end_line) + 1('\0') = 517 */
    /* Offsets and lengths of various fields in an S-Record record */
    /* S-Type */
    SRECORD_START_CODE_OFFSET = 0,
    SRECORD_START_CODE = 'S',
    SRECORD_TYPE_OFFSET = 1,
    SRECORD_TYPE_LEN = 1,
    /* Byte Count */
    SRECORD_COUNT_OFFSET = 2,
    SRECORD_COUNT_LEN = 2,
    /* Address */
    SRECORD_ADDRESS_OFFSET = 4,
    SRECORD_MAX_ADDRESS_LEN = 8, /* Maximum ascii hex length of the S-Record address field */
    /* Check sum */
    SRECORD_CHECKSUM_LEN = 2,
    /* Maximum ascii hex length of the S-Record data field (address + data) */
    SRECORD_MAX_DATA_LEN = 254*2,
    /* Data length of S5 = 16 bits*/
    SRECORD_DATA_S5 = 2*2,
    /* Data length of S6 = 24 bits*/
    SRECORD_DATA_S6 = 3*2,
    /* Ascii hex length of a single byte */
    SRECORD_ASCII_TO_BYTE = 2,
    /* 10 is smallest length = 2(Record type) + 2(Byte count) + 4(Address) + 2(Checksum) */
    SRECORD_MIN_LEN = 10,
};

/* All possible error codes the Motorola S-Record utility functions may return */
enum _SRecordErrors {
    SRECORD_OK = 0,                         /* Success or no error. */
    SRECORD_ERROR_MISS_ASCII = -1,          /* Error code for error missing ASCII char or too short. */
    SRECORD_ERROR_START = -2,               /* Error code for error start not S. */
    SRECORD_ERROR_TYPE = -3,                /* Error code for error type unknown. */
    SRECORD_ERROR_SYNTAX = -4,              /* Error code for encountering character without hex when reading from a file. */
    SRECORD_ERROR_BYTE_COUNT = -5,          /* Error code for error byte count. */
    SRECORD_ERROR_CHECK_SUM = -6,           /* Error code for error check sum. */
    SRECORD_ERROR_S5_S6 = -7,               /* Error code for error when chosing S5/S6 depend line count, or format S5/S6. */
    SRECORD_ERROR_LINE_COUNT = -8,          /* Error code for error wrong line count. */
    SRECORD_EOF = -9,                       /* EOF found */
};

/* Motorola S-Record Types S0-S9 */
enum SRecordTypes {
    SRECORD_TYPE_S0 = 0, /* Header record. 16-bit address normally set to 0x0000 and header information is stored in the data field. */
    SRECORD_TYPE_S1, /* Data record with 16-bit address */
    SRECORD_TYPE_S2, /* Data record with 24-bit address */
    SRECORD_TYPE_S3, /* Data record with 32-bit address */
    SRECORD_TYPE_S4, /* Extension by LSI Logic, Inc. Reserved. */
    SRECORD_TYPE_S5, /* 16-bit address field that contains the number of S1, S2, and S3 (all data) records transmitted. No data field. */
    SRECORD_TYPE_S6, /* 24-bit address field that contains the number of S1, S2, and S3 (all data) records transmitted. No data field. */
    SRECORD_TYPE_S7, /* Termination record for S3 data records. 32-bit address field contains address of the entry point after the S-Record file has been processed. No data field. */
    SRECORD_TYPE_S8, /* Termination record for S2 data records. 24-bit address field contains address of the entry point after the S-Record file has been processed. No data field. */
    SRECORD_TYPE_S9, /* Termination record for S1 data records. 16-bit address field contains address of the entry point after the S-Record file has been processed. No data field. */
};

/* Structure to hold the fields of a Motorola S-Record record. */
typedef struct {
    uint8_t type;                           /* The Motorola S-Record type of this record (S0-S9). */
    uint8_t byte_count;                     /* The number of bytes of data stored in this record. */
    uint8_t data[SRECORD_MAX_DATA_LEN/2];   /* The 8-bit array data field, which has a maximum size of 32 bytes. */
    uint8_t checksum;                       /* The checksum of this record. */
    uint32_t current_line;                  /* Current line contain this record */
} SRecord;

/********************************************************************
 * API
********************************************************************/
int32_t srecord_parseSREC(SRecord *srec, FILE *fp);
void srecord_printSREC(SRecord *srec);

#endif  /* __SRECORD_H__ */
