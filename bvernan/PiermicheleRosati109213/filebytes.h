#ifndef PIERMICHELEROSATI109213_FILEBYTES_H
#define PIERMICHELEROSATI109213_FILEBYTES_H

/**
 * Struttura dati utilizzata per memorizzare rispettivamente il file descriptor e la relativa dimensione in byte del file.
 */
typedef struct s_file {
    FILE *fd;
    long size;
} File;

typedef unsigned char byte;

/**
 * Struttura dati utilizzata per memorizzare rispettivamente il byte, la relativa i-esima posizione nel blocco j-esimo ed il numero di blocco j.
 */
typedef struct s_byte {
    byte b;
    int index;
    int numBlock;
} Byte;

/**
 * Funzione che controlla l'apertura del file passato come parametro.
 * In caso di apertura non andata a buon fine viene stampato un messaggio di errore.
 * @param f la struttura dati in cui inizializzare il file descriptor del file da aprire.
 * @param file il path assoluto o relativo del file di cui controllarne l' apertura.
 * @return 0 in caso di apertura andata a buon fine, 1 altrimenti.
 */
int checkOpeningFile(File *f, char *file);

/**
 * Funzione che inizializza la struttura dati f.
 * @param f la struttura dati da inizializzare.
 * @param file il path assoluto o relativo del file da aprire.
 * @return 0 in caso di inizializzazione andata a buon fine, 1 altrimenti.
 */
int initializeFile(File *f, char *file);

/**
 * Funzione che calcola la dimensione del file f in byte.
 * @param f il file di cui calcolarne la dimensione.
 * @return la dimensione in byte del file f.
 */
long fileSize(File f);

/**
 * Funzione che calcola se il file f passato come parametro sia vuoto.
 * @param f il file di cui controllarne se sia vuoto.
 * @return 1 in caso di file vuoto, 0 altrimenti.
 */
int isEmpty(File f);

/**
 * Procedura che chiude il file descriptor e pulisce tutti i campi della struttura dati f.
 * @param f
 */
void cleanFile(File *f);

#endif //PIERMICHELEROSATI109213_FILEBYTES_H
