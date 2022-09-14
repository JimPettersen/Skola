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
	void ProgramMenu();

    std::string Username = "";
    std::string Nytt = "";
    std::string Password = "";

	int num = 0;
	int num2 = 0;



	std::vector<Student> students;
	std::vector<std::string>schoolClasses;
	std::vector<std::string>Usernames;
	std::vector<std::string>Passwords;
private:
	bool mainLoop = true;
	bool loop2 = false;
};