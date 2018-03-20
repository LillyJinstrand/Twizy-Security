GPR=security.gpr
OBJ=obj
BIN=bin
TEMP=temp
ROS=ros
#LIBGNAT=/usr/lib/gcc/x86_64-linux-gnu/7/adalib/libgnat.a
LIBPATH=$(shell gcc --print-libgcc-file-name)
LIBGNAT=$(shell dirname $(LIBPATH))/adalib/libgnat.a
SPARKOBJECTS=$(OBJ)/gpsmodule.o $(OBJ)/perception.o $(OBJ)/speedmodule.o $(OBJ)/wrapper.o $(OBJ)/interface_utils.o
SPARKALI=$(OBJ)/gpsmodule.ali $(OBJ)/perception.ali $(OBJ)/speedmodule.ali $(OBJ)/wrapper.ali $(OBJ)/interface_utils.ali
ADASPEC=common_data_h.ads perception_data_h.ads prediction_data_h.ads localization_data_h.ads control_cmd_data_h.ads

APOLLO=~/AutonomousTwizy/src/BSc2018/apollo-2.0.0

$(BIN)/security.a: $(OBJ)/lib.a $(OBJ)/security.o
	mkdir -p $(BIN)
	rm -rf $(TEMP)
	mkdir $(TEMP)
	cd $(TEMP); ar -x ../$(OBJ)/lib.a; ar -x $(LIBGNAT)
	ar cr $(BIN)/security.a $(OBJ)/security.o $(TEMP)/*.o
	rm -rf $(TEMP)

$(OBJ)/security.o: security.cc security.h
	g++ -c -fpic -o $(OBJ)/security.o -Wall security.cc

$(OBJ)/lib.a: $(ADASPEC) $(SPARKOBJECTS) #$(OBJ)/wrapper.o 
	gnatbind -Lck -o ck.adb $(SPARKALI)
	gnatmake -D $(OBJ) ck.adb
	ar cr $(OBJ)/lib.a $(OBJ)/ck.o $(SPARKOBJECTS)
	rm -f ck.ad*

$(OBJ)/%.o: %.adb %.ads 
	mkdir -p $(OBJ)
	gnatmake -D $(OBJ) $*

$(BIN)/test: test.cc $(BIN)/security.a
	make $(ADASPEC)
	g++ -o $(BIN)/test test.cc $(BIN)/security.a


%_data_h.ads: %_data.h
	g++ -c -fdump-ada-spec $^



.PHONY: ros
ros: $(BIN)/security.a security.h perception_data.h
	cp security.h $(ROS)/src/package/include/security.h
	mkdir -p $(ROS)/src/package/lib
	cp $(BIN)/security.a $(ROS)/src/package/lib/security.a
	cp *_data.h $(ROS)/src/package/include/
	rm -rf $(ROS)/build

.PHONY: apollo
apollo:
	make ros
	cp -r $(ROS) $(APOLLO)

.PHONY: test
test: $(BIN)/test
	@echo -----------------------------
	@echo Starting test
	@echo -----------------------------
	@$(BIN)/test

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
	rm -f $(ADASPEC)
