using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Threading;

namespace MazeofMinotaur
{
    class GEngine
    {
        /*--------------members--------------*/
        private Graphics m_drawHandle;
        private Thread m_renderThread;

        private Bitmap tex_shadow;
        private Bitmap tex_dirt;

        /*-------------functions-------------*/
        public GEngine(Graphics g)
        {
            m_drawHandle = g;
        }
        public void Init()
        {
            LoadAssets();

            //Starts the render thread
            m_renderThread = new Thread(new ThreadStart(Render));
            m_renderThread.Start();
        }

        //Load resorces
        private void LoadAssets()
        {
            tex_shadow = MazeofMinotaur.Properties.Resources.little_shadow;
            tex_dirt = MazeofMinotaur.Properties.Resources.tex_dirt;
        }

        public void Stop()
        {
            m_renderThread.Abort();
        }
        private void Render()
        {
            int framesRendered = 0;
            long startTime = Environment.TickCount;

            Bitmap frame = new Bitmap(Game.CANVAS_WIDTH, Game.CANVAS_HEIGHT);
            Graphics frameGraphics = Graphics.FromImage(frame);

            TextureID[,] textures = Level.Blocks;

            while (true)
            {
                //Background color
                //frameGraphics.FillRectangle(new SolidBrush(Color.Black), 0, 0, Game.CANVAS_WIDTH, Game.CANVAS_HEIGHT);

                for(int x = 0; x < Game.LEVEL_WIDTH; x++)
                {
                    for(int y = 0; y < Game.LEVEL_HEIGTH; y++)
                    {
                        switch(textures[x, y])
                        {
                            case TextureID.air:
                                break;
                            case TextureID.dirt:
                                frameGraphics.FillRectangle(new SolidBrush(Color.Black), 0, 0, 50, 25);
                                frameGraphics.DrawImage(tex_dirt, 0, 0, 46, 50);
                                break;
                        }
                    }
                }
                //Draw my frame
                frameGraphics.DrawImage(tex_shadow, 50, 50);

                m_drawHandle.DrawImage(frame, 0, 0);

                framesRendered++;
                if (Environment.TickCount >= startTime + 1000)
                {
                    Console.WriteLine("GEngine: " + framesRendered + " " + "fps");
                    framesRendered = 0;
                    startTime = Environment.TickCount;
                }
            }
        }
    }
}
