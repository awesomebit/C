#include <stdio.h>

char sol[25000 * 50];
int ans;//sol배열에 저장된 개수

struct TRIE{
	bool word, leaf, last;//word:단어끝, leaf:종단노드, last:가장긴문자열포함
	TRIE *next[26];
	TRIE(){
		last = word = false; leaf = true;
		for (register int i = 0; i < 26; i++) next[i] = NULL;
	}
	~TRIE(){
		for (register int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(char *p){
		if (*p == 0){
			word = true; return;
		}
		int idx = *p - 'a';
		if (next[idx] == NULL) {
			next[idx] = new TRIE(); leaf = false;
		}
		next[idx]->insert(p + 1);
	}
	void markLast(char *p){//가장 긴 문자열은 마지막에 탐색하도록 표시
		last = true;
		if (*p == 0) return;
		next[*p - 'a']->markLast(p + 1);
	}
	void search(){//모든 노드 탐색(가장 긴 문자열은 마지막에 탐색)
		if (word){//단어완성
			sol[ans++] = 'P';
			if (leaf) return;
		}
		int lastidx = -1;//가장 긴 문자열이 포함된 인덱스 저장용(0~25)
		for (register int i = 0; i < 26; i++){
			if (next[i] == NULL) continue;
			if (next[i]->last) {//가장 긴 문자열은 마지막에 탐색
				lastidx = i; continue;
			}
			sol[ans++] = (char)(i + 'a');//글자를 활자인쇄기에 추가
			next[i]->search();
			sol[ans++] = '-';//추가한 글자 제거
		}
		if (lastidx > -1){
			sol[ans++] = (char)(lastidx + 'a');
			next[lastidx]->search();
		}
	}
};

void OutputData(){
	printf("%d\n", ans);
	for (register int i = 0; i < ans; i++) printf("%c\n", sol[i]);
}

inline int strlength(char *a){
	register int cnt;
	for (cnt = 0; a[cnt]; cnt++);
	return cnt;
}

inline void strcopy(char *dst, char *src){
	register int i;
	for (i = 0; src[i]; i++) dst[i] = src[i];
	dst[i] = 0;
}

int main(){
	int T; char str[30]; int maxlen = 0; char maxstr[30];
	scanf("%d", &T);
	TRIE *root = new TRIE();
	for (register int i = 0; i < T; i++){
		scanf("%s", str);
		root->insert(str);//모든 문자열 등록
		int len = strlength(str);
		if (maxlen < len){//가장 긴 문자열 찾기
			maxlen = len; strcopy(maxstr, str);
		}
	}
	root->markLast(maxstr);//가장 긴 문자열 표시
	root->search();
	OutputData();
	delete root;
	return 0;
}