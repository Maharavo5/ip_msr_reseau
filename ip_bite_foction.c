#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ip_bite.h"

void entrer(char enter[100],int *bite_reseau,nombre *nbr)
{   
    

    do
    {
        printf("entrer l'adresse IO et le nombre nombre de bite du reseau(IP|nbr_reseau):");
        scanf("%s",enter);
        sscanf(enter,"%d.%d.%d.%d|%d",&nbr->un,&nbr->deux,&nbr->trois,&nbr->quatre,bite_reseau);
        printf("\nip____%d,%d,%d,%d\n",nbr->un,nbr->deux,nbr->trois,nbr->quatre);
        if(nbr->un>255 || nbr->deux>255 || nbr->trois>255 || nbr->quatre>255 || strlen(enter)!=18 && strlen(enter)<17)
        {
            printf("erreur --- reessayer\n");
        }
    } while(nbr->un>255 || nbr->deux>255 || nbr->trois>255 || nbr->quatre>255 && strlen(enter)>18 && strlen(enter)<17);
    printf("%s",enter);
    
}

void msr (nombre ms,nombre nbr,int bite_reseau,char msr_bin[100])
{       
    //char chaine[100];
    char one[17],two[17],three[17],four[17];
    int i;
    int a;
    printf ("masque de sous reseau:");
    for ( i=0;i<bite_reseau;i++)
    {
        strcat(msr_bin,"1");
        if(i%8==7)
        {
                 strcat(msr_bin,"|");
        }
        else
        {
            strcat(msr_bin,".");
        }
    }
    for(i=0;i<(32-bite_reseau);i++)
    {   
        strcat(msr_bin,"0");
        if(i%8==(8-(bite_reseau%8)))
        {
                 strcat(msr_bin,"|");
        }
        else
        {
            strcat(msr_bin,".");
        }
       
    }
    //printf("%s",msr_bin);
    sscanf(msr_bin,"%[^|]|%[^|]|%[^|]|%s",one,two,three,four);
   // printf("\n%s\n%s\n%s\n%s\n",one,two,three,four);
    ms.un=binaire(one);
    ms.deux=binaire(two);
    ms.trois=binaire(three);
    ms.quatre=binaire(four);
    printf("%d.%d.%d.%d\n",ms.un,ms.deux,ms.trois,ms.quatre);
}

int binaire(char chaine[17])
{   
    int mb;
    int un,deux,trois,quatre,cinq,six,sept,huit;
    int a,b,c,d,e,f,g,h;
    sscanf(chaine,"%d.%d.%d.%d.%d.%d.%d.%d",&un,&deux,&trois,&quatre,&cinq,&six,&sept,&huit);
    if(un==1)
    {
        a=puissance(7);
    }
    else{
         a=0;
    }
       
    if(deux==1){
        b=puissance(6);
    }
     else{
         b=0;
    }
     if(trois==1){
        c=puissance(5);
    }
     else{
         c=0;
    }
     if(quatre==1){
        d=puissance(4);
    }
     else{
         d=0;
    }
     if(cinq==1){
        e=puissance(3);
    }
     else{
         e=0;
    }
     if(six==1){
        f=puissance(2);
    }
     else{
         f=0;
    }
     if(sept==1){
        g=puissance(1);
    }
     else{
         g=0;
    }
     if(huit==1){
        h=puissance(0);
    }
     else{
         h=0;
    }
    mb=a+b+c+d+e+f+g+h;
    return mb;
}

int puissance (int n)
{   
    int i;
    int a=1;
    for (i=0 ;i<n;i++)
    {
        a*=2;
    }
    return a;
}


void machine(int bite_reseau,int *nbr_machine)
{
    int a;
  
    a=32-(bite_reseau);
    *nbr_machine=puissance(a)-2;
    //printf("le nombre du machine connecté est %d\n**",*nbr_machine);
}

void do_binaire(nombre nbr,char chaine[100])
{   
    int b;
    int i;
    for (i=7;i>=0;i--)
    {
        if(nbr.un>=puissance(i))
        {   
            
            b=nbr.un-puissance(i);
            nbr.un=b;
            strcat(chaine,"1");
        }
        else{
            strcat(chaine,"0");
        }
         if(i==0){
                 strcat(chaine,"|");
        }
        else{
                 strcat(chaine,".");
            }
    }
     for (i=7;i>=0;i--)
    {
       
        if(nbr.deux>puissance(i))
        {   
            b=nbr.deux-puissance(i);
            nbr.deux=b;
            strcat(chaine,"1");
           
        }
        else{
            strcat(chaine,"0");
           
        }
        if(i==0){
            strcat(chaine,"|");
        }
        else{
            strcat(chaine,".");
        }
    }
     for (i=7;i>=0;i--)
    {
       
        if(nbr.trois>puissance(i))
        {   
            b=nbr.trois-puissance(i);
            nbr.trois=b;
            strcat(chaine,"1");
          
        }
        else{
            strcat(chaine,"0");
           
        }
          if(i==0){
            strcat(chaine,"|");
        }
        else{
            strcat(chaine,".");
        }
    }
     for (i=7;i>=0;i--)
    {
       
        if(nbr.quatre>puissance(i))
        {   
            b=nbr.quatre-puissance(i);
            nbr.quatre=b;
            strcat(chaine,"1");
            
        }
        else{
            strcat(chaine,"0");

        }
          if(i==0){
            strcat(chaine,"|");
        }
        else{
            strcat(chaine,".");
        }
    }
}



