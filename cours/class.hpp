// CLASSES

#ifndef CLASS_H
#define CLASS_H

/*
    En C++, une classe est un type de structure permettant de stocker et manipuler 
    des données. Elle peut contenir des variables et des fonctions que l'on 
    appelle les membres de la classe.
*/

class Personnage // Déclaration d'une nouvelle classe "Personnage"
{
    // Spécificateur d'accès :
    public: // Les membres "public" sont accessibles depuis n'importe où dans le programme.

        // Variables membres
        std::string Nom;
        int Âge;

        // Les fonctions membres sont appelées les méthodes.
        void    ft_print_info(void);

        // Le constructeur et le destructeur sont des méthodes spéciales appelées
        // lors de la création ou de la destruction d'une instance de classe.
        Personnage(void); // Constructeur
        ~Personnage(void); // Destructeur
};

#endif