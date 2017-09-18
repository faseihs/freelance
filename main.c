#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

char temp1[101];
char* getmychar(int j,int index[] ,char array[])    //function to return the word starting from the index 'j'
{

    sscanf(&array[index[j]],"%s",temp1);
    return temp1;
}

int lowcmp(char str[],char str1[])              //comparing the strings alphabetically after converting to lowercase
{
    int i,j;
    for( i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;

    }
    for( j=0;j<=strlen(str1);j++){
      if(str1[j]>=65&&str1[j]<=90)
         str1[j]=str1[j]+32;
    }
    return strcmp(str,str1);

}
int main()
{

    char text[1000];
    gets(text);


    int index[100]={0};

    int count=1;
    int i =0;
    index[0]=0;
    for(i;i<strlen(text);i++)           //finding the starting index of the unsorted array
    {
        if (text[i]==' ')
        {
            index[count]=i+1;
            count++;

        }
    }
    char s1[101];
    printf("Words and indexes(the printed words are cleaned)");
    printf("\ni\t|index[i]  |words");
    printf("\n--------|----------|------");

    for(i=0;i<count;i++)            //for loop to print the unsorted words and indices
    {

        printf("\n%d  \t  %d",i,index[i]);
        sscanf(&text[index[i]],"%s",s1);
        printf("\t     %s\n",s1);
        printf("\n--------|----------|------");

    }

    int key,j;
    char temp[101];
    for (i=1;i<count;i++)           //for loop for insertion sort
    {
        key = index[i];
        sscanf(&text[key],"%s",temp);
        j=i-1;
        while(j>=0 && lowcmp(getmychar(j,index,text),temp)>0)
        {
            index[j+1]=index[j];
            j=j-1;
        }
        index[j+1]=key;
    }

    printf("\nThe sorted data (The printed words are cleaned)");

   printf("\ni\t|index[i]  |words");
    printf("\n--------|----------|------");

    for(i=0;i<count;i++)        //for loop to print the sorted words and indices
    {

        printf("\n%d  \t  %d",i,index[i]);
        sscanf(&text[index[i]],"%s",s1);
        printf("\t     %s\n",s1);
        printf("\n--------|----------|------");

    }
	printf('\n');
    char search[100];
    gets(search);
    while (strcmp(search,"-1")!=0){                 //while loop to get the words untill -1 is entered
    char cleaned[100]="";
    if(ispunct(search[strlen(search)-1]))           //check for punctuation marks
       {
           strncpy(cleaned,search,strlen(search)-1);
       }

    else strcpy(cleaned,search);

    int l=0;
    int r=count-1;
    int iterations=0;
    int match=0;
    while (l<=r)                //while loop for binary search
    {
        int m = l + (r-l)/2;


        if (lowcmp(cleaned,getmychar(m,index,text)) == 0)
            match=1;


        if (lowcmp(cleaned,getmychar(m,index,text))> 0) {
            l = m + 1;

        }

        else {
            r = m - 1;

        }
        iterations++;
    }
    if(match==1)        //match found
    {
        printf("\n(original : %s)",search);
        printf("\ncleaned: %s - found ( %d iterations)",cleaned,iterations);
    }
    else {              //not found
      printf("(original : %s)",search);
    printf("\ncleaned: %s - not found ( %d iterations)",cleaned,iterations);

    }
    gets(search);
    }
    return 0;
}
