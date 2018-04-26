

///********* main_code ************



#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define M 1000
typedef long long LL;
static int org[N + 5], dat[N + 5], ans[M + 5], user_ans[M + 5];
static int getCount, userN;
static int orgN, dataN, ansN;
extern int card_find(int user_ans[]);

int getNumber(int select, int num) {
	getCount++;
	if (select == 1) return org[num];
	else if (select == 2) return dat[num];
	else return 0;
}

static void init() {
	int i;
	getCount = ansN = 0;
	for (i = 0; i < 1000; i++) {
		user_ans[i] = 0;
	}
	scanf("%d %d", &orgN, &dataN);
	ansN = orgN - dataN;
	for (i = 0; i < orgN; i++) scanf("%d", &org[i]);
	for (i = 0; i < dataN; i++) scanf("%d", &dat[i]);
	for (i = 0; i < ansN; i++) {
		scanf("%d", &ans[i]);
	}
}

inline void Swap(int&a, int&b){
	int tmp = a; a = b; b = tmp;
}

static void init(int tc)
{
	int i;
	/// 초기화
	getCount = 0;
	for (i = 0; i < M; ++i){
		ans[i] = user_ans[i] = 0;
	}
	for (i = 0; i < N; ++i){
		org[i] = dat[i] = 0;
	}

	/// 데이터 생성
	orgN = 100000 + tc * 100000 + rand() % 10000;
	if (orgN > N) orgN = N;
	ansN = 100 + rand() % 901;
	dataN = orgN - ansN;
	for (i = 0; i < orgN; ++i) org[i] = i + 1;
	for (i = 0; i < orgN; ++i){
		int idx = (LL)rand()*rand() % orgN;
		Swap(org[i], org[idx]);
	}

	for (i = 0; i < orgN; ++i) dat[i] = org[i];

	/// dat[]에서 ansN개 삭제
	for (i = 0; i < ansN; ++i){
		int idx = (LL)rand()*rand() % orgN;
		while (dat[idx] == 0){
			idx = (LL)rand()*rand() % orgN;
		}
		dat[idx] = 0;
	}
	int j = 0, k = 0;
	for (i = 0; i < orgN; ++i){
		if (dat[i] == 0) ans[k++] = org[i];
		else dat[j++] = dat[i];
	}
	for (; j < orgN; ++j) dat[j] = 0;
}

static void check(){
	if (ansN != userN) getCount = N;

	for (int i = 0; i < ansN; i++) {
		if (ans[i] != user_ans[i]) getCount = N;
	}
}

int main(void){
	int T = 1; /// 1 ~ 10

	//scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		// init();
		init(tc);
		userN = card_find(user_ans);
		check();
		printf("#%d %d\n", tc + 1, getCount);
	}
	return 0;
}


///******** use_code ************

#define MAXN (1000000)
#define LEFT (1)
#define RIGHT (2)
int L[MAXN];
int R[MAXN];
int Llen, Rlen;
int ansCnt;
int* sol;

extern int getNumber(int, int);

int binarySearch(int* arr, int select){
	register int s = 0, e = MAXN - 1, m, sol = e;
	while (s <= e){
		m = (s + e) / 2;
		arr[m] = getNumber(select, m);
		if (arr[m] == 0) e = m - 1;
		else {
			sol = m; s = m + 1;
		}
	}
	return sol;
}

void DQ(int rs, int re){
	int le = re + ansCnt;
	if (L[le] == 0) L[le] = getNumber(LEFT, le);
	if (R[re] == 0) R[re] = getNumber(RIGHT, re);
	if (L[le] == R[re]) return;	//(rs~re)까지 없어진 카드 없음
	if (rs == re){ //분할할 수 없음, le부터 없는 카드임
		for (register int i = le; i <= Llen; i++){
			if (L[i] == 0) L[i] = getNumber(LEFT, i);
			if (L[i] == R[re]) break;
			sol[ansCnt++] = L[i]; //없어진 카드임
		}
	}
	else{
		int m = (rs + re) / 2;
		DQ(rs, m); DQ(m + 1, re);
	}
}

int card_find(int user_ans[]){
	register int i;
	sol = user_ans; ansCnt = 0; //초기화
	for (i = 0; i < MAXN; i++) L[i] = R[i] = 0; //초기화
	Llen = binarySearch(L, LEFT); //왼쪽 카드 더미의 마지막 요소 번호
	Rlen = binarySearch(R, RIGHT); //오른쪽 카드 더미의 마지막 요소 번호
	DQ(0, Rlen);
	for (i = Rlen + ansCnt + 1; i <= Llen; i++){
		if (L[i] == 0) L[i] = getNumber(LEFT, i);
		sol[ansCnt++] = L[i];
	}
	return ansCnt;
}


