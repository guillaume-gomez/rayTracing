#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
    public:
        Camera(Vector3 point = Vector3(), Vector3 lookAt = Vector3(), float fov = 45.0f);
        Camera(const Camera& copy);
        Camera& operator=(const Camera& source);
        virtual ~Camera();
        Vector3 eyeVector();
        float getFov() const { return fov; };
        const Vector3& getPoint() const { return point; };
        const Vector3& getLookAt() const { return lookAt; };
        const Vector3& getForward() const { return forward; };
        const Vector3& getUp() const { return up; };
        const Vector3& getRight() const { return right; };
     private:
        Vector3 point;
        Vector3 lookAt;
        Vector3 up;
        Vector3 right;
        Vector3 viewPlaneLeft;
        float fov;
        float viewPlaneWidth;
        float viewPlaneHeight;
        float viewPlaneDist;
        Vector3 forward;
};

#endif // CAMERA_H
