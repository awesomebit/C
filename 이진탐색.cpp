#include <stdio.h>
int N;	//자료 개수
int A[50000 + 10];
void InputData(){
	scanf("%d", &N);
	for (register int i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
}

//lower bound, upper bound 구현
inline int lowerBound(int s, int e, int d){//d보다 크거나 같은 값중 제일 작은 값의 위치
	register int m, sol = 0;
	while (s <= e){
		m = (s + e) / 2;
		if (A[m] >= d){
			sol = m; e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

inline int upperBound(int s, int e, int d){//d보다 작거나 같은 값중 제일 큰 값의 위치
	register int m, sol = 0;
	while (s <= e){
		m = (s + e) / 2;
		if (A[m] <= d){ //
			sol = m; s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

inline int UpperBound(int s, int e, int d){//d보다 작은 값중 제일 큰 값의 위치
	register int m, sol = 0;
	while (s <= e){
		m = (s + e) / 2;
		if (A[m] < d){ //
			sol = m; s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

inline int binarysearch(int d){
	register int s = 1, e = N, m;
	while (s <= e){
		m = (s + e) / 2;
		if (A[m] == d) return m; //성공
		else if (A[m] > d) e = m - 1; //m이상에는 찾는 값 없음
		else s = m + 1; //m이하에는 찾는 값 없음
	}
	return 0; //실패
}

int bs(int s, int e, int d){ //재귀함수, 분할정복
	if (s > e) return 0; //start가 end보다 크면 실패.
	int m = (s + e) / 2;
	if (A[m] == d) return m; //찾기 성공
	if (A[m] > d) return bs(s, m - 1, d); //m이상에는 찾는 값 없음
	return bs(m + 1, e, d);	//m이하에는 찾는 값 없음
}

void solve(){
	int T, d; register int i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++){
		scanf("%d", &d);
		printf("%d\n", binarysearch(d));
	}
}

int main(){
	InputData();
	solve();
	return 0;
}