#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <time.h>
#include <assert.h>


void greetings(void);
void fileExist(void);
void printAdvice(int nCharacters);
void logFile(char *fileName, int pswLenght);                              
void generatePsw(int lenght);
int config(void);
bool choice(void);


void fileExist(void)
{
    /*if(command != 2)
    {
        printf("Usage:%s fileName \n",progName);
        exit(EXIT_FAILURE);
    }
    file = fopen(fileName,"a");
    if(file == NULL)
    {
        printf("%s Can't be opened ",fileName);
        exit(EXIT_FAILURE);

    }*/
}

void greetings(void)
{
    printf("Welcome to password generator\n");
    printf("Insert number of characters required "
    "for the psw: ");
}

void printAdvice(int nCharacters)
{
    if (nCharacters < 0 || nCharacters == 0)
    {
        while (nCharacters <= 0)
        {
            fprintf(stderr,"The password lenght should be "
            "at least 1 character long, for maximum security "
            "is preferable at least 8 characters\n");
            fprintf(stderr, "Please reinsert the lenght of the password: ");
            scanf("%d",&nCharacters);
        }
    }

}

bool choice(void)
{
    int inpValue;
    printf("If you are ok with you choices press 1 else press 0: ");
    scanf("%d",&inpValue);
    return inpValue == 1 ? true : false;
}

int config(void){
 
    int pswLenght = 0;
    bool confirmation = true;

    greetings();
    scanf("%d",&pswLenght);
    printAdvice(pswLenght);
    confirmation = choice();
    
    while(confirmation == false)
    {
        pswLenght = 0;
        greetings();
        scanf("%d",&pswLenght);
        printAdvice(pswLenght);
        confirmation = choice();
        //config();
    }
    return pswLenght;
}

//insert and pass to funtion int nmbrPsw to print the psw to the file
void logFile(char *fileName,  int pswLenght){
    FILE *file;
    file = fopen(fileName,"a");
    fprintf(file, "Log:\n\tdate:\n\tpassword lenght: %d\n", pswLenght);
    fclose(file);
}

void generatePsw(int lenght)
{
    int databaseRandIndex;
    char database[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f',
    'g','h','j','k','l','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U',
    'I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',
    '?','!','$'};
    srand(time(NULL));
    databaseRandIndex = rand() % 52;
}


int main(int argc, char *argv[]){
    int pswLenght;
    //pswLenght = config();
    //logFile(argv[1],pswLenght);
    generatePsw(pswLenght);
    return 0;
}