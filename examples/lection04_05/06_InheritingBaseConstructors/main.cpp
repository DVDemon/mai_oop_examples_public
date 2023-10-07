#include <iostream>
#include "person.h"
#include "engineer.h"

int main(){

	Engineer eng1("Daniel Gray",23,"asdl;fkjdas;fkdas;fk",4);
	
	Engineer eng2("Daniel Gray",23,"asdl;fkjdas;fkdas;fk"); // Copied constructor

	Engineer eng3;

    return 0;
}