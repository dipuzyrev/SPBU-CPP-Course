package puzyrev.sem2.test2_2;

import java.util.Comparator;

/**
 * Bubble sorting for arrays with elements of any types.
 */
public class BubbleSort<T> {

    /**
     * Sort array.
     * @param array array for sorting
     * @param comparator comparator object for array elements
     */
    public void sort(T[] array, Comparator<T> comparator) {
        for (int i = array.length; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (comparator.compare(array[j], array[j + 1]) > 0) {
                    T min = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = min;
                }
            }
        }
    }
}
