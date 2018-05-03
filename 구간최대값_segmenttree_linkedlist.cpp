#include <stdio.h>

//segment tree - linked list 기반
int N, Q;
inline int MAXNUM(int a, int b){
	return (a > b) ? a : b;
}

struct SegmentTree{
	int maxv, s, e, m;
	SegmentTree *left, *right;
	SegmentTree(){ maxv = s = e = m = 0; left = right = NULL; }
	SegmentTree(int si, int ei){
		s = si; e = ei; m = (s + e) / 2;
		if (s == e){ //leaf node, 실제 데이터 저장
			scanf("%d", &maxv); left = right = NULL; return;
		}
		left = new SegmentTree(s, m);
		right = new SegmentTree(m + 1, e);
		maxv = MAXNUM(left->maxv, right->maxv);
	}
	~SegmentTree(){
		delete left; delete right;
	}
	void update(int idx, int value){
		if ((idx < s) || (e < idx)) return;
		if (s == e){ //leaf node, 실제 데이터 저장
			maxv = value; return;
		}
		left->update(idx, value); right->update(idx, value);
		maxv = MAXNUM(left->maxv, right->maxv);
	}
	int query(int qs, int qe){
		if ((qe < s) || (e < qs)) return 0;
		if ((qs <= s) && (e <= qe)) return maxv;
		return MAXNUM(left->query(qs, qe), right->query(qs, qe));
	}
};
SegmentTree *tree;

void InputData(){
	scanf("%d %d", &N, &Q);
	delete tree; tree = new SegmentTree(1, N);
}

void solve(){
	register int i; int qs, qe;
	for (i = 1; i <= Q; i++){
		scanf("%d %d", &qs, &qe);
		printf("%d\n", tree->query(qs, qe));
	}
}

int main(){
	InputData();
	solve();
	return 0;
}
