//Name:			Ron Landagan
//Email:		isaac.violin@gmail.com
//ID:			5446632
//Class:		CISC 205
//Assignment:	Chapter 17

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Gemstone.h"
using namespace std;

// Function Declarations
int displayMenu();
int getValidatedChoice(string, int);
Gemstone inputGemstone(vector<Gemstone>);
void getNewID(vector<Gemstone>, Gemstone*);
void getNewName(Gemstone*);
void getNewWeight(Gemstone*);
void getNewAmountPaid(Gemstone*);
void getNewRating(Gemstone*);
string displayRatingMenu();
void searchGemstones(vector<Gemstone>);
void displayGemstones(vector<Gemstone>);
void mostExpensiveGemstone(vector<Gemstone>);

int main()
{
	int choice = 0; // User's choice
	vector<Gemstone> gemstones;

	while (choice != 5)
	{
		Gemstone tempGemstone;
		choice = displayMenu();
		switch (choice) {
		case 1: // Adds a new gemstone to the vector
			tempGemstone = inputGemstone(gemstones);
			gemstones.push_back(tempGemstone);
			break;
		case 2: // Searches for a gemstone by ID
			searchGemstones(gemstones);
			break;
		case 3: // Displays all gemstones
			displayGemstones(gemstones);
			break;
		case 4: // Searches for and displays most-paid gemstone
			mostExpensiveGemstone(gemstones);
			break;
		case 5:
			// Exits program
			cout << "Thank you for using this program." << endl;
			break;
		default:
			// In case the user inputs an invalid menu option
			cout << "Invalid input. Please enter a number from 1 to 5." << endl << endl;
		}
	}
	system("pause");
	return 0;
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   int choice
// calls:     getValidatedChoice
// The displayMenu function presents a menu to the user   *
// and returns the user's choice	                      *
// ********************************************************
int displayMenu() {
	int choice;
	string prompt = "";

	//Create menu to show user
	prompt += "Hello. Welcome to the Gemstone Information program.\n\n";
	prompt += "Please choose one of the following options: \n\n";
	prompt += "1) Enter a new Gemstone \n";
	prompt += "2) Search for a Gemstone by ID number \n";
	prompt += "3) Display all Gemstones \n";
	prompt += "4) Display the most expensive Gemstone \n";
	prompt += "5) Exit \n\n";

	choice = getValidatedChoice(prompt, 5);

	return choice;
}

// ********************************************************
// name:      getValidatedChoice
// called by: displayMenu, displayRatingMenu
// passed:    string prompt, int numberOfChoices
// returns:   int choice
// calls:     nothing
//			  
// The getValidatedChoice function takes in a string and  *
// the number of options to choose from. The function     *
// asks the user for a choice, validates it, and returns  *
// it.													  *
// ********************************************************
int getValidatedChoice(string prompt, int numberOfChoices)
{
	int choice = 0;
	do
	{
		//Display passed-in prompt to user
		cout << prompt << endl;
		cin >> choice;

		//If the user chooses an invalid option
		if (choice < 1 || choice > numberOfChoices)
			cout << "Invalid input. Please choose an option between 1 and " << numberOfChoices << endl << endl;
	} while (choice < 1 || choice > numberOfChoices);

	cout << endl;
	return choice;
}

// ********************************************************
// name:      inputGemstone
// called by: main
// passed:    vector<Gemstone> v
// returns:   Gemstone
// calls:     getNewID, getNewName, getNewWeight, 
//			  getNewAmountPaid, getNewRating
//			  
// The inputGemstone function takes in a vector full of	  *
// Gemstones, creates a new Gemstone and pointer, and	  *
// sets the new information for the Gemstone and returns  *
// it.													  *
// ********************************************************
Gemstone inputGemstone(vector<Gemstone> v)
{
	Gemstone temp;
	Gemstone* gemPtr = &temp;

	// Get the new Gemstone's ID number
	getNewID(v, gemPtr);

	// Get the new Gemstone's name
	getNewName(gemPtr);

	// Get the new Gemstone's weight
	getNewWeight(gemPtr);

	// Get the amount paid for the new Gemstone
	getNewAmountPaid(gemPtr);

	// Get the new Gemstone's rating
	getNewRating(gemPtr);

	return temp;
}

// ********************************************************
// name:      getNewID
// called by: inputGemstone
// passed:    vector<Gemstone> v, Gemstone *temp
// returns:   nothing
// calls:     Gemstone::setID
//			  
// The getNewID function takes in a vector full of	      *
// Gemstones and a pointer to a Gemstone. It asks the user*
// for an ID number, sets it, and catches any exceptions  *
// that are thrown.										  *
// ********************************************************
void getNewID(vector<Gemstone> v, Gemstone *temp)
{
	int ID;
	bool validInput = true;
	do
	{
		try
		{
			cout << endl << "Please enter the new gemstone's ID number:" << endl;
			cin >> ID;
			cout << endl;
			temp->setID(ID, v); // Sets the new ID
			validInput = true;
		}
		catch (Gemstone::NonpositiveInt) // If the passed in value is less than 1
		{
			validInput = false;
			cout << "Error: ID number must be a positive, non-zero number." << endl << endl << endl;
		}
		catch (Gemstone::NonuniqueID) // If another Gemstone in the program has the same ID
		{
			validInput = false;
			cout << "Error: ID number must be unique." << endl << endl << endl;
		}
	} while (validInput == false); // Program loops until an acceptable value is passed in
}

// ********************************************************
// name:      getNewName
// called by: inputGemstone
// passed:    Gemstone *temp
// returns:   nothing
// calls:     Gemstone::setName
//			  
// The getNewName function takes in a pointer to a		  *
// Gemstone and it asks the user for an name, sets it,    *
// and catches any exceptions that are thrown.			  *
// ********************************************************
void getNewName(Gemstone *temp)
{
	string name;
	bool validInput = true;
	cin.ignore();

	do
	{
		try
		{
			cout << endl << "Please enter the new gemstone's name:" << endl;
			getline(cin, name);
			cout << endl;
			temp->setName(name); // Sets the new name
			validInput = true;
		}
		catch (Gemstone::EmptyString) // If the user inputs an empty string
		{
			validInput = false;
			cout << "Error: Name input cannot be empty." << endl << endl << endl;
		}
		catch (Gemstone::TooLongString) // If the user inputs a string over 14 characters long
		{
			validInput = false;
			cout << "Error: Name input must be between 1 and 14 characters long." << endl << endl << endl;
		}
	} while (validInput == false); // Program loops until an acceptable value is passed in
}

// ********************************************************
// name:      getNewWeight
// called by: inputGemstone
// passed:    Gemstone *temp
// returns:   nothing
// calls:     Gemstone::setWeight
//			  
// The getNewWeight function takes in a pointer to a	  *
// Gemstone and it asks the user for a weight, sets it,   *
// and catches any exceptions that are thrown.			  *
// ********************************************************
void getNewWeight(Gemstone *temp)
{
	float weight;
	bool validInput = true;

	do
	{
		try
		{
			cout << endl << "Please enter the new gemstone's weight:" << endl;
			cin >> weight;
			cout << endl;
			temp->setWeight(weight); // Sets the new weight
			validInput = true;
		}
		catch (Gemstone::NegativeFloat) // If the user inputs a float less than 0
		{
			validInput = false;
			cout << "Error: Weight input cannot be a negative number." << endl << endl << endl;
		}
	} while (validInput == false); // Program loops until an acceptable value is passed in
}

// ********************************************************
// name:      getNewAmountPaid
// called by: inputGemstone
// passed:    Gemstone *temp
// returns:   nothing
// calls:     Gemstone::setAmountPaid
//			  
// The getNewAmountPaid function takes in a pointer to a  *
// Gemstone and it asks the user for a float, sets it,    *
// and catches any exceptions that are thrown.			  *
// ********************************************************
void getNewAmountPaid(Gemstone *temp)
{
	float amountPaid;
	bool validInput = true;

	do
	{
		try
		{
			cout << endl << "Please enter the amount paid for the new gemstone:" << endl;
			cin >> amountPaid;
			cout << endl;
			temp->setAmountPaid(amountPaid); // Sets the new amount paid
			validInput = true;
		}
		catch (Gemstone::NegativeFloat) // If the user inputs a float less than 0
		{
			validInput = false;
			cout << "Error: Amount paid cannot be a negative number." << endl << endl << endl;
		}
	} while (validInput == false); // Program loops until an acceptable value is passed in
}

// ********************************************************
// name:      getNewRating
// called by: inputGemstone
// passed:    Gemstone *temp
// returns:   nothing
// calls:     displayRatingMenu, Gemstone::setRating
//			  
// The getNewRating function takes in a pointer to a      *
// Gemstone, asks the user for a rating, sets it, and     *
// catches any exceptions that are thrown.				  *
// ********************************************************
void getNewRating(Gemstone *temp)
{
	int choice;
	string rating;
	bool validInput = true;

	cin.ignore();
	do
	{
		try
		{
			cout << endl;
			rating = displayRatingMenu();
			temp->setRating(rating); // Sets the new rating
			validInput = true;
		}
		catch (Gemstone::EmptyString) // If the user inputs an empty string
		{
			validInput = false;
			cout << "Error: Rating cannot be an empty string." << endl << endl << endl;
		}
		catch (Gemstone::IncorrectRatingFormat) // If the user inputs a rating of the wrong format
		{
			validInput = false;
			cout << "Error: Rating must be of the correct format." << endl << endl << endl;
		}
	} while (validInput == false); // Program loops until an acceptable value is passed in
}

// ********************************************************
// name:      displayRatingMenu
// called by: getNewRating
// passed:    nothing
// returns:   nothing
// calls:     getValidatedChoice
//			  
// The displayRatingMenu function displays a menu to the  *
// user, asking them to choose a rating for the new		  *
// gemstone. It then returns the new star rating.         *
// ********************************************************
string displayRatingMenu() 
{
	int choice;
	string prompt = "", rating = "";

	// Create menu to show user
	prompt += "Please choose the new gemstone's rating: \n\n";
	prompt += "1) * \n";
	prompt += "2) ** \n";
	prompt += "3) *** \n";
	prompt += "4) **** \n";
	prompt += "5) ***** \n\n";

	// Get user's choice
	choice = getValidatedChoice(prompt, 5);

	// Assign rating based on user's choice
	switch (choice)
	{
	case 1:
		rating = "*";
		break;
	case 2:
		rating = "**";
		break;
	case 3:
		rating = "***";
		break;
	case 4:
		rating = "****";
		break;
	case 5:
		rating = "*****";
		break;
	}

	return rating;
}

// ********************************************************
// name:      searchGemstones
// called by: main
// passed:    vector<Gemstone> v
// returns:   nothing
// calls:     Gemstone::print
//			  
// The searchGemstones function asks the user for an ID to*
// search for. The program searches for a Gemstone with   *
// the same ID and prints the results.					  *
// ********************************************************
void searchGemstones(vector<Gemstone> v)
{
	int searchID;
	bool found = false;

	cout << "Please enter an ID to search for: " << endl;
	cin >> searchID;
	cout << endl << endl;

	// Loop through Gemstone vector
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (searchID == it->getID())
		{
			found = true;
			cout << "Gemstone found!" << endl << endl;
			it->print(); // If found, the Gemstone's information is printed
		}
	}
	if (!found) // If there was no ID match
		cout << "Sorry, ID not found in program." << endl << endl << endl;

}

