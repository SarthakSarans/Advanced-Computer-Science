#include "disc.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

// Implement the functions protoyped in disc.h
// Your code here
Disc::Disc() {
	size = 0;
}

Disc::Disc(int a) {
	size = a;
}
Disc::~Disc() {
	size = 0;
}
int Disc::getSize() {
	return size;
};
bool Disc::setSize(int a) {
	size = a;
}
std::string Disc::toString() {
	std::stringstream ss;
	ss << size;
	std::string str = ss.str();
	return str;
}