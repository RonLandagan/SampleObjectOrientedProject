//Name:			Ron Landagan
//Email:		isaac.violin@gmail.com
//ID:			5446632
//Class:		CISC 205
//Assignment:	Chapter 17

// Implementation file for Gemstone class
#include "Gemstone.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

// ********************************************************
// name:      setID
// passed:    int n, vector<Gemstone> v
// returns:   nothing
// calls:     nothing
//			  
// The setID function takes in an int value and throws an *
// exception if it is less than 1 or if another gemstone  *
// has the same value. If an exception wasn't thrown, the *
// passed in int becomes the ID.					      *
// ********************************************************
void Gemstone::setID(int n, vector<Gemstone> v)
{
	if (n < 1)
		throw NonpositiveInt();
	else
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (n == it->getID())
				throw NonuniqueID();
		}
	}
	ID = n;
}

// ********************************************************
// name:      setName
// passed:    string n
// returns:   nothing
// calls:     nothing
//			  
// The setName function takes in a string and throws an   *
// exception if it is more than 14 characters long or if  *
// it is empty. If an exception wasn't thrown, the passed *
// in string becomes the name.					          *
// ********************************************************
void Gemstone::setName(string n)
{
	if (n.empty())
		throw EmptyString();
	else if (n.length() > 14)
		throw TooLongString();
	else
		name = n;
}

// ********************************************************
// name:      setWeight
// passed:    float f
// returns:   nothing
// calls:     nothing
//			  
// The setWeight function takes in a float and throws an  *
// exception if it is less than 0. If an exception wasn't *
// thrown, the passed in float becomes the weight.		  *
// ********************************************************
void Gemstone::setWeight(float f)
{
	if (f < 0)
		throw NegativeFloat();
	else
		weight = f;
}

// ********************************************************
// name:      setAmountPaid
// passed:    float f
// returns:   nothing
// calls:     nothing
//			  
// The setAmountPaid function takes in a float and throws *
// an exception if it is less than 0. If an exception     *
// wasn't thrown, the passed in float becomes the		  *
// amountPaid.											  *
// ********************************************************
void Gemstone::setAmountPaid(float f)
{
	if (f < 0)
		throw NegativeFloat();
	else
		amountPaid = f;
}

// ********************************************************
// name:      setRating
// passed:    string n
// returns:   nothing
// calls:     nothing
//			  
// The setName function takes in a string and throws an   *
// exception if it doesn't consist of 1-5 stars in a row. *
// If an exception wasn't thrown, the passed in string	  *
// becomes the rating.							          *
// ********************************************************
void Gemstone::setRating(string n)
{
	if (n.compare("*") == 0)
		rating = n;
	else if (n.compare("**") == 0)
		rating = n;
	else if (n.compare("***") == 0)
		rating = n;
	else if (n.compare("****") == 0)
		rating = n;
	else if (n.compare("*****") == 0)
		rating = n;
	else
		throw IncorrectRatingFormat();
}

// ********************************************************
// name:      print
// passed:    nothing
// returns:   nothing
// calls:     nothing
//			  
// The print function prints out all of the Gemstone's    *
// information in a nice format.						  *
// ********************************************************
void Gemstone::print()
{
	//TEMP have each line be 25 chars wide
	string output = "";
	stringstream stream;

	output += "ID:";
	stream << setw(23) << ID;
	output += stream.str();
	stream.str("");
	output += "\n";

	output += "Name:";
	stream << setw(21) << name;
	output += stream.str();
	stream.str("");
	output += "\n";

	output += "Weight:";
	stream << setw(19) << fixed << setprecision(2) << weight;
	output += stream.str();
	stream.str("");
	output += "\n";
	
	output += "Amount Paid:";
	stream << setw(6) << right << "$";
	stream  << setw(8)  << fixed << setprecision(2) << right << amountPaid;
	output += stream.str();
	stream.str("");
	output += "\n";

	output += "Rating:";
	stream << setw(19) << rating;
	output += stream.str();
	stream.str("");
	output += "\n";

	cout << output << endl;
}