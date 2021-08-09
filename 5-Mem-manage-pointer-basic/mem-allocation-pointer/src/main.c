#include "userincl.h"

int main(void)
{
	int i, num_malloc, num_calloc, x;
	int *ptr_malloc, *ptr_calloc;

	/* malloc() */
	printf("Nhap so luong phan tu con tro malloc: ");
	scanf("%d%*c", &num_malloc);
	ptr_malloc = (int*)malloc(num_malloc * sizeof(int));
	for(i = 0; i < num_malloc; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");
	/* nhap phan tu cho ptr-malloc */
	for(i = 0; i < num_malloc; i++)
	{
		printf("malloc[%d] = ", i);
		scanf("%d%*c", ptr_malloc + i);
	}
	for(i = 0; i < num_malloc; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");

	/* calloc() */
	printf("Nhap so luong phan tu con tro calloc: ");
	scanf("%d%*c", &num_calloc);
	ptr_calloc = (int*)calloc(num_calloc, sizeof(int));
	for(i = 0; i < num_calloc; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");
	/* nhap phan tu cho ptr-calloc */
	for(i = 0; i < num_calloc; i++)
	{
		printf("calloc[%d] = ", i);
		scanf("%d%*c", ptr_calloc + i);
	}
	for(i = 0; i < num_calloc; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");

	/* realloc() */
	printf("Kich thuoc mang muon thay doi la: ");
	scanf("%d%*c", &x);

	printf("malloc before = %p\n", ptr_malloc);
	ptr_malloc = realloc(ptr_malloc, x);	/* cap phat ghi de len vung da dc cap phat cho bien khac */
	if(ptr_malloc == NULL)
		printf("Khong cap phat resize ptr-malloc dc!");
	printf("malloc after = %p\n", ptr_malloc);

	printf("calloc before = %p\n", ptr_calloc);
	ptr_calloc = realloc(ptr_calloc, x);	/* cap phat ghi de len vung da dc cap phat cho bien khac */
	if(ptr_calloc == NULL)
		printf("Khong cap phat resize ptr-calloc dc!");
	printf("calloc after = %p\n", ptr_calloc);

	for(i = 0; i < x; i++)
		printf("%d\t", *(ptr_malloc + i));
	printf("\n");
	for(i = 0; i < x; i++)
		printf("%d\t", *(ptr_calloc + i));
	printf("\n");

	/* free() */
	free(ptr_malloc);	/* hai vung nho de nhau tai sao van free duoc ma khong loi */
	free(ptr_calloc);	/* hai vung nho de nhau tai sao van free duoc ma khong loi */

	return 0;
}
