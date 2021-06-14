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
### 게임 저장 기능 (게임 중 s키 입력 시)
```
        if (input == 83 || input == 115) { 

            ofstream clear("data.txt");    
            clear.close();
            
            ofstream save("data.txt");  
            for (int i = 1; i <= COL; i++) {
                for (int j = 1; j <= ROW; j++) {
                    save << table[i][j].val << " ";
                }
                save << endl;
            }
            save.close();

            fstream fout("data.txt", ios::out | ios::app); 
            fstream fin("replay.txt", ios::in); 
            int c;
            while ((c = fin.get()) != EOF) { 
                fout.put(c); 
            }
            fin.close();
            fout.close();

            PrintSave();

            break; 
        }
```

## 아직 남은 문제점
### 게임 진행 시 마우스 클릭 이벤트가 발생하면 콘솔 화면이 깜박이는 문제점
#### 문제 원인
- system("cls") 명령어를 통해 콘솔의 내용을 지우고 다시 쓰고 하는 방식을 사용하기 때문
- 화면을 까맣게 지웠다가 새로 지뢰판을 그리는 과정에서 깜박임이 발생함
#### 해결 방안
- gotoxy() 함수를 사용해 출력 좌표를 고정시킨 뒤 같은 내용을 반복 출력
- 더블 버퍼링 사용 (윈도우 API 함수 사용 없이)
- ↓ 관련링크 ↓
- https://codevang.tistory.com/39
- https://doo9713.tistory.com/10
