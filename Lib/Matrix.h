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

const float * MatrixGet(Matrix3D *matrix,int i, int j);
Vector3D * MatrixGetVector(Matrix3D *matrix, int j);

Matrix3D Matrix3DOperationNew(Matrix3D *m1, Operation operation, Matrix3D *m2);
void Matrix3DOperation(Matrix3D *m1, Operation operation, Matrix3D *m2);

Matrix3D Matrix3DOperationScalarNew(Matrix3D *m1, float scalar);
void Matrix3DOperationScalar(Matrix3D *m1, float scalar);

#endif