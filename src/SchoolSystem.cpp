#include "SchoolSystem.h"



void SchoolSystem::Run()
{
	Menu();
	while (mainLoop)
	{
		//Menyn
		//Input
		//Feedback
		if (!mainLoop) break;
		std::cin.get();
	}
}

void SchoolSystem::AddStudent()
{
	Student student;
	student.name = "Rick";
	student.age = 18;
	students.push_back(student);
}

void SchoolSystem::RemoveStudent()
{

}

void SchoolSystem::Menu()
{
	int input = 0;
	std::cout << "Welcome to Schoolsystem program\n" << "\nLog in press 1\n" << "Create account press 2\n" << "Close program press 3\n";
	std::cin >> input;

	switch (input)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		mainLoop = false;
		break;
	default:
		break;
	}
	
}

void SchoolSystem::CreateAccount()
{
}

void SchoolSystem::LogIn()
{
}
