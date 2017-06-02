package puzyrev.sem2.hw3.task2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int array[][] = inputArray();
        System.out.println("Where you want to print your array? (console/file): ");
        String where = sc.nextLine();
        if (where.equals("console")) {
            ConsoleOut out = new ConsoleOut();
            out.print(array);
        } else if (where.equals("file")) {
            FileOut out = new FileOut();
            out.print(array);
        }
    }

    private static int[][] inputArray() {
        System.out.print("Input size of your 2-dimensional array: ");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int inputArray[][] = new int[size][size];
        System.out.println("Input your array: ");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                inputArray[i][j] = sc.nextInt();
            }
        }
        return inputArray;
    }
}