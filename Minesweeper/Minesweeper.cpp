#include "Minesweeper.h"
#include "Tile.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;


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
            LoadGame();
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

void Minesweeper::DrawReadyGame()
{
    system("cls");    //화면을 클리어 해주는 함수 입니다.
    gotoxy(1, 1);
    cout << "201710321 김원석";
    gotoxy(7, 5);
    cout << "******************************";
    gotoxy(7, 6);
    cout << "*        지뢰찾기 게임       *";
    gotoxy(7, 7);
    cout << "******************************";
    gotoxy(10, 10);
    cout << "[이어하기]";
    gotoxy(10, 12);
    cout << "[시작하기] 난이도 하";
    gotoxy(10, 14);
    cout << "[시작하기] 난이도 중";
    gotoxy(10, 16);
    cout << "[시작하기] 난이도 상";
    gotoxy(10, 18);
    cout << "[종료하기]";
}

void Minesweeper::DrawLoadGame()
{
    system("cls");
    gotoxy(1, 1);
    cout << "201710321 김원석";
    gotoxy(10, 10);
    cout << "기능 준비중...";
}

void Minesweeper::DrawStartGame_Easy()
{
    system("cls");

    gotoxy(1, 1);
    cout << "201710321 김원석";

    if (isLose && !isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 오 버            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▶  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▷  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  메뉴로 돌아가려면 C키를 누르세요";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 승 리             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c 키 혹은 C 키  : 메뉴로 돌아가기";
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            난이도 (하)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " 스페이스 바(SPACE) : 블록 선택하기";
        gotoxy(30, 20);
        cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        gotoxy(30, 22);
        cout << "   s 키 혹은 S 키   : 게임 저장하기";
        gotoxy(30, 24);
        cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        drawTable();
    }


}

void Minesweeper::DrawStartGame_Standard()
{
    system("cls");

    gotoxy(1, 1);
    cout << "201710321 김원석";

    if (isLose && !isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 오 버            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▶  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▷  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  메뉴로 돌아가려면 C키를 누르세요";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 승 리             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c 키 혹은 C 키  : 메뉴로 돌아가기";
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            난이도 (중)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " 스페이스 바(SPACE) : 블록 선택하기";
        gotoxy(30, 20);
        cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        gotoxy(30, 22);
        cout << "   s 키 혹은 S 키   : 게임 저장하기";
        gotoxy(30, 24);
        cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        drawTable();
    }


}

void Minesweeper::DrawStartGame_Hard()
{
    system("cls");

    gotoxy(1, 1);
    cout << "201710321 김원석";

    if (isLose && !isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 오 버            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // 게임 오버된 상태 보여주기

        Sleep(3000); // 3초 후에 리플레이 시작

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▶  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";


        for (int i = 1; i <= COL; i++) {
            for (int j = 1; j <= ROW; j++) {
                table[i][j].clicked = false;
                table[i][j].flag = false;
            }
        }
        isLose = false;
        isWin = false;

        drawTable();

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ▷  리 플 레 이           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  메뉴로 돌아가려면 C키를 누르세요";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            게 임 승 리             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c 키 혹은 C 키  : 메뉴로 돌아가기";
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            난이도 (상)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         폭탄 갯수 => " << BOMBS_CNT << "개";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " 스페이스 바(SPACE) : 블록 선택하기";
        gotoxy(30, 20);
        cout << "   f 키 혹은 F 키   : 깃발 표시하기";
        gotoxy(30, 22);
        cout << "   s 키 혹은 S 키   : 게임 저장하기";
        gotoxy(30, 24);
        cout << "   c 키 혹은 C 키   : 뒤로 돌아가기";

        drawTable();
    }


}

double Minesweeper::SelectMapSize_Easy()
{
    system("cls");
    gotoxy(1, 1);
    cout << "201710321 김원석";
    gotoxy(10, 8);
    cout << "난이도 하 (맵 크기의 10% 지뢰 생성)";
    gotoxy(10, 10);
    cout << "맵의 가로 크기 입력 : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "맵의 세로 크기 입력 : ";
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }

    return 0.1;
}

double Minesweeper::SelectMapSize_Standard()
{
    system("cls");
    gotoxy(1, 1);
    cout << "201710321 김원석";
    gotoxy(10, 8);
    cout << "난이도 중 (맵 크기의 20% 지뢰 생성)";
    gotoxy(10, 10);
    cout << "맵의 가로 크기 입력 : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "맵의 세로 크기 입력 : ";
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }

    return 0.2;
}

double Minesweeper::SelectMapSize_Hard()
{
    system("cls");
    gotoxy(1, 1);
    cout << "201710321 김원석";
    gotoxy(10, 8);
    cout << "난이도 상 (맵 크기의 30% 지뢰 생성)";
    gotoxy(10, 10);
    cout << "맵의 가로 크기 입력 : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "맵의 세로 크기 입력 : ";
    cin >> COL;

    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }

    return 0.3;
}

void Minesweeper::LoadGame()
{
    DrawLoadGame();
    system("pause>nul");
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

        gotoxy(10 + x, 10 + y); 
        
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
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수
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

        gotoxy(10 + x, 10 + y);

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
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수
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

        gotoxy(10 + x, 10 + y);

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
            break;
        }
        if (input == 83 || input == 115) { // s나 S키를 받을 경우 게임 저장하기
            // 게임을 저장하는 함수
        }
    }
}

int Minesweeper::QuitGame()
{
    return 0;
}

void Minesweeper::SetBombs(double para)
{
    BOMBS_CNT = (ROW * COL) * para; // 폭탄 개수 : 맵 크기의 10% 생성
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
}

void Minesweeper::saveData(int _k, int _i, int _j)
{   
    if (!isLose && !isWin) { // 이기거나 지기 전까지만 데이터를 저장함
        ofstream save("data.txt", ios::app);
        save << _k << " " << _i << " " << _j << endl;
        save.close();
    }
}

void Minesweeper::clearData()
{
    ofstream clear("data.txt");
    clear.close();
}

void Minesweeper::replay()
{

}

void Minesweeper::drawTable()
{
    int y = 10;

    gotoxy(10, y);

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            cout << table[i][j].state();
        }
        gotoxy(10, ++y);
    }
}

MENU Minesweeper::ReadyGame()
{
    int y = 0;                //커서의 y위치
    int input = 0;            //키보드 입력을 받을 변수
    while (true)            //게임 루프
    {
        DrawReadyGame();    //준비화면 그리기

        //-------------------
        //DrawUserCursor 함수
        if (y <= 0)        //커서가 위로 그만 올라가게 
        {
            y = 0;
        }
        else if (y >= 8) //커서가 아래로 그만 내려가게
        {
            y = 8;
        }

        gotoxy(9, 10 + y); //위치조정
        cout << ">";
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

