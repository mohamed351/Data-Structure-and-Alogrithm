using System.Collections;

namespace _1_Arrays
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MyArrayList<int> list = new MyArrayList<int>(5);
            list.Append(10);
            list.Append(20);
            list.Append(30);
            list.Append(40);
            list.Append(50);
            list.Append(60);
            list.Append(70);


            list.Insert(100, 1);


            Console.Write(list.ToString());
        }
    }
}
