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
     * Complete the 'isBalanced' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String isBalanced(String s) {
        // Write your code here
        String r = "YES";
        
        Vector<Character> openBrackets = new Vector<Character>();
        
        for(int index = 0; index < s.length(); index++)
        {
            if(s.charAt(index) == '(' || 
               s.charAt(index) == '{' || 
               s.charAt(index) == '[')
            {
                openBrackets.add(s.charAt(index)); 
            }
            else
            {
                switch(s.charAt(index))
                {
                    case ')' : 
                        if(openBrackets.size() > 0 && openBrackets.lastElement() == '(')
                        {
                            openBrackets.remove(openBrackets.size() - 1);
                        }
                        else
                        {
                            return "NO";
                        }
                    break;
                    case '}' : 
                        if(openBrackets.size() > 0 && openBrackets.lastElement() == '{')
                        {
                            openBrackets.remove(openBrackets.size() - 1);
                        }
                        else
                        {
                            return "NO";
                        }
                    break;
                    case ']' : 
                        if(openBrackets.size() > 0 && openBrackets.lastElement() == '[')
                        {
                            openBrackets.remove(openBrackets.size() - 1);
                        }
                        else
                        {
                            return "NO";
                        }
                    break;
                    default: continue;
                }
            }
        }
        
        if(openBrackets.size() > 0)
            r = "NO";
        
        return r;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, t).forEach(tItr -> {
            try {
                String s = bufferedReader.readLine();

                String result = Result.isBalanced(s);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
