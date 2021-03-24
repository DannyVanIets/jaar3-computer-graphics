using System;
using System.Text;

namespace MatrixTransformations
{
    public class Matrix
    {
        float[,] mat = new float[3, 3];

        public Matrix()
        {
            /* Create it like this:
             * [1,0]
             * [0,1]
             */
            mat = new Matrix(
                1, 0, 
                0, 1
            ).mat;
        }

        public Matrix(float m11, float m12,
                      float m21, float m22)
        {
            mat[0, 0] = m11; mat[0, 1] = m12; mat[0, 2] = 0;
            mat[1, 0] = m21; mat[1, 1] = m22; mat[1, 2] = 0;
            mat[2, 0] = 0;   mat[2, 1] = 0;   mat[2, 2] = 1;
        }

        public Matrix(Vector v)
        {
            mat[0, 0] = v.x;
            mat[1, 0] = v.y;
            mat[2, 0] = v.z;
        }

        public static Matrix ZeroMatrix()
        {
            Matrix matrix = new Matrix();
            matrix.mat[0, 0] = 0; matrix.mat[0, 1] = 0; matrix.mat[0, 2] = 0;
            matrix.mat[1, 0] = 0; matrix.mat[1, 1] = 0; matrix.mat[1, 2] = 0;
            matrix.mat[2, 0] = 0; matrix.mat[2, 1] = 0; matrix.mat[2, 2] = 0;
            return matrix;
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            Matrix matrix = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrix.mat[i, j] = m1.mat[i, j] + m2.mat[i, j];
                }
            }
            return matrix;
        }

        public static Matrix operator -(Matrix m1, Matrix m2)
        {
            Matrix matrix = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrix.mat[i, j] = m1.mat[i, j] - m2.mat[i, j];
                }
            }
            return matrix;
        }

        public static Matrix operator *(Matrix m1, float f)
        {
            Matrix matrix = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrix.mat[i, j] = m1.mat[i, j] * f;
                }
            }
            return matrix;
        }

        public static Matrix operator *(float f, Matrix m1)
        {
            Matrix matrix = new Matrix();
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrix.mat[i, j] = m1.mat[i, j] * f;
                }
            }
            return matrix;
        }

        public static Matrix operator *(Matrix m1, Matrix m2)
        {
            Matrix matrix = ZeroMatrix();
            int columns = m1.mat.GetLength(0);
            int rows = m1.mat.GetLength(1);

            for (int i = 0; i < columns; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    for (int n = 0; n < rows; n++)
                    {
                        matrix.mat[i, j] += m1.mat[i, n] * m2.mat[n, j];
                    }
                }
            }
            return matrix;
        }

        public static Vector operator *(Matrix m1, Vector v)
        {
            Matrix m2 = new Matrix(v);
            Matrix m3 = m1 * m2;
            Vector newVector = new Vector
            {
                x = m3.mat[0, 0],
                y = m3.mat[1, 0],
                z = m3.mat[2, 0]
            };
            return newVector;
        }

        public static Matrix Identity()
        {
            return new Matrix();
        }

        public Vector ToVector()
        {
            Vector vector = new Vector
            {
                x = mat[0, 0],
                y = mat[1, 0],
                z = mat[2, 0]
            };
            return vector;
        }

        public override string ToString()
        {
            string toString = "";
            for (int i = 0; i < mat.GetLength(0); i++)
            {
                for (int j = 0; j < mat.GetLength(1); j++)
                {
                    toString += mat[i, j];

                    if (i != mat.GetLength(1) - 1 || j != mat.GetLength(1) - 1)
                    {
                        toString += ", ";
                    }
                }
            }
            return toString;
        }

        // For lecture 3
        public static Matrix ScaleMatrix(float s)
        {
            Matrix m = new Matrix();
            m.mat[0, 0] = s;
            m.mat[1, 1] = s;
            return m;
        }

        public static Matrix RotateMatrix(float degrees)
        {
            // Turn degrees into radians, radians is used by cos and sin.
            double radians = degrees * Math.PI / 180;

            Matrix rotatedMatrix = new Matrix(
                (float)Math.Cos(radians), -(float)Math.Sin(radians),
                (float)Math.Sin(radians), (float)Math.Cos(radians)
            );
            return rotatedMatrix;
        }

        public static Matrix TranslateMatrix(Vector t)
        {
            Matrix matrix = new Matrix();

            matrix.mat[0,2] += t.x;
            matrix.mat[1,2] += t.y;
            matrix.mat[2,2] += t.z;

            return matrix;
        }
    }
}
