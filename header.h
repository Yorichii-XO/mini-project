
#ifndef HEADER_H
#define HEADER_H

typedef struct {
     int id;
    char name[90];
    char description[90];
    int priority;
    int dd,mm,yy;
    int completed;


} Task;

void ajouter_tache();

void Afficher();
void marq();
void deleteTaskByID(int id);
void modifyTaskByID(int id);
void filtre(int priority);
#endif
