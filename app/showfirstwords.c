#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text.h"

static void show_first_words(int index, char *text);

/**
 * Выводит первое слово из каждой строки в прямом порядке следования строк
 */
void showfirstwords(text txt)
{
    /* Применяем функцию show_first_words к каждой строке текста */
    process_forward(txt, show_first_words);
}

/**
 * Выводит первое слово из каждой строки в прямом порядке следования строк
 */
static void show_first_words(int index, char *text)
{
    /* Функция обработчик всегда получает существующцю строку */
    assert(text != NULL);

    /* Декларируем неиспользуемый параметр */
    UNUSED(index);

    /* Выводим символы от начала строки до тех пор, пока не пробел*/
    unsigned int i;
    for (i=0; i < strlen(text) - 1; i++)
    {
	// Дополнительная проверка, если строка начинается с пробела
	
	if (text[0] == ' ')
	{
	    while (text[i] == ' ') i++;
        }
	if (text[i] == ' ') break;
	printf("%c", text[i]);
    }
    printf(" ");
}


	





	
