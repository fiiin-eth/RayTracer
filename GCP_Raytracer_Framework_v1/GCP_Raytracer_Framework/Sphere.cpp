#include "Sphere.h"
#include "Ray.h"


Sphere::Sphere(glm::vec3 Position, float Radius) : Position(Position), Radius(Radius) {

}

bool Sphere::RayIntersect(Ray* _ray, glm::vec3& Intersect_) {

	glm::vec3 a = _ray->Origin;
	glm::vec3 n = _ray->Direction;
	glm::vec3 ClosestIntersection;

	float d;
	float x;

	if (glm::distance(a, Position) <= Radius)
	{
		return false;
	}

	d = glm::length(Position - a - (glm::dot(Position - a, n) * n));

	x = glm::sqrt((Radius * Radius) - (d * d));

	ClosestIntersection = a + ((glm::dot(Position - a, n) - x) * n);

	if (d > Radius) {
		return false;
	}

	if(glm::dot(n, ClosestIntersection - a) < 0.0f){
		return false;
	}
	else {
		Intersect_ = ClosestIntersection;
		return true;
	}

}

glm::vec3 Sphere::Shade(glm::vec3 _Intersect) {
	return glm::vec3();

}

glm::vec3 Sphere::GetNormal() { 
	return glm::vec3();


}