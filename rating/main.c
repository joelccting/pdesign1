#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{
    char name[21];
    int m;
    int e;
    int c;
    int sum;
} Student;

int cmp(const void *a, const void *b)
{
    Student *aa = (Student *)a;
    Student *bb = (Student *)b;

    if (aa->sum > bb->sum) return -1;
    else if  (aa->sum < bb->sum) return 1;
    else //(aa->sum == bb->sum)
    {
        if (aa->m > bb->m) return -1;
        else if  (aa->m < bb->m) return 1;
        else
        {
            if (aa->e > bb->e) return -1;
            else if  (aa->e < bb->e) return 1;
            else
            {
                if (aa->c > bb->c) return -1;
                else if  (aa->c < bb->c) return 1;
            }
        }
    }
    return 0;
}


int main()
{
    int t;

    scanf("%d", &t);
    Student s[t];

    for (int i = 0; i < t; ++i)
    {
        scanf("%s %d %d %d", s[i].name, &(s[i].c), &(s[i].e), &(s[i].m));
        s[i].sum = s[i].c + s[i].e + s[i].m;
    }

#if 0
    for (int i = 0; i < t; ++i)
    {
        printf("%s %d %d %d\n", s[i].name, s[i].c, s[i].e, s[i].m);
    }
#endif

    qsort(s, t, sizeof(Student), cmp);

    for (int i = 0; i < t; ++i)
    {
        printf("%s %d %d %d %d\n", s[i].name, s[i].sum, s[i].m, s[i].e, s[i].c);
    }

    return 0;
}
