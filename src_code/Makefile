# Macros
#   syntax: 
#       <macro_name> = <macro_string>

# Entries
#   syntax:
#       <target>: [ <dependency> ]*
#           [ <TAB> <command> <endl> ] +

# object files
OBJS = main.o RobotPart.o Torso.o Head.o Arm.o Locomotor.o Battery.o RobotModel.o TrackingParts.o RobotOrder.o Customer.o

# compiler
#   since fltk-config --cxx displays the c++ compiler that was used to compile FLTK (g++)
#       we just use it instead of ... for safety purpose
CC = -std=c++11
CXX = $(shell fltk-config --cxx)

# debugging flag
DEBUG = -g

# flags used in compiling and creating object files
#   - fltk-config --cxxflags displays C++ complier options to use when compiling FLTK
#       source files
#       + can also be used when compiling non FLTK files
#   - Wall: tells compiler to print all warnings
#   - c: is needed to create object file, i.e. .o files
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -c $(DEBUG)

# flags used in linking
#   - fltk-config --ldflags displays the linker options to use when linking a FLTK app
#   - ??? fltk-config --ldstaticflags ... when lking a FLTK app to the static FLTK libraries
LFLAGS = $(shell fltk-config --ldflags) -Wall $(DEBUG)
# may need below options when using images
# LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)

# FLTK libraries 
FLTKLIB = -lfltk

executable: $(OBJS)
	$(CC) $(CXX) $(LFLAGS) $(OBJS) $(FLTKLIB)

main.o: main.cpp
	$(CC) $(CXX) $(CXXFLAGS) main.cpp

RobotPart.o : RobotPart.cpp RobotPart.h
	$(CC) $(CXX) $(CXXFLAGS) RobotPart.cpp

Torso.o : Torso.cpp Torso.h
	$(CC) $(CXX) $(CXXFLAGS) Torso.cpp

Head.o : Head.cpp Head.h
	$(CC) $(CXX) $(CXXFLAGS) Head.cpp

Arm.o : Arm.cpp Arm.h
	$(CC) $(CXX) $(CXXFLAGS) Arm.cpp

Locomotor.o : Locomotor.cpp Locomotor.h
	$(CC) $(CXX) $(CXXFLAGS) Locomotor.cpp

Battery.o : Battery.cpp Battery.h
	$(CC) $(CXX) $(CXXFLAGS) Battery.cpp

RobotModel.o : RobotModel.cpp RobotModel.h
	$(CC) $(CXX) $(CXXFLAGS) RobotModel.cpp

TrackingParts.o : TrackingParts.cpp TrackingParts.h
	$(CC) $(CXX) $(CXXFLAGS) TrackingParts.cpp

RobotOrder.o : RobotOrder.cpp RobotOrder.h
	$(CC) $(CXX) $(CXXFLAGS) RobotOrder.cpp

Customer.o: Customer.cpp Customer.h
	$(CC) $(CXX) $(CXXFLAGS) Customer.cpp

clean:
	\rm *.o a.out    