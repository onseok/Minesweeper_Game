#include "Minesweeper.h"
#include "Tile.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

namespace kws {
    void printName() {
        cout << "201710321 김원석";
    }
}

Minesweeper::Minesweeper()
    :ROW(0), COL(0), BOMBS_CNT(0)
{
    clearData();
}

Minesweeper::~Minesweeper()
{
}

int Minesweeper::start()
{
    while (true)
    {
        switch (ReadyGame())    //리턴을 받아서 판단.
        {
        case MENU::GAMESTART_LOAD:
            StartGame_Load();
            break;
        case MENU::GAMESTART_EASY:
            StartGame_Easy();
            break;
        case MENU::GAMESTART_STANDARD:
            StartGame_Standard();
            break;
        case MENU::GAMESTART_HARD:
            StartGame_Hard();
            break;
        case MENU::QUIT:
            system("cls");
            return 0;
        }
    }
	
}

void Minesweeper::DrawReadyGame(int para) // 방향키를 움직일 때마다 이 함수가 매번 호출 됨.
{
    system("cls");    //화면을 클리어  함수 입니다.
    gotoxy(1, 1);
    kws::printName();

    PrintLogo(); // 로고 출력

    // 로고 도안 
    //gotoxy(5, 8);
    //cout << "※※※※※※※※※※ ※※※※※※※※※※ ※※※※★★※※※※ ※※※※※※※※※※"; gotoxy(5, 9);
    //cout << "※※※※※※※※※※ ※※※※※※※※※※ ※※※※★★※※※※ ※※※※※※※※※※"; gotoxy(5, 10);
    //cout << "★★★★★★★★★★ ★★★★★★★★★★ ★★★★★★★★★★ ★★★★★★★★★★"; gotoxy(5, 11);
    //cout << "※※※※★★※※※※ ※※※※※※※※※★ ※※※※★★※※※※ ※※※※※※※※※★"; gotoxy(5, 12);
    //cout << "※※※※★★※※※※ ※※※※※※※※※★ ※※※※★★※※※※ ※※※※※※※※※★"; gotoxy(5, 13);
    //cout << "※※※★※※★※※※ ★★★★★★★★★★ ※※※★※※★※※※ ※※※※※※※※※★"; gotoxy(5, 14);
    //cout << "※※★※※※※★※※ ★※※※※※※※※※ ※※★※※※※★※※ ※※※※※※※※※★"; gotoxy(5, 15);
    //cout << "※★※※※※※※★※ ★※※※※※※※※※ ※★※※※※※※★※ ※※※※※※※※※★"; gotoxy(5, 16);
    //cout << "★※※※※※※※※★ ★★★★★★★★★★ ★※※※※※※※※★ ※※※※※※※※※★"; gotoxy(5, 17);
    //cout << "※※※※※※※※※※ ※※※※※※※※※※ ※※※※※※※※※※ ※※※※※※※※※※"; gotoxy(5, 18);
    //cout << "※※※※※※※※※※ ※※※※※※※※※※ ※※※※※※※※※※ ※※※※※※※※※※";


    switch (para) {
    case 2 :
        PrintEasy(4, 25, true);
        break;      
    case 4 :
        PrintStandard(4, 25, true);
        break;
    case 6 :
        PrintHard(4, 25, true);
        break;
    }


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
    
    switch (para) {
    case 0:
        gotoxy(36, 27);
        cout << "가장 최근에 저장했던";
        gotoxy(36, 29);
        cout << " 게임을 불러옵니다";

        gotoxy(20, 24);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 해당 라인 초록색으로 바꿔주기
        gotoxy(19, 24 + para); //위치조정
        cout << "> ";
        cout << "[이어하기]";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
        gotoxy(20, 26);
        cout << "[시작하기] 난이도 하";
        gotoxy(20, 28);
        cout << "[시작하기] 난이도 중";
        gotoxy(20, 30);
        cout << "[시작하기] 난이도 상";
        gotoxy(20, 32);
        cout << "[종료하기]";
        break;
    case 2:
        gotoxy(20, 24);
        cout << "[이어하기]";
        gotoxy(20, 26);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 해당 라인 초록색으로 바꿔주기
        gotoxy(19, 24 + para); //위치조정
        cout << "> ";
        cout << "[시작하기] 난이도 하";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
        gotoxy(20, 28);
        cout << "[시작하기] 난이도 중";
        gotoxy(20, 30);
        cout << "[시작하기] 난이도 상";
        gotoxy(20, 32);
        cout << "[종료하기]";
        break;
    case 4:
        gotoxy(20, 24);
        cout << "[이어하기]";
        gotoxy(20, 26);
        cout << "[시작하기] 난이도 하";
        gotoxy(20, 28);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 해당 라인 초록색으로 바꿔주기
        gotoxy(19, 24 + para); //위치조정
        cout << "> ";
        cout << "[시작하기] 난이도 중";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
        gotoxy(20, 30);
        cout << "[시작하기] 난이도 상";
        gotoxy(20, 32);
        cout << "[종료하기]";
        break;
    case 6:
        gotoxy(20, 24);
        cout << "[이어하기]";
        gotoxy(20, 26);
        cout << "[시작하기] 난이도 하";
        gotoxy(20, 28);
        cout << "[시작하기] 난이도 중";
        gotoxy(20, 30);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 해당 라인 초록색으로 바꿔주기
        gotoxy(19, 24 + para); //위치조정
        cout << "> ";
        cout << "[시작하기] 난이도 상";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
        gotoxy(20, 32);
        cout << "[종료하기]";
        break;
    case 8:
        gotoxy(36, 28);
        cout << " 게임을 종료합니다";
        gotoxy(20, 24);
        cout << "[이어하기]";
        gotoxy(20, 26);
        cout << "[시작하기] 난이도 하";
        gotoxy(20, 28);
        cout << "[시작하기] 난이도 중";
        gotoxy(20, 30);
        cout << "[시작하기] 난이도 상";
        gotoxy(20, 32);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 해당 라인 초록색으로 바꿔주기
        gotoxy(19, 24 + para); //위치조정
        cout << "> ";
        cout << "[종료하기]";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기
        break;
    }

    //gotoxy(20, 24);
    //cout << "[이어하기]";
    //gotoxy(20, 26);
    //cout << "[시작하기] 난이도 하";
    //gotoxy(20, 28);
    //cout << "[시작하기] 난이도 중";
    //gotoxy(20, 30);
    //cout << "[시작하기] 난이도 상";
    //gotoxy(20, 32);
    //cout << "[종료하기]";
}

