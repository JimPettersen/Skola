#include "SchoolSystem.h"

void SchoolSystem::Run()
{
	std::cout << "Welcome to Schoolsystem program\n";
	while (mainLoop)
	{
		Menu();
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
	int studentAge = 0;
	std::string studentName = "";
	std::string className = "";


	std::cout << "\nAdd student press 1\n" << "Remove student press 2\n"
		<< "Add class press 3\n" << "Add student to class press 4\n" << "Remove student from class 5\n" <<
		"Information about classes/students press 6\n" << "Close program press 7\n";
	std::cin >> input;

	switch(input)
	{
	case 1:
		std::cout << "What is the name of the student? \n";
		std::cin >> studentName;
		std::cout << "How old is the student? \n";
		std::cin >> className;
		AddStudent(studentName, studentAge);
		break;
	case 2:
		RemoveStudent();
		break;
	case 3:
		std::cout << "What is the name of the class? \n";
		std::cin >> className;
		AddClass(className);
		break;
	case 4:
		addStudentToClass();
		break;
	case 5: 
		RemoveStudentFromClass();
		break;
	case 6:
		info();
		break;
	case 7:
		std::cout << "Bye ";
		loop2 = false;
		break;
	default:
		std::cout << "Error ";
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
	std::cout << "What is the name of the student you want to remove?\n";
	std::cin >> deletStudent;
	std::vector<Student> newStudents;
	for (auto x : students)
	{
		if (x.name != deletStudent)
		{
			newStudents.push_back(x);
		}
		else {
			std::cout << "You removed " << x.name << "\n";
		}
	}
	students = newStudents;
}

void SchoolSystem::RemoveStudentFromClass()
{
	std::string deletStudent = "";
	std::cout << "What is the name of the student you want to remove?\n";
	std::cin >> deletStudent;
	std::vector<Student> newStudents;
	Student stud;
	for (auto x : students)
	{
		if (x.name != deletStudent)
		{
			newStudents.push_back(x);
		}
		else {
			stud = x;
			std::cout << "You removed " << x.name << " from the class:\n" << x.klass << "\n";
		}
	}
	students = newStudents;
	stud.klass = "";
	students.push_back(stud);
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
	int in = 0;
	std::string imp = "";

	std::cout << "Check info about a certain student: 1\n" << "Check info about a certain class: 2\n"
		<< "Check all the info: 3\n";
	std::cin >> in;
	switch (in)
	{
	case 1:
		std::cout << "What is the name of the student?\n";
		std::cin >> imp;
		for (auto k : students)
		{
			if (imp == k.name)
			{
				std::cout << "Age: " << k.age << ", Name: " << k.name << ", Class: " << k.klass << "\n";
			}
		}
		break;
	case 2:
		std::cout << "What is the name of the class?\n";
		std::cin >> imp;
		std::cout << "Students in class: \n";
		for (auto k : students)
		{
			if (k.klass == imp)
			{
				std::cout << k.name << ", ";
			}
		}
		std::cout << "\n";
		break;
	case 3:
		std::cout << "All students: ";
		for (auto k : students)
		{
			std::cout << k.name << ", ";
		}	
		std::cout << "\nAll classes: ";
		for (auto k : students)
		{
			std::cout << k.klass << ", ";
		}
		break;
	default:
		break;
	}
}

void SchoolSystem::addStudentToClass()
{
	std::string name;
	std::string skolKlass;
	std::cout << "What is the name of the student? \n";
	std::cin >> name;
	std::cout << "What class is the student in? \n";
	std::cin >> skolKlass;

	for (auto& classes : schoolClasses)
	{
		if (classes != skolKlass)
		{
			std::cout << "There is no classes by this name";
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
		std::cout << "Welcome " << Username << "\n";
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
	std::cout << "Insert Username: \n";
	std::cin >> Username;

	for (auto i : Usernames)
	{
		if (i == Username)
		{
			std::cout << "Name already used pick another one\n";
			CreateAccount();
		}
	}
	Usernames.push_back(Username);
	std::cout << "Inser password: \n";
	std::cin >> Password;
	Passwords.push_back(Password);
}

void SchoolSystem::LogIn()
{
	int num = 0;
	int num2 = 0;
	std::cout << "What is your username: \n";
	std::cin >> Username;
	std::cout << "What is your password: \n";
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
		else std::cout << "Already exist \n", Menu();
	};
}
