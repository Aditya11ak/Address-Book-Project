// Name: Aditya N. Chakre.
// Batch: 25048.
// UserId: adityachakre123@gmail.com

#include <stdio.h>
#include "addressbook.h"

int main()
{
	int choice;

	struct AddressBook addressBook;
	addressBook.contactCount = 0;
	addressBook.ir_size = 0;

	// Loading all the existing contacts in the database before performing any other operation.
	loadContacts(&addressBook);

	do
	{
		printf("\nAddress Book Menu:\n");
		printf("1. Add/Create contact\n");
		printf("2. Search contact\n");
		printf("3. Edit contact\n");
		printf("4. Delete contact\n");
		printf("5. List all contacts\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		scanf("%d", &choice);

		// Made ir_size = 0 as we will be reusing the index_record multiple times, for every main function.
		addressBook.ir_size = 0;

		switch (choice)
		{
		case 1:
			add_contact(&addressBook);
			break;
		case 2:
			search_contact(&addressBook);
			break;
		case 3:
			edit_contact(&addressBook);
			break;
		case 4:
			delete_contact(&addressBook);
			break;
		case 5:
			list_contacts(&addressBook);
			break;
		case 6:
			saveAllContactsToDataBase(&addressBook);
			printf("Saving and Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 6);

	return 0;
}