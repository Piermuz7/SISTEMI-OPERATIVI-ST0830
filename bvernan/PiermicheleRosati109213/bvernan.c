#include <stdio.h>
#include "filebytes.h"
#include "bvernan.h"

/**
 * Funzione privata che calcola lo xor tra il byte in posizione (i+j) % k del keyfile e il byte i-esimo del j-esimo blocco dell' inputfile.
 * @param keyfile il keyfile.
 * @param keyByte il byte in posizione (i+j) % k del keyfile.
 * @param inputByte il byte i-esimo del j-esimo bloco dell' inputfile.
 * @return il byte risultante dallo xor tra keyByte e inputByte.
 */
byte cryptographyFunction(File keyfile, Byte *keyByte, Byte *inputByte);

/**
 * Funzione privata che calcola il numero di blocchi in cui dividere logicamente l' inputfile.
 * La dimensione dei blocchi dipende dalla dimensione dell' inputfile N e del keyfile K.
 * In particolare, se N > K,  N / K da resto != 0, il resto equivale alla dimensione dell' ultimo blocco, altrimenti la dimensione equivale a K.
 * Quindi in caso di resto la dimensione dell' ultimo blocco viene aggiornata tramite indirizzo.
 * @param n la dimensione dell' inputfile.
 * @param k la dimensione dell' outputfile.
 * @param lengthLastBlock l' indirizzo della dimensione dell' ultimo blocco.
 * @return il numero di blocchi in cui dividere logicamente l' inputfile.
 */
long calculateBlocksLength(long n, long k, long *lengthLastBlock);

int bvernanEncode(char *keyfile, char *inputfile, char *outputfile) {
    File key, input;
    FILE *output = fopen(outputfile, "wb");
    if (initializeFile(&key, keyfile) || initializeFile(&input, inputfile))
        return 1;
    if (isEmpty(key)) {
        fprintf(stderr, "Errore: keyfile vuoto!\n");
        return 1;
    }
    long lengthLastBlock = key.size;
    long blocks = calculateBlocksLength(input.size, key.size, &lengthLastBlock);
    int j, i, k;
    Byte keyByte, inputByte;
    byte xor;
    for (j = 0; j < blocks; j++) {
        k = (j != (blocks - 1)) ? key.size : lengthLastBlock;
        for (i = 0; i < k; i++) {
            fread(&inputByte.b, sizeof(byte), 1, input.fd);
            keyByte.index = i;
            keyByte.numBlock = j;
            xor = cryptographyFunction(key, &keyByte, &inputByte);
            fwrite(&xor, sizeof(byte), 1, output);
        }
    }
    cleanFile(&key);
    cleanFile(&input);
    fclose(output);
    return 0;
}

byte cryptographyFunction(File keyfile, Byte *keyByte, Byte *inputByte) {
    fseek(keyfile.fd, ((keyByte->index + keyByte->numBlock) % keyfile.size), SEEK_SET);
    fread(&keyByte->b, sizeof(byte), 1, keyfile.fd);
    return keyByte->b ^ inputByte->b;
}

long calculateBlocksLength(long n, long k, long *lengthLastBlock) {
    long blocks = n / k;
    if ((n % k) != 0) {
        *lengthLastBlock = n % k;
        blocks++;
    }
    return blocks;
}