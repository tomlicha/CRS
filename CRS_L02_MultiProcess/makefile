#-----------------------------------------------------------------------------
# this makefile relies on the Visual-Studio-2015 toolchain
# nb: this package provides the nmake.exe command

#~~~~ project-specific settings ~~~~
HEADER_FILES=platformAdapter.h \
             crsUtils.hpp
COMMON_OBJECT_FILES=crsUtils.obj
OBJECT_FILES=$(COMMON_OBJECT_FILES) \
             prog01_fork_waitpid.obj \
             prog01_fork_waitpid_solution.obj \
             prog02_address_space.obj \
             prog02_address_space_solution.obj \
             prog03_pipe.obj \
             prog03_pipe_solution.obj \
             prog04_pipe_redir_exec.obj \
             prog04_pipe_redir_exec_solution.obj
EXE_FILES=prog01_fork_waitpid.exe \
          prog01_fork_waitpid_solution.exe \
          prog02_address_space.exe \
          prog02_address_space_solution.exe \
          prog03_pipe.exe \
          prog03_pipe_solution.exe \
          prog04_pipe_redir_exec.exe \
          prog04_pipe_redir_exec_solution.exe

#~~~~ compiler/linker settings ~~~~
CXX=cl.exe /nologo /W3 /EHsc
CXXFLAGS=/MD
LDFLAGS=/link USER32.LIB WS2_32.LIB

#~~~~ debug/optimisation settings ~~~~
# (un)comment to {en|dis}able optimisation
# CXXFLAGS=$(CXXFLAGS) /O2
#
# (un)comment to {en|dis}able debug informations
CXXFLAGS=$(CXXFLAGS) /Z7

#~~~~ main target ~~~~
all : $(EXE_FILES)

rebuild : clean all

#~~~~ source file dependencies ~~~~
prog01_fork_waitpid.exe : \
  prog01_fork_waitpid.obj $(COMMON_OBJECT_FILES)

prog01_fork_waitpid.obj : \
  prog01_fork_waitpid.cpp $(HEADER_FILES)

prog01_fork_waitpid_solution.exe : \
  prog01_fork_waitpid_solution.obj $(COMMON_OBJECT_FILES)

prog01_fork_waitpid_solution.obj : \
  prog01_fork_waitpid_solution.cpp $(HEADER_FILES)

prog02_address_space.exe : \
  prog02_address_space.obj $(COMMON_OBJECT_FILES)

prog02_address_space.obj : \
  prog02_address_space.cpp $(HEADER_FILES)

prog02_address_space_solution.exe : \
  prog02_address_space_solution.obj $(COMMON_OBJECT_FILES)

prog02_address_space_solution.obj : \
  prog02_address_space_solution.cpp $(HEADER_FILES)

prog03_pipe.exe : \
  prog03_pipe.obj $(COMMON_OBJECT_FILES)

prog03_pipe.obj : \
  prog03_pipe.cpp $(HEADER_FILES)

prog03_pipe_solution.exe : \
  prog03_pipe_solution.obj $(COMMON_OBJECT_FILES)

prog03_pipe_solution.obj : \
  prog03_pipe_solution.cpp $(HEADER_FILES)

prog04_pipe_redir_exec.exe : \
  prog04_pipe_redir_exec.obj $(COMMON_OBJECT_FILES)

prog04_pipe_redir_exec.obj : \
  prog04_pipe_redir_exec.cpp $(HEADER_FILES)

prog04_pipe_redir_exec_solution.exe : \
  prog04_pipe_redir_exec_solution.obj $(COMMON_OBJECT_FILES)

prog04_pipe_redir_exec_solution.obj : \
  prog04_pipe_redir_exec_solution.cpp $(HEADER_FILES)

crsUtils.obj : crsUtils.cpp $(HEADER_FILES)

#~~~~ linker command to produce the executable files ~~~~
.obj.exe :
	@echo ==== linking $@ ====
	$(CXX) $** $(LDFLAGS) /out:$@
	@echo.

#~~~~ compiler command for every source file ~~~~
.cpp.obj :
	@echo ==== compiling $< ====
	$(CXX) /Fo$@ /c $<  $(CXXFLAGS)
	@echo.

#~~~~ remove generated files ~~~~
clean :
	@echo ==== cleaning ====
	del /q $(OBJECT_FILES) $(EXE_FILES) output_*
	@echo.

#-----------------------------------------------------------------------------
