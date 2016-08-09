import java.util.HashMap;

/**
 * Created by musteryu on 16/4/29.
 */
public class HashMapTester {
    public static class StringTuple {
        private int hash;
        public StringTuple(String s1, String s2) {
            hash = s1.hashCode() * s2.hashCode();
        }

        @Override
        public int hashCode() {
            return hash;
        }
    }
    HashMap<StringTuple, Boolean> map = new HashMap();
    public void test() {
        map.put(new StringTuple("a", "b"), true);
        System.out.print(map.get(new StringTuple("a", "b")));
    }

    public static void main(String[] args) {
        System.out.println(new StringTuple("a", "b").hashCode());
        System.out.println(new StringTuple("a", "b").hashCode());
        new HashMapTester().test();
    }
}
