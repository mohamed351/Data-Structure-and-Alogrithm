using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_Arrays
{
    public class MyArrayList<T>
    {
        int _index;
        int _size;
        T[] _array;
        public MyArrayList(int capacity)
        {
            _array = new T[capacity];
            _size = capacity;
            _index = 0;
            
        }
        private void ResizeArrayIfNessary()
        {
            if (_index == _size)
            {
                var newArray = new T[_size * 2];
                _size *= 2;
                for (int i = 0; i < _array.Length; i++)
                {
                    newArray[i] = _array[i];
                }
                _array = newArray;

            }
        }
    

        public void Append(T item)
        {
            ResizeArrayIfNessary();
           _array[_index] = item;
            _index++;
        }

        public void Insert(T element , int index)
        {
            //Resize the Array if Nessary
            if(index < 0 || index > _size)
            {
                throw new Exception("The Index out of boundry");
            }
            ResizeArrayIfNessary();
            for (int i = _index; i > index; i--)
            {
                _array[i] = _array[i - 1];
            }
            _array[index] = element;


        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("[");
            int i;
            for (i=0; i < _index -1; i++)
            {
                stringBuilder.Append(_array[i]);
                stringBuilder.Append(",");

            }
            stringBuilder.Append(_array[i]);
            stringBuilder.Append("]");
            return stringBuilder.ToString();
        }



    }
}
