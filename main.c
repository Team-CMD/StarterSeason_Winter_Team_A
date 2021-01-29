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

// Import Header file
# include "omok.h"

// Main Function
int main() {

    int choice = 0;

    while (1)
    {
        system("cls");
        printf("                                                  Starter Season_Winter_Team A\n");
        printf("-------------------------------(Omok Game Rule)-------------------------------\n");
        printf("* 같은 색의 돌을 가로, 세로, 대각선으로 5개를 놓으면 승리\n");
        printf("* 선공은 흑돌\n");
        printf("* 키보드 방향키로 움직이고 스페이스바로 돌을 놓을 수 있습니다.\n");
        printf("------------------------------------------------------------------------------\n");        
        printf("1. Game start\n");
        printf("2. Exit\n");
        printf("------------------------------------------------------------------------------\n");
        printf("input : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            show_stone();
            gotoxy(0, 23);
            printf("아무키를 누르시면 최초화면으로 돌아갑니다.\n");
            _getch();
            break;
        case 2:
            return;
        default:
            break;
        }
    }
    
    return 0;
}