void Minesweeper::DrawStartGame_Load() 
{
    switch (stage)
    {
    case 1:
        DrawStartGame_Easy();
        break;
    case 2:
        DrawStartGame_Standard();
        break;
    case 3:
        DrawStartGame_Hard();
        break;
    }
}

void Minesweeper::DrawStartGame_Easy()
{
    system("cls");

    gotoxy(1, 1);
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _      _____  _____  _____   _ "; gotoxy(18, 29);
        cout << "| |    |  _  |/  ___||  ___| | |"; gotoxy(18, 30);
        cout << "| |    | | | |\\ `--. | |__   | |"; gotoxy(18, 31);
        cout << "| |    | | | | `--. \\|  __|  | |"; gotoxy(18, 32);
        cout << "| |____\\ \\_/ //\\__/ /| |___  |_|"; gotoxy(18, 33);
        cout << "\\_____/ \\___/ \\____/ \\____/  (_)";

        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        system("cls"); // lose 보여주고 지우기

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);

        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;
      
            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }

        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _    _   _____   _   _   _ "; gotoxy(18, 29);
        cout << "| |  | | |_   _| | \\ | | | |"; gotoxy(18, 30);
        cout << "| |  | |   | |   |  \\| | | |"; gotoxy(18, 31);
        cout << "| |/\\| |   | |   | . ` | | |"; gotoxy(18, 32);
        cout << "\\  /\\  /  _| |_  | |\\  | |_|"; gotoxy(18, 33);
        cout << " \\/  \\/   \\___/  \\_| \\_/ (_)";

        drawTable(); // 게임 승리된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }

        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else {
        //gotoxy(30, 10);
        //cout << "===================================";
        //gotoxy(30, 11);
        //cout << "            난이도 (하)            ";
        //gotoxy(30, 13);
        //cout << "              " << ROW << " X " << COL;
        //gotoxy(30, 15);
        //cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        //gotoxy(30, 16);
        //cout << "===================================";
        //gotoxy(30, 18);
        //cout << " 스페이스 바(SPACE) : 블록 선택하기";
        //gotoxy(30, 20);
        //cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        //gotoxy(30, 22);
        //cout << "   s 키 혹은 S 키   : 게임 저장하기";
        //gotoxy(30, 24);
        //cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        PrintEasy(3, 10, false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);  // 글씨색상 변경 : 어두운 하늘
        gotoxy(5, 19);
        cout << " 난이도 (하)";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색

        drawTable();

        gotoxy(16, 26);
        cout << " _______________  "; gotoxy(16, 27);
        cout << "|__ Space Bar __| " << "   블록 선택하기"; gotoxy(16, 29);
        cout << "     _____        "; gotoxy(16, 30);
        cout << "    |_ F _|       " << "   깃발 표시하기"; gotoxy(16, 32);
        cout << "     _____        "; gotoxy(16, 33);
        cout << "    |_ S _|       " << "   게임 저장하기"; gotoxy(16, 35);
        cout << "     _____        "; gotoxy(16, 36);
        cout << "    |_ C _|       " << "   뒤로 돌아가기";

        gotoxy(36, 29);
        cout << "          ______        "; gotoxy(36, 30);
        cout << "         |_ ↑ _|       ";

        gotoxy(36, 31);
        cout << " ______   ______   ______ "; gotoxy(36, 32);
        cout << "|_ ← _| |_ ↓ _| |_ → _|"; gotoxy(36, 34);
        cout << "       커서 이동하기      ";

        gotoxy(40, 12);
        cout << "지 뢰  개 수"; gotoxy(40, 14);
        cout << "  ********  "; gotoxy(40, 15);
        cout << "  *      *  "; gotoxy(40, 16);
        if(BOMBS_CNT < 10) {
            cout << "  *   " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        }
        cout << "  *  " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        cout << "  *      *  "; gotoxy(40, 18);
        cout << "  ********  ";
    }
}

void Minesweeper::DrawStartGame_Standard()
{
    system("cls");

    gotoxy(1, 1);
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _      _____  _____  _____   _ "; gotoxy(18, 29);
        cout << "| |    |  _  |/  ___||  ___| | |"; gotoxy(18, 30);
        cout << "| |    | | | |\\ `--. | |__   | |"; gotoxy(18, 31);
        cout << "| |    | | | | `--. \\|  __|  | |"; gotoxy(18, 32);
        cout << "| |____\\ \\_/ //\\__/ /| |___  |_|"; gotoxy(18, 33);
        cout << "\\_____/ \\___/ \\____/ \\____/  (_)";

        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        system("cls"); // lose 보여주고 지우기

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }
        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _    _   _____   _   _   _ "; gotoxy(18, 29);
        cout << "| |  | | |_   _| | \\ | | | |"; gotoxy(18, 30);
        cout << "| |  | |   | |   |  \\| | | |"; gotoxy(18, 31);
        cout << "| |/\\| |   | |   | . ` | | |"; gotoxy(18, 32);
        cout << "\\  /\\  /  _| |_  | |\\  | |_|"; gotoxy(18, 33);
        cout << " \\/  \\/   \\___/  \\_| \\_/ (_)";

        drawTable(); // 게임 승리된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }

        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else {
        //gotoxy(30, 10);
        //cout << "===================================";
        //gotoxy(30, 11);
        //cout << "            난이도 (중)            ";
        //gotoxy(30, 13);
        //cout << "              " << ROW << " X " << COL;
        //gotoxy(30, 15);
        //cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        //gotoxy(30, 16);
        //cout << "===================================";
        //gotoxy(30, 18);
        //cout << " 스페이스 바(SPACE) : 블록 선택하기";
        //gotoxy(30, 20);
        //cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        //gotoxy(30, 22);
        //cout << "   s 키 혹은 S 키   : 게임 저장하기";
        //gotoxy(30, 24);
        //cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        PrintStandard(3, 10, false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  // 글씨색상 변경 : 어두운 노랑
        gotoxy(5, 19);
        cout << " 난이도 (중)";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색

        drawTable();

        gotoxy(16, 26);
        cout << " _______________  "; gotoxy(16, 27);
        cout << "|__ Space Bar __| " << "   블록 선택하기"; gotoxy(16, 29);
        cout << "     _____        "; gotoxy(16, 30);
        cout << "    |_ F _|       " << "   깃발 표시하기"; gotoxy(16, 32);
        cout << "     _____        "; gotoxy(16, 33);
        cout << "    |_ S _|       " << "   게임 저장하기"; gotoxy(16, 35);
        cout << "     _____        "; gotoxy(16, 36);
        cout << "    |_ C _|       " << "   뒤로 돌아가기";

        gotoxy(36, 29);
        cout << "          ______        "; gotoxy(36, 30);
        cout << "         |_ ↑ _|       ";

        gotoxy(36, 31);
        cout << " ______   ______   ______ "; gotoxy(36, 32);
        cout << "|_ ← _| |_ ↓ _| |_ → _|"; gotoxy(36, 34);
        cout << "       커서 이동하기      ";

        gotoxy(40, 12);
        cout << "지 뢰  개 수"; gotoxy(40, 14);
        cout << "  ********  "; gotoxy(40, 15);
        cout << "  *      *  "; gotoxy(40, 16);
        if(BOMBS_CNT < 10) {
            cout << "  *   " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        }
        cout << "  *  " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        cout << "  *      *  "; gotoxy(40, 18);
        cout << "  ********  ";
    }
}




