#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This is a line of text It is the \n \n \nsecond line \n then next line";

    char ptr[] = "iter-ibcs-soa-sum-ids-CSE";
    char *token, *ptoken;
    char *prr, *pr2;

    token = strtok_r(str, " ", &prr);
    ptoken = strtok_r(ptr, "-", &pr2);
    int i = 0;
    while (token != NULL)
    {
        ++i;
        printf("%s\n", token);
        token = strtok_r(NULL, " ", &prr);
    }

    printf("%d\n", i - 1);
    return 0;
}