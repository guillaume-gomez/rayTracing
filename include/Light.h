#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light(const Vector3 position);
        virtual ~Light();
        Vector3 getPosition() const { return position; };
    private:
        Vector3 position;
};

#endif // LIGHT_H
