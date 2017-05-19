package sp;

import org.junit.Test;
import java.util.ArrayList;
import org.junit.Before;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import static org.junit.Assert.*;

public class SecondPartTasksTest {
    private Map<String, List<String>> compositions = new HashMap<>();
    private List<Map<String, Integer>> orders = new ArrayList<>();

    @Before
    public void initialize() {
        compositions.put("Author1", Arrays.asList(
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
                "Phasellus nec risus in orci dapibus iaculis quis vitae felis.",
                "Nam sagittis eget augue sed rutrum."));

        compositions.put("Author2", Arrays.asList(
                "Aenean mauris dui, condimentum nec scelerisque vel, lacinia sed odio.",
                "Proin nec odio porta, aliquet odio a, dignissim massa.",
                "Lorem ipsum dolor sit."));

        compositions.put("Author3", Arrays.asList(
                "Praesent ex purus, malesuada vitae metus et, pretium aliquam nibh.",
                "In gravida dictum turpis id scelerisque."));

        Map<String, Integer> firstOrder = new HashMap<>();
        firstOrder.put("Banana", 15);
        firstOrder.put("Pork", 50);
        firstOrder.put("Nuts", 10);

        Map<String, Integer> secondOrder = new HashMap<>();
        secondOrder.put("Ice-cream", 50);
        secondOrder.put("Banana", 35);

        Map<String, Integer> thirdOrder = new HashMap<>();
        thirdOrder.put("Nuts", 30);
        thirdOrder.put("Bread", 100);
        thirdOrder.put("Dumplings", 25);

        orders.addAll(Arrays.asList(firstOrder, secondOrder, thirdOrder));
    }

    @Test
    public void testFindQuotes() {
        for (Map.Entry<String, List<String>> entry : compositions.entrySet()) {
            try {
                FileWriter writer = new FileWriter(new File(entry.getKey() + ".txt"));
                for (String string : entry.getValue()) {
                    writer.write(string + '\n');
                }
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        List paths = Arrays.asList("Author1.txt", "Author2.txt", "Author3.txt");

        assertEquals(Arrays.asList(
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
                "Lorem ipsum dolor sit."
        ), SecondPartTasks.findQuotes(
                paths, "ipsum"));

        assertEquals(Arrays.asList(
                "Phasellus nec risus in orci dapibus iaculis quis vitae felis.",
                "Aenean mauris dui, condimentum nec scelerisque vel, lacinia sed odio.",
                "Proin nec odio porta, aliquet odio a, dignissim massa."
        ), SecondPartTasks.findQuotes(
                paths, "ne"));

        assertEquals(Arrays.asList(),
                SecondPartTasks.findQuotes(paths, "not exist"));

        assertEquals(Arrays.asList(),
                SecondPartTasks.findQuotes(Arrays.asList(), "ne"));
    }

    @Test
    public void testPiDividedBy4() {
        double expected = (double) Math.round(Math.PI * .25 * 10) / 10;

        for (int i = 0; i < 10; i++) {
            double result = (double) Math.round(SecondPartTasks.piDividedBy4() * 10) / 10;
            assertTrue(result == expected);
        }
    }

    @Test
    public void testFindPrinter() {
        assertEquals("Author1", SecondPartTasks.findPrinter(compositions));
        assertEquals(null, SecondPartTasks.findPrinter(new HashMap<>()));
    }

    @Test
    public void testCalculateGlobalOrder() {
        Map<String, Integer> expected = new HashMap<>();
        expected.put("Banana", 50);
        expected.put("Pork", 50);
        expected.put("Nuts", 40);
        expected.put("Ice-cream", 50);
        expected.put("Bread", 100);
        expected.put("Dumplings", 25);

        assertEquals(expected, SecondPartTasks.calculateGlobalOrder(orders));
    }
}