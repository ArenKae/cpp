// VISIBILITY & INITIALIZATION

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
        std::string const name; // Le nom du personnage est une constante.
        int level;

        Character(std::string str, int credits, int helath); // Constructeur prenant 2 paramètres à initialiser
        ~Character(void); // Destructeur

		// Les accesseurs (accessors) sont des fonctions permettant de lire des données private/protected :
		int getHealth(void) const; 	// const indique ici que cette fonction membre ne modifiera pas notre
		int getCredits(void) const;	// instance actuelle de la classe Character (mode lecture seule).

		// Les mutateurs (mutators) permettent de modifier des données private/protected :
		void editCredits(int amount);
		void takeDamage(int dmg);

	// Les membres "private" ne sont accessibles que depuis l'intérieur de la classe.
	// This is useful for encapsulation to control what is accessible or not to the user.
	private:
		int _credits;					// Le nom d'un membre privé est souvent précédé 
		void _addCredits(int amount);	// d'un underscore '_' par convention.

	// Les membres "protected" ne sont accessibles que depuis l'intérieur d'une classe et de
	// ses classes dérivées ou classes "enfant" (voir notion d'héritage).
	protected:
		int _health;
		void _applyDamage(int dmg);
};

#endif