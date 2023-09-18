#pragma once
#include "raylib.h"

// window and overall game variables
const int tileSize = 10;

const int maxTileRow = 100;
const int maxTileCol = 100;

const int windowHeight = maxTileRow * tileSize;
const int windowWidth = maxTileCol * tileSize;

const int FPS = 60;

// path finding variables
int bulletX;
int bulletY;

int startingX;
int startingY;

int destinationX;
int destinationY;

int distanceX;
int distanceY;

// Mode variables
const int startingPoint = 0;
const int endingPoint = 2;

int clickingMode = startingPoint;