void Minesweeper::DrawStartGame_Hard()
{
    system("cls");

    gotoxy(1, 1);
    /*cout << "201710321 김원석";*/
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _      _____  _____  _____   _ "; gotoxy(18, 29);
        cout << "| |    |  _  |/  ___||  ___| | |"; gotoxy(18, 30);
        cout << "| |    | | | |\\ `--. | |__   | |"; gotoxy(18, 31);
        cout << "| |    | | | | `--. \\|  __|  | |"; gotoxy(18, 32);
        cout << "| |____\\ \\_/ //\\__/ /| |___  |_|"; gotoxy(18, 33);
        cout << "\\_____/ \\___/ \\____/ \\____/  (_)";

        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        system("cls"); // lose 보여주고 지우기

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }

        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(18, 28);
        cout << " _    _   _____   _   _   _ "; gotoxy(18, 29);
        cout << "| |  | | |_   _| | \\ | | | |"; gotoxy(18, 30);
        cout << "| |  | |   | |   |  \\| | | |"; gotoxy(18, 31);
        cout << "| |/\\| |   | |   | . ` | | |"; gotoxy(18, 32);
        cout << "\\  /\\  /  _| |_  | |\\  | |_|"; gotoxy(18, 33);
        cout << " \\/  \\/   \\___/  \\_| \\_/ (_)";

        drawTable(); // 게임 승리된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        int _x = 14;
        int _y = 26;
        gotoxy(_x, _y);
        cout << "           ▶   ▶   ▶   ▶   ▶              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // 타일을 열어주는 함수
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
                if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
                }
            }

            Sleep(1000);

            drawTable();
        }

        gotoxy(_x, _y);
        cout << "           ▷   ▷   ▷   ▷   ▷              "; gotoxy(_x + 1, _y + 1);
        cout << "                                               "; gotoxy(_x + 1, _y + 2);
        cout << "______  _____ ______  _       ___  __   __ㅇ   "; gotoxy(_x + 1, _y + 3);
        cout << "| ___ \\|  ___|| ___ \\| |     / _ \\ \\ \\ / /"; gotoxy(_x + 1, _y + 4);
        cout << "| |_/ /| |__  | |_/ /| |    / /_\\ \\ \\ v /   "; gotoxy(_x + 1, _y + 5);
        cout << "|    / |  __| |  __/ | |    |  _  |  \\ /      "; gotoxy(_x + 1, _y + 6);
        cout << "| |\\ \\ | |___ | |    | |____| | | |  | |     "; gotoxy(_x + 1, _y + 7);
        cout << "\\_| \\_|\\____/ \\_|    \\_____/\\_| |_/  \\_/"; gotoxy(_x + 1, _y + 8);
        cout << "                                               "; gotoxy(_x + 1, _y + 9);
        cout << "                                               "; gotoxy(_x + 1, _y + 10);
        cout << "      메뉴로 돌아가려면 c키를 누르세요         "; gotoxy(_x + 1, _y + 11);

        system("pause>nul");
    }
    else {
        //gotoxy(30, 10);
        //cout << "===================================";
        //gotoxy(30, 11);
        //cout << "            난이도 (상)            ";
        //gotoxy(30, 13);
        //cout << "              " << ROW << " X " << COL;
        //gotoxy(30, 15);
        //cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        //gotoxy(30, 16);
        //cout << "===================================";
        //gotoxy(30, 18);
        //cout << " 스페이스 바(SPACE) : 블록 선택하기";
        //gotoxy(30, 20);
        //cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        //gotoxy(30, 22);
        //cout << "   s 키 혹은 S 키   : 게임 저장하기";
        //gotoxy(30, 24);
        //cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        PrintHard(3, 10, false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 글씨색상 변경 : 연한 빨강
        gotoxy(5, 19);
        cout << " 난이도 (상)";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색

        drawTable();

        gotoxy(16, 26);
        cout << " _______________  "; gotoxy(16, 27);
        cout << "|__ Space Bar __| " << "   블록 선택하기"; gotoxy(16, 29);
        cout << "     _____        "; gotoxy(16, 30);
        cout << "    |_ F _|       " << "   깃발 표시하기"; gotoxy(16, 32);
        cout << "     _____        "; gotoxy(16, 33);
        cout << "    |_ S _|       " << "   게임 저장하기"; gotoxy(16, 35);
        cout << "     _____        "; gotoxy(16, 36);
        cout << "    |_ C _|       " << "   뒤로 돌아가기";

        gotoxy(36, 29);
        cout << "          ______        "; gotoxy(36, 30);
        cout << "         |_ ↑ _|       ";

        gotoxy(36, 31);
        cout << " ______   ______   ______ "; gotoxy(36, 32);
        cout << "|_ ← _| |_ ↓ _| |_ → _|"; gotoxy(36, 34);
        cout << "       커서 이동하기      ";

        gotoxy(40, 12);
        cout << "지 뢰  개 수"; gotoxy(40, 14);
        cout << "  ********  "; gotoxy(40, 15);
        cout << "  *      *  "; gotoxy(40, 16);
        if (BOMBS_CNT < 10) {
            cout << "  *   " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        }
        cout << "  *  " << BOMBS_CNT << "  *"; gotoxy(40, 17);
        cout << "  *      *  "; gotoxy(40, 18);
        cout << "  ********  ";
    }
}

