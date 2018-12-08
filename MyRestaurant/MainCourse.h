#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Food.h"

using namespace std;

class MainCourse : public Food {
public:
	MainCourse();

	void setName(string);
	void setPrice(double);
	void setPosition(int);
	void setQuantity(int);

	string getName();
	int getPosition();
	int getQuantity();
	double getPrice();

private:
	string name;
	int position, quantity;
	double price;
};