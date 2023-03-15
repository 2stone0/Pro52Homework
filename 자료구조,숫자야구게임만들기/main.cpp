#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int duplicate_Check(int* P_N, int* C_N, int* count, bool* b1);
bool bool_check(int* P_N, int* C_N, bool* b1);
int main()
{
	int Com_num[3] = { 0 };// 컴퓨터 랜덤
	int Player_num[3] = { 0 }; //Player 입력
	int count = 0;
	bool b1 = true;
	printf("숫자 3개를 입력해주세요.\n");
	printf("중복X, 숫자0~9사이 숫자\n");
	printf("숫자 사이 간격을 띄워주세요.\n");
	printf("입력예시: 123(x) 1 2 3(o)\n");
	printf("종료를 원하시면 0 0 0 입력해주세요.\n");
start:
	do //랜덤 숫자 생성
	{
		Com_num[0] = rand() % 10;
		Com_num[1] = rand() % 10;
		Com_num[2] = rand() % 10;
	} while (Com_num[0] == Com_num[1] || Com_num[1] == Com_num[2] || Com_num[0] == Com_num[2]);
	//printf("ramdom:%d %d %d\n", Com_num[0], Com_num[1], Com_num[2]);//test
	while (b1)
	{
		count++;
		scanf_s("%d %d %d", &Player_num[0], &Player_num[1], &Player_num[2]);
		if (Player_num[0] == 0 && Player_num[1] == 0 && Player_num[2] == 0)
		{
			return 0;
		}
		printf("%d번째 도전: %d %d %d\n", count, Player_num[0], Player_num[1], Player_num[2]);
		duplicate_Check(Player_num, Com_num, &count,&b1); //숫자 제대로 입력되었는지 체크
		if (count == 9)
		{
			printf("실패입니다.\n");
		}
	}
	goto start;
	
	//printf("함수후%d %d %d\n", Player_num[0], Player_num[1], Player_num[2]);//test
}

int duplicate_Check(int* P_N, int* C_N, int* count, bool* b1) //중복 체크
{
	int i = 0;
	
	for (int j = 0; j < 3; j++)//while로 바꾸기
	{
		if (P_N[j] > 9)
		{
			printf("숫자는 0~9사이의 숫자만 입력가능합니다.\n");
			*count -= 1;
			return 0;
		}
	}

	if (P_N[0] == P_N[i + 1] || P_N[i] == P_N[i + 2] || P_N[i + 1] == P_N[i + 2])
	{
		printf("숫자를 다시 입력해주세요. 숫자 중복 안됩니다.\n");
		*count -= 1;
		return 0;
	}
	bool_check(P_N, C_N,b1);
}

bool bool_check(int* P_N, int* C_N,bool *b1) //ball,out,strike 출력 
{
	int a = 0;
	int s_num = 0;

	for (int i = 0; i < 3; i++)
	{

		if (P_N[i] == C_N[i])
		{
			printf("Strike ");
			s_num += 1;
		}
		else if (P_N[i] != C_N[0] && P_N[i] != C_N[1] && P_N[i] != C_N[2])
		{
			printf("Out ");
		}
		else
			printf("Ball ");
	}
	printf("\n");
	if (s_num == 3) 
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("정답입니다. 축하드립니다.\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		*b1 = false;
		return *b1;
	}
	s_num = 0;
}

