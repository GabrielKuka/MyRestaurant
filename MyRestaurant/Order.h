#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Food.h"
#include "Drinks.h"
#include "Item.h"
#include <vector>

using namespace std;

class Order : public Item {
public:
	Order();
	~Order();
	void setId(int);
	void setTableNumber(int);
	void setNumberOfGuests(int);
	void setTotalPrice(double);
	void setServerName(string);

	void setNext(Order*);

	void setAppetizer(Food* f);
	void setMainCourse(Food*);
	void setDessert(Food*);

	void setAppetizers(vector<Food*>&);
	void setMainCourses(vector<Food*>&);
	void setDesserts(vector<Food*>&);

	vector<Food*>& getAppetizers();
	vector<Food*>& getMainCourses();
	vector<Food*>& getDesserts();

	void setAlcoholic(Drinks*);
	void setNonAlcoholic(Drinks*);

	void setAlcoholics(vector<Drinks*>&);
	void setNonAlcoholics(vector<Drinks*>&);

	vector<Drinks*>& getAlcoholics();
	vector<Drinks*>& getNonAlcoholics();


	int& getId();
	int& getTableNumber();
	int& getNumberOfGuests();
	double getTotalPrice();
	string& getServerName();

	Order* getNext()const;

	static bool isItemShared(int);
	
private:
	template<typename T>
	void deleteVector(vector<T*>&);
	int id, tableNumber;
	int numberOfGuests;
	double totalPrice;
	string serverName;
	vector<Food*> a;
	vector<Food*> m;
	vector<Food*> d;

	vector<Drinks*> al;
	vector<Drinks*> nonAl;
	
	Order* next;

};