#include "pch.h"
#include <iostream>
#include "Queue.h"
#include "Food.h"
#include "Appetizers.h"
#include "MainCourse.h"
#include "Desserts.h"
#include "Alcoholic.h"
#include "NonAlcoholic.h"
#include "Item.h"
#include <vector>
#include <string>
#include <iomanip>

Food* food;
Drinks* d;
vector<Food*> a, mC, de;
vector<Drinks*> al, nonAl;
string commands[] = {"exit", "remove", "add order", "search order", "sort orders", "display", "search server", "help"};
Queue* list = new Queue();

using namespace std;


void createOrder();
void findOrder();
int  foundCommand(string&);
void checkCommand();
void askForServer();
void printHelp();

template<typename T>
void deleteVector(vector<T*>&);

int main()
{

	cout << setw(60) << "Welcome to my restaurant!\n\n";



	// testing


	Order* o3 = new Order();
	o3->setId(1);
	o3->setNumberOfGuests(2);
	o3->setTableNumber(15);
	o3->setServerName("Ivan");

	d = new Alcoholic();
	d->setName("German Wine");
	d->setPrice(800);
	d->setPosition(0);
	d->setQuantity(1);
	o3->setAlcoholic(d);

	list->addOrder(o3);


	Order* o1 = new Order();
	o1->setId(1);
	o1->setNumberOfGuests(2);
	o1->setTableNumber(11);
	o1->setServerName("Atanas");

	food = new Appetizers();
	food->setName("Mozarella");
	food->setPosition(1);
	food->setPrice(22);
	food->setQuantity(1);
	o1->setAppetizer(food);

	food = new MainCourse();
	food->setName("Halibut");
	food->setPosition(1);
	food->setPrice(45);
	food->setQuantity(1);
	o1->setMainCourse(food);

	food = new MainCourse();
	food->setName("Swordfish");
	food->setPosition(2);
	food->setPrice(50);
	food->setQuantity(1);
	o1->setMainCourse(food);

	food = new Desserts();
	food->setName("Ice cream");
	food->setPosition(0);
	food->setPrice(14);
	food->setQuantity(1);
	o1->setDessert(food);

	d = new NonAlcoholic();
	d->setName("Pepsi");
	d->setPrice(11);
	d->setPosition(1);
	d->setQuantity(1);
	o1->setNonAlcoholic(d);

	d = new NonAlcoholic();
	d->setName("Sparkling Water");
	d->setPrice(19);
	d->setPosition(2);
	d->setQuantity(1);
	o1->setNonAlcoholic(d);

	list->addOrder(o1);

	Order* o2 = new Order();
	o2->setId(7);
	o2->setNumberOfGuests(2);
	o2->setTableNumber(16);
	o2->setServerName("Gabriel");

	d = new Alcoholic();
	d->setName("French Wine");
	d->setPrice(450);
	d->setPosition(0);
	d->setQuantity(1);
	o2->setAlcoholic(d);

	list->addOrder(o2);



	// testing finished

	checkCommand();
	

	getchar();
	return 0;
}

template<typename T>
void deleteVector(vector<T*>& list){
	for(T* o : list){
		delete o;
	}
	list.clear();
}

int foundCommand(string& c) {
	int a = -1;
	for (int i = 0; i < 8; i++) {
		if(commands[i].compare(c) == 0){
			a = i;
			break;
		}
	}

	return a;
}

void checkCommand() {
	string command;
	cout << "-> ";
	getline(cin, command);
	
	int commandIndex = foundCommand(command);

	switch (commandIndex) {
	case 0:
		// Clear up resources
		deleteVector(a);
		deleteVector(mC);
		deleteVector(de);
		deleteVector(al);
		deleteVector(nonAl);
		delete d;
		delete food;
		delete list;
		cout << setw(50) << "Goodbye!" << endl;
		break;
	case 1:
		// remove order
		list->removeOrder();
		checkCommand();
		break;
	case 2:
		// add order
		createOrder();
		checkCommand();
		break;
	case 3:
		// search order
		findOrder();
		checkCommand();
		break;
	case 4: {
		// sort order
		cout << "\nSorting...\n";

		vector<Order*> sortedOrders = list->insertionSort();
		list->displayOrders(sortedOrders);
		cout << "\nSorted.\n";
		checkCommand();
		break;
	}
	case 5:
		// display orders
		list->displayOrders();
		checkCommand();
		break;
	case 6:
		askForServer();
		checkCommand();
		break;
	case 7:
		printHelp();
		checkCommand();
		break;
	default:
		cout << "Command not found!\n";
		checkCommand();
		break;
	}
	

}

void printHelp() {
	cout << setw(50) << "+ Commands +\n" << endl ; 

	cout << setw(30) << "exit" << setw(50) << "List the commands" << endl;
	cout << setw(30) << "remove" << setw(50) << "Removes the order at the top of the list" << endl;
	cout << setw(30) << "add order" << setw(50) << "Adds a new order" << endl;
	cout << setw(30) << "search order" << setw(50) << "Search for an order" << endl;
	cout << setw(30) << "sort orders" << setw(50) << "Sort orders from the most expensive" << endl;
	cout << setw(30) << "display" << setw(50) << "Displays all the orders" << endl;
	cout << setw(30) << "search server" << setw(50) << "Search a server to show his/her orders" << endl;
	cout << setw(30) << "help" << setw(50) << "Shows this list." << endl;
}

