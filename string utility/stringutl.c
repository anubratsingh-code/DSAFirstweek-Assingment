#include <stdio.h>
#include <string.h>

#define MAX 100

void findLength(char str[]);
void reverseString(char str[]);
void checkPalindrome(char str[]);
void countVowels(char str[]);
void countDigits(char str[]);
void countSpaces(char str[]);
void characterFrequency(char str[]);

int main()
{
    char str[MAX];
    int choice;

    printf("===== String Utility Toolkit =====\n");
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Find Length\n");
        printf("2. Reverse String\n");
        printf("3. Check Palindrome\n");
        printf("4. Count Vowels\n");
        printf("5. Count Digits\n");
        printf("6. Count Spaces\n");
        printf("7. Character Frequency\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                findLength(str);
                break;

            case 2:
                reverseString(str);
                break;

            case 3:
                checkPalindrome(str);
                break;

            case 4:
                countVowels(str);
                break;

            case 5:
                countDigits(str);
                break;

            case 6:
                countSpaces(str);
                break;

            case 7:
                characterFrequency(str);
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

void findLength(char str[])
{
    printf("Length of String = %lu\n", strlen(str));
}

void reverseString(char str[])
{
    int len = strlen(str);

    printf("Reversed String = ");

    for(int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");
}

void checkPalindrome(char str[])
{
    int i, len = strlen(str);
    int flag = 1;

    for(i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is NOT a Palindrome.\n");
}

void countVowels(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            count++;
        }
    }

    printf("Number of Vowels = %d\n", count);
}

void countDigits(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }

    printf("Number of Digits = %d\n", count);
}

void countSpaces(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            count++;
        }
    }

    printf("Number of Spaces = %d\n", count);
}

void characterFrequency(char str[])
{
    int freq[256] = {0};

    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequency:\n");

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            printf("%c : %d\n", i, freq[i]);
        }
    }
}