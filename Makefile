CXX = g++
CXXFLAGS = -std=c++2b -Wall -Werror
TARGET = output

# Only include implementation files, NOT the test source files
SOURCES = main.cc \
          Compiler/compiler.cc Compiler/compile.cc Compiler/getresult.cc \
          Compiler/sendresult.cc Compiler/handlecompilationerror.cc \
          CompilationJobs/compilationjobs.cc CompilationJobs/getsourcefile.cc \
          CompilationManager/producer.cc CompilationManager/consumer.cc

# Build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean target  
clean:
	rm -f $(TARGET) error.txt *.o source1.o source2.o source3.o

.PHONY: clean