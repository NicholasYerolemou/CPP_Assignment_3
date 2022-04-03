CC=g++
CXXFLAGS=$(INCLUDES) -Wall # Headers + All Warnings

TARGET=findcomp
OBJECTS= ConnectedComponent.o PGMimageProcessor.o driver.o
# Linking Rule

$(TARGET): $(OBJECTS)
	$(CC) PGMimageProcessor.h
	$(CC) $(OBJECTS) -o $(TARGET)
	@cp $(TARGET) ./binaries


.cpp.o:
	$(CC) $(CXXFLAGS) -c $<

test: UnitTests.o ConnectedComponent.o PGMimageProcessor.o
	$(CC) -c UnitTests.cpp
	$(CC) -o UnitTest UnitTests.o ConnectedComponent.o PGMimageProcessor.o
	./UnitTest

clean:
	@rm -f *.o
	rm findcomp
	rm UnitTest