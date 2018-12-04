CXX = g++
CXXFLAGS =
LFLAGS =
DELFILES =
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

# include make modules (order is important)

include $(wildcard mk/cppfiles.mk)
include $(wildcard mk/cppgraphics.mk)
include $(wildcard mk/cppproj.mk)
include $(wildcard mk/cpplint.mk)
include $(wildcard mk/util/*.mk)


