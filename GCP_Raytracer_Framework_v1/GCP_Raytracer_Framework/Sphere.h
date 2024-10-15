#pragma once

#include <GLM/glm.hpp>
#include "Ray.h"

class Sphere {

	Sphere();
	~Sphere();

	glm::vec3 Position;
	glm::vec3 Colour;

	bool RayIntersect(Ray _ray, glm::vec3& Intersect_);

	glm::vec3 Shade(glm::vec3 _Intersect);

	glm::vec3 GetNormal();
};

