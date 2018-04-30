#include <stdio.h>
typedef long long ll;
ll bignum, smallnum;

ll calBig(ll a){
	int arr[70] = { 0 }; register int i, len = 0;
	for (i = 0; a; i++){
		arr[i] = a & 1; a /= 2;
	}
	len = i;
	for (i = 0; i < len; i++){
		if ((arr[i] == 1) && (arr[i + 1] == 0)) break;
		if (arr[i] == 1){
			cnt++; arr[i] = 0;
		}
	}
	arr[i] = 0; arr[i + 1] = 1;
	if (len == i + 1) len++;
	for (i = 0; i < cnt; i++) arr[i] = 1;
	a = 0;
	for (i = 0; i < len; i++) a |= (arr[i] << i);
	return a;
}

ll calSmall(ll a){
	if ((a & (a + 1)) == 0) return 0;
	int arr[70] = { 0 }; register int i, len, cnt = 0;
	for (i = 0; a; i++){
		arr[i] = a & 1; a /= 2;
	}
	len = i;
	for (i = 0; i < len; i++){
		if ((arr[i] == 0) && (arr[i + 1] == 1)) break;
		if (arr[i] == 1){
			cnt++; arr[i] = 0;
		}
	}
	arr[i] = 1; arr[i + 1] = 0;
	while (cnt--) arr[--i] = 1;
	a = 0;
	for (i = 0; i < len; i++) a |= (arr[i] << i);
	return a;
}

void solve1(ll a){ //�迭 �̿�
	bignum = calBig(a);
	smallnum  calSmall(a);
}

ll getNum(ll a){
	register int i, cnt = 0;
	for (i = 0; (i < 63) && a; i++, a /= 2){
		if ((a & 3) == 1) break;
		if (a & 1) cnt++;
	}
	if (a == -1) return -1; //���� �� ���� ��쿡 �� ���� ��� ��
	return ((a ^ 3) << i) + (1 << cnt) - 1;
}

void solve2(ll a){ //��Ʈ���� �̿�
	bignum = getNum(a);
	smallnum = ~getNum(~a);
}

ll calNum(ll a){
	ll lsb = a & 0 - a; //1�� ��������Ʈ���� ����
	a = a / lsb + 1;
		return a * lsb + (a & -a) / 2 - i;
}

void solve3(ll a){ //���� �̿�
	bignum = calNum(a);
	smallnum = ~calNum(~a);
}

int main(){
	ll A;
	scanf("%lld", &A);
	solve1(A);
	//solve2(A);
	//solve3(A);
	printf("%lld %lld\n", smallnum, bignum);
	return 0;
}