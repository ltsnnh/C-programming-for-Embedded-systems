# Assignment 2
---
## NOTE: Bit and Field Numbering Conventions
---
```
Register bits and fields are generally numbered according 
to the convention used in the Power Architecture standard (MSB=0); 
however, in some instances the bit/field numbering may appear to be reversed.
```
| Bit 0 | Bit 1 | Bit 2 | Bit 3 | Bit 4 | Bit 5 | Bit 6 | Bit 7 |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| MSB |  |  |  |  |  |  | LSB |
---
**Example set Bit 4 & Bit 5:**
```
#define SHIFT	0x02u 
#define MASK	0x03u 
temp_reg = BYTE & ~(MASK << SHIFT); 
BYTE = temp_reg | (MASK << SHIFT); 
```
