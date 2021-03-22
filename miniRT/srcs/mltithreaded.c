#include "minirt.h"

//потоковая функция
void* threadFunc(void* thread_data)
{
	//завершаем поток
	pthread_exit(0);
}
