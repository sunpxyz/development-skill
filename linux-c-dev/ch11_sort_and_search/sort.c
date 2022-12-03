#include <stdio.h>

void insertion_sort(int a[], int len)
{
    printf("before: ");
    for (int i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    for (int i = 1; i < len; ++i) {
        int j = i - 1, tmp = a[i];
        while (j >= 0 && a[j] > tmp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
    printf("\nafter: ");
    for (int i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[5] = {5, 3, 4, 2, 1};
    insertion_sort(a, 5);

    return 0;
}