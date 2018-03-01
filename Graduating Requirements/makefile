#Anthony Caligure, Na Li, Valentina Bejarano



# Specifiy the target
all:	schedule

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
schedule:		CA5.o Credit.o Course.o Choose.o string_graph.o
	g++  CA5.o Credit.o Course.o Choose.o string_graph.o -o schedule

# Specify how the object files should be created from source files
CA5.o:	CA5.cpp
	g++ -c CA5.cpp

Credit.o: Credit.cpp Credit.h
	g++ -c Credit.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp

Choose.o: Choose.cpp Choose.h
	g++ -c Choose.cpp

string_graph.o: string_graph.cpp string_graph.h
	g++ -c -g string_graph.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o schedule
