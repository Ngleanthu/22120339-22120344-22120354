#include "Menu.h"
void Menu(string username)
{
	int choice;
	if (username.find("staff"))
	{
		
		
		do {
			cout << "1.Class Management" << endl << "2.Course Management" << endl << "Enter your choice : ";
			cin >> choice; 
			if (choice == 1)
			{

			}
			if (choice == 2)
			{

			}
			else {
				cout << "Invalid input";
			}
			system("cls");
		} while (choice != 1 && choice != 2);
		
	}
	else
	{
		do {
			cout << "1.View course" << endl << "2.Scoreboard" << endl << "Enter your choice : ";
			cin >> choice;
			if (choice == 1)
			{

			}
			if (choice == 2)
			{

			}
			else {
				cout << "Invalid input";
			}
			system("cls");
		} while (choice != 1 && choice != 2);
	}


}
