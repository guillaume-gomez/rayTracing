#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
    public:
        Camera();
        virtual ~Camera();
    private:
        Vector3 point;
        Vector3 direction;
        float fov;
};

#endif // CAMERA_H
