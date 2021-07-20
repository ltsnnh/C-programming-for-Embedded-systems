# Pointer advance assignment - Assignment 5
```
Cho một mảng gồm 20 bytes “uint8_t assignment4[20] = {0xFF, 0xFF,…,0xFF}”
dùng để lưu trữ các giá trị từ 0 đến 100.
Dùng danh sách liên kết đơn để quản lý các phần tử trong mảng theo giá trị
từ thấp đến cao và viết “menu” chương trình cho phép người dùng:
1. Nhập 1 giá trị vào 1 phần tử chỉ định của mảng trên (Dùng phím 1 để chọn option này)
-Vị trí từ 0 đến 19. Báo lỗi nếu:
    -Vị trí người dùng chọn ngoài khoảng 0 đến 19
    -Vi trí đã được nhập rồi.
-Giá trị từ 0 đến 100. Báo lỗi nếu:
    -Giá trị người dùng chọn ngoài khoảng 0 đến 100
    -Giá trị người dùng chọn đã tồn tại ở trong mảng.
2. Xóa 1 giá trị nào đó trong mảng trên (Dùng phím 2 để chọn option này)
-Sau khi chọn option này, người dùng sẽ chọn 1 giá trị từ 0 đến 100 để xóa, ví dụ người dùng chọn 50:
    -Nếu giá trị này nằm trong mảng trên thì xóa phần tử này khỏi mảng.
    -Nếu giá trị này không nằm trong mảng, báo lỗi không tồn tại.
-Nếu giá trị người dùng chọn ngoài khoảng từ 0 đến 100, báo lỗi giá trị chọn không đúng.
3. In giá trị các phần từ được nhập vào mảng (Dùng phím 3 để chọn option này)
-Sau khi chọn option này, người dùng chọn
    -1: In các giá trị của mảng khi chưa sắp xếp từ thấp đến cao.
    -2: In các giá trị của mảng được sắp xếp (dùng danh sách liên kết đơn theo yêu cầu ban đầu).
4. Kết thúc chương trình (Dùng phím 4 để chọn option này).
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
