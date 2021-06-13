#include "Minesweeper.h"
#include "Tile.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

namespace kws {
    void printName() {
        cout << "201710321 �����";
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
        switch (ReadyGame())    //������ �޾Ƽ� �Ǵ�.
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

void Minesweeper::DrawReadyGame()
{
    system("cls");    //ȭ���� Ŭ����  �Լ� �Դϴ�.
    gotoxy(1, 1);
    kws::printName();

    // �ΰ� ���� 
    //gotoxy(5, 8);
    //cout << "�ءءءءءءءءء� �ءءءءءءءءء� �ءءءءڡڡءءء� �ءءءءءءءءء�"; gotoxy(5, 9);
    //cout << "�ءءءءءءءءء� �ءءءءءءءءء� �ءءءءڡڡءءء� �ءءءءءءءءء�"; gotoxy(5, 10);
    //cout << "�ڡڡڡڡڡڡڡڡڡ� �ڡڡڡڡڡڡڡڡڡ� �ڡڡڡڡڡڡڡڡڡ� �ڡڡڡڡڡڡڡڡڡ�"; gotoxy(5, 11);
    //cout << "�ءءءءڡڡءءء� �ءءءءءءءءء� �ءءءءڡڡءءء� �ءءءءءءءءء�"; gotoxy(5, 12);
    //cout << "�ءءءءڡڡءءء� �ءءءءءءءءء� �ءءءءڡڡءءء� �ءءءءءءءءء�"; gotoxy(5, 13);
    //cout << "�ءءءڡءءڡءء� �ڡڡڡڡڡڡڡڡڡ� �ءءءڡءءڡءء� �ءءءءءءءءء�"; gotoxy(5, 14);
    //cout << "�ءءڡءءءءڡء� �ڡءءءءءءءء� �ءءڡءءءءڡء� �ءءءءءءءءء�"; gotoxy(5, 15);
    //cout << "�ءڡءءءءءءڡ� �ڡءءءءءءءء� �ءڡءءءءءءڡ� �ءءءءءءءءء�"; gotoxy(5, 16);
    //cout << "�ڡءءءءءءءء� �ڡڡڡڡڡڡڡڡڡ� �ڡءءءءءءءء� �ءءءءءءءءء�"; gotoxy(5, 17);
    //cout << "�ءءءءءءءءء� �ءءءءءءءءء� �ءءءءءءءءء� �ءءءءءءءءء�"; gotoxy(5, 18);
    //cout << "�ءءءءءءءءء� �ءءءءءءءءء� �ءءءءءءءءء� �ءءءءءءءءء�";



    PrintLogo(); //�ΰ� ���

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // ������ �ؽ�Ʈ ���� ������� �ٲ��ֱ�
    
    gotoxy(20, 24);
    cout << "[�̾��ϱ�]";
    gotoxy(20, 26);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(20, 28);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(20, 30);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(20, 32);
    cout << "[�����ϱ�]";
}

void Minesweeper::DrawStartGame_Load() // ����Ű�� ������ ������ �� �Լ��� �Ź� ȣ�� ��.
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
    /*cout << "201710321 �����";*/
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // ���� ������ ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;
      
            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";

        drawTable(); // ���� �¸��� ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            ���̵� (��)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         ��ź ���� => " << BOMBS_CNT << "��";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " �����̽� ��(SPACE) : ��� �����ϱ�";
        gotoxy(30, 20);
        cout << "   f Ű Ȥ�� F Ű   : ��� ǥ���ϱ�";
        gotoxy(30, 22);
        cout << "   s Ű Ȥ�� S Ű   : ���� �����ϱ�";
        gotoxy(30, 24);
        cout << "   c Ű Ȥ�� C Ű   : �ڷ� ���ư���";

        drawTable();
    }
}

