//stack 구조체 없이 배열이용


#include <stdio.h>

struct NODE{

	int h, pos;//높이, 위치

	NODE(){ h = pos = 0; };//생성자

	NODE(int a, int b){ h = a; pos = b; }//생성자

};

NODE stack[100000 + 10];

int sp;

inline bool empty(){

	return sp == 0;

}

inline int size(){

	return sp;

}

inline void push(int h, int pos){

	stack[++sp] = NODE(h, pos);

}

inline NODE top(){

	return stack[sp];

}

inline void pop(){

	sp--;

}

int main(){

	int N, h; register int i, pos; long long maxarea = 0, area;

	sp = 0;//스택 초기화

	scanf("%d", &N);

	for (i = 0; i < N; i++){

		scanf("%d", &h); pos = i;

		while (!empty()){

			if (top().h > h){//제거

				area = (long long)top().h * (i - top().pos);

				if (maxarea < area) maxarea = area;

				pos = top().pos; pop();

			}

			else break;

		}

		push(h, pos);

	}

	while (!empty()){

		area = (long long)top().h * (N - top().pos);

		if (maxarea < area) maxarea = area;

		pop();

	}

	printf("%lld\n", maxarea);

	return 0;

}