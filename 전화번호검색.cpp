#include <stdio.h>

struct TRIE{
	bool word;//단어끝
	TRIE *next[10];
	TRIE(){//생성자
		word = false; for (register int i = 0; i < 10; i++) next[i] = NULL;
	}
	~TRIE(){//소멸자
		for (register int i = 0; i < 10; i++)
			if (next[i]) delete next[i];
	}

	void insert(char *p){
		if (*p == 0){
			word = true; return;
		}
		int idx = *p - '0'; //현재 문자의 배열 인덱스로 구하기
		if (next[idx] == NULL) next[idx] = new TRIE(); //새로운 문자
		next[idx]->insert(p + 1);
	}

	bool check(char *p){
		if (word) return true;//이전 단어가 현재 단어의 접두어
		if (*p == 0) return true;//현재 단어가 이전 단어의 접두어
		int idx = *p - '0';
		if (next[idx] == NULL) return false;//일관성 있음
		return next[idx]->check(p + 1);
	}
};

char *message[] = { "YES", "NO" };

int main(){
	int T, N; char str[20]; register int i, j;
	TRIE *root = NULL;
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%d", &N);
		delete root; root = new TRIE(); bool flag = false;
		for (j = 0; j < N; j++){
			scanf("%s", str);
			if (flag) continue;//이미 일관성 없음
			flag = root->check(str);//일관성 체크
			if (!flag) root->insert(str);
		}
		printf("%s\n", message[flag]);
	}
	return 0;
}