void Minesweeper::DrawStartGame_Standard()
{
    system("cls");

    gotoxy(1, 1);
    /*cout << "201710321 �����";*/
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // ���� ������ ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c Ű Ȥ�� C Ű  : �޴��� ���ư���";

        drawTable(); // ���� �¸��� ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            ���̵� (��)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         ��ź ���� => " << BOMBS_CNT << "��";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " �����̽� ��(SPACE) : ��� �����ϱ�";
        gotoxy(30, 20);
        cout << "   f Ű Ȥ�� F Ű   : ��� ǥ���ϱ�";
        gotoxy(30, 22);
        cout << "   s Ű Ȥ�� S Ű   : ���� �����ϱ�";
        gotoxy(30, 24);
        cout << "   c Ű Ȥ�� C Ű   : �ڷ� ���ư���";

        drawTable();
    }


}

void Minesweeper::DrawStartGame_Hard()
{
    system("cls");

    gotoxy(1, 1);
    /*cout << "201710321 �����";*/
    kws::printName();

    if (isLose && !isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��            ";
        gotoxy(30, 14);
        cout << "===================================";


        drawTable(); // ���� ������ ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else if (!isLose && isWin) {
        CursorView(false);

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c Ű Ȥ�� C Ű  : �޴��� ���ư���";

        drawTable(); // ���� �¸��� ���� �����ֱ�

        Sleep(3000); // 3�� �Ŀ� ���÷��� ����

        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "         ��  �� �� �� ��           ";
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

        ifstream load("replay.txt", ios::in);

        while (!load.eof()) {
            int keyboard, _x, _y;

            load >> keyboard >> _x >> _y;

            if (keyboard == SPACE) {
                // Ÿ���� �����ִ� �Լ�
                if (!table[_x][_y].clicked) {
                    OpenTile(_x, _y);

                    // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                    if (remainTiles() == BOMBS_CNT) {
                        Win();
                        isWin = true;
                    }
                    else {
                        isWin = false;
                    }
                }
            }
            if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
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
        cout << "         ��  �� �� �� ��           ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 16);
        cout << "  �޴��� ���ư����� CŰ�� ��������";

        system("pause>nul");
    }
    else {
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 11);
        cout << "            ���̵� (��)            ";
        gotoxy(30, 13);
        cout << "              " << ROW << " X " << COL;
        gotoxy(30, 15);
        cout << "         ��ź ���� => " << BOMBS_CNT << "��";
        gotoxy(30, 16);
        cout << "===================================";
        gotoxy(30, 18);
        cout << " �����̽� ��(SPACE) : ��� �����ϱ�";
        gotoxy(30, 20);
        cout << "   f Ű Ȥ�� F Ű   : ��� ǥ���ϱ�";
        gotoxy(30, 22);
        cout << "   s Ű Ȥ�� S Ű   : ���� �����ϱ�";
        gotoxy(30, 24);
        cout << "   c Ű Ȥ�� C Ű   : �ڷ� ���ư���";

        drawTable();
    }


}

