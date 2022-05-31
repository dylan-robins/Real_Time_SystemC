## Variable that points to SystemC installation path
SYSTEMC = /opt/systemc

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux64

TARGET_ARCH = linux64

CC     = g++
STD    = -std=c++17
OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated -static
CFLAGS = $(STD) $(OPT) $(OTHER)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = run
SRCS = main.cpp cpu.cpp kernel.cpp os.cpp processes.cpp top.cpp timer.cpp
OBJS   = $(SRCS:.cpp=.o)
LIBS   =  -lsystemc -lm $(EXTRA_LIBS)
EXE    = $(MODULE).x

.SUFFIXES: .cc .cpp .o .x
