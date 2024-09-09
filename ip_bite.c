#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ip_bite.h"

int main ()
{   
    char enter[100];
    int bite_reseau;
    nombre ms;
    nombre nbr;
    nombre res;
    nombre broadcast;
    char ip_bin[100];
    char msr_bin[100];
    char ad_reseau[100];
    int nbr_machine;
    char ad_broad[100];
    entrer(enter,&bite_reseau,&nbr);
    msr(ms,nbr,bite_reseau,msr_bin);
   
    do_binaire(nbr,ip_bin);
   // printf("\nmsr_bin %s",msr_bin);
   
   // reseau(&res,msr_bin,ip_bin,ad_reseau);
   adresse_reseau(bite_reseau,ip_bin,ad_reseau,&res);
    //printf("\nAdresse reseau: %d.%d.%d.%d\n",res.un,res.deux,res.trois,res.quatre);
    //printf("\nAdresse IP binaire: %d.%d.%d.%d\n",nbr.un,nbr.deux,nbr.trois,nbr.quatre); 
    adresse_broadcast(bite_reseau,ip_bin,ad_broad,&broadcast); 
     machine(bite_reseau,&nbr_machine);
     printf("\nle nombre du machine est %d\n",nbr_machine);
    decoupage(bite_reseau,res);
    return 0;
}

