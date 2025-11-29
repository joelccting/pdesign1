#include <stdio.h>
#include <stdlib.h>

#define dbg(s, b...) //printf(s, ##b)

//int isOverTwo(unsigned *p, unsigned size, unsigned from, unsigned to)
//{
//    unsigned person[10] = {0};
//    unsigned sum = 0;
//    for (int i = 0; i < size; ++i)
//    {
//        if (p[i])
//        {
//            sum++;
//        }
//    }
//
//    if (sum > 2) return 1;
//
//    return 0;
//}

#if 0
unsigned getCount(unsigned *d, unsigned start, unsigned end)
{
    unsigned chatroom[10] = {0};
    unsigned sum = 0;

    for (int i = start; i <= end; ++i) chatroom[d[i]] = 1;
    for (int i = 0; i < 10; ++i) sum += chatroom[i];
    return sum;
}
#endif

static unsigned chatroom[10] = {0};

void setChatroom(unsigned *d, unsigned idx, int isEnter)
{
    if (isEnter) chatroom[d[idx]]++;
    else chatroom[d[idx]]--;
}

unsigned getCnt(void)
{
    unsigned ret = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (chatroom[i]) ret++;
    }

    dbg("getCnt=%d\n", ret);

    return ret;
}

unsigned getLen(void)
{
    unsigned ret = 0;

    for (int i = 0; i < 10; ++i)
    {
        ret += chatroom[i];
    }

    dbg("getLen=%d\n", ret);

    return ret;
}

unsigned getMaxLen(unsigned *d, unsigned size)
{
    int left = 0;
    unsigned len = 0, maxLen = 0;

    for (int right = 0; right < size; ++right)
    {
        dbg("+%d,", d[right]);
        setChatroom(d, right, 1);
        if (getCnt() < 3)
        {
            len = getLen();

            if (len > maxLen)
            {
                maxLen = len;
                dbg("maxLen=%d\n", maxLen);
            }
            continue;
        }

//        len = right - left;
//        if (len > maxLen)
//        {
//            maxLen = len;
//            dbg("\nmaxLen=%d\n", maxLen);
//        }

        while (left != right)
        {
            dbg("-%d,", d[left]);
            setChatroom(d, left, 0);
            left++;
            //if (getCount(d, left, right) < 3) break;
            if (getCnt() < 3) break;
        }

//        if (len > maxLen)
//        {
//            dbg("\nmaxLen=%d\n", maxLen);
//            maxLen = len;
//        }
    }

    return maxLen;
}

int main()
{
    unsigned nMessages;

    scanf("%u", &nMessages);
    unsigned data[nMessages];

    for (int i = 0; i < nMessages; ++i)
    {
        scanf("%u", data + i);
    }

    //getMaxLen(data, nMessages);
    printf("%u", getMaxLen(data, nMessages));

    return 0;
}
