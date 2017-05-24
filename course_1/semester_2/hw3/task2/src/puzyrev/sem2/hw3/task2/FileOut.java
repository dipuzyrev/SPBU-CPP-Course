package puzyrev.sem2.hw3.task2;

import java.io.IOException;
import java.io.FileWriter;

/**
 * Cycle printing array to file.
 */
public class FileOut extends Out {

    /**
     * Array cycle printing.
     *
     * @param array 2-dimensional array to print.
     */
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
