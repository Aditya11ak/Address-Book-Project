#include <string.h>
#include "../addressbook.h"

void deleteContactPermanantly(struct AddressBook *addressBook, int index);

void delete_contact(struct AddressBook *addressBook)
{

    int choice = 0;

    printf("\n\u2757\u2757 Danger Zone!!!  \u2757\u2757\n\n");
    printf("\nIf you dont want to delete anything then you can enter 2 and exit the Danger Zone!! \n");
    printf("\nIf you really want to delete something then enter 1\n");

    do
    {
        scanf(" %1d", &choice);
        switch (choice)
        {
        case 1:

            search_contact(addressBook);

            if (addressBook->ir_size == 0)
                return;

            if (addressBook->ir_size == 1)
            {
                deleteContactPermanantly(addressBook, 0);
            }
            else
            {
                printf("\nEnter the index of contact which you want to \u2757\u2757 DELETE \u2757\u2757\n");
                int index = getIndex(addressBook);
                deleteContactPermanantly(addressBook, index - 1);
            }
            return;

        case 2:
            printf("\n\u2757\u2757 Danger Zone!!!  \u2757\u2757 Exited Successfully!\n");
            break;

        default:
            printf("\nYou have entered Invalid input try again!!\n");
        }

        while (getchar() != '\n')
            ;
    } while (choice != 2);
}

void deleteContactPermanantly(struct AddressBook *addressBook, int index)
{

    for (int i = addressBook->index_record[index]; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("\nContact deleted successfully!\n");
}
