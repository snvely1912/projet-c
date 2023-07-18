#include<stdio.h>
#include<string.h>
#include "LOBAT.h"
void DemandeinscriptionLobat(){
    Inscription in;
    printf("Entrer votre nom:");
    scanf("%s",in.nom);
    printf("Entrer votre prenom:");
    scanf("%s",in.prenom);
    fflush(stdin);
    printf("Entrer votre email:");
    scanf("%s",in.email);
    fflush(stdin);
    printf("Creer un login:");
    scanf("%s",&in.login);
    fflush(stdin);
    printf("Creer un mots de passe:");
    scanf("%s",&in.password);
    do{
        printf("Confirmer le mots de passe:");
        scanf("%s",&in.pass);
        if(strcmp(in.password,in.pass)!=0){
            printf("Mots de passe non-identique! veuillez resaisir!\n");
        }
    }while(strcmp(in.password,in.pass)!=0);
}
void AjouterUtilisateur(FILE *file){
    Inscription in;
    file=fopen("User.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void AjouterAdministrateur(FILE *file){
    Inscription in;
    file=fopen("Admin.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void AjouterGestionnaire(FILE *file){
    Inscription in;
    file=fopen("Gestion.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void AjouterPaiement(FILE *file){
    Inscription in;
    file=fopen("Paiement.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %s %s %s paiement effectue avec succes\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void DemandeconnexionLobat(){
    connexion conx;
    printf("Veuillez entrer votre login:");
    scanf("%s",&conx.login);
    printf("Veuillez entrer votre mots de passe:");
    scanf("%s",&conx.password);
}
void rechercheAdministrateur(FILE *file) {
    file = fopen("Admin.txt", "r");
    connexion conx;
    Inscription in;
    int isConnected = 0; // Variable pour suivre l'état de connexion

    if (file != NULL) {
        do {
            printf("Veuillez entrer votre login:");
            scanf("%s", conx.login);
            printf("Veuillez entrer votre mot de passe:");
            scanf("%s", conx.password);

            while (fscanf(file, "%s %s %s %s %s %s\n", in.nom, in.prenom, in.email, in.login, in.password, in.pass) != EOF) {
                if (strcasecmp(in.login, conx.login) == 0 && strcasecmp(in.password, conx.password) == 0) {
                    printf("Connexion reussie!\n");
                    isConnected = 1;
                    break; // Sortir de la boucle dès qu'on trouve une correspondance
                }
            }

            if (!isConnected) {
                printf("Connexion echouee\n");
            }

            rewind(file); // Réinitialiser le curseur de fichier pour répéter la recherche
        } while (!isConnected);

    } else {
        printf("Erreur d'ouverture du fichier\n");
    }

    fclose(file);
}

void rechercheGestionnaire(FILE *file) {
    file = fopen("Gestion.txt", "r");
    connexion conx;
    Inscription in;
    int isConnected = 0;

    if (file != NULL) {
        do {
            printf("Veuillez entrer votre login:");
            scanf("%s", conx.login);
            printf("Veuillez entrer votre mot de passe:");
            scanf("%s", conx.password);

            while (fscanf(file, "%s %s %s %s %s %s\n", in.nom, in.prenom, in.email, in.login, in.password, in.pass) != EOF) {
                if (strcasecmp(in.login, conx.login) == 0 && strcasecmp(in.password, conx.password) == 0) {
                    printf("Connexion reussie!\n");
                    isConnected = 1;
                    break;
                }
            }

            if (!isConnected) {
                printf("Connexion echouee\n");
                DemandeconnexionLobat();
            }

            rewind(file);
        } while (!isConnected);

    } else {
        printf("Erreur d'ouverture du fichier\n");
    }

    fclose(file);
}

void choisirLocation(FILE *file,int position){
location l;
bailleur b;
int cp=0;
    FILE* fnewe=fopen("LocationNew.txt","a");
    file=fopen("Location.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,&l.prix,b.CNI)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
            }else{
                fprintf(fnewe,"%s %s %s %d %s Location approuve avec succes!\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("Location.txt");
    rename("locationNew.txt","Location.txt");
}
int menu(){
    int choix;
    printf(" 1-Ajouter un bailleur et les informations de sa location\n ");
    printf("2-Consulter la liste des bailleurs \n ");
    printf("3-Modifier un bailleur et sa location\n");
    printf(" 4-Supprimer un bailleur\n");
    printf(" 5-Ajouter un gestionnaire\n");
    printf(" 6-Consulter un gestionnaire\n");
    printf(" 7-Modifier un gestionnaire\n");
    printf(" 8-Voir la liste des locations disponibles\n");
    printf(" 9-Consulter une location suivant selon le type (studio,appartement,maison)\n");
    printf(" 10-Consulter une location selon le login\n");
    printf(" 11-Se deconnecter!\n");
    do{
        printf("Entrer votre choix:");
        scanf("%d",&choix);
        if(choix<1 || choix>11)
        {
            printf("veuillez entrer un choix valide!\n");
        }
    }while(choix<1 || choix>11);
    return choix;
}
void AfficherGestion(){
    Inscription in;
     printf("%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
}
void consulterGestion(FILE *file){
    file=fopen("Gestion.txt","r");
    Inscription in;
    if(file!=NULL){

        while(fscanf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass)!=EOF){
           AfficherGestion();
            system("pause");
        }
    }else{
        printf("Erreur d'ouverture du fichier!\n");
    }
    fclose(file);
}
void modifierGestion(FILE *file,int position){
Inscription in;
int cp=0;
    FILE* fnewe=fopen("GestionNew.txt","a");
    file=fopen("Gestion.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
            }else{
                DemandeinscriptionLobat();
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("Gestion.txt");
    rename("gestionNew.txt","Gestion.txt");
}
void ChercherGestion(FILE *file,char login){
    Inscription in;
    file=fopen("User.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass)!=EOF){
              if(strcasecmp(in.login,login)==0){
                    AfficherGestion();
                    system("pause");
                }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void ChercherLocation(FILE *file,char locat){
    location l;
    bailleur b;
   file=fopen("Location.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,&l.prix,b.CNI)!=EOF){
             if(strcasecmp(l.type,locat)==0){
                    AfficherLocation(l,b);
                    system("pause");
                }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void supprimerUsers(FILE *file,int position){
Inscription in;
int cp=0;
    FILE* fnewe=fopen("UserNew.txt","a");
    file=fopen("User.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%s %s %s %s %s %s\n",in.nom,in.prenom,in.email,in.login,in.password,in.pass);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("User.txt");
    rename("UserNew.txt","User.txt");
}
int menu1(){
    int repo;
    printf(" 1-Ajouter un contrat pour un client deja existant\n ");
    printf("2-Consulter la liste des clients \n ");
    printf("3-Modifier un client et son contrat\n");
    printf(" 4-Supprimer un client\n");
    printf(" 5-Appliquer une demande de paiement pour un clients\n");
    printf(" 6-Se deconnecter!\n");
    do{
        printf("Entrer votre choix:");
        scanf("%d",&repo);
        if(repo<1 || repo>6)
        {
            printf("veuillez entrer un choix valide!\n");
        }
    }while(repo<1 || repo>6);
    return repo;
}
void AjouterBailleurAuFichier(FILE *file,location l, bailleur b){

    file=fopen("Bailleurs.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %d %s\n",b.nom,b.prenom,b.adresse,b.tel,b.CNI);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
    file=fopen("Location.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void  AjouterClientAuFichier(FILE *file,contrat co,client cl){
     file=fopen("Clients.txt","a");

    if(file!=NULL){
        fprintf(file,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,cl.tel,cl.CNI);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
    file=fopen("Contrat.txt","a");

    if(file!=NULL){
        fprintf(file,"%d %d %d %d %d %d %s %s\n",co.j,co.m,co.a,co.jj,co.mm,co.aa,co.modePaiement,cl.CNI);
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(file);
}
void AfficherBailleur(bailleur b){
     printf("%s %s %s %d %s\n",b.nom,b.prenom,b.adresse,b.tel,b.CNI);
}
void AfficherLocation(location l,bailleur b){
     printf("%s %s %s %d %s\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
}
void AfficherClients(client cl){
    printf("%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,cl.tel,cl.CNI);
}
void AfficherContrat(contrat co,client cl){
    printf("%d %d %d %d %d %d %s %s\n",co.j,co.m,co.a,co.jj,co.mm,co.aa,co.modePaiement,cl.CNI);
}
bailleur creerBailleur() {
    bailleur b;
    location l;
    fflush(stdin);
    puts("Saisir le nom du bailleur:");
    gets(b.nom);
    puts("Saisir le prenom du bailleur:");
    gets(b.prenom);
    puts("Saisir l adresse du bailleur:");
    gets(b.adresse);
        printf("Entrer le numero de telephone du bailleur:");
        scanf("%d",&b.tel);
    do{
        fflush(stdin);
        printf("Entrer le numero de la carte CNI du bailleur:");
        gets(b.CNI);
        if(strlen(b.CNI)!=17)
        {
            printf("Numero de carte invalide ! Veuillez resaisir un numero qui contient 17 chiffres!\n");
        }
    }while(strlen(b.CNI)!=17);
     fflush(stdin);
    strcat(b.id,b.adresse);
    return b;
}
location infoLocation(){
    location l;
    fflush(stdin);
    puts("Saisir le libelle de la location:");
    gets(l.libe);
    puts("Saisir l adresse de la location :");
    gets(l.adresse);
   do{
        puts("Saisir le type de la location : maison,appartement,studio");
        gets(l.type);
   }while(strcmp(l.type,"maison")!=0 && strcmp(l.type,"appartement")!=0 && strcmp(l.type,"studio")!=0);
    do{
        printf("Saisir le prix de la location:");
        scanf("%d",&l.prix);
    }while(l.prix<=0);
return l;

}
client creerClient() {
    client cl;
    contrat co;
    fflush(stdin);
    puts("Saisir le nom du client:");
    gets(cl.nom);
    puts("Saisir le prenom du client:");
    gets(cl.prenom);
    puts("Saisir l email du client:");
    gets(cl.email);
        printf("Entrer le numero de telephone du client:");
        scanf("%d",&cl.tel);
    do{
        fflush(stdin);
        printf("Entrer le numero de la carte CNI du client:");
        gets(cl.CNI);
        if(strlen(cl.CNI)!=17)
        {
            printf("Numero de carte invalide ! Veuillez resaisir un numero qui contient 17 chiffres!\n");
        }
    }while(strlen(cl.CNI)!=17);
     fflush(stdin);
    strcat(cl.id,cl.email);
    return cl;
}
contrat infoContrat(){
    contrat co;
    fflush(stdin);
    do{
        printf("Saisir le jour de debut du contrat:");
        scanf("%d",&co.j);
    }while(co.j<1 || co.j>31);
    do{
        printf("Saisir le mois de debut du contrat:");
        scanf("%d",&co.m);
    }while(co.m<1 || co.m>12);
    do{
        printf("Saisir l annee  de debut du contrat:");
        scanf("%d",&co.a);
    }while(co.a<2000);
    do{
        printf("Saisir le jour de fin du contrat:");
        scanf("%d",&co.jj);
    }while(co.jj<1 || co.jj>31);
    do{
        printf("Saisir le mois de fin du contrat:");
        scanf("%d",&co.mm);
    }while(co.mm<1 || co.mm>12);
    do{
        printf("Saisir l annee de fin du contrat:");
        scanf("%d",&co.aa);
    }while(co.aa<co.a);
    fflush(stdin);
   do{
        puts("Saisir le mode de paiement de la location : Wave,OraneMoney,FreeMoney");
        gets(co.modePaiement);
   }while(strcmp(co.modePaiement,"Wave")!=0 && strcmp(co.modePaiement,"OraneMoney")!=0 && strcmp(co.modePaiement,"FreeMoney")!=0);
return co;

}
void consulterBailleurs(FILE *file){
    file=fopen("Bailleurs.txt","r");
    bailleur b;
    if(file!=NULL){

        while(fscanf(file,"%s %s %s %d %s",b.nom,b.prenom,b.adresse,&b.tel,b.CNI)!=EOF){
           AfficherBailleur(b);
            system("pause");
        }
    }else{
        printf("Erreur d'ouverture du fichier!\n");
    }
    fclose(file);
}
void consulterLocation(FILE *file){
    file=fopen("Location.txt","r");
    location l;
    bailleur b;
    if(file!=NULL){

        while(fscanf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,&l.prix,b.CNI)!=EOF){
           AfficherLocation(l,b);
            system("pause");
        }
    }else{
        printf("Erreur d'ouverture du fichier!\n");
    }
    fclose(file);
}
void consulterClient(FILE *file){
    file=fopen("Clients.txt","r");
    client cl;
    if(file!=NULL){

        while(fscanf(file,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,&cl.tel,cl.CNI)!=EOF){
           AfficherClients(cl);
            system("pause");
        }
    }else{
        printf("Erreur d'ouverture du fichier!\n");
    }
    fclose(file);
}
void consulterContrat(FILE *file){
    file=fopen("Contrat.txt","r");
    contrat co;
    client cl;
    if(file!=NULL){

        while(fscanf(file,"%d %d %d %d %d %d %s %s\n",&co.j,&co.m,&co.a,&co.jj,&co.mm,&co.aa,co.modePaiement,cl.CNI)!=EOF){
           AfficherContrat(co,cl);
        }
    }else{
        printf("Erreur d'ouverture du fichier!\n");
    }
    fclose(file);
}
void modifierInfo(FILE *file, int position,location lo,bailleur ba){
int cpt=0,cp=0;
bailleur b;
  location l;
    FILE* fnew=fopen("BailleursNew.txt","a");
    file=fopen("Bailleurs.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s",b.nom,b.prenom,b.adresse,&b.tel,b.CNI)!=EOF){
                cpt++;
            if(cpt!=position){
                fprintf(fnew,"%s %s %s %d %s\n",b.nom,b.prenom,b.adresse,b.tel,b.CNI);
            }else{
                fprintf(fnew,"%s %s %s %d %s\n",ba.nom,ba.prenom,ba.adresse,ba.tel,ba.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnew);
    fclose(file);
    remove("Bailleurs.txt");
    rename("BailleursNew.txt","Bailleurs.txt");

    FILE* fnewe=fopen("LocationNew.txt","a");
    file=fopen("Location.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,&l.prix,b.CNI)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
            }else{
                fprintf(fnewe,"%s %s %s %d %s\n",lo.libe,lo.adresse,lo.type,lo.prix,ba.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("Location.txt");
    rename("locationNew.txt","Location.txt");
}
void supprimerInfo(FILE *file, int position){
int cpt=0,cp=0;
bailleur b;
  location l;
    FILE* fnew=fopen("BailleursNew.txt","a");
    file=fopen("Bailleurs.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s",b.nom,b.prenom,b.adresse,&b.tel,b.CNI)!=EOF){
                cpt++;
            if(cpt!=position){
                fprintf(fnew,"%s %s %s %d %s\n",b.nom,b.prenom,b.adresse,b.tel,b.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnew);
    fclose(file);
    remove("Bailleurs.txt");
    rename("BailleursNew.txt","Bailleurs.txt");

    FILE* fnewe=fopen("LocationNew.txt","a");
    file=fopen("Location.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,&l.prix,b.CNI)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%s %s %s %d %s\n",l.libe,l.adresse,l.type,l.prix,b.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("Location.txt");
    rename("locationNew.txt","Location.txt");
}

void effectuerPaiement(FILE*file,int position){
int cpt=0,cp=0,m;
client cl;
    FILE* fnew=fopen("ClientsNew.txt","a");
    file=fopen("Clients.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,&cl.tel,cl.CNI)!=EOF){
                cpt++;
            if(cpt!=position){
                fprintf(fnew,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,cl.tel,cl.CNI);
            }else{
                printf("Entrer le montant a paye :");
                scanf("%d",&m);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnew);
    fclose(file);
    remove("Clients.txt");
    rename("ClientsNew.txt","Clients.txt");
}
void supprimerClients(FILE *file, int position){
int cpt=0,cp=0;
client cl;
  contrat co;
    FILE* fnew=fopen("ClientsNew.txt","a");
    file=fopen("Clients.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,&cl.tel,cl.CNI)!=EOF){
                cpt++;
            if(cpt!=position){
                fprintf(fnew,"%s %s %s %d %s\n",cl.nom,cl.prenom,cl.email,cl.tel,cl.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnew);
    fclose(file);
    remove("Clients.txt");
    rename("ClientsNew.txt","Clients.txt");

    FILE* fnewe=fopen("ContratNew.txt","a");
    file=fopen("Contrat.txt","r");
    if(file!=NULL){
        while(fscanf(file,"%d %d %d %d %d %d %s %s\n",&co.j,&co.m,&co.a,&co.jj,&co.mm,&co.aa,co.modePaiement,cl.CNI)!=EOF){
                cp++;
            if(cp!=position){
                fprintf(fnewe,"%d %d %d %d %d %d %s %s\n",co.j,co.m,co.a,co.jj,co.mm,co.aa,co.modePaiement,cl.CNI);
            }
        }
    }else{
        printf("Erreur d'ouverture du fichier\n");
    }
    fclose(fnewe);
    fclose(file);
    remove("Contrat.txt");
    rename("ContratNew.txt","Contrat.txt");
}

