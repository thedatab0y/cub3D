#include <stdio.h>

#define WORLD_WIDTH 10
#define WORLD_HEIGHT 10

float playerX = 5.0f, playerY = 5.0f;
float playerDirX = -1.0f, playerDirY = 0.0f;

int worldMap [WORLD_HEIGHT][WORLD_WIDTH] = {

};

void castRay(float rayPosXm, float rayPosY, float rayDirX, float rayDirY) {

}

void update()
{

}

void draw()
{

}

int main()
{
	while (1){
		update();
		draw();
	}
	return 0;
}