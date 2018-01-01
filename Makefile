EXEC:=main
OBJS:=main.o lib/ll.o lib/ll_tree.o
OBJDIR=result
GV=result/output.dot
GV2=result/output2.dot
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
	./$(EXEC) $(GV) $(GV2)
	dot -Grankdir=LR -Tpng $(GV) -o result/graph.png
	dot -Tpng $(GV2) -o result/graph2.png

clean: 
	rm $(OBJS) $(EXEC) 
	rm -rf $(OBJDIR)