double Minesweeper::SelectMapSize_Easy()
{
    system("cls");
    gotoxy(1, 1);
    kws::printName();

    gotoxy(23, 9);
    cout << "난이도 하";

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색
    
    int _x = 14;
    int _y = 11;
    gotoxy(_x, _y);
    cout << "############################################"; gotoxy(_x, _y + 1);
    cout << "##                                        ##"; gotoxy(_x, _y + 2);
    cout << "##  맵 크기의 10% 만큼 폭탄이 생성됩니다  ##"; gotoxy(_x, _y + 3);
    cout << "##                                        ##"; gotoxy(_x, _y + 4);
    cout << "##           숫자 누르고 엔터 X 2         ##"; gotoxy(_x, _y + 5);
    cout << "##                                        ##"; gotoxy(_x, _y + 6);
    cout << "##        ←                     →       ##"; gotoxy(_x, _y + 7);
    cout << "##      ↑ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 8);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 9);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 10);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 11);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 12);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 13);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 14);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 15);
    cout << "##      ↓ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 16);
    cout << "##                                        ##"; gotoxy(_x, _y + 17);
    cout << "############################################"; gotoxy(_x, _y + 18);

    gotoxy(_x + 11, _y + 6);
    cin >> ROW;

    gotoxy(_x + 4, _y + 11);
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }

    //table = make_unique<unique_ptr<Tile[]>[]>(COL + 2);
    //for (int i = 0; i < COL + 2; ++i) {
    //    table[i] = make_unique<Tile[]>(ROW + 2);
    //}

    return 0.1;
}

double Minesweeper::SelectMapSize_Standard()
{
    system("cls");
    gotoxy(1, 1);
    kws::printName();

    gotoxy(23, 9);
    cout << "난이도 중";

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색

    int _x = 14;
    int _y = 11;
    gotoxy(_x, _y);
    cout << "############################################"; gotoxy(_x, _y + 1);
    cout << "##                                        ##"; gotoxy(_x, _y + 2);
    cout << "##  맵 크기의 20% 만큼 폭탄이 생성됩니다  ##"; gotoxy(_x, _y + 3);
    cout << "##                                        ##"; gotoxy(_x, _y + 4);
    cout << "##           숫자 누르고 엔터 X 2         ##"; gotoxy(_x, _y + 5);
    cout << "##                                        ##"; gotoxy(_x, _y + 6);
    cout << "##        ←                     →       ##"; gotoxy(_x, _y + 7);
    cout << "##      ↑ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 8);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 9);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 10);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 11);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 12);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 13);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 14);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 15);
    cout << "##      ↓ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 16);
    cout << "##                                        ##"; gotoxy(_x, _y + 17);
    cout << "############################################"; gotoxy(_x, _y + 18);

    gotoxy(_x + 11, _y + 6);
    cin >> ROW;

    gotoxy(_x + 4, _y + 11);
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }
    //table = make_unique<unique_ptr<Tile[]>[]>(COL + 2);
    //for (int i = 0; i < COL + 2; ++i) {
    //    table[i] = make_unique<Tile[]>(ROW + 2);
    //}

    return 0.2;
}

double Minesweeper::SelectMapSize_Hard()
{
    system("cls");
    gotoxy(1, 1);
    kws::printName();

    gotoxy(23, 9);
    cout << "난이도 상";

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 글씨색상 변경 : 흰색

    int _x = 14;
    int _y = 11;
    gotoxy(_x, _y);
    cout << "############################################"; gotoxy(_x, _y + 1);
    cout << "##                                        ##"; gotoxy(_x, _y + 2);
    cout << "##  맵 크기의 30% 만큼 폭탄이 생성됩니다  ##"; gotoxy(_x, _y + 3);
    cout << "##                                        ##"; gotoxy(_x, _y + 4);
    cout << "##           숫자 누르고 엔터 X 2         ##"; gotoxy(_x, _y + 5);
    cout << "##                                        ##"; gotoxy(_x, _y + 6);
    cout << "##        ←                     →       ##"; gotoxy(_x, _y + 7);
    cout << "##      ↑ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 8);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 9);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 10);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 11);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 12);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 13);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 14);
    cout << "##         □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 15);
    cout << "##      ↓ □□□□□□□□□□□□       ##"; gotoxy(_x, _y + 16);
    cout << "##                                        ##"; gotoxy(_x, _y + 17);
    cout << "############################################"; gotoxy(_x, _y + 18);

    gotoxy(_x + 11, _y + 6);
    cin >> ROW;

    gotoxy(_x + 4, _y + 11);
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }

    //table = make_unique<unique_ptr<Tile[]>[]>(COL + 2);
    //for (int i = 0; i < COL + 2; ++i) {
    //    table[i] = make_unique<Tile[]>(ROW + 2);
    //}

    return 0.3;
}

