#include <stdio.h>
#include <time.h>

//faire un ulimit -s unlimited pour taille supperieur a 2 000 000

#define len 1000000

//int *tabLong(){
//
//    //création du tab
//    int tab [len];
//    printf ("tab 1 :\n");
//    for (int i = 0 ; i <= len ; i++){
//        tab[i]=i;
//        printf(" %d ",tab[i]);
//    }
//
//    //swap du tab
//    int separation = 3;
//    int temp;
//    printf("\ntab 2 :\n");
//    for (int i = 0 ; i < len - separation ; i++){
////        temp = tab[i];
////        tab[i] = tab[separation+i+1];
////        tab[len - separation +i+1]= temp;
////        temp = tab[len - separation - i];
////        tab[len-separation+i] = tab[i];
////        tab[i]=temp;
//        temp = tab[len - i];
//        tab[len-i] = tab[separation-i+1];
//        tab[separation-i+1]=temp;
//        for (int i = 0 ; i <= len ; i++){
//            printf(" %d ",tab[i]);
//        }
//        printf("\n");
////        temp = tab[separation + 1 + i];
////        tab[len - separation + 1 + i] = tab[i];
////        tab[i] = temp;
//    }
//    printf("\n\n\n");
//    //print du tab
//    for (int i = 0 ; i <= len ; i++){
//        printf(" %d ",tab[i]);
//    }
//}



int *invers(int  *tab,int start , int end){ //cette fonctione permet d'inversé avec en paramètre le tableau a inversé le debut de où on veut l'inversé et la fin
    int longueur = end - start ; //on defini la longueur de ce qu'on veut inverser avec la fin - le debut
    int temp;
    for (int i = 0; i <= (longueur / 2) ; i++) {// (floor(longueur/2) une boucle for tant que i est inferieur a longueur diviser par 2 pour ne pas faire le tour du tableau 2 fois ce qui renverais un tableau pas inversé
        temp = tab[end - i]; //on stock dans une variable temporaire la fin de la parti du tableau qu'on veut inverser - i (pour décrémenté)
        tab[end - i] = tab[start + i]; //on met a la fin du tableau - i (pour décrémenté) , le debut du tableau +i (pour incrémenté)
        tab[start + i] = temp; //on met dans le debut du tableau +i (pour incrémenté) la variable temporaire
    }
    return (tab); //on renvoie le tab qu'on a trié
}

int *tabChanger(int *tab){
    int separation=len/2; // comme ca ca evite de mettre un nombre brut (il va evoluer en fonctione de len)
    tab = invers(tab,0,separation); //on inverse le debut jusqu'au separateur
    tab = invers(tab,separation+1,len); // du separateur à la fin
    tab = invers(tab,0,len); //et puis du debut jusqu'a la fin pour l'inversement de tout le tableau

    /* pour print le tab */
//    printf("\n\ntab final :\n");
//    for (int i = 0 ; i <= len ; i++){
//        printf(" %d ",tab[i]);
//    }
    return (tab); //renvoie le tab inversé
}

int main(){

    clock_t debut = clock(); //pour calculer le temps
    //création du tableau
    int tab [len]; //on creer le tab avec la taille len
    printf ("tab de base :\n");
    for (int i = 0 ; i <= len ; i++){ //implemente mon tableau
        tab[i]=i;
//        printf(" %d ",tab[i]);
    }
    //swap
    tabChanger(tab); //j'appel la fonction pour inversé le tableau
    clock_t fin = clock(); //fin de la clock

    unsigned long millis = (fin -  debut) * 1000 / CLOCKS_PER_SEC; // je calcule mon temps pour l'afficher en ms

    printf( "\n\nfini en : %ld ms\n", millis );
    return 0;
}
