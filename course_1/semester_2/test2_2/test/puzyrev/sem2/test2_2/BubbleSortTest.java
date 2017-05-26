package puzyrev.sem2.test2_2;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BubbleSortTest {
    @Test
    void testIntegers() {
        Integer[] testAray = {5,3,-1,6,7};
        Integer[] sortedArray = {-1,3,5,6,7};

        BubbleSort<Integer> sorter = new BubbleSort<>();
        sorter.sort(testAray, Integer::compareTo);

        for (int i = 0; i < testAray.length; i++) {
            assertTrue(testAray[i].equals(sortedArray[i]));
        }
    }

    @Test
    void testDoubles() {
        Double[] testAray = {1.4, -5.3, 5.6, 8.1, 10.4};
        Double[] sortedArray = {-5.3, 1.4, 5.6, 8.1, 10.4};

        BubbleSort<Double> sorter = new BubbleSort<>();
        sorter.sort(testAray, Double::compareTo);

        for (int i = 0; i < testAray.length; i++) {
            assertTrue(testAray[i].equals(sortedArray[i]));
        }
    }

    @Test
    void testStrings() {
        String[] testAray = {"m", "ac", "ab", "c", "ca"};
        String[] sortedArray = {"ab", "ac", "c", "ca", "m"};

        BubbleSort<String> sorter = new BubbleSort<>();
        sorter.sort(testAray, String::compareTo);

        for (int i = 0; i < testAray.length; i++) {
            assertTrue(testAray[i].equals(sortedArray[i]));
        }
    }
}