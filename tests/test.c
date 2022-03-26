#include <stdarg.h>
#include <stdio.h>

void print(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    printf("\033[1;31merror\033[0m ");

    vprintf(s, ap);

    va_end(ap);
}
int main()
{

    int *ptr = NULL;

    printf("%d", *ptr);

    return 0;
}
