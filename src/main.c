#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>



int config(void);
void openCreateFile(char *fileName,  int pswLenght);
//void generatePsw();


int config(void){
 
    int pswLenght = 0;
    
    printf("Welcome to password generator\n");
    printf("Insert number of characters required "
    "for the psw: ");
    scanf("%d",&pswLenght);
    
    if (pswLenght < 0 || pswLenght == 0)
    {
        while (pswLenght <= 0)
        {
            fprintf(stderr,"The password lenght should be "
            "at least 1 character long, for maximum security "
            "is preferable at least 8 characters\n");
            fprintf(stderr, "Please reinsert the lenght of the password: ");
            scanf("%d",&pswLenght);
        }
    }
    return pswLenght;

}

void openCreateFile(char *fileName,  int pswLenght){
    FILE *file;
    file = fopen(fileName,"a");
    
    if(file == NULL)
    {
        fprintf(stderr, "Generated %s",fileName);
        file = fopen(fileName,"w");
        file = fopen(fileName,"a+");
    }

    fprintf(file, "Log:\n\tpassword lenght: %d\n", pswLenght);
    fclose(file);
}


int main(int argc, char *argv[]){
    int pswLenght = 0;
    pswLenght = config();
    printf("value = %d \n",pswLenght);
    openCreateFile(argv[1],pswLenght);
}