double Minesweeper::SelectMapSize_Easy()
{
    system("cls");
    gotoxy(1, 1);
    /*cout << "201710321 �����";*/
    kws::printName();

    PrintEasy();

    gotoxy(23, 18);
    cout << "���̵� ��";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // �۾����� ���� : ���
    
    gotoxy(14, 20);
    cout << "############################################"; gotoxy(14, 21);
    cout << "##                                        ##"; gotoxy(14, 22);
    cout << "##  �� ũ���� 20% ��ŭ ��ź�� �����˴ϴ�  ##"; gotoxy(14, 23);
    cout << "##                                        ##"; gotoxy(14, 24);
    cout << "##           ���� ������ ���� X 2         ##"; gotoxy(14, 25);
    cout << "##                                        ##"; gotoxy(14, 26);
    cout << "##        ��                     ��       ##"; gotoxy(14, 27);
    cout << "##      �� �������������       ##"; gotoxy(14, 28);
    cout << "##         �������������       ##"; gotoxy(14, 29);
    cout << "##         �������������       ##"; gotoxy(14, 30);
    cout << "##         �������������       ##"; gotoxy(14, 31);
    cout << "##         �������������       ##"; gotoxy(14, 32);
    cout << "##         �������������       ##"; gotoxy(14, 33);
    cout << "##         �������������       ##"; gotoxy(14, 34);
    cout << "##         �������������       ##"; gotoxy(14, 35);
    cout << "##      �� �������������       ##"; gotoxy(14, 36);
    cout << "##                                        ##"; gotoxy(14, 37);
    cout << "############################################"; gotoxy(14, 38);

    gotoxy(25, 26);
    cin >> ROW;

    gotoxy(18, 31);
    cin >> COL;

    CursorView(true); // Ŀ�� ���̰� �ϱ�

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
    /*cout << "201710321 �����";*/
    kws::printName();

    PrintStandard();

    gotoxy(23, 18);
    cout << "���̵� ��";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // �۾����� ���� : ���

    gotoxy(14, 20);
    cout << "############################################"; gotoxy(14, 21);
    cout << "##                                        ##"; gotoxy(14, 22);
    cout << "##  �� ũ���� 20% ��ŭ ��ź�� �����˴ϴ�  ##"; gotoxy(14, 23);
    cout << "##                                        ##"; gotoxy(14, 24);
    cout << "##           ���� ������ ���� X 2         ##"; gotoxy(14, 25);
    cout << "##                                        ##"; gotoxy(14, 26);
    cout << "##        ��                     ��       ##"; gotoxy(14, 27);
    cout << "##      �� �������������       ##"; gotoxy(14, 28);
    cout << "##         �������������       ##"; gotoxy(14, 29);
    cout << "##         �������������       ##"; gotoxy(14, 30);
    cout << "##         �������������       ##"; gotoxy(14, 31);
    cout << "##         �������������       ##"; gotoxy(14, 32);
    cout << "##         �������������       ##"; gotoxy(14, 33);
    cout << "##         �������������       ##"; gotoxy(14, 34);
    cout << "##         �������������       ##"; gotoxy(14, 35);
    cout << "##      �� �������������       ##"; gotoxy(14, 36);
    cout << "##                                        ##"; gotoxy(14, 37);
    cout << "############################################"; gotoxy(14, 38);

    gotoxy(25, 26);
    cin >> ROW;
    
    gotoxy(18, 31);
    cin >> COL;

    CursorView(true); // Ŀ�� ���̰� �ϱ�

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
    /*cout << "201710321 �����";*/
    kws::printName();

    PrintHard();

    gotoxy(23, 18);
    cout << "���̵� ��";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // �۾����� ���� : ���

    gotoxy(14, 21);
    cout << "############################################"; gotoxy(14, 22);
    cout << "##                                        ##"; gotoxy(14, 23);
    cout << "##  �� ũ���� 30% ��ŭ ��ź�� �����˴ϴ�  ##"; gotoxy(14, 24);
    cout << "##                                        ##"; gotoxy(14, 25);
    cout << "##           ���� ������ ���� X 2         ##"; gotoxy(14, 26);
    cout << "##                                        ##"; gotoxy(14, 27);
    cout << "##        ��                     ��       ##"; gotoxy(14, 28);
    cout << "##      �� �������������       ##"; gotoxy(14, 29);
    cout << "##         �������������       ##"; gotoxy(14, 30);
    cout << "##         �������������       ##"; gotoxy(14, 31);
    cout << "##         �������������       ##"; gotoxy(14, 32);
    cout << "##         �������������       ##"; gotoxy(14, 33);
    cout << "##         �������������       ##"; gotoxy(14, 34);
    cout << "##         �������������       ##"; gotoxy(14, 35);
    cout << "##         �������������       ##"; gotoxy(14, 36);
    cout << "##      �� �������������       ##"; gotoxy(14, 37);
    cout << "##                                        ##"; gotoxy(14, 38);
    cout << "############################################"; gotoxy(14, 39);

    gotoxy(25, 27);
    cin >> ROW;

    gotoxy(18, 32);
    cin >> COL;

    CursorView(true); // Ŀ�� ���̰� �ϱ�

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
    // ���Ϸκ��� ROW, COL ���ϱ�
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

    // table ��ü ����
    table = new Tile * [COL + 2];
    for (int i = 0; i < COL + 2; ++i) {
        table[i] = new Tile[ROW + 2];
    }
    //table = make_unique<unique_ptr<Tile[]>[]>(COL + 2);
    //for (int i = 0; i < COL + 2; ++i) {
    //    table[i] = make_unique<Tile[]>(ROW + 2);
    //}
    // ==========================

    // table �ʱ�ȭ
    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            table[i][j].clicked = false;
            table[i][j].flag = false;
            table[i][j].val = WALL;
        }
    }
    // =========================

    // table ���� ����
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

    // ���̵� �Ǻ��ϱ�
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

    int x = 0;                //Ŀ���� x��ġ
    int y = 0;                //Ŀ���� y��ġ
    int input = 0;            //Ű���� �Է��� ���� ����

    int arr_i;
    int arr_j;

    PrintLoad();

    CursorView(true); // Ŀ�� ���̰� �ϱ�

    DrawInitGame();

    while (true) {

        DrawStartGame_Load();

        if (y <= 0)        //Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        if (y > COL - 1) //Ŀ���� �Ʒ��� �׸� ��������
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

        input = _getch();    //Ű���� �Է��� �޾Ҵ�.
        //�����
        if (input == MAGIC_KEY)    //�޾Ҵµ� 224��?
        {
            switch (_getch())    //�׷� �ѹ��� �޾ƺ��� �����¿� �ϼ� ������.
            {
            case UP:            //��
                --y;
                break;
            case DOWN:          //�Ʒ�
                ++y;
                break;
            case LEFT:          //����
                --x;
                break;
            case RIGHT:         //������
                ++x;
                break;
            }
        }
        if (input == SPACE) //Ű���� �Է� �޾Ҵµ� �����̽���?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            // Ÿ���� �����ִ� �Լ�
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // cŰ�� CŰ�� ���� ��� �ǵ��ư���
            isLose = false;
            isWin = false;
            deleteMem(); // �����Ҵ��� �޸� �����ϱ�
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�

            ofstream clear("data.txt");    // s�� ���� ������ data ���� ����
            clear.close();

            ofstream save("data.txt");  // ���̺� ���� �����ϱ�
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // ������� ���� ����
            fstream fin("replay.txt", ios::in); // �б� ���� ���� ����
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY ���� ������ ���� �б�
                fout.put(c); // ���� ���� ���
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save�� �� �Ŀ� �޴��� ����������
        }
    }
}

