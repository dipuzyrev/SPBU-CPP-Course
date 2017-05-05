package puzyrev.sem2.hw3.task2;

public class ConsoleOutput implements Output {
    public void print(int[][] array) {
        int center = (array.length - 1) / 2;

        System.out.print(array[center][center]);
        int startCol = center;

        for (int i = center - 1; i >= 0; i--) {
            int pathLength = (center - i) * 2 + 1;
            int leftSide = startCol - 1;
            int rightSide = startCol + pathLength - 2;
            int bottomSide = i + pathLength - 1;

            //print top line
            for (int j = startCol; j <= rightSide; j++) {
                System.out.print(" " + array[i][j]);
            }

            //print right line
            for (int j = i + 1; j <= bottomSide; j++) {
                System.out.print(" " + array[j][rightSide]);
            }

            //print bottom line
            for (int j = rightSide - 1; j >= leftSide; j--) {
                System.out.print(" " + array[bottomSide][j]);
            }

            //print left side
            for (int j = bottomSide - 1; j >= i; j--) {
                System.out.print(" " + array[j][leftSide]);
            }

            startCol = bottomSide;
        }
    }
}
