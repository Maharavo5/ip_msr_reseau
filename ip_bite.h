#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct numero
{
    int un;
    int deux;
    int trois;
    int quatre;
}nombre;

void entrer(char enter[100],int *bite_reseau,nombre *nbr);
void msr (nombre msr,nombre nbr,int bite_reseau,char msr_bin[100]);
int binaire(char chaine[17]);
int puissance (int n);
void machine(int bite_reseau,int *nbr_machine);
void do_binaire(nombre nbr,char chaine[100]);
void adresse_broadcast (int bite_reseau,char ip_bin[100],char ad_broad[100] ,nombre *broadcast);
//void reseau (nombre *res,char msr_bin[100],char ip_bin[100],char ad_reseau[100]);
void decoupage(int bite_reseau,nombre res);
nombre *allocation(int n);
void adresse_reseau (int bite_reseau,char ip_bin[100],char ad_reseau[100],nombre *reseau );
void enter(char chaine[40] ,nombre *ip,nombre *msr,char msr_bite[100],int *bite_reseau,char ip_bite[100]);
void masque_sr(nombre msr,char msr_bite[100]);


