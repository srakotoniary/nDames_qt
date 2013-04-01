#############################################################################
# Makefile for building: nDames_qt
# Generated by qmake (2.01a) (Qt 4.8.1) on: Mon Apr 1 23:19:57 2013
# Project:  nDames_qt.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile nDames_qt.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = case.cpp \
		fenetre.cpp \
		main.cpp \
		echequier.cpp \
		algo.cpp \
		generateandtest.cpp \
		backtrack.cpp \
		forwardchecking.cpp \
		recherchelocal.cpp moc_fenetre.cpp
OBJECTS       = case.o \
		fenetre.o \
		main.o \
		echequier.o \
		algo.o \
		generateandtest.o \
		backtrack.o \
		forwardchecking.o \
		recherchelocal.o \
		moc_fenetre.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nDames_qt.pro
QMAKE_TARGET  = nDames_qt
DESTDIR       = 
TARGET        = nDames_qt

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: nDames_qt.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile nDames_qt.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile nDames_qt.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/nDames_qt1.0.0 || $(MKDIR) .tmp/nDames_qt1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/nDames_qt1.0.0/ && $(COPY_FILE) --parents case.h fenetre.h echequier.h echequier.h algo.h generateandtest.h backtrack.h forwardchecking.h recherchelocal.h .tmp/nDames_qt1.0.0/ && $(COPY_FILE) --parents case.cpp fenetre.cpp main.cpp echequier.cpp algo.cpp generateandtest.cpp backtrack.cpp forwardchecking.cpp recherchelocal.cpp .tmp/nDames_qt1.0.0/ && (cd `dirname .tmp/nDames_qt1.0.0` && $(TAR) nDames_qt1.0.0.tar nDames_qt1.0.0 && $(COMPRESS) nDames_qt1.0.0.tar) && $(MOVE) `dirname .tmp/nDames_qt1.0.0`/nDames_qt1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/nDames_qt1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_fenetre.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_fenetre.cpp
moc_fenetre.cpp: echequier.h \
		case.h \
		forwardchecking.h \
		algo.h \
		generateandtest.h \
		backtrack.h \
		recherchelocal.h \
		fenetre.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) fenetre.h -o moc_fenetre.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

case.o: case.cpp case.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o case.o case.cpp

fenetre.o: fenetre.cpp fenetre.h \
		echequier.h \
		case.h \
		forwardchecking.h \
		algo.h \
		generateandtest.h \
		backtrack.h \
		recherchelocal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetre.o fenetre.cpp

main.o: main.cpp fenetre.h \
		echequier.h \
		case.h \
		forwardchecking.h \
		algo.h \
		generateandtest.h \
		backtrack.h \
		recherchelocal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

echequier.o: echequier.cpp echequier.h \
		case.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o echequier.o echequier.cpp

algo.o: algo.cpp algo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o algo.o algo.cpp

generateandtest.o: generateandtest.cpp generateandtest.h \
		algo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o generateandtest.o generateandtest.cpp

backtrack.o: backtrack.cpp backtrack.h \
		algo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o backtrack.o backtrack.cpp

forwardchecking.o: forwardchecking.cpp forwardchecking.h \
		algo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o forwardchecking.o forwardchecking.cpp

recherchelocal.o: recherchelocal.cpp recherchelocal.h \
		algo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o recherchelocal.o recherchelocal.cpp

moc_fenetre.o: moc_fenetre.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetre.o moc_fenetre.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

