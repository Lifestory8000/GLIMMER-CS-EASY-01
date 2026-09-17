#include <stdio.h>

int main(void)
{
    int age, score;
    scanf_s("%d", &age);
    scanf_s("%d", &score);

    printf("1: %d\n", age < 18 && score >= 60);
    printf("2: %d\n", age >= 80 || score >= 90);
    printf("3: %d\n", !(age > 0));
    printf("4: %d\n", age > 7 && score >= 60 && score < 80);
    printf("5: %d\n", (age > 99 || score >= 60) && (age < 30));
    if (score >= 90)
	{
		printf("夯\n");
	}
	else if (score >= 80)
	{
		printf("顶级\n");
	}
	else if (score >= 70)
	{
		printf("人上人\n");

	}
	else if (score >= 60) {
		printf("npc\n");

	}
	else if (score >= 0) {
		printf("拉完了\n");

	}
	else if (score < 0 && age >=18) {
		printf("??????\n");

	}

    return 0;
}