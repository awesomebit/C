#include <stdio.h>
 
typedef struct
{
    int n, h;
}GAME;
 
GAME set[1000 + 10];
 
int a[1000 + 10];
int N;
int area = 0;
 
int max_h = 0;
int max_n = 0;
 
int left_h = 0;
int left_n = 0;
 
int right_h = 0;
int right_n = 0;
 
void sort(void)
{
    int i, j;
    GAME temp;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (set[i].n > set[j].n)
            {
                temp = set[j];
                set[j] = set[i];
                set[i] = temp;
            }
        }
    }
}
 
void findMax(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (max_h < set[i].h)
        {
            max_h = set[i].h;
            max_n = set[i].n;
        }
    }
}
 
void findLeftRight(void)
{
    left_h = set[0].h;
    left_n = set[0].n;
 
    right_h = set[N - 1].h;
    right_n = set[N - 1].n;
}
 
void function(void)
{
    int i;
    int L = 0;
    int H;
 
    H = set[0].h;
    for (i = left_n; i <= max_n; i++)
    {
        if (H < a[i])
        {
            H = a[i];
        }
        area += H;
    }
 
    H = set[N-1].h;
    for (i = right_n; i > max_n; i--)
    {
        if (H < a[i])
        {
            H = a[i];
        }
        area += H;
    }
     
}
 
void main(void)
{
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &set[i].n, &set[i].h);
        a[set[i].n] = set[i].h;
    }
 
    sort();
    findMax();
    findLeftRight();
    function();
 
    printf("%d", area);
 
}
