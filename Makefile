bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir 	-p 	bin
	g++ 	-o 	bin/testTableEntry testTableEntry.cpp
	
bin/testHashTable:	Dict.h	HashTable.h	TableEntry.h
	mkdir	-p	bin
	g++	-o	bin/testHashTable	testHashTable.cpp

bin/testBSTree:	testBSTree.cpp	BSNode.h	BSTree.h
	mkdir	-p	bin
	g++	-o	bin/testBSTree	testBSTree.cpp

bin/testBSTreeDict:  BSTree.h BSNode.h TableEntry.h Dict.h testBSTreeDict.cpp
	mkdir	-p	bin
	g++ 	-o	bin/testBSTreeDict testBSTreeDict.cpp BSTree.h BSNode.h BSTreeDict.h
	
clean:
	rm -rf *.o *.gch bin
