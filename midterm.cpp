#include "X.h"

int main (int agrc, char* argv []){
	std::cout << "*****Begin midterm test run.*****\n";
	X<long double> a, b(1000); //default and 1 arg constructor
	a = b; //assignment operator
	X<long double>c (std::move(a)); //move constructor
	a = std::move(b); //move assignment, b is zombie
	b = std::move(a); //move assignment, a is zombie
	a = std::move(c); //move assignment, c is zombie
	//a and b have data, c is zombie
//	std::cout << "data in a is: " <<a.data[0] << "\n";
//	std::cout << "size of a string is :" << sizeof(std::string) <<"\n";

}
