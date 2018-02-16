GPR=security.gpr
OBJ=obj
BIN=bin
TEMP=temp
LIBGNAT=/usr/lib/gcc/x86_64-linux-gnu/7/adalib/libgnat.a

security.a: lib.a security.o
	mkdir -p $(BIN) 
	rm -rf $(TEMP)
	mkdir $(TEMP)
	cd $(TEMP); ar -x ../$(OBJ)/lib.a; ar -x $(LIBGNAT)
	ar cr $(BIN)/security.a $(OBJ)/security.o $(TEMP)/*.o 

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
	gnatprove -j 0 -k --level=4 -P$(GPR)
.PHONY: clean
clean:
	rm -rf gnatprove
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf $(TEMP)
