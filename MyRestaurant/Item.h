#pragma once
#include "pch.h"

class Item {
public:
	virtual double getTotalPrice() = 0;
	virtual void setTotalPrice(double) = 0;
};
