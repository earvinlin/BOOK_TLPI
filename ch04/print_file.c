#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "用法：%s <檔案名稱>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int print_count = 0;

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("開啟檔案失敗");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
        print_count += 1;
    }

    if (bytesRead == -1) {
        perror("讀取檔案失敗");
    }

    printf("呼叫write %i 次。\n", print_count);

    close(fd);
    return 0;
}

