#
# Specifiy the target
all:	FBL

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
FBL:		FBLUser.o FBLUserLL.o FBLUserNode.o CA3.o FBLPost.o FBLPostNode.o FBLPostLL.o FBLComment.o FBLCommentNode.o FBLCommentLL.o
	g++  FBLUser.o FBLUserLL.o FBLUserNode.o CA3.o FBLPost.o FBLPostNode.o FBLPostLL.o FBLComment.o FBLCommentNode.o FBLCommentLL.o -o FBL

FBLUser.o:	FBLUser.cpp FBLUser.h
	g++ -c FBLUser.cpp

FBLUserLL.o:	FBLUserLL.cpp FBLUser.h
	g++ -c FBLUserLL.cpp

FBLUserNode.o:	FBLUserNode.cpp FBLUserNode.h
	g++ -c FBLUserNode.cpp

FBLPost.o:	FBLPost.cpp FBLPost.h
	g++ -c FBLPost.cpp

FBLPostNode.o:	FBLPostNode.cpp FBLPostNode.h
	g++ -c FBLPostNode.cpp

FBLPostLL.o:	FBLPostLL.cpp FBLPostLL.h
	g++ -c FBLPostLL.cpp

FBLComment.o: FBLComment.cpp FBLComment.h
	g++ -c FBLComment.cpp

FBLCommentNode.o: FBLCommentNode.cpp FBLCommentNode.h
	g++ -c FBLCommentNode.cpp

FBLCommentLL.o: FBLCommentLL.cpp FBLCommentLL.h
	g++ -c FBLCommentLL.cpp

CA3.o:		CA3.cpp
	g++ -c CA3.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o FBL
