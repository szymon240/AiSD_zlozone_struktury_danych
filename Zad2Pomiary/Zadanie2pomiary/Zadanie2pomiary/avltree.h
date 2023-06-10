#include <iostream>
#include "array.h"
#include <fstream>
#include <chrono>

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

void preOrder(Node* root);

Node* insert(Node* node, int key);

int getBalance(Node* N);

Node* leftRotate(Node* x);

Node* rightRotate(Node* y);

Node* newNode(int key);

int max(int a, int b);

int height(Node* N);

Node* build_AVL(Node* root, int* array, int size);

void avl_test();