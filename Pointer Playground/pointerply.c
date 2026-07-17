#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int num1, num2, n, i;
    int arr[100];
    int *ptr;

    // Memory Address and Dereferencing
    printf("Enter a number: ");
    scanf("%d", &num1);

    ptr = &num1;

    printf("\nValue of num1 = %d\n", num1);
    printf("Address of num1 = %p\n", ptr);
    printf("Value using pointer = %d\n", *ptr);

    // Swapping using pointers
    printf("\nEnter two numbers to swap: ");
    scanf("%d%d", &num1, &num2);

    printf("Before Swap: %d %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After Swap : %d %d\n", num1, num2);

    // Array Traversal using pointers
    printf("\nEnter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("\nArray Elements using Pointer:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Pointer Arithmetic
    printf("\n\nPointer Arithmetic:\n");

    ptr = arr;

    for(i = 0; i < n; i++)
    {
        printf("Address: %p  Value: %d\n", (ptr + i), *(ptr + i));
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}