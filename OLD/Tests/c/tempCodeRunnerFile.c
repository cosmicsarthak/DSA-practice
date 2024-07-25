#include <stdio.h>
int linear_search(const int arr[], int target, int n);
int main(void)
{
    int n;
    printf("Enter Size Of The Array: \n");
    scanf("%d", &n);
    int a[n], i;
    printf("Enter Value To The Array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int target;
    printf("Enter The Target Element: \n");
    scanf("%d", &target);
    int flag = linear_search(a, target, n);
    if (flag != -1)
    {
        printf("Target Element Found At Index %d In The Array.\n", flag);
    }
    else
    {
        printf("Target Element Is Not Present In The Array.\n");
    }
    return 0;
}
int linear_search(const int arr[], int target, int n)
{
    int i, flag = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            flag = i;
            break;
        }
    }
    return flag;
}
