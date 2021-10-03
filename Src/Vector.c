float
Vec3GetMagnitude(Vector3D *vec3)
{
    return SquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
}

Vector3D
Vec3NormalizeNew(Vector3D *vec3)
{
    float reverseMagnitude = InverseSquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
    return Vec3OperationScalarNew(vec3, Mul, reverseMagnitude);
}

void
Vec3Normalize(Vector3D *vec3)
{
    float reverseMagnitude = InverseSquareRoot(vec3->x*vec3->x + vec3->y*vec3->y + vec3->z*vec3->z);
    Vec3OperationScalar(vec3, Mul, reverseMagnitude);
}

Vector3D
Vec3OperationScalarNew(Vector3D *vec3, Operation operation, float scalar)
{
    Vector3D result = {};
    switch (operation)
    {
        case Mul:
            result.x = vec3->x * scalar;
            result.y = vec3->y * scalar;
            result.z = vec3->z * scalar;
            break;
        case Div:
            result.x = vec3->x / scalar;
            result.y = vec3->y / scalar;
            result.z = vec3->z / scalar;
            break;
        case Negate:
            result.x = vec3->x * -1;
            result.y = vec3->y * -1;
            result.z = vec3->z * -1;
            break;        
        default:
            ErrorExit("Invalid operation in Vec3ScalarOperationNew.\n");
    }
    return result;
}

void
Vec3OperationScalar(Vector3D *vec3, Operation operation, float scalar)
{
    switch (operation)
    {
        case Mul:
            vec3->x *= scalar;
            vec3->y *= scalar;
            vec3->z *= scalar;
            break;
        case Div:
            vec3->x /= scalar;
            vec3->y /= scalar;
            vec3->z /= scalar;
            break;
        case Negate:
            vec3->x *= -1;
            vec3->y *= -1;
            vec3->z *= -1;
            break;        
        default:
            vec3 = NULL;
    }
}

Vector3D
Vec3OperationVectoralNew(Vector3D *vecA, Operation operation, Vector3D *vecB)
{
    Vector3D result = {};
    float sign = 0;

    switch (operation)
    {
        case Sum:
            sign = 1;
            break;
        case Subs:
            sign = -1;
            break; 
        default:
            ErrorExit("Invalid operation in Vec3VectoralOperationNew\n");
    }

    result.x = vecA->x + sign * vecB->x;
    result.y = vecA->y + sign * vecB->y;
    result.z = vecA->z + sign * vecB->z;

    return result;
}

void
Vec3OperationVectoral(Vector3D *vecA, Operation operation, Vector3D *vecB)
{
    float sign = 0;
    
    switch (operation)
    {
        case Sum:
            sign = 1;
            break;
        case Subs:
            sign = -1;
            break;
        default:
            vecA = NULL;
            return;
    }

    vecA->x += sign * vecB->x;
    vecA->y += sign * vecB->y;
    vecA->z += sign * vecB->z;

}

int
Vec3Equals(Vector3D *vecA, Vector3D *vecB)
{
    return (vecA->x == vecB->x && vecA->y == vecB->y && vecA->z && vecB->z);
}