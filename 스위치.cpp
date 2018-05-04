//모든 노드 갱신하는 방법
#include <stdio.h>

struct SegmentTree{//구간합
	int sumv, s, e, m; SegmentTree *left, *right;
	SegmentTree(){ sumv = s = e = m = 0; left = right = NULL; }
	SegmentTree(int si, int ei){//초기에 모든 스위치 OFF
		sumv = 0; s = si; e = ei; m = (s + e) / 2;
		if (s == e){//leaf node
			left = right = NULL; return;
		}
		left = new SegmentTree(s, m); right = new SegmentTree(m + 1, e);
	}
	~SegmentTree(){ delete left; delete right; }
	void update(int qs, int qe){
		if ((qe < s) || (e < qs)) return;//범위 벗어남
		if (s == e){//leaf node
			sumv ^= 1; return;
		}
		left->update(qs, qe); right->update(qs, qe);
		sumv = left->sumv + right->sumv;
	}
	int query(int qs, int qe){
		if ((qe < s) || (e < qs)) return 0;//범위 벗어남
		if ((qs <= s) && (e <= qe)) return sumv;
		return left->query(qs, qe) + right->query(qs, qe);
	}
};
SegmentTree *tree;

int main(){
	int M, N, cmd, qs, qe; register int i;
	scanf("%d %d", &N, &M);
	delete tree; tree = new SegmentTree(1, N);//트리 생성
	for (i = 1; i <= M; i++){
		scanf("%d %d %d", &cmd, &qs, &qe);
		if (cmd == 0) tree->update(qs, qe);
		else printf("%d\n", tree->query(qs, qe));
	}
	return 0;
}