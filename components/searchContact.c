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

    printf("\nEnter name, mobile number or email to search contact:\n");
    printf("\nFor phone number Only digits allowed! \n");
    printf("\nEmail instructions:\n1) Only lower case letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of anyother symbol.\n");

    scanf(" %49[^\n]", str);

    // Figuring out the exact type of the given format.
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
        printf("\nSomething went wrong!!\n");

    // Checking if the given information is valid or not.
    if (valid == 0)
        printf("\nEntered data format is not valid!!\n");
    else if (valid == -1)
        printf("\nSomething is wrong with the validation!!\n");

    // Checking the availability of the data in the Contacts array.

    int count = 1;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // printf("Checking: %s | %s | %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

        if (strstr(addressBook->contacts[i].name, str) != NULL ||
            strstr(addressBook->contacts[i].phone, str) != NULL ||
            strstr(addressBook->contacts[i].email, str) != NULL)
        {
            printf("\n[%d] Contact found: \n", count++);
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);

            // Storing the index of the contact in case user called the search_contact function for editing or deleting the contact.

            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
            found = 1;
        }
    }

    for (int i = 0; i < addressBook->ir_size; i++)
    {
        printf("%d -> %d\n", i, addressBook->index_record[i]);
    }

    if (found == 0)
    {
        printf("\nEntry with given information %s not found!!", str);
    }
}