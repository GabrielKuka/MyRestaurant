#include "pch.h"
#include "Queue.h"
#include <iomanip>

Queue::Queue() {
	counter = 0;
	tail = head = NULL;
}

Queue::~Queue() {

		for (int i = 0; i < counter; i++) {
			removeOrder();
		}
	
		cout << "List cleared.\n";
}

bool Queue::isEmpty() {
	return head == NULL;
}

int Queue::getNumberOfOrders() {
	return counter;
}

void Queue::setSingleOrderPrice(double p) {
	singleOrderPrice += p;
}

double Queue::getSingleOrderPrice() {
	return singleOrderPrice;
}

void Queue::addOrder(int& tN, int& nOg, string& sN, vector<Food*>& ap, vector<Food*>& mC, vector<Food*>& d, vector<Drinks*>& al, vector<Drinks*>& nonAl) {
	// Set up order
	temp = new Order();
	temp->setId(counter);
	temp->setTableNumber(tN);
	temp->setNumberOfGuests(nOg);
	temp->setServerName(sN);

	// Fill order with items (food and drinks)
	temp->setAppetizers(ap);
	temp->setMainCourses(mC);
	temp->setDesserts(d);

	temp->setAlcoholics(al);
	temp->setNonAlcoholics(nonAl);

	temp->setTotalPrice(getSingleOrderPrice());

	temp->setNext(NULL);

	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		
		tail->setNext(temp);
		tail = temp;
	}

	temp = NULL;
	++counter;
}

void Queue::addOrder(Order*& order) {
	temp = order;

	temp->setNext(NULL);

	if (isEmpty()) {
		head = tail = temp;
	}
	else {
		tail->setNext(temp);
		tail = temp;
	}

	temp = NULL;

	++counter;
}

void Queue::findOrder(int& tN) {
	Order* currentOrder = this->head;
	bool found = false;
	while (currentOrder != NULL) {
		if (currentOrder->getTableNumber() == tN) {
			cout << "Order found.\n";
			displayOrderData(currentOrder);
			found = true;
			break;
		}
		else {
			currentOrder = currentOrder->getNext();
		}
	}

	if (!found) {
		cout << "Order could not be found!\n";
	}

}

void Queue::removeOrder() {
	if (!isEmpty()) {
		temp = head;
		head = head->getNext();
		--counter;
		delete temp;
		cout << "Order deleted.\n";
	}
	else {
		cout << "There are no orders to remove.\n";
	}
}

void Queue::displayOrders(string& s) {
	Order* currentOrder = this->head;

	cout << "~~~~~~~~~~ Start Search ~~~~~~~~~~\n\n";
	while(currentOrder != NULL){
		if(currentOrder->getServerName().compare(s) == 0){  // if server name matches with the one we are looking for
			// print order data
			displayOrderData(currentOrder);
		
		}
		currentOrder = currentOrder->getNext();
	}	
	cout << "\n~~~~~~~~~~ End Search ~~~~~~~~~~\n";
	delete currentOrder;
}

void Queue::displayOrders(vector<Order*>& list) {
	cout << "~~~~~~~~~~ Start Search ~~~~~~~~~~\n\n";
	for (int i = 0; i < list.size(); i++) {
		// print order data
		displayOrderData(list[i]);
	}
	cout << "\n~~~~~~~~~~ End Search ~~~~~~~~~~\n";
}

void Queue::displayOrders() {
	if (isEmpty()) {
		cout << "There are currently no orders!\n";
	}
	else {
		Order* currentOrder = this->head;
		cout << "~~~~~~~~~~ Start Search ~~~~~~~~~~\n\n";

		while (currentOrder != NULL) {
			// print order data
			displayOrderData(currentOrder);
			currentOrder = currentOrder->getNext();
		}

		cout << "\n~~~~~~~~~~ End Search ~~~~~~~~~~\n";
		delete currentOrder;
	}

	
}

void Queue::displayOrderData(Order*& o){
	// print order data
	cout << "+++++++++++++++++++++++++" << endl;
	cout << "Id: " << o->getId();
	cout << "   Tbl: " << o->getTableNumber();
	cout << "   Gsts: " << o->getNumberOfGuests() << endl;
	cout << "Server: " << o->getServerName() << endl;
	cout << "   Drinks:" << endl;

	cout << "     - Alcoholic: " << endl;
	displayItem(o->getAlcoholics());


	cout << "     - Non Alcoholic: " << endl;
	displayItem(o->getNonAlcoholics());

	cout << "   Food:" << endl;
	cout << "     - Appetizers: " << endl;
	displayItem(o->getAppetizers());

	cout << "     - Main Course: " << endl;
	displayItem(o->getMainCourses());

	cout << "     - Desserts: " << endl;
	displayItem(o->getDesserts());

	cout << "Total Price: $" << o->getTotalPrice() << endl;
	cout << "\n\n";
}

