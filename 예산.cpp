#include <stdio.h>

int N; //지방의 수
int M; //총 예산
int a[10010]; //각 지방의 예산요청
int max, sum;

void inputData() {
	scanf("%d", &N);
	for (register int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (max <= a[i]) max = a[i];
	}
	scanf("%d", &M);
}

void sort() {
	register int i, j;
	int tmp;
	for (i = 1; i <= N - 1; i++) {
		for (j = i; j <= N; j++) {
			if (a[i] > a[j]) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}
}

int solve() {
	int cnt = 1;
	register int i, j;
	for (;;) {
		for (i = N, j = 2; i > 1; i--, j++) {
			if (a[i] == a[i - 1]) cnt = j;
			else break;
		}
		for (i = 0; i < cnt; i++) {
			a[N - i]--; sum--;
			if (sum <= M) return a[N];
		}
	}
}

int ans() {
	sort();
	if (sum >= M) {
		//상한액 구하기
		return solve();
	}
	else return max;
}

int main() {
	inputData();
	printf("%d\n", ans()); 
	return 0;
}