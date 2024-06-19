// CLASS VS STRUCT

#ifndef CLASS_VS_STRUCT_H
#define CLASS_VS_STRUCT_H

#include <iostream>

/*
	Les structures existent aussi en C++. En fait, les classes ne sont rien d'autre que
	des structures particulières. La syntaxe pour déclarer une classe ou une structure
	est très similaire. La seule différence entre les 2 est que la classe permet un 
	meilleur contrôle sur la visibilité des objets qu'elle contient.
*/

class Character // Déclaration d'une nouvelle classe "Character"
{
	// Spécificateur d'accès :
    // Les membres "public" sont accessibles depuis n'importe où dans le programme.
	public:
        std::string name;
        int level;

        Character(void); // Constructeur 
        ~Character(void); // Destructeur
		void editGold(int amount);	// Méthode public pour manipuler l'or d'un personnage.
		void takeDamage(int dmg);	// Méthode public pour infliger des dégâts.

	// Les membres "private" ne sont accessibles que depuis l'intérieur de la classe.
	// This is useful for encapsulation to control what is accessible or not to the user.
	private:
		int _gold;					// Le nom d'un membre privé est souvent précédé 
		void _addGold(int amount);	// d'un underscore '_' par convention.

	// Les membres "protected" ne sont accessibles que depuis l'intérieur d'une classe et de
	// ses classes dérivées ou classes "enfant" (voir notion d'héritage).
	protected:
		int health;
		void applyDamage(int dmg);
};

#endif