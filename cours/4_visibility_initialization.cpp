// VISIBILITY & INITIALIZATION

#include <iostream>
#include "4_visibility_initialization.hpp"

/*	Constructeur utilisant une syntaxe particulière pour initialiser les attributs name (public), 
	_credits (private) et _health (protected). On parle de liste d'initialisation, car il ne s'agit pas
	ici d'une assignation, mais bien d'une initialisation. Autrement, les attributs déclarés en const
	tels que "name" ne pouraient être modifiés et cela ne compilerai pas. Le constructeur doit prendre 
	en argument les valeurs que l'on souhaite donner aux membres de la classe Character. */
Character::Character(std::string str, int crédits, int health) : name(str), _credits(crédits), _health(health)
{
	std::cout << ">>> Greetings, my name is " << this->name << "." << std::endl;
}

// Destructeur
Character::~Character()
{
	std::cout << ">>> Farewell, and may the Force be with you." << std::endl;
}

// Private method to increase crédits amount.
void Character::_addCredits(int amount)
{
	this->_credits += amount;
}

// Public method (mutator) to safely add crédits.
void Character::editCredits(int amount)
{
	this->_addCredits(amount);
	std::cout << this->name << " gained " << amount << " credits." << std::endl;
}

// Accessor for total crédits value.
int	Character::getCredits(void) const
{
	std::cout << this->name << " currently has " << this->_credits << " credits." << std::endl;
	return this->_credits;
}

// Private method to apply damage.
void Character::_applyDamage(int value)
{
	this->_health -= value;
}

// Public method (mutator) to safely apply damage.
void Character::takeDamage(int value)
{
	this->_applyDamage(value);
	std::cout << this->name << " received " << value << " damage." << std::endl;
}

// Accessor for health value.
int	Character::getHealth(void) const
{
	std::cout << this->name << " has " << this->_health << " health remaining." << std::endl;
	return this->_health;
}

int	main(void)
{
	Character Kreia("Kreia", 58, 100); // Les paramètres servent à initialiser name, _credits et _health via le constructeur de classe.
	Kreia.level = 12;	// Le level peut être assigné ici car c'est un membre public.

//	Kreia._addCredits(25);		Cette ligne ne compile pas car _addCredits() est une méthode private.
	Kreia.editCredits(25); //	On utilise plutôt le mutateur editCredits() qui est public.
	int g = Kreia.getCredits();	// Accesseur

//	Kreia._applyDamage(10);		Même chose ici, _applyDamage est protected donc ça ne compile pas.
	Kreia.takeDamage(10);
	int h = Kreia.getHealth(); // Accesseur

	return 0;
}
