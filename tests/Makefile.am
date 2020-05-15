
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_BIBLION_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

noinst_PROGRAMS = v0

v0_SOURCES = v0.cc 
v0_LDFLAGS = $(OCTETOS_BIBLION_LIBS) $(top_builddir)/src/libbiblion.la
v0_CFLAGS = -I$(top_srcdir)/src 
v0_CPPFLAGS = -I$(top_srcdir)/src 
v0_CXXFLAGS = -I$(top_srcdir)/src
v0_LDADD = $(OCTETOS_BIBLION_LIBS) 
if NATIVE_WIN32
v0_LDFLAGS += -mwindows
endif
