#include <stdio.h>
 
typedef struct
{
    int r;
    int c;
}POS;
 
POS pos[18];
 
char puyo[14][8];
int chk[14][8];
int conn_cnt;
 
void Input_Data(void)
{
    int i;
    for (i = 1; i <= 12; i++)
    {
        scanf("%s", &puyo[i][1]);
    }
}
 
void Init_Check(void)
{
    int r, c;
 
    for (r = 1; r <= 12; r++)
    {
        for (c = 1; c <= 6; c++)
        {
            chk[r][c] = 0;
        }
    }
}
 
 
void Flood_Fill(int r, int c, char color)
{
    int i;
    static int dr[4] = { 0,0,1,-1 };
    static int dc[4] = { 1,-1,0,0 };
 
    chk[r][c] = 1;
    conn_cnt++;
 
    for (i = 0; i<4; i++)
    {
        if ((puyo[r + dr[i]][c + dc[i]] == color) && (!chk[r + dr[i]][c + dc[i]]))
        {
            Flood_Fill(r + dr[i], c + dc[i], color);
        }
    }
}
 
void Delete_Puyo(int r, int c, char color)
{
    int i;
    static int dr[4] = { 0,0,1,-1 };
    static int dc[4] = { 1,-1,0,0 };
 
    puyo[r][c] = '.';
 
    for (i = 0; i<4; i++)
    {
        if ((puyo[r + dr[i]][c + dc[i]] == color))
        {
            Delete_Puyo(r + dr[i], c + dc[i], color);
        }
    }
}
 
void Fall_Puyo(void)
{
    int c, er, pr;
 
    for (c = 1; c <= 6; c++)
    {
        er = 12;
        for (;;)
        {
            while (er>0 && puyo[er][c] != '.') er--;
            if (er == 0) break;
 
            pr = er - 1;
            while (pr>0 && puyo[pr][c] == '.') pr--;
            if (pr == 0) break;
 
            puyo[er][c] = puyo[pr][c];
            puyo[pr][c] = '.';
        }
    }
}
 
int main(void)
{
    int T;
    int i, r, c;
    int combo;
    int connected;
     
     
 
    scanf("%d",&T);
     
    while (T--)
    {
        Input_Data();
        combo = 0;
 
        for (;;)
        {
            connected = 0;
            Init_Check();
 
            for (r = 1; r <= 12; r++)
            {
                for (c = 1; c <= 6; c++)
                {
                    if (puyo[r][c] != '.' && !chk[r][c])
                    {
                        conn_cnt = 0;
                        Flood_Fill(r, c, puyo[r][c]);
                        if (conn_cnt >= 4)
                        {
                            pos[connected].r = r;
                            pos[connected].c = c;
                            connected++;
                        }
                    }
                }
            }
 
            if (connected == 0) break;
            combo++;
 
            for (i = 0; i<connected; i++)
            {
                Delete_Puyo(pos[i].r, pos[i].c, puyo[pos[i].r][pos[i].c]);
            }
            Fall_Puyo();
        }
 
        printf("%d\n", combo);
    }
     
    return 0;
}
