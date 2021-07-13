### MEMORY ALLOCATION FOR A POINTER
---
#### #include <stdlib.h>
---
#### Ham malloc() : cap phat bo nho
	ptr = (castType*) malloc(size);
`ptr = (float*) malloc(100 * sizeof(float));`

![malloc()](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Malloc-function-in-c.png)

#### Ham calloc() : cap phat bo nho va gan gia tri bang 0
	ptr = (castType*) calloc(n, size);
`ptr = (float*) calloc(25, sizeof(float));`

![calloc()](https://media.geeksforgeeks.org/wp-content/cdn-uploads/calloc-function-in-c.png)

#### Ham free() : giai phong bo nho
	free(ptr);

![free()](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Free-function-in-c.png)

#### Ham realloc() : thay doi kich thuoc cua bo nho dc cap phat
	ptr = realloc(ptr, x);

![realloc()](https://media.geeksforgeeks.org/wp-content/cdn-uploads/realloc-function-in-c.png)

##### (Ham malloc(), calloc(), realloc() khi thanh cong tra ve con tro kieu void, khi khong thanh cong tra ve NULL.)
