//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {//TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        ArrayList list = new ArrayList(5);
        list.Append(10);
        list.Append(20);
        list.Append(30);
        list.Append(40);
        list.Append(50);
        list.Append(60);
        list.Insert(100,1);

        list.RemoveAt(6);
        list.Print();

    }
}