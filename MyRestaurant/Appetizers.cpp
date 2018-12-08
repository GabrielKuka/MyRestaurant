#include "pch.h"
#include "Appetizers.h"


Appetizers::Appetizers() {
	price = 0.0;
	quantity = 1;
}

bool Appetizers::isShared(int x){
	return x == -1;
}

void Appetizers::setName(string n){
	name = n;
}

string Appetizers::getName() {
	return name;
}

void Appetizers::setQuantity(int q){
	quantity = q;
}

int Appetizers::getQuantity() {
	return quantity;
}

void Appetizers::setPosition(int p) {
	position = p;
}

int Appetizers::getPosition() {
	return position;
}

void Appetizers::setPrice(double p) {
	price = getQuantity() * p;
}

double Appetizers::getPrice() {
	return price;
}