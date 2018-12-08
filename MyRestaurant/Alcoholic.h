#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Drinks.h"

using namespace std;

class Alcoholic: public Drinks {
public:

	Alcoholic();

	void setName(string);
	void setQuantity(int);
	void setPosition(int);
	void setPrice(double);

	string getName();

	int getPosition();
	int getQuantity();

	double getPrice();

private:
	string name;
	int quantity, position;
	double price;
};