
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

lib_LTLIBRARIES = libbiblion.la

libbiblion_la_CFLAGS = -fPIC  $(AM_CFLAGS)
libbiblion_la_CPPFLAGS = -fPIC $(AM_CPPFLAGS)
libbiblion_la_CXXFLAGS = -fPIC $(AM_CPPFLAGS)
libbiblion_la_LDFLAGS = -shared -fPIC
if PLATFORM_WIN32
libbiblion_la_LDFLAGS += -no-undefined
endif
if NATIVE_WIN32
libbiblion_la_LDFLAGS += -export-dynamic

libbiblion_la_LIBADD = $(OCTETOS_BIBLION_LIBS)
endif
libbiblion_la_LIBDADD =
libbiblion_la_SOURCES = \
	cita.c \
	cita.tab.c \
	cita-lexer.cc \
	biblion.cc