void Minesweeper::StartGame_Easy()
{
    double para = SelectMapSize_Easy();
    init(para);
    
    int x = 0;                //Ŀ���� x��ġ
    int y = 0;                //Ŀ���� y��ġ
    int input = 0;            //Ű���� �Է��� ���� ����

    int arr_i;
    int arr_j;

    while(true) {

        DrawStartGame_Easy();

        if (y <= 0)        //Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        if (y > COL - 1) //Ŀ���� �Ʒ��� �׸� ��������
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
        
        input = _getch();    //Ű���� �Է��� �޾Ҵ�.
        //�����
        if (input == MAGIC_KEY)    //�޾Ҵµ� 224��?
        {
            switch (_getch())    //�׷� �ѹ��� �޾ƺ��� �����¿� �ϼ� ������.
            {
            case UP:            //��
                --y;
                break;
            case DOWN:          //�Ʒ�
                ++y;
                break;
            case LEFT:          //����
                --x;
                break;
            case RIGHT:         //������
                ++x;
                break;
            }
        }
        if (input == SPACE) //Ű���� �Է� �޾Ҵµ� �����̽���?
        {   
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input ,arr_i, arr_j);

            // Ÿ���� �����ִ� �Լ�
            if (!table[arr_i][arr_j].clicked) {
               OpenTile(arr_i, arr_j);

               // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
               if (remainTiles() == BOMBS_CNT) {
                   Win();
                   isWin = true;
               }
               else {
                   isWin = false;
               }
            }
        }
        if (input == 70 || input == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // cŰ�� CŰ�� ���� ��� �ǵ��ư���
            isLose = false;
            isWin = false;
            deleteMem(); // �����Ҵ��� �޸� �����ϱ�
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�

            ofstream clear("data.txt");    // s�� ���� ������ data ���� ����
            clear.close();

            ofstream save("data.txt");  // ���̺� ���� �����ϱ�
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out|ios::app); // ������� ���� ����
            fstream fin("replay.txt", ios::in); // �б� ���� ���� ����
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY ���� ������ ���� �б�
                fout.put(c); // ���� ���� ���
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save�� �� �Ŀ� �޴��� ����������
        }
    }
}

