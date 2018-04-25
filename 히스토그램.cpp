#include <stdio.h>

struct NODE{

	int h, pos;

	NODE(){ h = pos = 0; };

	NODE(int a, int b){ h = a; pos = b; }

};

struct STACK{

	NODE * arr;

	int sp;

	STACK(){//생성자

		arr = NULL; sp = 0;

	}

	STACK(int n){//생성자

		arr = new NODE[n]; sp = 0;

	}

	~STACK(){//소멸자

		delete[] arr;

	}

	bool empty(){ return sp == 0; }

	int size(){ return sp; }

	void push(int a, int b){ arr[++sp] = NODE(a, b); }

	NODE top(){ return arr[sp]; }

	void pop(){ sp--; };

};

STACK * stack;

int main(){

	int N, h; register int i, pos;

	long long maxarea = 0, area;

	scanf("%d", &N);

	stack = new STACK(N + 10);

	for (i = 0; i < N; i++){

		scanf("%d", &h); pos = i;

		while (!stack->empty()){

			NODE tmp = stack->top();

			if (tmp.h > h){//스택에서 제거, 그전에 계산

				area = (long long)tmp.h * (i - tmp.pos);

				if (maxarea < area) maxarea = area;

				pos = tmp.pos;

				stack->pop();

			}

			else break;

		}

		stack->push(h, pos);

	}

	while (!stack->empty()){

		NODE tmp = stack->top();

		area = tmp.h * (N - tmp.pos);

		if (maxarea < area) maxarea = area;

		stack->pop();

	}

	printf("%lld\n", maxarea);

	delete stack;

	return 0;

}