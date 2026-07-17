#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int id;
    char name[50];
    float marks;
};

struct Student s[MAX];
int n = 0;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    do
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent()
{
    printf("Enter Student ID: ");
    scanf("%d", &s[n].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[n].name);

    printf("Enter Marks: ");
    scanf("%f", &s[n].marks);

    n++;

    printf("Student Added Successfully!\n");
}

void displayStudents()
{
    int i;

    if(n == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\nID\tName\t\tMarks\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\n", s[i].id, s[i].name, s[i].marks);
    }
}

void searchStudent()
{
    int id, i;

    printf("Enter Student ID to Search: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(s[i].id == id)
        {
            printf("\nRecord Found\n");
            printf("ID : %d\n", s[i].id);
            printf("Name : %s\n", s[i].name);
            printf("Marks : %.2f\n", s[i].marks);
            return;
        }
    }

    printf("Student Not Found!\n");
}

void updateStudent()
{
    int id, i;

    printf("Enter Student ID to Update: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(s[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record Updated Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

void deleteStudent()
{
    int id, i, j;

    printf("Enter Student ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(s[i].id == id)
        {
            for(j = i; j < n - 1; j++)
            {
                s[j] = s[j + 1];
            }

            n--;

            printf("Record Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}