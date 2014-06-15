CC=g++
CFLAGS=-I Project

PROJECT_SRC = Project
PROJECT_OBJ = OBJ_Project
DESP = $(PROJECT_SRC)/Number.h

$(PROJECT_OBJ)/%.o: $(PROJECT_SRC)/%.cpp $(DESP)
	@mkdir -p $(PROJECT_OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

Calculate: $(PROJECT_OBJ)/Number.o $(PROJECT_OBJ)/CalculateSquares.o
	$(CC) -g $(PROJECT_OBJ)/Number.o $(PROJECT_OBJ)/CalculateSquares.o -o Calculate $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(PROJECT_OBJ)/*.o Calculate


