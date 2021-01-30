# include "omok.h"

void game_control(void){
    // 전체적인 게임의 흐름을 제어하는 함수
};

void gotoxy(int x, int y){
    // 화면상의 커서 위치를 파악하고 제어하는 함수
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
};

void show_stone(){
    // 바둑돌을 보여주는 함수
};

void move_position(char key, int* x1, int* y1, int x_b, int y_b) {
    // 사용자가 입력하는 화살표 키에 따라 좌표 x, y값을 변경하는 함수
    switch (key) {
        case 72:// 상 방향키 
            *y1 = *y1 - 1;
            if (*y1 < 1)   *y1 = 1;
            break;
        case 75:// 좌 방향키
            *x1 = *x1 - 1;    // 좌측으로 2씩 감소
            if (*x1 < 1)   *x1 = 1; // x축의 최대값
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