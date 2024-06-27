#include <raylib.h>
#include "game.h"
#include "colors.h"
#include<iostream>

double lastupdatetime = 0;

bool EventTriggered(double interval){
    double currenttime = gettime();
    if(currenttime - lastupdatetime >= interval){
        lastupdatetime = currenttime;
        return true;
    }
    return false;
}
int main(){
    InitWindow(500, 620, "raylib Tetris"); 
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while(WindowShouldClose()==false){ 
        game.HandleInput();
        if (EventTriggered(0.2)){
        game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver){
        DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoretext[10];
        sprintf(scoretext, %d, game.score);
        Vector2 textsize = MeasureTextEx(font, scoretext, 38, 2);
        DrawTextEx(font, scoretext, {320 + (170 - textsize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}