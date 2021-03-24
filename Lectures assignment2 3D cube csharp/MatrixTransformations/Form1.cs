using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace MatrixTransformations
{
    public partial class Form1 : Form
    {
        // Axes
        AxisX x_axis;
        AxisY y_axis;

        // Objects
        Square square;

        // Window dimensions
        const int WIDTH = 800;
        const int HEIGHT = 600;

        public Form1()
        {
            InitializeComponent();

            this.Width = WIDTH;
            this.Height = HEIGHT;
            this.DoubleBuffered = true;

            Vector v1 = new Vector();
            Console.WriteLine(v1); // X: 0, Y: 0
            Vector v2 = new Vector(1, 2);
            Console.WriteLine(v2); // X: 1, Y: 2
            Vector v3 = new Vector(2, 6);
            Console.WriteLine(v3); // X: 2, Y: 6
            Vector v4 = v2 + v3;
            Console.WriteLine(v4); // X: 3, Y: 8
            Console.WriteLine();

            Matrix m1 = new Matrix();
            Console.WriteLine(m1); // 1, 0, 0, 1
            Matrix m2 = new Matrix(
                2, 4,
                -1, 3);
            Console.WriteLine(m2); // 2, 4, -1, 3
            Console.WriteLine(m1 + m2); // 3, 4, -1, 4
            Console.WriteLine(m1 - m2); // -1, -4, 1, -2
            Console.WriteLine(m2 * m2); // 0, 20, -5, 5

            Matrix m3 = new Matrix(v1);
            Console.WriteLine(m3); // 0, 0, 0, 0

            Console.WriteLine(m2 * v3); // 28, 16

            // Define axes
            x_axis = new AxisX(200);
            y_axis = new AxisY(200);

            // Create object
            square = new Square(Color.Purple, 100);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            List<Vector> vb;

            // Draw axes
            vb = ViewportTransformation(x_axis.vb);
            x_axis.Draw(e.Graphics, vb);
            vb = ViewportTransformation(y_axis.vb);
            y_axis.Draw(e.Graphics, vb);

            // Draw square
            vb = ViewportTransformation(square.vb);
            square.Draw(e.Graphics, vb);

            // Draw scaled square.
            square = new Square(Color.Cyan);
            Matrix scaledMatrix = Matrix.ScaleMatrix(1.5f);
            List<Vector> scaledVectors = new List<Vector>();

            foreach(Vector v in square.vb)
            {
                scaledVectors.Add(scaledMatrix * v);
            }

            vb = ViewportTransformation(scaledVectors);
            square.Draw(e.Graphics, vb);

            // Draw rotated square.
            square = new Square(Color.Orange);
            Matrix rotateMatrix = Matrix.RotateMatrix(20);
            List<Vector> rotateVectors = new List<Vector>();

            foreach (Vector v in square.vb)
            {
                rotateVectors.Add(rotateMatrix * v);
            }

            vb = ViewportTransformation(rotateVectors);
            square.Draw(e.Graphics, vb);

            // Draw translation square.
            square = new Square(Color.DarkBlue);
            Matrix translateMatrix = Matrix.TranslateMatrix(new Vector(75, -25));
            List<Vector> translateVectors = new List<Vector>();

            foreach (Vector v in square.vb) // Turn these foreaches into a function, saves a lot of code.
            {
                translateVectors.Add(translateMatrix * v);
            }

            vb = ViewportTransformation(translateVectors);
            square.Draw(e.Graphics, vb);
        }

        public static List<Vector> ViewportTransformation(List<Vector> vb)
        {
            List<Vector> result = new List<Vector>();

            float delta_x = WIDTH / 2;
            float delta_y = HEIGHT / 2;

            foreach(Vector v in vb)
            {
                Vector v2 = new Vector(v.x + delta_x, delta_y - v.y);
                result.Add(v2);
            }
            return result;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                Application.Exit();
        }
    }
}