void Minesweeper::StartGame_Standard()
{
    double para = SelectMapSize_Standard();
    init(para);

    int x = 0;                //Ŀ���� x��ġ
    int y = 0;                //Ŀ���� y��ġ
    int input = 0;            //Ű���� �Է��� ���� ����

    int arr_i;
    int arr_j;

    while (true) {

        DrawStartGame_Standard();

        if (y <= 0)        //Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        if (y > COL - 1) //Ŀ���� �Ʒ��� �׸� ��������
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

        input = _getch();    //Ű���� �Է��� �޾Ҵ�.
        //�����
        if (input == MAGIC_KEY)    //�޾Ҵµ� 224��?
        {
            switch (_getch())    //�׷� �ѹ��� �޾ƺ��� �����¿� �ϼ� ������.
            {
            case UP:            //��
                --y;
                break;
            case DOWN:          //�Ʒ�
                ++y;
                break;
            case LEFT:          //����
                --x;
                break;
            case RIGHT:         //������
                ++x;
                break;
            }
        }
        if (input == SPACE) //Ű���� �Է� �޾Ҵµ� �����̽���?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            // Ÿ���� �����ִ� �Լ�
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // cŰ�� CŰ�� ���� ��� �ǵ��ư���
            isLose = false;
            isWin = false;
            deleteMem(); // �����Ҵ��� �޸� �����ϱ�
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�

            ofstream clear("data.txt");    // s�� ���� ������ data ���� ����
            clear.close();

            ofstream save("data.txt");  // ���̺� ���� �����ϱ�
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // ������� ���� ����
            fstream fin("replay.txt", ios::in); // �б� ���� ���� ����
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY ���� ������ ���� �б�
                fout.put(c); // ���� ���� ���
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save�� �� �Ŀ� �޴��� ����������
        }
    }
}

void Minesweeper::StartGame_Hard() 
{
    double para = SelectMapSize_Hard();
    init(para);

    int x = 0;                //Ŀ���� x��ġ
    int y = 0;                //Ŀ���� y��ġ
    int input = 0;            //Ű���� �Է��� ���� ����

    int arr_i;
    int arr_j;

    while (true) {

        DrawStartGame_Hard();

        if (y <= 0)        //Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        if (y > COL - 1) //Ŀ���� �Ʒ��� �׸� ��������
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

        input = _getch();    //Ű���� �Է��� �޾Ҵ�.
        //�����
        if (input == MAGIC_KEY)    //�޾Ҵµ� 224��?
        {
            switch (_getch())    //�׷� �ѹ��� �޾ƺ��� �����¿� �ϼ� ������.
            {
            case UP:            //��
                --y;
                break;
            case DOWN:          //�Ʒ�
                ++y;
                break;
            case LEFT:          //����
                --x;
                break;
            case RIGHT:         //������
                ++x;
                break;
            }
        }
        if (input == SPACE) //Ű���� �Է� �޾Ҵµ� �����̽���?
        {
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            // Ÿ���� �����ִ� �Լ�
            if (!table[arr_i][arr_j].clicked) {
                OpenTile(arr_i, arr_j);

                // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        if (input == 70 || input == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
            arr_i = y + 1;
            arr_j = x + 1;

            // ������ ���� �κ�
            saveData(input, arr_i, arr_j);

            if (table[arr_i][arr_j].clicked == false) {
                table[arr_i][arr_j].flag = !table[arr_i][arr_j].flag;
            }
        }
        if (input == 67 || input == 99) { // cŰ�� CŰ�� ���� ��� �ǵ��ư���
            isLose = false;
            isWin = false;
            deleteMem(); // �����Ҵ��� �޸� �����ϱ�
            clearData();
            PrintQuit();
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�

            ofstream clear("data.txt");    // s�� ���� ������ data ���� ����
            clear.close();

            ofstream save("data.txt");  // ���̺� ���� �����ϱ�
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); // ������� ���� ����
            fstream fin("replay.txt", ios::in); // �б� ���� ���� ����
            int c;
            while ((c = fin.get()) != EOF) { // REPLAY ���� ������ ���� �б�
                fout.put(c); // ���� ���� ���
            }
            fin.close();
            fout.close();

            PrintSave();

            break; // save�� �� �Ŀ� �޴��� ����������
        }
    }
}

