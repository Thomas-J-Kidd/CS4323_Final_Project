In order to create the executables please type `make` in the src directory

We tested our code on the csx0 server. 

Contents of the Makefile

```
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = driver

# Object files
OBJS = driver.o InputParser.o IPCModule.o ProcessManager.o SynchronizationModule.o Account.o File.o

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Individual source files
driver.o: driver.cpp InputParser.h ProcessManager.h IPCModule.h SynchronizationModule.h Account.h File.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

InputParser.o: InputParser.cpp InputParser.h
	$(CXX) $(CXXFLAGS) -c InputParser.cpp

IPCModule.o: IPCModule.cpp IPCModule.h
	$(CXX) $(CXXFLAGS) -c IPCModule.cpp

ProcessManager.o: ProcessManager.cpp ProcessManager.h
	$(CXX) $(CXXFLAGS) -c ProcessManager.cpp

SynchronizationModule.o: SynchronizationModule.cpp SynchronizationModule.h
	$(CXX) $(CXXFLAGS) -c SynchronizationModule.cpp

Account.o: Account.cpp Account.h
	$(CXX) $(CXXFLAGS) -c Account.cpp

File.o: File.cpp File.h
	$(CXX) $(CXXFLAGS) -c File.cpp

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
```