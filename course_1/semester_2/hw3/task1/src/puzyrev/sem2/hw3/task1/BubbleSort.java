package puzyrev.sem2.hw3.task1;

public class BubbleSort implements Sorting {
    public void sort(int[] array) {
        for (int i = array.length; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int smallNumber = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = smallNumber;
                }
            }
        }
    }
}