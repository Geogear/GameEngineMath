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