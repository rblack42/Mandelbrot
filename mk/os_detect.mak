CXX = g++
CXXFLAGS =
LFLAGS =
ifeq ($(OS), Windows_NT)
    PREFIX = 
	RM = del
	EXT = .exe
	PLATFORM = Windows
else
    PREFIX = ./
	RM = rm -f
	EXT =
	PLATFORM = Mac
endif

include $(wildcard mk/*.mk)
