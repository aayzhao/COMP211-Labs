#include <stdio.h>

int foobar(int x)
{
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int maxInt()
{
    int prev = 0;
    int cur = 1;
    while (cur > prev)
    {
        cur++;
        prev++;
    }
    return prev;
}

int main() 
{
    printf("Hello, world\n");
    char str[20];
    printf("\nWhat is your name?\n");

    scanf("%19s",str);
    printf("Nice to meet you, %s\n", str);

    int a = foobar(200);
    printf("value of a: ");
    printf("%i\n", a);
    
    int max = maxInt();
    printf("Int max value: %d\n", max);

    return 0;
}
