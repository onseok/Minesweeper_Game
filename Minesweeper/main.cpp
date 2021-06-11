// #0 STL(ǥ�����ø����̺귯�� ��� ������)
// #1 ����ڰ� ��û�� ũ�� ��ŭ ���� �����ؾ���.
// #2 ����ڰ� ������ ���̵��� ����
// �� : �� ũ���� 10%
// �� : �� ũ���� 20%
// �� : �� ũ���� 30%
// ! ���� �� ��� ��ź�� ��ġ�� ��� �� �����Ѵ�.
// ! ���ڰ� �ƴ� ���� �ֺ� ���� ������ ��Ʈ�� �����Ѵ�.
// ! �ֺ� ���� ������ 0�� ���� ������ ���, 8���� ���� �ڵ� ��ħ�� �����Ѵ�.
// ! ������ �ϴ� �߰��� ���α׷��� �����ؾ� �ϴ� ��� �����ϱ� ����� �����Ͽ� ������ �� �ְ� �ϱ�. =>�޸��� ���
// ! �ٽ� ������ ���� �̾��ϱ� ����� �����Ѵ�. => �޸��� ���
// ! ������ ���� �Ǹ�, ���� ���� ������ �ڵ����� ���÷��� �����ش�.
// ! ����ã�� ���� ȭ�� ���
// ! 

#include <iostream>
#include <stdlib.h> // srand, rand �Լ��� ����ϱ� ����
#include <time.h> // time �Լ��� ����ϱ�  
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Minesweeper.h"
#include "Tile.h"

using namespace std;

namespace kws {
	void printName() {
		cout << "�й� : 201710321 �̸� : �����" << '\n' << endl;
	}
}


//�ܼ� ũ��, Ÿ��Ʋ
void SetConsoleView()
{
	system("mode con:cols=100 lines=40");        //���� 100, ���� 40
	system("title Minesweeper");    // Ÿ��Ʋ ���ϱ�
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