template<typename T>
void Queue::displayItem(vector<T*> l) {

		if (l.size() > 0) {
			for (int i = 0; i < l.size(); i++) {
				cout << "\t-> ";
				cout << setw(2) << l[i]->getQuantity() << " "
					<< setw(20) << left <<l[i]->getName() << " $"
					<< setw(2) << l[i]->getPrice() / l[i]->getQuantity()
					<< " Pos: ";
				if (Order::isItemShared(l[i]->getPosition())) {
					cout << setw(10) << "Shared";
				}
				else {
					cout << setw(5) << l[i]->getPosition();
				}
				cout << endl;
			}
	
		}
		
	}

/* 
											Insertion Sort Algorithm
*/		

vector<Order*> Queue::insertionSort(){
	// put the orders in a vector
	Order* currentOrder = this->head;
	vector<Order*> orders;

	while(currentOrder != NULL){
		orders.push_back(currentOrder);
		currentOrder = currentOrder->getNext();
	}

	int j;
	Order* k;
	for (int i = 1; i < orders.size(); i++) {
		j = i - 1;
		k = orders[i];

		while (j >= 0 && orders[j]->getTotalPrice() < k->getTotalPrice()) {
			orders[j + 1] = orders[j];
			j = j - 1;
		}

		orders[j + 1] = k;
	}

	return orders;
	
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
										Boyer-Moore Algorithm
*/
int Queue::maxNumber(int a, int b){
	return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void Queue::badCharHeuristic(string *str, int size, int badchar[Queue::CHARS])
{
	int i;

	// Initialize all occurrences as -1
	for (i = 0; i < CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence of a character
	for (i = 0; i < size; i++)
		badchar[str->at(i)] = i;
}

void Queue::searchServer(string& server){
	if (!isEmpty()) {
		bool foundServer = false;
		try {
			foundServer = search(joinServers(), server);
		}catch(exception e){
			cerr << "There was an error with search algorithm.\n";
		}
		if (foundServer) {
			// print the orders of that server
			displayOrders(server);			
		}
		else {
			cout << "The server you searched for is not found.\n";
		}
	}
	else {
		cout << "There are no orders at the moment.\n";
	}
	servers = "";
}

bool Queue::search(string& t, string& p){
	bool matchFound = false;

	// Pointers of pattern and text
	string* txt = &t;
	string* pat = &p;
	
	// Length of pattern and text
	int pL = strlen(pat->c_str());
	int tL = strlen(txt->c_str());

	int badchar[CHARS];

	// Fill the bad character array
	badCharHeuristic(pat, pL, badchar);

	int shift = 0; // stores the shift of the pattern with respect to the text
	while (shift <= (tL - pL)){
		// Makes sure that pattern is checked within the text and that it doesn't get out of the text
		int j = pL - 1;

		// This loop reduces the value of j while the chars of the pattern match and text match at the current shift
		while (j >= 0 && pat->at(j) == txt->at(shift + j)) {
			j--;
		}

		// If we have a match of the pattern in the text j becomes -1 and matchFound becomes true
		if (j < 0)
		{

			// Here I shift the pattern so that the next char in the text aligns with the last occurence of it in the pattern
			shift += (shift + pL < tL) ? pL - badchar[txt->at(shift + pL)] : 1;

			matchFound = true;			// Assign variable matchFound with true of a match is found
			break;						// stop the while loop because we already found a match
		}

		else {
			// Shift the pattern so that the bad character in the text is aligned with the last occurence of itself in the pattern
			// We might get a negative shift if the bad character is on the right of the current one.
			// In this case maxNumber function is used to get a positive shift
			
			shift += maxNumber(1, j - badchar[txt->at(shift + j)]);
		}
	}

	return matchFound;				// return the result of the search
}

// Put all the servers in a single string
string& Queue::joinServers() {

	Order* currentOrder = this->head;

	while(currentOrder != NULL){
		servers += currentOrder->getServerName();

		currentOrder = currentOrder->getNext();
	}

	delete currentOrder;

	return servers;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

