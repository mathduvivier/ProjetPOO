CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 \
           -IComponents \
           -IComponents/Grid \
           -IServices \
           -IServices/File \
           -IServices/GameOfLife \
           -IIHM \
           -IServices/Test

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp \
      Components/Grid/Grid.cpp \
      Services/GameOfLife/GameOfLife.cpp \
      Services/File/File.cpp \
      IHM/GraphicSFML.cpp \
      Services/Test/Test.cpp

OBJ = $(SRC:.cpp=.o)

game: $(OBJ)
	$(CXX) -o game $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o
	rm -f Components/*.o
	rm -f Components/Grid/*.o
	rm -f Components/typeState/*.o
	rm -f Services/*.o
	rm -f Services/File/*.o
	rm -f Services/GameOfLife/*.o
	rm -f Services/Test/*.o
	rm -f IHM/*.o
	rm -f game

	find . -name "iteration_*.txt" -delete
