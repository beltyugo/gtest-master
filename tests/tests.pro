include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += "TESTIDIR=\\\"$$PWD/../testi\\\""

HEADERS +=     tst_test1.h \
    ../app/myfunc.h \
    fibonachi_test.h \
    ../app/common.h \
    ../app/_text.h \
    ../app/text.h \
    test_one.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/showlengths.c \
    ../app/process_forward.c \
    ../app/load.c \
    ../app/create_text.c

INCLUDEPATH += ../app
