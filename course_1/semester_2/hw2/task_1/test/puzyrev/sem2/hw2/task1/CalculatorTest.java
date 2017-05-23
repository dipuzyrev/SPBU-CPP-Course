package puzyrev.sem2.hw2.task1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    String testExpression = "3 * (4 + 6) / 5";
    int correctAnswer = 6;

    @Test
    public void calculatorTest() {
        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }
}