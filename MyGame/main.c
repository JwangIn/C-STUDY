#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// printf �Լ��� scanf �Լ��� ����ؼ� ������ ������ ����� ������ ����.

	// �÷��̾ ȯ���ϴ� �ؽ�Ʈ�� ������ּ���.

	// prinrf(���ڸ� �Է��ϸ� ������ �����Ѵ�.) Press start Any Key ����
	// scanf -> �Է��� �޴´�... Ŀ���� ������·� ����ϰ� �ִ�.

	// ���� �Ǵ� �Ǽ� �����͸� ���� ��ǻ�Ͱ� �����ϴ� ����� ����ϰ�,
	// ���� �����ϴ� ����� ���� ����ϴ� ���α׷��� ����� ������.


	srand(time(NULL));
	int commputerValue = rand() % 100 + 1; // 1~100 ������ ���ڰ� computerValue�� �Է��� �˴ϴ�.
	
	
	printf("�ڡ� ȯ���մϴ�. �١�\n");
	printf("���ڸ� �Է��ϸ� ������ �����մϴ�.\n");
	int Start;
	scanf_s("%d", &Start);
	printf("���� ����!\n");

	printf("�÷��̾��� ���� �Է����ּ���.\n");
	int userValue;
	scanf_s("%d", &userValue);

	return 0;
}