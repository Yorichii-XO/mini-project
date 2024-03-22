#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_TASKS 100

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    int op;
int displaymenu=1;
    while (1) {
            if(displaymenu){
        printf("######## Menu ########## \n");
        printf("1. Ajouter une tache\n");
        printf("2. Modifier une tache\n");
        printf("3. Supprimer une tache\n");
        printf("4. Filtrer les taches par priorité ou par date d'echeance\n");
        printf("5. Afficher de maniere organisée toutes les taches ajoutées\n");
        printf("6. Marquer une tache comme terminee\n");
        printf("0. Quitter\n");
        }
        printf("Entrez votre choix : ");

        scanf("%d", &op);

        switch (op) {
            case 1:
                ajouter_tache(tasks, &num_tasks);
                displaymenu=1;
                break;
            case 2:{
                 int id;
                    printf("Entrez l'ID de la tâche à modifier : ");
                    scanf("%d", &id);
                    modifyTaskByID(id);
                }
                 displaymenu=0;

                break;
            case 3:
                {
                    int id;
                    printf("Entrez l'ID de la tâche à supprimer : ");
                    scanf("%d", &id);
                    deleteTaskByID(id);
                }
                 displaymenu=0;
                break;

            case 4:
                {
                    int priority;
                    printf("Entrez la prioriter: ");
                    scanf("%d", &priority);
                    filtre(priority);
                }

                break;

            case 5:
                Afficher();
                displaymenu=1;
                break;
            case 6:
                 marq();
                 displaymenu=0;
                break;
            case 0:
                printf("Programme termine.\n");
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}
