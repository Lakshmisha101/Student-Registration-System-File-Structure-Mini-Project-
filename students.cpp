#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
class student
{
private:
    string name, usn, course, address, email_id;
    long long int contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();

    
    void deleted();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT REGISTERATION SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Add New Student Record" << endl;
    cout << "\t\t\t 2. Display Student Record" << endl;
    cout << "\t\t\t 3. Modify Student Record" << endl;
    cout << "\t\t\t 4. Search Student Record" << endl;
    cout << "\t\t\t 5. Delete Student Record" << endl;
    cout << "\t\t\t 6. Exit\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}
void student::insert() 
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Usn: ";
    cin >> usn;
    cout << "\t\t\tEnter Branch: ";
    cin >> course;
email:
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }
contact:
    cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << usn << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display() 
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> usn>> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tUsn: " << usn<< "\n";
            cout << "\t\t\tBranch: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            file >> name >> usn >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void student::modify() 
{
    system("cls");
    fstream file, file1;
    string Usn;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Usn of Student which you want to Modify: ";
        cin >> Usn;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> usn>> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (Usn != usn)
                file1 << " " << name << " " << usn << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                int choice;
                cout << "\n\t\t\tWhat do you want to modify?" << endl;
                cout << "\t\t\t1. Name" << endl;
                cout << "\t\t\t2. Usn" << endl;
                cout << "\t\t\t3. Course" << endl;
                cout << "\t\t\t4. Email ID" << endl;
                cout << "\t\t\t5. Contact No." << endl;
                cout << "\t\t\t6. Address" << endl;
                cout << "\t\t\tEnter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\t\t\tEnter Name: ";
                    cin >> name;
                    break;
                case 2:
                    cout << "\t\t\tEnter Usn: ";
                    cin >> usn;
                    break;
                case 3:
                    cout << "\t\t\tEnter Branch: ";
                    cin >> course;
                    break;
                case 4:
                    cout << "\t\t\tEnter Email ID: ";
                    cin >> email_id;
                    break;
                case 5:
                    cout << "\t\t\tEnter Contact No.: ";
                    cin >> contact_no;
                    break;
                case 6:
                    cout << "\t\t\tEnter Address: ";
                    cin >> address;
                    break;
                default:
                    cout << "\t\t\tInvalid Choice..." << endl;
                    break;
                }
                cout << "\n\t\t\tStudent record modified successfully.";
                file1 << " " << name << " " << usn << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> usn >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Usn Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() 
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string Usn;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Usn of Student which you want to search: ";
        cin >> Usn;
        file >> name >> usn >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (Usn == usn)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tUsn: " << usn << "\n";
                cout << "\t\t\tBranch: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }

            file >> name >> usn >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Usn Not Found....";
            }
        }
        file.close();
    }
}
void student::deleted() 
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string Usn;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Usn of Student which you want Delete Data: ";
        cin >> Usn;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> usn >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (Usn !=usn)
            {
                file1 << " " << name << " " << usn << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted The Data";
            }
            file >> name >> usn >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Usn Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();  
    return 0;
}
