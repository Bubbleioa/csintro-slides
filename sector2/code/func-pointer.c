#include <stdio.h>
int add(int a, int b);
int minus(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (*methods[])(int, int) = {
    add,
    minus,
    mul,
    div,
};

int for_each(int *arr, int n, int method(int, int))
{
    if (n == 1)
        return arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = method(res, arr[i]);
    }
    return res;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", for_each(a, 5, methods[i]));
    }
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}
