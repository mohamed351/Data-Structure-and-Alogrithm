public class ArrayList {
   private int[] array;
    private int count;
    public ArrayList(int length){
        array = new int[length];
        count = 0;
    }

    private void ResizeItIfNessary(){
        if(array.length == count){
            var newArray = new int[count *2];
            for(int i=0;i< count;i++){
                newArray[i] = array[i];
            }
            array = newArray;
        }
    }
    public void Append(int item){
        ResizeItIfNessary();
        array[count] = item ;
        count++;
    }
    public void Insert(int element , int index){

        if(index < 0 || index >= count){
            throw new IndexOutOfBoundsException();
        }
        ResizeItIfNessary();
        for(int i = array.length -1 ; i > index;i--){
            array[i] = array[i-1];

        }
        array[index] = element;
        count++;
    }

    public void RemoveAt(int index){
        if(index < 0 ||  index >= count){
            throw  new IndexOutOfBoundsException();
        }
        for(int i= index; i < count ;i++){
            array[i] = array[i+1];
        }
        count--;
    }


    public void Print(){
        for(int i=0;i< count;i++){
            System.out.println(array[i]);
        }
    }

}
