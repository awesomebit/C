#include <stdio.h>
 
int N;
char a[100 + 10][100 + 10];
char b[100 + 10][100 + 10];
 
int Check(int i, int j)
{
    int di[] = { -1, 1, 0, 0 };
    int dj[] = { 0, 0, -1, 1 };
    int flag = 0;
    int cnt = 0;
    int ni, nj;
    int k;
    for (k = 0; k < 4; k++)
    {
        ni = i + di[k];
        nj = j + dj[k];
 
        if (ni < 0 || ni > N || nj < 0 || nj > N) continue;
 
        cnt++;
        if (b[ni][nj] < b[i][j])
        {
            // 성공 조건
            flag++;
        }
    }
    if (flag == cnt) return 1;
    else return 0;
}
 
 
int main(void)
{
    scanf("%d", &N);
    int i, j;
    for (i = 0; i < N; i++)
    {
        scanf("%s", a[i]);
    }
    for (i = 0; i < N; i++)
    {
        sscanf(a[i],"%s", b[i]);
    }
 
    for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j < N - 1; j++)
        {
            if (Check(i, j) == 1)
            {
                a[i][j] = 'X';
            }
        }
    }
 
    for (i = 0; i < N; i++)
    {
        printf("%s\n", a[i]);
    }
 
    return 0;
}
