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
	for (int y = 0; y < 15; y++) // 대각선으로 5개가 되려면 y = 15 까지가 최대
	{	
		for (int x = 0; x < 15; x++) // 대각선으로 5개가 되려면 x = 15 까지가 최대
		{
			count_W = 0, count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0
			
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
		for (int y = 0; y < 15; y++) // 대각선으로 5개가 되려면 y = 15 까지가 최대
		{
			count_W = 0, count_B = 0; // 줄마다 갯수 체크를 위해 count_W = 0, count_B = 0
			
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

void gotoxy(int x, int y){
    // 화면상의 커서 위치를 파악하고 제어하는 함수
    COORD Pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
};

void show_stone()     // 바둑돌을 놓는 함수
{
	char key; // 키보드 입력받는 변수
	int x = 0, y = 0, x_b = 18, y_b = 18, order = 0; // x, y = x,y좌표, x_b,y_b = 각 축의 최댓값, order = 돌 놓는 순서 구분 변수
	int* x1 = &x, * y1 = &y;
	int map[MAX_Scale][MAX_Scale];
	char* stone_color[2] = { "○", "●" };
	int end = 3;

	gotoxy(x, y);
	show_map();

	while (1)
	{
		gotoxy(x, y);
		key = _getch(); // 키입력받음

		if (key >= 72) // 입력받은 값이 이동값이면
		{
			move_position(key, x1, y1, x_b, y_b); // 움직이는 함수 호출
		}
		else if (key == 32) // 입력받은 값이 스페이스바이면
		{
			printf("%s", stone_color[order]); // 현재 좌표위치에 돌을 놓는다.

			if (order == 0) // 돌이 검정이라면
			{
				map[y][x] = order; // 현재 위치에 0(검은돌임을 알려줌)을 저장
				end = game_control(map);
				if (end == 0) // 흑돌이 이긴다면 반환값 0.
				{
					gotoxy(1, 21);
					printf("검은돌이 이겼습니다.");
					break; // 승자가 나오면 종료.
				}
				order = 1; // 다음 순서를 위해 값 변경
			}
			else // 돌이 하양이라면
			{
				map[y][x] = order; // 현재 위치에 1(백돌임을 알려줌)을 저장
				end = game_control(map);
				if (end == 1) // 백돌이 이긴다면 반환값 1.
				{
					gotoxy(1, 21);
					printf("백돌이 이겼습니다.");
					break; // 승자가 나오면 종료.
				}
				order = 0; // 다음 순서를 위해 값 변경
			}
		}
	}

	return 0;
}

void move_position(char key, int* x1, int* y1, int x_b, int y_b) {
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
    switch (key) {
        case 72:// 상 방향키 
            *y1 = *y1 - 1;
            if (*y1 < 1)   *y1 = 0;
            break;
        case 75:// 좌 방향키
            *x1 = *x1 - 1;    // 좌측으로 2씩 감소
            if (*x1 < 1)   *x1 = 0; // x축의 최대값
            break;
        case 77:// 우 방향키
            *x1 = *x1 + 1; //오른쪽 방향의 화살표 키 입력, 우측으로 2씩 증가
            if (*x1 > x_b)  *x1 = x_b;
            break;
        case 80:// 하 방향키
            *y1 = *y1 + 1; //아래쪽 방향의 화살표 키 입력
            if (*y1 > y_b)   *y1 = y_b; // y축의 최대값
            break;
        default:
            return;
    }
};

void show_map(){
    //바둑판을 보여주는 함수
};
