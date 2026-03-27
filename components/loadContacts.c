#include <string.h>
#include "../addressbook.h"

void loadContacts(struct AddressBook *addressBook)
{

    FILE *fp = fopen("database.csv", "r");

    if (fp == NULL)
    {
        perror("Error: ");
        return;
    }

    // finding all the entires in the Database before starting anyother part of the program.
    char buffer[200];
    char *delimiter = ",";

    // Searching the database using the number or email.

    while (fgets(buffer, 200, (FILE *)fp) != NULL)
    {
        // fixed the \n problem at the end because of the fgets function
        buffer[strcspn(buffer, "\n")] = '\0';

        char *name = strtok(buffer, delimiter);
        char *phone = strtok(NULL, delimiter);
        char *email = strtok(NULL, delimiter);

        printf("Added: %s,%s,%s\n", name, phone, email);

        strcpy(addressBook->contacts[addressBook->contactCount].name, name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, email);
        addressBook->contactCount++;
    }
}