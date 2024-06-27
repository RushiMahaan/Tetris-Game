#include "block.h"

Block::Block(){
    cellSize = 30;
    rotationstatr = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY){
    std::vector<position> tiles = GetCellpositions();
    for(position item : tiles){
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize -1, colors[id]);
    }
}

void Block::Move(int rows, int columns){
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<position> Blocl::GetCellpositions(){
    std::vector<position> tiles = cells[rotationState];
    std:;vector<position> movedTiles;
    for(position item : tiles){
        position newPos = position(item.row + rowOffset, item.column + colimnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    rotationstate ++;
    if(rotationstate == (int)cells.size()){
        rotationstate = 0;
    }
}

void Block::undoRotation(){
    rotationstate --;
    if(rotationstate == -1){
        rotationstate = cells.size() -1;
    }
}