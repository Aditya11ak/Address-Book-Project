#include "../addressbook.h"

void saveAllContactsToDataBase(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv", "w");

    if (fp == NULL)
    {
        perror("Error: ");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        char *name = addressBook->contacts[i].name;
        char *phone = addressBook->contacts[i].phone;
        char *email = addressBook->contacts[i].email;
        fprintf(fp, "%s,%s,%s\n", name, phone, email);
        printf("Added: %s,%s,%s\n", name, phone, email);
    }

    fclose(fp);
}