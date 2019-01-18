#include "Camera.h"

Camera::Camera(Vector3 _point, Vector3 _lookAt, float _fov)
: point(_point), lookAt(_lookAt), fov(_fov)
{
    viewPlaneDist     = 1.0f;
    viewPlaneHeight   = 0.35f;
    viewPlaneWidth    = 0.5f;


    Vector3 globalUp = (0.0f, 1.0f, 0.0f);
    right = globalUp * eyeVector();
    up = right * eyeVector();

    viewPlaneLeft = point + ((eyeVector() * viewPlaneDist) + (up * (viewPlaneHeight / 2.0f)))-(right * ( viewPlaneWidth / 2.0f));

}

Camera::Camera(const Camera& original)
: point(original.point), lookAt(original.lookAt), fov(original.fov), up(original.up)
{
}

Camera& Camera::operator=(const Camera& source) {
    point = source.point;
    lookAt = source.lookAt;
    fov = source.fov;
    return *this;
}

Vector3 Camera::eyeVector() {
    forward = lookAt - point;
    return forward.unitVector();
}

Camera::~Camera()
{
    //dtor
}
