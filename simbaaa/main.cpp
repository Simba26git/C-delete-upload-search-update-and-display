#include <iostream>
#include <string>
#include<fstream>

using namespace std;

const int maxrow = 10;

string EmpName [ maxrow]= {};
string EmpID[ maxrow] = {};

void AddRecord()
{
     char name [50];
     char empno[5];

     cin.ignore();

     cout << "Employee ID. ";
     cin.getline(empno, 5);
     cout << "Employee Name. ";
     cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
      {
        if (EmpID [x] == "\0")
      {
        EmpID[x] =empno;
        EmpName[x] = name;

        break;
      }
    }
}
void UpdateRecord(string search)
{
    char name[50];
    char empno[5];

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] == search)
        {
            counter++;

            cout<<"Employee Name. ";
            cin.getline(name, 50);

            EmpName[x] = name;

            cout << "Update Successfull!" << endl;
            cout << "===============================" << endl;
            break;
        }
    }
}
void DeleteRecord(string search)
{

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] == search)
        {
            counter++;

            EmpName[x] = "";
            EmpID[x] = "";

            cout << "Successfully Deleted!" << endl;
            cout << "===============================" << endl;
            break;
        }
    }
    if (counter == 0)
    {
        cout << "ID Number does not exist";
    }
}
void SearchRecord(string search)
{
    system("CLS");
    cout <<"Current Record(s)" << endl;
    cout <<"=============================" << endl;
    int counter = 0;

        for (int x = 0; x<maxrow; x++)
    {
        if(EmpID[x] == search)
        {
            counter++;
            cout << "    " << counter << "       " << EmpID[x] << "        " << EmpName[x] << endl;
            break;

        }
    }
    if (counter == 0)
    {
        cout <<"No Record Found!" << endl;
    }

    cout <<"===============================" << endl;
}

void ListRecord()
{
    system ("CLS");
    cout << "Current Record(s)"<< endl;
    cout << "<============================" << endl;

    int counter = 0;
    cout<< "No. |  ID   |    NAME    " << endl <<"--------------------------------\n";
    for (int x = 0; x<maxrow; x++)
    {
        if(EmpID [x] != "\0")
        {
            counter++;
            cout << "    " << counter << "       " << EmpID[x] << "        " << EmpName[x] << endl;

        }
    }

    if (counter == 0)
    {
        cout << "No Records Found!" << endl;

    }
    cout << "====================================" << endl;
}

int main ()
{
    std::cout << "MENU\n";
    int option;
    string empID;
    system("CLS");

    do{
        cout << "1-Create Records" << endl;
        cout << "2-Update Records" << endl;
        cout << "3-Delete Records" << endl;
        cout << "4-search Records" << endl;
        cout << "5-Display all Records" << endl;
        cout << "6-Exit and Save Records" << endl;
        cout << "<==========================>" << endl;

        cout << "Select option >>";
        cin >> option;

        switch (option)
        {
            case 1: AddRecord();
                  system("CLS");
                  break;
            case 2:
                cin.ignore();
                cout <<"Search by ID >>";
                getline(cin, empID);
                UpdateRecord(empID);
                break;

            case 3:
                cin.ignore();
                cout << "Delete by ID >>";
                getline(cin, empID);
                DeleteRecord(empID);
                cin.ignore();
                system("CLS");
                break;

            case 4:
                cin.ignore();
                cout <<"Search by ID >>";
                getline(cin, empID);
                SearchRecord(empID);
                break;

            case 5: ListRecord();
                  break;
        }
    } while (option !=6);
}
