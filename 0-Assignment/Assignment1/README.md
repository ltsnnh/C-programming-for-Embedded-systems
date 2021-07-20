# Assignment 1
```
Viết một chương trình quản lý mảng số nguyên với các yêu cầu như sau:
Khi chạy chương trình sẽ hiện lời giới thiệu chương trình “CT Quản Lý dãy số bằng mảng” và hướng dẫn sử dụng với các tính năng của chương trình:
- Nhập ‘c’ để tạo mảng số nguyên (Nếu đã có mảng thì clear data của mảng cũ).
- Nhập ‘p’ để in dãy (Nếu dãy chưa có giá trị thì báo dãy trống).
- Nhập ‘i’ để thêm 1 phần tử vào dãy.
- Nhập ‘d’ để xóa 1 phần tử tại vị trí thứ k (Nếu vị trí k không chứa gía trị thì báo ko có phần tử k).
- Nhập ‘s’ để sắp xếp dãy số theo chiều tăng dần.
- Nhập ‘x’ để sắp xếp theo chiều giảm.
- Nhập ‘t’ để tìm kiếm 1 số x có trong dãy không (x nhập từ bàn phím)?
- Nhập ‘a’ để in ra màn hình số lớn nhất.
- Nhập ‘w’ để in ra màn hình số nhỏ nhất.
- Nếu nhập ‘e’ thì thoát chương trình.
```
---
# Coding convention (shortcut)
1. General
- Avoid global variables or else justify their usage.
- Avoid extern variables or else justify their usage.
- No unconditional jumps:
    - break is used only in switch statement.
    - continue is avoided.
    - goto is avoided.
    - return is used only one time at end of function.
2. Variable rule
- One local variable get its own line but not add several local variables into one line like.
- Local variable must be initialized.
---
# Simple Makefile
Let's go through a really juicy Make example that works well for medium sized projects.
Building from different source folder to different target folder.

### This Makefile can be used to build a project with this kind of structure:
    Top-directory/
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

### How to use this Makefile to adapt to your project you have to:
1. Change the BINARY variable to match your target name.
2. Put your C/C++ files in the `src/` folder.
3. Put your Header files in the `inc/` folder.
4. Object files in `obj/` folder, execultive program in root directory.
5. If required, change corresponding flags.
