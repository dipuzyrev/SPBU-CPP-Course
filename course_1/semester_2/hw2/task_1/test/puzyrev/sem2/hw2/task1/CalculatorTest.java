package puzyrev.sem2.hw2.task1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    @Test
    public void testPlus() {
        String testExpression = "4 + 5";
        int correctAnswer = 9;

        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }

    @Test
    public void testMinus() {
        String testExpression = "9 - 2";
        int correctAnswer = 7;

        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }

    @Test
    public void testMult() {
        String testExpression = "4 * 9";
        int correctAnswer = 36;

        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }

    @Test
    public void testDivision() {
        String testExpression = "15 / 3";
        int correctAnswer = 5;

        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }

    @Test
    public void testBigExpression() {
        String testExpression = "3 * (4 + 6) / 5";
        int correctAnswer = 6;

        assertTrue(correctAnswer == Calculator.getAnswer(testExpression));
    }
}