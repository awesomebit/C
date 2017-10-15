#include <stdio.h>
 
//int M, N;
int K;
typedef struct
{
    int sx;
    int sy;
    int ex;
    int ey;
}BUS;
 
BUS bus[5000];
int chk[5000];
 
int sx, sy, ex, ey;
 
typedef struct
{
    int bus_n;
    int cnt;
}QUEUE;
 
QUEUE queue[5000];
int wp, rp;
 
#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueNotEmpty (wp > rp)
 
void Input_Data(void)
{
    int i,m, n;
    scanf("%d %d",&m,&n);
    scanf("%d",&K);
    for (i = 0; i < K;i++)
    {
        scanf("%d %d %d %d %d", &m, &bus[i].sx, &bus[i].sy, 
            &bus[i].ex, &bus[i].ey);
 
        // 가로
        if (bus[i].sx == bus[i].ex)
        {
            if (bus[i].sy > bus[i].ey)
            {
                int temp;
                temp = bus[i].sy;
                bus[i].sy = bus[i].ey;
                bus[i].ey = temp;
            }
        }
 
        // 세로
        else if (bus[i].sy == bus[i].ey)
        {
            if (bus[i].sx > bus[i].ex)
            {
                int temp;
                temp = bus[i].sx;
                bus[i].sx = bus[i].ex;
                bus[i].ex = temp;
            }
        }
    }
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
}
 
int BFS(void)
{
    QUEUE data, ndata;
    int i;
 
    for (i = 0; i < K; i++)
    {
        if ((bus[i].sx <= sx) && (sx <= bus[i].ex) &&
            (bus[i].sy <= sy) && (sy <= bus[i].ey))
        {
            data.bus_n = i;
            data.cnt = 1;
            Enqueue(data);
            chk[i] = 1;
        }
    }
 
    while (QueueNotEmpty)
    {
        Dequeue(data);
 
        if ((bus[data.bus_n].sx <= ex) && (ex <= bus[data.bus_n].ex) &&
            (bus[data.bus_n].sy <= ey) && (ey <= bus[data.bus_n].ey))
        {
            return data.cnt;
        }
 
        for (i = 0; i < K; i++)
        {
            if (chk[i]) continue;
            if (!((bus[i].sx <= bus[data.bus_n].sx && bus[data.bus_n].sx <= bus[i].ex)
                || (bus[data.bus_n].sx <= bus[i].sx && bus[i].sx <= bus[data.bus_n].ex)))
                continue;
            if (!((bus[i].sy <= bus[data.bus_n].sy && bus[data.bus_n].sy <= bus[i].ey)
                || (bus[data.bus_n].sy <= bus[i].sy && bus[i].sy <= bus[data.bus_n].ey)))
                continue;
            ndata.bus_n = i;
            ndata.cnt = data.cnt + 1;
            Enqueue(ndata);
            chk[i] = 1;
        }
    }
    return -1;
}
 
int main(void)
{
    Input_Data();
 
    printf("%d\n", BFS());
 
    return 0;
}
