#include <stdio.h>
#include <stdlib.h>

int seek(unsigned *data, unsigned key, int from, int to)
{
    if (from > to) return -1;

    int mid = (from + to) / 2;

    if (key > data[mid]) return seek(data, key, mid + 1, to);
    else if (key < data[mid]) return seek(data, key, from, mid - 1);

    return mid;
}

int main()
{
    int tTest, nMessages;
    int mQuery;

    scanf("%d %d", &tTest, &nMessages);

    for (int i = 0; i < tTest; ++i)
    {
        scanf("%d", &mQuery);

        unsigned data[nMessages];
        for (int j = 0; j < nMessages; ++j)
        {
            scanf("%d", data + j);
        }

        for (int j = 0; j < mQuery; ++j)
        {
            unsigned key;
            scanf("%u", &key);
            printf("%d\n", seek(data, key, 0, nMessages - 1));
        }
    }


    return 0;
}