void askForServer() {
	string server = "";
	cout << "Enter the server you are looking for: ";
	getline(cin, server);
	cout << "\n";
	list->searchServer(server);
}

void findOrder() {
	int tbl;
	cout << "Enter table number -> ";
	cin >> tbl;

	list->findOrder(tbl);
	cin.ignore();
}

void createOrder() {
	string input, name, server;
	int pos, quantity, tbl, gsts;
	double price;

	cout << "Server -> ";
	getline(cin, server);

	cout << "\nTable -> ";
	cin >> tbl;
	cout << "\nGuests -> ";
	cin >> gsts;
	
	food = NULL;

	cout << "\nEnter appetizers Y/N? ";
	cin.ignore();
	getline(cin, input);
	while (input.compare("Y") == 0) {
		food = new Appetizers();
		cout << "Name -> ";
		getline(cin, name);

		cout << "\nQuantity -> ";
		cin >> quantity;

		cout << "\nPosition -> ";
		cin >> pos;

		cout << "\nPrice -> ";
		cin >> price;
		cout << "\n";

		food->setName(name);
		food->setQuantity(quantity);
		food->setPosition(pos);
		food->setPrice(price);
		list->setSingleOrderPrice(food->getPrice());
		a.push_back(food);
		cout << "-> Done!\n";
		cin.ignore();
		cout << "Add another appetizer? Y/N: ";
		getline(cin, input);
	}

	cout << "Enter main course dish Y/N ? ";
	getline(cin, input);
	while (input.compare("Y") == 0) {
		food = new MainCourse();
		cout << "Name -> ";
		getline(cin, name);

		cout << "\nQuantity -> ";
		cin >> quantity;

		cout << "\nPosition -> ";
		cin >> pos;

		cout << "\nPrice -> ";
		cin >> price;
		cout << "\n";

		food->setName(name);
		food->setQuantity(quantity);
		food->setPosition(pos);
		food->setPrice(price);
		list->setSingleOrderPrice(food->getPrice());
		mC.push_back(food);
		cout << "-> Done!\n";
		cin.ignore();
		cout << "Add another main course dish? Y/N: ";
		getline(cin, input);
	}

	cout << "Enter desserts Y/N ? ";
	getline(cin, input);

	
	while (input.compare("Y") == 0) {
		food = new Desserts();
		
		cout << "Name -> ";
		getline(cin, name);

		cout << "\nQuantity -> ";
		cin >> quantity;

		cout << "\nPosition -> ";
		cin >> pos;

		cout << "\nPrice -> ";
		cin >> price;
		cout << "\n";

		food->setName(name);
		food->setQuantity(quantity);
		food->setPosition(pos);
		food->setPrice(price);
		list->setSingleOrderPrice(food->getPrice());
		de.push_back(food);
		cout << "-> Done!\n";
		cin.ignore();
		cout << "Add another dessert? Y/N: ";
		getline(cin, input);
	}



	d = NULL;

	cout << "Enter alcoholic drinks Y/N: ";
	getline(cin, input);

	while (input.compare("Y") == 0) {
		d = new Alcoholic();
		cout << "Name -> ";
		getline(cin, name);

		cout << "\nQuantity -> ";
		cin >> quantity;

		cout << "\nPosition -> ";
		cin >> pos;

		cout << "\nPrice -> ";
		cin >> price;
		cout << "\n";

		d->setName(name);
		d->setQuantity(quantity);
		d->setPosition(pos);
		d->setPrice(price);
		list->setSingleOrderPrice(d->getPrice());
		al.push_back(d);
		cout << "-> Done!\n";
		cin.ignore();
		cout << "Add another alcoholic drink? Y/N: ";
		getline(cin, input);
	}
	
	cout << "Enter non-alcoholic drinks Y/N: ";
	getline(cin, input);

	while (input.compare("Y") == 0) {
		d = new NonAlcoholic();
		cout << "Name -> ";
		getline(cin, name);

		cout << "\nQuantity -> ";
		cin >> quantity;

		cout << "\nPosition -> ";
		cin >> pos;

		cout << "\nPrice -> ";
		cin >> price;
		cout << "\n";

		d->setName(name);
		d->setQuantity(quantity);
		d->setPosition(pos);
		d->setPrice(price);
		list->setSingleOrderPrice(d->getPrice());
		nonAl.push_back(d);
		cout << "-> Done!\n";
		cin.ignore();
		cout << "Add another non alcoholic drink? Y/N: ";
		getline(cin, input);
	}

	list->addOrder(tbl, gsts, server, a, mC, de, al, nonAl);
	list->setSingleOrderPrice(-list->getSingleOrderPrice());

	a.clear();
	mC.clear();
	de.clear();
	al.clear();
	nonAl.clear();




}
