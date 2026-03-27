#include <string.h>
#include "../addressbook.h"

void list_contacts(struct AddressBook *addressBook)
{
    // listing all the contacts which are there in the array.
    printf("\nList of all the contacts is: \n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf(" %s | %s | %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}