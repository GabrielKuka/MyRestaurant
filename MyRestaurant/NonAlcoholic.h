#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Drinks.h"

using namespace std;

class NonAlcoholic : public Drinks{
public:

	NonAlcoholic();

	void setName(string);

	void setPosition(int);
	void setQuantity(int);

	void setPrice(double);

	string getName();
	double getPrice();
	int getQuantity();
	int getPosition();

private:
	string name;
	int quantity, position;
	double price;
	const double discount = 0.1;
};


