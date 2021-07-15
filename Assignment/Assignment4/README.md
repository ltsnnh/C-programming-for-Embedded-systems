# Data and Structure - Assignment 4
```
Viết 1 chương trình quản lý thông tin lớp fresher bao gồm:
-Mã số học viên
-Tên
-Account
-Điểm trung bình
Yêu cầu:
-Sử dụng link list đơn để quản lý danh sách
-Có các hàm để thêm/bớt 1 sinh viên vào vị trí bất kỳ
-Có hàm tìm kiếm tên sinh viên và show ra toàn bộ information nếu match
-Có hàm để sắp xếp sinh viên theo
    -Điểm trung bình
    -Tên
```
---
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
