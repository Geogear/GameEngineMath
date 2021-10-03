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
MatrixGet(Matrix3D *M, int i, int j)
{
    return &M->n[j][i];
}

Vector3D *
MatrixGetVector(Matrix3D *M, int j)
{
    Vector3D *vec = NULL;
    vec = (Vector3D *)M->n[j];
    return vec;
}

Matrix3D
Matrix3DOperationNew(Matrix3D *A, Operation operation, Matrix3D *B)
{
    Vector3D vecA = Vec3OperationVectoralNew(MatrixGetVector(A, 0), operation, MatrixGetVector(B, 0));
    Vector3D vecB = Vec3OperationVectoralNew(MatrixGetVector(A, 1), operation, MatrixGetVector(B, 1));
    Vector3D vecC = Vec3OperationVectoralNew(MatrixGetVector(A, 2), operation, MatrixGetVector(B, 2));
    return Matrix3DNewFromVectors(&vecA, &vecB, &vecC);
}

void Matrix3DOperation(Matrix3D *A, Operation operation, Matrix3D *B)
{
    Vec3OperationVectoral(MatrixGetVector(A, 0), operation, MatrixGetVector(B, 0));
    Vec3OperationVectoral(MatrixGetVector(A, 1), operation, MatrixGetVector(B, 1));
    Vec3OperationVectoral(MatrixGetVector(A, 2), operation, MatrixGetVector(B, 2));
}

Matrix3D
Matrix3DOperationScalarNew(Matrix3D *A, float scalar)
{
    Vector3D vecA = Vec3OperationScalarNew(MatrixGetVector(A, 0), Mul, scalar);
    Vector3D vecB = Vec3OperationScalarNew(MatrixGetVector(A, 1), Mul, scalar);
    Vector3D vecC = Vec3OperationScalarNew(MatrixGetVector(A, 2), Mul, scalar);

    return Matrix3DNewFromVectors(&vecA, &vecB, &vecC);
}

void
Matrix3DOperationScalar(Matrix3D *A, float scalar)
{
    Vec3OperationScalar(MatrixGetVector(A, 0), Mul, scalar);
    Vec3OperationScalar(MatrixGetVector(A, 1), Mul, scalar);
    Vec3OperationScalar(MatrixGetVector(A, 2), Mul, scalar);
}

int
Matrix3DEquals(Matrix3D *A, Matrix3D *B)
{
    return Vec3Equals(MatrixGetVector(A, 0), MatrixGetVector(B, 0))
        && Vec3Equals(MatrixGetVector(A, 1), MatrixGetVector(B, 1))
        && Vec3Equals(MatrixGetVector(A, 2), MatrixGetVector(B, 2));
}

Matrix3D
Matrix3DMulMatrix(Matrix3D *A, Matrix3D *B)
{
    return (Matrix3DNew(B->n[0][0] * A->n[0][0] + B->n[0][1] * A->n[1][0] + B->n[0][2] * A->n[2][0],
                    B->n[0][0] * A->n[0][1] + B->n[0][1] * A->n[1][1] + B->n[0][2] * A->n[2][1],
                    B->n[0][0] * A->n[0][2] + B->n[0][1] * A->n[1][2] + B->n[0][2] * A->n[2][2],
                    B->n[1][0] * A->n[0][0] + B->n[1][1] * A->n[1][0] + B->n[1][2] * A->n[2][0],
                    B->n[1][0] * A->n[0][1] + B->n[1][1] * A->n[1][1] + B->n[1][2] * A->n[2][1],
                    B->n[1][0] * A->n[0][2] + B->n[1][1] * A->n[1][2] + B->n[1][2] * A->n[2][2],
                    B->n[2][0] * A->n[0][0] + B->n[2][1] * A->n[1][0] + B->n[2][2] * A->n[2][0],
                    B->n[2][0] * A->n[0][1] + B->n[2][1] * A->n[1][1] + B->n[2][2] * A->n[2][1],
                    B->n[2][0] * A->n[0][2] + B->n[2][1] * A->n[1][2] + B->n[2][2] * A->n[2][2]));
}

Vector3D
Matrix3DMulVector(Matrix3D *M, Vector3D *v)
{
    Vector3D vec = {.x = M->n[0][0] * v->x + M->n[1][0] * v->y + M->n[2][0] * v->z,
                    .y = M->n[0][1] * v->x + M->n[1][1] * v->y + M->n[2][1] * v->z,
                    .z = M->n[0][2] * v->x + M->n[1][2] * v->y + M->n[2][2] * v->z};
    return vec;
}