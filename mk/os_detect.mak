CXX = g++
CXXFLAGS =
LFLAGS =
ifeq ($(OS), Windows_NT)
    PREFIX = 
	RM = del
	EXT = .exe
	PLATFORM = Windows
else
    RM = rm -f
    EXT =
    PREFIX = ./
    UNAME = $(shell uname -s)
    ifeq ($(UNAME), Linux)
	PLATFORM = Linux
    else
	PLATFORM = Mac
    endif
endif

include $(wildcard mk/*.mk)
