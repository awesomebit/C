///===================user.cpp========================

#define MAXN (100000 + 10)
int N;//마지막 요소 번호
int HeaderPos;//헤더위치
int HeaderDir;//헤더방향
int used[MAXN];//CD존재 유무
int queue[MAXN];
int wp, rp, uniq;

inline void push(int head){
	used[head] = uniq; queue[wp++] = head;
}
inline int pop(){//front&pop
	return queue[rp++];
}
inline bool empty(){
	return wp == rp;
}

inline int MAXNUM(int a, int b){ return (a > b) ? a : b; }
inline int MINNUM(int a, int b){ return (a < b) ? a : b; }

struct SegmentTree{//구간최대값, 최소값
	int maxv, minv, s, e, m; SegmentTree *left, *right;
	SegmentTree(){ maxv = -MAXN; minv = MAXN; s = e = m = 0; left = right = NULL; }
	SegmentTree(int si, int ei){
		maxv = -MAXN; minv = MAXN; s = si; e = ei; m = (s + e) / 2;
		if (s == e){//leaf node
			left = right = NULL; return;
		}
		left = new SegmentTree(s, m); right = new SegmentTree(m + 1, e);
	}
	void insert(int idx){
		if (s == e){//leaf node
			push(idx); maxv = minv = idx; return;
		}
		if (idx > m) right->insert(idx);
		else left->insert(idx);
		maxv = MAXNUM(left->maxv, right->maxv); minv = MINNUM(left->minv, right->minv);
	}
	void del(int idx){
		if (s == e){//leaf node
			used[idx] = 0; maxv = -MAXN; minv = MAXN; return;
		}
		if (idx > m) right->del(idx);
		else left->del(idx);
		maxv = MAXNUM(left->maxv, right->maxv); minv = MINNUM(left->minv, right->minv);
	}
	int maxquery(int qs, int qe){
		if ((qe < s) || (e < qs)) return -MAXN;//범위벗어남, 영향안주는 값을 리턴
		if ((qs <= s) && (e <= qe)) return maxv;
		return MAXNUM(left->maxquery(qs, qe), right->maxquery(qs, qe));
	}
	int minquery(int qs, int qe){
		if ((qe < s) || (e < qs)) return MAXN;//범위벗어남, 영향안주는 값을 리턴
		if ((qs <= s) && (e <= qe)) return minv;
		return MINNUM(left->minquery(qs, qe), right->minquery(qs, qe));
	}
};
SegmentTree *tree;

// 홀더의 크기와 처음 header의 위치를 전달받아 초기화 한다.
void init(int holder_size, int head){
	N = holder_size - 1; HeaderPos = head; HeaderDir = -1;//최초왼쪽방향
	delete tree; tree = new SegmentTree(0, N); wp = rp = 0; uniq++;
}

// CD를 holder의 위치에 저장한다. HEADER의 위치는 변하지 않는다
// 한 번 저장되었던 holder에는 CD가 제거 되더라도 
// 다시 같은 위치에 입력(저장)되는 경우는 없다.
void insert(int holder){
	tree->insert(holder);
}

// 가장 먼저 저장된 CD를 홀더에서 꺼내고 HEADER의 위치를 리턴한다.
int first(){
	while (!empty()){//used[HeaderPos]!=uniq 이면 다른 방법으로 제거된 자리임
		HeaderPos = pop(); if (used[HeaderPos] == uniq) break;
	}
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER의 현재 위치에서 가장 가까운 곳의 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 거리가 같은 CD가 있다면 커서의 왼쪽에 있는 CD를 우선으로 처리한다.
int near(){
	int left = tree->maxquery(0, HeaderPos);//왼쪽에 현재위치와 가장 가까운 인덱스
	int right = tree->minquery(HeaderPos, N);//오른쪽에 현재위치와 가장 가까운 인덱스
	if ((right == MAXN) || (HeaderPos - left <= right - HeaderPos)) HeaderPos = left;
	else HeaderPos = right;
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER의 현재 위치에서 바라보던 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 바라보던 방향의 끝까지 CD가 한 개도 없으면 반대방향으로 방향을 돌려서 첫 번째 CD를 꺼낸다.
// HEADER는 처음에는 왼쪽을 바라보고 있으며 forward() 함수에서만 바라보는 방향이 바뀔 수 있고 
// 다른 함수에서는 어느쪽으로 이동하든 바라보는 방향은 바뀌지 않는다.
int forward(){
	int num;
	if (HeaderDir == -1){//왼쪽
		num = tree->maxquery(0, HeaderPos);
		if (num < 0){//CD없음
			HeaderDir = 1;//방향전환
			num = tree->minquery(HeaderPos, N);
		}
	}
	else{//오른쪽
		num = tree->minquery(HeaderPos, N);
		if (num == MAXN){//CD없음
			HeaderDir = -1;//방향전환
			num = tree->maxquery(0, HeaderPos);
		}
	}
	HeaderPos = num; tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER의 현재 위치에서 왼쪽 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 왼쪽 끝까지 CD가 한 개도 없으면 holder의 가장 오른쪽으로 이동한 후 다시 왼쪽 방향으로 첫 번째 CD를 꺼낸다. 
int left(){
	HeaderPos = tree->maxquery(0, HeaderPos);
	if (HeaderPos < 0){//왼쪽에 CD 없음
		HeaderPos = tree->maxquery(0, N);//가장 오른쪽에 있는 CD 인덱스
	}
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER의 현재 위치에서 오른쪽 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 오른쪽 끝까지 CD가 한 개도 없으면 holder의 가장 왼쪽으로 이동한 후 다시 오른쪽 방향으로 첫 번째 CD를 꺼낸다. 
int right(){
	HeaderPos = tree->minquery(HeaderPos, N);
	if (HeaderPos == MAXN){//오른쪽에 CD 없음
		HeaderPos = tree->minquery(0, N);//가장 왼쪽에 있는 CD 인덱스
	}
	tree->del(HeaderPos);
	return HeaderPos;
}