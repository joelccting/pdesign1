#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[5] = {0};
    int i, shift, tmp;

    //scanf("%s", s);
    for (i = 0; i < 4; ++i)
    {
        scanf("%c", &(s[i]));
    }

    scanf("%d", &shift);

    for (i = 0; i < 4; ++i)
    {
        tmp = (s[i] - 'A') + shift;
        tmp %= 26;
        tmp += 'A';
        s[i] = tmp;

        //printf("%c\n", s[i]);
    }

    printf("%s\n", s);

    return 0;
}

//這一題主要是用到ASCII code的概念。電腦會將字元認為ASCII code的編碼，如果將該字元進行加減，就可以得到其在ASCII表上相對位置的字元。
//Sample solution
//
//int main(){
//    char c1,c2,c3,c4;
//    int k;
//    scanf(" %c%c%c%c %d",&c1,&c2,&c3,&c4,&k);
//    printf("%c%c%c%c",((c1-'A'+k)%26)+'A',((c2-'A'+k)%26)+'A',((c3-'A'+k)%26)+'A',((c4-'A'+k)%26)+'A');
//    return 0;
//}