// ********************************************************
// name:      displayGemstones
// called by: main
// passed:    vector<Gemstone> v
// returns:   nothing
// calls:     Gemstone::print, Gemstone::operator+
//			  
// The displayGemstones function displays each Gemstone's *
// information and the total amount paid.				  *
// ********************************************************
void displayGemstones(vector<Gemstone> v)
{
	float totalAmountPaid = 0;

	cout << "\n\n     Gemstone Information" << endl;
	cout << "_____________________________" << endl;
	if (v.empty())
		cout << "There are no gemstones in program." << endl << endl << endl;
	else
	{
		// Loop through Gemstone vector
		for (auto it = v.begin(); it != v.end(); it++)
		{
			totalAmountPaid = *it + totalAmountPaid; // Accumulate total amount paid
			it->print();
		}
		cout << "The total amount paid is: $" << fixed << setprecision(2) 
			<< totalAmountPaid << endl << endl << endl;
	}
}

// ********************************************************
// name:      mostExpensiveGemstone
// called by: main
// passed:    vector<Gemstone> v
// returns:   nothing
// calls:     Gemstone::operator>, Gemstone::getAmountPaid,
//			  Gemstone::print
//			  
// The mostExpensiveGemstone function finds the highest   *
// amount paid Gemstone, and displays it.				  *
// ********************************************************
void mostExpensiveGemstone(vector<Gemstone> v)
{
	int expensiveGemstoneIndex = 0, index = 0;
	float mostExpensive = 0;

	cout << endl << endl;
	if (v.empty())
		cout << "There are no gemstones in program." << endl << endl << endl;
	else
	{
		// Loop through Gemstone vector
		for (auto it = v.begin(); it != v.end(); it++, index++)
		{
			// Finds the highest amount paid value and the Gemstone's index in the vector
			if (*it > mostExpensive)
			{
				mostExpensive = it->getAmountPaid();
				expensiveGemstoneIndex = index;
			}
		}

		cout << "The highest paid gemstone is: " << endl << endl;
		v.at(expensiveGemstoneIndex).print(); // Prints the found Gemstone
		cout << endl << endl;
	}
}
