#pragma once

#include <GLM/glm.hpp>
#include "Ray.h"

class Camera {

public:
	Ray* GetRay(glm::ivec2 _WinPos);

private:
	glm::mat4 ViewMat;
};