void Minesweeper::StartGame_Load()
{
    // 파일로부터 ROW, COL 구하기
    ifstream load("data.txt");
    int row_cnt = 0;
    int col_cnt = 0;
    int cnt = 0;
    string line;
    vector<string> test;

    while (getline(load, line)) {
        test.push_back(line);
        if (test[0].length() == test[cnt].length()) {
            col_cnt += 1;
        }
        cnt++;
    }
    row_cnt = test[0].length() / 2;
    
    ROW = row_cnt;
    COL = col_cnt;
    
    load.close();
    // ==========================

    // table 객체 생성
    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }
    //table = make_unique<unique_ptr<Tile[]>[]>(COL + 2);
    //for (int i = 0; i < COL + 2; ++i) {
    //    table[i] = make_unique<Tile[]>(ROW + 2);
    //}
    // ==========================

    // table 초기화
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            table[i][j].clicked = false;
            table[i][j].flag = false;
            table[i][j].val = WALL;
        }
    }
    // =========================

    // table 정보 저장
    ifstream load_2("data.txt");

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            load_2 >> table[i][j].val;
        }
    }

    int bombs_cnt = 0;
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            if (table[i][j].val == BOMB) {
                table[i][j].bomb = true;
                bombs_cnt += 1;
            }
        }
    }
    BOMBS_CNT = bombs_cnt;

    load_2.close();
    // =============================

    // 난이도 판별하기
    if (int(ROW * COL * 0.1) == BOMBS_CNT) {
        stage = 1;
    }
    if (int(ROW * COL * 0.2) == BOMBS_CNT) {
        stage = 2;
    }
    if (int(ROW * COL * 0.3) == BOMBS_CNT) {
        stage = 3;
    }
    // ==============================

    int x = 0;                //커서의 x위치
    int y = 0;                //커서의 y위치
    int input = 0;            //키보드 입력을 받을 변수

    int arr_i;
    int arr_j;

    int width = 50; // 초기 값 설정 (테이블을 가운데 상단에 맞추기 위한 초기변수 설정)
    int height = 30;
    int table_x = (width / 2) - (ROW / 2);
    int table_y = (height / 2) - (COL / 2);

    PrintLoad();

    CursorView(true); // 커서 보이게 하기

    DrawInitGame();

    while (true) {

        DrawStartGame_Load();

        if (y <= 0)        //커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        if (y > COL - 1) //커서가 아래로 그만 내려가게
        {
            y = COL - 1;
        }
        if (x <= 0) {
            x = 0;
        }
        if (x > ROW - 1) {
            x = ROW - 1;
        }


        gotoxy(table_x + x, table_y + y);

        input = _getch();    //키보드 입력을 받았다.
        //→←↑↓
        if (input == MAGIC_KEY)    //받았는데 224네?
        {
            switch (_getch())    //그럼 한번더 받아보자 상하좌우 일수 있으니.
            {
            case UP:            //위
                --y;
                break;
            case DOWN:          //아래
                ++y;
                break;
            case LEFT:          //왼쪽
                --x;
                break;
            case RIGHT:         //오른쪽
                ++x;
                break;
            }
        }
        if (input == SPACE) //키보드 입력 받았는데 스페이스네?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            // 타일을 열어주는 함수
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // c키나 C키를 받을 경우 되돌아가기
            isLose = false;
            isWin = false;
            deleteMem(); // 동적할당한 메모리 삭제하기
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수

            ofstream clear("data.txt");    // s를 누를 때마다 data 파일 비우기
            clear.close();

            ofstream save("data.txt");  // 테이블 정보 저장하기
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // 쓰기모드로 파일 열기
            fstream fin("replay.txt", ios::in); // 읽기 모드로 파일 열기
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY 파일 끝까지 문자 읽기
                fout.put(c); // 읽은 문자 기록
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save를 한 후에 메뉴로 빠져나오기
        }
    }
}

void Minesweeper::StartGame_Easy()
{
    double para = SelectMapSize_Easy();
    init(para);
    
    int x = 0;                //커서의 x위치
    int y = 0;                //커서의 y위치
    int input = 0;            //키보드 입력을 받을 변수

    int arr_i;
    int arr_j;

    int width = 50; // 초기 값 설정 (테이블을 가운데 상단에 맞추기 위한 초기변수 설정)
    int height = 30;
    int table_x = (width / 2) - (ROW / 2);
    int table_y = (height / 2) - (COL / 2);

    PrintLoad(); // 로딩 화면 보이기 

    CursorView(true); // 커서 보이게 하기

    while(true) {

        DrawStartGame_Easy();

        if (y <= 0)        //커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        if (y > COL - 1) //커서가 아래로 그만 내려가게
        {
            y = COL - 1;
        }
        if (x <= 0) {
            x = 0;
        }
        if (x > ROW - 1) { 
            x = ROW - 1;
        }

        gotoxy(table_x + x, table_y + y); 
        
        input = _getch();    //키보드 입력을 받았다.
        //→←↑↓
        if (input == MAGIC_KEY)    //받았는데 224네?
        {
            switch (_getch())    //그럼 한번더 받아보자 상하좌우 일수 있으니.
            {
            case UP:            //위
                --y;
                break;
            case DOWN:          //아래
                ++y;
                break;
            case LEFT:          //왼쪽
                --x;
                break;
            case RIGHT:         //오른쪽
                ++x;
                break;
            }
        }
        if (input == SPACE) //키보드 입력 받았는데 스페이스네?
        {   
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input ,arr_i, arr_j);

            // 타일을 열어주는 함수
            if (!table[arr_i][arr_j].clicked) {
               OpenTile(arr_i, arr_j);

               // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
               if (remainTiles() == BOMBS_CNT) {
                   Win();
                   isWin = true;
               }
               else {
                   isWin = false;
               }
            }
        }
        if (input == 70 || input == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // c키나 C키를 받을 경우 되돌아가기
            isLose = false;
            isWin = false;
            deleteMem(); // 동적할당한 메모리 삭제하기
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수

            ofstream clear("data.txt");    // s를 누를 때마다 data 파일 비우기
            clear.close();

            ofstream save("data.txt");  // 테이블 정보 저장하기
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out|ios::app); // 쓰기모드로 파일 열기
            fstream fin("replay.txt", ios::in); // 읽기 모드로 파일 열기
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY 파일 끝까지 문자 읽기
                fout.put(c); // 읽은 문자 기록
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save를 한 후에 메뉴로 빠져나오기
        }
    }
}

