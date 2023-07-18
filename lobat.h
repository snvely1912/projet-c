#ifndef LOBAT_H_INCLUDED
#define LOBAT_H_INCLUDED
#include<stdio.h>

typedef struct{
    char nom[15],prenom[30],adresse[30],CNI[17],id[20];
    int tel;
}bailleur;
typedef struct{
    char libe[20],adresse[30],type[20];
    int prix;
}location;
typedef struct{
    char nom[15],prenom[30],email[30],CNI[17],id[20];
    int tel;
}client;
typedef struct{
    int j,m,a,jj,mm,aa;
    char modePaiement[20];
}contrat;
typedef struct{
    char login[20],password[20],pass[20],nom[20],prenom[20],email[20];
}Inscription;
typedef struct{
    char login[20],password[20];
}connexion;
void DemandeconnexionLobat();
void DemandeinscriptionLobat();
void AjouterUtilisateur(FILE *file);
void rechercheUser(FILE *file);
void  AjouterBailleurAuFichier(FILE *file,location l, bailleur b);
void  AjouterClientAuFichier(FILE *file,contrat co,client cl);
void AfficherBailleur(bailleur b);
void AfficherLocation(location l,bailleur b);
void AjouterGestionnaire(FILE *file);
void rechercheAdministrateur(FILE *file);
void effectuerPaiement(FILE*file,int position);
void AjouterAdministrateur(FILE *file);
void AfficherClients(client cl);
void AfficherContrat(contrat co,client cl);
void rechercheGestionnaire(FILE *file);
void consulterGestion(FILE *file);
void  AfficherGestion();
void AjouterPaiement(FILE *file);
void modifierGestion(FILE *file,int position);
void supprimerGestion(FILE *file,int position);
bailleur creerBailleur();
location infoLocation();
client creerClient();
contrat infoContrat();
void consulterBailleurs(FILE *file);
void consulterLocation(FILE *file);
void consulterContrat(FILE *file);
void consulterContrat(FILE *file);
int menu();
int menu1();
int menu2();
void ChercherGestion(FILE *file,char login);
void ChercherLocation(FILE *file,char locat);
void choisirLocation(FILE *file,int position);
void modifierInfo(FILE *file,int position,location lo, bailleur ba);
void supprimerInfo(FILE *file, int position);
void supprimerClients(FILE *file, int position);



#endif // LOBAT_H_INCLUDED
