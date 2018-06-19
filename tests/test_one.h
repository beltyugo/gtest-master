#ifndef TEST_ONE_H
#define TEST_ONE_H

#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

extern "C" {
#include "common.h"
#include "text.h"
#include "_text.h"
#define STDOUT 1
}


//test run
TEST (Showlengths, suite1) {
    text txt = create_text();
    showlengths(txt);
    SUCCEED();
}

//3 words on 3 lines
TEST (Showlengths, suite2) {

    text txt = create_text();

    char *filedir=(char*)malloc(256);
    sprintf(filedir, "%s/text.txt", TESTIDIR);
    load(txt, filedir);

    int old_dup;
    int out_func = open("testwork.txt",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
    old_dup = dup(STDOUT);
    dup2(out_func, STDOUT);

    showlengths(txt);

    fflush(stdout);
    close(out_func);

    dup2(old_dup, STDOUT);

    FILE *testwork;
    testwork = fopen("testwork.txt","rw");
    if(testwork == NULL){
           FAIL();
           return;
    }

    char *buf1 = (char*)malloc(sizeof(char)*512);
    int readcount1 = fread(buf1,1,512,testwork);

    char *checkdir=(char*)malloc(256);
    FILE *check;
    sprintf(checkdir, "%s/proverka.txt", TESTIDIR);
    check = fopen(checkdir,"rw");
    if(check == NULL){
           FAIL();
           return;
    }

    char *buf2 = (char*)malloc(sizeof(char)*512);
    int readcount2 = fread(buf2,1,512,check);

    fclose(testwork);
    fclose(check);
    remove("testwork.txt");

    EXPECT_EQ(readcount2, readcount1);
}

//Empty test file
TEST (Showlengths, suite3) {

    text txt = create_text();

    char *filedir=(char*)malloc(256);
    sprintf(filedir, "%s/text2.txt", TESTIDIR);
    load(txt, filedir);

    int old_dup;
    int out_func = open("testwork2.txt",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
    old_dup = dup(STDOUT);
    dup2(out_func, STDOUT);

    showlengths(txt);

    fflush(stdout);
    close(out_func);

    dup2(old_dup, STDOUT);

    FILE *testwork;
    testwork = fopen("testwork2.txt","rw");
    if(testwork == NULL){
           FAIL();
           return;
    }

    char *buf = (char*)malloc(sizeof(char)*512);
    int readcount = fread(buf,1,512,testwork);

    fclose(testwork);
    remove("testwork2.txt");

    EXPECT_EQ(0, readcount);
}

#endif // TEST_ONE_H
