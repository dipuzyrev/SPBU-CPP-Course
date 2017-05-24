package puzyrev.sem2.hw3.task2;

import java.io.IOException;
import java.io.FileWriter;

public class FileOut extends Out {
    public void print(int[][] array) {
        try {
            FileWriter writer = new FileWriter("print.txt", false);
            int[] result = getResultArray(array);

            writer.append(Integer.toString(result[0]));
            writer.flush();
            for (int i = 1; i < result.length; i++) {
                writer.append(" " + result[i]);
                writer.flush();
            }
        } catch (IOException e) {
            System.out.println("Can't write to print file 'print.txt'.");
        }
    }
}
