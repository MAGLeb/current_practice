import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*; 

public class Main {
  /**
   * Iterate through each line of input.
   */
    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(reader);
        String line;
        while ((line = in.readLine()) != null) {
            Main.matchBenchmark(line);
        }
    }
  
    public static class CustomMap {
      
        private Map<String, Integer> currentMap = new HashMap<String, Integer>();
      
        public CustomMap(String inputString) {
            String[] stringArray = inputString.split("\\|", 0);
          
            if (stringArray.length > 1) {
                for (String string : stringArray) {
                    String[] splittedString = string.split(",", 0);
                    String company = splittedString[0];
                    String command = splittedString[1];
                    String value = splittedString[2];
                    Integer intValue = Integer.parseInt(value);
                    
                    this.put(company + "," + command, intValue);
                }
            }
        }
        
        public Set<String> keySet() {
            return currentMap.keySet();
        }
        
        public Integer get(String key) {
            return currentMap.get(key);
        }
        
        public void put(String key, Integer value) {
            currentMap.put(key, value);
        }
        
        public CustomMap findDiff(CustomMap expectedMap) {
            CustomMap resultMap = new CustomMap("");
            
            for (String key : expectedMap.keySet())  {
                Integer currentValue = 0;
                Integer expectedValue = expectedMap.get(key);
                
                if (currentMap.containsKey(key)) {
                    currentValue = currentMap.get(key); 
                }
                
                resultMap.put(key, currentValue - expectedValue);
            }
            
            return resultMap;
        }
        
        public void print() {
            ArrayList<String> sortedKeys = new ArrayList<String>(currentMap.keySet()); 
          
            Collections.sort(sortedKeys);
        
            for (String key : sortedKeys) {
                Integer value = currentMap.get(key);
                
                if (value < 0) {
                    String result = "BUY," + key + ',' + Integer.toString(Math.abs(value));
                    System.out.println(result);
                } else if (value > 0) {
                    String result = "SELL," + key + ',' + Integer.toString(Math.abs(value));
                    System.out.println(result);
                }
            }
        }
        
        
    }
  
    public static void matchBenchmark(String input) {
        String[] arrOfStr = input.split(":", 0);
        String currentString = arrOfStr[0];
        String expectedString = arrOfStr[1];
        
        CustomMap current = new CustomMap(currentString);
        CustomMap expected = new CustomMap(expectedString);
            
        CustomMap result = current.findDiff(expected);
        result.print();
    }
}
