float
Vec3GetMagnitude(Vector3D *vec3)
{
    return SquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
}

Vector3D
Vec3NormalizeNew(Vector3D *vec3)
{
    Vector3D normalized = {};
    float reverseMagnitude = InverseSquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
    Vec3ScalarOperation(&normalized, Operation.Mul, reverseMagnitude);
    return normalized;
}

void
Vec3Normalize(Vector3D *vec3)
{
    float reverseMagnitude = InverseSquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
    Vec3ScalarOperation(vec3, Operation.Mul, reverseMagnitude);
}

Vector3D
Vec3ScalarOperationNew(Vector3D *vec3, Operation operation, float scalar)
{
    Vector3D operated = {};
    switch (operation)
    {
        case Operation.Mul:
            operated.x = vec3->x * scalar;
            operated.y = vec3->y * scalar;
            operated.z = vec3->z * scalar;
            break;
        case Operation.Div:
            operated.x = vec3->x / scalar;
            operated.y = vec3->y / scalar;
            operated.z = vec3->z / scalar;
            break;
        case Operation.Negate:
            operated.x = vec3->x * -1;
            operated.y = vec3->y * -1;
            operated.z = vec3->z * -1;
            break;        
        default:
            return NULL;
    }
    return operated;
}

void
Vec3ScalarOperation(Vector3D *vec3, Operation operation, float scalar)
{
    switch (operation)
    {
        case Operation.Mul:
            vec3->x *= scalar;
            vec3->y *= scalar;
            vec3->z *= scalar;
            break;
        case Operation.Div:
            vec3->x /= scalar;
            vec3->y /= scalar;
            vec3->z /= scalar;
            break;
        case Operation.Negate:
            vec3->x *= -1;
            vec3->y *= -1;
            vec3->z *= -1;
            break;        
        default:
            vec3 = NULL;
    }
}