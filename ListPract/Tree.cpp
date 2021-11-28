#include<iostream>
#include "Tree.h"


TreeNode* Tree::addnode(int x, TreeNode* tree)
{
	if (tree == nullptr) {
		tree = new TreeNode();
		tree->value = x;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (x < tree->value)
		tree->left = addnode(x, tree->left);
	else
		tree->right = addnode(x, tree->right);
	return tree;
}

void Tree::treePrintPostfix(TreeNode* tree)
{
	if (tree != nullptr) {
		treePrintPostfix(tree->left);
		treePrintPostfix(tree->right);
		std::cout << tree->value;
	}
}

void Tree::treePrintInfix(TreeNode* tree)
{
	if (tree != nullptr) {
		treePrintInfix(tree->left);
		std::cout << tree->value;
		treePrintInfix(tree->right);
	}
}

void Tree::treePrintPrefix(TreeNode* tree)
{
	if (tree != nullptr) {
		std::cout << tree->value;
		treePrintPrefix(tree->left);
		treePrintPrefix(tree->right);
	}
}

void Tree::printCool(TreeNode* tree, int lvl)
{
	if (tree == nullptr)
		return;
	else {
		printCool(tree->left, ++lvl);
		for (int i = 0; i < lvl; i++)
			std::cout << "    ";
		std::cout << tree->value << "\n";
		lvl--;
	}
	printCool(tree->right, ++lvl);
}

void Tree::add(int x)
{
	root = addnode(x, root);
}

void Tree::freemem(TreeNode* tree)
{
	if (tree != nullptr) {
		freemem(tree->left);
		freemem(tree->right);
		delete tree;
	}
}

void Tree::print(PrintType type)
{
	switch (type) {
	case Postfix:
		treePrintPostfix(root);
		break;
	case Infix:
		treePrintInfix(root);
		break;
	case Prefix:
		treePrintPrefix(root);
		break;
	case Cool:
		std::cout << "Cool\n";
		printCool(root, 0);
		std::cout << "\n";
		break;
	default:
		break;
	}
}


