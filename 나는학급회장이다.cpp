#include <stdio.h>

int score[4]; //[0~9bits]3의개수, [10bits~]점수

void InputData(){
	register int i, j; int N;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= 3; j++){
			scanf("%d", &d);
			score[i] += (d << 10) + (d == 3);
		}
	}
}
int solve(){
	register int maxid = 1, i;
	for (i = 2; i <= 3; i++){
		if (score[maxid] < score[i]) maxid = i;
		else if (score[maxid] == score[i]){
			maxid = 0; score[0] = score[i];
		}
	}
	return maxid;
}
int main(){
	InputData();
	int ans = solve();
	printf("%d %d\n", ans, score[ans] >> 10);
	return 0;
}