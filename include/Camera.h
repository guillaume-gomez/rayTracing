#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
    public:
        Camera(Vector3 point = Vector3(), Vector3 direction = Vector3(), float fov = 45.0f);
        Camera(const Camera& copy);
        Camera& operator=(const Camera& source);
        virtual ~Camera();
        Vector3 eyeVector();
        float getFov() const { return fov; };
        const Vector3& getPoint() const { return point; };
        const Vector3& getDirection() const { return direction; };
        const Vector3& getForward() const { return forward; };
        const Vector3& getUp() const { return up; };
        const Vector3& getRight() const { return right; };
     private:
        Vector3 point;
        Vector3 direction;
        Vector3 forward;
        Vector3 up;
        Vector3 right;
        float fov;
};

#endif // CAMERA_H
