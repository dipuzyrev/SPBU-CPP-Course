package puzyrev.sem2.hw3.task2;

import java.io.IOException;
import java.io.FileWriter;

public class FileOutput implements Output {
    public void print(int[][] array) throws IOException {
        int center = (array.length - 1) / 2;

        FileWriter writer = new FileWriter("output.txt", false);
        writer.append(Integer.toString(array[center][center]));
        writer.flush();

        int startCol = center;

        for (int i = center - 1; i >= 0; i--) {
            int pathLength = (center - i) * 2 + 1;
            int leftSide = startCol - 1;
            int rightSide = startCol + pathLength - 2;
            int bottomSide = i + pathLength - 1;

            //print top line
            for (int j = startCol; j <= rightSide; j++) {
                writer.append(" " + array[i][j]);
                writer.flush();
            }

            //print right line
            for (int j = i + 1; j <= bottomSide; j++) {
                writer.append(" " + array[j][rightSide]);
                writer.flush();
            }

            //print bottom line
            for (int j = rightSide - 1; j >= leftSide; j--) {
                writer.append(" " + array[bottomSide][j]);
                writer.flush();
            }

            //print left side
            for (int j = bottomSide - 1; j >= i; j--) {
                writer.append(" " + array[j][leftSide]);
                writer.flush();
            }

            startCol = bottomSide;
        }
    }
}
