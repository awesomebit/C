#include <stdio.h>
int N;	//�ڷ� ����
int A[50000 + 10];
void InputData(){
	scanf("%d", &N);
	for (register int i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
}

//lower bound, upper bound ����
inline int lowerBound(int s, int e, int d){//d���� ũ�ų� ���� ���� ���� ���� ���� ��ġ
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

inline int upperBound(int s, int e, int d){//d���� �۰ų� ���� ���� ���� ū ���� ��ġ
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

inline int UpperBound(int s, int e, int d){//d���� ���� ���� ���� ū ���� ��ġ
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
		if (A[m] == d) return m; //����
		else if (A[m] > d) e = m - 1; //m�̻󿡴� ã�� �� ����
		else s = m + 1; //m���Ͽ��� ã�� �� ����
	}
	return 0; //����
}

int bs(int s, int e, int d){ //����Լ�, ��������
	if (s > e) return 0; //start�� end���� ũ�� ����.
	int m = (s + e) / 2;
	if (A[m] == d) return m; //ã�� ����
	if (A[m] > d) return bs(s, m - 1, d); //m�̻󿡴� ã�� �� ����
	return bs(m + 1, e, d);	//m���Ͽ��� ã�� �� ����
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