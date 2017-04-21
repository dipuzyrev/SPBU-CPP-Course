package puzyrev.sem2.hw1.task2;

public class Main {
    public static void main(String[] args) {
        List<String> testList = new List();

        System.out.println("Add values to list: \"First\", \"Second\", \"Third\" and \"Fourth\".");
        testList.addValue("First");
        testList.addValue("Second");
        testList.addValue("Third");
        testList.addValue("Fourth");

        System.out.println("Delete values: in the middle (\"Second\"), last (\"Fourth\") and finally first (\"First\").");
        testList.deleteValue("Second");
        testList.deleteValue("Fourth");
        testList.deleteValue("First");

        System.out.println("Is empty? " + testList.isEmpty());

        if (testList.isEmpty()) {
            System.out.println("Something went wrong!");
            return;
        }

        System.out.println("Delete remaining value \"Third\".");
        testList.deleteValue("Third");

        System.out.println("Is empty now? " + testList.isEmpty());

        if (testList.isEmpty()) {
            System.out.println("Test passed successfully.");
        } else {
            System.out.println("Something went wrong!");
        }
    }
}
