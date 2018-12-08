#pragma once
#include "pch.h"
#include <iostream>
#include "Food.h"
#include "Drinks.h"
#include "Order.h"

using namespace std;

class Queue {
private:
	Order* head;
	Order* tail;
	Order* temp;
	int counter;
	double singleOrderPrice = 0.0;
	static const int CHARS = 256;
	string servers = "";
	bool isEmpty();
	template<typename T>
	void displayItem(vector<T*>);
	string& joinServers();
	bool search(string&, string&);
	void badCharHeuristic(string*, int, int[CHARS]);
	int maxNumber(int, int);
	void displayOrderData(Order*&);
public:
	Queue();
	~Queue();
	void addOrder( int& tableN, int& nOg, string& sN, vector<Food*>&, vector<Food*>&, vector<Food*>&, vector<Drinks*>&, vector<Drinks*>&);
	void addOrder(Order*&);
	void removeOrder();
	void displayOrders();
	void displayOrders(vector<Order*>&);
	void displayOrders(string&);
	void findOrder(int&);
	void setSingleOrderPrice(double);
	double getSingleOrderPrice();
	int getNumberOfOrders();
	vector<Order*> insertionSort();
	void searchServer(string&);
	
};