#include <iostream>

#include <stdlib.h>

#include <ctime>

#define MAXSIZE 100000
using namespace std;
static int org[MAXSIZE], dat[MAXSIZE];
static int arrCount, QueryCount;
extern void array_restore(int arrCount, int dat[]);


///////////////////////////////////////////////////
#define MAXN (100000+10)
extern int orderCheck(int left, int right);
int idx[MAXN];
int tmp[MAXN];
void sort(int s, int e){
	if (s >= e) return;
	register int i = s, k = s, m = (s + e) / 2, j = m + 1;
	sort(s, m); sort(m + 1, e);
	while ((i <= m) && (j <= e)){
		if (orderCheck(idx[i], idx[j]) == 1) tmp[k++] = idx[i++];
		else tmp[k++] = idx[j++];
	}
	while (i <= m) tmp[k++] = idx[i++];
	while (j <= e) tmp[k++] = idx[j++];
	for (i = s; i <= e; i++) idx[i] = tmp[i];
}
void array_restore(int arrCount, int dat[]){
	// implement here
	register int i;
	for (i = 0; i < arrCount; i++) idx[i] = i;
	sort(0, arrCount - 1);
	for (i = 0; i < arrCount; i++) dat[idx[i]] = i + 1;
}




int orderCheck(int left, int right)
{
	QueryCount++;
	if (org[left] < org[right]) return 1;
	else return 0;
}

inline void Swap(int&a, int&b){
	int t = a; a = b; b = t;
}

static void init(int t)
{
	int i, j;
	QueryCount = 0;
	arrCount = rand() % 2000 + t * 2000;

	for (i = 0; i < arrCount; i++) {
		org[i] = i + 1;
		dat[i] = 0;
	}
	for (i = 0; i < arrCount; i++){
		j = (int)((long long)rand() * rand() % arrCount);
		Swap(org[i], org[j]);
	}
}

int arr_comp()
{
	if (QueryCount >= arrCount * 20) return MAXSIZE * 100;

	for (int i = 0; i < arrCount; i++) {
		if (org[i] != dat[i]) return MAXSIZE * 100;
	}
	return QueryCount;
}

int main(void)
{
	srand(time(NULL));

	for (int tc = 0; tc < 50; tc++)
	{
		init(tc);
		array_restore(arrCount, dat);
		cout << "#" << tc << " " << arrCount << " " << arr_comp() << endl;
	}

	return 0;
}
