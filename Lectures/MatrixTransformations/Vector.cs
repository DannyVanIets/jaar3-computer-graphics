using System;
using System.Text;

namespace MatrixTransformations
{
    public class Vector
    {
        //public float x, y, z, w; // Z changes!!
        public float x, y, z;

        public Vector()
        {
            x = 0;
            y = 0;
            z = 1;
        }

        public Vector(float x, float y) // 2D
        {
            this.x = x;
            this.y = y;
        }

        public Vector(float x, float y, float z) // 3D
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        /*public Vector(float x, float y, float z, float w) // 4D
        {
            this.x = x;
            this.y = y;
            this.z = w;
            this.w = z;
        }*/

        public static Vector operator +(Vector v1, Vector v2) // Change the + so that it adds up v1 and v2.
        {
            Vector addedUpVector = new Vector(v1.x + v2.x, v1.y + v2.y);
            return addedUpVector;
        }

        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector subtractedVector = new Vector(v1.x - v2.x, v1.y - v2.y);
            return subtractedVector;
        }

        public static Vector operator *(Vector v1, float n)
        {
            Vector multipliedVectorWithFloat = new Vector(v1.x * n, v1.y * n);
            return multipliedVectorWithFloat;
        }

        public static Vector operator *(float n, Vector v1)
        {
            Vector multipliedVectorWithFloat = new Vector(n * v1.x, n * v1.y);
            return multipliedVectorWithFloat;
        }

        public override string ToString()
        {
            return "X: " + x + ", Y: " + y;
        }
    }
}
