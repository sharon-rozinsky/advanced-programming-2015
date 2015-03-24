//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person_t.h"
using namespace std;

int main() {
	Person_t p("moshe cohen", 50);
	cout << p.toString();
	return 0;
}
