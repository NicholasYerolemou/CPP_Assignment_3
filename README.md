# CPP_Assignment_3

How to run:

This program has a working makefile.
To compile type "make"
To run type "./findcomp [parameters]

The order of the parameters does not matter and both -p and -w are optional.



If you wish to run the unit tests type "run test".
This will automatically run the unit test program.
Note: one of the tests print out data instead of a REQUIRE statement

A "make clean" command is also available.

Note:When running with the -p parameter to print to an output file the code is very inefficient, give it about 10 seconds to produce the output file. Furthermore, the output file is not correct. It produces a series of lines, with the correct number of components but incorrect shape.



Role of files

The driver.cpp contains the main class that hnadles the user input and calling the correct functions based on that input.

PGMImageProcessor.cpp holds the main chunk of the code, it handels the image and all its manipulation. As well as actually extracting the components from the image.

ConnectedComponent.cpp is a small class that holds a few variables to represent a component in the image.
