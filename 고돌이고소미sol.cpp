//Problem D solution


#include <stdio.h>

int N;//지도 크기

int msr, msc, mer, mec;//고돌이 현재위치, 집위치

int wsr, wsc, wer, wec;//고소미 현재위치, 집위치

int map[30][30];//지도 정보

int visit[30][30][30][30];//[mr][mc][wr][wc], 고돌이, 고소미

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0, 0 };

int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 };

struct QUEUE{

	int mr, mc, wr, wc, t;//고돌이세로가로, 고소미세로가로, 시간

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

	if (visit[mr][mc][wr][wc] == 1) return;//이미 해본 경우임

	for (register int i = 0; i < 9; i++){

		if ((mr == wr + dr[i]) && (mc == wc + dc[i])) return;//둘레에 있는 경우

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

	wp = rp = 0;//초기화, 테스트 케이스 여러개면 visit 배열 반드시 초기화

	push(msr, msc, wsr, wsc, 0);//시작위치 큐에 저장

	while (!empty()){//반복문

		QUEUE p = front(); pop();

		if ((p.mr == mer) && (p.mc == mec) && (p.wr == wer) && (p.wc == wec)) return p.t;//성공

		for (register int i = 0; i < 9; i++){//고돌이

			int nmr = p.mr + dr[i]; int nmc = p.mc + dc[i];//고돌이 9방향의 좌표

			if ((nmr < 1) || (nmr > N) || (nmc < 1) || (nmc > N)) continue;//범위벗어남

			if (map[nmr][nmc] == 1) continue;//웅덩이임, 이동불가

			for (register int j = 0; j < 9; j++){//고소미

				int nwr = p.wr + dr[j]; int nwc = p.wc + dc[j];//고소미 9방향의 좌표

				if ((nwr < 1) || (nwr > N) || (nwc < 1) || (nwc > N)) continue;//범위벗어남

				if (map[nwr][nwc] == 1) continue;//웅덩이임, 이동불가

				push(nmr, nmc, nwr, nwc, p.t + 1);

			}

		}

	}

	return -1;//실패, 이 문제는 이런 경우 없음

}

int main(){

	InputData();

	int ans = BFS();

	printf("%d\n", ans);

	return 0;

}