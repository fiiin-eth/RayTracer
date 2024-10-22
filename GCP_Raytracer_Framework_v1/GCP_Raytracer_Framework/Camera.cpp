#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera::Camera() {
	uProjection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
}


Ray Camera::GetRay(glm::ivec2 _WinPos, glm::ivec2 _WinSize) {

	glm::vec4 NearPoint;
	glm::vec4 FarPoint;

	NearPoint.x = float(_WinPos.x) / float(_WinSize.x) * 2.0 - 1.0;
	NearPoint.y = float(_WinPos.y) / float(_WinSize.y) * 2.0 - 1.0;
	NearPoint.z = -1;
	NearPoint.w = 1;

	NearPoint = FarPoint;
	FarPoint.z = 1;

	NearView = glm::inverse(uProjection) * NearPoint;
	FarView = glm::inverse(uProjection) * FarPoint;


	Ray newRay;
	newRay.Origin = glm::vec3(NearPoint.x, NearPoint.y, -1);
	newRay.Direction = glm::vec3(0, 0, -1);
	
	std::cout << NearPoint.x << "," << NearPoint. y << "," << newRay.Origin.z << std::endl;

	return newRay;
}