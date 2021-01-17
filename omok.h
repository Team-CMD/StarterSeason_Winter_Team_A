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
// Import Header file
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <windows.h>

// Custom Function Declaration
void game_control(void);
void gotoxy();
void show_stone();
void move_position();
void show_map();
// etc...

# endif