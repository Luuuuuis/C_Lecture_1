#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"
#include <stdbool.h>

bool isLastElement(listElement *listElement) {
    return listElement->nextElem == NULL;
}

int scanForNumericInput() {
    int value;

    while (scanf("%d", &value) != 1) {
        printf("Invalid input... Please input an integer.\nTry again: \n");
        fflush(stdin); // flush any leftover characters in the stdin
    }

    return value;
}

void addElement(listElement *start, listElement *newElement) {
    listElement *currElem = start;
    while (!isLastElement(currElem)) // get last elem in list
        currElem = currElem->nextElem;

    currElem->nextElem = newElement; // add new to the end of list
    newElement->nextElem = NULL;
}

void createNewElement(listElement *start) {
    listElement *new = (listElement *) malloc(sizeof(listElement));
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
    new->age = scanForNumericInput();

    addElement(start, new);
}

void printList(listElement *start) {
    if (isLastElement(start)) {
        printf("List is empty.\n");
        return;
    }

    listElement *currElem = start;
    printf("\ncurrent list:\n\n");

    int i = 0;
    while (!isLastElement(currElem)) {
        currElem = currElem->nextElem;
        printf("%d", i);
        printf("\tlast name: %s\n", currElem->lastName);
        printf("\tfirst name: %s\n", currElem->firstName);
        printf("\tage: %d\n", currElem->age);
        i++;
    }
}

bool doesIndexExist(listElement *start, int index) {
    return index < getLenOfList(start) && index >= 0;
}

listElement *findElementByIndex(listElement *start, int index) {
    listElement *currElem = start;
    for (int i = 0; i <= index; ++i) {
        currElem = currElem->nextElem;
    }
    return currElem;
}

void delListElem(listElement *start) {
    if (isLastElement(start)) {
        printf("There is nothing to delete from :(\n");
        return;
    }

    printList(start);

    printf("Enter the index of the element you want to delete: \n");
    int indexToDelete = scanForNumericInput();

    if (!doesIndexExist(start, indexToDelete)) {
        printf("The element doesnt exist in the list :C\n");
        return;
    }

    listElement *previousElement = findElementByIndex(start, indexToDelete - 1);
    listElement *toDeleteElement = findElementByIndex(start, indexToDelete);
    listElement *nextElement = findElementByIndex(start, indexToDelete + 1);

    previousElement->nextElem = nextElement;
    free(toDeleteElement);

    printf("Index %d was deleted from the list\n", indexToDelete);
}

void delList(listElement *start) {
    if (isLastElement(start)) {
        printf("List is already empty :)\n");
        return;
    }

    listElement *currElem = start->nextElem;
    while (!isLastElement(currElem)) {
        listElement *toFree = currElem; //to avoid the edge case that the freed memory is already used elsewhere in the small timeframe
        currElem = currElem->nextElem;

        free(toFree);
    }

    start->nextElem = NULL;

    printf("List was cleared\n");
}

int getLenOfList(listElement *start) {
    int counter = 0;
    listElement *currElem = start;

    while (!isLastElement(currElem)) {
        currElem = currElem->nextElem;
        counter++;
    }

    return counter;
}

void writeElementToFile(char filename[], listElement *currElem) {
    FILE *fPtr;

    fPtr = fopen(filename, "a");
    if (fPtr == NULL) {
        printf("Could not open file\n");
        return;
    }

    fprintf(fPtr, "%s %s %d\n", currElem->lastName, currElem->firstName, currElem->age);

    fclose(fPtr);
}

void saveList(listElement *start) {
    if (isLastElement(start)) {
        printf("There nothing to save :(\n");
        return;
    }

    char filename[100];

    printf("In what file should the list be save? (suffix with .txt please): \n");
    scanf("%s", filename);

    remove(filename); // delete an eventual old file.

    listElement *currElem = start;
    while (!isLastElement(currElem)) {
        currElem = currElem->nextElem;
        writeElementToFile(filename, currElem);
    }

    printf("List saved in file: %s\n", filename);
}

void loadList(listElement *start) {
    printf("Choose a save file from the list and type the name: \n");
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
        listElement *new = (listElement *) malloc(sizeof(listElement));
        if (new == NULL) {
            printf("can't reserve storage.\n");
            return;
        }

        fscanf(fPtr, "%s %s %d\n", new->lastName, new->firstName, &(new->age));
        addElement(start, new);
    }

    fclose(fPtr);

    printf("loading data will be appended to current list...\nNew current list: \n");
    printList(start);
}

void exitFcn(listElement *start) {
    if (isLastElement(start)) // list is empty so dont ask for save
        return;

    printf("Do you want to save your current file? (0/1): \n");
    int decision = scanForNumericInput();

    if (decision == 0) {
        printf("no saving.. have a good day :)");
        return;
    }

    saveList(start);
}

int getRandomNumberInRange(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

bool numberExistsInArray(int array[], int number) {
    for (int i = 0; i < 100; ++i) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

/*
void shufflePointers(listElement *start) {
    int used[getLenOfList(start)];

    for (int i = 0; i < getLenOfList(start); i++) {
        int attempts = 0;
        int randomElementId = getRandomNumberInRange(0, getLenOfList(start));
        while (numberExistsInArray(used, randomElementId) && attempts < 10) {
            printf("number %d rnd exists\n", randomElementId);
            randomElementId = getRandomNumberInRange(0, getLenOfList(start));
            attempts++;
        }

        if(attempts >= 10) {
            printf("broky broky scoot scoot");
            return;
        }

        listElement *randomElement = findElementByIndex(start, randomElementId);
        findElementByIndex(start, i)->nextElem = randomElement;

        used[i] = randomElementId;
    }
}

void sortList(listElement *start) {
    if(isLastElement(start)) {
        printf("nix zu sortieren :(\n");
        return;
    }

    bool isSortedInverted = true;

    while (isSortedInverted) {
        listElement *currElem = start->nextElem;
        while (!isLastElement(currElem)) {
            int iPrev = currElem->age;
            currElem = currElem->nextElem;
            int iNow = currElem->age;

            printf("prev: %d now: %d\n", iPrev, iNow);
            isSortedInverted = iPrev > iNow;
        }

        shufflePointers(start);
    }

} */

void sortList(listElement *start) {
    int lengthList = getLenOfList(start);
    int sorted = 0;
    listElement *prevElem = NULL;
    listElement *currElem;
    listElement *nextElement;


    while (!sorted) {
        sorted = 1;
        prevElem = NULL;
        currElem = start;
        nextElement = currElem->nextElem;

        for (int i = 0; i <= lengthList - 1; i++) {
            if (currElem->age > nextElement->age) {
                sorted = 0;

                listElement *temp = currElem;
                if (prevElem != NULL) {
                    prevElem->nextElem = nextElement;
                }

                currElem->nextElem = nextElement->nextElem;
                nextElement->nextElem = temp;
                currElem = nextElement;
                nextElement = currElem->nextElem;
            } else {
                prevElem = currElem;
                currElem = nextElement;
                nextElement = nextElement->nextElem;
            }
        }
    }
}

void stringToLower(char *string) {
    printf("\n>>stringToLower fcn is tbd.\n\n");
}