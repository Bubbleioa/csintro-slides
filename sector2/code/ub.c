#include <stdio.h>
int foo()
{
    return 2022;
}
int bar()
{
    return 1 << -3;
}

int main()
{
    foo();
    printf("%d\n", bar());
    return 0;
}