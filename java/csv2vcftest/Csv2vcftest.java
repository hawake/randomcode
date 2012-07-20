package csv2vcftest;

/**
 *
 * @author hawake
 * @version 0.1
 * 
 * Released under the terms of the GNU General Public License version 3
 */

import csv2vcftest.io.DataBank;
import java.io.*;
import java.util.*;

public class Csv2vcftest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        System.out.println("\n\nLooking for CSV files . . . ") ;
        
        // "file.csv" is the csv file with all contacts...
        lavora( args[0] ) ;
        
        // I'll use something like this to filter directories
        // in JFileChooser when i'll build the GUI...
        class JustaFilter extends javax.swing.filechooser.FileFilter {
            @Override
            public boolean accept( File file ) {
                // Allow only directories, or files with ".csv" extension
                // (comma separated text files)
                return file.isDirectory() || file.getAbsolutePath().endsWith( ".csv" ) ;
            }
            @Override
            public String getDescription() {
                // Extension description . . .
                return "CSV file (*.csv)" ;
            }
        }
    }
    
    protected static void lavora( String tf ) throws FileNotFoundException, IOException {
        File miofile = new File( tf ) ;
        FileReader fileReader = new FileReader( miofile ) ;
        BufferedReader in1 = new BufferedReader( fileReader ) ;
        
        risulto += "\n\r" ;
        
        String s ;
        
        numero_righe = 0 ;
        
        while ( ( s = in1.readLine() ) != null ) {
            if ( numero_righe > 0 ) {
                
                db = s.split( ";" ) ;
               
                creaVcf( db ) ;
                
                System.out.println( "\n\r" ) ;
            } else if ( numero_righe == 0 ) {
                titoli = s.split( ";" ) ;
            }
            numero_righe++ ;
        }
    }
    
    protected static void creaVcf( String [] record ) throws FileNotFoundException {
        dtbnk.setOutputFile( record[1] + ".vcf" );
        
        if ( record.length > 9 ) {
            name = record[1] + " " + record[3] ;
            name = name.trim() ;
            
            dtbnk.WriteLine( "BEGIN:VCARD" ) ;
            dtbnk.WriteLine( "VERSION:2.1" ) ;
            
            dtbnk.WriteLine( "N: " + record[1] + ";" + record[3] ) ;
            
            dtbnk.WriteLine( "TEL;CELL:" + record[13] ) ;
            dtbnk.WriteLine( "TEL;VOICE:" + record[14] ) ;
            dtbnk.WriteLine( "TEL;FAX:" + record[16] ) ;
            dtbnk.WriteLine( "TITLE:" + record[0] );
            dtbnk.WriteLine( "EMAIL:" + record[15] ) ;
            
            
            if ( !record[6].equals("") )
                dtbnk.WriteLine( "ORG: " + record[6] ) ;
            
            dtbnk.WriteLine( "END:VCARD" ) ;
        }
    }
    
    private static String name ;
    private static DataBank dtbnk = new DataBank() ;
    private static String [] titoli ;
    private static String [] titolitmp ;
    private static String [] db ;
    private static StringTokenizer st , st2 ;
    private static int numero_righe ;
    private static String risulto ;
    private String [] contenuto ;
}
