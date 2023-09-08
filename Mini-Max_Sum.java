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
     * Complete the 'miniMaxSum' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void miniMaxSum(List<Integer> arr) {
        // Write your code here
        List<Long> sums = new ArrayList<Long>();
        long min = Long.MAX_VALUE;
        long max = Long.MIN_VALUE;
        
        for(int i = 0; i < arr.size(); i++)
        {
            long sum = 0;
            for(int index = 0; index < arr.size(); index++)
            {
                if(index != i)
                    sum += arr.get(index);
                    
                //System.out.println("index:: " + index + " --Sum:: " + sum);
            }
            //System.out.println("--Sum:: " + sum);
            sums.add(sum);
        }
        
        for(int iSum = 0; iSum < sums.size(); iSum++)
        {
            min = Long.min(min, sums.get(iSum));
            max = Long.max(max, sums.get(iSum));
            //System.out.println("Sum:: " + sums.get(iSum));
        }
        
        System.out.print(min + " " + max);
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.miniMaxSum(arr);

        bufferedReader.close();
    }
}
