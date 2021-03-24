using System;
using System.Text;

namespace MatrixTransformations
{
    public class Vector
    {
        public float x, y, z, w; // Z changes everytime!

        public Vector()
        {
            x = 0;
            y = 0;
            z = 1;
        }

        public Vector(float x, float y, float z = 1)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public static Vector operator +(Vector v1, Vector v2) // Change the + so that it adds up v1 and v2.
        {
            Vector addedUpVector = new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
            return addedUpVector;
        }

        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector subtractedVector = new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
            return subtractedVector;
        }

        public static Vector operator *(Vector v1, float n)
        {
            Vector multipliedVectorWithFloat = new Vector(v1.x * n, v1.y * n, v1.z * n);
            return multipliedVectorWithFloat;
        }

        public static Vector operator *(float n, Vector v1)
        {
            Vector multipliedVectorWithFloat = new Vector(n * v1.x, n * v1.y, n * v1.z);
            return multipliedVectorWithFloat;
        }

        public override string ToString()
        {
            return "X: " + x + ", Y: " + y + ", Z: " + z;
        }
    }
}
