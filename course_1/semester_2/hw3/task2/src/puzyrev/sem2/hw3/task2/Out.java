package puzyrev.sem2.hw3.task2;

/**
 * Abstract class with method for cycle array printing.
 */
abstract class Out {

    /**
     * Cycle converting 2-dimensional array to 1-dimensional.
     *
     * @param array 2-dimensional array for converting
     * @return converted 1-dimensional array
     * @throws NullPointerException if array is empty
     */
    public int[] getResultArray(int[][] array) throws NullPointerException {
        int length = array.length * array.length;
        int[] result = new int[length];

        if (length == 0) {
            throw new NullPointerException("Array is empty!");
        }

        int center = (array.length - 1) / 2;
        result[0] = array[center][center];

        int startCol = center;
        int temp = 1;

        for (int i = center - 1; i >= 0; i--) {
            int pathLength = (center - i) * 2 + 1;
            int leftSide = startCol - 1;
            int rightSide = startCol + pathLength - 2;
            int bottomSide = i + pathLength - 1;

            //print top line
            for (int j = startCol; j <= rightSide; j++) {
                result[temp] = array[i][j];
                temp++;
            }

            //print right line
            for (int j = i + 1; j <= bottomSide; j++) {
                result[temp] = array[j][rightSide];
                temp++;
            }

            //print bottom line
            for (int j = rightSide - 1; j >= leftSide; j--) {
                result[temp] = array[bottomSide][j];
                temp++;
            }

            //print left side
            for (int j = bottomSide - 1; j >= i; j--) {
                result[temp] = array[j][leftSide];
                temp++;
            }

            startCol = bottomSide;
        }

        return result;
    }
}