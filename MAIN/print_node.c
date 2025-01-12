#include <stdio.h>
#include <stdlib.h>

#define MAX 3  

typedef struct BPlusNode {
    int keys[MAX];
    struct BPlusNode *children[MAX + 1];  
    int numKeys;  
    int isLeaf;
} BPlusNode;


void printNode(BPlusNode* node) {
    if (node == NULL) {
        printf("Node is NULL\n");
        return;
    }

    printf("Node keys: ");
    for (int i = 0; i < node->numKeys; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\n");

    if (!node->isLeaf) {
        printf("Child pointers: ");
        for (int i = 0; i <= node->numKeys; i++) {
            if (node->children[i] != NULL) {
                printf("[%p] ", node->children[i]);
            }
        }
        printf("\n");
    }
}



