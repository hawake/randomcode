package csv2vcftest.io;

/**
 *
 * @author hawake
 * @version 0.2
 * 
 * Released under the terms of the GNU General Public License version 3
 */

import java.io.*;

public class DataBank {
    public DataBank() {
        // Costruttore
        output_file = "default" ;
    }
    public void setOutputFile ( String outf ) {
       this.output_file = outf ;
    }
    public String getOutputFile () {
        return output_file ;
    }
    public static synchronized boolean WriteLine( String line ) {
		try {
			File f = new File(output_file);
			FileOutputStream fos = new FileOutputStream(f,true);
			PrintStream ps = new PrintStream(fos);
                        ps.println( line ) ;
		} catch (IOException err) {
			System.out.println("Error in Input/Output: " + err);
		}
		return true;
    }
    public static synchronized boolean WriteLine(String out_file , String line) {
		try {
			File f = new File(out_file);
			FileOutputStream fos = new FileOutputStream(f,true);
			PrintStream ps = new PrintStream(fos);
                        ps.println("" + line);
		} catch (IOException err) {
			System.out.println("Error in Input/Output: " + err);
		}
		return true;
    }
    public static String [] readFile( int [] righe ) {
        String ret[] = new String[righe.length];
        try {
            BufferedReader in = new BufferedReader(new FileReader(output_file));
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
    
    public static String [] readFile(String out_file, int [] righe) {
        String ret[] = new String[righe.length];
        try {
            BufferedReader in = new BufferedReader(new FileReader(out_file));
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
    private static String output_file ;
}
