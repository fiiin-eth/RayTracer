
#include "GCP_GFX_Framework.h"
#include "RayTracer.h"
#include "Camera.h"
#include "Sphere.h"



int main(int argc, char* argv[])
{
	// Set window size
	glm::ivec2 winSize(640, 480);

	// This will handle rendering to screen
	GCP_Framework _myFramework;
	RayTracer RT;
	Camera cam;

	Sphere* newSphere = new Sphere(glm::vec3(320.0f,240.0f,-80.0f), 10.0f );

	RT.Objects.push_back(newSphere);

	// Initialises SDL and OpenGL and sets up a framebuffer
	if (!_myFramework.Init(winSize))
	{
		return -1;
	}




	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = winSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 1
	glm::vec3 pixelColour(1, 0, 0);


	// Sets all pixels the same colour
    _myFramework.SetAllPixels( glm::vec3(0.1f,0.1f,0.3f) );

	// Draws a single pixel
	//_myFramework.DrawPixel(pixelPosition, pixelColour);

	glm::vec3 Intersect;

	for (int x = 0; x < 640; x++) {
		for (int y = 0; y < 480; y++) {

			pixelPosition = { x,y };
			Ray* ray = cam.GetRay(pixelPosition);
			for (int i = 0; i < RT.Objects.size(); i++) {
				if (RT.Objects[i]->RayIntersect(cam.GetRay(pixelPosition), Intersect)) {
					pixelColour = { 1, 0, 0 };
				}
				else {
					pixelColour = { 0, 0, 0 };
				}

			}
			_myFramework.DrawPixel(pixelPosition, pixelColour);
		}
	}


	// Pushes the framebuffer to OpenGL and renders to screen
	// Also contains an event loop that keeps the window going until it's closed
	_myFramework.ShowAndHold();
	return 0;


}
