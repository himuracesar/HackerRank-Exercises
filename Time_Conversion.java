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
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String s) {
        // Write your code here
        String hour = s.substring(0, 2);
        String mins = s.substring(3, 5);
        String segs = s.substring(6, 8);
        String ma = s.substring(8, 10);
        String milHour = "";
        
        ///System.out.println(hour + ":" + mins + ":" + segs + ma);
        
        int iHour = Integer.parseInt(hour);
        if("AM".equals(ma))
            milHour = (iHour == 12) ? "00" : hour;
        else
            milHour = (iHour == 12) ? hour : Integer.toString(iHour + 12);
        
        return milHour + ":" + mins + ":" + segs;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
