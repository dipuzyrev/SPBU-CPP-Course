package puzyrev.sem2.hw1.task1;

public class Main {

    public static void main (String[] args) {

        //Integer test
        System.out.println("INTEGER TEST:");
        Stack<Integer> intStack = new Stack();

        System.out.println("Push values: (1) and then (2);");
        intStack.push(1);
        intStack.push(2);

        System.out.println("Pop value: " + intStack.pop());
        System.out.println("Pop other value: " + intStack.pop());
        System.out.println("Is empty? " + intStack.isEmpty() + "\n");

        //String test
        System.out.println("STRING TEST:");
        Stack<String> strStack = new Stack();

        System.out.println("Push values: (First string) and then (Second string);");
        strStack.push("First string");
        strStack.push("Second string");

        System.out.println("Pop value: " + strStack.pop());
        System.out.println("Pop other value: " + strStack.pop());
        System.out.println("Is empty? " + strStack.isEmpty());
    }
}