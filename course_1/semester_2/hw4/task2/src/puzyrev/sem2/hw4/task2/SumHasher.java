package puzyrev.sem2.hw4.task2;

/**
 * Sum hash algorithm.
 */
public class SumHasher implements Hasher {
    @Override
    public int getHash(String data, int mod) {
        long value = 5381;

        for (int i = 0; i < data.length(); i++) {
            value += data.charAt(i);
        }

        return Math.abs((int) value) % mod;
    }
}