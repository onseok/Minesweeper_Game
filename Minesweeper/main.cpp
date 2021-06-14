// #0 STL(표준템플릿라이브러리 사용 가능함)
// #1 사용자가 요청한 크기 만큼 맵을 생성해야함.
// #2 사용자가 선택한 난이도에 따라
// 하 : 맵 크기의 10%
// 중 : 맵 크기의 20%
// 상 : 맵 크기의 30%
// ! 종료 시 모든 폭탄의 위치를 출력 후 종료한다.
// ! 지뢰가 아닌 곳은 주변 지뢰 개수를 힌트로 제공한다.
// ! 주변 지뢰 개수가 0인 곳을 선택할 경우, 8방향 연속 자동 펼침을 수행한다.
// ! 게임을 하는 중간에 프로그램을 종료해야 하는 경우 저장하기 기능을 제공하여 저장할 수 있게 하기. => 메모장 기능
// ! 다시 시작할 때는 이어하기 기능을 제공한다. => 메모장 기능
// ! 게임이 종료 되면, 게임 진행 과정을 자동으로 리플레이 시켜준다.
// ! 지뢰찾기 게임 화면 출력

// @@@남은 수정 사항@@@ 
// 1. 저장 할 때 마지막에 flag를 하면 불러올 때 마지막 flag가 불러와지지 않는다. 
// 그런데  신기하게도 마지막에 숫자가 열리면 그건 또 된다. 그 부분만 수정하면 될듯..
// 2. 주석을 조금 더 가다듬고 프로젝트 제출하자.
// 3. 맵 크기 선택 받을 때, 가끔 프로그램이 비정상 종료 될 때가 있다. 가로 길이가 세로보다 더 길 때 발생하는 듯..
// 4. UI 부분 조금 더 개선하기
// 5. 1~4 과정이 완료되었다고 판단이 들면 최종점검하기.

#include <iostream>
#include <stdlib.h> // srand, rand 함수를 사용하기 위해
#include <time.h> // time 함수를 사용하기  
#include <vector>
#include <conio.h>
#include <windows.h>
#include <crtdbg.h>
#include "Minesweeper.h"
#include "Tile.h"
#define _CRTDBG_MAP_ALLOC

using namespace std;

//콘솔 크기, 타이틀
void SetConsoleView()
{
	system("mode con:cols=100 lines=40");        //가로 100, 세로 40
	system("title l Minesweeper_Game l made by Kim Won Seok l");    // 타이틀 정하기
}

int main(void) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  

	srand((unsigned)time(NULL)); 

	SetConsoleView(); 

	Minesweeper greenjoa;
	
	greenjoa.start();

	return 0;
}



