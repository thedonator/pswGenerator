#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>


void greetings(void);
void printWarning(void);
void createPsw(int lenght, int pswId);
void pswOutput(int pswLenght,int repetition);
int printAdvice(int pswCharacters);                            
int config(void);
bool choice(void);


void greetings(void)
{
    printf("Insert number of characters required "
    "for the psw:");
}


void printWarning(void)
{
    fprintf(stderr, "The password lenght should be "
    "at least 10 character long, for maximum security "
    "is preferable at least 10 characters\n");
    fprintf(stderr, "Please reinsert the lenght of the password: ");
}


void createPsw(int lenght,int pswId)
{
    int databaseRandIndex = 0;
    char *password;
    char database[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f',
    'g','h','j','k','l','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U',
    'I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',
    '?','!','$','1','2','3','4','5','6','7','8','9','0'};

    password=malloc(lenght);
    srand(time(NULL));  
    
    for(size_t i=0;i<lenght;i++)
    {
        databaseRandIndex = rand() % 65;
        password[i]=database[databaseRandIndex];
    }
    printf("Password [%d]:%s\n\n",pswId, password);
}


void pswOutput(int pswLenght,int repetition)
{
    for (size_t i = 0; i < repetition; i++)
    {
        createPsw(pswLenght,i);
        sleep(1);
    }
}


int printAdvice(int pswCharacters)
{
    if (pswCharacters < 10 || pswCharacters == 0)
    {
        while (pswCharacters < 10)
        {
            printWarning();
            scanf("%d",&pswCharacters);
        }
    }
    return pswCharacters;
}


int config(void){
    int pswLenght = 0;
    bool confirmation = true;

    greetings();
    scanf("%d",&pswLenght);
    pswLenght = printAdvice(pswLenght);
    confirmation = choice();
    
    while(confirmation == false)
    {
        pswLenght = 0;
        greetings();
        scanf("%d",&pswLenght);
        pswLenght = printAdvice(pswLenght);
        confirmation = choice();
    }
    return pswLenght;
}


bool choice(void)
{
    int inpValue;
    printf("If you are ok with you choices press 1 else press 0:");
    scanf("%d",&inpValue);
    return inpValue == 1 ? true : false;
}


int main(){
    int pswLenght = 0;
    int numbrPassword =0;
    bool accept = false;
    printf("\n\n\t\tWELCOME TO PASSWORD GENERATOR\n\n");
    printf("insert the number of passwords you want to create:");
    scanf("%d",&numbrPassword);
    accept = choice();
    if(accept == false)
    {
        while (accept == false)
        {
            printf("insert the number of passwords you want to create:");
            scanf("%d",&numbrPassword);
            accept = choice();          
        }
    }
    
    if(numbrPassword <=0)
    {
        while (numbrPassword <=0)
        {
            printf("You have to generate at least one password,please reinsert:");
            scanf("%d",&numbrPassword);            
        }
        
    }
    pswLenght = config();
    pswOutput(pswLenght,numbrPassword);
    return 0;
}