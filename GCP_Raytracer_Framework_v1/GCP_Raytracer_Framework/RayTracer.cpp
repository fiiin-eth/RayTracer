#include "RayTracer.h"

glm::vec3 RayTracer::TraceRay(Ray _ray) {

	for (int i = 0; i < Objects.size(); i++) {
		glm::vec3 Intersect;
		if (Objects[i]->RayIntersect(_ray, Intersect)) {
			return Objects[i]->Shade(Intersect);
		}

	}
	return glm::vec3(0.0f, 0.3f, 0.2f);
}


RayTracer::RayTracer()
{
}

RayTracer::~RayTracer()
{
}