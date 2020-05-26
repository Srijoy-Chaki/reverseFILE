#include<stdio.h>
#include<errno.h>
long count(FILE*);
int main()
{
    int i;
    long int c;
    char ch1,ch2;
    FILE *fptr1,*fptr2;
    if(fptr1=fopen("source.txt","r"))
    {

        printf("The has been opened.\n");
        fptr2=fopen("target.txt","w");
        c=count(fptr1);
        fseek(fptr1,-1L,2);
        printf("Number of characters to be copied: %d\n",ftell(fptr1));
        while(c)
        {
            ch1=fgetc(fptr1);
            fputc(ch1,fptr2);
            fseek(fptr1,-2L,1);
            c--;
        }
        printf("\nFILE copied successfully in reverse order");
    }
    else
    {
        perror("Error occured\n");
    }
    fclose(fptr1);
    fclose(fptr2);
}
long count(FILE*f)
{
    fseek(f,-1L,2);
    long last_pos=ftell(f);
    last_pos++;
    return last_pos;
}
