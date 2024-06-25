// VISIBILITY & INITIALIZATION

#include <iostream>
#include "4_visibility_initialization.hpp"

/*	Constructeur utilisant une syntaxe particulière pour initialiser les attributs name (public), 
	_gold (private) et _health (protected). On parle de liste d'initialisation. Pour cela, le constructeur 
	doit prendre en argument les valeurs que l'on souhaite attribuer aux membres de la classe Character. */
Character::Character(std::string str, int gold, int health) : name(str), _gold(gold), _health(health)
{
	std::cout << ">>> Enchanté, mon nom est " << this->name << "." << std::endl;
}

// Destructeur
Character::~Character()
{
	std::cout << ">>> Aurevoir, et que les flots du destin vous guident." << std::endl;
}

// Private method to increase gold amount.
void Character::_addGold(int amount)
{
	this->_gold += amount;
}

// Public method to safely add gold.
void Character::editGold(int amount)
{
	this->_addGold(amount);
	std::cout << this->name << " a gagné " << amount << " pièces d'or." << std::endl;
}

// Private method to apply damage.
void Character::_applyDamage(int value)
{
	this->_health -= value;
}

// Public method to safely apply damage.
void Character::takeDamage(int value)
{
	this->_applyDamage(value);
	std::cout << this->name << " subit " << value << " points de dégâts!" << std::endl;
}

int	main(void)
{
	Character Alrik("Alrik", 58, 100); // Les paramètres servent à initialiser _gold et _health via le constructeur de classe.
	Alrik.level = 12;	// Le level peut être assigné ici car c'est un membre 'public'.
	
//	Alrik._addGold(25);	 Cette ligne ne compile pas car _addGold() est une méthode 'private".
	Alrik.editGold(25); // On utilise plutôt la méthode public editGold() qui appelée un mutateur.

//	Alrik._applyDamage(10);	Même chose ici, _applyDamage est 'protected' donc ça ne compile pas.
	Alrik.takeDamage(10);

	return 0;
}
