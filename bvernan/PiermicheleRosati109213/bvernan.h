#ifndef PIERMICHELEROSATI109213_BVERNAN_H
#define PIERMICHELEROSATI109213_BVERNAN_H

/**
 * Funzione che presi in input i path assoluti o relativi del keyfile,
 * inputfile e outputfile, cripta l' inputfile applicando il cifrario
 * bvernan con il keyfile e scrivendo il risultato ottenuto nell' utputfile.
 * @param keyfile la sequenza di byte rappresentante la chiave.
 * @param inputfile la sequenza di byte da criptare.
 * @param outputfile la sequenza di byte criptati.
 * @return 0 in caso di criptazione dell' inputfile andata a buon fine, 1 altrimenti.
 */
int bvernanEncode(char *keyfile, char *inputfile, char *outputfile);

#endif //PIERMICHELEROSATI109213_BVERNAN_H
