all:

SHELL       := /bin/sh

# Support out-of-tree builds
srcdir      := .
VPATH       := .

prefix      := /usr/local
exec_prefix := ${prefix}
datarootdir := ${prefix}/share
bindir      := ${exec_prefix}/bin
datadir     := ${datarootdir}
sysconfdir  := ${prefix}/etc
libdir      := ${exec_prefix}/lib
sbindir     := ${exec_prefix}/sbin
localstatedir := ${prefix}/var
CXX      := g++
# CXXFLAGS are for the main binary, so don't use them here, use MODFLAGS instead
MODFLAGS := -DHAVE_CONFIG_H    -D_FORTIFY_SOURCE=2 -O2 -Wall -W -Wno-unused-parameter -Woverloaded-virtual -Wshadow   -fvisibility=hidden -fPIC -I$(srcdir)/.. -I..
MODLINK  := -bundle -flat_namespace -undefined suppress
LDFLAGS  := 
# LIBS are not and should not be used in here.
# The znc binary links already against those.
# LIBS     := -lssl -lcrypto -lz  
PERL_ON  := no
PERL     := 
PYTHON_ON:= no
PY_CFLAGS:= 
PY_LDFLAGS:=
SWIG     := 
SWIG_ON  := @USESWIG@
MODDIR   := ${exec_prefix}/lib/znc
DATADIR  := ${datarootdir}/znc
LIBZNC   := 
LIBZNCDIR:= 
INSTALL         := /usr/bin/install -c
INSTALL_PROGRAM := ${INSTALL}
INSTALL_SCRIPT  := ${INSTALL}
INSTALL_DATA    := ${INSTALL} -m 644

TCL_FLAGS:= 

ifneq "$(V)" ""
VERBOSE=1
endif
ifeq "$(VERBOSE)" ""
Q=@
E=@echo
else
Q=
E=@\#
endif

ifneq "$(LIBZNC)" ""
LDFLAGS += -L.. -lznc -Wl,-rpath,$(LIBZNCDIR)
endif

CLEAN    :=

FILES    := $(notdir $(wildcard $(srcdir)/*.cpp))
# If extra is enabled
ifeq "no" "yes"
FILES    += $(addprefix extra/, $(notdir $(wildcard $(srcdir)/extra/*.cpp)))
endif

include $(srcdir)/modperl/Makefile.inc
include $(srcdir)/modpython/Makefile.inc
include $(srcdir)/modtcl/Makefile.inc

FILES    := $(basename $(FILES))

ifeq "" "1"
FILES    := $(foreach file, $(FILES), \
	$(if $(shell grep REQUIRESSL $(srcdir)/$(file).cpp), \
		, \
		$(basename $(file)) \
	))
endif

ifeq "" ""
FILES    := $(shell echo $(FILES) | sed -e "s:extra/saslauth::")
endif
saslauthFLAGS := -lsasl2

ifeq "" ""
FILES    := $(shell echo $(FILES) | sed -e "s:extra/charset::")
endif
charsetFLAGS := 

TARGETS  := $(addsuffix .so, $(FILES))

CLEAN    += *.so extra/*.so

.PHONY: all clean install install_datadir uninstall

all: $(TARGETS)

install: all install_datadir
	$(INSTALL_PROGRAM) $(TARGETS) $(DESTDIR)$(MODDIR)

install_datadir:
	rm -rf $(DESTDIR)$(DATADIR)/modules
	mkdir -p $(DESTDIR)$(MODDIR)
	mkdir -p $(DESTDIR)$(DATADIR)/modules
	rm -rf $(DESTDIR)$(MODDIR)/*.so
	mkdir -p $(DESTDIR)$(DATADIR)/modules
	cp -R $(srcdir)/data/* $(DESTDIR)$(DATADIR)/modules
	if test "no" = "yes" ; then \
		cp -R $(srcdir)/extra/data/* $(DESTDIR)$(DATADIR)/modules ; \
	fi
	find $(DESTDIR)$(DATADIR)/modules -type d -exec chmod 0755 '{}' \;
	find $(DESTDIR)$(DATADIR)/modules -type f -exec chmod 0644 '{}' \;

clean:
	rm -rf $(CLEAN)

%.so: %.cpp Makefile
	@mkdir -p .depend
	@mkdir -p extra
	$(E) Building $(if $(filter %extra/,$(dir $<)),extra )module $(notdir $(basename $@))...
	$(Q)$(CXX) $(MODFLAGS) $(LDFLAGS) $(MODLINK) -o $@ $< $($(notdir $(basename $@))FLAGS) -MMD -MF .depend/$(notdir $@).dep

uninstall:
	# Yes, we are lazy, just remove everything in there
	rm -rf $(DESTDIR)$(MODDIR)/*
	rm -rf $(DESTDIR)$(DATADIR)/*
	rmdir $(DESTDIR)$(MODDIR)
	rmdir $(DESTDIR)$(DATADIR)

-include $(wildcard .depend/*.dep)
