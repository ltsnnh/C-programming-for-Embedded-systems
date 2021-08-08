# MOCK1
```
Mọi người được cung cấp 1 file image của 1 bảng FAT (FAT12).
Tất cả các bài tập dưới đây mọi người sẽ thao tác với file này thay vì thao tác với ổ đĩa thực.
Chúng ta sẽ mặc định rằng đây là FAT12 và mỗi sector có 512 byte

I. Phần basic:
    1. Viết các hàm để thao tác đến lớp vật lý (tạo file HAL.h và HAL.c)
        Bình thường, người ta sẽ chia file system thanh các layer.
        Layer giao tiếp với lớp vật lý gọi la Hardware abtraction layer (HAL).
        Lớp này sẽ được thây đổi tùy theo cấu trúc vật lý của hệ thống.
        Các lớp trên sẽ chỉ gọi đến các hàm của lớp này mà không truy xuất trực tiếp đến phần cứng của hệ thống.

        Đối với bài toán của chúng ta, HAL sẽ thao tác đến file image thay vì ổ đĩa thực.
        Tất cả các chương trình khác sẽ gọi các hàm ở lớp này.
        Sau này, khi muốn đọc từ ổ đĩa thực, chúng ta chỉ việc thay đổi file này mà không cần đả động gì đến các file chương trình khác.

        HAL của chúng ta sẽ cần ít nhất là các hàm sau:

            a) int32_t kmc_read_sector(uint32_t index, uint8_t *buff)
                Hàm này read sector thứ index vào buff, trả về số byte được đọc.

            b) int32_t kmc_read_multi_sector(uint32_t index, uint32_t num, uint8_t *buff)
                Đọc num sector liên tiếp, bắt đầu từ sector thứ index, vào mảng trỏ bởi buff.
                Hàm này trả về số byte được đọc

        Ngoài những hàm trên, nếu mọi người thấy cần thêm hàm nào khác để code thuận tiện hơn thì tự thêm vào.

    2. Viết chương trình để (Tạo file ví dụ: read_file.h và read_file.c)
        a) Hiển thị tất cả các folder và file trong thư mục gốc.
        b) Cho phép hiển thị các thư mục con và file ở trong 1 thư mục
        c) Hiển thị nội dung của 1 file được lựa chọn lên màn hình.

        Do ở đây ta không chú trọng đến phần lập trình đồ họa, nên mọi người hãy nghĩ cách đơn giản nhất để làm.
        Ví dụ printf ra màn hình, sau đó nhập vào 1 để mở file thứ 1...

        Các mục a, b, c ở trên có thể làm riêng biệt, từ dễ đến khó hoặc làm gộp làm 1 chương trình.

    * Các bài tập trên chỉ cần thao tác với tên file ngắn mà không cần chú ý đến Long File Name

II. Phần Advance:
    Xử lý cả 3 loại FAT12/FAT16/FAT32 và Long file name
    Sau khi đã làm được phần basic ở trên, hãy viết FAT file system library.
    Library này cho phép mở file, đọc file, ghi file... Giống như các hàm fopen, fread, fwrite...

```
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

### How to use this Makefile To adapt this Makefile to your project you have to:
1. Change the BINARY variable to match your target name.
2. Put your C/C++ files in the `src/` folder.
3. Put your Header files in the `inc/` folder.
4. Object files in `obj/` folder, execultive program in root directory.
5. If required, change the compiler and the flags.