void Minesweeper::StartGame_Standard()
{
    double para = SelectMapSize_Standard();
    init(para);

    int x = 0;                //커서의 x위치
    int y = 0;                //커서의 y위치
    int input = 0;            //키보드 입력을 받을 변수

    int arr_i;
    int arr_j;

    int width = 50; // 초기 값 설정 (테이블을 가운데 상단에 맞추기 위한 초기변수 설정)
    int height = 30;
    int table_x = (width / 2) - (ROW / 2);
    int table_y = (height / 2) - (COL / 2);

    PrintLoad(); // 로딩 화면 보이기 

    CursorView(true); // 커서 보이게 하기

    while (true) {

        DrawStartGame_Standard();

        if (y <= 0)        //커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        if (y > COL - 1) //커서가 아래로 그만 내려가게
        {
            y = COL - 1;
        }
        if (x <= 0) {
            x = 0;
        }
        if (x > ROW - 1) {
            x = ROW - 1;
        }

        gotoxy(table_x + x, table_y + y);

        input = _getch();    //키보드 입력을 받았다.
        //→←↑↓
        if (input == MAGIC_KEY)    //받았는데 224네?
        {
            switch (_getch())    //그럼 한번더 받아보자 상하좌우 일수 있으니.
            {
            case UP:            //위
                --y;
                break;
            case DOWN:          //아래
                ++y;
                break;
            case LEFT:          //왼쪽
                --x;
                break;
            case RIGHT:         //오른쪽
                ++x;
                break;
            }
        }
        if (input == SPACE) //키보드 입력 받았는데 스페이스네?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            // 타일을 열어주는 함수
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // c키나 C키를 받을 경우 되돌아가기
            isLose = false;
            isWin = false;
            deleteMem(); // 동적할당한 메모리 삭제하기
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수

            ofstream clear("data.txt");    // s를 누를 때마다 data 파일 비우기
            clear.close();

            ofstream save("data.txt");  // 테이블 정보 저장하기
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // 쓰기모드로 파일 열기
            fstream fin("replay.txt", ios::in); // 읽기 모드로 파일 열기
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY 파일 끝까지 문자 읽기
                fout.put(c); // 읽은 문자 기록
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save를 한 후에 메뉴로 빠져나오기
        }
    }
}

void Minesweeper::StartGame_Hard() 
{
    double para = SelectMapSize_Hard();
    init(para);

    int x = 0;                //커서의 x위치
    int y = 0;                //커서의 y위치
    int input = 0;            //키보드 입력을 받을 변수

    int arr_i;
    int arr_j;

    int width = 50; // 초기 값 설정 (테이블을 가운데 상단에 맞추기 위한 초기변수 설정)
    int height = 30;
    int table_x = (width / 2) - (ROW / 2);
    int table_y = (height / 2) - (COL / 2);

    PrintLoad(); // 로딩 화면 보이기 

    CursorView(true); // 커서 보이게 하기

    while (true) {

        DrawStartGame_Hard();

        if (y <= 0)        //커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        if (y > COL - 1) //커서가 아래로 그만 내려가게
        {
            y = COL - 1;
        }
        if (x <= 0) {
            x = 0;
        }
        if (x > ROW - 1) {
            x = ROW - 1;
        }

        gotoxy(table_x + x, table_y + y);

        input = _getch();    //키보드 입력을 받았다.
        //→←↑↓
        if (input == MAGIC_KEY)    //받았는데 224네?
        {
            switch (_getch())    //그럼 한번더 받아보자 상하좌우 일수 있으니.
            {
            case UP:            //위
                --y;
                break;
            case DOWN:          //아래
                ++y;
                break;
            case LEFT:          //왼쪽
                --x;
                break;
            case RIGHT:         //오른쪽
                ++x;
                break;
            }
        }
        if (input == SPACE) //키보드 입력 받았는데 스페이스네?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            // 타일을 열어주는 함수
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
            arr_i = y + 1;
            arr_j = x + 1;

            // 데이터 저장 부분
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // c키나 C키를 받을 경우 되돌아가기
            isLose = false;
            isWin = false;
            deleteMem(); // 동적할당한 메모리 삭제하기
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수

            ofstream clear("data.txt");    // s를 누를 때마다 data 파일 비우기
            clear.close();

            ofstream save("data.txt");  // 테이블 정보 저장하기
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // 쓰기모드로 파일 열기
            fstream fin("replay.txt", ios::in); // 읽기 모드로 파일 열기
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY 파일 끝까지 문자 읽기
                fout.put(c); // 읽은 문자 기록
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save를 한 후에 메뉴로 빠져나오기
        }
    }
}

int Minesweeper::QuitGame()
{
    return 0;
}

void Minesweeper::SetBombs(double para)
{
    BOMBS_CNT = (ROW * COL) * para; // 폭탄 개수 : 맵 크기 * para 만큼 생성
    int bombs_cnt = 0;
    while (bombs_cnt != BOMBS_CNT) {
        int x = (rand() % ROW) + 1; // 1~ ROW 까지의 랜덤값
        int y = (rand() % COL) + 1;

        if (table[x][y].val != BOMB) {
            table[x][y].val = BOMB;
            table[x][y].bomb = true;
            bombs_cnt += 1;
        }
    }
}

void Minesweeper::SetNums()
{
    int cnt = 0;

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            if (table[i][j].val != BOMB) {
                // 8방 확인
                for (int m = -1; m <= 1; m++) {
                    for (int n = -1; n <= 1; n++) {
                        if (m == 0 && n == 0) {
                            continue; // 본인
                        }
                        if (table[i + m][j + n].val == BOMB) {
                            cnt += 1;
                        }
                    }
                }
                table[i][j].val = cnt;
                cnt = 0;
            }
        }
    }
}

void Minesweeper::init(double para)
{
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            table[i][j].clicked = false;
            table[i][j].flag = false;
            table[i][j].val = WALL;
        }
    }

    SetBombs(para);
    SetNums();
}

void Minesweeper::OpenTile(int _i, int _j)
{
    table[_i][_j].clicked = true;

    if (table[_i][_j].val == BLANK) {
       OpenBlanks(_i, _j);
    }
    else if (table[_i][_j].val == BOMB) {
        Lose();
    }
}

