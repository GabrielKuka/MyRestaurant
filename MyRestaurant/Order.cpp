#include "pch.h"
#include "Order.h"

Order::Order() {
	this->id = 0;
}

Order::~Order() {

	deleteVector(getAppetizers());
	deleteVector(getMainCourses());
	deleteVector(getAlcoholics());
	deleteVector(getNonAlcoholics());
}

template<typename T>
void Order::deleteVector(vector<T*>& list){
	for (T* o : list) {
		delete o;
	}
	list.clear();
}

void Order::setId(int i){
	this->id = i;
}

int& Order::getId() {
	return this->id;
}

void Order::setTableNumber(int tblN){
	tableNumber = tblN;
}

int& Order::getTableNumber() {
	return this->tableNumber;
}

void Order::setNumberOfGuests(int nOg){
	numberOfGuests = nOg;
}

int& Order::getNumberOfGuests() {
	return this->numberOfGuests;
}

void Order::setServerName(string n){
	serverName = n;
}

string& Order::getServerName() {
	return serverName;
}

void Order::setTotalPrice(double p){
	totalPrice += p;
}

double Order::getTotalPrice(){
	return totalPrice;
}

void Order::setAppetizer(Food* ap) {
	a.push_back(ap);
	totalPrice += ap->getPrice();
}

void Order::setMainCourse(Food* mc) {
	m.push_back(mc);
	totalPrice += mc->getPrice();
}

void Order::setDessert(Food* de) {
	d.push_back(de);
	totalPrice += de->getPrice();
}

void Order::setAppetizers(vector<Food*>& list) {
	a = list;
}

void Order::setMainCourses(vector<Food*>& list) {
	m = list;
}

void Order::setDesserts(vector<Food*>& list) {
	d = list;
}

vector<Food*>& Order::getAppetizers() {
	return a; 
}

vector<Food*>& Order::getMainCourses() {
	return m;
}

vector<Food*>& Order::getDesserts() {
	return d;
}

void Order::setAlcoholic(Drinks* d){
	al.push_back(d);
	totalPrice += d->getPrice();
}

void Order::setNonAlcoholic(Drinks* d) {
	nonAl.push_back(d);
	totalPrice += d->getPrice();
}

void Order::setAlcoholics(vector<Drinks*>& d) {
	al = d;
}

void Order::setNonAlcoholics(vector<Drinks*>& d) {
	nonAl = d;
}

vector<Drinks*>& Order::getAlcoholics() {
	return al;
}

vector<Drinks*>& Order::getNonAlcoholics() {
	return nonAl;
}

bool Order::isItemShared(int x) {
	return x == 0;
}

void Order::setNext(Order* o){
	this->next = o;
}

Order* Order::getNext() const{
	return next;
}