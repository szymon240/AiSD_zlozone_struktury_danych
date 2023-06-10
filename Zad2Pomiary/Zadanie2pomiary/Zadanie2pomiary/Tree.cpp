#include "Tree.h"

//int left_height = 0;
//int right_height = 0;

tree* insert(tree* root, int x) {
    if (root == nullptr) {
        root = new tree(x);
        return(root);
    }
    if (root->info > x)
        root->left = insert(root->left, x);
    else 
    {
        if (root->info < x)
            root->right = insert(root->right, x);
    }
    return root;
}

tree* search( tree* root, int x)
{
     tree* ptr;
    ptr = root;
    while (ptr)
    {
        if (x > ptr->info)
            ptr = ptr->right;
        else if (x < ptr->info)
            ptr = ptr->left;
        else
            break;
    }
    //std::cout << ptr->info << " ";
    return ptr;
}

void inorder( tree* root)
{
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->info;
        inorder(root->right);
    }
}

void postorder( tree* root)
{
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        delete root;
    }

}

void preorder( tree* root)
{
    if (root != nullptr)
    {
        std::cout << root->info;
        preorder(root->left);
        preorder(root->right);
    }
}

tree* build_tree(int *tab, int n)
{
    tree* root = new tree(tab[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, tab[i]);
    }
    return root;
}

void display_tree(tree* root)
{
    if (root->left != nullptr)
        display_tree(root->left);
    std::cout << root->info << " ";
    if (root->right != nullptr)
        display_tree(root->right);
}

void test_tree()
{
    std::ofstream out;
    int lim, down, step;
    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow tworzenia struktury: ";
    std::cin >> down >> lim >> step;
    out.open("./treeCreation.txt", std::fstream::out);
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i <= lim; i += step)
    {
        int* test_array = new int[i];
        create_random_array(test_array, i);
        auto start_time = std::chrono::steady_clock::now();
        tree* root = build_tree(test_array, i);
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] test_array;
    }
    out.close();


    out.open("./treeSearch.txt", std::fstream::out);
    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow przeszukania struktury: ";
    std::cin >> down >> lim >> step;
    int* search_array = new int[lim];
    create_random_array(search_array, lim);
    tree* search_list = nullptr;
    search_list = build_tree(search_array, lim);
    tree* temp = search_list;
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i < lim; i+= step)
    {
        int* search_array = new int[i];
        create_random_array(search_array, i);
        tree* search_list = nullptr;
        search_list = build_tree(search_array, i);
        tree* temp = search_list;
        auto start_time = std::chrono::steady_clock::now();
        for(int j = 0; j < i; j++)
            search(search_list, search_array[j]);
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        //out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] search_array;
    }
    out.close();


    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow usuwania struktury: ";
    std::cin >> down >> lim >> step;
    out.open("./treeDelete.txt", std::fstream::out);
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i <= lim; i += step)
    {
        int* test_array = new int[i];
        create_random_array(test_array, i);
        tree* root = nullptr;
        root = build_tree(test_array, i);
        auto start_time = std::chrono::steady_clock::now();
        postorder(root);
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] test_array;
    }
    out.close();

    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow wysokosci struktury: ";
    std::cin >> down >> lim >> step;
    out.open("./treeHeight.txt", std::fstream::out);
    out << "LiczbaElementow\tWysokosc\n";
    for (int i = down; i <= lim; i += step)
    {
        int* test_array = new int[i];
        create_random_array(test_array, i);
        tree* root = build_tree(test_array, i);
        
        out << i << "\t" << get_tree_height(root) << "\n";
        delete[] test_array;
    }
    out.close();

}

int get_tree_height(tree* root)
{
    if (root == nullptr)
    {
            return 0;
    }
    else
    {
        int left_height = get_tree_height(root->left);
        int right_height = get_tree_height(root->right);
        if (left_height > right_height)
        {
            return (left_height + 1);
        }
        else
            return (right_height + 1);
    }
}

int get_balance(tree* root)
{
    return (get_tree_height(root->left) - get_tree_height(root->right));
}

tree* rotate_right(tree* y)
{
       tree* x = y->left;
       tree* t2 = x->right;
       x->right = y;
       y->left = t2;
       return x;
}

tree* rotate_left(tree* x)
{
    tree* y = x->right;
    tree* t2 = y->left;
    y->left = x;
    x->right = t2;
    return y;
}

tree* avl_insert(tree* root, int x)
{
    if (root == nullptr) {
        root = new tree(x);
        return(root);
    }
    if (root->info > x)
        root->left = insert(root->left, x);
    else if (root->info < x)
            root->right = insert(root->right, x);
    else
        return root;

    int balance = get_balance(root);
    if (balance > 1)
    {
        if (x < root->left->info)
            return rotate_right(root);
        else if (x > root->left->info)
        {
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }
    }
    if (balance < -1)
    {
        if (x > root->right->info)
            return rotate_left(root);
        else if (x < root->right->info)
        {
            root->right = rotate_right(root->left);
            return rotate_left(root);
        }
    }
    return root;

}

tree* build_avl_tree(tree* root, int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        root = avl_insert(root, array[i]);
    }
    return root;
}

int sortgreater(const void* a, const void* b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}
