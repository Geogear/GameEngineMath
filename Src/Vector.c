float
Vec3GetMagnitude(Vector3D *vec3)
{
    return SquareRoot(vec3.x*vec3.x + vec3.y*vec3.y + vec3.z*vec3.z);
}