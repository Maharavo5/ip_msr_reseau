#include <stdio.h>
#include <stdlib.h>
#include "ip_bite.h"

void enter(char chaine[40] ,nombre *ip,nombre *msr,char msr_bite[100],int *bite_reseau,char ip_bite[100])
{   
    char chaines[17];
    char chain[17];
    int i;
    char b;
    char a;
    
    do
    {
        printf("entrer votre adresse IP et le masque de sous reseau(IP|MSR): ");
        scanf("%s",chaine);    
        sscanf(chaine,"%[^|]|%s",chaines,chain);
        sscanf(chaine,"%d.%d.%d.%d|%d.%d.%d.%d",&ip->un,&ip->deux,&ip->trois,&ip->quatre,&msr->un,&msr->deux,&msr->trois,&msr->quatre);
        if(strlen(chaine)!=31 ||strlen(chain)!=15 ||strlen(chaines)!=15 ||ip->un>255||ip->deux>255||ip->trois>255||ip->quatre>255||msr->un>255||msr->deux>255||msr->trois>255||msr->quatre>255 )
        {
            printf("erreur ...réessayer\n");
        }
       // printf("\n%s",chain);
        //printf("\n%s\n",chaines);
        do_binaire(*ip,ip_bite);
        do_binaire(*msr,msr_bite);
        //printf("%s",msr_bite);
        b='1';
         //printf("\n%d",b);
        for(i=0;i<strlen(msr_bite);i++)
        {   
          if(msr_bite[i]==49)
            {

                *bite_reseau=i/2;
                
    
            }
            if(msr_bite[i]==48)
            {
                b=msr_bite[i];
               
            }
           
           // printf("\nb=%d",b);
           // printf("\n%d=%d",i,msr_bite[i]);

            if(b==48 && msr_bite[i]==49)
            {
                printf("il y a un erreur sur la masse de sous reseau\n");
                a='1';
               
                exit (1);

            }
           
        }
    //printf("res=%d\n",*bite_reseau);

    } while (strlen(chaine)!=31 ||strlen(chain)!=15 ||strlen(chaines)!=15 || ip->un>255||ip->deux>255||ip->trois>255||ip->quatre>255||msr->un>255||msr->deux>255||msr->trois>255||msr->quatre>255 ||b=='0' && a=='1');
    
   
    
}
