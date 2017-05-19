package sp;

import javafx.util.Pair;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.function.DoubleFunction;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class SecondPartTasks {

    private SecondPartTasks() {}

    // Найти строки из переданных файлов, в которых встречается указанная подстрока.
    public static List<String> findQuotes(List<String> paths, CharSequence sequence) {
        return paths.stream().flatMap((path) -> {
                try {
                    return Files.lines(Paths.get(path))
                            .filter(line -> line.contains(sequence))
                            .collect(Collectors.toList()).stream();
                } catch (IOException e) {
                    return Stream.empty();
                }
            }).collect(Collectors.toList());
    }

    // В квадрат с длиной стороны 1 вписана мишень.
    // Стрелок атакует мишень и каждый раз попадает в произвольную точку квадрата.
    // Надо промоделировать этот процесс с помощью класса java.util.Random и посчитать, какова вероятность попасть в мишень.
    public static double piDividedBy4() {
        int count = 1000000;

        Random randomizer = new Random();
        int successful = (int) randomizer
                .doubles(count)
                .mapToObj(new DoubleFunction<Pair<Double, Double>>() {
                    double previous = -1;

                    @Override
                    public Pair<Double, Double> apply(double current) {
                        Pair result;
                        if (previous != -1) {
                            result = new Pair(previous, current);
                            previous = -1;
                        } else {
                            result = new Pair(null, null);
                            previous = current;
                        }

                        previous = current;
                        return result;
                    }
                })
                .filter((v) -> v.getValue() != null)
                .filter((v) -> Math.sqrt(Math.pow((double) v.getKey() - .5, 2)
                        + Math.pow(Math.abs((double) v.getValue() - .5), 2)) <= .5)
                .count();
        return (double) successful / count;
    }

    // Дано отображение из имени автора в список с содержанием его произведений.
    // Надо вычислить, чья общая длина произведений наибольшая.
    public static String findPrinter(Map<String, List<String>> compositions) {
        return compositions.entrySet().stream()
                .map(entry -> new Pair<>(entry.getKey(), String.join("", entry.getValue()).length()))
                .max(Comparator.comparing(Pair::getValue))
                .orElse(new Pair<>(null, null)).getKey();
    }

    // Вы крупный поставщик продуктов. Каждая торговая сеть делает вам заказ в виде Map<Товар, Количество>.
    // Необходимо вычислить, какой товар и в каком количестве надо поставить.
    public static Map<String, Integer> calculateGlobalOrder(List<Map<String, Integer>> orders) {
        return orders.stream()
                .flatMap(order -> order.entrySet().stream())
                .collect(Collectors.groupingBy(Map.Entry::getKey, Collectors.collectingAndThen(Collectors.toList(),
                    list -> list.stream().mapToInt(Map.Entry::getValue).sum())));
    }
}
