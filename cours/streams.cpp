// STDIO STREAMS

/*
    <iostream> est une bibliothèque qui permet la gestion dynamique des 
    entrées et des sorties en C++. L'on peut s'en servir pour lire et écrire
    très simplement les différents flux de données (stdin, stdout, stderr)
    sans avoir besoin d'utiliser des fonctions comme read() ou write().
*/

#include <iostream>
#include <cmath>

int main(void)
{
    /*
        iostream contient le namespace "std" qui permet d'accéder à différents 
        objets comme "cout", "cin" et "endl".

        "cout" est l'objet de flux d'entrée standard utilisé pour afficher des
        données à l'écran. Il est souvent combiné avec l'opérateur de sortie
        '<<' pour écrire du texte et des variables dans la console.
    */
    std::cout << "Hello world!\n\n";

    //  En plus des strings literal, std::cout peut être utilisé pour afficher
    //  des valeurs de variables ou de retour de fonctions :

    int i = 64;
    std::cout << "i vaut " << i << " et √i = " << sqrt(i) << "\n\n";

    /*
        Plutôt que d'utiliser des '\n', on peut invoquer l'objet std::endl pour
        afficher une newline. Cette méthode à l'avantage d'être plus portable, 
        l'interprétation du '\n' pouvant varier selon l'OS. De plus, il s'agit
        d'une pratique plus sécurisée et "propre" (mais moins performance efficiente)
        car std::endl vide le tampon associé au flux de sortie, ce qui garantit
        l'affichage immédiat des données et évite qu'elles soient "buffurisées".
    */

    std::cout << "I love 42!" << std::endl;
    std::cout << "C++ is an awesome langage!\n" << std::flush; // Vide le tampon manuellement
    std::cout << "Try doing this in C!\n\n";
    std::cout.flush(); // Autre méthode de vidage manuel du tampon

    /*
        "cin" est l'objet de flux d'entrée standard utilisé pour lire des données depuis
        le clavier. Il est souvent combiné avec l'opérateur d'entrée '>>' pour extraire
        des données et les stocker dans des variables.
    */

    char buffer[512];
    std::cout << "Input a word: ";
    std::cin >> buffer; // Lit l'entrée standard et stock son contenu dans buffer
    if (!std::cin) {    // Gestion d'erreur
        std::cerr << "Input error" << std::endl; // Écrit sur la sortie d'erreur avec std::cer
        return (1);}
    std::cout << "Your word is: " << buffer << std::endl;

    return 0;
}