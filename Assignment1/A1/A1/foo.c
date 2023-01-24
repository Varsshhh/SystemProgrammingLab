#include<stdio.h>
#include<string.h>
#include"foo.h"

void fooprn(unsigned int n)
{
    char res[200];
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

    if (n/1000000000 >0)
    {
        printf("%s",arr0[n/1000000000]);
        printf(" billions ");
        fooprn(n%1000000000);
        return;
    }
    if (n/1000000>0)
    {
        int c=n/1000000;
        fooprn(c);
        printf(" millions ");
        fooprn(n%1000000);
        return;
    }
    if (n/1000>0)
    {
        int c=n/1000;
        fooprn(c);
        printf(" thousands ");
        fooprn(n%1000);
        return;
    }
    if (n<10)
    {
        strcat(res,arr0[n]);
        printf("%s",res);
        return;

    }
    else if (n>9 && n<20)
    {
        strcat(res,arr4[n-10]);
        printf("%s",res);
        return;
        
    }
    else if(n>19 && n<100)
    {
        int c=n/10;
        strcat(res,arr2[c]);
        strcat(res," ");
        c=n%10;
        strcat(res,arr1[c]);
        printf("%s",res);
        return;
        
    }
    else if (n>99 && n<1000)
    {
        int c=n/100;
        printf("%s ",arr3[c]);
        fooprn(n%100);  
        return;
    }   
}

