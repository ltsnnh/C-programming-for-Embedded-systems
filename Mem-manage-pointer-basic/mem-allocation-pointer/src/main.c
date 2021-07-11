#include "userincl.h"

int main(void)
{
	int i, num_malloc, num_calloc, x;
	int *ptr_malloc, *ptr_calloc, *stt;

	/* malloc() */
	printf("Nhap so luong phan tu con tro malloc: ");
	scanf("%d", &num_malloc);
	ptr_malloc = (int*)malloc(num_malloc * sizeof(int));
	for(i = 0; i < num_malloc; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");
	/* nhap phan tu cho ptr-malloc */
	for(i = 0; i < num_malloc; i++)
	{
		printf("malloc[%d] = ", i);
		scanf("%d", ptr_malloc + i);
	}
	for(i = 0; i < num_malloc; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");

	/* calloc() */
	printf("Nhap so luong phan tu con tro calloc: ");
	scanf("%d", &num_calloc);
	ptr_calloc = (int*)calloc(num_calloc, sizeof(int));
	for(i = 0; i < num_calloc; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");
	/* nhap phan tu cho ptr-calloc */
	for(i = 0; i < num_calloc; i++)
	{
		printf("calloc[%d] = ", i);
		scanf("%d", ptr_calloc + i);
	}
	for(i = 0; i < num_calloc; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");

	/* realloc() */
	printf("Kich thuoc mang muon thay doi la: ");
	scanf("%d", &x);
	stt = realloc(ptr_malloc, x);
	if(stt == NULL)
		printf("Khong cap phat resize ptr-malloc dc!");
	stt = realloc(ptr_calloc, x);
	if(stt == NULL)
		printf("Khong cap phat resize ptr-calloc dc!");
	for(i = 0; i < x; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");
	for(i = 0; i < x; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");

	/* free() */
	free(ptr_malloc);
	free(ptr_calloc);
	return 0;
}
