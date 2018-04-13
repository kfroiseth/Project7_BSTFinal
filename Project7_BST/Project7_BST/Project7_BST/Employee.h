//Krista Froiseth
//COP2535.0M1
//Project 7 - Binary Search Tree: This program uses a EmployeeBinaryTree which holds an instance of the Employee class. The nodes are sorted by the id number.
//The program prompts the user for an employee ID number, searches the tree and displays the results, either "found along with the employee name" or "ID not found." User can
//continue searching or quit.


#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<iostream>
#include<fstream>
//#include "EmployeeBinaryTree.h"
using namespace std;

class Employee																//create employee class
{
private:																	//private member varibales for employee id and name
	int id;
	string name;

public:																		//public member functions
	Employee()																//default constrcutor
	{}
	
	Employee(int empID, string empName)										//constructor
	{
		id = empID;
		name = empName;
	};
	void setID(int num)														//mutator to set ID number
	{
		id = num;
	}
	void setName(string empName)											//mutator to set employee name
	{
		name = empName;
	}
	int getID() const														//accessor to get ID number
	{ 
		return id;
	}
	string getName() const													//accessor to get employee name
	{ 		
		return name;
	}
	bool operator < (const Employee &right)									//bool operator for "less than" comparisons of type employee								
	{
		bool flag;
		if (id < right.id)
			flag = true;
		else
			flag = false;
		return flag;
	}
	
	bool operator >(const Employee &right)									//bool operator for "greater than" comparisons of type employee
	{
		bool flag;
		if (id > right.id)
			flag = true;
		else
			flag = false;
		return flag;
	}

	bool operator == (const Employee &right)								//bool operator for "equal to" comparisons of type employee
	{
		bool flag;
		if (id == right.id)
			flag = true;
		else
			flag = false;
		return flag;
	}

	friend ostream& operator<<(ostream &strm, Employee &obj)				//insertion operator << for formatting and outputting data of Employee type (name)
	{
		strm << "Employee ID: " << obj.id << " Employee Name: " << obj.name << endl;
		return strm;
	}

};

#endif

