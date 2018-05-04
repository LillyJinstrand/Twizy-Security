#
# 
# TLDR: Set the varibles in the top of the file, run make apollo, and then run catkin_make in the 
# ros folder in the apollo docker container

# Name of of the gpr file, and the directories to put binaries and similar into
GPR=security.gpr
OBJ=obj
BIN=bin
TEMP=temp
ROS=ros
# LIBGNAT needs to be set on a system by system basic
# The setting below is the path on an ubuntu 18 system
# The automatic path should work ubuntu and debian systems, possibly others
#LIBGNAT=/usr/lib/gcc/x86_64-linux-gnu/7/adalib/libgnat.a
LIBPATH=$(shell gcc --print-libgcc-file-name)
LIBGNAT=$(shell dirname $(LIBPATH))/adalib/libgnat.a

# Path to the apollo root, configure to match your apollo directory
APOLLO=~/AutonomousTwizy/src/BSc2018/apollo-2.0.0

# This block lists targets. They should be generated in a better way, but are hardcoded for now
# SPARKOBJECTS contains all the SPARK/Ada files to be built. Needed to differentiate between ada and c++ 
SPARKOBJECTS=$(OBJ)/gpsmodule.o $(OBJ)/perception.o $(OBJ)/speedmodule.o $(OBJ)/wrapper.o $(OBJ)/interface_utils.o $(OBJ)/mathutil.o $(OBJ)/converters.o 
# SPARKALI is just the same list as above but with .ali, can easily be replaced with something generated
SPARKALI=$(OBJ)/gpsmodule.ali $(OBJ)/perception.ali $(OBJ)/speedmodule.ali $(OBJ)/wrapper.ali $(OBJ)/interface_utils.ali $(OBJ)/mathutil.ali $(OBJ)/converters.ali 
# A list of ada spec files, needed to make lib.a to rebuilt when ada files changes
ADASPEC=common_data_h.ads perception_data_h.ads prediction_data_h.ads localization_data_h.ads control_cmd_data_h.ads speed_data_h.ads 

# Rule to build the main library, with the c++ wrapper. Matches the security.h header
# It combines the objects from security.o with lib.a by extracting the contents of lib.a into a temporary folder
# and then combines them, and finally deletes the temp folder.
$(BIN)/security.a: $(OBJ)/lib.a $(OBJ)/security.o
	mkdir -p $(BIN)
	rm -rf $(TEMP)
	mkdir $(TEMP)
	cd $(TEMP); ar -x ../$(OBJ)/lib.a; ar -x $(LIBGNAT)
	ar cr $(BIN)/security.a $(OBJ)/security.o $(TEMP)/*.o
	rm -rf $(TEMP)

# -fpic flag is needed to make sure library works correctly.
# -Wall is just to turn on warnings, more warnings could probably be enabled.
$(OBJ)/security.o: security.cc security.h
	g++ -c -fpic -o $(OBJ)/security.o -Wall security.cc

# Packs together the SPARK/Ada components into a temporary library.
# Can be linked to on ist own against the interface exposed in wrapper.ads
$(OBJ)/lib.a: $(ADASPEC) $(SPARKOBJECTS) 
	gnatbind -Lck -o ck.adb $(SPARKALI)
	gnatmake -D $(OBJ) ck.adb
	ar cr $(OBJ)/lib.a $(OBJ)/ck.o $(SPARKOBJECTS)
	rm -f ck.ad*

# Rule to make most SPARK/Ada files
$(OBJ)/%.o: %.adb %.ads 
	mkdir -p $(OBJ)
	gnatmake -D $(OBJ) $*

# Rule to make gnatmake run on spec only modules
$(OBJ)/%.o: %.ads
	mkdir -p $(OBJ)
	gnatmake -D $(OBJ) $*

# Builds and links the (very) limited test program.
# A full test suite is a good idea for an extension
$(BIN)/test: test.cc $(BIN)/security.a
	make $(ADASPEC)
	g++ -o $(BIN)/test test.cc $(BIN)/security.a

# This rule creates the ada specs from the c++ data files.
# NOTE: If you add any files that end in _data.h you will need to change this rule
%_data_h.ads: %_data.h
	g++ -c -fdump-ada-spec $^


# Utility rules to help with the horrible nightmare that is this build system
#
# The ros rule copies all the SPARK/Ada and wrapper components contained in security.a and security.h
# into their correct location in the ros folder.
# rsync is used instead of cp to preserver last modified times.
.PHONY: ros
ros: $(BIN)/security.a security.h perception_data.h
	rsync -auv security.h $(ROS)/src/security/include/security.h
	mkdir -p $(ROS)/src/security/lib
	rsync -auv $(BIN)/security.a $(ROS)/src/security/lib/security.a
	rsync -auv *_data.h $(ROS)/src/security/include/
	rm -rf $(ROS)/build

# Copies the whole ros folder into the configured apollo directory.
.PHONY: apollo
apollo:
	make ros
	rsync -auv -r $(ROS) $(APOLLO)

# Runs the small test program
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

# Runs the spark prover.
# Most often a good idea to run it directly from the command line with more precise options
.PHONY: prove
prove: $(OBJ)/lib.a
	gnatprove -j 0 -k --level=4 -P$(GPR)

# Nukes all binaries and build artifacts
.PHONY: clean
clean:
	rm -rf gnatprove
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf $(TEMP)
	rm -f $(ADASPEC)
