/**
 * mwef.c -- реализует перемещение курсора в конец текущего слова,
 * если это возможно
 *
 * Copyright (c) 2017, Sveta Beltyugova <beltyugo@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <ctype.h>
#include "_text.h"

/**
 * Перемещаем курсор в конец слова
 */
void mwef(text txt)
{
    /* Создаем указатель на cтроку с курсором */
    char *text = txt->cursor->line->contents;
    unsigned int pos = txt->cursor->position;
    /* В конце строки */
    if (pos == strlen(text) - 1)
	/* Если курсор уже в конце слова слова */
	return;
    
    if ((isalpha(text[pos]) && !isalpha(text[pos + 1])))
    {
	txt->cursor->position++;
        return;
        /* Перемещаем курсор */
    }
    else
    {
        while (isalpha(text[pos + 1]))
	{
            pos++;
        }
	pos++;
        txt->cursor->position = pos;
    }
    /* if(isalpha(text[pos+1]))  */
    /*   txt->cursor->position= pos+1; */

}
