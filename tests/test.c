#include <stdarg.h>
#include <stdio.h>

void print(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    vprintf(s, ap);

    va_end(ap);
}
int main()
{

    int *ptr = NULL;

    printf("%d", *ptr);

    return 0;
}
