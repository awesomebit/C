#include <stdio.h>
 
//정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 
//정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
 
typedef struct{
    int i, j, d;
}TOMATO;
 
TOMATO Q[1000*1000+10];
 
int M, N;
 
int arr[1010][1010];
int chk[1010][1010];
 
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
 
int wp, rp;
 
int ni, nj, nd;
int ti, tj, td;
 
int cnt = 0;
int empty = 0;
 
int flag = 0;
int sol = 0;
 
void findTomato(void)
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
                Q[wp].i = i;
                Q[wp].j = j;
                Q[wp++].d = 0;
                chk[i][j] = 1;
            }
            else if (arr[i][j] == -1)
            {
                empty++;
            }
        }
    }
}
 
int functionBFS(void)
{
    int k;
    while (wp > rp)
    {
        ti = Q[rp].i;
        tj = Q[rp].j;
        td = Q[rp++].d;
 
        for (k = 0; k < 4; k++)
        {
            ni = ti + di[k];
            nj = tj + dj[k];
 
            if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
            if (arr[ni][nj] != 0 || chk[ni][nj] != 0) continue;
 
            Q[wp].i = ni;
            Q[wp].j = nj;
            Q[wp++].d = td + 1;
            chk[ni][nj] = 1;
        }
    }
    return td;
     
}
 
void main(void)
{
    scanf("%d %d", &M, &N);
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
 
    findTomato();
 
    sol = functionBFS();
 
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (arr[i][j] == -1)
            {
                chk[i][j] = 1;
            }
            if (chk[i][j] == 0) flag++;
        }
    }
 
    if (cnt == (N*M - flag - empty)) printf("0");
    else if (flag > 0) printf("-1");
    else printf("%d", sol);
 
}
