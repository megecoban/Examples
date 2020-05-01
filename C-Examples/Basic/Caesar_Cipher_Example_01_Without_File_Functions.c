#include <stdio.h>
#include <stdlib.h>

char inputLP[100];
char encryptedText[100];
char decryptedText[100];
char normalText[100];
int userInput;
int lockpickVar;


int main()
{
    printf("Please Enter A LockPick: ");
    scanf("%s", &inputLP);
    lockpickVar = atoi(inputLP);

    while(1==1)
    {
        printf("\n\tPlease select an action: \n\n\t1 - Encrypt\n\t2 - Decrypt\n\n\t[INPUT]: ");
        scanf("%d", &userInput);
        if(userInput==1)
        {
            encryptF(lockpickVar);
        } else if(userInput==2)
        {
            decryptF(lockpickVar);
        }
        printf("\n");
        for(int a=0; a<50; a++)
        {
            printf("==");
        }
    }
}

void encryptF(int lockpickVar)
{
    printf("\n\tPlease Enter The Text (Which Text Do You Want To Be Encrypt): ");
    scanf("%s", &normalText);
    for(int i=0; i<sizeof(normalText); i++)
    {
        if(normalText[i]==NULL)
            break;
        encryptedText[i] = (char)((int)normalText[i]+(int)lockpickVar); //Encrypting
    }
    printf("\n\tEncrypted Text: %s", encryptedText);
    getch();
}

void decryptF(int lockpickVar)
{
    printf("\n\tPlease Enter The Text (Which Text Do You Want To Be Decrypt): ");
    scanf("%s", &encryptedText);
    for(int i=0; i<sizeof(encryptedText); i++)
    {
        if(encryptedText[i]==NULL)
            break;
        decryptedText[i] = (char)((int)encryptedText[i]-(int)lockpickVar); //Decrypting
    }
    printf("\n\tDecrypted Text: %s", decryptedText);
    getch();
}
