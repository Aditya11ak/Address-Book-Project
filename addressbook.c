//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include <string.h>
// #include "../addressbook.h"

// void search_contact(struct AddressBook *addressBook)
// {

//     // also i have to add the name to search the data in database. also use the substring checking.
//     // for duplicate entires.with names we have to check the index_record and from that we have to print all the avialable entries
//     // in that we have to give user option which he wants but in the edit contact not in search.

//     // add isEmail, verify -> struct -> search database.
//     // in the string we have to add function that we can be able to search names using the substrings. and give all the names to user
//     // onto the console.

//     printf("\nEnter name, mobile number or email to search contact:\n\n");
//     printf("For phone number Only digits allowed!\n\n");
//     printf("Email instructions:\n1) Only lower case letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of anyother symbol.\n");

//     char str[50];

//     int isNumber = 1;
//     int atCount = 0;
//     int isName = 1;
//     int found = 0;
//     int ch = getchar();
//     int isValid = 1;

//     fgets(str, 50, stdin);
//     str[strcspn(str, "\n")] = '\0';

//     for (int i = 0; i < strlen(str); i++)
//     {

//         if (!(str[i] >= '0' && str[i] <= '9'))
//             isNumber = 0;

//         if (str[i] == '@')
//             atCount += 1;

//         if (!((str[i] >= 'a' && str[i] <= 'z') ||
//               (str[i] >= '0' && str[i] <= '9') ||
//               str[i] == '@' ||
//               str[i] == '.'))
//             isValid = 0;

//         if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
//             isName = 0;
//     }

//     // File opening.
//     FILE *fp = fopen("database.csv", "r");
//     if (fp == NULL)
//     {
//         perror("Error: ");
//         return;
//     }

//     char buffer[100];
//     char *delimiter = ",";

//     // Searching the database using the number or email.
//     if (isNumber && isValid)
//     {

//         while (fgets(buffer, 100, (FILE *)fp) != NULL)
//         {
//             // fixed the \n problem at the end because of the fgets function
//             buffer[strcspn(buffer, "\n")] = '\0';

//             char *name = strtok(buffer, delimiter);
//             char *phone = strtok(NULL, delimiter);
//             // searching member with number.
//             int isEqual = strcmp(str, phone);
//             char *email = strtok(NULL, delimiter);
//             if (isEqual == 0)
//             {
//                 printf("\nEntry found!! Informatin of the given Member is: \n");
//                 printf("\nName: %s \nPhoneNumber: %s\nEmail: %s\n", name, phone, email);
//                 found = 1;
//                 break;
//             }
//         }

//         if (found == 0)
//         {
//             printf("\nEntry with given information %s not found!!", str);
//         }
//     }
//     else if (isValid && atCount == 1)
//     {
//         while (fgets(buffer, 100, (FILE *)fp) != NULL)
//         {
//             // fixed the \n problem at the end because of the fgets function
//             buffer[strcspn(buffer, "\n")] = '\0';

//             char *name = strtok(buffer, delimiter);
//             char *phone = strtok(NULL, delimiter);
//             char *email = strtok(NULL, delimiter);
//             // searching member with Email.
//             int isEqual = strcmp(str, email);
//             if (isEqual == 0)
//             {
//                 printf("\nEntry found!! Informatin of the given Member is: \n");
//                 printf("\nName: %s \nPhoneNumber: %s\nEmail: %s\n", name, phone, email);
//                 found = 1;
//                 break;
//             }
//         }

//         if (found == 0)
//         {
//             printf("\nEntry with given information %s not found!!", str);
//         }
//     }
//     else if (isNumber == 0 && atCount == 0 && isName == 1)
//     {
//         int count = 1;
//         for (int i = 0; i < addressBook->contactCount; i++)
//         {
//             printf("Checking: %s | %s | %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

