#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient p[MAX];

int n = 0;
int i, j, id;
int choice;

void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();

int main()
{
    do
    {
        printf("\n===== Hospital Patient Management =====\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
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

void addPatient()
{
    printf("Enter Patient ID: ");
    scanf("%d", &p[n].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p[n].name);

    printf("Enter Age: ");
    scanf("%d", &p[n].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p[n].disease);

    n++;

    printf("Patient Added Successfully.\n");
}

void displayPatients()
{
    if(n == 0)
    {
        printf("No Patient Records.\n");
        return;
    }

    printf("\nID\tName\t\tAge\tDisease\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t%s\n",
        p[i].id,
        p[i].name,
        p[i].age,
        p[i].disease);
    }
}

void searchPatient()
{
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID : %d\n", p[i].id);
            printf("Name : %s\n", p[i].name);
            printf("Age : %d\n", p[i].age);
            printf("Disease : %s\n", p[i].disease);
            return;
        }
    }

    printf("Patient Not Found.\n");
}

void updatePatient()
{
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", p[i].name);

            printf("Enter New Age: ");
            scanf("%d", &p[i].age);

            printf("Enter New Disease: ");
            scanf(" %[^\n]", p[i].disease);

            printf("Record Updated Successfully.\n");
            return;
        }
    }

    printf("Patient Not Found.\n");
}

void deletePatient()
{
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            for(j = i; j < n - 1; j++)
            {
                p[j] = p[j + 1];
            }

            n--;

            printf("Record Deleted Successfully.\n");
            return;
        }
    }

    printf("Patient Not Found.\n");
}