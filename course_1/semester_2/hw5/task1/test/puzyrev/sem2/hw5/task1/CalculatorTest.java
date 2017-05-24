package puzyrev.sem2.hw5.task1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    @Test
    void count() {
        Calculator calc = new Calculator();

        assertTrue(calc.count("-", 5, 4) == 1);
        assertTrue(calc.count("+", 234, 54) == 288);
        assertTrue(calc.count("*", 5, 7) == 35);
        assertTrue(calc.count("/", 27, 9) == 3);
    }
}