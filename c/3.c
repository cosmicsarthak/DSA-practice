#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "ITER-IBCS-SOA-SUM-ids";
    char ptr[] = "iter-ibcs-soa-sum-ids-CSE";
    char *token, *ptoken;
    char *prr, *pr2;

    token = strtok_r(str, "-", &prr);
    ptoken = strtok_r(ptr, "-", &pr2);
    while (token != NULL && ptoken != NULL)
    {
        printf("%s\n", token);
        printf("%s\n", ptoken);
        token = strtok_r(NULL, "-", &prr);
        ptoken = strtok_r(NULL, "-", &pr2);
    }
    return 0;
}