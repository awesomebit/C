#include <stdio.h>
#define IMP (60000)
int P; //�� ����
int dist[128][128]; //��� ���� �Ÿ�
int visit[128]; //�갣('Z')������ �Ÿ�
int queue[52 * 100]; //�ߺ��湮�ϹǷ� ���*(��� 10��, �����ϰ� 100��)
int wp, rp;
inline bool empty(){ return rp == wp; }
inline int front(){ return queue[rp]; }
inline void pop(){ rp++; }
inline void push(int node, int d){
	if (visit[node] <= d) return; //�������� ������
	visit[node] = d;
	queue[wp++] = node;
}
struct QUEUE{

};

void InputData(){
	register int i, j; //�� ���
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
	wp = rp = 0; //�ʱ�ȭ
	push('Z', 0); //������ġ ť�� ����
	while (!empty()){ //�ݺ���
		int p = front(); pop();
		for (i = 'A'; i <= 'z'; i++){ //�빮�ڰ� �ƽ�Ű�ڵ忡�� �ҹ��ں��� �۴�
			push(i, visit[p] + dist[p][i]); //'Z' -> p -> i
		}
	}
	for (i = 'B'; i <= 'Y'; i++){ //���ã��
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