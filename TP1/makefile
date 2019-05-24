#-----------------------------------------------------------------------------
# this makefile relies on the Visual-Studio-2015 toolchain
# nb: this package provides the nmake.exe command

#~~~~ project-specific settings ~~~~
HEADER_FILES=platformAdapter.h \
             crsUtils.hpp
COMMON_OBJECT_FILES=crsUtils.obj
OBJECT_FILES=$(COMMON_OBJECT_FILES) \
             prog01_interaction.obj \
             prog01_interaction_solution.obj \
             prog02_copy.obj \
             prog02_copy_solution.obj \
             prog03_exec_redir.obj \
             prog03_exec_redir_solution.obj \
             prog04_fifo.obj \
             prog04_fifo_solution.obj
EXE_FILES=prog01_interaction.exe \
          prog01_interaction_solution.exe \
          prog02_copy.exe \
          prog02_copy_solution.exe \
          prog03_exec_redir.exe \
          prog03_exec_redir_solution.exe \
          prog04_fifo.exe \
          prog04_fifo_solution.exe

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
prog01_interaction.exe : \
  prog01_interaction.obj $(COMMON_OBJECT_FILES)

prog01_interaction.obj : \
  prog01_interaction.cpp $(HEADER_FILES)

prog01_interaction_solution.exe : \
  prog01_interaction_solution.obj $(COMMON_OBJECT_FILES)

prog01_interaction_solution.obj : \
  prog01_interaction_solution.cpp $(HEADER_FILES)

prog02_copy.exe : \
  prog02_copy.obj $(COMMON_OBJECT_FILES)

prog02_copy.obj : \
  prog02_copy.cpp $(HEADER_FILES)

prog02_copy_solution.exe : \
  prog02_copy_solution.obj $(COMMON_OBJECT_FILES)

prog02_copy_solution.obj : \
  prog02_copy_solution.cpp $(HEADER_FILES)

prog03_exec_redir.exe : \
  prog03_exec_redir.obj $(COMMON_OBJECT_FILES)

prog03_exec_redir.obj : \
  prog03_exec_redir.cpp $(HEADER_FILES)

prog03_exec_redir_solution.exe : \
  prog03_exec_redir_solution.obj $(COMMON_OBJECT_FILES)

prog03_exec_redir_solution.obj : \
  prog03_exec_redir_solution.cpp $(HEADER_FILES)

prog04_fifo.exe : \
  prog04_fifo.obj $(COMMON_OBJECT_FILES)

prog04_fifo.obj : \
  prog04_fifo.cpp $(HEADER_FILES)

prog04_fifo_solution.exe : \
  prog04_fifo_solution.obj $(COMMON_OBJECT_FILES)

prog04_fifo_solution.obj : \
  prog04_fifo_solution.cpp $(HEADER_FILES)

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
