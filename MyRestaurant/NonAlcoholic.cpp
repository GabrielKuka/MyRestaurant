#include "pch.h"
#include "NonAlcoholic.h"

using namespace std;

NonAlcoholic::NonAlcoholic() {
	price = 0.0;
	quantity = 1;
}


void NonAlcoholic::setName(string n){
	name = n;
}

string NonAlcoholic::getName(){
	return name;
}

void NonAlcoholic::setPosition(int pos){
	position = pos;
}

int NonAlcoholic::getPosition() {
	return position;
}

void NonAlcoholic::setPrice(double p){
	price = getQuantity()*(p - (discount * p));
}

double NonAlcoholic::getPrice() {
	return price;
}

void NonAlcoholic::setQuantity(int q) {
	quantity = q;
}

int NonAlcoholic::getQuantity(){
	return quantity;
}
