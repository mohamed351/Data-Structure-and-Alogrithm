import java.util.Arrays;
import java.util.LinkedList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        //linked list in java
//        LinkedList list = new LinkedList();
//        list.addLast(20);
//        list.addLast(30);
//        list.addLast(40);
//        list.addFirst(10);
//        System.out.println(list.size());
//        System.out.println(list.indexOf(10));
//        System.out.println(list);

        //Building Linked List from Scratch
        MyLinkedList list = new MyLinkedList();
        list.addFirst(5);
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        System.out.println("Index of 4 :"+list.indexOf(4));
        System.out.println("Index of 5 :"+list.indexOf(5));
        System.out.println("Index of 10 :"+list.indexOf(10));
        System.out.println("=======================================");
        System.out.println("The Item 5 is "+list.contains(5));
        System.out.println("The Item 4 is "+list.contains(4));
        System.out.println("===============remove element first ========================");
        //list.removeFirst();
        System.out.println("The Item 5 is "+list.contains(5));
      //  list.removeLastSecoundVersion();
        list.removeLast();
        list.addLast(90);
        System.out.println(list.getSize());
        System.out.println(Arrays.toString(list.toArray()));


    }
}