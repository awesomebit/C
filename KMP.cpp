#include <stdio.h>
char str[400000 + 10];
int fail[400000 + 10];
int stack[400000 + 10];
int sp;

inline void push(int n){
	stack[++sp] = n;
}

inline int pop(){
	return stack[sp--];
}

inline bool empty(){
	return sp == 0;
}

void PRT(int n){
	//if (n == 0) return;
	//PRT(fail[n]);
	//printf("%d ", n);
	while (n){
		push(n); n = fail[n];
	}
	while (!empty()) printf("%d", pop());
}

inline int strlength(char *a){
	register int cnt;
	for (cnt = 0; a[cnt]; cnt++);
	return cnt;
}

void preKMP(int len){
	register int i, k;
	for (i = 2, k = 0; i <= len; i++){
		while (k && (str[k + 1] != str[i])) k = fail[k];
		if (str[k + 1] == str[i]) fail[i] = ++k;
	}
}

int main(){
	scanf("%s", &str[1]);
	int len = strlength(&str[1]);
	preKMP(len);
	PRT(len);
	printf("\n");
	return 0;
}