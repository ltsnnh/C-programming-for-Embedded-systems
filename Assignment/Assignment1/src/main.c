#include "main.h"

/********************************************************************
 * Definitions
********************************************************************/
#define SORT_INCREASE   0
#define SORT_REDUCTION  1
#define FIND_MAX        0
#define FIND_MIN        1

/********************************************************************
 * Code
********************************************************************/
int main(void)
{
    int32_t array[25] = {};
    int8_t commit = 0;          /* NULL */
    int8_t clear_stdin = 0;     /* NULL */
    uint8_t num_element = 0;    /* NULL */
    bool array_stt = false;

    enum {
        nhap_mang = 'c',
        in_mang = 'p',
        them_phan_tu = 'i',
        xoa_phan_tu = 'd',
        sap_xep_tang = 's',
        sap_xep_giam = 'x',
        tim_phan_tu = 't',
        in_lon_nhat = 'a',
        in_nho_nhat = 'w',
        thoat_ct = 'e'
    };

    printf("CT quan ly day so bang mang:\n\
        \t- Nhap 'c' de tao mang so nguyen\n\
        \t- Nhap 'p' de in day\n\
        \t- Nhap 'i' de them 1 phan tu vao day\n\
        \t- Nhap 'd' de xoa 1 phan tu\n\
        \t- Nhap 's' de sap xep day so theo chieu tang dan\n\
        \t- Nhap 'x' de sap xep day so theo chieu giam dan\n\
        \t- Nhap 't' de tim 1 so\n\
        \t- Nhap 'a' de in ra man hinh so lon nhat\n\
        \t- Nhap 'w' de in ra man hinh so nho nhat\n\
        \t- Nhap 'e' de thoat chuong trinh\n\
        \t(Recommend: 'c')\n");

    while(1)
    {
        printf("Nhap lenh: ");
        commit = getchar();

        if(commit != '\n')  /* fflush(stdin); */
        {
            do
            {
                clear_stdin = getchar();
            }while(clear_stdin != '\n');
        }

        switch(commit)
        {
            case nhap_mang:
                if(array_stt == false)
                {
                    num_element = func_import_array(array);
                    array_stt = true;
                }
                else
                {
                    func_remove_array(num_element, array);
                    num_element = func_import_array(array);
                }
                break;
            case in_mang:
                func_print_array(num_element, array);
                break;
            case them_phan_tu:
                func_insert_element(num_element, array);
                num_element++;
                break;
            case xoa_phan_tu:
                num_element -= func_remove_element(num_element, array);
                break;
            case sap_xep_tang:
                func_sort_increase_reduction(num_element, array, SORT_INCREASE);
                break;
            case sap_xep_giam:
                func_sort_increase_reduction(num_element, array, SORT_REDUCTION);
                break;
            case tim_phan_tu:
                func_find_element(num_element, array);
                break;
            case in_lon_nhat:
                printf("Phan tu lon nhat = %d\n", func_find_max_min(num_element, array, FIND_MAX));
                break;
            case in_nho_nhat:
                printf("Phan tu nho nhat = %d\n", func_find_max_min(num_element, array, FIND_MIN));
                break;
            case thoat_ct:
                exit(0);
                break;
        }
    }

    return 0;
}
