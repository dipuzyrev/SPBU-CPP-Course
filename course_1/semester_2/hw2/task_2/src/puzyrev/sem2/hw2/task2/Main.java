package puzyrev.sem2.hw2.task2;

public class Main {
    public static void main(String[] args) {
        System.out.println("TEST 1 BEGINNING: (SINGLE LINKED)");
        testMyList(new SingleLinkedList());

        System.out.println("\nTEST 2 BEGINNING: (DOUBLE LINKED);");
        testMyList(new DoubleLinkedList());
    }

    public static void testMyList(List testList) {
        System.out.print("Add values to list from 0 to 15 and print: ");
        for (int i = 0; i <= 15; i++) {
            testList.addValue(i);
        }
        testList.print();

        System.out.print("Delete values from 5 to 15 and print: ");
        for (int i = 5; i <= 15; i++) {
            testList.deleteValue(i);
        }
        testList.print();

        System.out.println("Is empty? " + testList.isEmpty());

        if (testList.isEmpty()) {
            System.out.println("Something went wrong!");
            return;
        }

        System.out.print("Delete remaining values from 0 to 4. ");
        for (int i = 0; i <= 4; i++) {
            testList.deleteValue(i);
        }

        System.out.println("Is empty now? " + testList.isEmpty());

        if (testList.isEmpty()) {
            System.out.println("Test passed successfully.");
        } else {
            System.out.println("Something went wrong!");
        }
    }
}