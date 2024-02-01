#include "HashMapSocial.h"
#include "LinkedList2.h"

int getHashIndexInsert(char name[], Person * personList[])
{

	// printf("Entering getHashIndexInsert\n");

	int into = getIntFromStr(name);

	int index = into % 211;

	// Linear Probing
	while (personList[index] != NULL)
	{
		index++;
		if (index == 211)
		{
			// printf("Leave getHashIndexInsert1\n");
			return -1;
		}
	}

	// printf("Leave getHashIndexInsert2 with Index: %d\n", index);
	return index;
}

int getHashIndex(char name[], Person * personList[])
{
	// printf("Entering getHashIndex\n");


	int into = getIntFromStr(name);

	int index = into % 211;

	if (personList[index] == NULL)
	{
		return index;
	}

	// Linear Probing
	while ( (strcmp( ((personList[index])->name), name) != 0))
	{
		// printf("Inside loop\n");
		index++;
		if (index == 211)
		{	
			// printf("Leave getHashIndex1\n");		
			return -1;
		}

	}

	// printf("Leave getHashIndex2\n");	
	return index;
}



int getIntFromStr(char name[])
{
	// printf("Entering getIntFromStr\n");

	
	int sum = 0;
	int i = 0;
	int hold = 0;
	char c = name[0];
	
	while (c != '\0')
	{
		c = name[i];
		hold = c - '0';
		sum += hold;
		i++;
	}


	// printf("Leave getIntFromStr with name sum: %d\n", sum);
	return sum;
}


void createPerson(char name[], Person * personList[])
{
	// printf("Entering createPerson\n");


	Person * person = malloc(sizeof(Person));
	person->name = malloc(sizeof(char) * (strlen(name)+1));

	strcpy(person->name, name); 

	person->friendsList = initList();

	int index = getHashIndexInsert(name, personList);

	if (index == -1)
	{
		printf("\nError: Hash Table is full\n");
		return;
	}

	personList[index] = person;

	printf("\n%s has now been successfully added to the system!\n", name);

	// printf("Leave createPerson\n");

}

int makeFriend(Person * person1, Person * person2, Person * personList[])
{
	// printf("Entering makeFriend\n");

	int index1 = getHashIndex(person1->name, personList);
	int index2 = getHashIndex(person2->name, personList);

	if ( (index1 == -1) || (index2 == -1) )
	{
		// printf("Leave makeFriend1\n");
		return -1;
	}


	if ( (person1->friendsList)->head == NULL )
	{
		(person1->friendsList)->head = makeNode(person2, NULL);
	}
	else
	{
		Node * node = (person1->friendsList)->head;
		
		(person1->friendsList)->head = makeNode(person2, node);
	}
	((person1->friendsList)->size)++;


	if ( (person2->friendsList)->head == NULL )
	{
		(person2->friendsList)->head = makeNode(person1, NULL);
	}
	else
	{
		Node * node = (person2->friendsList)->head;
	
		(person2->friendsList)->head = makeNode(person1, node);
	}
	((person2->friendsList)->size)++;

	// printf("Leave makeFriend2\n");

	printf("\n%s and %s are now friends!\n", (person1->name), (person2->name));
	return 0;
}



void unfriend(Person * person1, Person * person2, Person * personList[])
{
	// printf("Entering unfriend\n");


	List * friendsList1 = person1->friendsList;
	List * friendsList2 = person2->friendsList;

	Node * node1 = friendsList1->head;
	Node * node2 = friendsList2->head;

	int i = 0;

	while (node1 != NULL)
	{
		if ( strcmp( ((node1->data)->name), (person2->name) ) == 0 )
		{
			// printf("#1 Break with index: %d\n", i);
			break;
		}
		i++;

		node1 = node1->next;
	}

	if (node1 == NULL)
	{
		printf("\n%s and %s are already not friends.\n", (person1->name), (person2->name) );
		return;
	}

	removeAtIndex(friendsList1, i);

	// printf("updated friendsList1: %s\n", ((friendsList1->head)->data)->name);

	i = 0;

	while (node2 != NULL)
	{
		if ( strcmp( ((node2->data)->name), (person1->name) ) == 0 )
		{
			// printf("#2 Break with index: %d\n", i);
			break;
		}
		i++;

		node2 = node2->next;
	}

	
	removeAtIndex(friendsList2, i);
	// printf("updated friendsList2: %s\n", ((friendsList2->head)->data)->name);
	// printf("Leave unfriend\n");

	printf("\n%s and %s are no longer friends.\n", (person1->name), (person2->name));

}

void printFriends(Person * person)
{
	// printf("Entering printFriends\n");


	Node * node = (person->friendsList)->head;

	printf("\nFriends:\n");

	while (node != NULL)
	{
		char * name = (node->data)->name;
		printf("%s ", name);
		node = node->next;
	}


	printf("\n");

	// printf("Leave printFriends\n");
}

int checkFriends(Person * person1, Person * person2, Person * personList[])
{	
	// printf("Entering checkFriends\n");


	List * friendsList1 = person1->friendsList;	

	Node * node1 = friendsList1->head;
	

	// printf("Here1\n");

	int returnVal = 1;
	
	while (node1 != NULL)
	{
		// printf("Here in loop1\n");
		if ( strcmp( ((node1->data)->name), (person2->name)) == 0 ) 
		{
			returnVal = 0;
			break;
		}

		node1 = node1->next;
	}

	// printf("Here3\n");



	if (returnVal == 0)
	{
		// printf("Leave checkFriends1\n");
		return 0;
	}
	else
	{
		// printf("Leave checkFriends2\n");
		return 1;
	}
	
}

void freePerson (Person * person)
{
	// printf("Entering freePerson\n");

	if (person != NULL)
	{
		freeList(person->friendsList);
		person->name = NULL;
		person = NULL;
	}

	// printf("Leave freePerson\n");

}

Person * getPersonFromName (char name[], Person * personList[])
{
	// printf("Entering getPersonFromName\n");

	int index = getHashIndex(name, personList);

	if (index == -1)
	{
		// printf("Leave getPersonFromName1\n");
		return NULL;
	}
	
	// printf("Leave getPersonFromName2\n");
	return personList[index];

}

int checkIsInTable(char name[], Person * personList[])
{
	int index = getHashIndex(name, personList);

	// printf("check index = %d with name %s\n", index, name);

	if (personList[index] == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}





