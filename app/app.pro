TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    tracer.c \
    showwordbeginnings.c \
    showupfirst.c \
    showrev.c \
    showodd.c \
    shownum.c \
    shownonempty.c \
    showlengths.c \
    showfirstwords.c \
    showevenbeforodd.c \
    show.c \
    save.c \
    rt.c \
    rn.c \
    remove_all.c \
    rc.c \
    r1ne.c \
    process_forward2.c \
    process_forward.c \
    process_backward.c \
    pp.c \
    myfunc.c \
    mwef.c \
    mwbb.c \
    mplb.c \
    mp.c \
    mle.c \
    mcb.c \
    load.c \
    j.c \
    editor.c \
    delete_line.c \
    cursors.c \
    create_text.c \
    append_line.c \
    process_forward_extra_option.c

HEADERS += \
    myfunc.h \
    _text.h \
    #../../inf/task7/lab7/text/_text.h \
   #_text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

#DISTFILES += \
#    ../../inf/task7/lab7/text/tracer.o \
#    ../../inf/task7/lab7/showlengths.o
