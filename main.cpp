#include <iostream>
using namespace std;
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>

class park
{
private:
    string name, Car_no;
    int time_in;
    int time_out;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void cal();
    void deleted();
};
// Project Menu
void park::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| CAR PARKING MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Fare Calculation" << endl;
    cout << "\t\t\t 6. Delete Record" << endl;
    cout << "\t\t\t 7. Exit\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Car Record (Y, N) : ";
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
        cal();
        break;
    case 6:
        deleted();
        break;
    case 7:
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    goto menustart;
}
void park::insert() // Add student details
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Car Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Driver Name: ";
    cin >> name;
    cout << "\t\t\tEnter Car.No.: ";
    cin >> Car_no;
    cout << "\t\t\tEnter Time In: ";
    cin >> time_in;
    cout << "\t\t\tEnter Time Out: ";
    cin >> time_out;   
    file.open("CarParking.txt", ios::app | ios::out);
    file << " " << name << " " << Car_no << " " << time_in << " " << time_out <<"\n";
    file.close();
}
void park::display() // Display data of student
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Car Parking Record --------------------------------------------" << endl;
    file.open("CarParking.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> Car_no >> time_in >> time_out;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tCar TC No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tCar No.: " << Car_no << "\n";
            cout << "\t\t\tTime In: " << time_in << "\n";
            cout << "\t\t\tTime Out: " << time_out << "\n";

            file >> name >> Car_no >> time_in >> time_out ;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void park::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Car Parking Modify Details ------------------------------------------" << endl;
    file.open("CarParking.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Car No. of Student which you want to Modify: ";
        cin >> Car_no;
        file1.open("reord.txt", ios::app | ios::out);
        file >> name >> Car_no >> time_in >> time_out;
        while (!file.eof())
        {
            if (rollno != Car_no)
                file1 << " " << name << " " << Car_no << " " << time_in << " " << time_out << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Car No. : ";
                cin >> Car_no;
                cout << "\t\t\tEnter Time In: ";
                cin >> time_in;
                cout << "\t\t\tEnter Time Out: ";
                cin >> time_out;
              
                file1 << " " << name << " " << Car_no << " " << time_in << " " << time_out << " " << "\n";
                found++;
            }
            file >> name >> Car_no >> time_in >> time_out;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("CarParking.txt");
        rename("record.txt", "CarParking.txt");
    }
}

void park::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("CarParking.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Car Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string Car_no;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Car Search Table --------------------------------------------" << endl;
        cout << "\nEnter Car No. of Student which you want to search: ";
        cin >> Car_no;
        file >> name >> Car_no >> time_in >> time_out;
        while (!file.eof())
        {
            if (Car_no == Car_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tCar No.: " << Car_no << "\n";
                cout << "\t\t\tTime In: " << time_in << "\n";
                cout << "\t\t\tTime Out: " << time_out << "\n";
                found++;
            }
            file >> name >> Car_no >> time_in >> time_out;
            if (found == 0)
            {
                cout << "\n\t\t\t Car No. Not Found....";
            }
        }
        file.close();
    }
}
void park::cal() // Calculate the fare
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("CarParking.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Car Fare Calculation --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string Car_no;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Car Fare Calculation --------------------------------------------" << endl;
        cout << "\nEnter Car No. of Student which you want to Calculate the Fare: ";
        cin >> Car_no;
        file >> name >> Car_no >> time_in >> time_out;
        while (!file.eof())
        {
            if (Car_no == Car_no)
            {
                cout << "\n\n\t\t\tTotal Fare: " << (time_out-time_in)*20 << "\n";
                found++;
            }
            file >> name >> Car_no >> time_in >> time_out;
            if (found == 0)
            {
                cout << "\n\t\t\t Car No. Not Found....";
            }
        }
        file.close();
    }
}
void park::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("CarParking.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Car No.  which you want Delete from Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> Car_no >> time_in>> time_out;
        while (!file.eof())
        {
            if (roll != Car_no)
            {
                file1 << " " << name << " " << Car_no << " " << time_in << " " << time_out<< " " << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> Car_no>> time_in>> time_out;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tCar No. Not Found....";
        }
        file1.close();
        file.close();
        remove("CarParking.txt");
        rename("record.txt", "CarParking.txt");
    }
}
int main()
{
    park project; // object
    project.menu();  //object calling
} 
