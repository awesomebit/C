#include <stdio.h>
#define IMP (60000)
int P; //길 개수
int dist[128][128]; //노드 사이 거리
int visit[128]; //헛간('Z')에서의 거리
int queue[52 * 100]; //중복방문하므로 노드*(적어도 10배, 안전하게 100배)
int wp, rp;
inline bool empty(){ return rp == wp; }
inline int front(){ return queue[rp]; }
inline void pop(){ rp++; }
inline void push(int node, int d){
	if (visit[node] <= d) return; //이전보다 안좋음
	visit[node] = d;
	queue[wp++] = node;
}
struct QUEUE{

};

void InputData(){
	register int i, j; //길 계수
	char a, b; int d;
	scanf("%d", &P);
	for (i = 'A'; i <= 'z'; i++){
		visit[i] = IMP;
		for (j = 'A'; j <= 'z'; j++){
			dist[i][j] = IMP;
		}
	}
	for (i = 1; i <= P; i++){
		scanf(" %c %c %d", &a, &b, &d);
		if (dist[a][b] > d) dist[a][b] = dist[b][a] = d;
	}
}

int BFS(){
	register int i, minidx = 'A';
	wp = rp = 0; //초기화
	push('Z', 0); //시작위치 큐에 저장
	while (!empty()){ //반복문
		int p = front(); pop();
		for (i = 'A'; i <= 'z'; i++){ //대문자가 아스키코드에서 소문자보다 작다
			push(i, visit[p] + dist[p][i]); //'Z' -> p -> i
		}
	}
	for (i = 'B'; i <= 'Y'; i++){ //결과찾기
		if (visit[minidx] > visit[i]) minidx = i;
	}
	return minidx;
}

int main(){
	InputData();
	int ans = BFS();
	printf("%c %d\n", ans, visit[ans]);
	return 0;
}