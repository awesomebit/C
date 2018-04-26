//Problem E solution


#include <stdio.h>

int N;//��� ����

int K;//���ڿ�����

char code[1010][40];//�����ڵ�

int A, B;

int visit[1010];//�湮ǥ�ÿ�

int path[1010];//��������

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

			if (++cnt > 1) return 0;//�عְŸ� 1�� �ƴ�

		}

	}

	return 1;//�عְŸ� 1��

}

inline int push(int n, int pre){

	if (visit[n] == 1) return 0;//�̹� �湮

	if (pre && (HammingCheck(code[n], code[pre]) == 0)) return 0;//�عְŸ� 1�� �ƴ�

	path[n] = pre;//�������

	if (n == B) return 1;//����, ����

	visit[n] = 1;//�湮ǥ��

	queue[wp++] = n;

	return 0;

}

void InputData(){

	scanf("%d%d", &N, &K);

	for (register int i = 1; i <= N; i++) scanf("%s", code[i]);

	scanf("%d%d", &A, &B);

}

int BFS(){

	wp = rp = 0;//�ʱ�ȭ, visit, path �ʱ�ȭ

	push(A, 0);//������ġ ť�� ����

	while (!empty()){//�ݺ���

		int p = front(); pop();

		for (register int i = 1; i <= N; i++) {

			if (push(i, p) == 1) return 1;//���� ����

		}

	}

	return -1;//����

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