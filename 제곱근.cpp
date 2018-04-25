//Problem C solution


#include <stdio.h>

typedef long long ll;

inline ll upperbound(ll s, ll e, ll d){

	ll m, sol = 0;

	while (s <= e){

		m = (s + e) / 2;

		if (m <= d / m){//m*m <= d(범위 벗어남)

			sol = m; s = m + 1;

		}

		else e = m - 1;

	}

	return sol;

}

double root(double d){//바빌로니아법

	double n = d / 2, x = 0;

	while (n != x){

		x = n;

		n = (n + d / n) / 2;

	}

	return n;

}

int main(){

	ll N;

	scanf("%lld", &N);

	printf("%lld\n", upperbound(1, N, N));

	//printf("%lld\n", (ll)root(N));

	return 0;

}