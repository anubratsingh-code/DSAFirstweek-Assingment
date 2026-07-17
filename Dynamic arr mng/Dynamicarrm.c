#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *marks;
    int total = 0, highest, lowest;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    marks = (int *)malloc(n * sizeof(int));

    if (marks == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter student marks:\n");
    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nStudent Marks:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }

    highest = lowest = marks[0];

    for(i = 0; i < n; i++)
    {
        total += marks[i];

        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];
    }

    average = (float)total / n;

    printf("\n\nTotal Marks = %d", total);
    printf("\nAverage Marks = %.2f", average);
    printf("\nHighest Marks = %d", highest);
    printf("\nLowest Marks = %d", lowest);

    // Free allocated memory
    free(marks);

    printf("\n\nMemory Released Successfully.\n");

    return 0;
}