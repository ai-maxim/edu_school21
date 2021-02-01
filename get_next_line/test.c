/* platinum, с -- ваш вес в платиновом эквиваленте */
#include <stdio.h>

int main(void)
{
	float weight; /* вес пользователя */
	float value; /* платиновый эквивалент */
	printf("Хотите узнать свой вес в платиновом эквиваленте?\n");
	printf("Давайте подсчитаем.\n");
	printf("Пожалуйста, введите свой вес, выраженный в фунтах: ");
	/* получить входные данные от пользователя */
	scanf("%f", &weight);
	/* считаем, что цена родия равна $1700 за тройскую унцию */
	/* 14.5833 коэффициент для перевода веса, выраженного в фунтах, в тройские унции */
	value = 1700.0 * weight * 14.5833;
	printf("Ваш вес в платиновом эквиваленте составляет $%.2f.\n", value);
	printf("Вы легко можете стать достойным этого! Если цена платины падает,\n");
	printf("ешьте больше для поддержания своей стоимости.\n");
	return 0;
}
