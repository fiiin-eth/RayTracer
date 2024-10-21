#pragma once

#include <GLM/glm.hpp>
#include "Ray.h"

class Sphere {

public:
	Sphere(glm::vec3 Position, float Radius, glm::vec3 Colour);


	bool RayIntersect(Ray _ray, glm::vec3& Intersect_);

	glm::vec3 Shade(glm::vec3 _Intersect);

	glm::vec3 GetNormal(glm::vec3 _Intersect);

private:
	glm::vec3 Position;
	glm::vec3 Colour;
	float Radius;

};

