#include "Camera.h"

Camera::Camera(Vector3 _point, Vector3 _direction, float _fov)
: point(_point), direction(_direction), fov(_fov)
{
    //ctor
}

Camera::Camera(const Camera& original)
: point(original.point), direction(original.direction), fov(original.fov)
{

}

Camera& Camera::operator=(const Camera& source) {
    point = source.point;
    direction = source.direction;
    fov = source.fov;
    return *this;
}

Vector3 Camera::eyeVector() {
    Vector3 vec = direction - point;
    return vec.unitVector();
}

Camera::~Camera()
{
    //dtor
}
