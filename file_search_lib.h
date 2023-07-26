#ifndef FILE_SEARCH_LIB_H
#define FILE_SEARCH_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <limits.h>
#include <pthread.h>
#endif

#define MAX_THREADS 8

void search_file(const char* dir_path, const char* filename);

#ifdef _WIN32
DWORD WINAPI search_thread(LPVOID param);
#else
void* search_thread(void* param);
#endif

#endif // FILE_SEARCH_LIB_H
