#include <stdio.h>

struct NODE{
	int data; NODE *next;
	NODE()
	{//持失切(default)
		data = 0; 
		next = NULL;
	}
	NODE(int d, NODE *p)
	{//持失切
		data = d; 
		next = p;
	}
};

struct STACK{
	NODE *head; int cnt;
	STACK()
	{//持失切(default)
		head = NULL; 
		cnt = 0;
	}
	~STACK()
	{//社瑚切
		while (!empty()) pop();
	}
	bool empty()
	{
		return cnt == 0;//head == NULL
	}
	int size()
	{
		return cnt;
	}
	void push(int data)
	{
		head = new NODE(data, head); 
		cnt++;
	}
	int front()
	{
		return head->data;
	}
	void pop()
	{
		NODE *temp = head; 
		head = head->next; 
		delete temp; 
		cnt--;
	}
};

int main(){
	int N; char cmd; int data; register int i;
	STACK * stack = new STACK();
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf(" %c", &cmd);
		switch (cmd)
		{
		case 'i'://push
			scanf("%d", &data); 
			stack->push(data);
			break;
		case 'c'://size
			printf("%d\n", stack->size());
			break;
		case 'o'://front, pop
			if (stack->empty()) printf("empty\n");
			else 
			{
				printf("%d\n", stack->front()); 
				stack->pop();
			}
		}
	}
	delete stack;
	return 0;
}