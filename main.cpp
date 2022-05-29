#include "IntegerBinaryTree.h"
using namespace std;

void main()
{
	IntegerBinaryTree tree;
	vector<int> v = {};
	tree.addElem(10, v);
	v = { 1 };
	tree.addElem(21, v);
	v = { 0 };
	tree.addElem(7, v);
	v = { 0, 0 };
	tree.addElem(4, v);
	v = { 0, 1 };
	tree.addElem(9, v);
	v = { 0, 0, 0 };
	tree.addElem(2, v);
	v = { 1, 0 };
	tree.addElem(16, v);
	v = { 1, 0, 1 };
	tree.addElem(19, v);
	cout << tree << endl;
	cout << endl;

	cout << "Even elements count - " << tree.getEvenCount() << endl;
	cout << "Is positive - " << tree.checkPositive() << endl;
	cout << "ArithmeticMean - " << tree.getArithmeticMean() << endl;
	cout << "isBinarySearch - " << tree.isBinarySearchTree() << endl;
	v = tree.findElem(16);
	cout << "Path to elem 16: " << v[0] << " " << v[1] << endl;
	cout << endl;

	
	v = { 0, 0, 0 };
	tree.addElem(-1, v);
	v = {};
	tree.addElem(45, v);
	cout << tree << endl;
	cout << endl;

	cout << "Even elements count - " << tree.getEvenCount() << endl;
	cout << "Is positive - " << tree.checkPositive() << endl;
	cout << "ArithmeticMean - " << tree.getArithmeticMean() << endl;
	cout << "isBinarySearch - " << tree.isBinarySearchTree() << endl;
	cout << endl;

	
	tree.deleteAllLeaves();
	cout << tree << endl;
	cout << "Even elements count - " << tree.getEvenCount() << endl;
	cout << "Is positive - " << tree.checkPositive() << endl;
	cout << "ArithmeticMean - " << tree.getArithmeticMean() << endl;
	cout << "isBinarySearch - " << tree.isBinarySearchTree() << endl;
}

