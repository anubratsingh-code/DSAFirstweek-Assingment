#include <stdio.h>

int arr[100], n;
int i, j, temp, key, found;

void input();
void display();
void largestSmallest();
void reverse();
void removeDuplicates();
void frequency();
void linearSearch();
void sortArray();

int main()
{
    int choice;

    input();

    do
    {
        printf("\n===== LeetCode Array Challenge =====\n");
        printf("1. Display Array\n");
        printf("2. Largest, Second Largest, Smallest, Second Smallest\n");
        printf("3. Reverse Array\n");
        printf("4. Remove Duplicates\n");
        printf("5. Count Frequency\n");
        printf("6. Linear Search\n");
        printf("7. Sort Array\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display();
                break;

            case 2:
                largestSmallest();
                break;

            case 3:
                reverse();
                break;

            case 4:
                removeDuplicates();
                break;

            case 5:
                frequency();
                break;

            case 6:
                linearSearch();
                break;

            case 7:
                sortArray();
                break;

            case 8:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
}

void input()
{
    printf("Enter Size of Array: ");
    scanf("%d", &n);

    printf("Enter Array Elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display()
{
    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void largestSmallest()
{
    int largest, secondLargest;
    int smallest, secondSmallest;

    largest = secondLargest = arr[0];
    smallest = secondSmallest = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }

        if(arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", secondLargest);
    printf("Smallest = %d\n", smallest);
    printf("Second Smallest = %d\n", secondSmallest);
}

void reverse()
{
    printf("Reversed Array: ");

    for(i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\n");
}

void removeDuplicates()
{
    int newArr[100];
    int k = 0, duplicate;

    for(i = 0; i < n; i++)
    {
        duplicate = 0;

        for(j = 0; j < k; j++)
        {
            if(arr[i] == newArr[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(!duplicate)
        {
            newArr[k++] = arr[i];
        }
    }

    printf("Array without Duplicates: ");

    for(i = 0; i < k; i++)
        printf("%d ", newArr[i]);

    printf("\n");
}

void frequency()
{
    int visited[100] = {0};

    for(i = 0; i < n; i++)
    {
        if(visited[i])
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d occurs %d time(s)\n", arr[i], count);
    }
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
            printf("Element Found at Position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Element Not Found.\n");
}

void sortArray()
{
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

    printf("Sorted Array: ");

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}