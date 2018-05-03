#include <stdio.h>

//hash table 활용

typedef unsigned long long ull;
int N;
struct DATA{
	char str[24]; ull code; int idx;
};
DATA data[10001];
struct NODE{
	DATA* data;
	NODE* next;
	NODE(){ data = NULL; next = NULL; }
	NODE(DATA *a, NODE *b){ data = a; next = b; }
	~NODE(){ delete next; }
};
struct LIST{
	NODE *head, *tail;
	LIST(){ head = tail = new NODE(NULL, NULL); }
	~LIST(){ delete head; }
	void push(DATA *a){
		tail->next = new NODE(a, NULL);
		tail = tail->next;
	}
};
LIST* list[10000];
int sel[10001];
#define MOD (10000)

inline ull hash(char* c){
	ull hash = 5381;
	for (register int i = 0; c[i]; i++){
		hash = hash * 33 + c[i];
	}
	return hash;
}

void init(){
	for (register int i = 0; i < MOD; i++){
		if (list[i]) delete list[i];
		list[i] = new LIST();
		sel[i + 1] = 0;
	}
}

void InputData(){
	scanf("%d", &N);
	for (register int i = 1; i <= N; i++){
		scanf("%s", data[i].str);
		sel[i] = 0; data[i].code = hash(data[i].str); data[i].idx = i;
		list[data[i].code % MOD]->push(&data[i]);
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
	for (i = 1; i < N; i++){
		if (sel[i] == 1) continue; //이미 선택되었던 문자열 skip
		int count = 0;
		NODE* cur = list[data[i].code % MOD]->head->next;
		for (; cur; cur = cur->next){
			if (strcompare(data[i].str, cur->data->str) == 0){
				++count; sel[cur->data->idx] = 1;
				if (count == 2){
					printf("%s %d %d", data[i].str, i, cur->data->idx);
					uniq = false;
				}
				else if (count > 2){
					printf(" %d", cur->data->idx);
				}
			}
		}
		if (count > 1) printf("\n");
	}
	if (uniq) printf("unique\n");
}

int main(){
	init();
	InputData();
	solve();
	return 0;
}