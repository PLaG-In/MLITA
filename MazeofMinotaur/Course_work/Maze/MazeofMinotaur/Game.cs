using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace MazeofMinotaur
{
    class Game
    {
        //Constans
        public const int CANVAS_HEIGHT = 700;
        public const int CANVAS_WIDTH = 1200;
        public const int LEVEL_WIDTH = 24;
        public const int LEVEL_HEIGTH = 14;
        public const int TILE_SIDE_LENGTH = 50;

        //members
        private GEngine gEngine;

        //Load level
        public void LoadLevel()
        {
            Level.InitLevel();
        }
        public void StartGraphics(Graphics g)
        {
            gEngine = new GEngine(g);
            gEngine.Init();
        }

        public void StopGame()
        {
            gEngine.Stop();
        }
    }

    public enum TextureID
    {
        air,
        dirt
    }
}
