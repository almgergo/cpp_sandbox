# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\projects\personal\Cpp\simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\projects\personal\Cpp\simulator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\simulator.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\simulator.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\simulator.dir\flags.make

CMakeFiles\simulator.dir\main.cpp.obj: CMakeFiles\simulator.dir\flags.make
CMakeFiles\simulator.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\projects\personal\Cpp\simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simulator.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\simulator.dir\main.cpp.obj /FdCMakeFiles\simulator.dir\ /FS -c E:\projects\personal\Cpp\simulator\main.cpp
<<

CMakeFiles\simulator.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulator.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\simulator.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\projects\personal\Cpp\simulator\main.cpp
<<

CMakeFiles\simulator.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulator.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\simulator.dir\main.cpp.s /c E:\projects\personal\Cpp\simulator\main.cpp
<<

# Object files for target simulator
simulator_OBJECTS = \
"CMakeFiles\simulator.dir\main.cpp.obj"

# External object files for target simulator
simulator_EXTERNAL_OBJECTS =

simulator.exe: CMakeFiles\simulator.dir\main.cpp.obj
simulator.exe: CMakeFiles\simulator.dir\build.make
simulator.exe: CMakeFiles\simulator.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\projects\personal\Cpp\simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simulator.exe"
	"C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\simulator.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\simulator.dir\objects1.rsp @<<
 /out:simulator.exe /implib:simulator.lib /pdb:E:\projects\personal\Cpp\simulator\cmake-build-debug\simulator.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\simulator.dir\build: simulator.exe

.PHONY : CMakeFiles\simulator.dir\build

CMakeFiles\simulator.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\simulator.dir\cmake_clean.cmake
.PHONY : CMakeFiles\simulator.dir\clean

CMakeFiles\simulator.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\projects\personal\Cpp\simulator E:\projects\personal\Cpp\simulator E:\projects\personal\Cpp\simulator\cmake-build-debug E:\projects\personal\Cpp\simulator\cmake-build-debug E:\projects\personal\Cpp\simulator\cmake-build-debug\CMakeFiles\simulator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\simulator.dir\depend

