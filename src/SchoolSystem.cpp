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
		LogIn();
		break;
	case 2:
		CreateAccount();
		std::cout << "Välkommen " << Username << "\n";
		break;
	case 3:
		std::cout << "Bye ";
		mainLoop = false;
		break;
	default:
		break;
	}
	Menu();
	
}

void SchoolSystem::CreateAccount()
{
	std::cout << "Vad vill du ha för användarnamn: \n";
	std::cin >> Username;

	for (auto i : Usernames)
	{
		if (i == Username)
		{
			std::cout << "Finns redan\n";
			CreateAccount();
		}
	}
	Usernames.push_back(Username);
	std::cout << "Vad vill du ha för lössenord: \n";
	std::cin >> Password;
	Passwords.push_back(Password);
}

void SchoolSystem::LogIn()
{
	int num = 0;
	int num2 = 0;
	std::cout << "Vad har du för användarnamn: \n";
	std::cin >> Username;
	std::cout << "Vad har du för lössenord: \n";
	std::cin >> Password;
	for (auto i : Usernames)
	{
		int x = 0;
		if (i == Username)
		{
			x = num;
		}
			
		for (auto y : Passwords) 
		{
			int h = 0;
			if (y == Password)
			{
				h = num2;
			}
			h++;
		}
		x++;
		if (num == num2)
		{
			ProgramMenu();
		}
		else std::cout << "Finns inte \n", Menu();
	}
}

void SchoolSystem::ProgramMenu()
{
	std::cout << "You made it yay \n";
	std::cin >> num;
}
