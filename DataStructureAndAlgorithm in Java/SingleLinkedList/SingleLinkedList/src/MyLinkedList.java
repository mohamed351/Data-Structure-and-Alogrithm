import java.lang.reflect.Field;
import java.util.NoSuchElementException;

public class MyLinkedList {

    private class Node{
        private int value;
        private Node next;
        public Node(int value){
            this.value= value;
        }

    }

    private  Node first;
    private  Node last;
    private  int size;
    public int getSize() {
        return size;
    }

    public void addLast(int value){
       var node = new Node(value);
        if(isEmpty()){
            first = last = node;
        }
        else{
            last.next = node;
            last = node;

        }
        size++;
    }
    public void addFirst(int value){
        var node = new Node(value);
        if(isEmpty()){
            first = last = node;
        }
        else{
            node.next=  first;
            first = node;
        }
        size++;
    }
    public int indexOf(int item){
        int index =0;
        var current = first;
        while (current != null){
            if(current.value == item) return index;
            current = current.next;
            index++;
        }
        return -1;
    }
    private  boolean isEmpty(){
        return first == null;
    }
    public  boolean contains(int item){
        return indexOf(item) != -1;
    }
    public void removeFirst(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
       if(first == last){
           first = last= null;
       }
        var second = first.next;
        first.next = null;
        first = second;
        size--;

    }
    public void removeLast(){
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        Node  previous = null;
        var current = first;
        while (current.next != null){
            previous = current;
            current = current.next;

        }
        if(previous != null){
            previous.next = null;
            last = previous;

        }
        size--;

    }
    public void removeLastSecoundVersion(){
        if(isEmpty()){
            throw  new NoSuchElementException();
        }
        if(first == last){
            first = last = null;
        }
      var previous = getPreviousNode(last);
      if(previous != null) {
          previous.next = null;
          last = previous;
      }
      size--;

    }

    private  Node getPreviousNode(Node node){
        var current = first;
        while (current != null){
            if(current.next == node) return current;
            current = current.next;
        }
        return null;

    }
    public int[] toArray(){
        int[] items = new int[size];
        int index =0;
        var current = first;
        while (current != null){
            items[index] = current.value;
            current = current.next;
            index++;

        }
        return items;

    }



}
