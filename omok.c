# include "omok.h"

void game_control(void){
    // 전체적인 게임의 흐름을 제어하는 함수
};

void show_stone(){
    // 바둑돌을 보여주는 함수
};

void move_position(){
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
};


void gotoxy(int x, int y){//화면상의 커서 위치를 파악하고 제어하는 함수
	COORD Pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void show_map(){//바둑판을 보여주는 함수
	gotoxy(0, 0);
	int i, j = 0;
	for(i = 0; i < MAX_Scale; i++){
		for (j = 0; j < MAX_Scale; j++) {
			gotoxy(j, i);
			if(i == 0){
				if(j == 0)
					printf("┌");
				else if(j == MAX_Scale - 1)
					printf("┐");
				else
					printf("┬"); 
			}
			else if(j == 0){
				if(i == MAX_Scale - 1)
					printf("└");
				else
					printf("├");
			}
			else if(j == MAX_Scale - 1){
				if(i == MAX_Scale - 1)
					printf("┘");
				else
					printf("┤");
			}
			else if(i == MAX_Scale - 1){
				printf("┴");
			}
			else
				printf("┼"); 
		}
		printf("\n");
	}
	for (i = 0; i < MAX_Scale; i++) {
		gotoxy(MAX_Scale, i);
		printf("%d", i+1);
		gotoxy(i, MAX_Scale);
		printf("%d", i+1);
		}
	}
