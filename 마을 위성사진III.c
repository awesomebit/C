#include <stdio.h>
 
int W, H;
int a[1000 + 10][1000 + 10];
int chk[1000 + 10][1000 + 10];
int max = 0;
int cnt = 0;
 
int floodfill(int i, int j)
{
    int di[] = { -1, -1, -1, 0, 1, 1, 1, 0};
    int dj[] = {  -1, 0, 1, 1, 1, 0, -1, -1};
    int ni, nj;
 
    int k;
    for (k = 0; k < 8; k++)
    {
        ni = i + di[k];
        nj = j + dj[k];
        if (chk[ni][nj] == 1 || a[ni][nj] != 1) continue;
 
        cnt++;
        a[ni][nj] = 2;
        chk[ni][nj] = 1;
        floodfill(ni, nj);
    }
    return cnt;
 
}
 
void print(void)
{
    int i, j;
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void main(void)
{
    scanf("%d %d", &W, &H);
    int i, j;
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
 
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            cnt = 0;
            int temp = floodfill(i, j);
            if (max < temp) max = temp;
        }
    }
 
    printf("%d", max);
 
}
