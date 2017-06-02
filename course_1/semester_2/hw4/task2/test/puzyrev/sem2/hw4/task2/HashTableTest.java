package puzyrev.sem2.hw4.task2;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.AfterEach;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Random;

class HashTableTest {
    private final int ARRAY_SIZE = 512;
    private final int STEP_SIZE = 64;
    private Integer[] testArray;

    @BeforeEach
    public void setUpTestArray() {
        Random randomizer = new Random();
        testArray = new Integer[ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testArray[i] = STEP_SIZE * i + randomizer.nextInt(STEP_SIZE - 1);
        }
    }

    @AfterEach
    public void tearDownTestArray() {
        testArray = null;
    }

    @Test
    public void testAdd() {
        HashTable<Integer> testTable = new HashTable<>(new DJB2Hasher());

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testTable.add(testArray[i]);
            assertTrue(testTable.contains(testArray[i]));
        }
    }

    @Test
    public void testRemove() {
        HashTable<Integer> testTable = new HashTable<>(new DJB2Hasher());

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testTable.remove(testArray[i]);
            assertTrue(!testTable.contains(testArray[i]));
        }
    }

    @Test
    public void testHasherChange() {
        HashTable<Integer> testTable = new HashTable<>(new DJB2Hasher());
        SumHasher hash = new SumHasher();
        testTable.changeHasher(hash);

        assertTrue(testTable.getHasher().equals(hash));
    }

    @Test
    public void testResizing() {
        HashTable<Integer> testTable = new HashTable<>(new DJB2Hasher());
        testTable.add(1);

        int size = testTable.getSize();
        testTable.resize();

        assertTrue(size < testTable.getSize());
    }
}