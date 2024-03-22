#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Task *tasks = NULL;
int num_tasks = 0;
int next_id = 1;

void ajouter_tache() {
    if (tasks == NULL) {

        tasks = (Task *)malloc(sizeof(Task));
    } else {

        tasks = (Task *)realloc(tasks, (num_tasks + 1) * sizeof(Task));
    }
    printf("Nom de la tache:");
    scanf("%s", tasks[num_tasks].name);

    printf("Description de la tache: ");
    scanf("%s", tasks[num_tasks].description);

    printf("Priorite de la tache (1 - Faible, 2 - Moyenne, 3 - Haute): ");
    scanf("%d", &tasks[num_tasks].priority);
    //Error handling for priority of task
    if(tasks[num_tasks].priority>3){
              printf("Invalide\n");
            while(tasks[num_tasks].priority>3){
               printf("Priorite de la tache (1 - Faible, 2 - Moyenne, 3 - Haute): ");
    scanf("%d", &tasks[num_tasks].priority);
            }
    }
    printf("Date d'echeance de la tache (format dd/mm/yy): ");
    scanf("%d/%d/%d", &tasks[num_tasks].dd, &tasks[num_tasks].mm, &tasks[num_tasks].yy);

    printf("marque si la tâche 1 est terminée ou 0 non terminee: ");
    scanf("%d", &tasks[num_tasks].completed);
    //Error handling for checking task
    if(tasks[num_tasks].completed> 1 ){
        printf("Invalide\n");
    while(tasks[num_tasks].completed>1){
    printf("marque si la tâche 1 est terminée ou 0 non terminee: ");
    scanf("%d", &tasks[num_tasks].completed);
    }}
    tasks[num_tasks].id = next_id++;
    num_tasks++;
    printf("La tache a ete ajoutee avec succes.\n");

}

void Afficher() {
      printf("L'affichage des tâches :\n");

    for (int i = 0; i < num_tasks; i++) {
        printf(" ID: %d, Name: %s, Description: %s, Priorite: %d, Date d'echeance: %d/%d/%d, Statut: %d\n",
            tasks[i].id, tasks[i].name, tasks[i].description,
               tasks[i].priority, tasks[i].dd, tasks[i].mm, tasks[i].yy,
               tasks[i].completed );
    }
}

void marq() {
    printf("L'affichage des tâches pour marquer :\n");
    printf("ID  Name  Description  Priority DateE Status\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d  %s  %s  %d  %d/%d/%d  %s\n",
               tasks[i].id, tasks[i].name, tasks[i].description,
               tasks[i].priority, tasks[i].dd, tasks[i].mm, tasks[i].yy,
               tasks[i].completed ? "Terminee" : "Non terminee");
    }

    int task_id;
    printf("Entrez l'ID de la tâche à marquer : ");
    scanf("%d", &task_id);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            printf("Marquer la tâche %d comme terminée (1): ", task_id);
            scanf("%d", &tasks[i].completed);
            printf("Statut de la tâche %d mis à jour.\n", task_id);
            return;
        }
    }
    printf("Tâche avec l'ID %d non trouvée.\n", task_id);
}

void modifyTaskByID(int id) {
    int found = 0;// qui rechercher
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == id) {
            printf("Enter new information for the task:\n");
            printf("Name: ");
            scanf("%s", &tasks[i].name);
             printf("Description: ");
            scanf("%s", &tasks[i].description);
             printf("Priority: ");
            scanf("%d", &tasks[i].priority);
             printf("Date d'echeance (format dd/mm/yy): ");
        scanf("%d/%d/%d", &tasks[i].dd, &tasks[i].mm, &tasks[i].yy);
             printf("tache términee: ");
            scanf("%d", &tasks[i].completed);
            printf("Task modified successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Task with ID %d not found.\n", id);
    }
}

void deleteTaskByID(int id) {
    int found = 0;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            num_tasks--;
            printf("Task with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Task with ID %d not found.\n", id);
    }
}
void filtre(int priority) {
    int found = 0;
    printf("ID  Name  Description  Priority DateE Status\n");

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].priority == priority) {
            printf("%d %s %s %d %d/%d/%d %d\n", tasks[i].id, tasks[i].name, tasks[i].description,
                   tasks[i].priority, tasks[i].dd, tasks[i].mm, tasks[i].yy,
                   tasks[i].completed);
            found = 1;
        }
    }

    if (!found) {
        printf("No tasks found with priority %d.\n", priority);
    }
}