int Minesweeper::QuitGame()
{
    return 0;
}

void Minesweeper::SetBombs(double para)
{
    BOMBS_CNT = (ROW * COL) * para; // ��ź ���� : �� ũ�� * para ��ŭ ����
    int bombs_cnt = 0;
    while (bombs_cnt != BOMBS_CNT) {
        int x = (rand() % ROW) + 1; // 1~ ROW ������ ������
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
                // 8�� Ȯ��
                for (int m = -1; m <= 1; m++) {
                    for (int n = -1; n <= 1; n++) {
                        if (m == 0 && n == 0) {
                            continue; // ����
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
            // �ڱ��ڽ��� pass(�̹� Ȯ���� �� ����)
            if (m == 0 && n == 0) {
                continue;
            }
            else {
                // ���� BLANK�̰�, flag�� �ƴ϶��
                if (table[_i + m][_j + n].val == BLANK && table[_i + m][_j + n].flag == false) {
                    // �̹� �������� ��
                    if (table[_i + m][_j + n].clicked == true) {
                        continue;
                    }
                    // �� ���� ���� ĭ�� ����, �ٽ� ��� ȣ���� ��
                    else {
                        table[_i + m][_j + n].clicked = true;
                        OpenBlanks(_i + m, _j + n);
                    }
                }
                // �ָ��� ������ ���
                else if (table[_i + m][_j + n].val >= 1 && table[_i + m][_j + n].val <= 8) {
                    table[_i + m][_j + n].clicked = true;
                    continue; // ���ڸ� ������ �� �̻� 8�� Ȯ���� ���ϰ� �� �ű������ �ϵ���
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
    if (!isLose && !isWin) { // �̱�ų� ���� �������� �����͸� ������
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
    int y = 10;

    gotoxy(10, y);

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            cout << table[i][j].state();
        }
        gotoxy(10, ++y);
    }
}

void Minesweeper::DrawInitGame()
{
    ifstream loadData("data.txt");
    string line;
    vector<string> replay;
    int cnt = 0;
    int keyboard, _x, _y;

    //���÷��� �� ������ ����

    for (int i = 1; i <= COL; i++) {
        for (int j = 1; j <= ROW; j++) {
            loadData >> dump[i][j];
        }
    }

    while (!loadData.eof()) {

        loadData >> keyboard >> _x >> _y;

        if (keyboard == SPACE) {
            // Ÿ���� �����ִ� �Լ�
            if (!table[_x][_y].clicked) {
                OpenTile(_x, _y);

                // ���� UNCLICK ���� (FLAG�� ����)�� ��ź������ �����ϸ� �¸�
                if (remainTiles() == BOMBS_CNT) {
                    Win();
                    isWin = true;
                }
                else {
                    isWin = false;
                }
            }
        }
        else if (keyboard == 70 || keyboard == 102) {  // fŰ�� FŰ�� ���� ��� (��� ����)
            if (table[_x][_y].clicked == false) {
                    table[_x][_y].flag = !table[_x][_y].flag;
            }
        }
    }
}

void Minesweeper::PrintLogo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);  // �۾����� ���� : ���� �ʷϻ� (�׸�����~)
    gotoxy(3, 8);
    cout << "                                                        �ء�                             "; gotoxy(3, 9);
    cout << "                                                        �ء�                             "; gotoxy(3, 10);
    cout << "�ءءءءءءءءء�    �ءءءءءءءءء�    �ءءءءءءءءء�    �ءءءءءءءء�"; gotoxy(3, 11);
    cout << "        �ء�                              ��            �ء�                            ��"; gotoxy(3, 12);
    cout << "        �ء�                              ��            �ء�                            ��"; gotoxy(3, 13);
    cout << "      ��    ��          �ءءءءءءءءء�          ��    ��                          ��"; gotoxy(3, 14);
    cout << "    ��        ��        ��                          ��        ��                        ��"; gotoxy(3, 15);
    cout << "  ��            ��      ��                        ��            ��                      ��"; gotoxy(3, 16);
    cout << "��                ��    �ءءءءءءءءء�    ��                ��                    ��";
}

void Minesweeper::PrintSave()
{
    system("cls");
    gotoxy(20, 20);
    cout << "��     ��     ��  . . .";
    CursorView(false); // Ŀ�� �����
    Sleep(1000);
}

void Minesweeper::PrintQuit()
{
    system("cls");
    gotoxy(20, 20);
    cout << "��   ��   ��   ��  . . .";
    CursorView(false); // Ŀ�� �����
    Sleep(800);
}

void Minesweeper::PrintLoad()
{
    system("cls");
    gotoxy(20, 20);
    cout << "��  ��  ��  ��  ��  . . .";
    CursorView(false); // Ŀ�� �����
    Sleep(1000);
}

void Minesweeper::PrintEasy()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);  // �۾����� ���� : ��ο� �ϴ�
    gotoxy(20, 8);
    cout << "�ءءءءءءءءء�"; gotoxy(20, 9);
    cout << "        �ء�        "; gotoxy(20, 10);
    cout << "        �ء�        "; gotoxy(20, 11);
    cout << "        �ءء�      "; gotoxy(20, 12);
    cout << "        �ءءء�    "; gotoxy(20, 13);
    cout << "        �ء�  �ء�  "; gotoxy(20, 14);
    cout << "        �ء�        "; gotoxy(20, 15);
    cout << "        �ء�        ";
}

void Minesweeper::PrintStandard()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  // �۾����� ���� : ��ο� ���
    gotoxy(20, 8);
    cout << "        �ء�        "; gotoxy(20, 9);
    cout << "        �ء�        "; gotoxy(20, 10);
    cout << "  �ءءءءءءء�  "; gotoxy(20, 11);
    cout << "  ��    �ء�    ��  "; gotoxy(20, 12);
    cout << "  ��    �ء�    ��  "; gotoxy(20, 13);
    cout << "  �ءءءءءءء�  "; gotoxy(20, 14);
    cout << "        �ء�        "; gotoxy(20, 15);
    cout << "        �ء�        ";
}

