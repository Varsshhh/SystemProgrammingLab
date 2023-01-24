#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"common.h"
#include"foo.h"
#include"bar.h"

int main()
{
    unsigned int n;
    #ifdef INTERACTIVE
    printf("Enter the input number\n");
    scanf("%u",&n);
    #endif

    #ifndef INTERACTIVE
    n=rand();
    #endif

    while (n>0)
    {
        printf("n = %u",n);
        printf("foo: ");
        fooprn(n);
        printf("bar: ");
        barprn(n);

        n=n/10;
    }

    return 0;
}
