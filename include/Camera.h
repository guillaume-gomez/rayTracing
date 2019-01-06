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
    private:
        Vector3 point;
        Vector3 direction;
        float fov;
};

#endif // CAMERA_H
