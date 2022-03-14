include env.mk

all: $(EXE)

$(EXE): $(OBJS) $(SYSTEMC)/lib/libsystemc.a 
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean::
	rm -f $(OBJS) *~ $(EXE) core
