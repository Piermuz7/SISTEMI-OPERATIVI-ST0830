//
// Created by piermuz on 18/07/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *newNode(int x) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL)
        fprintf(stderr, "Impossibile allocare un nuovo nodo");
    else {
        node->key = x;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

Node *insert(Node *root, int x) {
    if (root == NULL)    // Se non c'e' nessun nodo crea il BST
        return newNode(x);
    // Altrimenti verifico la proprieta' dei BST
    if (x <= root->key) {
        root->left = insert(root->left, x);
        root->left->parent = root;
    } else {
        root->right = insert(root->right, x);
        root->right->parent = root;
    }
    return root;
}

Node *search(Node *root, int x) {
    if (root == NULL || root->key == x)
        return root;
    if (x <= root->key)
        return search(root->left, x);
    else
        return search(root->right, x);
}

Node *minimum(Node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return minimum(root->left);
    return root;
}

Node *maximum(Node *root) {
    if (root == NULL)
        return NULL;
    else if (root->right != NULL)
        return maximum(root->right);
    return root;
}

Node *successor(Node *root, int x) {
    Node *nx = search(root, x);
    Node *tmp = NULL;
    if (nx != NULL) {
        if (nx->right != NULL)
            return minimum(nx->right);
        tmp = nx->parent;
        while (tmp != NULL && nx != NULL && nx == tmp->right) {
            nx = tmp;
            tmp = tmp->parent;
        }
    }
    return tmp;
}

Node *predecessor(Node *root, int x) {
    Node *nx = search(root, x);
    Node *tmp = NULL;
    if (nx != NULL) {
        if (nx->left != NULL)
            return maximum(nx->left);
        tmp = nx->parent;
        while (tmp != NULL && nx != NULL && nx == tmp->left) {
            nx = tmp;
            tmp = tmp->parent;
        }
    }
    return tmp;
}

Node *delete(Node *root, int x) {
    if (root == NULL)
        return NULL;
    // Altrimenti cerco dove sta il nodo con chiave x
    if (x > root->key)
        root->right = delete(root->right, x);
    else if (x < root->key)
        root->left = delete(root->left, x);
        // Se lo trovo ho 3 casi
    else {
        // Caso 1: il nodo da eliminare e' una foglia
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
            // Caso 2: il nodo da eliminare ha massimo un figlio
        else if (root->left == NULL || root->right == NULL) {
            Node *tmp;
            if (root->left == NULL)
                tmp = root->right;
            else
                tmp = root->left;
            free(root);
            return tmp;
        }
            // Caso 3: il nodo da eliminare ha entrambi i figli
        else {
            Node *tmp = successor(root, x);
            root->key = tmp->key;
            root->right = delete(root->right, tmp->key);
        }
    }
    return root;
}

void inorderTreeWalk(Node *root) {
    if (root != NULL) {
        inorderTreeWalk(root->left);
        printf(" [%d] ", root->key);
        inorderTreeWalk(root->right);
    }
}