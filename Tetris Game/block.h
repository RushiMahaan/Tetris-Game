#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int columns);
        std::vector<position> GetCellpositions();
        void Rotate();
        void undoRotation();
        int id;
        std::map<int, std::vector<position>> cells;

    private: 
    int cellSize;
    int rotationstate;
    std::vector<color> colors; 
    int rowOffset;
    int columnOffset;  
};