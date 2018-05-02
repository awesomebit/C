#define MAXN (30000)

struct WOOD{

	int code, minh, diff, id;//3진법코드, 최소높이, 최대높이-최소높이, 나무번호

	WOOD(){

		code = minh = diff = id = 0;

	}

	WOOD(int a, int b, int c, int d){

		code = a; minh = b; diff = c; id = d;

	}

};

WOOD A[MAXN]; WOOD RA[MAXN]; WOOD tmp[MAXN];

int used[MAXN];//사용여부

void init(){

	register int i;

	for (i = 0; i < MAXN; i++) used[i] = 0;//초기화

}

int calcode(int a[4][4]){

	register int i, j, minidx = 0; int arr[4] = { 0 };

	for (i = 0; i < 4; i++){

		for (j = 0; j < 4; j++){

			arr[0] = arr[0] * 3 + a[i][j];//0도

			arr[1] = arr[1] * 3 + a[j][3 - i];//270도

			arr[2] = arr[2] * 3 + a[3 - i][3 - j];//180도

			arr[3] = arr[3] * 3 + a[3 - j][i];//90도

		}

	}

	for (i = 1; i < 4; i++) if (arr[minidx] > arr[i]) minidx = i;

	return arr[minidx];

}

void makeWood(int module[4][4], int id){

	register int i, j, maxh = 0, minh = 10, diff; int ra[4][4]; int a[4][4];

	for (i = 0; i < 4; i++){

		for (j = 0; j < 4; j++){

			if (maxh < module[i][j]) maxh = module[i][j];

			if (minh > module[i][j]) minh = module[i][j];

		}

	}

	diff = maxh - minh;//차

	for (i = 0; i < 4; i++){

		for (j = 0; j < 4; j++){

			a[i][j] = module[i][j] - minh;

			ra[i][3 - j] = diff - a[i][j];//좌우반전, 높이반전

		}

	}

	A[id] = WOOD(calcode(a), minh, diff, id);

	RA[id] = WOOD(calcode(ra), minh, diff, id);

}

inline bool comp(WOOD *arr, int i, int j){

	if ((arr[i].code == arr[j].code) && (arr[i].minh >= arr[j].minh)) return true;

	else if (arr[i].code < arr[j].code) return true;

	return false;

}

void sort(WOOD *arr, int s, int e){

	if (s >= e) return;

	register int i = s, k = s, m = (s + e) / 2, j = m + 1;

	sort(arr, s, m); sort(arr, m + 1, e);

	while ((i <= m) && (j <= e)){

		if (comp(arr, i, j)) tmp[k++] = arr[i++];

		else tmp[k++] = arr[j++];

	}

	while (i <= m) tmp[k++] = arr[i++];

	while (j <= e) tmp[k++] = arr[j++];

	for (i = s; i <= e; i++) arr[i] = tmp[i];

}

int solve(){

	sort(A, 0, MAXN - 1); sort(RA, 0, MAXN - 1);//1순위:code 오름차순, 2순위:minh 내림차순

	register int i = 0, j = 0, sum = 0;

	while ((i < MAXN) && (j < MAXN)){

		while ((i < MAXN) && used[A[i].id]) i++;//사용하지 않은 블럭 선택

		while ((j < MAXN) && used[RA[j].id]) j++;//사용하지 않은 블럭 선택

		if ((i == MAXN) || (j == MAXN)) break;

		if (A[i].id == RA[j].id) {//선택한 두개의 블럭 아이디가 동일

			i++; continue;

		}

		if (A[i].code == RA[j].code){//결합됨

			sum += A[i].minh + RA[j].minh + RA[j].diff;

			used[A[i].id] = 1; used[RA[j].id] = 1;

			i++; j++;

		}

		else if (A[i].code < RA[j].code) i++;

		else j++;

	}

	return sum;

}

int makeTree(int module[][4][4]){

	int ans = 0; register int i;

	init();

	for (i = 0; i < MAXN; i++) makeWood(module[i], i);

	ans = solve();

	return ans;

}