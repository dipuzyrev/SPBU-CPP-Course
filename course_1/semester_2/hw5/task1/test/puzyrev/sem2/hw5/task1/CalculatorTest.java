package puzyrev.sem2.hw5.task1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    @Test
    void testPlus() {
        Calculator calc = new Calculator();

        assertTrue(calc.count("+", 234, 54) == 288);
        assertTrue(calc.count("+", 50, -50) == 0);
        assertTrue(calc.count("+", -1, 2) == 1);
    }

    @Test
    void testMinus() {
        Calculator calc = new Calculator();

        assertTrue(calc.count("-", 5, 4) == 1);
        assertTrue(calc.count("-", 3, 3) == 0);
        assertTrue(calc.count("-", 2, -5) == 7);
    }

    @Test
    void testMultiply() {
        Calculator calc = new Calculator();

        assertTrue(calc.count("*", 5, 7) == 35);
        assertTrue(calc.count("*", 45, 0) == 0);
        assertTrue(calc.count("*", 5, -1) == -5);
    }

    @Test
    void testDivision() {
        Calculator calc = new Calculator();

        assertTrue(calc.count("/", 27, 9) == 3);
        assertTrue(calc.count("/", 0, 60) == 0);
        assertTrue(calc.count("/", 7, 1) == 7);
    }
}