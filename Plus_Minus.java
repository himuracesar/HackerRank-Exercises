import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
        // Write your code here
        Vector<Integer> ints = new Vector<Integer>();
        ints.add(0);
        ints.add(0);
        ints.add(0);
        
        for(int iArr = 0; iArr < arr.size(); iArr++)
        {
            if(arr.get(iArr) > 0)
                ints.set(0, ints.get(0) + 1);
            else if(arr.get(iArr) < 0)
                ints.set(1, ints.get(1) + 1);
            else if(arr.get(iArr) == 0)
                ints.set(2, ints.get(2) + 1);
        }  
        
        DecimalFormat format = new DecimalFormat();
        format.setMaximumFractionDigits(6);
        
        for(int i = 0; i < ints.size(); i++)
        {
            float ratio = ints.get(i) / (float)arr.size();
            System.out.println(format.format(ratio));
        }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}
