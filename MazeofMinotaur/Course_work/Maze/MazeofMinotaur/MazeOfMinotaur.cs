using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace MazeofMinotaur
{
    public partial class MazeOfMinotaur : Form
    {
        private Game game = new Game();
        public MazeOfMinotaur()
        {
            InitializeComponent();
            KeyDown += new KeyEventHandler(MazeOfMinotaur_KeyDown);
            Paint += new PaintEventHandler(canvasPaint);
        }


        private void canvasPaint(object sender, PaintEventArgs e)
        {
            game.LoadLevel();
            Graphics g = canvas.CreateGraphics();
            e.Graphics.DrawEllipse(pen, rect);
            game.StartGraphics(g);
        }

        private void MazeOfMinotaur_FormClosing(object sender, FormClosingEventArgs e)
        {
            game.StopGame();
        }

        private void MazeOfMinotaur_Load(object sender, EventArgs e)
        {
            AllocConsole();
        }

        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAsAttribute(UnmanagedType.Bool)]
        static extern bool AllocConsole();

        Rectangle rect = new Rectangle(0, 0, 100, 100);
        Pen pen = new Pen(Color.Green);

        private void MazeOfMinotaur_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left)
                rect.Location = new Point(rect.Left - 10, rect.Top);
            if (e.KeyCode == Keys.Right)
                rect.Location = new Point(rect.Left + 10, rect.Top);
            if (e.KeyCode == Keys.Up)
                rect.Location = new Point(rect.Left, rect.Top - 10);
            if (e.KeyCode == Keys.Down)
                rect.Location = new Point(rect.Left, rect.Top + 10);


            Refresh();
        }


        public PaintEventHandler Form1_Paint { get; set; }
    }

}
