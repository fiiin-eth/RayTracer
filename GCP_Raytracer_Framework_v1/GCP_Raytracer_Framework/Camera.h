#pragma once

#include <GLM/glm.hpp>
#include "Ray.h"

class Camera {

public:

	Camera();

	Ray GetRay(glm::ivec2 _WinPos, glm::ivec2 _WinSize);

private:
	glm::mat4 ViewMat;
	glm::mat4 uProjection;
	glm::vec4 NearView;
	glm::vec4 FarView;
};