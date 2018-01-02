EXEC:=main
OBJS:=main.o lib/ll.o lib/ll_tree.o lib/ll_graph.o
OBJDIR=result
GV=result/output.dot
GV2=result/output2.dot
GV3=result/output3.dot
CXX=gcc
CFLAGS= -std=c11
CFLAGS_g=-g -std=c11

all: $(OBJS) lib/vll.h
	$(CXX) $^ -o $(EXEC) $(CFLAGS)

gdb: $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS_g)

valgrind: all $(OBJDIR)
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(EXEC) $(GV) $(GV2) $(GV3)

$(OBJDIR):
	mkdir -p $@

plot: all $(OBJDIR)
	./$(EXEC) $(GV) $(GV2) $(GV3)
	dot -Grankdir=LR -Tpng $(GV) -o result/graph.png
	dot -Tpng $(GV2) -o result/graph2.png
	dot -Tpng $(GV3) -o result/graph3.png

clean: 
	rm $(OBJS) $(EXEC) 
	rm -rf $(OBJDIR)