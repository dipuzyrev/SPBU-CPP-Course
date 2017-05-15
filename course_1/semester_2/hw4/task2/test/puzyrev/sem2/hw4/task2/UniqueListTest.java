package puzyrev.sem2.hw4.task2;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Random;

class UniqueListTest {
    Random random = new Random();
    int randomInt = random.nextInt();

    private void initialize(int[] array) {
        for (int i = 0; i < array.length; i++) {
            array[i] = randomInt;
            randomInt++;
        }
    }

    private void initialize(char[] array) {
        for (int i = 0; i < array.length; i++) {
            int maxChar = 256;
            array[i] = (char) (Math.random() * maxChar);
        }
    }

    @Test
    public void addTest() {
        int[] elements = new int[10];
        initialize(elements);
        List list = new UniqueList();

        // Add elements and check if they added:
        for (int i = 0; i < elements.length; i++) {
            list.add(elements[i]);
        }
        assertTrue(list.size() == 10);

        // Add similar values to throw exception:
        boolean thrown = false;
        try {
            list.add(1);
            list.add(1);
        } catch (RuntimeException e) {
            thrown = true;
        }
        assertTrue(thrown);
    }

    @Test
    public void removeTest() {
        int[] elements = new int[10];
        initialize(elements);
        List list = new UniqueList();

        // Add elements and check if they added:
        for (int i = 0; i < elements.length; i++) {
            list.add(elements[i]);
        }
        assertTrue(list.size() == 10);

        // Removing value which don't contains:
        boolean thrown = false;
        try {
            list.remove(elements[0] - 1);
        } catch (RuntimeException e) {
            thrown = true;
        }
        assertTrue(thrown);

        // Remove all elements and check if list is empty:
        for (int i = 0; i < elements.length; i++) {
            list.remove(elements[i]);
        }
        assertTrue(list.isEmpty());
    }

    @Test
    public void extractFirstTest() {
        int[] elements = new int[10];
        initialize(elements);
        List list = new UniqueList();

        // Add elements and check if they added:
        for (int i = 0; i < elements.length; i++) {
            list.add(elements[i]);
        }
        assertTrue(list.size() == 10);

        // Extract first elements and check values and list size:
        for (int i = 0; i < elements.length; i++) {
            int value = (int) list.extractFirst();

            assertTrue(value == elements[i]);
            assertTrue(list.size() == (elements.length - (i + 1)));
        }
        assertTrue(list.isEmpty());
    }

    @Test
    public void containsTest() {
        int[] elements = new int[10];
        initialize(elements);
        List list = new UniqueList();

        // Add elements and check if they added:
        for (int i = 0; i < elements.length; i++) {
            list.add(elements[i]);
        }
        assertTrue(list.size() == 10);

        // Check values containing in list:
        for (int i = 0; i < elements.length; i++) {
            assertTrue(list.contains(elements[i]));
        }

        // Check not contained value:
        assertTrue(!list.contains(elements[0] - 1));
    }
}