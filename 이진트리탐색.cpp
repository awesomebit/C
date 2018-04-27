#include <stdio.h>
struct TREE{
	int data;
	TREE *left, *right;
	TREE(){
		scanf("%d", &data);	//preorder
		if (data == -1){ //leaf node
			left = right = NULL;
			return;
		}
		left = new TREE(); //full binary tree
		right = new TREE();
	}
	~TREE(){
		delete left; delete right;
	}
	void preorder(){
		if (data == -1) return;
		printf("%d ", data);
		left->preorder();
		right->preorder();
	}
	void inorder(){
		if (data == -1) return;
		left->inorder();
		printf("%d ", data);
		right->inorder();
	}
	void postorder(){
		if (data == -1) return;
		left->postorder();
		right->postorder();
		printf("%d ", data);
	}
};

int main(){
	TREE* root = new TREE(); //입력받고 트리 생성
	root->postorder(); printf("\n");
	delete root;
	return 0;
}