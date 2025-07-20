#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    lseek(fd, 0, SEEK_SET);  // 移動到檔案開頭
    char buffer[100];
    ssize_t bytes = read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, bytes);

    close(fd);
    return 0;
}
