#include <stdio.h>

struct NODE{
	char ch;
	NODE *next, *prev;
	NODE(){
		ch = 0; next = prev = NULL;
	}
	NODE(char a, NODE *p){
		ch = a; prev = p; next = p->next;
	}
	void selfdel(){
		prev->next = next; next->prev = prev; delete this;
	}
};

struct LINE{
	NODE *head, *tail, *cur;
	LINE(){
		head = new NODE(); tail = new NODE();
		head->next = tail; tail->prev = head; cur = head;
	}
	~LINE(){
		delete head; delete tail;
	}
	void left(){
		if (cur == head) return;//�� ��
		cur = cur->prev;
	}
	void right(){
		if (cur->next == tail) return;//�� ��
		cur = cur->next;
	}
	void del(){
		if (cur == head) return;//�� ��
		cur = cur->prev; cur->next->selfdel();
	}
	void insert(char ch){
		cur = new NODE(ch, cur); cur->prev->next = cur->next->prev = cur;
	}
	void print(){
		while (head->next != tail){
			printf("%c", head->next->ch);
			head->next->selfdel();
		}
		printf("\n");
	}
};

LINE * line;
char str[1000000 + 10];

int main(){
	int T; register int i, j;
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%s", str);
		delete line; line = new LINE();
		for (j = 0; str[j]; j++){
			switch (str[j]){
			case '-'://����
				line->del();
				break;
			case '<'://Ŀ�� �������� �̵�
				line->left();
				break;
			case '>'://Ŀ�� ���������� �̵�
				line->right();
				break;
			default://���� �߰�
				line->insert(str[j]);
			}
		}
		line->print();
	}
}