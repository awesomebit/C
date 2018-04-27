#include <stdio.h>

struct NODE{
	int data; NODE* next;
	NODE(){ //������(default
		data = 0;
		next = NULL;
	}
	NODE(int d, NODE* q){
		data = d;
		next = q;
	}
};

struct QUEUE{
	NODE* head; NODE* tail; int cnt;
	QUEUE(){ //������
		head = tail = new NODE(0, NULL);
		cnt = 0;
	}
	~QUEUE(){ //�Ҹ���
		while (!empty()) pop(); delete head;
	}
	bool empty(){
		return cnt == 0; //head == tail
	}
	int size(){
		return cnt;
	}
	int front(){
		return head->next->data;
	}
	int back(){
		return tail->data;
	}
	void push(int data){
		tail->next = new NODE(data, NULL);	//dummy ��� ���
		tail = tail->next;
		cnt++;
	}
	void pop(){
		NODE* tmp = head;
		head = head->next;
		delete tmp;
		cnt--;
	}
};

int main(){
	int N; char cmd; int data; register int i;
	QUEUE * queue = new QUEUE();
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf(" %c", &cmd);
		switch (cmd){
		case 'i'://push
			scanf("%d", &data); 
			queue->push(data);
			break;
		case 'c'://size
			printf("%d\n", queue->size());
			break;
		case 'o'://front, pop
			if (queue->empty()) printf("empty\n");
			else {
				printf("%d\n", queue->front()); 
				queue->pop();
			}
		}
	}
	delete queue;
	return 0;
}