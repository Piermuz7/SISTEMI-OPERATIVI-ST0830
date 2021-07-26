//
// Created by piermuz on 18/07/21.
//
/**
 * Un albero binario di ricerca (meglio noto come BST, dall'inglese Binary Search Tree), in informatica,
 * e' un particolare tipo di struttura dati.
 * Permette di effettuare in maniera efficiente operazioni come:
 * ricerca, inserimento e cancellazione di elementi.
 * Ogni nodo u e' un oggetto costituito da diversi campi:
 * key (piu'eventuali dati satellite), un campo left, right e parent che puntano rispettivamente al
 * figlio sinistro, al figlio destro e al padre u.
 * Le chiavi sono sempre memorizzate in modo che sia verificata la proprieta' dell’ albero binario di ricerca:
 * Sia x un nodo di un albero binario di ricerca; allora:
 * se y e' un nodo del sottoalbero sinistro di x allora key[y] <= key[x]
 * se y e' un nodo del sottoalbero destro di x allora key[y] > key[x]
 */
#ifndef BST_BST_H
#define BST_BST_H

/**
 * Struttura dati rappresentante il nodo dell' albero.
 */
typedef struct node {
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

/**
 * Funzione che crea un nuovo BST.
 * @param x il campo chiave del nodo radice da aggiungere al nuovo BST.
 * @return la radice del BST creato, NULL altrimenti.
 */
Node *newNode(int x);

/**
 * Funzione che aggiunge un nuovo nodo con key x, al BST.
 * @param root il nodo radice del BST.
 * @param x il campo chiave del nuovo nodo da aggiungere al BST.
 * @return il nodo radice del BST.
 */
Node *insert(Node *root, int x);

/**
 * Funzione che cerca il nodo con key x, nel BST.
 * @param root il nodo radice del BST.
 * @param x il campo chiave del nodo da cercare nel BST.
 * @return il nodo cercato se presente, NULL altrimenti.
 */
Node *search(Node *root, int x);

/**
 * Funzione che calcola il nodo con campo chiave minimo nel BST.
 * @param root il nodo radice del BST.
 * @return il nodo minimo del BST se presente, NULL altrimenti.
 */
Node *minimum(Node *root);

/**
 * Funzione che calcola il nodo con campo chiave massimo nel BST.
 * @param root il nodo radice del BST.
 * @return il nodo massimo del BST se presente, NULL altrimenti.
 */
Node *maximum(Node *root);

/**
 * Funzione che calcola il nodo successore al nodo con campo chiave x.
 * @param root il nodo radice del BST.
 * @param x il campo chiave del nodo di cui trovarne il successore.
 * @return il nodo successore a quello con campo chiave x se presente, NULL altrimenti.
 */
Node *successor(Node *root, int x);

/**
 * Funzione che calcola il nodo predecessore al nodo con campo chiave x.
 * @param root il nodo radice del BST.
 * @param x il campo chiave del nodo di cui trovarne il predecessore.
 * @return il nodo predecessore a quello con campo chiave x se presente, NULL altrimenti.
 */
Node *predecessor(Node *root, int x);

/**
 * Funzione che elimina il nodo con key x, nel BST.
 * @param root il nodo radice del BST.
 * @param x il campo chiave del nodo da eliminare nel BST.
 * @return il nodo eliminato se presente, NULL altrimenti.
 */
Node *delete(Node *root, int x);

/**
 * Procedura che esegue la visita simmetrica del BST.
 * @param root
 */
void inorderTreeWalk(Node *root);

#endif //BST_BST_H
