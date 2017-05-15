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
    public void testFirstHasher() {
        testHashTable(new DJB2Hasher());
    }

    @Test
    public void testSecondHasher() {
        testHashTable(new SumHasher());
    }

    private void testHashTable(Hasher hasher) {
        HashTable<Integer> testTable = new HashTable<>(hasher);

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testTable.add(testArray[i]);
            assertTrue(testTable.contains(testArray[i]));
        }

        for (int i = 0; i < ARRAY_SIZE; i++) {
            testTable.remove(testArray[i]);
            assertTrue(!testTable.contains(testArray[i]));
        }
    }
}