/*void reseau (nombre *res,char msr_bin[100],char ip_bin[100],char ad_reseau[100]){
    char a[17],b[17],c[17],d[17];
    char e[17],f[17],g[17],h[17];
    int un,de,tr,qu,ci,si,se,hu;
    int i,j,k,l,m,n,o,p;
    //nombre res;
    char one[17],two[17],three[17],four[17];
    sscanf(ip_bin,"%[^|]|%[^|]|%[^|]|%s",a,b,c,d);
    sscanf(msr_bin,"%[^|]|%[^|]|%[^|]|%s",e,f,g,h);
    printf("\n%s==",a);
    sscanf(a,"%d.%d.%d.%d.%d.%d.%d.%d",&un,&de,&tr,&qu,&ci,&si,&se,&hu);
    printf("un:%d",un);
    sscanf(e,"%d.%d.%d.%d.%d.%d.%d.%d",&i,&j,&k,&l,&m,&n,&o,&p);
    printf("\n%d%d%d%d%d%d%d%d\n",un ,de,tr,qu,ci,si,se,hu);
     printf("%d%d%d%d%d%d%d%d",i,j,k,l,m,n,o,p);
    if(un==1 && i==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
    strcat(ad_reseau,".");
     if(de==1 && j==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(tr==1 && k==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(qu==1 && l==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(ci==1 && m==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(si==1 && n==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(se==1 && o==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(hu==1 && p==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }

     strcat(ad_reseau,"|");
    sscanf(b,"%d.%d.%d.%d.%d.%d.%d.%d",&un,&de,&tr,&qu,&ci,&si,&se,&hu);
    sscanf(f,"%d.%d.%d.%d.%d.%d.%d.%d",&i,&j,&k,&l,&m,&n,&o,&p);
    if(un==1 && i==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
    strcat(ad_reseau,".");
     if(de==1 && j==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(tr==1 && k==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(qu==1 && l==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(ci==1 && m==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(si==1 && n==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(se==1 && o==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(hu==1 && p==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,"|");
    sscanf(c,"%d.%d.%d.%d.%d.%d.%d.%d",&un,&de,&tr,&qu,&ci,&si,&se,&hu);
    sscanf(g,"%d.%d.%d.%d.%d.%d.%d.%d",&i,&j,&k,&l,&m,&n,&o,&p);
    if(un==1 && i==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
    strcat(ad_reseau,".");
     if(de==1 && j==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(tr==1 && k==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(qu==1 && l==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(ci==1 && m==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(si==1 && n==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(se==1 && o==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(hu==1 && p==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,"|");
    sscanf(d,"%d.%d.%d.%d.%d.%d.%d.%d",&un,&de,&tr,&qu,&ci,&si,&se,&hu);
    sscanf(h,"%d.%d.%d.%d.%d.%d.%d.%d",&i,&j,&k,&l,&m,&n,&o,&p);
    if(un==1 && i==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
    strcat(ad_reseau,".");
     if(de==1 && j==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(tr==1 && k==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(qu==1 && l==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(ci==1 && m==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(si==1 && n==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(se==1 && o==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,".");
     if(hu==1 && p==1)
    {
        strcat(ad_reseau,"1");
        
    }
    else
    {
        strcat(ad_reseau,"0");
    }
     strcat(ad_reseau,"|");

     printf("\nbin reseau %s\n",ad_reseau);
     
     sscanf(ad_reseau,"%[^|]|%15[^|]|%15[^|]|%s",one,two,three,four);
    res->un=binaire(one);
    res->deux=binaire(two);
    res->trois=binaire(three);
    res->quatre=binaire(four);
    printf("\nAdresse reseau: %d.%d.%d.%d\n",res->un,res->deux,res->trois,res->quatre);
}*/

