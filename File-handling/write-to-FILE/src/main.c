#include <stdio.h>

/*
KIEU NHI PHAN:  bao toan du lieu
                ma ket thuc tep khi doc den cuoi tep (EOF (= -1))
KIEU VAN BAN:   khac KIEU NHI PHAN: khi ghi LF -> CR LF     LF->10
                                    khi doc CR LF -> LF     CR->13
                                    khi ket thuc tep SUB    SUB->26
                cau truc phu hop vs tep van ban cua DOS
*/

int main(void)
{
    FILE *fvb, *fnp;    /* Khai bao 2 bien con tro tep */

    fvb = fopen("vb.txt", "wt");    /* Mo tep vb, ghi theo kieu van ban */
    fnp = fopen("np.txt", "wb");    /* Mo tep np, ghi theo kieu nhi phan */

    /* Ghi cac ky tu len tep vb */
    fputc('A', fvb);
    fputc(26, fvb); // 0x1A
    fputc(10, fvb); // CR (0x0D) LF (0x0A)
    fputc('B', fvb);
    /* Ghi cac ky tu len tep np */
    fputc('A', fnp);
    fputc(26, fnp); // 0x1A
    fputc(10, fnp); // LF (0x0A)
    fputc('B', fnp);

    fclose(fvb);    /* Dong tep */
    fclose(fnp);    /* Dong tep */

    return 0;
}
