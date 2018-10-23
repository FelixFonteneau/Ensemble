ECHO= @echo
RM= rm
COMP= g++
EDL= g++
CPPFLAGS= -D MAP
EDLFLAGS= 
RMFLAGS= -f
INT= Ensemble.h Test.h 
REAL= $(INT:.h=.cpp)
OBJ= $(REAL:.cpp=.o)
LIBS=
INCPATH=
LIBPATH=
EFFACE= clean
EXE= Ensemble
DATE= 22.10
AUTHOR= Baptiste & Felix
YEAR= 2018
EMAIL= baptiste.pauletto@insa-lyon.fr felix.fonteneau@insa-lyon.fr

.PHONY: $(EFFACE)

$(EXE) : $(OBJ) 
	$(ECHO) "Edition de liens de <$(EXE)>"
	$(EDL) -o $(EXE) $(OBJ) $(LIBS)

Ensemble.o : Ensemble.cpp Ensemble.h
	$(ECHO) "Compilation de <Ensemble.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c Ensemble.cpp

Test.o : Test.cpp Ensemble.h
	$(ECHO) "Compilation de <Test.cpp>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c Test.cpp

$(EFFACE) :
	$(ECHO) "Suppression des morts de Felix"
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core
