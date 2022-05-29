#include "IntegerBinaryTree.h"

TElem::TElem(int info, TElem * left, TElem * right)
{
	this->info = info;
	this->left = left;
	this->right = right;
}

void IntegerBinaryTree::copyTree(TElem* root, TElem* copy)
{
	if (!copy) {
		return;
	}
	root = new TElem(copy->info);
	copyTree(root->left, copy->left);
	copyTree(root->right, copy->right);
}

void IntegerBinaryTree::deleteTree(TElem* root)
{
	if (!root) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	if ((!root->left) && (!root->right)) {
		delete root;
	}
}

void IntegerBinaryTree::printTree(std::ostream & os, TElem* root, int counter)
{
	if (!root) {
		return;
	}
	for (int i = 0; i < counter; i++) {
		os << "\t";
	}
	os << root->info <<std::endl;
	printTree(os, root->left, counter+1);
	printTree(os, root->right, counter+1);
}

int IntegerBinaryTree::getEvenCount(TElem * root)
{
	if (!root) { return 0; }
	if (root->info % 2 == 0) {
		return (1 + getEvenCount(root->left) + getEvenCount(root->right));
	}
	return (getEvenCount(root->left) + getEvenCount(root->right));

}

bool IntegerBinaryTree::checkPositive(TElem * root)
{
	if (!root) {
		return true;
	}
	if (root->info <= 0) {
		return false;
	}
	if (!checkPositive(root->left)) {
		return false;
	}
	if (!checkPositive(root->right)) {
		return false;
	}
	return true;
}

bool IntegerBinaryTree::deleteAllLeaves(TElem * root)
{
	if (!root) { return false; }
	if (!root->left && !root->right) {
		delete root;
		return true;
	}
	else {
		if (deleteAllLeaves(root->left)) { root->left = nullptr; }
		if (deleteAllLeaves(root->right)) { root->right = nullptr; }
	}
	return false;
}

double IntegerBinaryTree::getSum(TElem * root)
{
	if (!root) { return 0; }
	return(root->info + getSum(root->left) + getSum(root->right));
}

bool IntegerBinaryTree::findElem(TElem * root, int x, std::vector<int> &path)
{
	if (!root) { return false; }
	if (root->info == x) {
		return true;
	}
	path.push_back(0);
	if (findElem(root->left, x, path)) { return true; }
	path.pop_back();
	path.push_back(1);
	if (findElem(root->right, x, path)) { return true; }
	path.pop_back();
	return false;
}

bool IntegerBinaryTree::isBinarySearchTree(TElem * root, int min, int max)
{
	if (!root) { return true; }
	if (root->info < min || root->info > max) {
		return false;
	}
	if (root->info == min && root->left && this->root->info == root->info) {
		return false;
	}
	if (root->info == max && root->right && this->root->info == root->info) {
		return false;
	}
	return isBinarySearchTree(root->left, min, root->info) && isBinarySearchTree(root->right, root->info, max);
}

void IntegerBinaryTree::findMin(TElem * root, int & min)
{
	if (!root) { return; }
	if (root->info < min) {
		min = root->info;
	}
	findMin(root->left, min);
	findMin(root->right, min);
}

void IntegerBinaryTree::findMax(TElem * root, int & max)
{
	if (!root) { return; }
	if (root->info > max) {
		max = root->info;
	}
	findMax(root->left, max);
	findMax(root->right, max);
}





IntegerBinaryTree::IntegerBinaryTree()
{
	root = nullptr;
	size = 0;
}

IntegerBinaryTree::IntegerBinaryTree(int x)
{
	root = new TElem(x);
	size = 1;
}

IntegerBinaryTree::IntegerBinaryTree(const IntegerBinaryTree &copy)
{
	if (!copy.root) {
		return;
	}
	size = copy.size;
	TElem *copyroot = copy.root;
	copyTree(root, copyroot);
}

IntegerBinaryTree::IntegerBinaryTree(IntegerBinaryTree &&move)
{
	std::swap(root, move.root);
	size = move.size;
}


IntegerBinaryTree::~IntegerBinaryTree()
{
	deleteTree(root);
}

IntegerBinaryTree & IntegerBinaryTree::operator=(const IntegerBinaryTree & obj)
{
	if (this == &obj) { return *this; }
	this->deleteTree(root);
	root = new TElem(obj.root->info);
	copyTree(root, obj.root);
	return *this;
}

IntegerBinaryTree & IntegerBinaryTree::operator=(IntegerBinaryTree && obj)
{
	std::swap(root, obj.root);
	size = obj.size;
	return *this;
}

void IntegerBinaryTree::addElem(int x, std::vector<int> path)
{
	TElem *current = root;
	if (!root && path.size() > 0) {
		throw BadPathException();
	}
	if (!root && path.size() == 0) {
		root = new TElem(x);
		return;
	}
	if (path.size() == 0) {
		root->info = x;
		return;
	}
	for (int i = 0; i < (path.size()-1); i++) {
		if (path[i] == 0) {
			current = current->left;
		}
		if (path[i] == 1) {
			current = current->right;
		}
		if (path[i] != 1 && path[i] != 0) {
			throw BadPathException();
		}
	}
	if (!current || (path.back()!=1 && path.back()!=0)) {
		throw BadPathException();
	}
	if (path.back() == 0) {
		if (!current->left) {
			current->left = new TElem(x);
			size++;
		}
		else {
			current->left->info = x;
		}
	}
	if (path.back() == 1) {
		if (!current->right) {
			current->right = new TElem(x);
			size++;
		}
		else {
			current->right->info = x;
		}
	}
}

int IntegerBinaryTree::getEvenCount()
{
	return getEvenCount(root);
}

bool IntegerBinaryTree::checkPositive()
{
	return checkPositive(root);
}

void IntegerBinaryTree::deleteAllLeaves()
{
	deleteAllLeaves(root);
}

double IntegerBinaryTree::getArithmeticMean()
{
	return getSum(root)/size;
}

bool IntegerBinaryTree::isBinarySearchTree()
{
	int max = INT_MIN, min = INT_MAX;
	findMin(root->left, min);
	findMax(root->right, max);
	return isBinarySearchTree(root, min, max);
}

std::vector<int> IntegerBinaryTree::findElem(int x)
{
	std::vector<int> path = {};
	if (!findElem(root, x, path)) {
		throw NoElemException();
	}
	return path;
}

std::ostream & operator<<(std::ostream & os, IntegerBinaryTree &obj)
{
	obj.printTree(os, obj.root, 0);
	return os;
}
