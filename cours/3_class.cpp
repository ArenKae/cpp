// CLASSES

#include <iostream>
#include <unistd.h>
#include "3_class.hpp"

/*
    Le constructeur est appelé automatiquement au moment où une nouvelle instance
    de classe est crée. La classe 'Personnage' déclaré dans le .hpp sert de "moule" pour
    créer une instance unique de type Personnage. Le constructeur est utile pour initialiser
    des variables ou allouer de la mémoire à la création d'une nouvelle instance de classe.
*/

Personnage::Personnage(void) // Constructeur Personnage de la classe Personnage
{
    std::cout << "Appel du constructeur." << std::endl;

    // Le mot-clé 'this' sert à désigner l'objet (ou l'instance de la classe) qui appelle 
    // le constructeur. 'this' peut uniquement être utilisé au sein des méthodes d'une classe.
	// this est un pointeur implicite qui fait référence à l'objet actuel au sein d'une méthode
	// de classe. 
    this->Nom = "Arren Kae";
    this->Âge = 42;
}

/*
    Le destructeur est appelé automatiquement au moment où une instance de classe est détruite
    (en général en quittant les brackets de la fonction où la classe fut crée). Cette méthode
    est surtout utile pour libérer la mémoire qui a été allouée dans cette classe.
*/

Personnage::~Personnage(void) // Destructeur ~Personnage de la classe Personnage
{
    std::cout << "Appel du destructeur." << std::endl;

    // L'instruction return n'est pas nécéssaire puisque le constructeur et le destructeur
    // n'ont pas de valeur de retour. On peut toutefois s'en servir par souci de clarté.
    return;
}

void    Personnage::ft_print_info(void)
{
    std::cout << std::endl;
    std::cout << "[Informations du personnage]" << std::endl;
    std::cout << "- Nom : " << this->Nom << std::endl;
    std::cout << "- Âge : " << this->Âge << " ans" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    Personnage ArenKae; // Une nouvelle instance de la classe 'Personnage' est crée.
    sleep(1);
    ArenKae.ft_print_info(); // La méthode ft_print_info() de l'objet 'ArenKae' est invoquée.
    sleep (1);
    return 0;
}
