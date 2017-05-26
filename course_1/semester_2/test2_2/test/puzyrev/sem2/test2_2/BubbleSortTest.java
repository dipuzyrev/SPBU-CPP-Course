package puzyrev.sem2.test2_2;

import org.junit.jupiter.api.Test;
import java.util.Comparator;
import static org.junit.jupiter.api.Assertions.*;

class BubbleSortTest {
    @Test
    void testIntegers() {
        Integer[] testAray = {5, 3, -1, 6, 7};
        Integer[] sortedArray = {-1, 3, 5, 6, 7};

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

    @Test
    void testClass() {
        TestClass[] testArray = {
            new TestClass(2, 1),
            new TestClass(3, 3),
            new TestClass(1, 4),
            new TestClass(1, 5),
            new TestClass(1, 5),
            new TestClass(3, 4)
        };

        BubbleSort<TestClass> sorter = new BubbleSort<>();
        sorter.sort(testArray, new TestClass(0,0));

        for (int i = 0; i < testArray.length - 1; i++) {
            assertTrue(testArray[i].compareTo(testArray[i + 1]) <= 0);
        }
    }

    private class TestClass implements Comparable<TestClass>, Comparator<TestClass> {
        public int firstIndex;
        public int secondIndex;

        public TestClass(int first, int second) {
            firstIndex = first;
            secondIndex = second;
        }

        public void getText() {
            System.out.println(firstIndex + "/" + secondIndex);
        }

        @Override
        public int compareTo(TestClass element) {
            if (firstIndex < element.firstIndex) {
                return -1;
            } else if (firstIndex > element.firstIndex) {
                return 1;
            } else {
                if (secondIndex < element.secondIndex) {
                    return -1;
                } else if (secondIndex > element.secondIndex) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }

        @Override
        public int compare(TestClass element1, TestClass element2) {
            if (element1.firstIndex < element2.firstIndex) {
                return -1;
            } else if (element1.firstIndex > element2.firstIndex) {
                return 1;
            } else {
                if (element1.secondIndex < element2.secondIndex) {
                    return -1;
                } else if (element1.secondIndex > element2.secondIndex) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}