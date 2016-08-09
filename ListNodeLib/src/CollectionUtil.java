import java.util.Collections;

/**
 * Created by musteryu on 16/5/1.
 */
public class CollectionUtil {
    public static <T> void printIterable(Iterable<T> iterable, String div) {
        boolean first = true;
        for (T i: iterable) {
            if (first) {
                System.out.print(i);
                first = false;
            } else {
                System.out.print(div+i);
            }
        }
    }
    public static <T> void printArray(T[] a, String div) {
        boolean first = true;
        for (T i: a) {
            if (first) {
                System.out.print(i);
                first = false;
            } else {
                System.out.print(div+i);
            }
        }
    }
}
