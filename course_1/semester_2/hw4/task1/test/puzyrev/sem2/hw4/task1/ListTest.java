package puzyrev.sem2.hw4.task1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Random;

public class ListTest {
    Random random = new Random();

    private void initialize(int[] array) {
        for (int i = 0; i < array.length; i++)
            array[i] = random.nextInt();
    }

    private void initialize(char[] array) {
        for (int i = 0; i < array.length; i++) {
            int maxChar = 256;
            array[i] = (char) (Math.random() * maxChar);
        }
    }

    @Test
    public void LinkedListIntegerTest() {
        int[] elements = new int[10];
        initialize(elements);
        List linkedList = new LinkedList();

        for (int i = 0; i < elements.length; i++) {
            linkedList.addValue(elements[i]);
        }
        assertTrue(linkedList.size() == 10);

        for (int i = 0; i < elements.length; i++) {
            linkedList.deleteValue(elements[i]);
        }
        assertTrue(linkedList.isEmpty());
    }

    @Test
    public void LinkedListCharTest() {
        char[] elements = new char[10];
        initialize(elements);
        List linkedList = new LinkedList();

        for (int i = 0; i < elements.length; i++) {
            linkedList.addValue(elements[i]);
        }
        assertTrue(linkedList.size() == 10);

        for (int i = 0; i < elements.length; i++) {
            linkedList.deleteValue(elements[i]);
        }
        assertTrue(linkedList.isEmpty());
    }

    @Test
    public void ElementExistTest() {
        boolean thrown = false;

        List<Integer> list = new UniqueList<>();
        int toAdd = random.nextInt();
        list.addValue(toAdd);

        try {
            list.addValue(toAdd);
        } catch (Exception e) {
            thrown = true;
        }

        assertTrue(thrown);
    }

    @Test
    public void ElementNotExistTest() {
        boolean thrown = false;

        List<Integer> list = new UniqueList<>();
        int toRemove = random.nextInt();

        try {
            list.deleteValue(toRemove);
        } catch (Exception e) {
            thrown = true;
        }
        assertTrue(thrown);
    }
}