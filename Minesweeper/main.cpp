#include <iostream>
#include "Minesweeper.h"
using namespace std;
namespace kws {
	void printName() {
		cout << "학번 : 201710321 이름 : 김원석" << '\n' << endl;
	}
}

// #0 STL(표준템플릿라이브러리 사용 가능함)
// #1 사용자가 요청한 크기 만큼 맵을 생성해야함.
// #2 사용자가 선택한 난이도에 따라
// 하 : 맵 크기의 10%
// 중 : 맵 크기의 20%
// 상 : 맵 크기의 30%
// ! 종료 시 모든 폭탄의 위치를 출력 후 종료한다.
// ! 지뢰가 아닌 곳은 주변 지뢰 개수를 힌트로 제공한다.
// ! 주변 지뢰 개수가 0인 곳을 선택할 경우, 8방향 연속 자동 펼침을 수행한다.
// ! 

int main() {

	kws::printName();



	return 0;
}