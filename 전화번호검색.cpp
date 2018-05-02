#include <stdio.h>

struct TRIE{
	bool word;//�ܾ
	TRIE *next[10];
	TRIE(){//������
		word = false; for (register int i = 0; i < 10; i++) next[i] = NULL;
	}
	~TRIE(){//�Ҹ���
		for (register int i = 0; i < 10; i++)
			if (next[i]) delete next[i];
	}

	void insert(char *p){
		if (*p == 0){
			word = true; return;
		}
		int idx = *p - '0'; //���� ������ �迭 �ε����� ���ϱ�
		if (next[idx] == NULL) next[idx] = new TRIE(); //���ο� ����
		next[idx]->insert(p + 1);
	}

	bool check(char *p){
		if (word) return true;//���� �ܾ ���� �ܾ��� ���ξ�
		if (*p == 0) return true;//���� �ܾ ���� �ܾ��� ���ξ�
		int idx = *p - '0';
		if (next[idx] == NULL) return false;//�ϰ��� ����
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
			if (flag) continue;//�̹� �ϰ��� ����
			flag = root->check(str);//�ϰ��� üũ
			if (!flag) root->insert(str);
		}
		printf("%s\n", message[flag]);
	}
	return 0;
}