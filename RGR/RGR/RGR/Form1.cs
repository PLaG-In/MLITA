using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics; 

namespace RGR
{
    public partial class Fractions : Form
    {
        public Fractions()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.textBox2.Text.Length == 0)
            {
                MessageBox.Show("Не введено имя файла",
                    "Ошибка");
                return;
            }

            if (!File.Exists(textBox2.Text)) //Если файл не существует
            {
                MessageBox.Show("Файл не ввода существует!");
                return;
            }
            StreamReader streamReader = new StreamReader(textBox2.Text);
            //textBox1.Text = File.ReadAllText(textBox2.Text);
            string str = ""; //Объявляем переменную, в которую будем записывать текст из файла
            while (!streamReader.EndOfStream) //Цикл длиться пока не будет достигнут конец файла
            {
                str += streamReader.ReadLine(); //В переменную str по строчно записываем содержимое файла
            }
            textBox1.Text = str;
            streamReader.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (this.textBox2.Text.Length == 0)
            {
                MessageBox.Show("Не введено имя файла",
                    "Ошибка");
                return;
            }
            if (!File.Exists(textBox2.Text)) //Если файл не существует
            {
                MessageBox.Show("Файл не ввода существует!");
                return;
            }
            Process.Start(@"Fractions.exe", textBox2.Text);//запуск процесса

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!File.Exists("output.txt")) //Если файл не существует
            {
                MessageBox.Show("Файл не вывода существует!Невозможно показать результат!");
                return;
            }
            StreamReader streamReader = new StreamReader("output.txt");
            string str = ""; //Объявляем переменную, в которую будем записывать текст из файла
            while (!streamReader.EndOfStream) //Цикл длиться пока не будет достигнут конец файла
            {
                str += streamReader.ReadLine() + " "; //В переменную str по строчно записываем содержимое файла
            }
            textBox1.Text = str;
            streamReader.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Требуется написать программу, которая выводит в порядке возрастания все несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают N.Ввод из файла INPUT.TXT. Входной файл содержит целое число N (2 ≤ N ≤ 1000).Вывод в файл OUTPUT.TXT. В выходной файл необходимо вывести все дроби по одной в каждой строке.", "Задача");
        }

    }   
}
