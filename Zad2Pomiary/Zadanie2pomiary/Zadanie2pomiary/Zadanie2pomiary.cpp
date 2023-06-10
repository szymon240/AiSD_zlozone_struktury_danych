#include "OWlist.h"
#include "Tree.h"
#include "avltree.h"

int main()
{
	std::cout << "Pomiary w plikach w nanosekundach.\nJednokierunkowa lista:\n";
	Owlist_test();
	//std::cout << "Drzewo binarne:\n";
	std::cout << "Normalne drzewo BST:\n";
	test_tree();
	std::cout << "Drzewo AVL: \n";
	avl_test();
	
	//std::cout << "\n" << get_tree_height(root->right->left) << " " << get_tree_height(root->right->right);
	/*int n;
	std::cin >> n;
	int* test_tab = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> test_tab[i];
	}

	//int option;
	//oWlist* start = nullptr;
	//start = build_owlist(test_tab, n, start);
	//display_owlist(start);

	//tree* root;
	//root = build_tree(test_tab, n);
	//display_tree(root);*/

	return 0;
}