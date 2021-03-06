// ExceptionHandling.cpp : Defines the entry point for the console application.
//
//
// Write a program that demonstrates the try / catch exception handler blocks for a minimum of 4 different exceptions.
// Include sufficient output to indicate the exception and the condition that caused it.Use more than one catch type.
// Explanation of the exceptions and conditions that caused them should be commented appropriately in the program.
//
// Christopher D Koon
// 6/17/2018
// C++ 275
// Assignment: Exceptions

#include "stdafx.h"
#include <iostream>
#include <exception>
#include <string>

using namespace std;

int main()
{
	// Variables
	string choice;
	int selection = 0;
	int totalPoints = 10;
	string characterName = "";
	int characterHealth = 100;
	int characterStamina = 50;
	int characterMana = 50;

	do 
	{
		// Menu Options
		cout << "Main Menu\n";
		cout << "1. Set Character Name\n";
		cout << "2. Set Character Health\n";
		cout << "3. Set Character Stamina\n";
		cout << "4. Set Character Mana\n";
		cout << "5. Display Current Stats\n";
		cout << "6. Quit\n";
		cout << "Please select an integer from the menu\n";
		cin >> choice;

		// Try Block
		try 
		{
			// Try convert choice to an int and throw an error if it cannot be converted * Throw 1
			selection = stoi(choice);
			// Throw exception if 0, or greater than 6 * Throw 2
			if (selection == 0 && selection > 6)
			{
				throw "Invalid option selected. Please select a valid menu option\n";
			}
			if (selection == 1)
			{
				if (characterName == "")
				{
					cout << "Please select a name for your character.\n";
					cin >> characterName;
				}
				else
				{
					// Throw exception if a name has already been chosen * Throw 3
					throw "Name already set";
				}
			}
			else if (selection == 2)
			{
				if (totalPoints <= 0)
				{ // Throw exception if you have no points to spend * Throw 4
					throw "Not enough points";
				}
				else
				{
					cout << "1 point added to Health\n";
					totalPoints -= 1;
					characterHealth += 10;
				}
			}
			else  if (selection == 3)
			{
				if (totalPoints <= 0)
				{
					// Throw exception if you have no points to spend * Throw 4 (same as other throw 4)
					throw "Not enough points";
				}
				else
				{
					cout << "1 point added to Stamina\n";
					totalPoints -= 1;
					characterStamina += 5;
				}
			}
			else if (selection == 4)
			{
				if (totalPoints <= 0)
				{
					// Throw exception if you have no points to spend * Throw 4 (same as other throw 4)
					throw "Not enough points";
				}
				else
				{
					cout << "1 point added to Mana\n";
					totalPoints -= 1;
					characterMana += 5;
				}
			}
			else  if (selection == 5)
			{
				cout << "Name: " << characterName << endl;
				cout << "Health: " << characterHealth << endl;
				cout << "Stamina: " << characterStamina << endl;
				cout << "Mana: " << characterMana << endl;
			}
		}
		// Catch blocks
		catch (const char* msg)
		{
			// This displays the message from the throw.
			cout << msg << endl;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
		catch (...)
		{
			cout << "An unexpected Error has occured. Please try again\n";
		}
		system("pause");
		system("cls");
	} while (selection != 6);

	cout << "Program End\n";
	system("pause");
    return 0;
}