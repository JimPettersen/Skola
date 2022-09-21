#include "SchoolSystem.h"

void SchoolSystem::Run()
{
	std::cout << "Welcome to Schoolsystem program\n";
	while (mainLoop)
	{
		ProgramMenu();
	    //ta bort n�r klar
		//L�gg till Menu() n�r klar
		//Menyn
		//Input
		//Feedback
		if (!mainLoop) break;
	}
	while(loop2)
	{
		ProgramMenu();
	}

}
void SchoolSystem::ProgramMenu()
{
	int input = 0;
	int elevens�lder = 0;
	std::string elevensNamn = "";


	std::cout << "\nAdd student press 1\n" << "Remove student press 2\n"
		<< "Add class press 3\n" << "Add student to class press 4\n" << "Information about classes/students press 5\n" << "Close program press 6\n";
	std::cin >> input;

	switch(input)
	{
	case 1:
		std::cout << "Vad heter eleven? \n";
		std::cin >> elevensNamn;
		std::cout << "Hur gammal �r eleven? \n";
		std::cin >> elevens�lder;
		AddStudent(elevensNamn, elevens�lder);
		break;
	case 2:
		RemoveStudent();
		break;
	case 3:
		break;
	case 4:
		addStudentToClass();
		break;
	case 5:
		info();
		break;
	case 6:
		std::cout << "Bye ";
		loop2 = false;
		break;
	default:
		break;
	}
}

void SchoolSystem::AddStudent(std::string name, int age)
{
	Student student;
	student.name = name;
	student.age = age;
	students.push_back(student);
}

void SchoolSystem::RemoveStudent()
{
	std::string deletStudent = "";
	std::cout << "Vad heter eleven du vill ta bort? \n";
	std::cin >> deletStudent;

	if (students.size() == 0)
	{
		std::cout << "Finns ingen elev vid detta namn\n";
	}

	for (size_t i = 0; i < students.size(); i++)
	{
		for (auto x : students)
		{
			if (x.name == deletStudent)
			{
				students.erase(std::begin(students) + i);
				std::cout << "Removed student " << x.name << "\nList of student \n";
				for (auto k : students)
				{
					std::cout << k.name << ", ";
				}
			}
			else 
			{
				std::cout << "Finns ingen elev vid detta namn\n";
			}
			
		}
		
	}
}

void SchoolSystem::AddClass(std::string klass)
{

}

void SchoolSystem::info()
{
	for (auto k : students)
	{
		std::cout << k.name << ", ";
	}
}

void SchoolSystem::addStudentToClass()
{
	std::string name;
	std::string skolKlass;
	std::cout << "Vad heter eleven? \n";
	std::cin >> name;
	std::cout << "Vilken klass g�r eleven i? \n";
	std::cin >> skolKlass;

	for (auto& classes : schoolClasses)
	{
		if (classes != skolKlass) return;
	}
	
	for (auto& student : students)
	{
		if (student.name == name)student.klass = skolKlass;
	}

}


void SchoolSystem::Menu()
{
	int input = 0;


	std::cout << "Log in press 1\n" << "Create account press 2\n" << "Close program press 3\n";
	std::cin >> input;

	switch (input)
	{
	case 1:
		LogIn();
		break;
	case 2:
		CreateAccount();
		std::cout << "V�lkommen " << Username << "\n";
		break;
	case 3:
		std::cout << "Bye ";
		mainLoop = false;
		break;
	default:
		break;
	};
	
}

void SchoolSystem::CreateAccount()
{
	std::cout << "Vad vill du ha f�r anv�ndarnamn: \n";
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
	std::cout << "Vad vill du ha f�r l�ssenord: \n";
	std::cin >> Password;
	Passwords.push_back(Password);
}

void SchoolSystem::LogIn()
{
	int num = 0;
	int num2 = 0;
	std::cout << "Vad har du f�r anv�ndarnamn: \n";
	std::cin >> Username;
	std::cout << "Vad har du f�r l�ssenord: \n";
	std::cin >> Password;

	for (auto i : Usernames)
	{
		int x = 0;//f�r att sedangemf�ra indexerna s� att r�tt password �r till r�tt username
		if (i == Username)
		{
			x = num;
		}

		for (auto y : Passwords)
		{
			int h = 0;//f�r att sedangemf�ra indexerna s� att r�tt password �r till r�tt username
			if (y == Password)
			{
				h = num2;
			}
			h++;
		}
		x++;
		if (num == num2)
		{
			mainLoop = false;
			loop2 = true;
		}
		else std::cout << "Finns inte \n", Menu();
	};
}
