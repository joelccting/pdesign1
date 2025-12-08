/** counting from 0
 * each step worths 1 to maxstep
 * the one who reaches the target wins
 */

#include <stdio.h>
#include <stdlib.h>

unsigned getPrev(unsigned target, unsigned maxstep)
{
    if (target > maxstep)
        return getPrev(target - maxstep - 1, maxstep);

    return target;
}

int main()
{
    unsigned target, maxstep;

    scanf("%u %u", &target, &maxstep);

    if (getPrev(target, maxstep))
        printf("First Win");
    else
        printf("Second Win");
    return 0;
}

//若自己想要達到x，則要讓對方數[x-1, x-y]。
//若要讓對方數(x-1, x-y), 則自己要先達到x-(y+1)。
//若自己要先達到x-(y+1)，則要讓對方數(x-(y+1)-1, x-(y+1)-y)。
//若要讓對方數(x-(y+1)-1, x-(y+1)-y)，則自己要先達到x-(y+1)-(y+1)。
//依此類推，每次需要搶到(x-n(y+1))這個關鍵數字, n=1,2,3,...
//int main() {
//    long long x;
//    int y;
//    scanf("%lld %d", &x, &y);
//
//    if (x % (y + 1) == 0)
//        printf("Second Win\n");
//    else
//        printf("First Win\n");
//
//    return 0;
//}
