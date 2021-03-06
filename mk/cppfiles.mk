USRCS = $(wildcard src/*.cpp)
TSRCS = $(wildcard tests/*.cpp)
LSRCS = $(shell python mk/pyfind.py lib .cpp)
SRCS  = $(USRCS) $(LSRCS) $(TSRCS)
HDRS  = $(wildcard include/*.h)

UOBJS = $(USRCS:.cpp=.o)
LOBJS = $(LSRCS:.cpp=.o)
TOBJS = $(TSRCS:.cpp=.o)
OBJS  = $(UOBJS) $(LOBJS) $(TOBJS)
DEPS  = $(OBJS:.o=.d)
ifeq ($(PLATFORM), Windows)
   DELFILES = $(subst /,\,$(OBJS)) $(subst /,\,$(DEPS))
else
   DELFILES = $(OBJS) $(DEPS) 
endif

