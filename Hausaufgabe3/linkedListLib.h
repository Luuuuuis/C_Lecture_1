#ifndef HA03_LINKEDLISTLIB_H_
#define HA03_LINKEDLISTLIB_H_

struct listElem{
    char lastName[50];
    char firstName[50];
    int age;
    struct listElem *nextElem;
};
typedef struct listElem listElement;

int scanForNumericInput();

void createNewElement(listElement *);

void printList(listElement *);

void delListElem(listElement *);

void delList(listElement *);

int getLenOfList(listElement *);

void saveList(listElement *);

void loadList(listElement *);

void exitFcn(listElement *);

void sortList(listElement *);

void stringToLower(char *);

#endif