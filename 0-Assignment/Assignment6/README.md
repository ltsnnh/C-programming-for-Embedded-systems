# FILE handling - Assignment 6
```
Viết chương trình parse file SREC.
Yêu cầu:
Kiểm tra định dạng (kí tự không phải của hexa) và checksum, byte count của từng dòng,
kiểm tra S5 S6 và in ra đầy đủ các lỗi như sau:
- lineNumber
- summary(lỗi gì)
Nếu không lỗi in ra màn hình các thông tin (của S1/S2/S3) như sau:
- địa chỉ
- dữ liệu
```
# Simple Makefile
Let's go through a really juicy Make example that works well for medium sized projects.
Building from different source folder to different target folder.

### This Makefile can be used to build a project with this kind of structure:
    Top-directory/
        |- main         Executable file (~main.zip)
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

### How to use this Makefile To adapt this Makefile to your project you have to:
1. Change the BINARY variable to match your target name.
2. Put your C/C++ files in the `src/` folder.
3. Put your Header files in the `inc/` folder.
4. Object files in `obj/` folder, execultive program in root directory.
5. If required, change the compiler and the flags.
