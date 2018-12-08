#include "pch.h"
#include "Desserts.h"


Desserts::Desserts() {
	price = 0.0;
	quantity = 1;
}


void Desserts::setName(string n){
	name = n;
}

string Desserts::getName() {
	return name;
}

void Desserts::setQuantity(int q){
	quantity = q;
}

int Desserts::getQuantity() {
	return quantity;
}

void Desserts::setPosition(int p) {
	position = p;
}

int Desserts::getPosition() {
	return position;
}

void Desserts::setPrice(double p){
	price = getQuantity() * (p - (p * discount));
	
}

double Desserts::getPrice() {
	return price;
}