///===================user.cpp========================

#ifndef NULL
#define NULL 0
#endif

#define MAXN (100000 + 10)
int N; //������ ��� ��ȣ
int HeaderPos; //�����ġ
int HeaderDir; //�������
int queue[MAXN];
int wp, rp, uniq;
inline void push(int head){
	used[head] = uniq;
	queue[wp++] = head;
}
inline int pop(){ //front&pop
	return queue[rp++];
}
inline bool empty(){
	return wp == rp;
}
int used[MAXN]; //CD���� ����
inline int MAXNUM(int a, int b){
	return (a > b ? a : b);
}
inline int MINNUM(int a, int b){
	return (a < b ? a : b);
}

struct SegmentTree{ //�����ִ밪, �ּҰ�
	int maxv, minv, s, e, m; SegmentTree *left, *right;
	SegmentTree(){ maxv = -MAXN; minv = MAXN; s = e = m = 0; left = right = NULL; }
	SegmentTree(int si, int ei){
		maxv = -MAXN; minv = MAXN; s = si; e = ei; m = (s + e) / 2;
		if (s == e){ //leaf node
			left = right = NULL; return;
		}
		left = new SegmentTree(s, m); right = new SegmentTree(m + 1, e);
	}
	void insert(int idx){
		if (s == e){ //leaf node
			push(idx);
			maxv = minv = idx; return;
		}
		if (idx > m) right->insert(idx);
		else left->insert(idx);
		maxv = MAXNUM(left->maxv, right->maxv);
		minv = MINNUM(left->minv, right->minv);
	}
};

// Ȧ���� ũ��� ó�� header�� ��ġ�� ���޹޾� �ʱ�ȭ �Ѵ�.
void init(int holder_size, int head){
	N = holder_size - 1; HeaderPos = head; HeaderDir = -1; //���ʿ��ʹ���
	delete tree; tree = new SegmentTree(0, N); wp = rp = 0; uniq++;
	


}







// CD�� holder�� ��ġ�� �����Ѵ�. HEADER�� ��ġ�� ������ �ʴ´�
// �� �� ����Ǿ��� holder���� CD�� ���� �Ǵ��� 
// �ٽ� ���� ��ġ�� �Է�(����)�Ǵ� ���� ����.
void insert(int holder){

}







// ���� ���� ����� CD�� Ȧ������ ������ HEADER�� ��ġ�� �����Ѵ�.
int first();







// HEADER�� ���� ��ġ���� ���� ����� ���� CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �Ÿ��� ���� CD�� �ִٸ� Ŀ���� ���ʿ� �ִ� CD�� �켱���� ó���Ѵ�.
int near();







// HEADER�� ���� ��ġ���� �ٶ󺸴� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �ٶ󺸴� ������ ������ CD�� �� ���� ������ �ݴ�������� ������ ������ ù ��° CD�� ������.
// HEADER�� ó������ ������ �ٶ󺸰� ������ forward() �Լ������� �ٶ󺸴� ������ �ٲ� �� �ְ� 
// �ٸ� �Լ������� ��������� �̵��ϵ� �ٶ󺸴� ������ �ٲ��� �ʴ´�.
int forward();







// HEADER�� ���� ��ġ���� ���� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ���� ������ CD�� �� ���� ������ holder�� ���� ���������� �̵��� �� �ٽ� ���� �������� ù ��° CD�� ������. 
int left();







// HEADER�� ���� ��ġ���� ������ �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ������ ������ CD�� �� ���� ������ holder�� ���� �������� �̵��� �� �ٽ� ������ �������� ù ��° CD�� ������. 
int right();



