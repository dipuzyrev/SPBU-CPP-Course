package puzyrev.sem2.hw6.task1;

public class Main {
    public static void main(String[] args) {
        Tree tree = new Tree("input.txt");
        System.out.println(tree.convertToString());
        System.out.println("Calculated result: " + trimZeros(tree.calculate()));
    }

    private static String trimZeros(float number) {
        if (number == Math.round(number)) {
            return Integer.toString((int) number);
        } else {
            return Float.toString(number);
        }
    }
}