#include <stdio.h>
#include <stdlib.h>

#define COLS 3

int compare_recursive(const int *a, const int *b, int col);

/* recursive lexicographic comparison of rows */
int compare_row(const void *pa, const void *pb) {
    const int *a = *(const int * const *)pa;
    const int *b = *(const int * const *)pb;

    return compare_recursive(a, b, 0);
}

/* recursive helper */
int compare_recursive(const int *a, const int *b, int col) {
    if (col == COLS)  /* all columns equal */
        return 0;

    if (a[col] < b[col]) return -1;
    if (a[col] > b[col]) return 1;

    /* equal ¡÷ compare next column */
    return compare_recursive(a, b, col + 1);
}

int main() {
    int data[][COLS] = {
        {3, 5, 1},
        {3, 4, 9},
        {2, 7, 8},
        {3, 4, 1}
    };

    int n = sizeof(data)/sizeof(data[0]);

    /* create array of pointers to rows */
    const int *rows[10];
    for (int i = 0; i < n; i++)
        rows[i] = data[i];

    qsort(rows, n, sizeof(int *), compare_row);

    /* print sorted rows */
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", rows[i][0], rows[i][1], rows[i][2]);
    }

    return 0;
}
