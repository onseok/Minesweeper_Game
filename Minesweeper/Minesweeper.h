#pragma once
#include <Windows.h>
#include "Tile.h"
#define MAGIC_KEY 224    //상하좌우 화살표가 들어올때 선행되어 들어오는 숫자
#define SPACE 32 //스페이스 키 값


enum class MENU
{
	GAMESTART_EASY = 0,
	GAMESTART_STANDARD,
	GAMESTART_HARD,
	GAMESTART_LOAD,
	QUIT
};
enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

class Minesweeper
{
private:
	int ROW; // 맵의 가로 길이
	int COL; // 맵의 세로 길이
	int BOMBS_CNT; // 폭탄의 갯수
	Tile** table;
	bool isLose = false;
	bool isWin = false;
	int stage = 0; // 
	int dump[100][100];
public:
	Minesweeper();
	~Minesweeper();
	int start();
	void DrawReadyGame();
	void DrawStartGame_Load();
	void DrawStartGame_Easy();
	void DrawStartGame_Standard();
	void DrawStartGame_Hard();
	double SelectMapSize_Easy();
	double SelectMapSize_Standard();
	double SelectMapSize_Hard();
	void StartGame_Load();
	void StartGame_Easy();
	void StartGame_Standard();
	void StartGame_Hard();
	int QuitGame();
	void SetBombs(double para);
	void SetNums();
	void init(double para);
	void OpenTile(int _i, int _j);
	void OpenBlanks(int _i, int _j);
	int remainTiles();
	void Win();
	void Lose();
	void deleteMem();
	void saveData(int _k, int _i, int _j);
	void clearData();
	void drawTable();
	void DrawInitGame();

	void gotoxy(int x, int y) //콘솔 커서 이동
	{
		COORD Pos;        //x, y를 가지고 있는 구조체
		Pos.X = 2 * x;
		Pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	};
	MENU ReadyGame();
}; 


