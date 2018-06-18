#ifndef TEST_ONE_H
#define TEST_ONE_H

extern "C" {
#include "common.h"
}

TEST(test_one_h, one)
{
    text txt = create_text();
    showlengths(txt);
    SUCCEED();
}

TEST(protest, show)

{

     int fptr;

     int oldstdout;

     fptr = open("DUMMY.BIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);

     oldstdout = dup(STDOUT);

     dup2(fptr,STDOUT);

     char *filedir=(char*)malloc(1024);

     sprintf(filedir, "%s/load.txt", TESTIDIR);

     text txt = create_text();

     load(txt, filedir);

     show(txt);

close(fptr);

dup2(oldstdout,STDOUT);

     FILE *t2;

     t2 = fopen("DUMMY.BIL","rw");

     if(t2 == NULL){

            FAIL();

            return;

     }

     char *buf = (char*)malloc(sizeof(char)*512);

     int readcount = fread(buf,1,512,t2);

     FILE *d2;

     sprintf(filedir, "%s/proveka.txt", TESTIDIR);

     d2 =fopen(filedir,"rw");

     if(d2 == NULL){

            FAIL();

            return;

     }

     char *buf2 = (char*)malloc(sizeof(char)*512);

     int readcount2 = fread(buf2,1,512,d2);

     fclose(t2);

     fclose(d2);

     ASSERT_EQ(readcount,readcount2);

}



#endif // TEST_ONE_H
