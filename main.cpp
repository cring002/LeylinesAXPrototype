//
//  Leylines protoype - Charlie Ringer - Copyright © 2017 cring002.github.io. All rights reserved.
//  
//  Axilya used with an MIT License - github.com/vexparadox/axilya
//
#include <Axilya/AXMain.h>
#include "level.h"

using namespace std;

Level* currentLevel;
AXTexture* background;

void setup()
{
    background = new AXTexture();
    background->loadImage("data/images/background.png");
    //Set the random seed
    srand (time(NULL));
    //Load all of the tile textures
    Tile::loadTextures();
    //Create a new level
    currentLevel = new Level("data/levels/testlevel.xml");
}

void update(){
    //Update the current level
    currentLevel->update();
}

void draw(){
    drawTexture(background, 0, 0, 1280, 720);
    //Draw the current level
    currentLevel->draw();
}

int main(int argc, char *argv[])
{
    //Make a new AX Window
    if(!AXWindow::init(1280, 720, "Leyline Prototype", AX_DEFAULT, setup, update, draw)){
        AXLog::log("Window failed to initialise", "Quitting", AX_LOG_ERROR);
        return -1;
    }
    //return the window run, this is where the update and draw will be called
    return AXWindow::run();
}
