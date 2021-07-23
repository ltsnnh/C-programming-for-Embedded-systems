######################################################################
# Author: Ltsnnh
######################################################################

PRJDIR  := $(realpath $(CURDIR))
INCDIR  := $(PRJDIR)/inc
SRCDIR  := $(PRJDIR)/src
OBJDIR  := $(PRJDIR)/obj

BINARY  = main

# Find all the C and C++ files we want to compile
SRCS    := $(shell find $(SRCDIR) -name *.cpp -or -name *.c)
# Classify C/C++ files
SRCSC	:= $(filter %.c,$(SRCS))
SRCSCPP	:= $(filter %.cpp,$(SRCS))

# String substitution for every C/C++ files
OBJS    := $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(notdir $(SRCSC))))
OBJS    += $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(notdir $(SRCSCPP))))

DEPS    := $(OBJS:.o=.d)

# Add a prefix to INCDIR
INC_FLAGS   := $(addprefix -I,$(INCDIR))
# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS    := $(INC_FLAGS) -MMD -MP

CC  = gcc
CXX = g++
CFLAGS = -std=c99 -Wall -g
CXXFLAGS = -Wall -g

# The final build step.
$(PRJDIR)/$(BINARY): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJDIR)/*.o -o $@

# Build step for C source
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean clobber
clean:
	-rm -f $(OBJDIR)/*.o
	-rm -f $(OBJDIR)/*.d

clobber: clean
	-rm -f $(BINARY)

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
