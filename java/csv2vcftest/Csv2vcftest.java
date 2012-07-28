package csv2vcftest;

/**
 *
 * @author hawake
 * @version 0.2
 * 
 * Released under the terms of the GNU General Public License version 3
 */

import java.io.*;

public class Csv2vcftest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        System.out.print("\n\nStarting GUI . . . " ) ;
        
        (new mainFrame()).setVisible(true);
        
        System.out.println( "OK!" ) ;
    }
}