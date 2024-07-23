/*
*  �ۼ��� : 2024-07-23
*  �ۼ��� : ������
*  �н���ǥ : ����ü
*/

#include "lectures.h"
#include "stdbool.h"

// ����ü�� ��� ������ �ʱ�ȭ�ϴ� ��

// ����ü�� ������
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
    // ����ü �����ͷ� ����� �ٲٴ� ��� ->(ȭ��ǥ) ������ ���
    p2->playerX += addvalue;
    p2->playerY += addvalue;
    // playerX�ּ��� �������� �� ���� addValue�� ���ض�
    p2->isPlayerDead = !(p2->isPlayerDead);
    
}

void ChangItemInfoByStruct(Item* I1, int addvalue)
{
    I1->itemX += addvalue;
    I1->itemY += addvalue;
    I1->itemInfo = !(I1->itemInfo);
}

void ChangePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int addValue) // X, Y�� ��ǥ�� addValue��ġ ��ŭ ������Ű�ÿ�
{
    *playerX += addValue;
    *playerY += addValue;
    *isPlayerDead = !(*isPlayerDead); // !(*(isPlayerDead : �ּҸ� ��� �ִ� ����): ����Ű�� �� false) => true 

}


void lecture24()
{
    // �÷��̾��� ��ġ�� ����ϴ� �Լ�
    // playerX, playerY, isPlayerDead :: �÷��̾��� ��ǥ(x,y), �÷��̾��� ���� ����
    // Call-by-Reference. ��, �ּҸ� �Ѱ��ִ� �Լ�
    int playerX = 5, playerY = 5;
    bool isPlayerDead = false;
    // structure �ڷᱸ��
    struct Player {
        int playerX;
        int playerY;
        bool isPlayerDead;
    };

    // typedef Ű���带 ����Ͽ� ����ü �����ϱ�


    // �������̶�� �̸����� ����ü�� ������ , itemX, itemY

    // ����ü �ȿ��� �ʱ�ȭ�� �� �� ����.
  


    struct Player p1;
    Player2 p2;
    Item I1; 

    // ����ü�� ��Ӻ����� ����ϴ� ��� : (.) ������

    p1.playerX = 5;
    p1.playerY = 5;
    p1.isPlayerDead = true;
    
    printf("player����ü�� ��� ��� playerX : %d, playerY : %d, isPlayerDead :%d \n", p1.playerX, p1.playerY, p1.isPlayerDead);

    p2.playerX = 5;
    p2.playerY = 5;
    p2.isPlayerDead = true;

    printf("player����ü�� ��� ��� playerX : %d, playerY : %d, isPlayerDead :%d \n", p2.playerX, p2.playerY, p2.isPlayerDead);


    I1.itemX = 8;
    I1.itemY = 8;
    I1.itemInfo = true;

    int some = 1;
    I1.itemPtr = &some;
    printf("some�� �� : %d\n", some);
    *I1.itemPtr = 10;// I1.*itemPtr �̶�� ��
    printf("some�� �� : %d\n", some);

    printf("Item ����ü�� ��� ��� ItemX : %d, ItemY : %d\n", I1.itemX, I1.itemY);

    // Item ����ü ������ ����Ű�� �ּҸ� �����ϴ� ����(������) �����ϱ�
    Item* ItemPtr = &I1;

    // ����ü�� �ּҸ� �̿��ؼ� ����ü ������ �����ϱ�
    (*ItemPtr).itemX = 20;  //  I1.itemX =20; �� ������ �����̴�.
    // *ItemPtr.itemX;  // �ǹ̴� ItemPtr�� ������ itemX�� �������϶�
    printf("I1�� itemX �� ��� : %d \n", I1.itemX);

    // (*�����ͺ���).�������; vs *�����ͺ���. ���Ǧ���� ������
    // *������ ������ : �켱 ������ ������ ���� �����̱� ������ *�����ͺ���.��� ������ ������ ��������� �������� �ǹ̸� ���´�.
    // (*������ ����) : ��������� ����ϸ�, (������ ������ ����Ű�� ��).��������� �����ϰ� �ȴ�

    // ����ü �����͸� �̿��ؼ� ��� ������ �����ϱ� ���ؼ��� 
    // (*������ �����̸�)�� ���·� �ݵ�� ����ؾ� �Ѵ�.

    // ȭ��ǥ �����ڰ� ���� !! : ����ü �����Ϳ��� ����ϴ� ������
    ItemPtr->itemX = 10; // (*itemPtr).itemX = 10;

    // ������ 
    // ����ü�� ���� ����
    // typedef struct �̸� ( int a;, int b;, int* ptr;) �̸� ;
    // ����ü�� �����ϰ� �� ����ü�� �ּҸ� ����Ű�� ����
    // ����ü ������ : ����ü�� �ּҸ� ����Ű�� ���� 
    // ����üŸ��* �������̸� =&����üŸ�� ����;
    // ���� �Ҵ�. malloc << ���� 
    // ����ü �����͸� �̿��ؼ� ���� �����ϱ����� -> ȭ��ǥ ������ ���.

    ChangePlayerInfo(&playerX, &playerY, &isPlayerDead, 3);
    printf("playerX : %d, playerY : %d, isPlayerDead�� �� : %d \n", playerX, playerY, (bool)isPlayerDead);

    ChangePlayerInfoBystruct(&p1, 5);
    printf("playerX : %d, playerY : %d, isPlayerDead�� �� : %d \n", p1.playerX, p1.playerY, p1.isPlayerDead);

    // �÷��̾ ���� ���� �Ӽ��� �ϳ��� ��� ǥ���� �� ������?
    // �ּ�, ������ Ÿ��(4����Ʈ) n��
    // ���� �ٸ� ������ Ÿ���� ����� �� �ִ� �ϳ��� Ÿ���� ���� �� �ִ� ��� => ����ü

    // Item�� ���� Item ����ü �����͸� ����Ͽ� �����ϴ� �Լ��� ��������


    ChangItemInfoByStruct(&I1,3);
    printf("itemX : %d, itemY : %d, itemInfo�� �� : %d \n", I1.itemX,I1.itemY,I1.itemInfo);


    Monster monster;

    monster.monsterGrade = "�Ϲ�";
    monster.monsterName = "���";

    printf("������ �̸� : %s ������ ��� : %s\n", monster.monsterName, monster.monsterGrade);
}



