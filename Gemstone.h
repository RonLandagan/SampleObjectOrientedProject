//Name:			Ron Landagan
//Email:		isaac.violin@gmail.com
//ID:			5446632
//Class:		CISC 205
//Assignment:	Chapter 17

// Specification file for the Gemstone class
#include<string>
#include<vector>
using namespace std;
#ifndef GEMSTONE_H
#define GEMSTONE_H

class Gemstone
{
private:
	int ID;
	string name;
	float weight;
	float amountPaid;
	string rating;

public:
	// Exception classes
	class NonpositiveInt {};
	class NonuniqueID {};
	class EmptyString {};
	class TooLongString {};
	class NegativeFloat {};
	class IncorrectRatingFormat {};

	// Default Constructor
	Gemstone()
	{
		ID = 555;
		name = "";
		weight = 0.1f;
		amountPaid = 100;
		rating = "***";
	}

	// Mutators
	void setID(int i, vector<Gemstone> v);
	void setName(string n);
	void setWeight(float f);
	void setAmountPaid(float f);
	void setRating(string n);

	// Accessors
	int getID() const
	{
		return ID;
	}

	string getName() const
	{
		return name;
	}

	float getWeight() const
	{
		return weight;
	}

	float getAmountPaid() const
	{
		return amountPaid;
	}

	string getRating() const
	{
		return rating;
	}

	// Print function
	void print();

	//Overload operators
	float operator+(float f)
	{
		return amountPaid + f;
	}

	bool operator>(float f)
	{
		return (amountPaid > f);
	}
};

#endif