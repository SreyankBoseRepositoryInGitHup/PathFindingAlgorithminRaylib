#include "raylib.h"
#include "variables.h"

void drawBullet();
// main Function
int main()
{
	// Initializing Window
	InitWindow(windowWidth, windowHeight, "Game Window");
	SetTargetFPS(FPS);

	// Game Loop calling the drawBullet Function
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGREEN);

		drawBullet();
		EndDrawing();
	}
	//Closing Window
	CloseWindow();

	return 0;
}
// drawBullet Function
void drawBullet() {

	// change mode 
	if (IsKeyPressed(KEY_ONE)) {
		clickingMode = startingPoint;
	}
	else if (IsKeyPressed(KEY_TWO)) {
		clickingMode = endingPoint;
	}

	// set clicking type according to mode
	if (IsMouseButtonPressed(0)) {
		if (clickingMode == startingPoint) {
			startingX = GetMousePosition().x;
			startingY = GetMousePosition().y;
		}
		else if (clickingMode == endingPoint) {
			destinationX = GetMousePosition().x;
			destinationY = GetMousePosition().y;
		}
	}

	// set the starting of the line to the starting of the point
	bulletX = startingX;
	bulletY = startingY;

	// draw a Black Line from the starting point to the ending point
	if (bulletX < destinationX) {
		while (bulletX < destinationX) {
			DrawRectangle(bulletX, bulletY, 1, 1, BLACK);
			bulletX++;
		}
	}
	if (bulletX > destinationX) {
		while (bulletX > destinationX) {
			DrawRectangle(bulletX, bulletY, 1, 1, BLACK);
			bulletX--;
		}
	}
	if (bulletY < destinationY) {
		while (bulletY < destinationY) {
			DrawRectangle(bulletX, bulletY, 1, 1, BLACK);
			bulletY++;
		}
	}
	if (bulletY > destinationY) {
		while (bulletY > destinationY) {
			DrawRectangle(bulletX, bulletY, 1, 1, BLACK);
			bulletY--;
		}
	}
	// Finding Distance between starting point and ending point
	if (startingX < destinationX) {
		distanceX = destinationX - startingX;
	}
	else {
		distanceX = startingX - destinationX;
	}

	if (startingY < destinationY) {
		distanceY = destinationY - startingY;
	}
	else {
		distanceY = startingY - destinationY;
	}

	// drawinf the pathfinding objects
	DrawCircle(startingX, startingY, 5, BLUE);
	DrawCircle(destinationX, destinationY, 5, RED);

	//drawing the distance
	DrawText(TextFormat("x: %i", distanceX), 10, 10, 50, WHITE);
	DrawText(TextFormat("Y: %i", distanceY), 10, 60, 50, WHITE);
}
