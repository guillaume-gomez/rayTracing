#include "Camera.h"

#include <iostream>

Vector3 globalUp = Vector3(0.0f, 1.0f, 0.0f);

Camera::Camera(Vector3 _point, Vector3 _lookAt, float _fov)
: point(_point), lookAt(_lookAt), fov(_fov)
{
    viewPlaneDist     = 1.0f;
    viewPlaneHeight   = 0.35f;
    viewPlaneWidth    = 0.5f;

    right = Vector3::crossProduct(globalUp, eyeVector()).unitVector();
    up = Vector3::crossProduct(right, eyeVector()).unitVector();

    viewPlaneUpLeft = point + ((eyeVector() * viewPlaneDist) + (up * (viewPlaneHeight / 2.0f)))- (right * ( viewPlaneWidth / 2.0f));

}

Camera::Camera(const Camera& original)
: point(original.point), lookAt(original.lookAt), fov(original.fov), up(original.up), viewPlaneDist(original.viewPlaneDist), viewPlaneHeight(original.viewPlaneHeight), viewPlaneWidth(original.viewPlaneWidth)
{
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

    //TODO
    //  Vector3 eyeVector = camera.eyeVector();
    // Vector3 up = Vector3(0.0f, 1.0f, 0.0f);

    // Vector3 vpRight = (Vector3::crossProduct(eyeVector, up)).unitVector();
    // Vector3 vpUp = (Vector3::crossProduct(vpRight, eyeVector)).unitVector();

    // float fovRadians = M_PI * (camera.getFov() / 2.0f) / 180.f;
    // float heightWidthRatio = height / width;
    // float halfWidth = tan(fovRadians);
    // float halfHeight = heightWidthRatio * halfWidth;
    // float camerawidth = halfWidth * 2.0f;
    // float cameraheight = halfHeight * 2.0f;
    // float pixelWidth = camerawidth / (width - 1.0f);
    // float pixelHeight = cameraheight / (height - 1.0f);

    //  // turn the raw pixel `x` and `y` values into values from -1 to 1
    //         // and use these values to scale the facing-right and facing-up
    //         // vectors so that we generate versions of the `eyeVector` that are
    //         // skewed in each necessary direction.
    //         Vector3 xcomp = vpRight * ( (x * pixelWidth) - halfWidth);
    //         Vector3 ycomp = vpUp    * ( (y * pixelHeight) - halfHeight);


    //         Vector3 rayDirection = (eyeVector + xcomp + ycomp).unitVector();
           
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
