#include <iostream>
#include <fstream>
#include "array.h"
#include <chrono>
#include <algorithm>
#include <functional>

class tree {
public:
    int info;
    tree* left;
    tree* right;

    tree(int _info)
    {
        info = _info;
        left = nullptr;
        right = nullptr;
    }
};

tree* insert(struct tree* root, int x);

tree* search(struct tree* root, int x);

void inorder(struct tree* root);

void postorder(struct tree* root);

void preorder(struct tree* root);

tree* build_tree(int* tab, int n);

void display_tree(tree* root);

void test_tree();

int get_tree_height(tree* root);

int sortgreater(const void* a, const void* b);