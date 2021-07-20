## FILE HANDLING
- FILE (du duoc xay dung bang cach nao): la day cac byte (0-255)
- Nhom ham cap 1: thuc hien doc ghi nhu DOS -> kho su dung, toc do nhanh hon
- Nhom ham cap 2: duoc xay dung tu cac ham cap 1 -> de su dung
	- co dich vu truy xuat cho tung kieu du lieu
	- C cung cap 1 vung dem (mac dinh 512 bytes), moi lan doc ghi se tien hanh tren vung dem
		- khi ghi, data duoc day vao vung dem, khi nao vung dem day moi day len dia
		- khi doc, data duoc lay tu vung dem, khi vung dem rong may moi lay data tu dia
	- lam viec thong qua bien con tro tep
---
### #include <stdio.h>
---
### Kieu nhi phan
- Bao toan du lieu: du lieu ghi tren tep theo cac byte nhi phan nhu trong bo nho
- Ma ket thuc tep: EOF va ham feof() cho gia tri != 0
### Kieu van ban
- Ma chuyen dong: LF (ma 10) -> CR (ma 13) LF (ma 10) (cho phu hop vs DOS)
- Ma ket thuc tep: SUB (ma 26), EOF, feof() != 0
---
### BINARY - TEXT
#### fopen
	FILE *fopen(const char *file_name, const char *type)
	@return: Ptr | NULL
| type | Description |
| ----------- | ----------- |
| "r" "rt" | read mode TEXT, loi neu file ko ton tai |
| "w" "wt" | write mode TEXT, mo file moi, xoa file neu da ton tai |
| "a" "at" | write mode TEXT, ghi bo sung, tao moi file neu chua ton tai |
| "rb" | read mode BINARY, loi neu file ko ton tai |
| "wb" | write mode BINARY, mo file moi, xoa file neu da ton tai |
| "ab" | write mode BINARY, ghi bo sung, tao moi file neu chua ton tai |
| "r+" "r+t" | read/write mode TEXT, loi neu file ko ton tai |
| "w+" "w+t" | read/write mode TEXT, mo file moi, xoa file neu da ton tai |
| "a+" "a+t" | read/write mode TEXT, ghi bo sung, tao moi file neu chua ton tai |
| "r+b" | read/write mode BINARY, loi neu file ko ton tai |
| "w+b" | read/write mode BINARY, mo file moi, xoa file neu da ton tai |
| "a+b" | read/write mode BINARY, ghi bo sung, tao moi file neu chua ton tai |
#### fclose
	int fclose(FILE *fp)
	@return: 0 | EOF
#### fcloseall
	int fcloseall(void)
	@return: n = so tep dong | EOF
#### fflush
	int fflush(FILE *fp)
	@return: 0 | EOF
#### fflushall
	int fflushall(void)
	@return: n = so tep dang mo | EOF
#### ferror
	int ferror(FILE *fp)
	@return: 0 | != 0
#### perror
	void perror(const char *s)
#### feof
	int feof(FILE *fp)
	@return: != 0 | 0
#### unlink - remove
	int unlink(const char *file_name)
	@return: 0 | EOF
	void remove(const char *file_name)
#### rewind
	void rewind(FILE *fp)
#### fseek
	int fseek(FILE *fp, long sb, int posit)
	@param: posit = SEEK_SET | SEEK_CUR | SEEK_END
	@return: 0 | != 0
	NOTE: ko nen dung tren kieu TEXT
#### ftell
	long ftell(FILE *fp)
	@return: int | -1L
#### putc - fputc
	int fputc(int ch, FILE *fp)
	@return: ch | EOF
#### getc - fgetc
	int fgetc(FILE *fp)
	@return: int | EOF
---
### TEXT
#### fprintf
	int fprintf(FILE *fp, "...", ...)
	@return: int so byte ghi | EOF
#### fscanf
	int fscanf(FILE *fp, "...", ...)
	@return: int so truong dc doc
#### fputs
	int fputs(const char *s, FILE *fp)
	@return: ky tu cuoi ('\0' ko ghi len tep) | EOF
#### fgets
	char *fgets(char *s, int n, FILE *fp)
	@return: & | NULL (error hoac EOF)
---
### BINARY
#### putw
	int putw(int n, FILE *fp)
	@return: n | EOF
#### getw
	int getw(FILE *fp)
	@return: int | EOF
#### fwrite
	int fwrite(void *ptr, int size, int n, FILE *fp)
	@return: int so mau in thuc su ghi dc ( <= n)
#### fread
	int fread(void *ptr, int size, int n, FILE *fp)
	@return: int so mau tin thuc su doc dc ( <= n)
---
### STREAMS AND THREADS
#### flockfile
	void flockfile(FILE *stream)
#### ftrylockfile
	int ftrylockfile(FILE *stream)
	@return: 0 | != 0
#### funlockfile
	void funlockfile(FILE *stream)
---
![Streams and Threads](https://live.staticflickr.com/65535/51324940210_c8e838dfd8_h.jpg)
