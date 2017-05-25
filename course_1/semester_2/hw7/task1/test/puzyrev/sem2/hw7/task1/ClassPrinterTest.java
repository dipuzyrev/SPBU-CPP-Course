package puzyrev.sem2.hw7.task1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.io.*;
import java.util.Scanner;

class ClassPrinterTest {
    @Test
    void printClass() throws IOException {
        File fileTest = new File("testOutput.txt");
        File fileCorrect = new File("correctOutput.txt");

        ClassPrinter printer = new ClassPrinter();
        printer.printClass(ClassPrinter.class);

        assertTrue(compareFiles(fileTest, fileCorrect));
    }

    public boolean compareFiles(File file1, File file2) throws FileNotFoundException {
        Scanner s1 = new Scanner(new FileReader(file1));
        Scanner s2 = new Scanner(new FileReader(file2));

        while (s2.hasNext() && s2.hasNext()) {
            String str1 = s1.nextLine();
            String str2 = s2.nextLine();
            if (!str1.equals(str2)) {
                System.out.println(str1);
                System.out.println(str2);
                return false;
            }
        }

        return true;
    }
}