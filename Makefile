######################################################################
#  Top Level
######################################################################

TOPDIR  := $(realpath $(CURDIR))

.PHONY: clean
clean:
	-rm $(TOPDIR)/*/*/*/*.o
	-rm $(TOPDIR)/*/*/*/*.d