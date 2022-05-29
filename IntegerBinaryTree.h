#pragma once
#include "iostream"
#include "vector"
#include "climits"

struct TElem {
	int info;
	TElem *left, *right;
	TElem(int info, TElem *left = nullptr, TElem *right = nullptr);
};

struct BadPathException {};
struct NoElemException {};

class IntegerBinaryTree
{
private:
	TElem *root;
	int size;
	void copyTree(TElem* root, TElem* copy);
	void deleteTree(TElem* root);
	void printTree(std::ostream& os, TElem* root, int counter);
	int getEvenCount(TElem* root);
	bool checkPositive(TElem* root);
	bool deleteAllLeaves(TElem* root);
	double getSum(TElem* root);
	bool findElem(TElem* root, int x, std::vector<int> &patn);
	bool isBinarySearchTree(TElem* root, int min, int max);
	void findMin(TElem *root, int &min);
	void findMax(TElem *root, int &max);
public:
	IntegerBinaryTree();
	IntegerBinaryTree(int x);
	IntegerBinaryTree(const IntegerBinaryTree& copy);
	IntegerBinaryTree(IntegerBinaryTree && move);
	~IntegerBinaryTree();
	IntegerBinaryTree& operator=(const IntegerBinaryTree& copy);
	IntegerBinaryTree& operator=(IntegerBinaryTree&& copy);
	void addElem(int x, std::vector<int> path);
	friend std::ostream& operator<<(std::ostream& os, IntegerBinaryTree& obj);
	int getEvenCount();
	bool checkPositive();
	void deleteAllLeaves();
	double getArithmeticMean();
	bool isBinarySearchTree();
	std::vector<int> findElem(int x);
};

