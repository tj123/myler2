#include "system.h"

#include <unistd.h>

int file_exists(const char *file_name)
{
    return access(file_name, 0);
}

int get_files(char *files[], int max_len, const char *file_name)
{
    return 0;
}

int create_dir(const char *dir){
    return 0;
}

char *join_path(char *path1, const char *path2){
    return path1;
}