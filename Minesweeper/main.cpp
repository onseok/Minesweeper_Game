// #0 STL(표준템플릿라이브러리 사용 가능함)
// #1 사용자가 요청한 크기 만큼 맵을 생성해야함.
// #2 사용자가 선택한 난이도에 따라
// 하 : 맵 크기의 10%
// 중 : 맵 크기의 20%
// 상 : 맵 크기의 30%
// ! 종료 시 모든 폭탄의 위치를 출력 후 종료한다.
// ! 지뢰가 아닌 곳은 주변 지뢰 개수를 힌트로 제공한다.
// ! 주변 지뢰 개수가 0인 곳을 선택할 경우, 8방향 연속 자동 펼침을 수행한다.
// ! 게임을 하는 중간에 프로그램을 종료해야 하는 경우 저장하기 기능을 제공하여 저장할 수 있게 하기. =>메모장 기능
// ! 다시 시작할 때는 이어하기 기능을 제공한다. => 메모장 기능
// ! 게임이 종료 되면, 게임 진행 과정을 자동으로 리플레이 시켜준다.
// ! 지뢰찾기 게임 화면 출력
// ! 

#include <iostream>
#include <stdlib.h> // srand, rand 함수를 사용하기 위해
#include <time.h> // time 함수를 사용하기  
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Minesweeper.h"
#include "Tile.h"

using namespace std;

namespace kws {
	void printName() {
		cout << "학번 : 201710321 이름 : 김원석" << '\n' << endl;
	}
}


//콘솔 크기, 타이틀
void SetConsoleView()
{
	system("mode con:cols=100 lines=40");        //가로 100, 세로 40
	system("title Minesweeper");    // 타이틀 정하기
}



int main(void) {

	srand((unsigned)time(NULL)); 

	SetConsoleView();

	Minesweeper greenjoa;
	
	greenjoa.start();

	if (greenjoa.isWin()) {
		greenjoa.Win();
	}

	return 0;
}



