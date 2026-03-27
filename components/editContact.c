#include <string.h>
#include "../addressbook.h"

char newName[50];
char newPhone[15];
char newEmail[50];

void saveToContacts(struct AddressBook *addressBook, int index);
void clearBuffer();

void edit_contact(struct AddressBook *addressBook)
{
    // used to search contact and find if the information they want to edit is actually present or not?
    search_contact(addressBook);

    if (addressBook->ir_size == 0)
        return;
    printf("\nEnter new name:\n");
    inputName(newName);

    printf("\nEnter new Phone number:\n");
    inputPhone(newPhone);

    printf("\nEnter new email: \n");
    printf("\nEmail instructions:\n1) Only lower case letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of any other symbol.\n");
    inputEmail(newEmail);

    if (addressBook->ir_size == 1)
    {
        saveToContacts(addressBook, 0);
    }
    else
    {
        printf("\nEnter the index of contact which you want to edit.\n");
        int index = getIndex(addressBook);
        saveToContacts(addressBook, index - 1);
    }
}

int getIndex(struct AddressBook *addressBook)
{
    int index = -1;
    while (1)
    {
        if (scanf(" %2d", &index) == 0)
        {
            clearBuffer();
            printf("\nInvalid input. Try again.\n");
            continue;
        }

        if (index > 0 && index - 1 < addressBook->ir_size)
        {
            break;
        }

        printf("Out of range. Try again.\n");
        clearBuffer();
    }
}

void saveToContacts(struct AddressBook *addressBook, int index)
{
    int isPresent1 = 0;
    int isPresent2 = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {

        if (i != addressBook->index_record[index])
        {
            isPresent1 = searchForDuplicate(addressBook, newPhone);
            isPresent2 = searchForDuplicate(addressBook, newEmail);

            if (!(isPresent1 && isPresent2))
                break;
        }
    }

    if (isPresent1 && isPresent2)
    {

        strcpy(addressBook->contacts[addressBook->index_record[index]].name, newName);
        strcpy(addressBook->contacts[addressBook->index_record[index]].phone, newPhone);
        strcpy(addressBook->contacts[addressBook->index_record[index]].email, newEmail);
    }
    else if (!isPresent1)
        printf("\n\nYou are trying to enter the duplicate Phone Number!!\n");
    else if (!isPresent2)
        printf("\n\nYou are trying to enter the duplicate Email!!\n");
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}