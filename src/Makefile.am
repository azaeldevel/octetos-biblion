
cita.tab.c : cita.y 
	bison -d -o $@ $<

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_BIBLION_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = octetos_biblion

octetos_biblion_SOURCES = \
	main.cc \
	cita.tab.c \
	cita-lexer.cc \
	biblion.cc

octetos_biblion_LDFLAGS = 

octetos_biblion_LDADD = $(OCTETOS_BIBLION_LIBS)


if NATIVE_WIN32
octetos_biblion_LDFLAGS += -mwindows
endif
