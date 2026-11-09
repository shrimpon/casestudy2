#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream> // eto ung library para magamit ung text file database na required ni sir
#include <iomanip> // decided to not to use it since my groupmates would've harder time to understand this program/system

using namespace std;

void menu();
void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();
void borrowBook();
void returnBook();
void sortBooks();
void saveBooks();
void loadBooks();s

struct Book
    {
        int id;
        string title;
        string author;
        int year;
        string borrower;
    };

    Book books[100];

    int bookCount = 0;
    int nextId = 1;

int main()
{

    loadBooks();
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    int choice;

    do
    {
        system("cls");

        cout<<"-----=====-----=====-----=====-----\n";
        cout<<"         LIBRARY MANAGEMENT\n";
        cout<<"-----=====-----=====-----=====-----\n";
        cout<<"\n";
        cout<<"       [1]  Add Book\n";
        cout<<"       [2]  View Books\n";
        cout<<"       [3]  Search Book\n";
        cout<<"       [4]  Update Book\n";
        cout<<"       [5]  Delete Book\n";
        cout<<"       [6]  Borrow Book\n";
        cout<<"       [7]  Return Book\n";
        cout<<"       [8]  Sort Books\n";
        cout<<"       [0]  Exit\n";
        cout<<"\n";
        cout<<"-----=====-----=====-----=====-----\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 0:
                cout<<"\nExiting program...\n";
                break;

            case 1:
                cin.ignore();
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                updateBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                borrowBook();
                break;

            case 7:
                returnBook();
                break;

            case 8:
                sortBooks();
                break;

            default:
                cout<<"\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);
}

void addBook()
{
    if (bookCount >= 100)
    {
        cout<<"\nLibrary is full!\n";
        return;
    }

    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              ADD BOOK\n";
    cout<<"-----=====-----=====-----=====-----\n";

    books[bookCount].id = nextId;

    cout<<"Enter Book Title: ";
    getline(cin, books[bookCount].title);

    cout<<"Enter Author: ";
    getline(cin, books[bookCount].author);

    cout<<"Enter Publication Year: ";
    cin>>books[bookCount].year;

    books[bookCount].borrower = "";

    bookCount++;
    nextId++;
    saveBooks();

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"       BOOK ADDED SUCCESSFULLY!";
    cout<<"\n-----=====-----=====-----=====-----\n";
}

void viewBooks()
{
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              BOOK LIST\n";
    cout<<"-----=====-----=====-----=====-----\n";

    if (bookCount == 0)
    {
        cout<<"\nNo books available.\n";
        cout<<"-----=====-----=====-----=====-----\n";
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        cout<<"\nBook ID: "<<books[i].id;
        cout<<"\nTitle: "<<books[i].title;
        cout<<"\nAuthor: "<<books[i].author;
        cout<<"\nYear: "<<books[i].year;

        if (books[i].borrower == "")
        {
            cout<<"\nStatus: Available";
        }
        else
        {
            cout<<"\nStatus: Borrowed by "<<books[i].borrower;
        }

        cout<<"\n-----=====-----=====-----=====-----\n";
    }

    cout<<"\nTotal Books: "<<bookCount<<"\n";

    cout<<"\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void searchBook()
{
    int searchId;
    bool found = false;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"             BOOK SEARCH\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\nEnter Book ID: ";
    cin>>searchId;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            cout<<"\n-----=====-----=====-----=====-----\n";
            cout<<"             BOOK FOUND\n";
            cout<<"-----=====-----=====-----=====-----\n";

            cout<<"\nBook ID: " << books[i].id;
            cout<<"\nTitle: " << books[i].title;
            cout<<"\nAuthor: " << books[i].author;
            cout<<"\nYear: " << books[i].year;

            if (books[i].borrower == "")
            {
                cout<<"\nStatus: Available";
            }
            else
            {
                cout<<"\nStatus: Borrowed by "<<books[i].borrower;
            }

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout<<"\nBook not found.\n";
    }

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void updateBook()
{
    int searchId;
    bool found = false;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              UPDATE BOOK\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\nEnter Book ID: ";
    cin>>searchId;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            cin.ignore();

            cout<<"\nCurrent Title: "<<books[i].title;
            cout<<"\nNew Title: ";
            getline(cin, books[i].title);

            cout<<"\nCurrent Author: "<<books[i].author;
            cout<<"\nNew Author: ";
            getline(cin, books[i].author);

            cout<<"\nCurrent Year: "<<books[i].year;
            cout<<"\nNew Publication Year: ";
            cin>>books[i].year;

            saveBooks();
            found = true;

            cout<<"\n-----=====-----=====-----=====-----\n";
            cout<<"         BOOK UPDATED SUCCESSFULLY!";
            cout<<"\n-----=====-----=====-----=====-----\n";

            cout<<"\nPress ENTER to continue...";
            cin.ignore();
            cin.get();

            break;
        }
    }

    if (found == false)
    {
        cout<<"\nBook not found.\n";
        cout<<"\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }
}

void deleteBook()
{
    int searchId;
    bool found = false;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              DELETE BOOK\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\nEnter Book ID: ";
    cin>>searchId;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            for (int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }

            bookCount--;
            saveBooks();

            found = true;

            cout<<"\n-----=====-----=====-----=====-----\n";
            cout<<"         BOOK DELETED SUCCESSFULLY!";
            cout<<"\n-----=====-----=====-----=====-----\n";
            cout<<"\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    if (found == false)
    {
        cout<<"\nBook not found.\n";
        cout<<"\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }
}

void borrowBook()
{
    int searchId;
    bool found = false;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              BORROW BOOK\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\nEnter Book ID: ";
    cin>>searchId;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            found = true;

            if (books[i].borrower != "")
            {
                cout<<"\nThis book is already borrowed.\n";
            }
            else
            {
                cin.ignore();

                cout<<"Enter Borrower's Name: ";
                getline(cin, books[i].borrower);

                saveBooks();

                cout<<"\n-----=====-----=====-----=====-----\n";
                cout<<"      BOOK BORROWED SUCCESSFULLY!";
                cout<<"\n-----=====-----=====-----=====-----\n";

            }
            cout<<"\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    if (found == false)
    {
        cout<<"\nBook not found.\n";
        cout<<"\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }
}

void returnBook()
{
    int searchId;
    bool found = false;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              RETURN BOOK\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\nEnter Book ID: ";
    cin>>searchId;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == searchId)
        {
            found = true;

            if (books[i].borrower == "")
            {
                cout<<"\nThis book is not borrowed.\n";
            }
            else
            {
                cout<<"\nBorrowed by: "<<books[i].borrower;

                books[i].borrower = "";

                saveBooks();

                cout<<"\n\n-----=====-----=====-----=====-----\n";
                cout<<"      BOOK RETURNED SUCCESSFULLY!";
                cout<<"\n-----=====-----=====-----=====-----\n";
            }
            cout<<"\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    if (found == false)
    {
        cout<<"\nBook not found.\n";
        cout<<"\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }
}

void sortBooks()
{
    int choice;
    system("cls");

    cout<<"\n-----=====-----=====-----=====-----\n";
    cout<<"              SORT BOOKS\n";
    cout<<"-----=====-----=====-----=====-----\n";

    cout<<"\n[1] Sort by Title";
    cout<<"\n[2] Sort by Year";
    cout<<"\n[3] Sort by Book ID";
    cout<<"\n[4] Sort by Author";
    cout<<"\n[0] Back to Menu";

    cout<<"\n\nEnter your choice: ";
    cin>>choice;

   if (choice == 0)
    {
        return;
    }

    for (int i = 0; i < bookCount - 1; i++)
    {
        for (int j = 0; j < bookCount - i - 1; j++)
        {
            switch (choice)
            {
                case 1:
                    if (books[j].title > books[j + 1].title)
                    {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                    break;

                case 2:
                    if (books[j].year > books[j + 1].year)
                    {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                    break;

                case 3:
                    if (books[j].id > books[j + 1].id)
                    {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                    break;

                case 4:
                    if (books[j].author > books[j + 1].author)
                    {
                        Book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                    break;

                default:
                    cout<<"\nInvalid choice!\n";
                    cout<<"\nPress ENTER to continue...";
                    cin.ignore();
                    cin.get();
                    return;
            }
        }
    }

    saveBooks();

    cout<<"\nBooks sorted successfully!\n";
    cout<<"\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void saveBooks()
{
    ofstream file("books.txt");

    for (int i = 0; i < bookCount; i++)
    {
        file<<books[i].id<<endl;
        file<<books[i].title<<endl;
        file<<books[i].author<<endl;
        file<<books[i].year<<endl;
        file<<books[i].borrower<<endl;
    }

    file.close();
}

void loadBooks()
{
    ifstream file("books.txt");

    if (!file)
    {
        return;
    }

    while (bookCount < 100 && file>>books[bookCount].id)
    {
        file.ignore();

        getline(file, books[bookCount].title);
        getline(file, books[bookCount].author);

        file>>books[bookCount].year;
        file.ignore();

        getline(file, books[bookCount].borrower);

        if (books[bookCount].id >= nextId)
        {
            nextId = books[bookCount].id + 1;
        }

        bookCount++;
    }

    file.close();
}

//
/*
    ==========================================
              LIBRARY SYSTEM REVIEWER
    ==========================================

    1. STRUCT
       struct Book
       {
           int id;
           string title;
           string author;
           int year;
           string borrower;
       };

       - Pinagsasama ang related variables sa isang data type.
       - Ginagamit para sa details ng bawat book.


    2. GLOBAL ARRAY
       Book books[100];
       int bookCount = 0;
       int nextId = 1;

       - books[100] can store up to 100 books.
       - bookCount counts kung ilan na ang books.
       - nextId assigns a unique ID sa bawat bagong book.


    3. NESTED LOOP
       for (int i = 0; i < bookCount; i++)
       {
           for (int j = 0; j < bookCount - 1; j++)
           {
               // Code here
           }
       }

       - Loop inside another loop.
       - Ginagamit sa Bubble Sort para mag-compare ng books.


    4. BUBBLE SORT
       Book temp = books[j];
       books[j] = books[j + 1];
       books[j + 1] = temp;

       - Nagpapalitan ng position ang dalawang book records.
       - temp temporarily stores a record habang nag-swap.


    5. LINEAR SEARCH
       bool found = false;

       for (int i = 0; i < bookCount; i++)
       {
           if (books[i].id == searchId)
           {
               found = true;
               break;
           }
       }

       - Isa-isang chine-check ang records hanggang mahanap ang ID.
       - break stops the loop kapag nakita na ang hinahanap.


    6. SWITCH STATEMENT
       switch (choice)
       {
           case 1:
               addBook();
               break;

           case 2:
               viewBooks();
               break;
       }

       - Nagdedecide kung anong function ang ie-execute
         base sa piniling menu option.


    7. FILE OUTPUT
       ofstream file("books.txt");

       - Ginagamit para magsulat o mag-save ng data sa file.
       - Dito sine-save ang book records.


    8. FILE INPUT
       ifstream file("books.txt");

       - Ginagamit para magbasa ng data mula sa file.
       - Dito nilo-load ang previously saved records.


    9. WHILE LOOP
       while (file >> books[bookCount].id)
       {
           // Read remaining book details
       }

       - Paulit-ulit na nagbabasa ng records hanggang maubos
         ang laman ng file.


    10. GETLINE
        getline(cin, books[bookCount].title);

        - Binabasa ang buong input kasama ang spaces.
        - Example: "The Great Gatsby".


    11. DO-WHILE LOOP
        do
        {
            // Display menu
        }
        while (choice != 0);

        - Inuulit ang menu habang hindi pinipili ang 0 (Exit).


    12. IF-ELSE
        if (books[i].borrower == "")
        {
            cout << "Available";
        }
        else
        {
            cout << "Borrowed";
        }

        - Chine-check kung available o borrowed ang isang book.
        - Empty borrower means available ang book.


    13. FUNCTION
        void addBook()

        - Isang block of code na may specific task.
        - Nakakatulong para hindi pagsamahin lahat ng code sa main().


    14. RETURN
        return;

        - Ginagamit para agad tapusin ang isang function.


    15. CIN.IGNORE() AND CIN.GET()
        cin.ignore();
        cin.get();

        - cin.ignore() removes the remaining newline.
        - cin.get() waits hanggang mag-press ng ENTER ang user.

    ==========================================
*/