void Minesweeper::OpenBlanks(int _i, int _j)
{
    if (table[_i][_j].val == WALL) {
        return;
    }

    for (int m = -1; m <= 1; m++) {
        for (int n = -1; n <= 1; n++) {
            // 자기자신은 pass(이미 확인을 한 상태)
            if (m == 0 && n == 0) {
                continue;
            }
            else {
                // 값이 BLANK이고, flag가 아니라면
                if (table[_i + m][_j + n].val == BLANK && table[_i + m][_j + n].flag == false) {
                    // 이미 열려있을 때
                    if (table[_i + m][_j + n].clicked == true) {
                        continue;
                    }
                    // 그 외의 경우는 칸을 열고, 다시 재귀 호출을 함
                    else {
                        table[_i + m][_j + n].clicked = true;
                        OpenBlanks(_i + m, _j + n);
                    }
                }
                // 최말단 숫자인 경우
                else if (table[_i + m][_j + n].val >= 1 && table[_i + m][_j + n].val <= 8) {
                    table[_i + m][_j + n].clicked = true;
                    continue; // 숫자를 만나면 더 이상 8방 확인은 안하고 딱 거기까지만 하도록
                }
            }
        }
    }
}

int Minesweeper::remainTiles()
{
    int cnt = 0;

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            if (table[i][j].clicked == false) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

void Minesweeper::Win()
{
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            table[i][j].flag = true;
        }
    }
}

void Minesweeper::Lose()
{
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            if (table[i][j].flag == true && table[i][j].val == BOMB) {
                table[i][j].flag = true;
            }
            else if (table[i][j].flag == true && table[i][j].val != BOMB) {
                table[i][j].flag = false;
            }
            table[i][j].clicked = true;
        }
    }
    isLose = true;
}

void Minesweeper::deleteMem()
{
    for (int i = 0; i < COL + 2; i++) {
        delete table[i];
    }
    delete table;
    table = nullptr;
}

void Minesweeper::saveData(int _k, int _i, int _j)
{   
    if (!isLose && !isWin) { // 이기거나 지기 전까지만 데이터를 저장함
        ofstream save("replay.txt", ios::app);
        save << _k << " " << _i << " " << _j << endl;
        save.close();
    }
}

void Minesweeper::clearData()
{
    ofstream clear("replay.txt");
    clear.close();
}

void Minesweeper::drawTable()
{
    //int y = 10;

    //gotoxy(10, y);

    //for (int i = 1; i <= COL; i++) {
    //    for (int j = 1; j <= ROW; j++) {
    //        cout << table[i][j].state();
    //    }
    //    gotoxy(10, ++y);
    //}
    int width = 50; // 초기 값 설정 (테이블을 가운데 상단에 맞추기 위한 초기변수 설정)
    int height = 30;
    int table_x = (width / 2) - (ROW / 2);
    int table_y = (height / 2) - (COL / 2);

    gotoxy(table_x, table_y);

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            cout << table[i][j].state();
        }
        gotoxy(table_x, ++table_y);
    }

    gotoxy((width / 2) - 2, (height / 2) - (COL / 2) - 2);
    cout << ROW << "  X  " << COL;




}

void Minesweeper::DrawInitGame()
{
    ifstream loadData("data.txt");
    string line;
    vector<string> replay;
    int cnt = 0;
    int keyboard, _x, _y;

    //리플레이 맨 마지막 적용

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            loadData >> dump[i][j];
        }
    }

    while (!loadData.eof()) {

        loadData >> keyboard >> _x >> _y;

        if (keyboard == SPACE) {
            // 타일을 열어주는 함수
            if (!table[_x][_y].clicked) {
                OpenTile(_x, _y);

                // 남은 UNCLICK 개수 (FLAG와 무관)가 폭탄개수와 동일하면 승리
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        else if (keyboard == 70 || keyboard == 102) {  // f키나 F키를 받을 경우 (깃발 생성)
            if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
            }
        }
    }
}

void Minesweeper::PrintLogo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  // 글씨색상 변경 : 초록색 (그린조아~)
    gotoxy(3, 8);
    cout << "                                                        ※※                             "; gotoxy(3, 9);
    cout << "                                                        ※※                             "; gotoxy(3, 10);
    cout << "※※※※※※※※※※    ※※※※※※※※※※    ※※※※※※※※※※    ※※※※※※※※※"; gotoxy(3, 11);
    cout << "        ※※                              ※            ※※                            ※"; gotoxy(3, 12);
    cout << "        ※※                              ※            ※※                            ※"; gotoxy(3, 13);
    cout << "      ※    ※          ※※※※※※※※※※          ※    ※                          ※"; gotoxy(3, 14);
    cout << "    ※        ※        ※                          ※        ※                        ※"; gotoxy(3, 15);
    cout << "  ※            ※      ※                        ※            ※                      ※"; gotoxy(3, 16);
    cout << "※                ※    ※※※※※※※※※※    ※                ※                    ※";
}

void Minesweeper::PrintSave()
{
    //system("cls");
    //gotoxy(20, 20);
    //cout << "저     장     중  . . .";
    //CursorView(false); // 커서 숨기기
    //Sleep(1000);

    system("cls");  // 디자인 변경 (아스키코드 변환 사이트)
    gotoxy(12, 15);
    cout << " _____                      _                               "; gotoxy(12, 16);
    cout << "/  ___|                    (_)                              "; gotoxy(12, 17);
    cout << "\\ `--.     __ _   __   __   _    _ __      __ _             "; gotoxy(12, 18);
    cout << " `--. \\   / _` |  \\ \\ / /  | |  | '_ \\    / _` |            "; gotoxy(12, 19);
    cout << "/\\__/ /  | (_| |   \\ V /   | |  | | | |  | (_| |    _  _  _ "; gotoxy(12, 20);
    cout << "\\____/    \\__,_|    \\_/    |_|  |_| |_|   \\__, |   (_)(_)(_)"; gotoxy(12, 21);
    cout << "                                           __/ |            "; gotoxy(12, 22);
    cout << "                                          |___/             "; gotoxy(12, 23);
    CursorView(false); // 커서 숨기기
    Sleep(1000);
}

