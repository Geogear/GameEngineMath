#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    float x, y, z;
}Vector3D;

float Vec3GetMagnitude(Vector3D *vec3);

#endif