package testimportrubrica.io;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

/**
 *
 * @author hawake
 */
public class DataBank {
    public DataBank() {
        // Costruttore
    }
    
    public static String [] readFile(String file, int [] righe) {
        String ret[] = new String[righe.length];
        try {
            BufferedReader in = new BufferedReader(new FileReader(file));
            int j = 0;
            for (int i = 1; i <= righe[righe.length-1]; i++) {
                if ( i == righe[j] ) ret[j++] = in.readLine();
                else in.readLine();
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        return ret;
    }
    public static String inputStr() {
        try {
            BufferedReader flussoInput = new BufferedReader(new InputStreamReader(System.in));
            String stringa = flussoInput.readLine();
            return(stringa);
        } catch (Exception e) {
            System.out.println("Errore: " + e + " in input");
            System.exit(0);
            return("");
        }
    }
    public static int inputInt() {
        try {
            BufferedReader flussoInput = new BufferedReader(new InputStreamReader(System.in));
            String stringa = flussoInput.readLine();
            return (Integer.valueOf(stringa).intValue());
        } catch (Exception e) {
            System.out.println("Error: " + e + " in input");
            System.exit(0);
            return -1;
        }
    }
    
}
