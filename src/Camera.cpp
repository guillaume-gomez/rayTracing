#include "Camera.h"

#include <math.h>
#include <limits>

#include <iostream>

Vector3 globalUp = Vector3(0.0f, 1.0f, 0.0f);

Camera::Camera(Vector3 _point, Vector3 _lookAt, float _fov)
: point(_point), lookAt(_lookAt), fov(_fov)
{

    right = Vector3::crossProduct(globalUp, eyeVector()).unitVector();
    up = Vector3::crossProduct(right, eyeVector()).unitVector();

    viewPlaneDist = 1.0f;
    viewPlaneHeight = 0.5f;
    viewPlaneWidth = 0.5f;
}

Camera::Camera(const Camera& original)
: point(original.point), lookAt(original.lookAt), fov(original.fov), up(original.up), viewPlaneDist(original.viewPlaneDist), viewPlaneHeight(original.viewPlaneHeight), viewPlaneWidth(original.viewPlaneWidth)
{
    right = Vector3::crossProduct(globalUp, eyeVector()).unitVector();
    up = Vector3::crossProduct(right, eyeVector()).unitVector();
}

Vector3 Camera::calcDirVec(float x, float y, int width, int height) {

    float xIndent = 0.f;
    float yIndent = 0.f;

    xIndent = viewPlaneWidth / (float) width;
    yIndent = viewPlaneHeight / (float) height;

    Vector3 raydir = (viewPlaneUpLeft + right * xIndent * x - up * yIndent * y) - point;
    return raydir.unitVector();

}

void Camera::computeViewPlane(float width, float height) {
    float fovRadians = M_PI * (fov / 2.0f) / 180.f;
    viewPlaneDist     = 1.0f;
    viewPlaneHeight   = tan(fovRadians) * 2.0f * viewPlaneDist;
    float ratio = width / height;
    viewPlaneWidth = viewPlaneHeight * ratio;

    viewPlaneUpLeft = point + ((eyeVector() * viewPlaneDist) + (up * (viewPlaneHeight / 2.0f)))- (right * ( viewPlaneWidth / 2.0f));

}

Camera& Camera::operator=(const Camera& source) {
    point = source.point;
    lookAt = source.lookAt;
    fov = source.fov;
    return *this;
}

void Camera::moveTo(const Vector3& newPosition) {
    point = newPosition;

}

void Camera::move(const Vector3& offset) {
    point += offset;
}

Vector3 Camera::eyeVector() {
    forward = lookAt - point;
    return forward.unitVector();
}

Camera::~Camera()
{
    //dtor
}
