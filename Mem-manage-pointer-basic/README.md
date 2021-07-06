### MEMORY ALLOCATION FOR A POINTER
---
#### #include <stdlib.h>
#### Ham malloc() : cap phat bo nho
	ptr = (castType*) malloc(size);
`ptr = (float*) malloc(100 * sizeof(float));`
#### Ham calloc() : cap phat bo nho va gan gia tri bang 0
	ptr = (castType*) calloc(n, size);
`ptr = (float*) calloc(25, sizeof(float));`
#### Neu khong cap phat dc cac ham se tra ve con tro NULL
#### Ham free() : giai phong bo nho
	free(ptr);
#### Ham realloc() : thay doi kich thuoc cua bo nho dc cap phat
	ptr = realloc(ptr, x);
