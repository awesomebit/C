
​/// ============== user code start ==============
#if 1

typedef struct Data{

	int strike;

	int ball;

} Data;




#endif // 1



/// ============== submit code start ==============


#define MAXN (5040)

int database[MAXN][6];	//[0]~[3]숫자, [4]:strike, [5]:ball
int datacnt;	//database에 저장된 개수
extern Data query(int supose[]);

inline int checkPossible(int suppose[]){
	int num[10] = { 0 }; register int i, j;
	for (i = 0; i < 4; i++){
		if (num[suppose[i]]) return 0;	//중복된 숫자 있음
		num[suppose[i]] = 1;
	}
	for (i = 0; i < datacnt; i++){
		int strike = 0, ball = 0;
		for (j = 0; j < 4; j++){
			if (suppose[j] == database[i][j]) strike++;
			else if (num[database[i][j]] == 1) ball++;
		}
		if ((database[i][4] != strike) || (database[i][5] != ball)) return 0;
	}
	return 1;
}

void tryBest(int suppose[]){
	datacnt = 0;	//초기화
	for (register int a = 123; a <= 9876; a++){
		suppose[0] = a / 1000; suppose[1] = a % 1000 / 100;
		suppose[2] = a % 100 / 10; suppose[3] = a % 10;
		if (checkPossible(suppose) == 0) continue;	//데이터 베이스와 비교, 정답후보만 쿼리
		Data ret = query(suppose);
		if (ret.strike == 4) return;	//정답
		//데이터 베이스에 추가
		for (register int i = 0; i < 4; i++) database[datacnt][i] = suppose[i];
		database[datacnt][4] = ret.strike; database[datacnt][5] = ret.ball;
		datacnt++;
	}
}

​/// ============== submit code end ============== ​



/// ============== ​user code end   ============== ​









/// ===== main_code ============================================================​



#include <stdio.h>

#include <stdlib.h>

#include <time.h>



#define MAX          4

#define MAX_COUNT 2520

#define _CRT_SECURE_NO_WARNINGS 



static int baseballNumbers[MAX];

static int numbersCheck[10];



static int T;



extern void tryBest(int suppose[]); ////************



static int queryCallCount;



static const int queryLimit = 110;

static int scoreTable[MAX_COUNT + 5];



typedef struct Data{

	int strike;

	int ball;

} Data;



static bool isAble(int suppose[]) {

	int supposeCheck[10];



	for (int count = 0; count < 10; ++count) supposeCheck[count] = 0;

	for (int idx = 0; idx < MAX; ++idx) {

		if (suppose[idx] < 0 || suppose[idx] >= 10 || supposeCheck[suppose[idx]] > 0) return false;

		supposeCheck[suppose[idx]]++;

	}

	return true;

}



Data query(int suppose[]) {

	Data result;

	if (queryCallCount > MAX_COUNT) {

		result.strike = -1;

		result.ball = -1;

		return result;

	}



	queryCallCount++;



	if (!isAble(suppose)) {

		result.strike = -1;

		result.ball = -1;

		return result;

	}



	result.strike = 0;

	result.ball = 0;



	for (int idx = 0; idx < MAX; ++idx)

		if (suppose[idx] == baseballNumbers[idx])

			result.strike++;

		else if (numbersCheck[suppose[idx]] > 0)

			result.ball++;



	return result;

}



static void initialize() {

	for (int count = 0; count < 10; ++count) numbersCheck[count] = 0;

	for (int idx = 0; idx < MAX;) {

		int c = rand() % 10;

		if (numbersCheck[c] == 0)
		{
			baseballNumbers[idx] = c;

			numbersCheck[c]++;

			idx++;
		}
	}
	queryCallCount = 0;

}



static bool check(int suppose[]) {

	for (int idx = 0; idx < MAX; ++idx)

	{

		if (suppose[idx] != baseballNumbers[idx])

			return false;

	}

	return true;

}





void initScoreTable(){

	int i;

	for (i = 0; i <= 10; ++i) scoreTable[i] = 100;

	for (; i <= queryLimit; ++i) scoreTable[i] = 110 - i;

}





int main() {

	int total_score = 0;



	//freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);



	//scanf("%d", &T);

	T = 50;

	initScoreTable();

	srand((unsigned int)time(NULL));

	for (int testcase = 1; testcase <= T; ++testcase) {

		initialize();



		int suppose[MAX];

		tryBest(suppose);



		if (!check(suppose)){

			queryCallCount = MAX_COUNT;

			total_score = 0;

			break;

		}

		printf("#%d %d : ", testcase, queryCallCount);

		for (int i = 0; i < 4; ++i) printf("%d", suppose[i]);

		puts("");

		if (queryCallCount > queryLimit)

			queryCallCount = queryLimit;

		total_score += scoreTable[queryCallCount];

	}

	printf("Total Score = %d\n", total_score / T);



	return 0;

}
