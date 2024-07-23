/*
*  작성일 : 2024-07-23
*  작성자 : 박종현
*  학습목표 : 구조체
*/

#include "lectures.h"
#include "stdbool.h"

// 구조체의 멤버 변수를 초기화하는 법

// 구조체와 포인터
typedef struct Item {
    int itemX;
    int itemY;
    int* itemPtr;
    bool itemInfo;
}Item;

typedef struct Player2 {
    int playerX;
    int playerY;
    bool isPlayerDead;
}Player2;

typedef struct Monster {
    char* monsterName;
    char* monsterGrade;
}Monster;

void ChangePlayerInfoBystruct(Player2* p2, int addvalue)
{
    // 구조체 포인터로 멤버를 바꾸는 방법 ->(화살표) 연산자 사용
    p2->playerX += addvalue;
    p2->playerY += addvalue;
    // playerX주소의 역참조를 한 값에 addValue를 더해라
    p2->isPlayerDead = !(p2->isPlayerDead);
    
}

void ChangItemInfoByStruct(Item* I1, int addvalue)
{
    I1->itemX += addvalue;
    I1->itemY += addvalue;
    I1->itemInfo = !(I1->itemInfo);
}

void ChangePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int addValue) // X, Y의 좌표를 addValue수치 만큼 증가시키시오
{
    *playerX += addValue;
    *playerY += addValue;
    *isPlayerDead = !(*isPlayerDead); // !(*(isPlayerDead : 주소를 담고 있는 변수): 가리키는 값 false) => true 

}


void lecture24()
{
    // 플레이어의 위치만 출력하는 함수
    // playerX, playerY, isPlayerDead :: 플레이어의 좌표(x,y), 플레이어의 생존 여부
    // Call-by-Reference. 값, 주소를 넘겨주는 함수
    int playerX = 5, playerY = 5;
    bool isPlayerDead = false;
    // structure 자료구조
    struct Player {
        int playerX;
        int playerY;
        bool isPlayerDead;
    };

    // typedef 키워드를 사용하여 구조체 선언하기


    // 아이템이라는 이름으로 구조체를 만들어라 , itemX, itemY

    // 구조체 안에서 초기화를 할 수 없다.
  


    struct Player p1;
    Player2 p2;
    Item I1; 

    // 구조체의 멤머변수를 사용하는 방법 : (.) 연산자

    p1.playerX = 5;
    p1.playerY = 5;
    p1.isPlayerDead = true;
    
    printf("player구조체의 멤버 출력 playerX : %d, playerY : %d, isPlayerDead :%d \n", p1.playerX, p1.playerY, p1.isPlayerDead);

    p2.playerX = 5;
    p2.playerY = 5;
    p2.isPlayerDead = true;

    printf("player구조체의 멤버 출력 playerX : %d, playerY : %d, isPlayerDead :%d \n", p2.playerX, p2.playerY, p2.isPlayerDead);


    I1.itemX = 8;
    I1.itemY = 8;
    I1.itemInfo = true;

    int some = 1;
    I1.itemPtr = &some;
    printf("some의 값 : %d\n", some);
    *I1.itemPtr = 10;// I1.*itemPtr 이라는 뜻
    printf("some의 값 : %d\n", some);

    printf("Item 구조체의 멤버 출력 ItemX : %d, ItemY : %d\n", I1.itemX, I1.itemY);

    // Item 구조체 변수를 가르키는 주소를 저장하는 변수(포인터) 선언하기
    Item* ItemPtr = &I1;

    // 구조체의 주소를 이용해서 구조체 변수에 접근하기
    (*ItemPtr).itemX = 20;  //  I1.itemX =20; 과 동일한 내용이다.
    // *ItemPtr.itemX;  // 의미는 ItemPtr의 변수의 itemX를 역참조하라
    printf("I1의 itemX 값 출력 : %d \n", I1.itemX);

    // (*포인터변수).멤버변수; vs *포인터변수. 멤버푠수의 차이점
    // *역참조 연산자 : 우선 순위가 오른쪽 먼저 연산이기 때문에 *포인터변수.멤버 변수의 선선언 멤버변수의 역참조의 의미를 갖는다.
    // (*포인터 변수) : 멤버변수를 사용하면, (포인터 변수가 가르키는 값).멤버변수에 접근하게 된다

    // 구조체 포인터를 이용해서 멤버 변수르 수정하기 위해서는 
    // (*포인터 변수이름)이 형태로 반드시 사용해야 한다.

    // 화살표 연산자가 등장 !! : 구조체 포인터에서 사용하는 연산자
    ItemPtr->itemX = 10; // (*itemPtr).itemX = 10;

    // 총정리 
    // 구조체의 변수 선언
    // typedef struct 이름 ( int a;, int b;, int* ptr;) 이름 ;
    // 구조체를 선언하고 그 구조체의 주소를 가리키는 변수
    // 구조체 포인터 : 구조체의 주소를 가리키는 변수 
    // 구조체타입* 포인터이름 =&구조체타입 변수;
    // 동적 할당. malloc << 내일 
    // 구조체 포인터를 이용해서 값을 변경하기위해 -> 화살표 연산자 사용.

    ChangePlayerInfo(&playerX, &playerY, &isPlayerDead, 3);
    printf("playerX : %d, playerY : %d, isPlayerDead의 값 : %d \n", playerX, playerY, (bool)isPlayerDead);

    ChangePlayerInfoBystruct(&p1, 5);
    printf("playerX : %d, playerY : %d, isPlayerDead의 값 : %d \n", p1.playerX, p1.playerY, p1.isPlayerDead);

    // 플레이어가 갖는 공통 속성을 하나로 묶어서 표현할 수 없을까?
    // 주소, 데이터 타입(4바이트) n개
    // 서로 다른 데이터 타입을 사용할 수 있는 하나의 타입을 만들 수 있는 기능 => 구조체

    // Item도 값을 Item 구조체 포인터를 사용하여 변경하는 함수를 만들어보세요


    ChangItemInfoByStruct(&I1,3);
    printf("itemX : %d, itemY : %d, itemInfo의 값 : %d \n", I1.itemX,I1.itemY,I1.itemInfo);


    Monster monster;

    monster.monsterGrade = "일반";
    monster.monsterName = "고블린";

    printf("몬스터의 이름 : %s 몬스터의 등급 : %s\n", monster.monsterName, monster.monsterGrade);
}



