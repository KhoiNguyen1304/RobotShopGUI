# Macros
#   syntax: 
#       <macro_name> = <macro_string>

# Entries
#   syntax:
#       <target>: [ <dependency> ]*
#           [ <TAB> <command> <endl> ] +

# object files
OBJS = main.o

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

clean:
	\rm *.o a.out    