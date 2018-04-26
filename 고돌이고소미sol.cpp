//Problem D solution


#include <stdio.h>

int N;//���� ũ��

int msr, msc, mer, mec;//���� ������ġ, ����ġ

int wsr, wsc, wer, wec;//��ҹ� ������ġ, ����ġ

int map[30][30];//���� ����

int visit[30][30][30][30];//[mr][mc][wr][wc], ����, ��ҹ�

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0, 0 };

int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 };

struct QUEUE{

	int mr, mc, wr, wc, t;//���̼��ΰ���, ��ҹ̼��ΰ���, �ð�

	QUEUE(){ mr = mc = wr = wc = t = 0; }

	QUEUE(int r, int c, int y, int x, int d){

		mr = r; mc = c; wr = y; wc = x; t = d;

	}

};

QUEUE queue[25 * 25 * 25 * 25 + 10];

int wp, rp;

inline bool empty() { return wp == rp; }

inline QUEUE front() { return queue[rp]; }

inline void push(int mr, int mc, int wr, int wc, int t){

	if (visit[mr][mc][wr][wc] == 1) return;//�̹� �غ� �����

	for (register int i = 0; i < 9; i++){

		if ((mr == wr + dr[i]) && (mc == wc + dc[i])) return;//�ѷ��� �ִ� ���

	}

	visit[mr][mc][wr][wc] = 1;

	queue[wp++] = QUEUE(mr, mc, wr, wc, t);

}

inline void pop(){ rp++; }

void InputData(){

	scanf("%d", &N);

	scanf("%d%d%d%d", &msr, &msc, &mer, &mec);

	scanf("%d%d%d%d", &wsr, &wsc, &wer, &wec);

	for (register int i = 1; i <= N; i++){

		for (register int j = 1; j <= N; j++){

			scanf("%d", &map[i][j]);

		}

	}

}

int BFS(){

	wp = rp = 0;//�ʱ�ȭ, �׽�Ʈ ���̽� �������� visit �迭 �ݵ�� �ʱ�ȭ

	push(msr, msc, wsr, wsc, 0);//������ġ ť�� ����

	while (!empty()){//�ݺ���

		QUEUE p = front(); pop();

		if ((p.mr == mer) && (p.mc == mec) && (p.wr == wer) && (p.wc == wec)) return p.t;//����

		for (register int i = 0; i < 9; i++){//����

			int nmr = p.mr + dr[i]; int nmc = p.mc + dc[i];//���� 9������ ��ǥ

			if ((nmr < 1) || (nmr > N) || (nmc < 1) || (nmc > N)) continue;//�������

			if (map[nmr][nmc] == 1) continue;//��������, �̵��Ұ�

			for (register int j = 0; j < 9; j++){//��ҹ�

				int nwr = p.wr + dr[j]; int nwc = p.wc + dc[j];//��ҹ� 9������ ��ǥ

				if ((nwr < 1) || (nwr > N) || (nwc < 1) || (nwc > N)) continue;//�������

				if (map[nwr][nwc] == 1) continue;//��������, �̵��Ұ�

				push(nmr, nmc, nwr, nwc, p.t + 1);

			}

		}

	}

	return -1;//����, �� ������ �̷� ��� ����

}

int main(){

	InputData();

	int ans = BFS();

	printf("%d\n", ans);

	return 0;

}