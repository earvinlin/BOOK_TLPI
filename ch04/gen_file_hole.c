/**
 * C 語言範例：建立空洞檔案 
 * 執行後會產生一個邏輯大小為 1GB+1 byte 的檔案，但實際磁碟只儲存 1 byte。
 * 驗證空洞檔案
 * ls -lh hole.txt      # 顯示邏輯大小
 * du -h hole.txt       # 顯示實際磁碟使用量
 * RESULT: 你會發現 ls 顯示檔案很大，但 du 顯示實際空間很小。
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    // 將檔案指標移動到 1GB 處
//    lseek(fd, 1024 * 1024 * 1024, SEEK_SET);
    lseek(fd, 1024 * 10, SEEK_SET);

    // 在 1GB 處寫入一個字元
    write(fd, "X", 1);

    close(fd);
    return 0;
}