void Minesweeper::PrintQuit()
{
    //system("cls");
    //gotoxy(20, 20);
    //cout << "나   가   는   중  . . .";
    //CursorView(false); // 커서 숨기기
    //Sleep(800);

    system("cls");
    gotoxy(12, 15);
    cout << " _____    _                    _                              "; gotoxy(12, 16);
    cout << "/  __ \\  | |                  (_)                             "; gotoxy(12, 17);
    cout << "| /  \\/  | |    ___     ___    _    _ __      __ _            "; gotoxy(12, 18);
    cout << "| |      | |   / _ \\   / __|  | |  | '_ \\    / _` |           "; gotoxy(12, 19);
    cout << "| \\__/\\  | |  | (_) |  \\__ \\  | |  | | | |  | (_| |   _  _  _ "; gotoxy(12, 20);
    cout << " \\____/  |_|   \\___/   |___/  |_|  |_| |_|   \\__, |  (_)(_)(_)"; gotoxy(12, 21);
    cout << "                                              __/ |           "; gotoxy(12, 22);
    cout << "                                             |___/            "; gotoxy(12, 23);
    CursorView(false); // 커서 숨기기
    Sleep(1000);
}

void Minesweeper::PrintLoad()
{
    //system("cls");
    //gotoxy(20, 20);
    //cout << "불  러  오  는  중  . . ."; 
    //CursorView(false); // 커서 숨기기
    //Sleep(1000);

    system("cls");
    gotoxy(10, 15);
    cout << " _                           _   _                             "; gotoxy(10, 16);
    cout << "| |                         | | (_)                            "; gotoxy(10, 17);
    cout << "| |       ___     __ _    __| |  _   _ __     __ _             "; gotoxy(10, 18);
    cout << "| |      / _ \\   / _` |  / _` | | | | '_ \\   / _` |            "; gotoxy(10, 19);
    cout << "| |____ | (_) | | (_| | | (_| | | | | | | | | (_| |  _   _   _ "; gotoxy(10, 20);
    cout << "\\_____/  \\___/   \\__,_|  \\__,_| |_| |_| |_|  \\__, | (_) (_) (_)"; gotoxy(10, 21);
    cout << "                                              __/ |            "; gotoxy(10, 22);
    cout << "                                             |___/             "; gotoxy(10, 23);
    CursorView(false); // 커서 숨기기
    Sleep(1000);
}

void Minesweeper::PrintEasy(int _x, int _y, bool check)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);  // 글씨색상 변경 : 어두운 하늘

    gotoxy(_x, _y);
    cout << "※※※※※※※※※※"; gotoxy(_x, _y + 1);
    cout << "        ※※        "; gotoxy(_x, _y + 2);
    cout << "        ※※        "; gotoxy(_x, _y + 3);
    cout << "        ※※※      "; gotoxy(_x, _y + 4);
    cout << "        ※※※※    "; gotoxy(_x, _y + 5);
    cout << "        ※※  ※※  "; gotoxy(_x, _y + 6);
    cout << "        ※※        "; gotoxy(_x, _y + 7);
    cout << "        ※※        "; 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기

    if (check) {
        gotoxy(36, 27);
        cout << " 맵 크기의 10% 만큼";
        gotoxy(36, 29);
        cout << " 폭탄을 생성합니다";
    }
}

void Minesweeper::PrintStandard(int _x, int _y, bool check)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  // 글씨색상 변경 : 어두운 노랑

    gotoxy(_x, _y);
    cout << "        ※※        "; gotoxy(_x, _y + 1);
    cout << "        ※※        "; gotoxy(_x, _y + 2);
    cout << "  ※※※※※※※※  "; gotoxy(_x, _y + 3);
    cout << "  ※    ※※    ※  "; gotoxy(_x, _y + 4);
    cout << "  ※    ※※    ※  "; gotoxy(_x, _y + 5);
    cout << "  ※※※※※※※※  "; gotoxy(_x, _y + 6);
    cout << "        ※※        "; gotoxy(_x, _y + 7);
    cout << "        ※※        ";     
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기

    if (check) {
        gotoxy(36, 27);
        cout << " 맵 크기의 20% 만큼";
        gotoxy(36, 29);
        cout << " 폭탄을 생성합니다";
    }
}

void Minesweeper::PrintHard(int _x, int _y, bool check)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 글씨색상 변경 : 연한 빨강색

    gotoxy(_x, _y);
    cout << "        ※※        "; gotoxy(_x, _y + 1);
    cout << "        ※※        "; gotoxy(_x, _y + 2);
    cout << "        ※※        "; gotoxy(_x, _y + 3);
    cout << "        ※※※※   "; gotoxy(_x, _y + 4);
    cout << "        ※※        "; gotoxy(_x, _y + 5);
    cout << "        ※※        "; gotoxy(_x, _y + 6);
    cout << "        ※※        "; gotoxy(_x, _y + 7);
    cout << "  ※※※※※※※※"; gotoxy(_x, _y + 8);
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 나머지 텍스트 색깔 흰색으로 바꿔주기

    if (check) {
        gotoxy(36, 27);
        cout << " 맵 크기의 30% 만큼";
        gotoxy(36, 29);
        cout << " 폭탄을 생성합니다";
    }
}

MENU Minesweeper::ReadyGame()
{
    CursorView(false); // 커서 숨기기
    int y = 0;                // 커서의 y위치
    int input = 0;            // 키보드 입력을 받을 변수

    while (true)            // 게임 루프
    {

        //-------------------
        if (y <= 0)        // 커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        else if (y >= 8) //커서가 아래로 그만 내려가게
        {
            y = 8;
        }

        DrawReadyGame(y);    // 준비화면 그리기


        //-------------------

        input = _getch();    //키보드 입력을 받았다.
        //→←↑↓
        if (input == MAGIC_KEY)    //받았는데 224네?
        {
            switch (_getch())    //그럼 한번더 받아보자 상하좌우 일수 있으니.
            {
            case UP:            //위
                y = y - 2;
                break;
            case DOWN:            //아래
                y = y + 2;
                break;
            }
        }
        else if (input == SPACE) //키보드 입력 받았는데 스페이스네?
        {
            switch (y)            //y위치에 따라 판단
            {
            case 0:
                return MENU::GAMESTART_LOAD;
            case 2:
                return MENU::GAMESTART_EASY;
            case 4:
                return MENU::GAMESTART_STANDARD;
            case 6:
                return MENU::GAMESTART_HARD;
            case 8:
                return MENU::QUIT;
            }
        }
    }
}

