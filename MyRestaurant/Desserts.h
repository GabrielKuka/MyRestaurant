#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Food.h"


using namespace std;

class Desserts : public Food{
public:

	Desserts();

	void setName(string);
	void setPrice(double);
	void setQuantity(int);
	void setPosition(int);

	string getName();
	int getQuantity();
	int getPosition();
	double getPrice();

private:
	string name;
	int quantity, position;
	double price;
	double const discount = 0.09;
};
