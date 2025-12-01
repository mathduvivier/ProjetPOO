CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -IComponents -IServices -IIHM

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp \
      Components/Grid.cpp \
      Services/File.cpp \
      Services/GameOfLife.cpp \
      IHM/GraphicSFML.cpp

OBJ = $(SRC:.cpp=.o)

game: $(OBJ)
	$(CXX) -o game $(OBJ) $(LDFLAGS)
