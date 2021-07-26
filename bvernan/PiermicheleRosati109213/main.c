#include <stdio.h>
#include "bvernan.h"

int main(int argc, char **argv) {
    int result;
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <keyfile> <inputfile> <outputfile>\n",argv[0]);
        return 1;
    }
    result = bvernanEncode(argv[1], argv[2], argv[3]);
    if (result)
        fprintf(stderr, "Errore in fase di criptazione.\n");
    else
        fprintf(stderr, "Criptazione del file %s avvenuta con successo.\n", argv[2]);
    return 0;
}