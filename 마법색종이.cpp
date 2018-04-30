#include <stdio.h>

int maxarea, minarea;

struct TREE{

	int sr, sc, er, ec, color;//시작세로가로, 끝세로가로, 색(0:흰색, 1:검은색)

	TREE *left, *right;

	TREE(){

		sr = sc = er = ec = color = 0; left = right = NULL;

	}

	TREE(int a, int b, int c, int d, int e){

		sr = a; sc = b; er = c; ec = d; color = e;

		left = right = NULL;

	}

	~TREE(){

		delete left; delete right;

	}

	void slice(int r, int c){

		if (left == NULL){//leaf 노드 임

			if (color == 0){//수평선으로 자름

				left = new TREE(sr, sc, r, ec, 1);

				right = new TREE(r, sc, er, ec, 1);

			}

			else{//수직선으로 자름

				left = new TREE(sr, sc, er, c, 0);

				right = new TREE(sr, c, er, ec, 0);

			}

			return;

		}

		if (left->check(r, c)) left->slice(r, c);

		else right->slice(r, c);

	}

	bool check(int r, int c){

		if ((sr <= r) && (r <= er) && (sc <= c) && (c <= ec)) return true;

		return false;

	}

	void calArea(){

		if (left == NULL){//leaf노드만 조각임

			int area = (er - sr)*(ec - sc);

			if (maxarea < area) maxarea = area;

			if (minarea > area) minarea = area;

			return;

		}

		left->calArea();

		right->calArea();

	}

};

int main(){

	int C, R, N, c, r;

	scanf("%d %d", &C, &R);

	TREE *tree = new TREE(0, 0, R, C, 0);

	scanf("%d", &N);

	for (register int i = 1; i <= N; i++){

		scanf("%d %d", &c, &r);

		tree->slice(r, c);

	}

	maxarea = 0; minarea = 40000 * 40000 + 10;

	tree->calArea();

	printf("%d %d\n", maxarea, minarea);

	delete tree;

	return 0;

}