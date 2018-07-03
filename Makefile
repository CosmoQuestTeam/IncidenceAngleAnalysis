#Makefile

TOPDIR = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BINDIR = $(TOPDIR)bin
INCDIR = $(TOPDIR)include
OBJDIR = $(TOPDIR)obj
SRCDIR = $(TOPDIR)src
SOURCES := $(wildcard $(SRCDIR)/*.cc)
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE1 := $(BINDIR)/IncidenceAngleAnalysis
EXE1_OBJS := $(OBJDIR)/Checkpoint.o $(OBJDIR)/EquirectangularProjection.o $(OBJDIR)/Images.o $(OBJDIR)/ImageSets.o $(OBJDIR)/IncidenceAngleAnalysis.o $(OBJDIR)/IncidenceAngles.o $(OBJDIR)/MySQLConnection.o $(OBJDIR)/OverlappedImages.o $(OBJDIR)/Plot.o $(OBJDIR)/ProjectiveTransformation.o $(OBJDIR)/ReadAuxilaryData.o $(OBJDIR)/RetrieveImages.o $(OBJDIR)/RetrieveImageSets.o $(OBJDIR)/SearchImages.o $(OBJDIR)/SortImages.o $(OBJDIR)/SortImageSets.o $(OBJDIR)/Utilities.o

#EXE1_OBJS := $(OBJDIR)/Circle.o $(OBJDIR)/EquirectangularProjection.o $(OBJDIR)/MySQLConnection.o $(OBJDIR)/Marks.o $(OBJDIR)/MasterImageOrientation.o  $(OBJDIR)/PixelResolution.o $(OBJDIR)/Rectangle.o  $(OBJDIR)/RetrieveImageSets.o $(OBJDIR)/RetrieveMarks.o $(OBJDIR)/SearchIncidenceAngles.o $(OBJDIR)/SearchMarks.o $(OBJDIR)/SortIncidenceAngles.o $(OBJDIR)/SortMasterImageOrientation.o $(OBJDIR)/SortMarks.o $(OBJDIR)/SortOverlappedImages.o $(OBJDIR)/SortPixelResolutions.o $(OBJDIR)/Utilities.o

CC = g++
CFLAGS = -g -Wshadow -Wall -Wextra -O3 -march=native -mavx -std=c++11
LDFLAGS = -lm -lmysqlcppconn
ROOT = $(ROOTSYS)
ROOTINCDIR = $(ROOT)/include/root
ROOTLIBDIR = $(ROOT)/lib/root
ROOTCONFIG = -L$(ROOTLIBDIR) -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread

all : $(OBJECTS) $(EXECUTABLE1)

$(EXECUTABLE1) : $(EXE1_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(ROOTCONFIG) $(EXE1_OBJS) -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cc
	$(CC) -c $(CFLAGS) -I$(INCDIR) -I$(ROOTINCDIR) -MMD $< -o $@

.PHONY : clean

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE1) $(OBJDIR)/*.d $(OBJDIR)/*.o
