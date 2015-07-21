# Compiler.
CC = g++

# Warning level.
WARN = -Wall

# Optimization level.
OPT = -O3

# Where to find the SVDLIBC package.
SVDLIBC = third_party/SVDLIBC

# Where to find the Eigen package.
EIGEN = third_party/eigen-eigen-36fd1ba04c12

# Compiler flags
CFLAGS = $(WARN) $(OPT) -pthread -std=c++11

# Extract object filenames by substituting ".cc" to ".o" in source filenames.
files = $(subst .cc,.o,$(shell ls *.cc) $(shell ls src/*.cc))

all: singular

singular: $(files) $(SVDLIBC)/libsvd.a
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cc
	$(CC) -c $< -o $@ -I $(EIGEN) $(CFLAGS)

$(SVDLIBC)/libsvd.a:
	make -C $(SVDLIBC)

.PHONY: clean
clean:
	rm -rf *.o src/*.o singular
	make -C $(SVDLIBC) clean
