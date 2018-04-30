#include <stdio.h>
int color; //0:R, 1:B, 2:Y, 3:G
int straightnum;
int maxnum;
int num[10];
inline int char2dec(char ch){
	switch (ch){
	case 'R': return 0;
	case 'B': return 1;
	case 'Y': return 2;
	case 'G': return 3;
	}
}
void InputData(){
	char ch; int d;
	for (register int i = 0; i < 5; i++){
		scanf(" %c %d", &ch, &d);
		color |= (1 << char2dec(ch));
		straightnum |= 1 << d;
		if (maxnum < d) maxnum = d;
		num[d]++;
	}
}
int solve(){
	int flush = (color & (color - 1)) == 0;
	int straight = (straightnum / (straightnum & -straightnum)) == 31;
	register int i, score = 0; int same[5] = { 0 };
	for (i = 9; i >= 1; i--){
		if (num[i] == 0) continue;
		if (same[num[i]]){
			if (num[i] == 2) same[0] = i;
		}
		else same[num[i]] = i;
	}
	if (flush && straight) score = 900 + same[1];
	else if (same[4]) score = 800 + same[4];
	else if (same[3]){
		if (same[2]) score = 700 + same[3] * 10 + same[2];
		else score = 400 + same[3];
	}
	else if (flush) score = 600 + same[1];
	else if (straight) score = 500 + same[1];
	else if (same[2]){
		if (same[0]) score = 300 + same[2] * 10 + same[0];
		else score = 200 + same[2];
	}
	else score = 100 + same[1];
	return score;
}
int main(){
	InputData();
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}