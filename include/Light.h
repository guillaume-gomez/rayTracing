#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light(const Vector3 position, const Vector3 color = Vector3(255.f, 255.f, 255.f));
        virtual ~Light();
        Vector3 getPosition() const { return position; };
        Vector3 getColor() const { return color; };
    private:
        Vector3 position;
        Vector3 color;
};

#endif // LIGHT_H
