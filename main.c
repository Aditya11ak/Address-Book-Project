// Name: Aditya N. Chakre.
// Batch: 25048.
// UserId: adityachakre123@gmail.com

/*
Description:

	#Overall structure of the project:

			In this project we have a struct of contact in which we are having name, phone and email.
		This is added in the AddressBook struct in the form of the array of the struct contacts which is
		having additional things like, total contactCount, index_record and ir_size.

			The contact and contactCount is used to store total contacts. At the beginning of the program,
		all the data is loaded from the database (database.csv) using loadContacts() and stored in this
		structure array. After that any kind of operation like addition of contact, editing of the contact,
		deleting contact, searching contact and listing contact will be performed on this array.

			While exiting the project we store all the updated data back to the database using
		saveAllContactsToDataBase(). This helps us to maintain proper sequence of the data even after
		deleting and updating the data.

			The index_record and ir_size are used during searching. index_record stores the indices of
		the matched contacts and ir_size keeps track of how many matches are found. This is useful when
		multiple entries are present with the same name.


There are 5 main functions,

1) add_contact:

			As we discussed all the data is loaded in the contacts array before performing any operation.
		If there is no data then nothing will be loaded. In the add contact we are using [inputName],
		[inputPhone] and [inputEmail] functions which internally use [validateName], [validatePhone],
		[validateEmail] to properly validate the data entered by the user.

			Before directly adding the data to the contacts array we check if the entered phone number
		and email are already present in the database using [searchForDuplicate] function. If no duplicate
		is found then the contact is added to the contacts array.


2) search_contact:

			In this function we are searching for the contacts using partial name, full phone number and
		email. For name searching we use partial matching using strstr(), which helps to find contacts
		even if only part of the name is entered.

			In search contact we are using index_record to store the indices of matched entries. This helps
		us to display multiple entries properly if duplicate names are present and also helps in future use
		of this function in [edit_contact] and [delete_contact].

			All the matched contacts are displayed to the user on the console.


3) edit_contact:

			In edit contact we are using the [search_contact] function first, because before editing we
		have to locate the specific contact. After searching, if the contact exists then it will be shown.

			If multiple entries are found then index_record is used to select the correct contact using
		user input. After that [inputName], [inputPhone] and [inputEmail] are used again to take new data
		with proper validation.

			While updating the contact we also check that the new phone number and email are not duplicates
		(with respect to other contacts). If everything is valid then the selected contact is updated.


4) delete_contact:

			In delete contact we are using the [search_contact] function to find the required contact.
		If multiple entries are found then index_record helps to select the correct one.

			After selecting the contact, it is deleted from the contacts array by shifting all the
		elements one position to the left. Then contactCount is decremented.

			Finally, the updated data will be saved to the database while exiting the program using
		[saveAllContactsToDataBase].


5) list_contacts:

			In this function we are printing all the contacts present in the contacts array.
		We iterate from 0 to addressBook->contactCount and print all the details onto the console
		in a formatted manner.


6) Exit:

			While exiting the program we are storing all the data present in the contacts array back
		into the database using [saveAllContactsToDataBase]. This ensures that all changes made during
		the execution are saved permanently.


*/

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