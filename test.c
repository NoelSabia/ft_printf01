#include <string.h>
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i = 0;
    char *result;

    int size = strlen(s);
    result = (char*)malloc(size + 1);
    if (!result)
        return  NULL;
    while (s[i] != 0)
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}

char custom_function(unsigned i, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

#include <stdio.h>
int main()
{
    const char *str = "Hello";
    unsigned int i = 3;
    char *result = ft_strmapi(str, custom_function);

    if (result)
    {
        printf("%s", result);
        free(result);
    }
    else
    {
        printf("Misserfolg");
    }

}
