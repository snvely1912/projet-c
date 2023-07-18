#include <stdio.h>
#include <stdlib.h>
#include "lobat.h"
int main()
{
    int choix,pos,chx,repo,bo,b,d,rep,locat;
    char login;
    FILE* f;
    printf("Bienvenue dans l'application Lobat Nous sommes ravis de vous accueillir dans notre application.!\n ");
    printf("Lobat est la pour vous aider a gerer efficacement vos locations immobilieres, simplifier les procedures de gestion et ameliorer votre experience en tant que bailleur, gestionnaire ou client.\n");
    printf("________________________________________________________________________________________________________________________\n");
    printf(" 1-Je suis administrateur\n");
    printf(" 2-Je suis gestionnaire\n");
    do{
        printf("Entrer votre reponse:");
        scanf("%d",&chx);
        if(chx<1 || chx>2){
            printf("Reponse invalide!Veuillez resaisir!\n");
        }
    }while(chx<1 || chx>2);
     system("cls");
    if(chx==1){
        printf("1-Se connecter\n");
        printf("2-Creer un compte\n");
        do{
            printf("Entrer votre reponse:");
            scanf("%d",&b);
        }while(b<1 || b>2);
        if(b==1){
           DemandeconnexionLobat();
           rechercheAdministrateur(f);
           system("pause");
                do{
               system("cls") ;
                choix= menu();
                    switch(choix){
                        case 1:
                            AjouterBailleurAuFichier(f,infoLocation(),creerBailleur());
                            break;
                        case 2:
                            consulterBailleurs(f);
                            break;
                        case 3:
                            consulterBailleurs(f);
                            printf("Saisir la position a modifier:");
                            scanf("%d",&pos);
                            modifierInfo(f,pos,infoLocation(),creerBailleur());
                        break;
                        case 4:
                            consulterBailleurs(f);
                            printf("Saisir la position a supprimer:");
                            scanf("%d",&pos);
                            supprimerInfo(f,pos);
                        break;
                        case 5:
                                DemandeinscriptionLobat();
                                AjouterGestionnaire(f);
                            break;
                        case 6:
                            consulterGestion(f);
                            break;
                        case 7:
                            consulterGestion(f);
                            printf("Saisir la position du gestionnaire a modifier:");
                            scanf("%d",&pos);
                            modifierGestion(f,pos);
                            AjouterGestionnaire(f);
                        break;
                         case 8:
                                    printf("Voici la liste des locations disponibles!\n");
                                    printf("-----------------------------------------\n");
                                    consulterLocation(f);
                                break;
                            case 9:
                                    printf("Saisir le type de location que vous souhaitez chercher:");
                                    scanf("%s",&locat);
                                    ChercherLocation(f,locat);
                            break;
                            case 10:
                                    printf("Saisir le login que vous souhaitez chercher:");
                                    scanf("%s",&login);
                                    ChercherGestion(f,login);
                            break;
                    default:
                        printf("Vous vous etes deconnecter de  l application!!\n");
                        printf("----------------------------------------------\n");
                    }

            }while(choix!=11);
        }else{
            DemandeinscriptionLobat();
            AjouterAdministrateur(f);
            system("cls");
            DemandeconnexionLobat();
           rechercheAdministrateur(f);
            system("pause");
                 do{
               system("cls") ;
                choix= menu();
                    switch(choix){
                        case 1:
                            AjouterBailleurAuFichier(f,infoLocation(),creerBailleur());
                            break;
                        case 2:
                            consulterBailleurs(f);
                            break;
                        case 3:
                            consulterBailleurs(f);
                            printf("Saisir la position a modifier:");
                            scanf("%d",&pos);
                            modifierInfo(f,pos,infoLocation(),creerBailleur());
                        break;
                        case 4:
                            consulterBailleurs(f);
                            printf("Saisir la position a supprimer:");
                            scanf("%d",&pos);
                            supprimerInfo(f,pos);
                        break;
                        case 5:
                                DemandeinscriptionLobat();
                                AjouterGestionnaire(f);
                            break;
                        case 6:
                            consulterGestion(f);
                            break;
                        case 7:
                            consulterGestion(f);
                            printf("Saisir la position du gestionnaire a modifier:");
                            scanf("%d",&pos);
                            modifierGestion(f,pos);
                            AjouterGestionnaire(f);
                        break;
                         case 8:
                                    printf("Voici la liste des locations disponibles!\n");
                                    printf("-----------------------------------------\n");
                                    consulterLocation(f);
                                break;
                            case 9:
                                    printf("Saisir le type de location que vous souhaitez chercher:");
                                    scanf("%s",&locat);
                                    ChercherLocation(f,locat);
                            break;
                            case 10:
                                    printf("Saisir le login que vous souhaitez chercher:");
                                    scanf("%s",&login);
                                    ChercherGestion(f,login);
                            break;
                    default:
                        printf("Vous vous etes deconnecter de  l application!!\n");
                        printf("----------------------------------------------\n");
                    }
            }while(choix!=11);
        }
    }else if(chx==2){
               DemandeconnexionLobat();
              rechercheGestionnaire(f);
               system("pause");
                do{
                   system("cls") ;
                    repo= menu1();
                        switch(repo){
                            case 1:
                                AjouterClientAuFichier(f,infoContrat(),creerClient());
                                break;
                            case 2:
                                consulterClient(f);
                                break;
                            case 3:
                                consulterClient(f);
                                printf("Saisir la position a modifier:");
                                scanf("%d",&pos);

                            break;
                            case 4:
                                consulterClient(f);
                                printf("Saisir la position a modifier:");
                                scanf("%d",&pos);
                                supprimerClients(f,pos);
                            break;
                            case 5:
                                consulterClient(f);
                                printf("Saisir la position a valider le paiement:");
                                scanf("%d",&pos);
                                effectuerPaiement(f,pos);
                                printf(" Paiement valider avec succes!\n");
                                printf("------------------------------\n");
                                AjouterPaiement(f);
                            break;
                            default:
                            printf("Vous vous etes deconnecter de l application!\n");
                            printf("----------------------------------------------\n");
                        }

                }while(repo!=6);
    }
    return 0;
}
