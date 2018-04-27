#include <stdio.h>
#define MAXQ (10010)
int queue[MAXQ]; //circular queue
int wp, rp;
inline bool empty(){
	return wp == rp;
}
inline void push(int d){
	//int tmp = wp + 1;
	//if (tmp >= MAXQ) tmp -= MAXQ;
	//if (tmp == rp) return; //full, 저장 불가
	//queue[wp] = d;
	//wp = tmp;

	queue[wp] = d;
	if (++wp >= MAXQ) wp -= MAXQ;
}
inline int front(){
	return queue[rp];
}
inline void pop(){
	if (++rp >= MAXQ) rp -= MAXQ; //rp = (rp + 1) % MAXQ;
}

int main(){
	int N, K; register int i, j;
	wp = rp = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) push(i);
	for (i = 1; i <= N; i++){
		for (j = 1; j < K; j++) {
			int a = front(); pop();
			push(a);
		}
		printf("%d ", front()); pop();
	}
	return 0;
}