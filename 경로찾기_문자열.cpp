//Problem E solution


#include <stdio.h>

int N;//노드 개수

int K;//문자열길이

char code[1010][40];//이진코드

int A, B;

int visit[1010];//방문표시용

int path[1010];//경로저장용

int queue[1010];

int wp, rp;

inline bool empty(){

	return wp == rp;

}

inline int front(){

	return queue[rp];

}

inline void pop(){

	rp++;

}

inline int HammingCheck(char *a, char *b){

	register int i, cnt = 0;

	for (i = 0; i < K; i++){

		if (a[i] != b[i]){

			if (++cnt > 1) return 0;//해밍거리 1이 아님

		}

	}

	return 1;//해밍거리 1임

}

inline int push(int n, int pre){

	if (visit[n] == 1) return 0;//이미 방문

	if (pre && (HammingCheck(code[n], code[pre]) == 0)) return 0;//해밍거리 1이 아님

	path[n] = pre;//경로저장

	if (n == B) return 1;//도착, 성공

	visit[n] = 1;//방문표시

	queue[wp++] = n;

	return 0;

}

void InputData(){

	scanf("%d%d", &N, &K);

	for (register int i = 1; i <= N; i++) scanf("%s", code[i]);

	scanf("%d%d", &A, &B);

}

int BFS(){

	wp = rp = 0;//초기화, visit, path 초기화

	push(A, 0);//시작위치 큐에 저장

	while (!empty()){//반복문

		int p = front(); pop();

		for (register int i = 1; i <= N; i++) {

			if (push(i, p) == 1) return 1;//도착 성공

		}

	}

	return -1;//실패

}

void PRT(int n){

	if (n == 0) return;

	PRT(path[n]);

	printf("%d ", n);

}

int main(){

	InputData();

	int ans = BFS();

	if (ans == -1) printf("-1");

	else PRT(B);

	printf("\n");

	return 0;

}