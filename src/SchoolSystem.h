#pragma once
#include "Student.h"
#include <vector>
#include <iostream>
#include <string>


class SchoolSystem
{
public:
	void Run();
	void AddStudent(std::string name, int age);
	void RemoveStudent();
	void AddClass(std::string klass);
	void Menu();
	void CreateAccount();
	void LogIn();
	void ProgramMenu();
	void info();
	void addStudentToClass();

    std::string Username = "";
    std::string Nytt = "";
    std::string Password = "";
	std::string studentName = "";
	std::string studentAge = "";

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