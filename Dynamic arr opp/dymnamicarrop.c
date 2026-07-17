#include <stdio.h>
#include <stdlib.h>

int *arr;
int n = 0, size;
int choice, i, j, pos, value, key, found;

void insert();
void deleteElement();
void update();
void display();
void linearSearch();
void binarySearch();
void sort();

int main()
{
    printf("Enter Array Size: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    do
    {
        printf("\n===== Dynamic Array Operations =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Linear Search\n");
        printf("6. Sort Array\n");
        printf("7. Binary Search\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                update();
                break;
            case 4:
                display();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                sort();
                break;
            case 7:
                binarySearch();
                break;
            case 8:
                free(arr);
                printf("Memory Released.\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
}

void insert()
{
    if(n == size)
    {
        printf("Array is Full!\n");
        return;
    }

    printf("Enter Element: ");
    scanf("%d", &value);

    arr[n] = value;
    n++;

    printf("Element Inserted.\n");
}

void deleteElement()
{
    printf("Enter Position (1-%d): ", n);
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid Position!\n");
        return;
    }

    for(i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Element Deleted.\n");
}

void update()
{
    printf("Enter Position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid Position!\n");
        return;
    }

    printf("Enter New Value: ");
    scanf("%d", &arr[pos - 1]);

    printf("Element Updated.\n");
}

void display()
{
    if(n == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    printf("Array Elements: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void linearSearch()
{
    printf("Enter Element to Search: ");
    scanf("%d", &key);

    found = 0;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Found at Position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Element Not Found.\n");
}

void sort()
{
    int temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array Sorted.\n");
}

void binarySearch()
{
    int low = 0, high = n - 1, mid;

    printf("Enter Element to Search: ");
    scanf("%d", &key);

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("Found at Position %d\n", mid + 1);
            return;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Element Not Found.\n");
}