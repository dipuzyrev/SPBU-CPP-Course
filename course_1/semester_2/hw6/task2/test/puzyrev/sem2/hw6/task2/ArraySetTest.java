package puzyrev.sem2.hw6.task2;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class ArraySetTest {
    private static final int ARRAY_SIZE = 100;
    private int testArray[] = new int[ARRAY_SIZE];
    ArraySet<Integer> testSet;
    Random randomizer = new Random();

    @BeforeEach
    public void initialize() {
        testSet = new ArraySet<Integer>();
    }

    /** Function "Size()" test: */
    @Test
    public void sizeTest() {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testSet.add(i);
        }
        assertTrue(testSet.size() == ARRAY_SIZE);
    }

    /** Function "isEmpty()" test: */
    @Test
    public void isEmptyTest() {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testSet.add(i);
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testSet.remove(i);
        }

        assertTrue(testSet.isEmpty());
    }

    /** Function "contains()" test: */
    @Test
    public void containsTest() {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int nextRandomNumber = randomizer.nextInt();
            testSet.add(nextRandomNumber);
            testArray[i] = nextRandomNumber;
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            assertTrue(testSet.contains(testArray[i]));
        }
    }

    /** Function "iterator()" test: */
    @Test
    public void iteratorTest() {
        testSet.add(14);
        testSet.add(62);
        testSet.add(991);
        testSet.add(3);
        testSet.add(5213);

        Iterator iterator = testSet.iterator();
        while (iterator.hasNext()) {
            assertTrue(testSet.contains(iterator.next()));
        }
    }

    /** Function "toArray()" test: */
    @Test
    public void toArrayTest() {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int nextRandomNumber = randomizer.nextInt();
            testSet.add(nextRandomNumber);
            testArray[i] = nextRandomNumber;
        }

        Object[] resultArray = testSet.toArray();

        for (int i = 0; i < resultArray.length; i++) {
            assertTrue(testSet.contains(resultArray[i]));
        }
    }

    /** Functions "add()" and "remove()" test: */
    @Test
    public void addAndRemoveTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int nextRandomNumber = randomizer.nextInt();
            testList.add(nextRandomNumber);
        }

        assertTrue(testSet.size() <= ARRAY_SIZE);

        Iterator iterator = testList.iterator();
        while (iterator.hasNext()) {
            testSet.remove(iterator.next());
        }

        assertTrue(testSet.isEmpty());
    }

    /** Function "containsAll()" test: */
    @Test
    public void containsAllTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int nextRandomNumber = randomizer.nextInt();
            testSet.add(nextRandomNumber);
            testList.add(nextRandomNumber);
        }

        assertTrue(testSet.containsAll(testList));
    }

    /** Function "addAll()" test: */
    @Test
    public void addAllTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testList.add(randomizer.nextInt());
        }

        testSet.add(randomizer.nextInt());
        testSet.addAll(testList);
        assertTrue(testSet.containsAll(testList));
    }

    /** Function "retainAll()" test: */
    @Test
    public void retainAllTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testList.add(randomizer.nextInt() + 10);
        }

        testSet.add(5);
        testSet.addAll(testList);
        testSet.add(7);
        testSet.retainAll(testList);

        assertTrue(testSet.containsAll(testList));
        assertTrue(!testSet.contains(5));
        assertTrue(!testSet.contains(7));
    }

    /** Function "removeAll()" test: */
    @Test
    public void removeAllTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testList.add(randomizer.nextInt());
        }

        testSet.addAll(testList);
        testSet.removeAll(testList);
        for (Integer value: testList) {
            assertTrue(!testSet.contains(value));
        }
    }

    /** Function "clear()" test: */
    @Test
    public void clearTest() {
        ArrayList<Integer> testList = new ArrayList<>();
        for (int i = 0; i < ARRAY_SIZE; i++) {
            testList.add(randomizer.nextInt());
        }

        testSet.addAll(testList);
        testSet.clear();

        assertTrue(testSet.isEmpty());
    }
}