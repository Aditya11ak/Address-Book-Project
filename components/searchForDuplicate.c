#include <string.h>
#include "../addressbook.h"

// TODO: Before adding to the array of the struct we have to check for duplicates in array not into the database.

int searchForDuplicate(struct AddressBook *addressBook, char *str)
{

    int isNumber = 1;
    int isEqual = -1;

    for (int i = 0; i < strlen(str); i++)
    {

        if (!(str[i] >= '0' && str[i] <= '9'))
            isNumber = 0;
    }

    // Searching the contacts array using the number or email.
    if (isNumber)
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {

            if (strcmp(addressBook->contacts[i].phone, str) == 0)
            {
                // duplicate entry found return 0
                return 0;
            }
        }

        // no duplicate entry present.
        return 1;
    }
    else
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {

            if (strcmp(addressBook->contacts[i].email, str) == 0)
            {
                // duplicate entry found return 0
                return 0;
            }
        }

        // no duplicate entry present.
        return 1;
    }
}
