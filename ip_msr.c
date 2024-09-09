#include <stdio.h>
#include <stdlib.h>
#include "ip_bite.h"

int main()
{
    char chaine[40];
    nombre ip;
    nombre msr;
    nombre reseau;
    nombre broadcast;
    char msr_bite[100];
    char ip_bite[100];
    char ad_reseau[100];
    char ad_broadcast[100];
    int bite_reseau;
    int nbr_machine;
    enter(chaine,&ip,&msr,msr_bite,&bite_reseau,ip_bite);
    adresse_reseau(bite_reseau,ip_bite,ad_reseau,&reseau);
   // printf("bite-reseau=%d",bite_reseau);
    adresse_broadcast(bite_reseau,ip_bite,ad_broadcast,&broadcast);
    machine(bite_reseau,&nbr_machine);
    printf("\n nombre de machine :%d",nbr_machine);
    return 0;
}