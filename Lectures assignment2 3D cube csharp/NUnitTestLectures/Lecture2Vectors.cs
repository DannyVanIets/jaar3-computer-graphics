using MatrixTransformations;
using NUnit.Framework;

namespace NUnitTestLectures
{
    public class Tests
    {
        [TestCase(0, 0)]
        [TestCase(5, 2)]
        [TestCase(10, 20)]
        [TestCase(-5, -10)]
        [TestCase(12, 30)]
        public void Test_Vector_Constructor(int x, int y)
        {
            // Arrange
            Vector v = new Vector(x, y);

            // Act
            

            // Assert
            Assert.AreEqual(x, v.x);
            Assert.AreEqual(y, v.y);
        }

        [TestCase(0, 0, 0, 0, 0, 0)]
        [TestCase(5, 5, 5, 5, 10, 10)]
        [TestCase(2, 3, 4, 5, 6, 8)]
        [TestCase(10, 5, 13, 7, 23, 12)]
        [TestCase(-8, -5, 9, 2, 1, -3)]
        public void Test_Vector_Plus(int x, int y, int secondX, int secondY, int expectedX, int expectedY)
        {
            // Arrange
            Vector v1 = new Vector(x, y);
            Vector v2 = new Vector(secondX, secondY);

            // Act
            Vector actual = v1 + v2;

            // Assert
            Assert.AreEqual(expectedX, actual.x);
            Assert.AreEqual(expectedY, actual.y);
        }

        [TestCase(0, 0, 0, 0, 0, 0)]
        [TestCase(5, 5, 5, 5, 0, 0)]
        [TestCase(23, 15, -30, 20, 53, -5)]
        [TestCase(100, 100, 50, 33, 50, 67)]
        public void Test_Vector_Minus(int x, int y, int secondX, int secondY, int expectedX, int expectedY)
        {
            // Arrange
            Vector v1 = new Vector(x, y);
            Vector v2 = new Vector(secondX, secondY);

            // Act
            Vector actual = v1 - v2;

            // Assert
            Assert.AreEqual(expectedX, actual.x);
            Assert.AreEqual(expectedY, actual.y);
        }

        [TestCase(0, 0, 0, 0, 0)]
        [TestCase(5, 5, 5, 25, 25)]
        [TestCase(22, 36, 8, 176, 288)]
        [TestCase(20, 54, 10, 200, 540)]
        [TestCase(13, 85, -6, -78, -510)]
        public void Test_Vector_Multiplied(int x, int y, int n, int expectedX, int expectedY)
        {
            // Arrange
            Vector v1 = new Vector(x, y);

            // Act
            Vector actual = v1 * n;

            // Assert
            Assert.AreEqual(expectedX, actual.x);
            Assert.AreEqual(expectedY, actual.y);
        }
    }
}