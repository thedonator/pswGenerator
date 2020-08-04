#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <time.h>
#include <assert.h>


void greetings(void);
int config(void);
void printAdvice(int nCharacters);
bool choice(void);
void openCreateFile(char *fileName,  int pswLenght);                              
//void generatePsw();

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

void openCreateFile(char *fileName,  int pswLenght){
    FILE *file;
    file = fopen(fileName,"a");
    fprintf(file, "Log:\n\tpassword lenght: %d\n", pswLenght);
    fclose(file);
}


int main(int argc, char *argv[]){
    int pswLenght;
    pswLenght = config();
    assert(pswLenght == 88);
    printf("value = %d \n",pswLenght);
    openCreateFile(argv[1],pswLenght);
    return 0;
}