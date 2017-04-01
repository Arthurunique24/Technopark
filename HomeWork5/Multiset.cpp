#include "stdafx.h"
#include "stdlib.h"
#include "Multiset.h"
#include <iostream>

int main(){
	tda::multiset<int> a;

	a.insert(2);
	a.insert(1);
	a.insert(0);
	a.insert(3);
	a.insert(5);
	a.insert(4);

	a.print();

	tda::multiset<int> b = a;
	
	b.erase(2);
	b.erase(1);
	b.print();

	a.swap(b);
	a.print();
	b.print();
	
    if (a == b){
		std::cout << "lol";
    }
    else{
		std::cout << "nelol";
    }
    
    return 0;
}

