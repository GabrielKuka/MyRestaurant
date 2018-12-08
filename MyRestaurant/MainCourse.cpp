#include "pch.h"
#include "MainCourse.h"


MainCourse::MainCourse() {
	price = 0.0;
	quantity = 1;
}

void MainCourse::setName(string n){
	name = n;
}

string MainCourse::getName(){
	return name;
}

void MainCourse::setPosition(int pos){
	position = pos;
}

int MainCourse::getPosition() {
	return position;
}

void MainCourse::setQuantity(int q){
	quantity = q;
}

int MainCourse::getQuantity() {
	return quantity;
}

void MainCourse::setPrice(double p){
	price = getQuantity() * p;
	
}

double MainCourse::getPrice() {
	return price;
}
