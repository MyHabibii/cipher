#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* decipher function */
void decipher(char encrypted[], char key[])
{
    char message[100];
    int i, j = 0;
    int encryptedLength = strlen(encrypted);
    int keyLength = strlen(key);
    for (i = 0; i < encryptedLength; i++)
    {
        /* Resetting the index to 0 if it reaches the key length */
        if (j == keyLength)
        {
            j = 0;
        }
        /* Using the formula (c = (m + k) % 26) and adding 97 so that the encrypted word is in lower case */
        message[i] = (((toupper(encrypted[i]) - toupper(key[j]) % 26) + 26) % 26) + 97;
        /* j is a counter of where the index is pointing to for the key */
        j++;
    }

    message[i] = '\0';

    /* Printing the results */
    printf("\n***** Decipher *****\n");
    printf("enc:      %s\n", encrypted);
    printf("key:      %s\n", key);
    printf("message:  %s\n", message);
}

/* encipher function */
void encipher(char message[], char key[])
{
    char encrypted[100];
    char newKey[100];
    int i, j = 0;
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    for (i = 0; i < messageLength; i++)
    {
        /* Resetting the index to 0 if it reaches the key length */
        if (j == keyLength)
        {
            j = 0;
        }
        /* Using the formula (c = (m + k) % 26) and adding 97 so that the encrypted word is in lower case */
        encrypted[i] = ((toupper(message[i]) + toupper(key[j])) % 26) + 97;

        /* If the key was less than the message then the new key will be stored and used here */
        newKey[i] = key[j];

        /* j is a counter of where the index is pointing to for the key */
        j++;
    }

    newKey[i] = '\0';
    encrypted[i] = '\0';

    /* Printing the results */
    printf("\n***** Encipher *****\n");
    printf("message:  %s\n", message);
    printf("key:      %s\n", newKey);
    printf("enc:      %s\n", encrypted);

    /* Calling the decipher function */
    decipher(encrypted, newKey);
}

/* Check to see if the message and key is a letter */
bool checkAlpha(char array[])
{
    int i = 0;

    while (array[i] != '\0')
    {
        if (!isalpha(array[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

/* Main function */
int main()
{
    char message[100];
    char key[100];

    /* Asking user to enter a message and a key word */
    printf("\nEnter a message and keyword (letter values only): ");
    scanf("%s %s", message, key);

    message[strlen(message)] = '\0';
    key[strlen(key)] = '\0';

    /* Checking to see if user entered the correct value */
    if (checkAlpha(message) && checkAlpha(key))
    {
        encipher(message, key);
    }
    else
    {
        printf("\nMessage or Key invalid\n");
        printf("\nYou entered %s %s\n", message, key);

        /* Giving the user one more chance to enter the correct message or key word */
        printf("\nEnter a message and keyword (letter values only): ");
        scanf("%s %s", message, key);

        /* Checking to see if user entered the correct value */
        if (checkAlpha(message) && checkAlpha(key))
        {
            encipher(message, key);
        }
        else
        {
            printf("\nMessage or Key invalid\n");
            printf("\nYou entered %s %s\n", message, key);
        }
    }
    return 0;
}
