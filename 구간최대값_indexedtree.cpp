#include <stdio.h>

//index tree(인덱스 트리), 배열기반

int N, Q;

int *tree;//int tree[N보다 크거나같은 2의 제곱수의 2배공간 확보];

int ds;//실제 데이터가 저장되는 시작위치

inline int MAXNUM(int a, int b){

	return (a > b) ? a : b;

}

void InputData(){

	register int i;

	scanf("%d %d", &N, &Q);

	for (i = 1; i < N; i *= 2);//N보다 크거나같은 2의 제곱수

	ds = i;//실제 데이터가 저장되는 시작위치

	tree = new int[i * 2]();//초기화된 공간 필요

	for (i = 1; i <= N; i++){//실제 데이터 저장

		scanf("%d", &tree[ds + i - 1]);

	}

	for (i = ds - 1; i > 0; i--){//인덱스 완성, 거꾸로 완성해야 함

		tree[i] = MAXNUM(tree[i * 2], tree[i * 2 + 1]);

	}

}

void update(int idx, int value){

	register int c = ds + idx - 1;//실제 저장된 위치

	register int p = c / 2;//부모 노드는 /2

	tree[c] = value;

	while (p){//0이면 부모노드 없음

		if (tree[p] < tree[c]){

			tree[p] = tree[c]; c = p; p = c / 2;

		}

		else break;

	}

}

int query(int qs, int qe){

	register int L = ds + qs - 1, R = ds + qe - 1, maxv = 0;

	while (L < R){

		if (L & 1) maxv = MAXNUM(maxv, tree[L++]);

		if (!(R & 1)) maxv = MAXNUM(maxv, tree[R--]);

		L /= 2; R /= 2;

	}

	if (L == R) maxv = MAXNUM(maxv, tree[L]);

	return maxv;

}

void solve(){

	register int i; int qs, qe;

	for (i = 1; i <= Q; i++){

		scanf("%d %d", &qs, &qe);

		printf("%d\n", query(qs, qe));

	}

}

int main(){

	InputData();

	solve();

	return 0;

}