EXEC:=main
OBJS:=main.o lib/ll.o 
OBJDIR=result
GV=result/output.dot
CXX=gcc
CFLAGS= -std=c11
CFLAGS_g=-g -std=c11

all: $(OBJS) lib/vll.h
	$(CXX) $^ -o $(EXEC) $(CFLAGS)

gdb: $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS_g)

$(OBJDIR):
	mkdir -p $@

plot: all $(OBJDIR)
	./$(EXEC) $(GV)
	dot -Grankdir=LR -Tpng $(GV) -o result/graph.png

clean: 
	rm $(OBJS) $(EXEC) 
	rm -rf $(OBJDIR)