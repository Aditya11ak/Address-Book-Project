<h1 align="center">📒 Address Book in C</h1>

<p align="center">
A simple and efficient Address Book project built in C with file handling, validation, and modular design.
</p>

---

<h2>📌 Project Overview</h2>

This project is a **console-based Address Book application** written in C.  
It allows users to store, manage, and manipulate contact details like:

- Name
- Phone Number
- Email Address

All data is stored persistently using a CSV file (`database.csv`).

---

<h2>✨ Features</h2>

<ul>
<li>➕ Add new contact</li>
<li>🔍 Search contact (by name / phone / email)</li>
<li>✏️ Edit existing contact</li>
<li>🗑️ Delete contact</li>
<li>📋 List all contacts</li>
<li>💾 File storage using CSV</li>
<li>✅ Input validation</li>
<li>🚫 Duplicate prevention</li>
</ul>

---

<h2>📂 Project Structure</h2>

<pre>
AddressBook/
│
├── main.c
├── addressbook.h
├── database.csv
├── README.md
│
└── components/
    ├── add_contact.c
    ├── search_contact.c
    ├── edit_contact.c
    ├── delete_contact.c
    ├── list_contact.c
    ├── file_operations.c
    ├── validation.c
</pre>

---

<h2>⚙️ Compilation & Execution</h2>

<pre>
gcc main.c components/*.c -o app
./app
</pre>

---

<h2>🧠 Core Concepts Used</h2>

<ul>
<li>Structures in C</li>
<li>File Handling (fopen, fgets, fprintf)</li>
<li>String Manipulation (strcpy, strcmp, strstr, strtok)</li>
<li>Modular Programming</li>
<li>Input Validation</li>
<li>Dynamic Searching</li>
</ul>

---

<h2>📊 Data Structures</h2>

<h3>Contact</h3>

<pre>
struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};
</pre>

<h3>Address Book</h3>

<pre>
struct AddressBook
{
    struct Contact contacts[100];
    int contactCount;

    int index_record[100]; // Stores search results
    int ir_size;
};
</pre>

---

<h2>🔄 Function Workflow</h2>

<h3>➕ Add Contact</h3>
<ul>
<li>Takes validated input</li>
<li>Checks for duplicate phone/email</li>
<li>Adds contact to array</li>
</ul>

<h3>🔍 Search Contact</h3>
<ul>
<li>Accepts name / phone / email</li>
<li>Detects type automatically</li>
<li>Supports partial matching (for names)</li>
<li>Stores results in <code>index_record</code></li>
</ul>

<h3>✏️ Edit Contact</h3>
<ul>
<li>Search first</li>
<li>Select contact (if multiple)</li>
<li>Update details with validation</li>
</ul>

<h3>🗑️ Delete Contact</h3>
<ul>
<li>Search first</li>
<li>Select contact</li>
<li>Shift array to remove entry</li>
</ul>

<h3>📋 List Contacts</h3>
<ul>
<li>Displays all stored contacts</li>
</ul>

---

<h2>💾 File Handling</h2>

<ul>
<li><b>Load:</b> Reads contacts from <code>database.csv</code> at startup</li>
<li><b>Save:</b> Writes all contacts back to file before exit</li>
</ul>

---

<h2>✅ Validation Rules</h2>

<h3>Name</h3>
<ul>
<li>Only letters, space, '_' and '-'</li>
</ul>

<h3>Phone</h3>
<ul>
<li>Must be exactly 10 digits</li>
</ul>

<h3>Email</h3>
<ul>
<li>Must contain '@' and '.'</li>
<li>No invalid characters</li>
<li>No consecutive dots</li>
<li>Proper format enforced</li>
</ul>

---

<h2>🚫 Duplicate Handling</h2>

<ul>
<li>No duplicate phone numbers allowed</li>
<li>No duplicate email addresses allowed</li>
</ul>

---

<h2>🔍 Special Feature</h2>

<p>
The project uses an <b>index tracking system</b> (<code>index_record[]</code>)  
to handle multiple search results efficiently during edit and delete operations.
</p>

---

<h2>📌 Notes</h2>

<ul>
<li>Maximum contacts: 100</li>
<li>Uses static arrays (no dynamic memory)</li>
<li>Designed for learning and academic purposes</li>
</ul>

---

<h2>👨‍💻 Author</h2>

<p>
Developed as part of a lab project to understand core C programming concepts.
</p>

---

<h2 align="center">⭐ If you like this project, give it a star!</h2>