#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook
{

    struct Contact contacts[100];
    int contactCount;
    int index_record[100];
    int ir_size;
};

void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);

// Additional functions which are used for simplicity.
void loadContacts(struct AddressBook *addressBook);
void saveAllContactsToDataBase(struct AddressBook *addressBook);
int searchForDuplicate(struct AddressBook *addressBook, char *str);
int getIndex(struct AddressBook *addressBook);

void inputName(char *tempName);
void inputPhone(char *tempPhone);
void inputEmail(char *tempEmail);

int validateName(char *tempName);
int validatePhone(char *tempPhone);
int validateEmail(char *tempEmail);

#endif
