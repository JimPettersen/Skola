#include "SchoolSystem.h"

void SchoolSystem::Run()
{
	std::cout << "Welcome to Schoolsystem program\n";
	while (mainLoop)
	{
		ProgramMenu();
	    //ta bort när klar
		//Lägg till Menu() när klar
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
	int elevensÅlder = 0;
	std::string elevensNamn = "";
	std::string klassensNamn = "";


	std::cout << "\nAdd student press 1\n" << "Remove student press 2\n"
		<< "Add class press 3\n" << "Add student to class press 4\n" << "Remove student from class 5\n" <<
		"Information about classes/students press 6\n" << "Close program press 7\n";
	std::cin >> input;

	switch(input)
	{
	case 1:
		std::cout << "Vad heter eleven? \n";
		std::cin >> elevensNamn;
		std::cout << "Hur gammal är eleven? \n";
		std::cin >> elevensÅlder;
		AddStudent(elevensNamn, elevensÅlder);
		break;
	case 2:
		RemoveStudent();
		break;
	case 3:
		std::cout << "Vad heter klassen? \n";
		std::cin >> klassensNamn;
		AddClass(klassensNamn);
		break;
	case 4:
		addStudentToClass();
		break;
	case 5: 
		break;
	case 6:
		info();
		break;
	case 7:
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
	Student student;
	student.klass = klass;
	students.push_back(student);
}

void SchoolSystem::info()
{
	Student student;
	std::cout << "Alla students: ";
	for (auto k : students)
	{
		std::cout << k.name << ", ";
	}
	std::cout << "\nAlla klasser: ";
	for (auto k : students)
	{
		std::cout << k.klass << ", ";
	}


}

void SchoolSystem::addStudentToClass()
{
	std::string name;
	std::string skolKlass;
	std::cout << "Vad heter eleven? \n";
	std::cin >> name;
	std::cout << "Vilken klass går eleven i? \n";
	std::cin >> skolKlass;

	for (auto& classes : schoolClasses)
	{
		if (classes != skolKlass)
		{
			std::cout << "Det finns inga klasser vid detta namn";
		}
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
		std::cout << "Välkommen " << Username << "\n";
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
		int x = 0;//för att sedangemföra indexerna så att rätt password är till rätt username
		if (i == Username)
		{
			x = num;
		}

		for (auto y : Passwords)
		{
			int h = 0;//för att sedangemföra indexerna så att rätt password är till rätt username
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
