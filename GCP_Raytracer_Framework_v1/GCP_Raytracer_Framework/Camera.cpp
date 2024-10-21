#include "Camera.h"

Ray Camera::GetRay(glm::ivec2 _WinPos) {

	Ray newRay;
	newRay.Origin = glm::vec3(_WinPos, 0);
	newRay.Direction = glm::vec3(0, 0, -1);

	return newRay;
}