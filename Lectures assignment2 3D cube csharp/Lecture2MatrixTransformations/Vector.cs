using System;
using System.Text;

namespace MatrixTransformations
{
    public class Vector
    {
        public float x, y;

        public Vector()
        {
            x = 0;
            y = 0;
        }

        public Vector(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public static Vector operator +(Vector v1, Vector v2)
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
