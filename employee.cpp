#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

struct Employee
{
        int id;
        string name;
        string designation;
        float salary;
};

void addEmployee()
{
        Employee emp;
        cout << "Enter Employee ID: ";
        cin >> emp.id;
        cout << "Enter Name: ";
        cin >> emp.name;
        cout << "Enter Designation: ";
        cin >> emp.designation;
        cout << "Enter Salary: ";
        cin >> emp.salary;

        ofstream out("employee.txt", ios::app);
        if (out.is_open())
        {
                out << emp.id << " " << emp.name << " " << emp.designation << " " << emp.salary << "\n";
                out.close();
                cout << "Employee added successfully!\n";
        }
        else
        {
                cout << "Error opening file.\n";
        }
}

void searchEmployee(int searchId)
{
        ifstream in("employee.txt");
        bool found = false;
        Employee emp;

        while (in >> emp.id >> emp.name >> emp.designation >> emp.salary)
        {
                if (emp.id == searchId)
                {
                        cout << "Employee Found:\n";
                        cout << "ID: " << emp.id << "\nName: " << emp.name
                             << "\nDesignation: " << emp.designation << "\nSalary: " << emp.salary << endl;
                        found = true;
                        break;
                }
        }
        in.close();
        if (!found)
        {
                cout << "Employee with ID " << searchId << " not found.\n";
        }
}

void deleteEmployee(int deleteId)
{
        ifstream in("employee.txt");
        ofstream temp("temp.txt");
        Employee emp;
        bool found = false;

        while (in >> emp.id >> emp.name >> emp.designation >> emp.salary)
        {
                if (emp.id == deleteId)
                {
                        found = true; // Skip writing this employee
                }
                else
                {
                        temp << emp.id << " " << emp.name << " " << emp.designation << " " << emp.salary << "\n";
                }
        }

        in.close();
        temp.close();

        remove("employee.txt");
        rename("temp.txt", "employee.txt");

        if (found)
        {
                cout << "Employee deleted successfully.\n";
        }
        else
        {
                cout << "Employee with ID " << deleteId << " not found.\n";
        }
}

int main()
{
        int choice, id;

        do
        {
                cout << "\n--- Employee Management System ---\n";
                cout << "1. Add Employee\n";
                cout << "2. Search Employee\n";
                cout << "3. Delete Employee\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                        addEmployee();
                        break;
                case 2:
                        cout << "Enter Employee ID to search: ";
                        cin >> id;
                        searchEmployee(id);
                        break;
                case 3:
                        cout << "Enter Employee ID to delete: ";
                        cin >> id;
                        deleteEmployee(id);
                        break;
                case 4:
                        cout << "Exiting...\n";
                        break;
                default:
                        cout << "Invalid choice. Try again.\n";
                }
        } while (choice != 4);

        return 0;
}
