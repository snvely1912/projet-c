#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lobat.h"


int generer_id(void *structures, int nb_structures, int taille_structure) {
    int dernier_id = 0;
    if (nb_structures > 0) {
        char *last_id = (char *)structures + (nb_structures-1)*taille_structure;
        dernier_id = atoi(last_id) + 1;
    }
    return dernier_id;
}

// Fonction pour ajouter un bailleur
void ajouter_bailleur(Bailleur *bailleurs, int *nb_bailleurs) {
    printf("Ajouter un bailleur :\n");
    printf("Nom : ");
    fgets(bailleurs[*nb_bailleurs].nom, 50, stdin);
    printf("Prénom : ");
    fgets(bailleurs[*nb_bailleurs].prenom, 50, stdin);
    printf("Adresse : ");
    fgets(bailleurs[*nb_bailleurs].adresse, 100, stdin);
    printf("Téléphone : ");
    fgets(bailleurs[*nb_bailleurs].tel, 20, stdin);
    printf("CIN : ");
    fgets(bailleurs[*nb_bailleurs].CIN, 20, stdin);
    sprintf(bailleurs[*nb_bailleurs].id, "%d", generer_id(bailleurs, *nb_bailleurs, sizeof(Bailleur)));
    (*nb_bailleurs)++;
    printf("Le bailleur a été ajouté avec succès (ID : %s).\n", bailleurs[*nb_bailleurs-1].id);

    // Écrire les informations dans le fichier bailleurs.txt
    FILE *fichier_bailleurs = fopen("bailleurs.txt", "a");
    if (fichier_bailleurs != NULL) {
        fprintf(fichier_bailleurs, "%s|%s|%s|%s|%s|%s\n", bailleurs[*nb_bailleurs-1].id, bailleurs[*nb_bailleurs-1].nom, bailleurs[*nb_bailleurs-1].prenom, bailleurs[*nb_bailleurs-1].adresse, bailleurs[*nb_bailleurs-1].tel, bailleurs[*nb_bailleurs-1].CIN);
        fclose(fichier_bailleurs);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier bailleurs.txt pour écrire les informations.\n");
    }
}

// Fonction pour ajouter une location
void ajouter_location(Location *locations, int *nb_locations) {
    printf("Ajouter une location :\n");
    printf("Libellé : ");
    fgets(locations[*nb_locations].libelle, 50, stdin);
    printf("Adresse : ");
    fgets(locations[*nb_locations].adresse, 100, stdin);
    printf("Type (maison, appartement, studio) : ");
    fgets(locations[*nb_locations].type, 20, stdin);
    printf("Prix : ");
    scanf("%f", &locations[*nb_locations].prix);
    getchar(); // consommer le caractère \n restant dans le buffer d'entrée
    printf("Date de début (JJ/MM/AAAA) : ");
    fgets(locations[*nb_locations].date_DEB, 20, stdin);
    printf("Date de fin (JJ/MM/AAAA) : ");
    fgets(locations[*nb_locations].date_FIN, 20, stdin);
    printf("Mode de paiement (CB, chèque, espèces) : ");
    fgets(locations[*nb_locations].modePaiement, 20, stdin);
    printf("ID du bailleur propriétaire : ");
    fgets(locations[*nb_locations].id_bailleur, 10, stdin);
    sprintf(locations[*nb_locations].id, "%d", generer_id(locations, *nb_locations, sizeof(Location)));
    (*nb_locations)++;
    printf("La location a été ajoutée avec succès (ID : %s).\n", locations[*nb_locations-1].id);

    // Écrire les informations dans le fichier locations.txt
    FILE *fichier_locations = fopen("locations.txt", "a");
    if (fichier_locations != NULL) {
        fprintf(fichier_locations, "%s|%s|%s|%s|%.2f|%s|%s|%s|%s\n", locations[*nb_locations-1].id, locations[*nb_locations-1].libelle, locations[*nb_locations-1].adresse, locations[*nb_locations-1].type, locations[*nb_locations-1].prix, locations[*nb_locations-1].date_DEB, locations[*nb_locations-1].date_FIN, locations[*nb_locations-1].modePaiement, locations[*nb_locations-1].id_bailleur);
        fclose(fichier_locations);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier locations.txt pour écrire les informations.\n");
    }
}

// Fonction pour ajouter un client
void ajouter_client(Client *clients, int *nb_clients) {
    printf("Ajouter un client :\n");
    printf("Nom : ");
    fgets(clients[*nb_clients].nom, 50, stdin);
    printf("Prénom : ");
    fgets(clients[*nb_clients].prenom, 50, stdin);
    printf("Téléphone : ");
    fgets(clients[*nb_clients].tel, 20, stdin);
    printf("Email : ");
    fgets(clients[*nb_clients].email, 100, stdin);
    printf("CIN : ");
    fgets(clients[*nb_clients].CIN, 20, stdin);
    sprintf(clients[*nb_clients].id, "%d", generer_id(clients, *nb_clients, sizeof(Client)));
    (*nb_clients)++;
    printf("Le client a été ajouté avec succès (ID : %s).\n", clients[*nb_clients-1].id);

    // Écrire les informations dans le fichier clients.txt
    FILE *fichier_clients = fopen("clients.txt", "a");
    if (fichier_clients != NULL) {
        fprintf(fichier_clients, "%s|%s|%s|%s|%s\n", clients[*nb_clients-1].id, clients[*nb_clients-1].nom, clients[*nb_clients-1].prenom, clients[*nb_clients-1].tel, clients[*nb_clients-1].email, clients[*nb_clients-1].CIN);
        fclose(fichier_clients);
    } else {
        printf("Erreur : impossible d'ouvrir le fichier clients.txt pour écrire les informations.\n");
    }
}

