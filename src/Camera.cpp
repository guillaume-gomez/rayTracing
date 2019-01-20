#include "Camera.h"

#include <iostream>

Camera::Camera(Vector3 _point, Vector3 _lookAt, float _fov)
: point(_point), lookAt(_lookAt), fov(_fov)
{
    viewPlaneDist     = 1.0f;
    viewPlaneHeight   = 0.5f;
    viewPlaneWidth    = 0.5f;


    Vector3 globalUp = (0.0f, 1.0f, 0.0f);
    right = Vector3::crossProduct(globalUp, eyeVector()).unitVector();
    up = Vector3::crossProduct(right, eyeVector()).unitVector();

    viewPlaneUpLeft = point + ((eyeVector() * viewPlaneDist) + (up * (viewPlaneHeight / 2.0f)))- (right * ( viewPlaneWidth / 2.0f));

}

Camera::Camera(const Camera& original)
: point(original.point), lookAt(original.lookAt), fov(original.fov), up(original.up)
{
    viewPlaneDist     = 1.0f;
    viewPlaneHeight   = 0.35f;
    viewPlaneWidth    = 0.5f;

    Vector3 globalUp = Vector3(0.0f, 1.0f, 0.0f);
    right = Vector3::crossProduct(globalUp, eyeVector()).unitVector();
    up = Vector3::crossProduct(right, eyeVector()).unitVector();

    viewPlaneUpLeft = point + ((eyeVector() * viewPlaneDist) + (up * (viewPlaneHeight / 2.0f)))- (right * ( viewPlaneWidth / 2.0f));

}

Vector3 Camera::calcDirVec(float x, float y, int xRes, int yRes) {

    float xIndent = 0.f;
    float yIndent = 0.f;

    xIndent = viewPlaneWidth / (float) xRes;
    yIndent = viewPlaneHeight / (float) yRes;

    Vector3 raydir = (viewPlaneUpLeft + right * xIndent * x - up * yIndent * y) - point;
    return raydir.unitVector();
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
