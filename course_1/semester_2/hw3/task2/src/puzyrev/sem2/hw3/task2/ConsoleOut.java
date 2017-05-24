package puzyrev.sem2.hw3.task2;

/**
 * Cycle printing array to console.
 */
public class ConsoleOut extends Out {

    /**
     * Array cycle printing.
     *
     * @param array 2-dimensional array to print.
     */
    public void print(int[][] array) {
        int[] result = getResultArray(array);

        System.out.print(result[0]);
        for (int i = 1; i < result.length; i++) {
            System.out.print(" " + result[i]);
        }
    }
}
