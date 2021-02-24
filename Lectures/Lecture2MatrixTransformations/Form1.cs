﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace MatrixTransformations
{
    public partial class Form1 : Form
    {
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
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                Application.Exit();
        }
    }
}
