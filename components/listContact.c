#include <string.h>
#include "../addressbook.h"

void list_contacts(struct AddressBook *addressBook)
{
    // Listing all the contacts which are there in the array.

    if (addressBook->contactCount == 0)
    {
        printf("\nNo contacts are available to show!\n");
    }
    else
    {
        printf("\nList of all the contacts is:\n\n");
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            printf("%-50s | %-10s | %-50s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }
}