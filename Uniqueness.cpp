#include <stdio.h>

int N;
char str[10001][24];
int sel[10001];

void InputData(){
	scanf("%d", &N);
	for (register int i = 1; i <= N; i++){
		scanf("%s", str[i]);
	}
}

inline int strcompare(char *a, char *b){
	register int i;
	for (i = 0; a[i] && b[i]; i++) if (a[i] != b[i]) break;
	return a[i] - b[i];
}

void solve(){
	register int i, j; 
	bool uniq = true;
	for (i = 1; i <= N; i++){
		if (sel[i] == 1) continue; //이미 선택되었던 문자열 skip
		bool first = true;
		for (j = i + 1; j <= N; j++){
			if (strcompare(str[i], str[j]) == 0){
				uniq = false; sel[j] = 1;
				if (first){
					printf("%s %d %d", str[i], i, j);
					first = false;
				}
				else printf(" %d", j);
			}
		}
		if (first == false) printf("\n");
	}
	if (uniq) printf("unique\n");
}

int main(){
	InputData();
	solve();

	return 0;
}