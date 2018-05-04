///===================user.cpp========================

#define MAXN (100000 + 10)
int N;//������ ��� ��ȣ
int HeaderPos;//�����ġ
int HeaderDir;//�������
int used[MAXN];//CD���� ����
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

struct SegmentTree{//�����ִ밪, �ּҰ�
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
		if ((qe < s) || (e < qs)) return -MAXN;//�������, ������ִ� ���� ����
		if ((qs <= s) && (e <= qe)) return maxv;
		return MAXNUM(left->maxquery(qs, qe), right->maxquery(qs, qe));
	}
	int minquery(int qs, int qe){
		if ((qe < s) || (e < qs)) return MAXN;//�������, ������ִ� ���� ����
		if ((qs <= s) && (e <= qe)) return minv;
		return MINNUM(left->minquery(qs, qe), right->minquery(qs, qe));
	}
};
SegmentTree *tree;

// Ȧ���� ũ��� ó�� header�� ��ġ�� ���޹޾� �ʱ�ȭ �Ѵ�.
void init(int holder_size, int head){
	N = holder_size - 1; HeaderPos = head; HeaderDir = -1;//���ʿ��ʹ���
	delete tree; tree = new SegmentTree(0, N); wp = rp = 0; uniq++;
}

// CD�� holder�� ��ġ�� �����Ѵ�. HEADER�� ��ġ�� ������ �ʴ´�
// �� �� ����Ǿ��� holder���� CD�� ���� �Ǵ��� 
// �ٽ� ���� ��ġ�� �Է�(����)�Ǵ� ���� ����.
void insert(int holder){
	tree->insert(holder);
}

// ���� ���� ����� CD�� Ȧ������ ������ HEADER�� ��ġ�� �����Ѵ�.
int first(){
	while (!empty()){//used[HeaderPos]!=uniq �̸� �ٸ� ������� ���ŵ� �ڸ���
		HeaderPos = pop(); if (used[HeaderPos] == uniq) break;
	}
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER�� ���� ��ġ���� ���� ����� ���� CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �Ÿ��� ���� CD�� �ִٸ� Ŀ���� ���ʿ� �ִ� CD�� �켱���� ó���Ѵ�.
int near(){
	int left = tree->maxquery(0, HeaderPos);//���ʿ� ������ġ�� ���� ����� �ε���
	int right = tree->minquery(HeaderPos, N);//�����ʿ� ������ġ�� ���� ����� �ε���
	if ((right == MAXN) || (HeaderPos - left <= right - HeaderPos)) HeaderPos = left;
	else HeaderPos = right;
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER�� ���� ��ġ���� �ٶ󺸴� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �ٶ󺸴� ������ ������ CD�� �� ���� ������ �ݴ�������� ������ ������ ù ��° CD�� ������.
// HEADER�� ó������ ������ �ٶ󺸰� ������ forward() �Լ������� �ٶ󺸴� ������ �ٲ� �� �ְ� 
// �ٸ� �Լ������� ��������� �̵��ϵ� �ٶ󺸴� ������ �ٲ��� �ʴ´�.
int forward(){
	int num;
	if (HeaderDir == -1){//����
		num = tree->maxquery(0, HeaderPos);
		if (num < 0){//CD����
			HeaderDir = 1;//������ȯ
			num = tree->minquery(HeaderPos, N);
		}
	}
	else{//������
		num = tree->minquery(HeaderPos, N);
		if (num == MAXN){//CD����
			HeaderDir = -1;//������ȯ
			num = tree->maxquery(0, HeaderPos);
		}
	}
	HeaderPos = num; tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER�� ���� ��ġ���� ���� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ���� ������ CD�� �� ���� ������ holder�� ���� ���������� �̵��� �� �ٽ� ���� �������� ù ��° CD�� ������. 
int left(){
	HeaderPos = tree->maxquery(0, HeaderPos);
	if (HeaderPos < 0){//���ʿ� CD ����
		HeaderPos = tree->maxquery(0, N);//���� �����ʿ� �ִ� CD �ε���
	}
	tree->del(HeaderPos);
	return HeaderPos;
}

// HEADER�� ���� ��ġ���� ������ �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ������ ������ CD�� �� ���� ������ holder�� ���� �������� �̵��� �� �ٽ� ������ �������� ù ��° CD�� ������. 
int right(){
	HeaderPos = tree->minquery(HeaderPos, N);
	if (HeaderPos == MAXN){//�����ʿ� CD ����
		HeaderPos = tree->minquery(0, N);//���� ���ʿ� �ִ� CD �ε���
	}
	tree->del(HeaderPos);
	return HeaderPos;
}