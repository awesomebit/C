#include <stdio.h>
 
int N;
typedef struct
{
    int a;
    int h; 
    int w;
    int n;
}BRICK;
BRICK brick[101];
 
int D[101];
int C[101];
int path[101];
 
void Input_Data(void)
{
    int i;
    scanf("%d",&N);
    for (i = 1; i <= N;i++)
    {
        scanf("%d %d %d", &brick[i].a, &brick[i].h, &brick[i].w);
        brick[i].n = i;
    }
}
 
int comp(const BRICK *p1, const BRICK *p2)
{
    return p1->w - p2->w;
}
 
int Find_LIS(void)
{
    int n, k, last_idx = 0;
 
    //D[1] = brick[1].h;
    //C[1] = 1;
    for (n = 1; n <= N;n++)
    {
        for (k = 0; k < n;k++)
        {
            if (brick[k].a < brick[n].a && D[n] < D[k] + brick[n].h)
            {
                D[n] = D[k] + brick[n].h;
                C[n] = C[k] + 1;
                path[n] = k;
            }
        }
        if (D[n] > D[last_idx])
        {
            last_idx = n;
        }
    }
    return last_idx;
}
 
void Print_Path(int idx)
{
    if (idx == 0) return;
    Print_Path(path[idx]);
    printf("%d\n",brick[idx].n);
}
 
int main(void)
{
    int last_idx;
    Input_Data();
 
    qsort(brick + 1, N, sizeof(BRICK), comp);
 
    last_idx = Find_LIS();
 
    printf("%d\n",C[last_idx]);
    Print_Path(last_idx);
 
    return 0;
}
