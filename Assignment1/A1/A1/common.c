#include<stdio.h>
#include<string.h>
#include"common.h"

void cmnprn(unsigned int n)
{
    if (n>1000)
    {
        printf("big\n");
    }
    else{
    char res[70];
    char arr0[10][20]={"zero","one","two","three","four",
    "five","six","seven","eight","nine"};

    char arr1[10][20]={"","one","two","three","four",
    "five","six","seven","eight","nine"};

    char arr2[10][20]={"","ten","twenty","thirty","forty","fifty",
    "sixty","seventy","eighty","ninety"};

    char arr3[10][20]={"","one hundred","two hundred","three hundred",
    "four hundred","five hundred","six hundred",
    "seven hundred","eight hundred","nine hundred"};

    char arr4[10][20]={"ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};

    if (n<10)
    {
        strcat(res,arr0[n]);
        printf("%s",res);

    }
    else if (n>9 && n<20)
    {
        strcat(res,arr4[n-10]);
        printf("%s",res);
        
    }
    else if(n>19 && n<100)
    {
        int c=n/10;
        strcat(res,arr2[c]);
        strcat(res," ");
        c=n%10;
        strcat(res,arr1[c]);
        printf("%s",res);
        
    }
    else if (n>99 && n<1000)
    {
        int c=n/100;
        strcat(res,arr3[c]);
        strcat(res," ");
        printf("%s",res);
        strcat(res," ");
        cmnprn(n%100);  
    }   
    } 

}

