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

	glm::vec3 W = glm::vec3(0.5f, 0.5, 0.0f);

	glm::vec3 L = glm::dot(W, GetNormal(_Intersect)) * Colour;

	if (glm::dot(W, GetNormal(_Intersect)) >= 0) {

	}


	return L;

}

glm::vec3 Sphere::GetNormal(glm::vec3 _Intersect) {

	return glm::normalize(_Intersect - Position);
}