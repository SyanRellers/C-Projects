#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList2.h"

int getHashIndex(char name[], Person * personList[]);
int getIntFromStr(char name[]);

void createPerson(char name[], Person * personList[]);
int makeFriend(Person * person1, Person * person2, Person * personList[]);
void unfriend(Person * person1, Person * person2, Person * personList[]);
void printFriends(Person * person);
int checkFriends(Person * person1, Person * person2, Person * personList[]);
void freePerson (Person * person);
int getHashIndexInsert(char name[], Person * personList[]);
Person * getPersonFromName(char * name, Person * personList[]);
int checkIsInTable(char name[], Person * personList[]);


