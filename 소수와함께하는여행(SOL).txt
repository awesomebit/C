#include <stdio.h>
#include <math.h>
  
#define MAX (9999)
  
typedef struct
{
    int prime;
    int level;
}QUEUE;
  
QUEUE Queue[10000];
int Wr,Rd;
  
int Not_Prime[10000];
int Visited[10000];
  
int Prime_Tour(int S,int E)
{
    int i,j;
    int tens;
    int num;
    int base;
    QUEUE data,newdata;
  
      
    data.prime = S;
    data.level = 0;
    Queue[Wr++] = data;
  
    while(Rd != Wr)
    {
        tens = 10;
        num = 1;
        data = Queue[Rd++];
        newdata.level = data.level+1;
        for(i=0;i<4;i++)
        {
            base = data.prime - (data.prime%tens/num)*num;
            for(j=(i==3)?1:0;j<=9;j++)
            {
                newdata.prime = base + j*num;
                if(!Not_Prime[newdata.prime] && !Visited[newdata.prime])
                {
                    if(newdata.prime == E) return newdata.level;
                    Queue[Wr++] = newdata;
                    Visited[newdata.prime] = 1;
                }
            }
            num *= 10;
            tens *= 10;
  
        }
    }
    return -1;
}
  
  
  
  
void Make_PrimeTable(void)
{
    int limit = sqrt(MAX);
    int i,j;
  
    Not_Prime[0] = 1;
    Not_Prime[1] = 1;
    for(i=2;i<=limit;i++)
    {
        if(!Not_Prime[i])
        {
            for(j=i+i;j<=MAX;j+=i) Not_Prime[j] = 1;
        }
    }
}
  
int main(void)
{
    int S,E;
    int ret;
  
    Make_PrimeTable();  
      
    scanf("%d %d",&S,&E);
  
    ret = Prime_Tour(S,E);
      
    printf("%d\n",ret);
    return 1;
}
