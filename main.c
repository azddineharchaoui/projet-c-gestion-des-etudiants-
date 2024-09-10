#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MAX_ETUDIANT 200

typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

typedef enum {INFORMATIQUE, MATHEMATIQUES, PHYSIQUE, CHIMIE}Departement;

typedef struct {
    int id;
    char nom[MAX];
    char prenom[MAX];
    Date date_naissance;
    Departement departement;
    float note;
}Etudiant;

int count =0;
Etudiant classe[MAX_ETUDIANT];

void ajouterEtudiant(){
    if(count >= MAX_ETUDIANT){ printf("Il n'y a pas de places vides\n");}
    else{
        classe[count].id = count+1;
        printf("Entrer le nom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].nom);
        printf("Entrer le prenom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].prenom);
        printf("Entrer la date de naissance (jour mois annee)");
        scanf("%d %d %d", &classe[count].date_naissance.jour, &classe[count].date_naissance.mois, &classe[count].date_naissance.annee );
        printf("Entrer la departement : \n0- INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
        scanf("%d", &classe[count].departement);
        printf("Entrer la note generale de l'etudiant\n");
        scanf("%f", &classe[count].note);
        count++;
    }
}

void modifierEtudiant(){
    int id;
    printf("Entrez l'id de l'etudiant que vous voulez modifier\n");
    scanf("%d", &id);
    for(int i=0; i<count ; i++){
        if(classe[i].id == id){
            printf("Entrer le nouveau nom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].nom);
            printf("Entrer le nouveau prenom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].prenom);
            printf("Entrer la nouvelle date de naissance (jour mois annee)");
            scanf("%d %d %d", &classe[i].date_naissance.jour, &classe[i].date_naissance.mois, &classe[i].date_naissance.annee );
            printf("Entrer la nouvelle departement : \n0-INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
            scanf("%d", &classe[i].departement);
            printf("Entrer la nouvelle note generale de l'etudiant\n");
            scanf("%f", &classe[i].note);
            printf("Les infos de l'etudiant ont ete modifie avec succes\n");
            return ;
        }
    }
    printf("Il n'y a pas d'etudiant avec cet id \n");
}

void supprimerEtudiant(){
    int id;
    printf("Entrer l'id de l'etudiant que vous voulez supprimer\n");
    scanf("%d",&id);
    if(id>count){
        printf("Il n'y a pas d'etudiant avec cet id \n");
        return ;
    }else {
        for(int i = id; i< count -1; i++){
            classe[i]=classe[i+1];
        }
        count--;
        printf("l'etudiant a ete supprime avec succes\n");
    }
}
char *departement(Departement d ){
    char * str = malloc(20*sizeof(char));
    switch(d){
    case 0 :
        strcpy(str, "Informatique");
        break;
    case 1:
        strcpy(str, "Mathematiques");
        break;
    case 2:
        strcpy(str, "Physique");
        break;
    case 3:
        strcpy(str, "Chimie");
        break;
    default:
        break;
    }
    return str;
}
void afficherEtudiants() {
    if (count == 0) {
        printf("La liste des etudiants est vide\n");
    } else {
        printf("%-3s | %-12s | %-12s | %-12s | %-12s | %s\n",
               "ID", "Nom", "Prenom", "Date de Naissance", "Departement", "Note Generale");
        printf("-----+-------------+-------------+--------------+-------------+------------\n");

        for (int i = 0; i < count; i++) {
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
        }
    }
}

void rechercherEtudiant(){
    char  str[30];
    printf("entrer le nom de l'etudiant que vous recherchez\n");
    scanf("%s", &str);
    for(int i=0; i<count ; i++){
        if(!strcmp(str, classe[i].nom)){
            printf("%d | %s | %s | %d/%d/%d | %s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
                   return ;
        }
    }
    printf("Il n'y a pas d'etudiant correspondant au nom que vous avez entre\n");
}

void afficherDepartement(){
    int dep;
    if(count ==0){
        printf("La liste des etudiants est vide \n");
    }else{
        printf("Entrer la departement que vous voulez afficher \n");
        printf("(0)-INFORMATIQUE.\n(1)-MATHEMATIQUES.\n(2)-PHYSIQUE.\n(3)-CHIMIE\n");
        scanf("%d", &dep);
        if(dep>3){
            printf("Cette departement n'existe pas \n");
            return ;
        }else{
        printf("id | nom | prenom | date de naissance | Departement | note generale\n");
        for(int i=0; i<count; i++){
            if(dep==classe[i].departement){
                printf("%d | %s | %s | %d/%d/%d | %s | %.2f\n",
                    classe[i].id, classe[i].nom, classe[i].prenom,
                    classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                    classe[i].date_naissance.annee, departement(classe[i].departement),
                    classe[i].note);
                }
            }
        }
    }
}

void claculMoyenne(){

}

int main(){
    int choix ;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter un etudiant a l'universite\n");
        printf("2- Modifier un etudiant\n");
        printf("3- Supprimer un etudiant\n");
        printf("4- Afficher tous les etudiants\n");
        printf("5- Rechercher un etudiant\n");
        printf("6- Afficher les etudiants d'une departement\n");
        printf("7- Calculer la moyenne generale\n");
        printf("8- Afficher les statistiques\n");
        printf("9- Trier les etudiants \n");
        printf("0- Quitter \n");
        printf("\n Votre choix \n\n");
        scanf("%d", &choix);
        switch(choix){
            case 1: ajouterEtudiant();
                break;
            case 2: modifierEtudiant();
                break;
            case 3: supprimerEtudiant();
                break ;
            case 4: afficherEtudiants();
                break ;
            case 5: rechercherEtudiant();
                break;
            case 6: afficherDepartement();
                break;
            case 7: claculMoyenne();
                break;
            case 8:
                break;
            case 9:
                break;

            default:
                break ;
        }
    }while(choix!=0);
    return 0;
}

