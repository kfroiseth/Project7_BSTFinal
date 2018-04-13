//Krista Froiseth
//COP2535.0M1
//Project 7 - Binary Search Tree: This program uses a EmployeeBinaryTree which holds an instance of the Employee class. The nodes are sorted by the id number.
//The program prompts the user for an employee ID number, searches the tree and displays the results, either "found along with the employee name" or "ID not found." User can
//continue searching or quit.


#ifndef EMPLOYEEBINARYTREE_H
#define EMPLOYEEBINARYTREE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"
using namespace std;

template<class T>

class EmployeeBinaryTree												//create template so we can work with data type "Employee"
{
private:
	struct TreeNode														//private member variables and functions to operate on the BST
	{
		T value;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void remove(TreeNode *&, T);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:																	//public member functions - these are called from main and will then recursively call the private member functions
	EmployeeBinaryTree<T>()												//includes constructor, destructor, insert, remove, display functions
	{
		root = NULL;
	}
	
	void insertNode(T);		
	bool searchNode(T);
	void removeNode(T);			
	void printName(T);

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};

/********************functions*******************
*************************************************/
template <class T>
void EmployeeBinaryTree<T>::insertNode(T emp)										//Takes employee and creates a node to hold it, will pass this to the private member function for insertion	
{
	TreeNode *newNode;
	newNode = new TreeNode;
	newNode->value = emp;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

template <class T>
void EmployeeBinaryTree<T>::insert(TreeNode *&tree, TreeNode *&newNode)				//will insert the new node containing the employee data into the appropriate node after comparing it to other nodes in the tree
{
	if (tree == NULL)																//if empty, set as root
		tree = newNode;
	
	else if (newNode->value < tree->value)											//if less than root, add to the node on the left
		insert(tree->left, newNode);
	else
		insert(tree->right, newNode);												//else add to the node on the right
}

template <class T>
bool EmployeeBinaryTree<T>::searchNode(T emp)										//bool function to find an employee by ID number
{
	TreeNode *nodePtr = root;														//set pointer to root
	while (nodePtr)
	{
		if (nodePtr->value == emp)													//traverse tree by comparing the input to the tree 
			return true;															//if equal, return true
		else if (nodePtr->value > emp)												//if not, set pointer value to left node and compare
			nodePtr = nodePtr->left;
		else																		//if not, set pointer value to right node and compare
			nodePtr = nodePtr->right;
	}
	return false;																	//if not found in tree, return false
}

template<class T>
void EmployeeBinaryTree<T>::printName(T emp)										//function to print employee information if found
{
	TreeNode *nodePtr = root;														//set pointer to root
	while (nodePtr)
	{
		if (nodePtr->value == emp)													//if equal, print value stored in pointer (name and id number)
			cout << nodePtr->value;
		
		if (nodePtr->value > emp)													//if employee id is less that pointer, set pointer to value in left node
			nodePtr = nodePtr->left;
		else																		//else set pointer to value in right node and continue searching
			nodePtr = nodePtr->right;
	}
	
}

template<class T>
void EmployeeBinaryTree<T>::remove(TreeNode *&tree, T emp)							//function to remove a node 
{
	if (tree == NULL) return;														//if root is null, nothing is in tree to remove, return
	if (emp < tree->value)															//if employee data is less than root, set tree pointer to value in left node
		remove(tree->left, emp);
	else if (emp > tree->value)														//if employee data is greater than root, set tree pointer to value in right node
		remove(tree->right, emp);
	else
		makeDeletion(tree);															//call prviate function to delete node
}

template <class T>
void EmployeeBinaryTree<T>::displayInOrder(TreeNode *nodePtr) const					//display tree in order, traverse left node, process data, traverse right nodes
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}



template <class T>
void EmployeeBinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const				//process data, traverse left nodes, traverse right nodes
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->left);
		displayInOrder(nodePtr->right);
	}
}

template <class T>
void EmployeeBinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const			//traverse left nodes, traverse right nodes, process data
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		displayInOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}


#endif
