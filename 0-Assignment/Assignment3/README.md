# Assignment 3
```
Assign1:
Viết chương trình cấp phát bộ nhớ động 10 bytes cho 1 con trỏ, với mẫu hàm được cung cấp như sau:

#include <stdint.h>
#include <stdbool.h>
bool allocate10Bytes(uint8_t *outPtr);
- outPtr: output pointer
- return:   - true: Nếu cấp phát thành công.
            - false: Nếu cấp phát bị lỗi.
Assign2:
Viết chương trình con tính giá trị tuyệt đối của hiệu hai số dương 8 bits a và b,  
với mẫu hàm được cung cấp như sau (không print bất kỳ thông tin gì trong chương trình con này):

#include <stdint.h>
void absoluteValue(uint8_t *data);
- data: in/out parameter.
Viết ứng dụng nhập 2 số dương 8 bits từ bàn phím, truyền 2 số dương 8 bits này  
vào data parameter của hàm absoluteValue để tính giá trị tuyệt đối hiệu 2 số 8 bits này.  
Print giá trị của 2 số 8 bits này, giá trị tuyệt đối của hiệu 2 số 8 bits này.  
Ứng dụng cho phép người dùng nhập nhiều lần 2 số 8 bits để tính toán.
```
### Folder structure
    Top-directory/
        |- Assign1
            |- *
        |- Assign2
            |- main         Executable file
            |- Makefile             
            |- inc/
                |- *        User library files
            |- src/
                |- main.c   Source code
                |- task1.c  
                |- task2.c  
                |- task3.c  
            |- obj/
                |- *        Object files
