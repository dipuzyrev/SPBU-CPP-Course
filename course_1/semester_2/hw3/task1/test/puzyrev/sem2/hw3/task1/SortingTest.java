package puzyrev.sem2.hw3.task1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Random;

public class SortingTest {
    private int arraySize = 1000;
    private int[] array = new int[arraySize];

    private void initialize(int[] array) {
        Random random = new Random();

        for (int i = 0; i < arraySize; i++) {
            array[i] = random.nextInt();
        }
    }

    @Test
    public void BubbleSortTest() {
        BubbleSort test = new BubbleSort();
        initialize(array);
        test.sort(array);
        for (int i = 0; i < array.length - 1; i++) {
            assertTrue(array[i] < array[i + 1]);
        }
    }

    @Test
    public void QuickSortTest() {
        QuickSort test = new QuickSort();
        initialize(array);
        test.sort(array);
        for (int i = 0; i < array.length - 1; i++) {
            assertTrue(array[i] < array[i + 1]);
        }
    }

    @Test
    public void InsertionSortTest() {
        InsertionSort test = new InsertionSort();
        initialize(array);
        test.sort(array);
        for (int i = 0; i < array.length - 1; i++) {
            assertTrue(array[i] < array[i + 1]);
        }
    }
}