# include "omok.h"

void game_control(void){
    // 전체적인 게임의 흐름을 제어하는 함수
};

void gotoxy(){
    // 화면상의 커서 위치를 파악하고 제어하는 함수
};

void show_stone()     // 바둑돌을 놓는 함수
{
	char key; // 키보드 입력받는 변수
	int x = 0, y = 1, x_b = 38, y_b = 20, order = 0; // x, y = x,y좌표, x_b,y_b = 각 축의 최댓값, order = 돌 놓는 순서 구분 변수
	int* x1 = &x, * y1 = &y;
	int map[MAX_Scale][MAX_Scale];
	char* stone_color[2] = { "○", "●" };
	//int end = 3;

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
				/*end = game_control();
				if (end == 0) // 흑돌이 이긴다면 반환값 0.
				{
					gotoxy(1, 21);
					printf("검은돌이 이겼습니다.");
					break; // 승자가 나오면 종료.
				}*/
				order = 1; // 다음 순서를 위해 값 변경
			}
			else // 돌이 하양이라면
			{
				map[y][x] = order; // 현재 위치에 1(백돌임을 알려줌)을 저장
				/*end = game_control();
				if (end == 1) // 백돌이 이긴다면 반환값 1.
				{
					gotoxy(1, 21);
					printf("백돌이 이겼습니다.");
					break; // 승자가 나오면 종료.
				}*/
				order = 0; // 다음 순서를 위해 값 변경
			}
		}
	}
	return 0;
}

void move_position(){
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
};

void show_map(){
    //바둑판을 보여주는 함수
};
