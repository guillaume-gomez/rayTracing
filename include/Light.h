#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light(const Vector3 position);
        virtual ~Light();
    private:
        Vector3 position;
};

#endif // LIGHT_H
