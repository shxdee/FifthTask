#include "IntegerBinaryTree.h"
using namespace std;

void main()
{
	IntegerBinaryTree tree;
	vector<int> v = {};
	tree.addElem(17, v);
	v = { 1 };
	tree.addElem(28, v);
	v = {0};
	tree.addElem(7, v);
	v = { 0, 0 };
	tree.addElem(6, v);
	v = { 0, 1 };
	tree.addElem(16, v);
	v = { 0, 0, 0 };
	tree.addElem(2, v);
	v = { 1, 0 };
	tree.addElem(22, v);
	v = { 1, 0, 1 };
	tree.addElem(25, v);
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
	tree.addElem(-5, v);
	v = {};
	tree.addElem(31, v);
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

