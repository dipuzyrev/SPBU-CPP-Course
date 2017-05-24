package puzyrev.sem2.hw3.task2;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class OutputTest {
    private int[][] testingArray = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    private String expectedOutput = "5 2 3 6 9 8 7 4 1";

    @Test
    public void ConsoleTest() throws IOException {
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        PrintStream printStream = new PrintStream(byteArrayOutputStream);
        PrintStream prev = System.out;
        System.setOut(printStream);

        ConsoleOut outConsole = new ConsoleOut();
        outConsole.print(testingArray);

        System.setOut(prev);
        printStream.close();

        String result = byteArrayOutputStream.toString();
        assertTrue(result.equals(expectedOutput));
    }

    @Test
    public void FileTest() throws IOException {
        FileOut outFile = new FileOut();
        outFile.print(testingArray);

        Scanner sc = new Scanner(new File("print.txt"));
        String result = sc.nextLine();
        assertTrue(result.equals(expectedOutput));
    }
}