void adresse_broadcast (int bite_reseau,char ip_bin[100],char ad_broad[100],nombre *broadcast )
{
    int i;

    char one[17],two[17],three[17],four[17];
    printf("adresse de broadcast:");
    ad_broad=ip_bin;
    //printf("\n %s\n",ad_broad);
    for ( i=0;i<strlen(ad_broad);i++)
    {
        if(i>((bite_reseau)*2))
        {
            if(ad_broad[i]=='1' || ad_broad[i]=='0')
            {
                ad_broad[i]='1';
            }
        }
    }
    // printf("\n %s\n",ad_broad);
     sscanf(ad_broad,"%[^|]|%[^|]|%[^|]|%s",one,two,three,four);
     //printf("\n--%s,%s,%s,%s\n--",one,two,three,four);
    broadcast->un=binaire(one);
    broadcast->deux=binaire(two);
    broadcast->trois=binaire(three);
    broadcast->quatre=binaire(four);
    printf("%d.%d.%d.%d\n",broadcast->un,broadcast->deux,broadcast->trois,broadcast->quatre);
}
void adresse_reseau (int bite_reseau,char ip_bin[100],char ad_reseau[100],nombre *reseau )
{
    int i;

    char one[17],two[17],three[17],four[17];
    printf("adresse de reseau:");
    ad_reseau=ip_bin;
    //printf("\n %s\n",ad_reseau);
    for ( i=0;i<strlen(ad_reseau);i++)
    {
        if(i>((bite_reseau)*2))
        {
            if(ad_reseau[i]=='1' || ad_reseau[i]=='0')
            {
                ad_reseau[i]='0';
            }
        }
    }
     //printf("\n %s\n",ad_reseau);
     sscanf(ad_reseau,"%[^|]|%[^|]|%[^|]|%s",one,two,three,four);
     //printf("\n--%s,%s,%s,%s\n--",one,two,three,four);
    reseau->un=binaire(one);
    reseau->deux=binaire(two);
    reseau->trois=binaire(three);
    reseau->quatre=binaire(four);
    printf("%d.%d.%d.%d\n",reseau->un,reseau->deux,reseau->trois,reseau->quatre);
}

void decoupage(int bite_reseau,nombre res)
{   
    int decoupe;
    int sr;
    int i;
    int s_bite_reseau;
    int nbr_machine;
    char s_ad_reseau[100];
    nombre *tab=NULL;
    nombre *tabs=NULL;
    printf("\nentrer le nombre du découpage:");
    scanf("%d",&decoupe);
    sr=puissance(decoupe);
    s_bite_reseau=bite_reseau+decoupe;
    printf("\nnombre de sous reseau:%d",sr);
    machine(s_bite_reseau,&nbr_machine);
    printf("\nnombre du machne dans chaque sous reseaux:%d",nbr_machine);
    tab=allocation(sr);
    tabs=allocation(sr);
    
    for(i=0;i<sr;i++)
    {   
        tab[i].un=res.un;
        tab[i].deux=res.deux;
        tab[i].trois=res.trois;
        tab[i].quatre=res.quatre;
        
        printf("\nadresse reseau du sous reseau %d:",i+1);
        printf("%d.%d.%d.%d",tab[i].un,tab[i].deux,tab[i].trois,tab[i].quatre);
        printf("\nadresse du broadcast du sous reseau %d:",i+1);
        tabs[i].quatre=tab[i].quatre+nbr_machine+1;

        if(tabs[i].quatre>255)
        {   
            tabs[i].quatre=255;
            tabs[i].trois=tab[i].trois+(tab[i].quatre+nbr_machine+1-255);
            res.deux=tabs[i].deux;
            res.un=tabs[i].un;
            if(tabs[i].trois>255)
            {
                tabs[i].trois=255;
                tabs[i].deux=tab[i].deux+(tab[i].trois+nbr_machine+1-255);
                res.un=tabs[i].un;
                if(tabs[i].deux>255)
                {
                    tabs[i].deux=255;
                    tabs[i].un=tab[i].un+(tab[i].deux+nbr_machine+1-255);
                }
                else{
                    tabs[i].un=tab[i].un;
                }
            }
            else{
                tabs[i].deux=tab[i].deux;
            }
        }
        else
        {
            tabs[i].trois=tab[i].trois;
            tabs[i].deux=tab[i].deux;
            tabs[i].un=tab[i].un;
        }
        res.quatre=tabs[i].quatre+1;
        res.trois=tabs[i].trois;
        res.deux=tabs[i].deux;
        res.un=tabs[i].un;
        printf("%d.%d.%d.%d",tabs[i].un,tabs[i].deux,tabs[i].trois,tabs[i].quatre);
       
       
    }
    
}

nombre *allocation(int n)
{
    nombre *tab=NULL;
    tab=(nombre*)malloc(n*sizeof(nombre));
    if (tab==NULL)
    {
        exit (1);
    }
    
    return tab;
}
