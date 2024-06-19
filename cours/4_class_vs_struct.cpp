#include <iostream>
#include "4_class_vs_struct.hpp"

// Private method to increase gold amount.
void Character::_addGold(int amount)
{
	this->_gold += amount;
}

// Public method to safely add gold.
void earnGold(int amount)
{
	
}

int	main(void)
{
	Character Alrik;

	Alrik.level = 12;	// level can be assigned here because it's a public member.
	
	Alrik._privateInfo = "Top secret plan";	// This line won't compile because _privateInfo is private.
	Alrik._privateJob().	// Same here, this member function can't be accessed from outside the class.

}
