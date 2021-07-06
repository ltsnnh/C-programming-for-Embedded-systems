#include "userincl.h"

typedef struct {
	int ngay_thu;			//4
	char ten_thang[10];		//10->12
	long int nam;			//8
} ngay;

int main(void)
{
	ngay ngay_la_lung, ngay_di = {10, "June", 1997}, ngay_den = {11, "April", 1997};

	// ngay_la_lung = {
	// 	3,
	// 	"June",
	// 	2016
	// };

	printf("sizeof(struct ngay) = %ld\n", sizeof(ngay));		//24
	printf("Ngay den: %d %s %ld\n", ngay_den.ngay_thu, ngay_den.ten_thang, ngay_den.nam);
	printf("Ngay di: %d %s %ld\n", ngay_di.ngay_thu, ngay_di.ten_thang, ngay_di.nam);
	//printf("Ngay la lung: %d %s %ld\n", ngay_la_lung.ngay_thu, ngay_la_lung.ten_thang, ngay_la_lung.nam);

	return 0;
}