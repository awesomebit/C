#include <stdio.h>

int N;

int A[1000001];//����ȣ �ε���, ���� �Է� ���� ����

struct SegmentTree{//������

	int sumv, s, e, m;

	SegmentTree *left, *right;

	SegmentTree(){

		sumv = s = e = m = 0; left = right = NULL;

	}

	SegmentTree(int si, int ei){//�ʱ⿡�� ��� 0�̹Ƿ�

		s = si; e = ei; m = (s + e) / 2; sumv = 0;

		if (s == e){//leaf node

			left = right = NULL; return;

		}

		left = new SegmentTree(s, m);

		right = new SegmentTree(m + 1, e);

	}

	~SegmentTree(){ delete left; delete right; }

	void update(int idx){

		if (s == e){//leaf node

			sumv = 1; return;

		}

		if (idx > m) right->update(idx);

		else left->update(idx);

		sumv = left->sumv + right->sumv;

	}

	int query(int qs, int qe){

		if ((qe < s) || (e < qs)) return 0;

		if ((qs <= s) && (e <= qe)) return sumv;

		return left->query(qs, qe) + right->query(qs, qe);

	}

};

SegmentTree *tree;

void InputData(){

	int num;

	scanf("%d", &N);

	for (register int i = 0; i < N; i++){

		scanf("%d", &num);//A�� ����ȣ

		A[num] = i;//����ȣ�� �ε����� ���� ���� ����

	}

	delete tree; tree = new SegmentTree(0, N - 1);

}

long long solve(){

	long long sum = 0; int num;

	for (register int i = 0; i < N; i++){

		scanf("%d", &num);//B�� ����ȣ

		sum += tree->query(A[num], N - 1);

		tree->update(A[num]);

	}

	return sum;

}

int main(){

	InputData();

	long long ans = solve();

	printf("%lld\n", ans);

	return 0;

}