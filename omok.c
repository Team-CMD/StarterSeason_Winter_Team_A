# include "omok.h"

int game_control(int map[MAX_Scale][MAX_Scale]){
	// 전체적인 게임의 흐름을 제어하는 함수
	int count_W = 0, count_B = 0; // count = 같은 색의 돌 갯수 체크 변수
	
	for (int y = 0; y < MAX_Scale; y++)
	{
		count_W = 0 , count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0

		for (int x = 0; x < MAX_Scale; x++)
		{
			if (map[y][x] == 0) { // 현 위치의 돌이 흑돌이면 count_B 증가
				count_B++;
			}
			else
				count_B = 0;

			if (map[y][x] == 1) { // 현 위치의 돌이 백돌이면 count_W 증가
				count_W++;
			}
			else
				count_W = 0;

			if (count_B == 5)
				return 0;
			else if (count_W == 5)
				return 1;
			else 
			{
				continue;
			}
		}
	}
	
	
	// 세로가 5개인 경우
	for (int x = 0; x < MAX_Scale; x++)
	{
		count_W = 0, count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0

		for (int y = 0; y < MAX_Scale; y++)
		{
			if (map[y][x] == 0) { // 현 위치의 돌이 흑돌이면 count_B 증가
				count_B++;
			}
			else
				count_B = 0;

			if (map[y][x] == 1) { // 현 위치의 돌이 백돌이면 count_W 증가
				count_W++;
			}
			else
				count_W = 0;

			if (count_B == 5)
				return 0;
			else if (count_W == 5)
				return 1;
			else
			{
				continue;
			}
		}
	}
	
	
	// 왼쪽 위에서 오른쪽 아래 대각선(↘)이 5개인 경우
	for (int y = 0; y < 15; y++) // 대각선으로 5개가 되려면 x = 15 까지가 최대
	{
		count_W = 0, count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0

		for (int x = 0; x < 15; x++) // 대각선으로 5개가 되려면 y = 15 까지가 최대
		{
			for (int i = 0; i < 5; i++) // 대각선에 존재하는 흑돌,백돌이 연속으로 5개 존재할 수 있는 경우의 수 모두 체크(중복 없이)
			{
				if (map[y+i][x+i] == 0)
					count_B++;
				else
					count_B = 0;

				if (map[y+i][x+i] == 1)
					count_W++;
				else
					count_W = 0;

				if (count_B == 5)
					return 0;
				else if (count_W == 5)
					return 1;
				else
					continue;
			}
		}
	}
	// 오른쪽 위에서 왼쪽 아래 대각선(↙)이  5개인 경우
	for (int x = 4; x < MAX_Scale; x++) // 대각선으로 5개가 되려면 최소 x = 4  최대 MAX_Scale까지 
	{
		count_W = 0, count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0

		for (int y = 0; y < 15; y++) // 대각선으로 5개가 되려면 y = 15 까지가 최대
		{
			for (int i = 0; i < 5; i++) // 대각선에 존재하는 흑돌,백돌이 연속으로 5개 존재할 수 있는 경우의 수 모두 체크(중복 없이)
			{
				if (map[y + i][x - i] == 0)
					count_B++;
				else
					count_B = 0;

				if (map[y + i][x - i] == 1)
					count_W++;
				else
					count_W = 0;

				if (count_B == 5)
					return 0;
				else if (count_W == 5)
					return 1;
				else
					continue;
			}
		}
	}

}

void gotoxy(){
    // 화면상의 커서 위치를 파악하고 제어하는 함수
};

void show_stone(){
    // 바둑돌을 보여주는 함수
};

void move_position(){
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
};

void show_map(){
    //바둑판을 보여주는 함수
};
