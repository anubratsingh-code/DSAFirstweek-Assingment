#include <stdio.h>

#define MAX 100

struct Employee
{
    int id;
    char name[50];
    float basic, hra, da, tax, gross, net;
};

struct Employee emp[MAX];

int n = 0;
int choice, i, j, id;
struct Employee temp;

void addEmployee();
void displayEmployees();
void sortSalary();

int main()
{
    do
    {
        printf("\n===== Employee Payroll System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Salary Report\n");
        printf("3. Sort by Net Salary\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                sortSalary();
                break;

            case 4:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void addEmployee()
{
    printf("Enter Employee ID: ");
    scanf("%d", &emp[n].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[n].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[n].basic);

    emp[n].hra = emp[n].basic * 0.20;
    emp[n].da  = emp[n].basic * 0.10;

    if(emp[n].basic > 50000)
        emp[n].tax = emp[n].basic * 0.10;
    else
        emp[n].tax = emp[n].basic * 0.05;

    emp[n].gross = emp[n].basic + emp[n].hra + emp[n].da;
    emp[n].net = emp[n].gross - emp[n].tax;

    n++;

    printf("Employee Added Successfully.\n");
}

void displayEmployees()
{
    if(n == 0)
    {
        printf("No Records Found.\n");
        return;
    }

    printf("\nID\tName\tBasic\tHRA\tDA\tTax\tGross\tNet\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
        emp[i].id,
        emp[i].name,
        emp[i].basic,
        emp[i].hra,
        emp[i].da,
        emp[i].tax,
        emp[i].gross,
        emp[i].net);
    }
}

void sortSalary()
{
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(emp[j].net > emp[j + 1].net)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    printf("Employees Sorted by Net Salary.\n");
    displayEmployees();
}