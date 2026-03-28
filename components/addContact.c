#include <string.h>
#include "../addressbook.h"

void add_contact(struct AddressBook *addressBook)
{

    char tempName[50];
    char tempPhone[15];
    char tempEmail[50];

    int isPresent1 = 0;
    int isPresent2 = 0;

    // Taking user input for the name.
    printf("\n\nPlease enter your name:\n");
    inputName(tempName);

    // Taking user input for the number.
    printf("\n\nPlease enter the mobile number:\n");
    inputPhone(tempPhone);

    // Taking user input for the email.
    printf("\n\nEnter your email address:\n");
    printf("\nEmail instructions:\n1) Only lowercase letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of any other symbols.\n");
    inputEmail(tempEmail);

    // Checking in the database before adding to avoid duplicate entries.
    isPresent1 = searchForDuplicate(addressBook, tempPhone);
    isPresent2 = searchForDuplicate(addressBook, tempEmail);

    if (isPresent1 && isPresent2)
    {
        if (addressBook->contactCount >= 100)
        {
            printf("\nThe Address Book is full!!\n");
        }
        else
        {
            strcpy(addressBook->contacts[addressBook->contactCount].name, tempName);
            strcpy(addressBook->contacts[addressBook->contactCount].phone, tempPhone);
            strcpy(addressBook->contacts[addressBook->contactCount].email, tempEmail);
            addressBook->contactCount++;
        }
    }
    else if (!isPresent1)
        printf("\n\nDuplicate phone number!!\n");
    else if (!isPresent2)
        printf("\n\nDuplicate email!!\n");
}

// All Input functions....

void inputName(char *tempName)
{

    while (1)
    {

        scanf(" %49[^\n]", tempName);

        int verified = validateName(tempName);

        if (verified)
            break;

        printf("\nInvalid name. Enter the name again.\n");
    }
}

void inputPhone(char *tempPhone)
{
    while (1)
    {

        scanf(" %14[^\n]", tempPhone);

        int verified = validatePhone(tempPhone);

        if (verified)
            break;

        printf("\nInvalid input. Enter again:\n");
    }
}

void inputEmail(char *tempEmail)
{
    while (1)
    {

        scanf(" %49[^\n]", tempEmail);

        int verified = validateEmail(tempEmail);

        if (verified)
            break;

        printf("\nInvalid email format. Enter again:\n");
    }
}