EXEC:=main
DEMO1:=src/demo_ll.o
DEMO2:=src/demo_ll_tree.o
DEMO3:=src/demo_ll_graph.o
OBJS:=lib/ll.o lib/ll_tree.o lib/ll_graph.o

OBJDIR=result
GV=result/output.dot
GV2=result/output2.dot
GV3=result/output3.dot
CXX=gcc
CFLAGS= -std=c11
CFLAGS_g=-g -std=c11

# library
lib: $(OBJS) lib/vll.h
	$(CXX) $^ -o $(EXEC) $(CFLAGS)

# demo 1 (linked-list)
demo: $(DEMO1) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS)
# demo 2 (binary tree)
demo2: $(DEMO2) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS)
# demo 3 (digraph)
demo3: $(DEMO3) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS)

# run demo 1
demo_r: demo $(OBJDIR)
	./$(EXEC) $(GV)
	dot -Grankdir=LR -Tpng $(GV) -o result/graph.png
# run demo 2
demo2_r: demo2 $(OBJDIR)
	./$(EXEC) $(GV2)
	dot -Tpng $(GV2) -o result/graph2.png
# run demo 3
demo3_r: demo3 $(OBJDIR)
	./$(EXEC) $(GV3)
	dot -Tpng $(GV3) -o result/graph3.png

# Run all by once
all: demo_r demo2_r demo3_r

gdb1: $(DEMO1) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS_g)
gdb2: $(DEMO2) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS_g)
gdb3: $(DEMO3) $(OBJS)
	$(CXX) $^ -o $(EXEC) $(CFLAGS_g)

memcheck1: demo1 $(OBJDIR)
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(EXEC) $(GV)
memcheck2: demo2 $(OBJDIR)
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(EXEC) $(GV2)
memcheck3: demo3 $(OBJDIR)
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(EXEC) $(GV3)

$(OBJDIR):
	mkdir -p $@

clean: 
	rm $(OBJS) $(EXEC) $(DEMO1) $(DEMO2) $(DEMO3)
	# rm -rf $(OBJDIR)