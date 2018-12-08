#include "pch.h"
#include "Alcoholic.h"
#include <string>


using namespace std;

Alcoholic::Alcoholic() {
	price = 0.0;
	quantity = 1;
}

void Alcoholic::setName(string n){
	name = n;
}

string Alcoholic::getName() {
	return name;
}

void Alcoholic::setPosition(int p){
	position = p;
}

int Alcoholic::getPosition() {
	return position;
}

void Alcoholic::setQuantity(int q) {
	quantity = q;
}

int Alcoholic::getQuantity() {
	return quantity;
}

void Alcoholic::setPrice(double p){
	price = getQuantity() * p;
}

double Alcoholic::getPrice(){
	return price;
}