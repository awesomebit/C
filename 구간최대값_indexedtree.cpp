#include <stdio.h>

//index tree(�ε��� Ʈ��), �迭���

int N, Q;

int *tree;//int tree[N���� ũ�ų����� 2�� �������� 2����� Ȯ��];

int ds;//���� �����Ͱ� ����Ǵ� ������ġ

inline int MAXNUM(int a, int b){

	return (a > b) ? a : b;

}

void InputData(){

	register int i;

	scanf("%d %d", &N, &Q);

	for (i = 1; i < N; i *= 2);//N���� ũ�ų����� 2�� ������

	ds = i;//���� �����Ͱ� ����Ǵ� ������ġ

	tree = new int[i * 2]();//�ʱ�ȭ�� ���� �ʿ�

	for (i = 1; i <= N; i++){//���� ������ ����

		scanf("%d", &tree[ds + i - 1]);

	}

	for (i = ds - 1; i > 0; i--){//�ε��� �ϼ�, �Ųٷ� �ϼ��ؾ� ��

		tree[i] = MAXNUM(tree[i * 2], tree[i * 2 + 1]);

	}

}

void update(int idx, int value){

	register int c = ds + idx - 1;//���� ����� ��ġ

	register int p = c / 2;//�θ� ���� /2

	tree[c] = value;

	while (p){//0�̸� �θ��� ����

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