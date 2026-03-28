#include <string.h>
#include "../addressbook.h"

void search_contact(struct AddressBook *addressBook)
{

    char str[50];

    int isNumber = 1;
    int isEmail = 0;
    int isName = 1;

    int found = 0;
    int valid = -1;

        printf("\nYou can enter partial name or Full mobile number and email to search contact:\n");
    printf("\nFor phone number, only digits allowed! \n");
    printf("\nEmail instructions:\n1) Only lowercase letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of any other symbol.\n");

    scanf(" %49[^\n]", str);

    // Figuring out the exact type of the given string.
    for (int i = 0; i < strlen(str); i++)
    {

        if (!(str[i] >= '0' && str[i] <= '9'))
            isNumber = 0;

        if (str[i] == '@')
            isEmail += 1;
    }

    // Checking the validation according to the type.
    if (isNumber)
        valid = validatePhone(str);

    else if (isEmail)
        valid = validateEmail(str);

    else if (isName)
        valid = validateName(str);

    else
    {
        printf("\nSomething went wrong!!\n");
        return;
    }
    // Checking if the given string is valid or not.
    if (valid == 0)
    {
        printf("\nEntered data format is not valid!!\n");
        return;
    }
    else if (valid == -1)
    {
        printf("\nSomething is wrong with the validation!!\n");
        return;
    }
    // Checking the availability of the data in the Contacts array.
    int count = 1;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strstr(addressBook->contacts[i].name, str) != NULL ||
            strstr(addressBook->contacts[i].phone, str) != NULL ||
            strstr(addressBook->contacts[i].email, str) != NULL)
        {
            printf("\n[%d] Contact found:\n", count++);
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);

            // Storing the index of the contact in case the user called the search_contact function for editing or deleting the contact.

            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
            found = 1;
        }
    }

    // This was added to see how index_record holds the index of the actual data.
    // Also how it helps us to change the data when multiple entries are present with same name.
    // for (int i = 0; i < addressBook->ir_size; i++)
    // {
    //     printf("%d -> %d\n", i, addressBook->index_record[i]);
    // }

    if (found == 0)
    {
        printf("\nEntry with the given information %s not found!!", str);
    }
}