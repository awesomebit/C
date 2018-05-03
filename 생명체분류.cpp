#include <stdio.h>

struct TRIE{
	int group; //종 개수
	TRIE *next[26];
	TRIE(){
		group = 0;
		for (register int i = 0; i < 26; i++) next[i] = NULL;
	}
	~TRIE(){
		for (register int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(char *p){
		group++;
		if (*p == 0) return;
		int idx = *p - 'A';
		if (next[idx] == NULL) next[idx] = new TRIE();
		next[idx]->insert(p + 1);
	}
	int getGroup(char *p){
		if (*p == 0) return group;
		int idx = *p - 'A';
		if (next[idx] == NULL) return 0; //이런 종으로 시작하는 종 없음
		return next[idx]->getGroup(p + 1);
	}
};

TRIE *root;

int main(){
	int T, N; register int i, j; char str[20]; char cmd;
	scanf("%d", &T);
	for (i = 1; i <= T; i++){
		scanf("%d", &N);
		delete root; root = new TRIE();
		for (j = 1; j <= N; j++){
			scanf(" %c %s", &cmd, str);
			if (cmd == 'I') root->insert(str);
			else printf("%d ", root->getGroup(str));
		}
		printf("\n");
	}
	return 0;
}