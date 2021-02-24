using System;
using System.Text;

namespace MatrixTransformations
{
    public class Matrix
    {
        float[,] mat = new float[2, 2];

        public Matrix()
        {
            /* Create it like this:
             * [1,0]
             * [0,1]
             */
            mat[0, 0] = 1; mat[0, 1] = 0;
            mat[1, 0] = 0; mat[1, 1] = 1;
        }

        public Matrix(float m11, float m12,
                      float m21, float m22)
        {
            mat[0, 0] = m11; mat[0, 1] = m12;
            mat[1, 0] = m21; mat[1, 1] = m22;
        }

        public Matrix(Vector v)
        {

            mat[0, 0] = v.x;
            mat[1, 0] = v.y;
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            float[,] matrice = new float[2, 2];
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrice[i, j] = m1.mat[i, j] + m2.mat[i, j];
                }
            }
            Matrix matrix = new Matrix
            {
                mat = matrice
            };
            return matrix;
        }

        public static Matrix operator -(Matrix m1, Matrix m2)
        {
            float[,] matrice = new float[2, 2];
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrice[i, j] = m1.mat[i, j] - m2.mat[i, j];
                }
            }
            Matrix matrix = new Matrix
            {
                mat = matrice
            };
            return matrix;
        }

        public static Matrix operator *(Matrix m1, float f)
        {
            float[,] matrice = new float[2, 2];
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrice[i, j] = m1.mat[i, j] * f;
                }
            }
            Matrix matrix = new Matrix
            {
                mat = matrice
            };
            return matrix;
        }

        public static Matrix operator *(float f, Matrix m1)
        {
            float[,] matrice = new float[2, 2];
            for (int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    matrice[i, j] = m1.mat[i, j] * f;
                }
            }
            Matrix matrix = new Matrix
            {
                mat = matrice
            };
            return matrix;
        }

        public static Matrix operator *(Matrix m1, Matrix m2)
        {
            Matrix matrix = new Matrix(0, 0, 0, 0);
            int columns = m1.mat.GetLength(0);
            int rows = m1.mat.GetLength(1);

            for (int i = 0; i < columns; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    for(int n = 0; n < rows; n++)
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
                y = m3.mat[1, 0]
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
                x = mat[0,0],
                y = mat[1,0]
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

                    if(i != mat.GetLength(1) - 1 || j != mat.GetLength(1) - 1)
                    {
                        toString += ", ";
                    }
                }
            }
            return toString;
        }
    }
}