//             if (strstr(addressBook->contacts[i].name, str) != NULL ||
//                 strstr(addressBook->contacts[i].phone, str) != NULL ||
//                 strstr(addressBook->contacts[i].email, str) != NULL)
//             {
//                 printf("\n[%d] Contact found: ", count++);
//                 printf("Name: %s\n", addressBook->contacts[i].name);
//                 printf("Phone: %s\n", addressBook->contacts[i].phone);
//                 printf("Email: %s\n", addressBook->contacts[i].email);
//                 found = 1;
//             }
//         }

//         if (found == 0)
//         {
//             printf("\nEntry with given information %s not found!!", str);
//         }
//     }
//     else
//     {
//         printf("\nInvalid data entered!!");
//     }

//     fclose(fp);
// }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include "addressbook.h"
// #include <string.h>

// void add_contact(struct AddressBook *addressBook);

// void search_contact(struct AddressBook *addressBook)
// {
//     printf("\nEnter mobile number or email to search contact:\n\n");
//     printf("For phone number Only digits allowed! \n");
//     printf("Email instructions:\n1) Only lower case letters\n2) No numbers after @ symbol\n3) No use of _ or -\n4) No use of anyother symbol.\n");

//     char str[50];

//     int isNumber = 1;
//     int found = 0;
//     int ch = getchar();
//     int isValid = 1;
//     int atCount = 0;

//     fgets(str, 50, stdin);
//     str[strcspn(str, "\n")] = '\0';

//     for (int i = 0; i < strlen(str); i++)
//     {

//         if (!(str[i] >= '0' && str[i] <= '9'))
//             isNumber = 0;

//         if (str[i] == '@')
//             atCount += 1;

//         if (!((str[i] >= 'a' && str[i] <= 'z') ||
//               (str[i] >= '0' && str[i] <= '9') ||
//               str[i] == '@' ||
//               str[i] == '.'))
//             isValid = 0;
//     }

//     // File opening.
//     FILE *fp = fopen("database.csv", "r");
//     if (fp == NULL)
//     {
//         perror("Error: ");
//         return;
//     }

//     char buffer[100];
//     int i = 0;
//     char *delimiter = ",";

//     // Searching the database using the number or email.
//     if (isNumber && isValid)
//     {

//         while (fgets(buffer, 100, (FILE *)fp) != NULL)
//         {
//             // fixed the \n problem at the end because of the fgets function
//             buffer[strcspn(buffer, "\n")] = '\0';

//             char *name = strtok(buffer, delimiter);
//             char *phone = strtok(NULL, delimiter);
//             // searching member with number.
//             int isEqual = strcmp(str, phone);
//             char *email = strtok(NULL, delimiter);
//             if (isEqual == 0)
//             {
//                 printf("\nEntry found!! Informatin of the given Member is: \n");
//                 printf("\nName: %s \nPhoneNumber: %s\nEmail: %s\n", name, phone, email);
//                 found = 1;
//                 break;
//             }
//         }

//         if (found == 0)
//         {
//             printf("\nEntry with given information %s not found!!", str);
//         }
//     }
//     else if (isValid && atCount == 1)
//     {
//         while (fgets(buffer, 100, (FILE *)fp) != NULL)
//         {
//             // fixed the \n problem at the end because of the fgets function
//             buffer[strcspn(buffer, "\n")] = '\0';

//             char *name = strtok(buffer, delimiter);
//             char *phone = strtok(NULL, delimiter);
//             char *email = strtok(NULL, delimiter);
//             // searching member with Email.
//             int isEqual = strcmp(str, email);
//             if (isEqual == 0)
//             {
//                 printf("\nEntry found!! Informatin of the given Member is: \n");
//                 printf("\nName: %s \nPhoneNumber: %s\nEmail: %s\n", name, phone, email);
//                 found = 1;
//                 break;
//             }
//         }

//         if (found == 0)
//         {
//             printf("\nEntry with given information %s not found!!", str);
//         }
//     }
//     else
//     {
//         printf("\nInvalid data entered!!");
//     }

//     fclose(fp);
// }

// void edit_contact(struct AddressBook *addressBook)
// {
// }
// void delete_contact(struct AddressBook *addressBook)
// {
// }
// void list_contacts(struct AddressBook *addressBook)
// {
// }
