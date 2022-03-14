## Variable that points to SystemC installation path
SYSTEMC = /opt/systemc

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib

TARGET_ARCH = linux64

CC     = g++
STD    = -std=c++17
OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated -static
CFLAGS = $(STD) $(OPT) $(OTHER)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = run
SRCS = main.cpp top.cpp bitgen.cpp bit2byte.cpp consumer.cpp fifo.cpp
OBJS   = $(SRCS:.cpp=.o)
LIBS   =  -lsystemc -lm $(EXTRA_LIBS)
EXE    = $(MODULE).x

.SUFFIXES: .cc .cpp .o .x
