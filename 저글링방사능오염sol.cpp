#include <stdio.h>
struct QUEUE{
	int r, c, t; //세로 가로 시간
	QUEUE(){ r = c = t = 0; }
	QUEUE(int a, int b, int d){
		r = a; c = b; t = d;
	}
};
QUEUE queue[100 * 100 + 10];
int wp, rp;
inline bool empty(){ return wp == rp; }
inline int size(){ return wp - rp; }
inline QUEUE front(){ return queue[rp]; }
inline QUEUE back(){ return queue[wp - 1]; }
inline void push(int r, int c, int t){ queue[wp++] = QUEUE(r, c, t); }
inline void pop(){ rp++; }
int C, R; //가로, 세로 크기
char map[110][110];
int sc, sr; //시작위치
int visit[110][110]; //필요시 초기화
int alive; //살아있는 저글링

void InputData(){
	scanf("%d %d", &C, &R);
	for (register int i = 0; i < R; i++){
		scanf("%s", map[i]);
	}
	scanf("%d %d", &sc, &sr); sc--; sr--;
}

int BFS(){
	//초기화
	//시작위치 큐에 저장
	//반복문
	//실패
}

int main(){
	InputData();
	int ans = BFS();
	printf("%d\n%d\n", ans, alive);
	return 0;
}