package puzyrev.sem2.hw3.task1;

public class QuickSort implements Sorting {
    public void sort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    private void quickSort(int[] array, int first, int last) {
        int pivot = array[(first + last) / 2];
        int i = first;
        int j = last;

        while (i < j) {
            while (i < j && array[i] < pivot)
                i++;
            while (j > i && array[j] > pivot)
                j--;
            if (i < j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        if (j - 1 - first > 0)
            quickSort(array, first, j - 1);
        if (last - i - 1 > 0)
            quickSort(array, i + 1, last);
    }
}