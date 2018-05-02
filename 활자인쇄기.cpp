#include <stdio.h>

char sol[25000 * 50];
int ans;//sol�迭�� ����� ����

struct TRIE{
	bool word, leaf, last;//word:�ܾ, leaf:���ܳ��, last:����乮�ڿ�����
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
	void markLast(char *p){//���� �� ���ڿ��� �������� Ž���ϵ��� ǥ��
		last = true;
		if (*p == 0) return;
		next[*p - 'a']->markLast(p + 1);
	}
	void search(){//��� ��� Ž��(���� �� ���ڿ��� �������� Ž��)
		if (word){//�ܾ�ϼ�
			sol[ans++] = 'P';
			if (leaf) return;
		}
		int lastidx = -1;//���� �� ���ڿ��� ���Ե� �ε��� �����(0~25)
		for (register int i = 0; i < 26; i++){
			if (next[i] == NULL) continue;
			if (next[i]->last) {//���� �� ���ڿ��� �������� Ž��
				lastidx = i; continue;
			}
			sol[ans++] = (char)(i + 'a');//���ڸ� Ȱ���μ�⿡ �߰�
			next[i]->search();
			sol[ans++] = '-';//�߰��� ���� ����
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
		root->insert(str);//��� ���ڿ� ���
		int len = strlength(str);
		if (maxlen < len){//���� �� ���ڿ� ã��
			maxlen = len; strcopy(maxstr, str);
		}
	}
	root->markLast(maxstr);//���� �� ���ڿ� ǥ��
	root->search();
	OutputData();
	delete root;
	return 0;
}