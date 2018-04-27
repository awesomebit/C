#include <stdio.h>

struct NODE{
	NODE* next; int data;
	NODE(){
		data = 0;
		next = NULL;
	}
	NODE(int d, NODE* p){
		data = d;
		next = p;
	}
};

struct CIRCULAR{
	NODE *cur, *head; 
	CIRCULAR(){
		cur = head = NULL;
	}
	CIRCULAR(int n){
		cur = head = new NODE(n, NULL);
		for (register int i = n - 1; i > 0; i--) push(i);
		cur->next = head; //cur가 head를 가리키면 circular로 돌게 됨.
	}
	void push(int d){
		head = new NODE(d, head);
	}
	void nextTarget(int k){
		for (register int i = 1; i < k; i++) cur = cur->next;
		output();
		pop();
	}
	void output(){
		printf("%d", cur->next->data);
	}
	void pop(){
		head = cur->next; 
		cur->next = cur->next->next;
		delete head;
	}
};

int main(){
	int N, K; register int i;
	scanf("%d %d", &N, &K);
	CIRCULAR *cir = new CIRCULAR(N);
	for (i = 1; i <= N; i++){
		cir->nextTarget(K);
	}
	delete cir;
	return 0;
}