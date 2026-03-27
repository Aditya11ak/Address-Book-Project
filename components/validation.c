#include <stdio.h>
#include <string.h>
#include "../addressbook.h"

int validateName(char *tempName)
{
    for (int i = 0; i < strlen(tempName); i++)
    {
        if (!((tempName[i] >= 'a' && tempName[i] <= 'z') ||
              (tempName[i] >= 'A' && tempName[i] <= 'Z') ||
              tempName[i] == '_' ||
              tempName[i] == '-' ||
              tempName[i] == ' '))
        {
            return 0;
        }
    }
    return 1;
}

int validatePhone(char *tempPhone)
{
    int len = strlen(tempPhone);

    if (len != 10)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (!(tempPhone[i] >= '0' && tempPhone[i] <= '9'))
            {
                return 0;
                break;
            }
        }
    }

    return 1;
}

int validateEmail(char *email)
{
    int len = strlen(email);
    int atCount = -1, dotCount = -1;

    // checks for the smallest possible email address.
    if (len < 5)
        return 0;

    if (email[0] == '@' || email[0] == '.' ||
        email[len - 1] == '@' || email[len - 1] == '.')
        return 0;

    for (int i = 0; i < len; i++)
    {
        // checks for the invalid character
        if (!((email[i] >= 'a' && email[i] <= 'z') ||
              (email[i] >= 'A' && email[i] <= 'Z') ||
              (email[i] >= '0' && email[i] <= '9') ||
              email[i] == '@' ||
              email[i] == '.'))
            return 0;

        // checks for two contineous .'s in entire email address.
        if (i < len - 1 && email[i] == '.' && email[i + 1] == '.')
            return 0;

        if (email[i] == '@')
        {
            if (atCount != -1) // more than one '@'
                return 0;
            atCount = i;
        }

        if (email[i] == '.')
        {
            dotCount = i;
        }

        if (i < len - 1 && email[i] == '@' && email[i + 1] == '.')
            return 0;
    }

    if (atCount == -1 || dotCount == -1 || dotCount < atCount)
        return 0;

    return 1;
}