void Minesweeper::PrintHard()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);  // �۾����� ���� : ��ο� ����
    gotoxy(20, 8);
    cout << "        �ء�        "; gotoxy(20, 9);
    cout << "        �ء�        "; gotoxy(20, 10);
    cout << "        �ء�        "; gotoxy(20, 11);
    cout << "        �ءءءء�  "; gotoxy(20, 12);
    cout << "        �ء�        "; gotoxy(20, 13);
    cout << "        �ء�        "; gotoxy(20, 14);
    cout << "        �ء�        "; gotoxy(20, 15);
    cout << "�ءءءءءءءءء�"; gotoxy(20, 16);
    cout << "�ءءءءءءءءء�";
}

MENU Minesweeper::ReadyGame()
{
    CursorView(false); // Ŀ�� �����
    int y = 0;                // Ŀ���� y��ġ
    int input = 0;            // Ű���� �Է��� ���� ����
    while (true)            // ���� ����
    {
        DrawReadyGame();    // �غ�ȭ�� �׸���

        //-------------------
        if (y <= 0)        // Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        else if (y >= 8) //Ŀ���� �Ʒ��� �׸� ��������
        {
            y = 8;
        }

        gotoxy(19, 24 + y); //��ġ����
        cout << ">";
        //-------------------

        input = _getch();    //Ű���� �Է��� �޾Ҵ�.
        //�����
        if (input == MAGIC_KEY)    //�޾Ҵµ� 224��?
        {
            switch (_getch())    //�׷� �ѹ��� �޾ƺ��� �����¿� �ϼ� ������.
            {
            case UP:            //��
                y = y - 2;
                break;
            case DOWN:            //�Ʒ�
                y = y + 2;
                break;
            }
        }
        else if (input == SPACE) //Ű���� �Է� �޾Ҵµ� �����̽���?
        {
            switch (y)            //y��ġ�� ���� �Ǵ�
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

