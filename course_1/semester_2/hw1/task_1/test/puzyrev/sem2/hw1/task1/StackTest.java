package puzyrev.sem2.hw1.task1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class StackTest {
    @Test
    void push() {
        Stack<Integer> testStack = new Stack<>();
        testStack.push(1);
        assertTrue(!testStack.isEmpty());
    }

    @Test
    void pop() {
        Stack<String> testStack = new Stack<>();
        testStack.push("First");
        testStack.push("Second");
        assertTrue(testStack.pop().equals("Second"));
    }

    @Test
    void isEmpty() {
        Stack<Integer> testStack = new Stack<>();
        assertTrue(testStack.isEmpty());

        testStack.push(1);
        assertTrue(!testStack.isEmpty());
    }
}