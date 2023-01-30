#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"
#include <stdbool.h>

void addElement(listElement *start, listElement *newElement) {
    listElement *currElem = start;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = newElement;          // add new to the end of list
    newElement->nextElem = NULL;
}

void addListElem(listElement *start) {
    listElement *new;
    new = (listElement *) malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n");
        return;
    }

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &(new->age));

    addElement(start, new);
}

void printList(listElement *start) {

    if (start->nextElem == NULL)
        printf("List is empty.\n");
    else {
        int i = 0;
        listElement *currElem = start;
        printf("\ncurrent list:\n\n");
        do {
            currElem = currElem->nextElem;
            printf("%d", i);
            printf("\t last name: %s\n", currElem->lastName);
            printf("\t first name: %s\n", currElem->firstName);
            printf("\t age: %d\n", currElem->age);
            i++;
        } while (currElem->nextElem != NULL);
    }
}

bool doesIndexExist(listElement *start, int index) {
    return index < getLenOfList(start) && index > 0;
}

listElement *findElementByID(listElement *start, int index) {
    listElement *currElem = start;
    for (int i = 0; i <= index; ++i) {
        currElem = currElem->nextElem;
    }
    return currElem;
}

void delListElem(listElement *start) {
    if (start->nextElem == NULL) {
        printf("There is nothing to delete from :(\n");
        return;
    }

    printList(start);

    int indexToDel;
    printf("Enter the index of the element you want to delete: \n");
    scanf("%d", &indexToDel);

    if (!doesIndexExist(start, indexToDel)) {
        printf("The element doesnt exist :C Try another one\n");
        return;
    }

    listElement *previousElement = findElementByID(start, indexToDel - 1);
    listElement *toDelElement = findElementByID(start, indexToDel);
    listElement *nextElement = findElementByID(start, indexToDel + 1);

    previousElement->nextElem = nextElement;
    free(toDelElement);

    printf("Index %d was deleted from the list\n", indexToDel);
}

void delList(listElement *start) {
    if (start->nextElem == NULL) {
        printf("List is already empty :)\n");
        return;
    }

    listElement *currElem = start->nextElem;
    while (currElem->nextElem != NULL) {
        listElement *toFree = currElem;
        currElem = currElem->nextElem;

        free(toFree);
    }

    start->nextElem = NULL;

    printf("List was cleared\n");
}

int getLenOfList(listElement *start) {
    int counter = 0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL) { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void writeFile(char filename[], listElement *currElem) {
    FILE *fPtr;

    fPtr = fopen(filename, "a");
    if (fPtr == NULL) {
        printf("Could not open file");
    }

    fprintf(fPtr, "%s %s %d\n", currElem->lastName, currElem->firstName, currElem->age);

    fclose(fPtr);
}

void saveList(listElement *start) {
    if (start->nextElem == NULL) {
        printf("There nothing to save :(\n");
        return;
    }

    char filename[100];

    printf("In what file should the list be saved? (suffix with .txt please): \n");
    scanf("%s", filename);

    remove(filename); // delete an eventual old file.

    listElement *currElem = start;
    do {
        currElem = currElem->nextElem;
        writeFile(filename, currElem);
    } while (currElem->nextElem != NULL);

    printf("List saved in file: %s\n", filename);
}

void loadList(listElement *start) {
    printf("Choose a savefile from the list: \n");
    system("dir *.txt");

    char filename[100];
    scanf("%s", filename);

    FILE *fPtr;

    fPtr = fopen(filename, "r");
    if (fPtr == NULL) {
        printf("Could not open file\n");
        return;
    }

    while (!feof(fPtr)) {
        listElement *new;
        new = (listElement *) malloc(sizeof(listElement));
        if (new == NULL) {
            printf("can't reserve storage.\n");
            return;
        }

        fscanf(fPtr, "%s %s %d\n", new->lastName, new->firstName, &(new->age));
        addElement(start, new);
    }

    fclose(fPtr);

    printf("loading data will be append to current list...\nNew current list: \n");
    printList(start); // show loaded list
}

void exitFcn(listElement *start) {
    if (start->nextElem == NULL) // list is empty so dont ask for save
        return;

    int save;
    printf("Do you want to save your current file? (0/1): \n");
    scanf("%d", &save);

    if (save == 0) {
        printf("no saving.. have a good day ;)");
        exit(0);
    }

    saveList(start);
}

void sortList(listElement *start) {
    printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char *string) {
    printf("\n>>stringToLower fcn is tbd.\n\n");
}