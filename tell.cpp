#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#define size 20
using namespace std;
const string filename = "meow.txt";
struct tt
{
    string f_name;
    string l_name;
    int phone = 0;
} Contacts[size];
void backUpStart()
{
    try
    {
        ifstream myFile(filename, ios::in);
        if (myFile.is_open())
        {
            cout << "File opened successfully." << endl;
            for (int i = 0; i < size; i++)
            {
                myFile >> Contacts[i].f_name;
                myFile >> Contacts[i].l_name;
                myFile >> Contacts[i].phone;
            }
            cout << "Data will be transferred successfully.\n";
            system("pause");
        }
        else
        {
            myFile.close();
            throw new exception;
        }
    }
    catch (...)
    {
        cout << "file not find.\n";
        system("pause");
    }
}

bool find(int i)
{

    if (Contacts[i].phone != 0)
        return true;
    else
        return false;
}

int find(void)
{
    for (int i = 0; i < size; i++)
    {
        if (Contacts[i].phone == 0)
            return i;
    }
    return -1;
}
void backUpEnd()
{
    ofstream myFile(filename, ios::out);
    for (int i = 0; i < size; i++)
    {
        if (find(i))
        {   
            cout<<"contact found ;-)";
            myFile << Contacts[i].f_name<<endl;
            myFile << Contacts[i].l_name<<endl;
            myFile << Contacts[i].phone<<endl;
        }
        else
            continue;
    }
    system("pause");
    myFile.close();
}
void add(int i)
{
    system("cls");
    cin.get();
    cout << "Please enter first name:";
    getline(cin, Contacts[i].f_name);
    cout << "Please enter last name:";
    getline(cin, Contacts[i].l_name);
    cout << "Please enter Phone:";
    cin >> Contacts[i].phone;
}
int menu(void)
{
    int z;
    system("cls");
    cout << "1)Add Contacts......" << endl;
    cout << "2)Delete Contacts......" << endl;
    cout << "3)search Contacts......" << endl;
    cout << "4)show Contacts......" << endl;
    cout << "5)exit.........." << endl;
    cout << "----------------------------------" << endl;
    cout << "please Select:";
    cin >> z;
    return z;
}
void show(void)
{
    system("cls");
    cout << left << setw(20) << "First name" << setw(20) << "last name" << setw(20) << "phone" << endl;
    cout << "************************************************" << endl;
    for (int i = 0; i < size; i++)
        if (Contacts[i].phone != 0)
            cout << left << setw(20) << Contacts[i].f_name << setw(20) << Contacts[i].l_name << setw(20) << Contacts[i].phone << endl;
    system("pause");
}
// func overLoding =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-===-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void show(int a)
{
    system("cls");
    cout << left << setw(20) << "First name" << setw(20) << "last name" << setw(20) << "phone" << endl;
    cout << "************************************************" << endl;
    cout << left << setw(20) << Contacts[a].f_name << setw(20) << Contacts[a].l_name << setw(20) << Contacts[a].phone << endl;
}

void searchContacts()
{
    string bin;
    bool find = false;
    int chose;

    cout << "what are you searching (1>name/2>last_name/3>phone_number): ";
    cin >> chose;

    switch (chose)
    {
    case 1:
        cout << "enter first_name: ";
        cin >> bin;
        for (int i = 0; i < size; i++)
            if (bin == Contacts[i].f_name)
            {
                show(i);
                find = true;
                break;
            }

        break;
    case 2:
        cout << "enter last_name: ";
        cin >> bin;
        for (int i = 0; i < size; i++)
            if (bin == Contacts[i].l_name)
            {
                show(i);
                find = true;
                break;
            }

        break;
    case 3:
        cout << "enter phone_number: ";
        cin >> chose;
        for (int i = 0; i < size; i++)
            if (chose == Contacts[i].phone)
            {
                show(i);
                find = true;
                break;
            }

        break;

    default:
        break;
    }

    if (!find)
        cout << "Contact not found...\n";

    system("pause");
}

void DeleteContacts()
{
    string bin;
    bool find = false;
    int chose;

    cout << "what are you searching (1>name/2>last_name/3>phone_number): ";
    cin >> chose;

    switch (chose)
    {
    case 1:
        cout << "enter first_name: ";
        cin >> bin;
        for (int i = 0; i < size; i++)
            if (bin == Contacts[i].f_name)
            {
                show(i);
                find = true;
                cout << "\nis it your what your are looking  for delete(1>yes/2>no)?";
                cin >> chose;
                if (chose == 1)
                    Contacts[i].phone = 0;
            }
    
        break;
    case 2:
        cout << "enter last_name: ";
        cin >> bin;
        for (int i = 0; i < size; i++)
            if (bin == Contacts[i].l_name)
            {
                show(i);
                find = true;
                cout << "\nis it your what your are looking  for delete(1>yes/2>no)?";
                cin >> chose;
                if (chose == 1)
                    Contacts[i].phone = 0;
            }
        break;

    case 3:
        cout << "enter phone_number: ";
        cin >> chose;
        for (int i = 0; i < size; i++)
            if (chose == Contacts[i].phone)
            {
                show(i);
                find = true;
                cout << "\nis it your what your are looking  for delete(1>yes/2>no)?";
                cin >> chose;
                if (chose == 1)
                    Contacts[i].phone = 0;
            }

        break;
    default:
        break;
    }

    if (!find)
        cout << "Contact not found...\n";

    system("pause");
}

int main()
{
    backUpStart();
    int z, i;
    while (true)
    {
        z = menu();
        switch (z)
        {
        case 1:
            i = find();
            if (i == -1)
            {
                cout << "storage is Full......" << endl;
                system("pause");
            }
            else
                add(i);
            backUpEnd();
            break;
        case 2:
            DeleteContacts();
            break;
        case 3:
            searchContacts();
            break;
        case 4:
            show();
            break;

        case 5:
            backUpEnd();
            exit(0);
            break;

        default:
            cout << "Please try again......";
            system("pause");
            break;
        }
    }

    return 0;
}
