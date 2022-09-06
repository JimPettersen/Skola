#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
#include <string>


class SchoolSystem
{
public:
	void Run();
	void AddStudent();
	void RemoveStudent();
	void Menu();
	void CreateAccount();
	void LogIn();



	std::vector<Student> students;
	std::vector<std::string> schoolClasses;
private:
	bool mainLoop = true;
};