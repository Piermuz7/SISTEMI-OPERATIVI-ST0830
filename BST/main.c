#include <stdio.h>
#include <assert.h>
#include "bst.h"

int main(int argc, char** argv) {
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    Node *root = NULL;
    assert(successor(root,0) == NULL);
    assert(predecessor(root,0) == NULL);
    assert(minimum(root) == NULL);
    assert(maximum(root) == NULL);
    root = newNode(20);
    assert(root != NULL);
    assert(root->key == 20);
    assert(root->parent == NULL);
    assert(root->left == NULL);
    assert(root->right == NULL);
    assert(successor(root,20) == NULL);
    assert(predecessor(root,20) == NULL);
    assert(minimum(root) == root);
    assert(maximum(root) == root);
    insert(root,5);
    Node *n5 = search(root,5);
    assert(root->left == n5);
    assert(n5->key == 5);
    assert(n5->parent == root);
    assert(n5->parent->key == 20);
    assert(root->right == NULL);
    assert(n5->left == NULL);
    assert(n5->right == NULL);
    assert(successor(root,5) == root);
    assert(predecessor(root,20) == n5);
    assert(minimum(root) == n5);
    assert(maximum(root) == root);
    insert(root,1);
    Node *n1 = search(root,1);
    assert(n5->left == n1);
    assert(n1->key == 1);
    assert(n1->left == NULL);
    assert(n1->right == NULL);
    assert(n1->parent == n5);
    assert(successor(root,1) == n5);
    assert(predecessor(root,1) == NULL);
    assert(minimum(root) == n1);
    assert(maximum(root) == root);
    insert(root,15);
    Node *n15 = search(root,15);
    assert(n5->right == n15);
    assert(n15->key == 15);
    assert(n15->left == NULL);
    assert(n15->right == NULL);
    assert(n15->parent == n5);
    assert(successor(root,15) == root);
    assert(predecessor(root,15) == n5);
    assert(minimum(root) == n1);
    assert(maximum(root) == root);
    insert(root,9);
    Node *n9 = search(root,9);
    assert(n15->left == n9);
    assert(n9->key == 9);
    assert(n9->left == NULL);
    assert(n9->right == NULL);
    assert(n9->parent == n15);
    assert(successor(root,9) == n15);
    assert(predecessor(root,9) == n5);
    assert(minimum(root) == n1);
    assert(maximum(root) == root);
    insert(root,7);
    Node *n7 = search(root,7);
    assert(n9->left == n7);
    assert(n7->key == 7);
    assert(n7->left == NULL);
    assert(n7->right == NULL);
    assert(n7->parent == n9);
    assert(successor(root,7) == n9);
    assert(predecessor(root,7) == n5);
    assert(minimum(root) == n1);
    assert(maximum(root) == root);
    insert(root,12);
    Node *n12 = search(root,12);
    assert(n9->right == n12);
    assert(n12->key == 12);
    assert(n12->left == NULL);
    assert(n12->right == NULL);
    assert(n12->parent == n9);
    assert(successor(root,12) == n15);
    assert(predecessor(root,12) == n9);
    assert(minimum(root) == n1);
    assert(maximum(root) == root);
    insert(root,30);
    Node *n30 = search(root,30);
    assert(root->right == n30);
    assert(n30->key == 30);
    assert(n30->left == NULL);
    assert(n30->right == NULL);
    assert(n30->parent == root);
    assert(successor(root,30) == NULL);
    assert(predecessor(root,30) == root);
    assert(minimum(root) == n1);
    assert(maximum(root) == n30);
    insert(root,25);
    Node *n25 = search(root,25);
    assert(n30->left == n25);
    assert(n25->key == 25);
    assert(n25->left == NULL);
    assert(n25->right == NULL);
    assert(n25->parent == n30);
    assert(successor(root,25) == n30);
    assert(predecessor(root,25) == root);
    assert(minimum(root) == n1);
    assert(maximum(root) == n30);
    insert(root,40);
    Node *n40 = search(root,40);
    assert(n30->right == n40);
    assert(n40->key == 40);
    assert(n40->left == NULL);
    assert(n40->right == NULL);
    assert(n40->parent == n30);
    assert(successor(root,40) == NULL);
    assert(predecessor(root,40) == n30);
    assert(minimum(root) == n1);
    assert(maximum(root) == n40);
    insert(root, 45);
    Node *n45 = search(root,45);
    assert(n40->right == n45);
    assert(n45->key == 45);
    assert(n45->left == NULL);
    assert(n45->right == NULL);
    assert(n45->parent == n40);
    assert(successor(root,45) == NULL);
    assert(predecessor(root,45) == n40);
    assert(minimum(root) == n1);
    assert(maximum(root) == n45);
    insert(root, 42);
    Node *n42 = search(root,42);
    assert(n45->left == n42);
    assert(n42->key == 42);
    assert(n42->left == NULL);
    assert(n42->right == NULL);
    assert(n42->parent == n45);
    assert(successor(root,42) == n45);
    assert(predecessor(root,42) == n40);
    assert(minimum(root) == n1);
    assert(maximum(root) == n45);
    inorderTreeWalk(root); // 1, 5, 7, 9, 12, 15, 20, 25, 30, 42, 45, 40
    printf("\n");
    // Nodi presenti nel BST
    assert(predecessor(root,1) == NULL);
    assert(successor(root,1) == n5);
    assert(predecessor(root,5) == n1);
    assert(successor(root,5) == n7);
    assert(predecessor(root,7) == n5);
    assert(successor(root,7) == n9);
    assert(predecessor(root,9) == n7);
    assert(successor(root,9) == n12);
    assert(predecessor(root,12) == n9);
    assert(successor(root,12) == n15);
    assert(predecessor(root,15) == n12);
    assert(successor(root,15) == root);
    assert(predecessor(root,20) == n15);
    assert(successor(root,25) == n30);
    assert(predecessor(root,30) == n25);
    assert(successor(root,30) == n40);
    assert(predecessor(root,42) == n40);
    assert(successor(root,42) == n45);
    assert(predecessor(root,45) == n42);
    assert(successor(root,45) == NULL);
    assert(predecessor(root,40) == n30);
    assert(successor(root,40) == n42);
    // Nodi non presenti nel BST
    assert(predecessor(root,0) == NULL);
    assert(successor(root,21) == NULL);

    root = delete(root, 1);
    assert(search(root,1) == NULL);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42
    */

    root = delete(root, 40);
    assert(search(root,40) == NULL);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       /
                /       /
               9       42
             /   \
            /     \
           7      12
    */

    root = delete(root, 45);
    assert(search(root,45) == NULL);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /
                /
               9
             /   \
            /     \
           7      12
    */
    root = delete(root, 9);
    assert(search(root,9) == NULL);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /
                /
               12
             /
            /
           7
    */
    inorderTreeWalk(root);  // 5, 7, 12, 15, 20, 25, 39, 42
    printf("\n");
    return 0;
}
