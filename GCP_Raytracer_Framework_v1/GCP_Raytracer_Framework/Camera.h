#pragma once

#include <GLM/glm.hpp>
#include "Ray.h"

class Camera {

	glm::mat4 ViewMat;

	Ray* GetRay(glm::ivec2 _WinPos);
};