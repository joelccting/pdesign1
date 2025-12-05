#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG (0)
#define LINELEN (4000)

#if DEBUG
#define dbg(s, b...) printf(s, ##b)
#else
#define dbg(s, b...)
#endif

struct word
{
    char *str;
    int cnt;
    struct word *next;
};

struct wordList
{
    struct word *head;
    struct word *tail;
};

struct word *create(char *s)
{
    dbg("+%s\n", __func__);
    int slen = strlen(s) + 1;
    struct word *p = malloc(sizeof(struct word));
    memset(p, 0, sizeof(struct word));

    p->str = malloc(slen);
    memset(p->str, 0, slen);
    memcpy(p->str, s, slen - 1);
    p->cnt = 1;
    dbg("-%s\n", __func__);
    return p;
};

struct wordList *init(void)
{
    struct wordList *list = malloc(sizeof(struct wordList));
    list->head = list->tail = NULL;
    return list;
}

struct word *seek(struct wordList *list, struct word *o)
{
    struct word *tmp = list->head;

    while (strcmp(o->str, tmp->str))
    {
        dbg("[%s] %s\n", __func__, tmp->str);
        dbg("[%s] %s\n", __func__, o->str);
        tmp = tmp->next;

        if (!tmp)
        {
            return NULL;
        }

    }

    return tmp;
};

void enque(struct wordList *list, struct word *o)
{
    dbg("+%s\n", __func__);

    o->next = NULL;

    if (list->head == NULL)
    {
        dbg("+%d\n", __LINE__);
        list->head = list->tail = o;
        dbg("-%d\n", __LINE__);
    }
    else
    {
        struct word *tmp = seek(list, o);
        if (!tmp)
        {
            list->tail->next = o;
            list->tail = o;
        }
        else
        {
            tmp->cnt++;
        }

    }
    dbg("-%s\n", __func__);
}

void deque(struct wordList *list)
{
    dbg("+%s\n", __func__);
    struct word *tmp = list->head;
    list->head = tmp->next;
    free(tmp->str);
    free(tmp);
    dbg("-%s\n", __func__);
}

void cleanup(struct wordList *list)
{
    while (list->head)
    {
        deque(list);
    }

}

void print(struct wordList *list)
{
    struct word *tmp = list->head;

    dbg("[%s]\n", __func__);

    while (tmp)
    {
        printf("%s %d", tmp->str, tmp->cnt);
        tmp = tmp->next;
        if (tmp) printf("\n");
    }
}

int main()
{
    char s[LINELEN];
    struct wordList *list = init();
    struct word *tmp;

    //fgets(s, 100, stdin);
    while (fgets(s, LINELEN - 1, stdin) != NULL)
    {
        s[strlen(s) - 1] = 0;

        char *pch = strtok(s, " ,.");
        while (pch)
        {
            dbg("%s\n", pch);
            tmp = create(pch);
            enque(list, tmp);
            pch = strtok(NULL, " ,.");
        }
    }

    print(list);
    cleanup(list);

    return 0;
}
