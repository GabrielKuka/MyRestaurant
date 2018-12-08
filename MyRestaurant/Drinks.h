#pragma once
#include "pch.h"
#include <string>

using namespace std;

class Drinks {
public:
	virtual void setName(string) = 0;
	virtual void setQuantity(int) = 0;
	virtual void setPosition(int) = 0;
	virtual void setPrice(double) = 0;

	virtual string getName() = 0;
	virtual int getQuantity() = 0;
	virtual int getPosition() = 0;
	virtual double getPrice() = 0;
protected:
	double drinksPrice;
};