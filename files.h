#ifndef FILES_H
#define FILES_H

#include <stdbool.h>
#include <stdio.h>

typedef enum {
    EXERCISE,
    README
} FileType;

typedef struct {
    char *file_path;
    char *file_name;
    char *file_name_no_ext;
    char *parent_dir_path;
    char *file_contents;
    bool file_diff;
    FileType file_type;
} File;

typedef struct {
    File *files;
    size_t file_ct;
} FileCollection;

/// This assumes that any path does not contain any dividers
/// *base_path = "../" or "./" or "/" if needed, otherwise pass ""
char* build_file_path(char **paths, int size, char *base_path);
char* read_file_contents(char *file_path);
void add_dir(FileCollection **dirs, File *files, int file_ct, int dir_idx);
void load_files(FileCollection **dirs);
int alphasort(const struct dirent **a, const struct dirent **b);

#endif
