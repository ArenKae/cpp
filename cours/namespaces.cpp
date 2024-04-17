// NAMESPACES

/*  
    En C++, le namespace est une fonctionnalité permettant de regrouper des
    noms d'entités (variables, fonctions, classes...) sous un même acronyme.

    Cette notion est utile pour créer des groupes d'objets partageant un lien
    logique, mais aussi et surtout pour éviter les conflits entre objets ayant 
    le même nom.
*/

// Première définition d'une variable globale et d'une fonction.
int global = 1;
int ft(void) { return 5;}

/*
    Le namespace "Foo" est créé et contient 2 objets global et ft() ayant leur
    propre valeur. Cela ne crée pas de conflit à la compilation car ces 2 objets
    sont redéfinis dans le scope du namespace Foo.
*/
namespace Foo
{
    int global = 2;
    int ft(void) { return 10;}  
}

/*
    Le namespace aliasing permet de définir un namespace comme équivalent à un
    autre. Cela peut être utile pour raccourcir la syntaxe lorsqu'on accède à
    des éléments se trouvant dans plusieurs namespaces imbriqués.
*/
namespace Bar = Foo;

#include <stdio.h>

int main(void)
{
    printf("global = %d\n", global);
    printf("ft() = %d\n\n", ft());

    //  L'opérateur de resotution de portée :: (scope resoution operator)
    //  permet d'accéder à un élément stocké dans un namespace.

    printf("Foo::global = %d\n", Foo::global);
    printf("Foo::ft() = %d\n\n", Foo::ft());

    printf("Bar::global = %d\n", Bar::global);
    printf("Bar::ft() = %d\n\n", Bar::ft());

    //  La syntaxe suivante est équivalente au fait d'appeler l'objet global
    //  ou ft() directement (il s'agit ici d'un empty namespace).

    printf("::global = %d\n", ::global);
    printf("::ft() = %d\n\n", ::ft());

    return 0;
}