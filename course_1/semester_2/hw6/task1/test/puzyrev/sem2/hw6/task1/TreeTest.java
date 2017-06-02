package puzyrev.sem2.hw6.task1;

import java.io.FileWriter;
import java.io.IOException;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TreeTest {
    private final String fileName = "input.txt";
    private String testExpression = "(/ (* 2 5) (- 4 (+ 1 1))";
    private int testAnswer = 5;

    @BeforeEach
    void setUp() {
        try {
            FileWriter writer = new FileWriter(fileName);
            writer.write(testExpression);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    void checkTreeWork() {
        Tree testTree = new Tree(fileName);
        assertTrue(testTree.calculate() == testAnswer);
    }
}