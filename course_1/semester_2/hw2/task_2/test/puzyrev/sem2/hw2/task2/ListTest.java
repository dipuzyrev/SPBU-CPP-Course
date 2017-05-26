package puzyrev.sem2.hw2.task2;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class ListTest {
    int[] elements = new int[10];

    private void initialize(int[] array) {
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt();
        }
    }

    @Test
    public void SingleLinkedListTest() {
        List SingleLinkedListList = new SingleLinkedList();
        initialize(elements);

        for (int i = 0; i < elements.length; i++) {
            SingleLinkedListList.addValue(elements[i]);
        }

        for (int i = 0; i < elements.length; i++) {
            SingleLinkedListList.deleteValue(elements[i]);
        }
        assertTrue(SingleLinkedListList.isEmpty());
    }

    @Test
    public void DoubleLinkedListTest() {
        List doubleLinkedList = new DoubleLinkedList();
        initialize(elements);

        for (int i = 0; i < elements.length; i++) {
            doubleLinkedList.addValue(elements[i]);
        }

        for (int i = 0; i < elements.length; i++) {
            doubleLinkedList.deleteValue(elements[i]);
        }
        assertTrue(doubleLinkedList.isEmpty());
    }
}