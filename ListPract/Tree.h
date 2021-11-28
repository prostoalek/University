#ifndef Tree_h
#define Tree_h
#pragma once
#endif // !Tree_h


enum PrintType {
	Infix,
	Postfix,
	Prefix,
	Cool,
};

struct TreeNode {
public:
	int value;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode() : value(0), left(nullptr), right(nullptr) {};
	TreeNode(int _value) : value(_value), left(nullptr), right(nullptr) {}
};


struct Tree {
public:
	TreeNode* root;

	Tree() : root(nullptr) {};
	Tree(int _value) {
		TreeNode* r = new TreeNode(_value);
		root = r;
	}


	TreeNode* addnode(int x, TreeNode* tree);
	void treePrintPostfix(TreeNode* tree);
	void treePrintInfix(TreeNode* tree);
	void treePrintPrefix(TreeNode* tree);
	void printCool(TreeNode* tree, int lvl);
	void add(int x);
	void freemem(TreeNode* tree);
	void print(PrintType type);
};

