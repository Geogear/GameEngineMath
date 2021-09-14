#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    float x, y, z;
}Vector3D;

typedef enum
{
    Sum,
    Subs,
    Mul,
    Div,
    Negate,
    OperationCount
}Operation;

float Vec3GetMagnitude(Vector3D *vec3);
Vector3D Vec3NormalizeNew(Vector3D *vec3);
void Vec3Normalize(Vector3D *vec3);

Vector3D Vec3ScalarOperationNew(Vector3D *vec3, Operation operation, float scalar);
void Vec3ScalarOperation(Vector3D *vec3, Operation operation, float scalar);

Vector3D Vec3VectoralOperationNew(Vector3D *vecA, Operation operation, Vector3D *vecB);
void Vec3VectoralOperation(Vector3D *vecA, Operation operation, Vector3D *vecB);

#endif