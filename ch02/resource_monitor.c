#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

void show_limit(int resource, const char *name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == -1) {
        perror("getrlimit");
        return;
    }

    printf("🔍 %s:\n", name);
    printf("   軟限制 (rlim_cur): %s\n", 
           limit.rlim_cur == RLIM_INFINITY ? "無限制" : 
           ({ char buf[32]; sprintf(buf, "%ld", limit.rlim_cur); buf; }));
    printf("   硬限制 (rlim_max): %s\n\n", 
           limit.rlim_max == RLIM_INFINITY ? "無限制" : 
           ({ char buf[32]; sprintf(buf, "%ld", limit.rlim_max); buf; }));
}

void set_limit(int resource, rlim_t soft, rlim_t hard) {
    struct rlimit limit = {soft, hard};
    if (setrlimit(resource, &limit) == -1) {
        perror("setrlimit");
    } else {
        printf("✅ 資源限制已更新。\n\n");
    }
}

int main() {
    printf("🧙‍♂️ Linux 資源監控工具\n\n");

    show_limit(RLIMIT_CPU, "CPU 時間限制");
    show_limit(RLIMIT_NOFILE, "檔案描述符數量");
    show_limit(RLIMIT_STACK, "堆疊大小");
    show_limit(RLIMIT_AS, "虛擬記憶體大小");

    char choice[16];
    printf("請選擇要設定的資源 (cpu / nofile / stack / as)：");
    scanf("%15s", choice);

    int resource;
    if (strcmp(choice, "cpu") == 0) resource = RLIMIT_CPU;
    else if (strcmp(choice, "nofile") == 0) resource = RLIMIT_NOFILE;
    else if (strcmp(choice, "stack") == 0) resource = RLIMIT_STACK;
    else if (strcmp(choice, "as") == 0) resource = RLIMIT_AS;
    else {
        printf("❌ 無效的選項。\n");
        return 1;
    }

    rlim_t soft, hard;
    printf("請輸入新的軟限制 (數字或 -1 表示無限制)：");
    scanf("%ld", &soft);
    printf("請輸入新的硬限制 (數字或 -1 表示無限制)：");
    scanf("%ld", &hard);

    if (soft == -1) soft = RLIM_INFINITY;
    if (hard == -1) hard = RLIM_INFINITY;

    set_limit(resource, soft, hard);
    show_limit(resource, "更新後的資源限制");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

void show_limit(int resource, const char *name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == -1) {
        perror("getrlimit");
        return;
    }

    printf("🔍 %s:\n", name);
    printf("   軟限制 (rlim_cur): %s\n", 
           limit.rlim_cur == RLIM_INFINITY ? "無限制" : 
           ({ char buf[32]; sprintf(buf, "%ld", limit.rlim_cur); buf; }));
    printf("   硬限制 (rlim_max): %s\n\n", 
           limit.rlim_max == RLIM_INFINITY ? "無限制" : 
           ({ char buf[32]; sprintf(buf, "%ld", limit.rlim_max); buf; }));
}

void set_limit(int resource, rlim_t soft, rlim_t hard) {
    struct rlimit limit = {soft, hard};
    if (setrlimit(resource, &limit) == -1) {
        perror("setrlimit");
    } else {
        printf("✅ 資源限制已更新。\n\n");
    }
}

int main() {
    printf("🧙‍♂️ Linux 資源監控工具\n\n");

    show_limit(RLIMIT_CPU, "CPU 時間限制");
    show_limit(RLIMIT_NOFILE, "檔案描述符數量");
    show_limit(RLIMIT_STACK, "堆疊大小");
    show_limit(RLIMIT_AS, "虛擬記憶體大小");

    char choice[16];
    printf("請選擇要設定的資源 (cpu / nofile / stack / as)：");
    scanf("%15s", choice);

    int resource;
    if (strcmp(choice, "cpu") == 0) resource = RLIMIT_CPU;
    else if (strcmp(choice, "nofile") == 0) resource = RLIMIT_NOFILE;
    else if (strcmp(choice, "stack") == 0) resource = RLIMIT_STACK;
    else if (strcmp(choice, "as") == 0) resource = RLIMIT_AS;
    else {
        printf("❌ 無效的選項。\n");
        return 1;
    }

    rlim_t soft, hard;
    printf("請輸入新的軟限制 (數字或 -1 表示無限制)：");
    scanf("%ld", &soft);
    printf("請輸入新的硬限制 (數字或 -1 表示無限制)：");
    scanf("%ld", &hard);

    if (soft == -1) soft = RLIM_INFINITY;
    if (hard == -1) hard = RLIM_INFINITY;

    set_limit(resource, soft, hard);
    show_limit(resource, "更新後的資源限制");

    return 0;
}

