GPR=security.gpr
OBJ=obj
BIN=bin

security.a: lib.a security.o
	mkdir -p $(BIN)
	ar rcs $(BIN)/security.a $(OBJ)/security.o $(OBJ)/lib.a /usr/lib/gcc/x86_64-linux-gnu/7/adalib/libgnat.a

security.o: security.cc security.h
	g++ -c -o $(OBJ)/security.o -Wall security.cc 

lib.a: wrapper.o
	gnatbind -Lck -o ck.adb $(OBJ)/wrapper.ali
	gnatmake -D $(OBJ) ck.adb
	ar cr $(OBJ)/lib.a $(OBJ)/ck.o $(OBJ)/wrapper.o
	rm -f ck.ad*


wrapper.o: wrapper.adb wrapper.ads
	mkdir -p $(OBJ)
	gnatmake -D $(OBJ) wrapper



.PHONY: spark
spark:
	mkdir -p obj
	gnatmake -P$(GPR)

.PHONY: prove
prove:
	gnatprove -j 0 --level=4 -P$(GPR)
.PHONY: clean
clean:
	rm -rf gnatprove
	rm -rf obj/*
	rm -rf bin/*
