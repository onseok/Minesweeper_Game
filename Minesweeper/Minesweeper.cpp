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
        switch (ReadyGame())    //������ �޾Ƽ� �Ǵ�.
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
    system("cls");    //ȭ���� Ŭ���� ���ִ� �Լ� �Դϴ�.
    gotoxy(1, 1);
    cout << "201710321 �����";
    gotoxy(7, 5);
    cout << "******************************";
    gotoxy(7, 6);
    cout << "*        ����ã�� ����       *";
    gotoxy(7, 7);
    cout << "******************************";
    gotoxy(10, 10);
    cout << "[�̾��ϱ�]";
    gotoxy(10, 12);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(10, 14);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(10, 16);
    cout << "[�����ϱ�] ���̵� ��";
    gotoxy(10, 18);
    cout << "[�����ϱ�]";
}

void Minesweeper::DrawLoadGame()
{
    system("cls");
    gotoxy(1, 1);
    cout << "201710321 �����";
    gotoxy(10, 10);
    cout << "��� �غ���...";
}

void Minesweeper::DrawStartGame_Easy()
{
    system("cls");

    gotoxy(1, 1);
    cout << "201710321 �����";

    if (isLose && !isWin) {
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

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c Ű Ȥ�� C Ű  : �޴��� ���ư���";
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
    cout << "201710321 �����";

    if (isLose && !isWin) {
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

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c Ű Ȥ�� C Ű  : �޴��� ���ư���";
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
    cout << "201710321 �����";

    if (isLose && !isWin) {
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

        ifstream load("data.txt", ios::in);

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
        gotoxy(30, 10);
        cout << "===================================";
        gotoxy(30, 12);
        cout << "            �� �� �� ��             ";
        gotoxy(30, 14);
        cout << "===================================";
        gotoxy(30, 20);
        cout << "  c Ű Ȥ�� C Ű  : �޴��� ���ư���";
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
    cout << "201710321 �����";
    gotoxy(10, 8);
    cout << "���̵� �� (�� ũ���� 10% ���� ����)";
    gotoxy(10, 10);
    cout << "���� ���� ũ�� �Է� : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "���� ���� ũ�� �Է� : ";
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
    cout << "201710321 �����";
    gotoxy(10, 8);
    cout << "���̵� �� (�� ũ���� 20% ���� ����)";
    gotoxy(10, 10);
    cout << "���� ���� ũ�� �Է� : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "���� ���� ũ�� �Է� : ";
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
    cout << "201710321 �����";
    gotoxy(10, 8);
    cout << "���̵� �� (�� ũ���� 30% ���� ����)";
    gotoxy(10, 10);
    cout << "���� ���� ũ�� �Է� : ";
    cin >> ROW;
    gotoxy(10, 12);
    cout << "���� ���� ũ�� �Է� : ";
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
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�
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
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�
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
            break;
        }
        if (input == 83 || input == 115) { // s�� SŰ�� ���� ��� ���� �����ϱ�
            // ������ �����ϴ� �Լ�
        }
    }
}

int Minesweeper::QuitGame()
{
    return 0;
}

void Minesweeper::SetBombs(double para)
{
    BOMBS_CNT = (ROW * COL) * para; // ��ź ���� : �� ũ���� 10% ����
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
}

void Minesweeper::saveData(int _k, int _i, int _j)
{   
    if (!isLose && !isWin) { // �̱�ų� ���� �������� �����͸� ������
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
    int y = 0;                //Ŀ���� y��ġ
    int input = 0;            //Ű���� �Է��� ���� ����
    while (true)            //���� ����
    {
        DrawReadyGame();    //�غ�ȭ�� �׸���

        //-------------------
        //DrawUserCursor �Լ�
        if (y <= 0)        //Ŀ���� ���� �׸� �ö󰡰� 
        {
            y = 0;
        }
        else if (y >= 8) //Ŀ���� �Ʒ��� �׸� ��������
        {
            y = 8;
        }

        gotoxy(9, 10 + y); //��ġ����
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

