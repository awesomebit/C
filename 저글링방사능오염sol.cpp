#include <stdio.h>
struct QUEUE{
	int r, c, t; //���� ���� �ð�
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
int C, R; //����, ���� ũ��
char map[110][110];
int sc, sr; //������ġ
int visit[110][110]; //�ʿ�� �ʱ�ȭ
int alive; //����ִ� ���۸�

void InputData(){
	scanf("%d %d", &C, &R);
	for (register int i = 0; i < R; i++){
		scanf("%s", map[i]);
	}
	scanf("%d %d", &sc, &sr); sc--; sr--;
}

int BFS(){
	//�ʱ�ȭ
	//������ġ ť�� ����
	//�ݺ���
	//����
}

int main(){
	InputData();
	int ans = BFS();
	printf("%d\n%d\n", ans, alive);
	return 0;
}