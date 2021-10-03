#ifndef MATRIX_H
#define MATRIX_H

/* Treating as if n[i] is the ith colum of the matrix */
typedef struct
{
    float n[3][3];
}Matrix3D;

Matrix3D Matrix3DNew(float n00, float n01, float n02,
                     float n10, float n11, float n12,
                     float n20, float n21, float n22);
Matrix3D Matrix3DNewFromVectors(const Vector3D *vecA, const Vector3D *vecB, const Vector3D *vecC);

const float * MatrixGet(Matrix3D *M, int i, int j);
Vector3D * MatrixGetVector(Matrix3D *M, int j);

Matrix3D Matrix3DOperationNew(Matrix3D *A, Operation operation, Matrix3D *B);
void Matrix3DOperation(Matrix3D *A, Operation operation, Matrix3D *B);

Matrix3D Matrix3DOperationScalarNew(Matrix3D *A, float scalar);
void Matrix3DOperationScalar(Matrix3D *A, float scalar);

int Matrix3DEquals(Matrix3D *A, Matrix3D *B);

Matrix3D Matrix3DMulMatrix(Matrix3D *A, Matrix3D *B);
Vector3D Matrix3DMulVector(Matrix3D *M, Vector3D *v);

#endif