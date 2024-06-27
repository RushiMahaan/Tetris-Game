#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock(){
    if(blocks.empty()){
      blocks =GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + ramdomIndex);
    return block;
}

std::vector<Block> Game::GettAllBlocks(){
    return {IBlocks(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};

}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw(11, 11);
    nextBlock.Draw(270, 270);
}

void Game::HandleInput(){
    int keypressed = Getkeypressed();
    if(gameOver && keypressed != 0){
        gameOver = false;
        Reset();
    }
    switch(keypressed){
        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
        casw KEYUP;
        RotateBlock();
        break;
    }
}

void Game::MoveBlockleft(){
    if(!gameOver){
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false){
         currentBlock.Move(0, 1);
    }
    }
}

void Game::MoveBlockRight(){
    if(!gameOver){
    currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false){
         currentBlock.Move(0, -1);
    }
    }
}

void Game::MoveBlockDown(){
    if(!gameOver){
    currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false){
         currentBlock.Move(-1, 0);
         LockBlock();
    }
    }
}

bool Game::IsBlockOutside(){
    std::vector<position> tiles + currentBlock.GetCellpositions();
    for(position item: tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock(){
    if(!rameOver){
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false){
        currentBlock.undoRotation();
    }
    }
}

void Game::LockBlock(){
    std::vector<position> tiles = currentBlock.GetCellpositions();
    for(position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock:
    if(BlockFits() == false){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
   int rowsCleared = grid.ClearFullRows();
   UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits(){
    std::vector<position> tiles = currentBlock.GetCellpositions();
    for(position item: tiles){
        if(grid.IsCellEmpty(item.row, item.column) == false){
            return false;
        }
    }
    return true;
}

void Game::Reset(){
    grid.Initalize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlocks();
    score = 0;
}

void Game::UpdateScore(int linescleared, int movedownpoints){
    switch (linescleared){
        case 1:
        score += 100;
        break;
        case 2:
        score += 300;
        break;
        case 3:
        score += 500;
        break;
        default:
        break;
    }

    Score = movedownpoints;
}