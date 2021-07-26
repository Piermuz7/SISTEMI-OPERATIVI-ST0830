#include <stdio.h>
#include "filebytes.h"

int checkOpeningFile(File *f, char *file) {
    f->fd = fopen(file, "rb");
    if (f->fd == NULL) {
        perror("\nErrore nell' apertura del file");
        return 1;
    }
    return 0;
}

int initializeFile(File *f, char *file) {
    if (checkOpeningFile(f, file))
        return 1;
    f->size = fileSize(*f);
    return 0;
}

long int fileSize(File f) {
    fseek(f.fd, 0L, SEEK_END);
    long int size = ftell(f.fd);
    rewind(f.fd);
    return size;
}

int isEmpty(File f) {
    return f.size == 0;
}

void cleanFile(File *f) {
    fclose(f->fd);
    f->fd = NULL;
    f->size = 0;
}