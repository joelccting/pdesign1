#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE (9)

int main()
{
    char passwd[SIZE] = {0};
    unsigned upper = 0, lower = 0, digit = 0;

    printf("Your password must contain upper and lower case, as well as digits\n");
    printf("Key in your password: ");
    fgets(passwd, SIZE, stdin); /* broke at blanks */

    if (strlen(passwd) != (SIZE - 1))
    {
        printf("Error: password \"%s\" is shorter than %d characters\n", passwd, SIZE);
        return 0;
    }

    for (int i = 0; i < SIZE - 1; ++i)
    {
        upper += isupper(passwd[i]);
        lower += islower(passwd[i]);
        digit += isdigit(passwd[i]);
    }

    if (!upper) printf("Error: your password does not contain upper letters.\n");
    else if (!lower) printf("Error: your password does not contain lower letters.\n");
    else if (!digit) printf("Error: your password does not contain digits\n");
    else printf("Success! your password is \"%s\"\n", passwd);

    return 0;
}
