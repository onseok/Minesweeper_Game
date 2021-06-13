# __C++로 구현한 지뢰찾기 게임__ 

201710321 김원석 개인 프로젝트

https://user-images.githubusercontent.com/76798309/121817648-9d027000-ccbd-11eb-95ad-b0c213c1bbb0.mp4

## 구현한 기능

### 맵 사이즈 컨트롤 
- 사용자가 원하는 크기의 맵 사이즈를 생성할 수 있음 (가로, 세로 둘 다)

### 난이도 선택 
- 난이도 하 : 맵 크기 10%만큼의 지뢰가 랜덤으로 생성됨
- 난이도 중 : 맵 크기 20%만큼의 지뢰가 랜덤으로 생성됨
- 난이도 상 : 맵 크기 30%만큼의 지뢰가 랜덤으로 생성됨
 
 ### 저장 및 불러오기 
 - 게임 진행 중 s키(혹은 S키)를 입력하면 게임이 저장됨
 - 저장 후 "이어하기" 메뉴를 선택하면 게임을 불러옴
 - 게임을 종료했다가 후에 재시작하여도 무관함
 
 ### 리플레이 
 - 게임이 종료되면 게임 진행과정을 자동으로 리플레이함
 - 게임 승패에 상관없이 게임 종료 후 리플레이 1회 진행함
  
  
## 주요 소스코드
```
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
```
