#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Food.h"


using namespace std;

class Appetizers : public Food {
public:

	Appetizers();

	void setName(string);
	void setPrice(double);
	void setQuantity(int);
	void setPosition(int);

	string getName();
	int getPosition();
	int getQuantity();
	double getPrice();
	bool isShared(int);
private:
	string name;
	double price;
	int quantity, position;
	
};