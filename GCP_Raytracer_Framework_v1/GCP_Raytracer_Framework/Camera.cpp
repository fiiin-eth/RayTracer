#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera::Camera() {
	uProjection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);


	glm::vec3 cameraPos(0.0f, 0.0f, 10.0f);
	glm::vec3 target(0.0f, 0.0f, 0.0f);
	glm::vec3 up(0.0f, 1.0f, 0.0f);

	uView = glm::lookAt(cameraPos, target, up);
}


Ray Camera::GetRay(glm::ivec2 _WinPos, glm::ivec2 _WinSize) {

	glm::vec4 NearPoint;
	glm::vec4 FarPoint;

	NearPoint.x = float(_WinPos.x) / float(_WinSize.x) * 2.0 - 1.0;
	NearPoint.y = float(_WinPos.y) / float(_WinSize.y) * 2.0 - 1.0;

	NearPoint.z = -1;
	NearPoint.w = 1;

	FarPoint = NearPoint;
	FarPoint.z = 1;

	NearView = glm::inverse(uProjection) * NearPoint;
	FarView = glm::inverse(uProjection) * FarPoint;

	NearView = glm::inverse(uView) * NearView;
	FarView = glm::inverse(uView) * FarView;

	NearView = NearView / NearView.w; // got rid of the code above uView inverse
	FarView = FarView / FarView.w;


	Ray newRay;
	newRay.Origin = glm::vec3(NearView);
	newRay.Direction = glm::normalize(glm::vec3(FarView - NearView));

	//std::cout << NearPoint.x << "," << NearPoint. y << "," << newRay.Origin.z << std::endl;

	return newRay;
}