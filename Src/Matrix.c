Matrix3D
Matrix3DNew(float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22)
{
    Matrix3D matrix = {};
    matrix.n[0][0] = n00; matrix.n[0][1] = n10; matrix.n[0][2] = n20;
    matrix.n[1][0] = n01; matrix.n[1][1] = n11; matrix.n[1][2] = n21;
    matrix.n[2][0] = n02; matrix.n[2][1] = n12; matrix.n[2][2] = n22;
    return matrix;
}

Matrix3D
Matrix3DNewFromVectors(const Vector3D *vecA, const Vector3D *vecB, const Vector3D *vecC)
{
    Matrix3D matrix = {};
    matrix.n[0][0] = vecA->x; matrix.n[0][1] = vecA->y; matrix.n[0][2] = vecA->z;
    matrix.n[1][0] = vecB->x; matrix.n[1][1] = vecB->y; matrix.n[1][2] = vecB->z;
    matrix.n[2][0] = vecC->x; matrix.n[2][1] = vecC->y; matrix.n[2][2] = vecC->z;
    return matrix;
}

const float *
MatrixGet(Matrix3D *matrix, int i, int j)
{
    return &matrix->n[j][i];
}

Vector3D *
MatrixGetVector(Matrix3D *matrix, int j)
{
    Vector3D *vec = NULL;
    vec = (Vector3D *)matrix->n[j];
    return vec;
}

Matrix3D
Matrix3DOperationNew(Matrix3D *m1, Operation operation, Matrix3D *m2)
{
    Vector3D vecA = Vec3OperationVectoralNew(MatrixGetVector(m1, 0), operation, MatrixGetVector(m2, 0));
    Vector3D vecB = Vec3OperationVectoralNew(MatrixGetVector(m1, 1), operation, MatrixGetVector(m2, 1));
    Vector3D vecC = Vec3OperationVectoralNew(MatrixGetVector(m1, 2), operation, MatrixGetVector(m2, 2));
    return Matrix3DNewFromVectors(&vecA, &vecB, &vecC);
}

void Matrix3DOperation(Matrix3D *m1, Operation operation, Matrix3D *m2)
{
    Vec3OperationVectoral(MatrixGetVector(m1, 0), operation, MatrixGetVector(m2, 0));
    Vec3OperationVectoral(MatrixGetVector(m1, 1), operation, MatrixGetVector(m2, 1));
    Vec3OperationVectoral(MatrixGetVector(m1, 2), operation, MatrixGetVector(m2, 2));
}

Matrix3D
Matrix3DOperationScalarNew(Matrix3D *m1, float scalar)
{
    Vector3D vecA = Vec3OperationScalarNew(MatrixGetVector(m1, 0), Mul, scalar);
    Vector3D vecB = Vec3OperationScalarNew(MatrixGetVector(m1, 1), Mul, scalar);
    Vector3D vecC = Vec3OperationScalarNew(MatrixGetVector(m1, 2), Mul, scalar);

    return Matrix3DNewFromVectors(&vecA, &vecB, &vecC);
}

void
Matrix3DOperationScalar(Matrix3D *m1, float scalar)
{
    Vec3OperationScalar(MatrixGetVector(m1, 0), Mul, scalar);
    Vec3OperationScalar(MatrixGetVector(m1, 1), Mul, scalar);
    Vec3OperationScalar(MatrixGetVector(m1, 2), Mul, scalar);
}

int
Matrix3DEquals(Matrix3D *m1, Matrix3D *m2)
{
    return Vec3Equals(MatrixGetVector(m1, 0), MatrixGetVector(m2, 0))
        && Vec3Equals(MatrixGetVector(m1, 1), MatrixGetVector(m2, 1))
        && Vec3Equals(MatrixGetVector(m1, 2), MatrixGetVector(m2, 2));
}