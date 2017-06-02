package puzyrev.sem2.hw4.task2;

/**
 * Interface for different hash algorithm classes.
 */
public interface Hasher {

    /**
     * Compute hash from string.
     * @param data string which should be converted to hash
     * @param mod max allowed number
     * @return hash value
     */
    public int getHash(String data, int mod);
}