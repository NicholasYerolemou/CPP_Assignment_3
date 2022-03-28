CC=g++
CXXFLAGS=$(INCLUDES) -Wall # Headers + All Warnings

TARGET=findcomp
OBJECTS=PGMimageProcessor.o ConnectedComponent.o driver.o
# Linking Rule

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@cp $(TARGET) ./binaries


.cpp.o:
	$(CC) $(CXXFLAGS) -c $<

test: UnitTests.o
	$(CC) -c UnitTests.cpp
	$(CC) -o UnitTest UnitTests.o 
	./UnitTest

clean:
	@rm -f *.o
	rm findcomp
	rm UnitTest