// Fonction pour enregistrer un paiement
void enregistrer_paiement(Paiement *paiements, int *nb_paiements) {
    printf("Enregistrer un paiement :\n");
    printf("ID de la location : ");
    fgets(paiements[*nb_paiements].id_location, 10, stdin);
    printf("Montant : ");
    scanf("%f", &paiements[*nb_paiements].montant);
getchar(); // consommer le caractère \n restant dans le buffer d'entrée
printf("Date (JJ/MM/AAAA) : ");
fgets(paiements[*nb_paiements].date, 20, stdin);
sprintf(paiements[*nb_paiements].id, "%d", generer_id(paiements, *nb_paiements, sizeof(Paiement)));
(*nb_paiements)++;
printf("Le paiement a été enregistré avec succès (ID : %s).\n", paiements[*nb_paiements-1].id);
// Écrire les informations dans le fichier contrats.txt
FILE *fichier_contrats = fopen("contrats.txt", "a");
if (fichier_contrats != NULL) {
    fprintf(fichier_contrats, "%s|%s|%.2f|%s\n", paiements[*nb_paiements-1].id, paiements[*nb_paiements-1].id_location, paiements[*nb_paiements-1].montant, paiements[*nb_paiements-1].date);
    fclose(fichier_contrats);
} else {
    printf("Erreur : impossible d'ouvrir le fichier contrats.txt pour écrire les informations.\n");
}
// Fonction pour afficher les informations d'un bailleur
void afficher_bailleur(Bailleur bailleur) {
printf("ID : %s\n", bailleur.id);
printf("Nom : %s", bailleur.nom);
printf("Prénom : %s", bailleur.prenom);
printf("Adresse : %s", bailleur.adresse);
printf("Téléphone : %s", bailleur.tel);
printf("CIN : %s", bailleur.CIN);
}

// Fonction pour afficher les informations d'une location
void afficher_location(Location location) {
printf("ID : %s\n", location.id);
printf("Libellé : %s", location.libelle);
printf("Adresse : %s", location.adresse);
printf("Type : %s", location.type);
printf("Prix : %.2f\n", location.prix);
printf("Date de début : %s", location.date_DEB);
printf("Date de fin : %s", location.date_FIN);
printf("Mode de paiement : %s", location.modePaiement);
printf("ID bailleur propriétaire : %s\n", location.id_bailleur);
printf("ID client : %s\n", location.id_client);
}

// Fonction pour afficher les informations d'un client
void afficher_client(Client client) {
printf("ID : %s\n", client.id);
printf("Nom : %s", client.nom);
printf("Prénom : %s", client.prenom);
printf("Téléphone : %s", client.tel);
printf("Email : %s", client.email);
printf("CIN : %s", client.CIN);
}

// Fonction pour afficher les informations d'un paiement
void afficher_paiement(Paiement paiement) {
printf("ID : %s\n", paiement.id);
printf("ID de la location : %s\n", paiement.id_location);
printf("Montant : %.2f\n", paiement.montant);
printf("Date : %s", paiement.date);
}

int main() {
Bailleur bailleurs[100];
int nb_bailleurs = 0;
Location locations[100];
int nb_locations = 0;
Client clients[100];
int nb_clients = 0;
Paiement paiements[100];
int nb_paiements = 0;
FILE *fichier_bailleurs = fopen("bailleurs.txt", "r");
if (fichier_bailleurs != NULL) {
    char ligne[256];
    while (fgets(ligne, 256, fichier_bailleurs) != NULL) {
        Bailleur bailleur;
        sscanf(ligne, "%9[^|]|%49[^|]|%49[^|]|%99[^|]|%19[^|]|%19s\n", bailleur.id, bailleur.nom, bailleur.prenom, bailleur.adresse, bailleur.tel, bailleur.CIN);
        bailleurs[nb_bailleurs] = bailleur;
        nb_bailleurs++;
    }
    fclose(fichier_bailleurs);
}

FILE *fichier_locations = fopen("locations.txt", "r");
if (fichier_locations != NULL) {
    char ligne[256];
    while (fgets(ligne, 256, fichier_locations) != NULL) {
        Location location;
        sscanf(ligne, "%9[^|]|%99[^|]|%99[^|]|%19[^|]|%f|%19[^|]|%19[^|]|%19[^|]|%9[^|]|%9s\n", location.id, location.libelle, location.adresse, location.type, &location.prix, location.date_DEB, location.date_FIN, location.modePaiement, location.id_bailleur, location.id_client);
        locations[nb_locations] = location;
        nb_locations++;
    }
    fclose(fichier_locations);
}

// Lire les informations des clients à partir du fichier clients.txt
FILE *fichier_clients = fopen("clients.txt", "r");
if (fichier_clients != NULL) {
    char ligne[256];
    while (fgets(ligne, 256, fichier_clients) != NULL) {
        Client client;
        sscanf(ligne, "%9[^|]|%49[^|]|%49[^|]|%19[^|]|%49[^|]|%19s\n", client.id, client.nom, client.prenom, client.tel, client.email, client.CIN);
        clients[nb_clients] = client;
        nb_clients++;
    }
    fclose(fichier_clients);
}

FILE *fichier_contrats = fopen("contrats.txt", "r");
if (fichier_contrats != NULL) {
    char ligne[256];
    while (fgets(ligne, 256, fichier_contrats) != NULL) {
        Paiement paiement;
        sscanf(ligne, "%9[^|]|%9[^|]|%f|%19[^|]\n", paiement.id, paiement.id_location, &paiement.montant, paiement.date);
        paiements[nb_paiements] = paiement;
        nb_paiements++;
    }
    fclose(fichier_contrats);
}




