#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char s[] = "Hello .., world , hehe,kk  ll";
    char delim[] = ",  ";
    char *prr;

    char *token = strtok_r(s, delim, &prr);

    while (token != NULL)
    {
        printf("%s\n", token);
        char *ptr2 = strtok_r(NULL, delim, &prr);
        token = ptr2;
    }

    return 0;
}