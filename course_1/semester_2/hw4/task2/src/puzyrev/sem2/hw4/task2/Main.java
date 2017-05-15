package puzyrev.sem2.hw4.task2;

import java.util.Scanner;

public class Main {
    private enum Operation {
        HELP,
        STAT,
        ADD,
        FIND,
        RM,
        HASHER
    }

    private enum Hash {
        DJB2,
        SUM
    }

    public static void main(String[] args) {
        printHelp();
        Scanner in = new Scanner(System.in);
        HashTable<String> table = null;
        boolean tableCreated = false;

        while(true) {
            if (tableCreated) {
                //System.out.print("$ ");
                String command = in.nextLine();

                if (!command.equals("exit")) {
                    String[] splitted = command.split(" ", 2);
                    Operation operation = getOperation(splitted[0]);
                    execute(table, operation, splitted);
                } else {
                    break;
                }

            } else {
                System.out.print("Input hash function you want to use: ");
                String hashName = in.nextLine();

                try {
                    Hash hash = Hash.valueOf(hashName.toUpperCase());
                    switch (hash) {
                        case DJB2:
                            table = new HashTable<>(new DJB2Hasher());
                            break;
                        case SUM:
                            table = new HashTable<>(new SumHasher());
                            break;
                    }
                    tableCreated = true;
                    System.out.println("Hash function selected");
                } catch (IllegalArgumentException e) {
                    System.out.println("Unknown hash function '" + hashName + "'");
                }
            }
        }
    }

    private static boolean execute(HashTable<String> table, Operation operation, String[] splitResult) {
        switch (operation) {
            case HELP:
                printHelp();
                break;
            case STAT:
                System.out.println(table.statistics());
                break;
            case ADD:
                if (checkArgumentsNumber(splitResult)) {
                    if (table.contains(splitResult[1])) {
                        System.out.println("Value '" + splitResult[1] + "' already exist");
                    } else {
                        table.add(splitResult[1]);
                        System.out.println("Value '" + splitResult[1] + "' added");
                    }
                }
                break;
            case FIND:
                if (checkArgumentsNumber(splitResult)) {
                    if (table.contains(splitResult[1])) {
                        System.out.println("Value '" + splitResult[1] + "' was found");
                    } else {
                        System.out.println("Value '" + splitResult[1] + "' not found");
                    }
                }
                break;
            case RM:
                if (checkArgumentsNumber(splitResult)) {
                    if (table.contains(splitResult[1])) {
                        table.remove(splitResult[1]);
                        System.out.println("Value '" + splitResult[1] + "' removed");
                    } else {
                        System.out.println("Value '" + splitResult[1] + "' not found");
                    }
                }
                break;
            case HASHER:
                if (checkArgumentsNumber(splitResult)) {
                    changeHashFunc(table, splitResult[1]);
                }
                break;
        }
        return true;
    }

    private static boolean checkArgumentsNumber(String[] splitted) {
        if (splitted.length != 2) {
            System.out.println("Syntax error, type 'help' to get usage");
        }

        return splitted.length == 2;
    }

    private static void changeHashFunc(HashTable table, String func) {
        try {
            Hash hash = Hash.valueOf(func.toUpperCase());
            switch (hash) {
                case DJB2:
                    table.changeHasher(new DJB2Hasher());
                    break;
                case SUM:
                    table.changeHasher(new SumHasher());
                    break;
            }
            System.out.println("Hash function changed");
        } catch (IllegalArgumentException e) {
            System.out.println("Unknown hash function '" + func + "'");
        }
    }

    private static Operation getOperation(String operation) {
        try {
            Operation nativeOperation = Operation.valueOf(operation.toUpperCase());
            return nativeOperation;
        } catch (IllegalArgumentException e) {
            return Operation.HELP;
        }
    }

    private static void printHelp() {
        System.out.println("You can use this commands:");
        System.out.println("exit - to close the program");
        System.out.println("help - to print this help message again");
        System.out.println("stat - to print hash table statistics");
        System.out.println("add <value> - to add <value> to hash table");
        System.out.println("find <value> - to check out if hash table contains <value>");
        System.out.println("rm <value> - to remove <value>");
        System.out.println("hasher <name> - to change hash function (available functions: djb2, sum)\n");
    }
}
