#include "HashMapSocial.h"

#define SIZE 211

int main()
{
	Person * hashTable[211];

	int k;

	for (k = 0; k < 211; k++) 
	{
		hashTable[k] = NULL;
	}

	char userInput = '0';

	printf("Please input the string coorseponding to what you would like to do\nP – Create a person record of the specified first name.\nF — Record that the two specified people are friends.\nU — Record that the two specified people are no longer friends.\nL — Print out the friends of the specified person.\nQ — Check whether the two people are friends.\nX – terminate the program.\n\n");

	while (userInput != 'X')
	{
		scanf(" %c", &userInput);

		if (userInput == 'P')
		{
			char name[200];

			printf("\nPlease input one name.\n");

			scanf(" %s", name);

			createPerson(name, hashTable);

		}
		else if (userInput == 'F')
		{
			char name1[200];
			char name2[200];

			printf("Please input the first friend name.\n");
			scanf(" %s", name1);

			int ec = checkIsInTable(name1, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system. Please add them to the system before you try and add them as a friend.\n", name1);
				continue;
			}

			// printf("name1 = %s\n", name1);


			printf("Please input the second friend name.\n");
			scanf("\n%s", name2);

			ec = checkIsInTable(name2, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system. Please add them to the system before you try and add them as a friend.\n", name2);
				continue;
			}

			// printf("name2 = %s\n", name2);


			Person * person1 = getPersonFromName(name1, hashTable);
			Person * person2 = getPersonFromName(name2, hashTable);

			ec = makeFriend(person1, person2, hashTable);

			if (ec == -1)
			{
				printf("\nError in makeFriend\n");
			}

		}
		else if (userInput == 'U')
		{
			char name1[200];
			char name2[200];

			printf("Please input the first friend name.\n");
			scanf(" %s", name1);

			int ec = checkIsInTable(name1, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system.\n", name1);
				continue;
			}

			printf("Please input the second friend name.\n");
			scanf(" %s", name2);

			ec = checkIsInTable(name2, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system.\n", name2);
				continue;
			}

			Person * person1 = getPersonFromName(name1, hashTable);
			Person * person2 = getPersonFromName(name2, hashTable);

			unfriend(person1, person2, hashTable);
		}
		else if (userInput == 'L')
		{
			char name[200];

			printf("Please input one name.\n");

			scanf(" %s", name);

			int ec = checkIsInTable(name, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system.\n", name);
				continue;
			}

			Person * person = getPersonFromName(name, hashTable);

			printFriends(person);


		}
		else if (userInput == 'Q')
		{
			char name1[200];
			char name2[200];

			printf("Please input the first friend name.\n");
			scanf(" %s", name1);

			int ec = checkIsInTable(name1, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system.\n", name1);
				continue;
			}

			printf("Please input the second friend name.\n");
			scanf(" %s", name2);

			ec = checkIsInTable(name2, hashTable);

			if (ec == 0)
			{
				printf("\n%s is not in the system.\n", name2);
				continue;
			}

			Person * person1 = getPersonFromName(name1, hashTable);
			Person * person2 = getPersonFromName(name2, hashTable);

			int val = checkFriends(person1, person2, hashTable);

			if (val == 0)
			{
				printf("\n%s is friends with %s\n", name1, name2);
			}
			else
			{
				printf("\n%s is not friends with %s\n", name1, name2);
			}


		}
		else if (userInput == 'X')
		{
			int i;

			for (i = 0; i < 211; i++)
			{
				freePerson(hashTable[i]);
			}
		}
		else
		{
			printf("\nINVALID INPUT\n");
		}

	}
	printf("\nThank you, Goodbye!\n");
}