package puzyrev.sem2.hw2.task1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string to get answer");
        System.out.println("Please, use only single-character numbers");
        System.out.println("To stop enter 0");

        String string = sc.nextLine();
        while (!string.equals("0")) {
            System.out.println("Answer: " + Calculator.getAnswer(string));
            string = sc.nextLine();
        }
    }
}