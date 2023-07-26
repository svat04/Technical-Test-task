#include "file_search_lib.h"

void search_file(const char* dir_path, const char* filename) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            printf("File found: %s/%s\n", dir_path, filename);
            break;
        }
    }

    closedir(dir);
}

#ifdef _WIN32
DWORD WINAPI search_thread(LPVOID param) {
#else
void* search_thread(void* param) {
#endif
    const char* dir_path = (const char*)param;
    char filename[] = "test1.txt"; // Замініть це на назву файлу, який ви хочете знайти
    search_file(dir_path, filename);
#ifdef _WIN32
    return 0;
#else
    pthread_exit(NULL);
#endif
}
