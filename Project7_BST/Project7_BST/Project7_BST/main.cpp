//Krista Froiseth
//COP2535.0M1
//Project 7 - Binary Search Tree: This program uses a EmployeeBinaryTree which holds an instance of the Employee class. The nodes are sorted by the id number.
//The program prompts the user for an employee ID number, searches the tree and displays the results, either "found along with the employee name" or "ID not found." User can
//continue searching or quit.


#include "Employee.h"							//inlcude Employee file containing employee class
#include "EmployeeBinaryTree.h"					//inlcude EmpoyeeBinaryTree file containing class with methods and BST struct
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*Prototype*/
int getInput();

int main()
{
	EmployeeBinaryTree<Employee> tree;									//create a binary tree object

	Employee info;														//create an employee object
	int number, searchID;												//variables to hold ID number, name, file, and character
	string employeeFName, employeeLName, employeeName;
	fstream file;
	char cont;

	file.open("employee.txt");											//call to open file
	if (!file)															//if file does not exist, notify user
	{
		cout << "Error opening file.\n";
		
	}
	else																//if file exists, open it and read in data line by line to process
	{

		string text;													//variable to hold each line from txt file
		while (getline(file, text))										//get line while there is a next line in the file
		{
			istringstream istr(text);									//create input string to read text directly into variables and operate on
			istr >> number >> employeeFName >> employeeLName;

			employeeName = employeeFName + " " + employeeLName;			//convert employee first name and last name into one string 
			Employee e(number, employeeName);							//create a new employee
			tree.insertNode(e);											//insert new employee into tree
			
		}
		cout << "Binary Tree created and loaded." << endl << endl;				//notify user when file has been read and that all employees have been added to the search tree

		//tree.displayInOrder();										// testing output functions of EmployeeBinaryTree
		tree.displayPostOrder();
		//tree.displayPreOrder();


		do {

			searchID = getInput();											//get valid user input
				
			
			

			info.setID(searchID);											//set the ID number in Employee class

			if (tree.searchNode(info))										//call searchNode function with employee info (ID)
			{
				cout << "Employee Found." << endl;								//if true, let user know ID was found and call function that will print the employee name
				tree.printName(info);
				cout << endl;
			}
			else
			{
				cout << "Employee not found." << endl;							//if false, let user know ID was not found.
			}

			cout << "Search again? Enter Y or N. ";							//prompt user to search again.
			cin >> cont;

		} while (cont == 'Y' || cont == 'y');
	}
	return 0;
}

/*******Get and validate input*******/
int getInput() {
	int num;																				//variable for input
	bool valid = false;																		//create bool variable and set it to false

	while (!valid)																			//start loop for user input
	{
		valid = true;																		//change bool to true, assuming input is correct/valid
		cout << "Please enter and ID to search for: ";												//prompt user
		cin >> num;																		//get input

		if (cin.fail())																		//if input is not an int
		{
			cin.clear();																	//clear buffer
			cin.ignore(20, '\n');															//ignore/discard input in buffer up tp 20 characters or until a new line is reached - this is incase user input a string
			cout << "Invalid input." << endl;								//notify user input was not valid
			valid = false;																	//set bool flag to false and restart loop
		}
	}
		return num;																			//return valid int value
	
}
