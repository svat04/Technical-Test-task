#include "file_search_lib.h"
#include <windows.h> // Для _MAX_PATH

int main() {
    const char* root_dir = "C:\\";

    // Зберігаємо всі підкаталоги в масиві
    char sub_dirs[MAX_THREADS][_MAX_PATH]; // Змінили PATH_MAX на _MAX_PATH
    int num_sub_dirs = 0;

    // Відкриваємо кореневий каталог
    DIR* dir = opendir(root_dir);
    if (!dir) {
        printf("Помилка при відкритті каталогу: %s\n", root_dir);
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(sub_dirs[num_sub_dirs], _MAX_PATH, "%s/%s", root_dir, entry->d_name); // Змінили PATH_MAX на _MAX_PATH
            num_sub_dirs++;
        }
    }
    closedir(dir);

    // ...
}
