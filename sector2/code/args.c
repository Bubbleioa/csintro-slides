#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int get_max(int cnt, ...)
{
    va_list args;
    va_start(args, cnt);
    int ret = INT_MIN;
    while (cnt)
    {
        cnt--;
        int num = va_arg(args, int);
        ret = num > ret ? num : ret;
    }
    return ret;
}

int main()
{
    printf("%d\n", get_max(4, -12, 5, 9, 2));
    return 0;
}