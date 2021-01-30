/*
============================================================
                    CMD_Winter Mini Ptj
    1. 담당 팀 : Starter Season_Winter_Team_A, B
    2. ptj 목적 : 오목
    3. 해당 기능 ▼
        01. 게임 규칙 보여주기
        02. 바둑판 표시하기
        03. 화살표 키에 따라 바둑돌의 위치가 변경되게 하고 스페이스바를 이용해 바둑돌 놓기
        04. 오목의 승패를 구분할 수 있기
============================================================
*/
# ifndef OMOK_H
# define OMOK_H
// Pre-definition keywords
# define MAX_Scale 19 // 바둑판의 크기 지정 (기본 바둑판 크기가 19X19 size )
# define paint_B printf("○") // 흑돌 출력문
# define paint_W printf("●") // 백돌 출력문
# define W 2 // 백돌 정의
# define B 1 // 흑돌 정의

// Import Header file
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <windows.h>

# define MAX_Scale 19 // 바둑판의 크기 지정
# define paint_B printf("○") // 흑돌 출력문
# define paint_W printf("●") // 백돌 출력문
# define W 2 // 백돌 정의
# define B 1 // 흑돌 정의

// Custom Function Declaration
void game_control();
void gotoxy(int x, int y);
void show_stone();
void move_position(char key, int *x1, int *y1, int x_b, int y_b);
void show_map();
// etc...

# endif
