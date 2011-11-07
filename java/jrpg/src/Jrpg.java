package jrpg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author hawake
 * @version version
 */
public class Jrpg {

    /**
     * @param args the command line arguments
     */
    public static void main( String[] args ) {
        if ( args.length != 0 ) {
            System.out.println( "\r\n\t ---> JAVA RANDOM PASSWORD GENERATOR <---\r\n" );
            System.out.println( "\t\tversion:" + version + "\n\t\tby hawake\n\n" );
            
            for ( int i = 0 ; i<args.length ; i++ ) {
                if ( args[i].equalsIgnoreCase( "-an" ) ) {
                    System.out.println( pwdElaborate( "-an" ) +"\r\n" );
                } else if ( args[i].equalsIgnoreCase( "-a" ) ){
                    System.out.println( pwdElaborate( "-a" ) +"\r\n" );
                } else if ( args[i].equalsIgnoreCase( "-n" ) ) {
                    System.out.println( pwdElaborate( "-n" ) + "\r\n" ); 
                } else if ( args[i].equalsIgnoreCase( "-ans" ) ) {
                    System.out.println( pwdElaborate( "-ans" ) + "\r\n" );
                } else {
                    help();
                }
            }
        } else
            help();
        System.exit(0);
    }
    
    // Help function
    protected static void help() {
        System.out.println( "\n\n\t [ JAVA RANDOM PASSWORD GENERATOR ] \n" );
        System.out.println( "\t\tversion: " + version + "\n\t\tby hawake\n\tReleased under the terms of GNU General Public License version 3.\n\n" );
        System.out.println( "\nUSAGE: java jrpg [command]" );
        System.out.println( "\nHELP: command | description\n" );
        System.out.println( "\t-a   | Generates an alfabetic password;" );
        System.out.println( "\t-n   | Generates a numeric password;" );
        System.out.println( "\t-an  | Generates an alfanumeric password;" );
        System.out.println( "\t-ans | Generates an alfanumeric password within ASCII symbols;\n\n");
    }
    
    // Password generation function. It uses a different
    // charset per ARGS parameter
    protected static String pwdElaborate( String p ){
        String[] words;
        String   answer;
        int      numLenght = 10;
        
        if ( p.equals( "-an" ) ) {
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
            numLenght = 62;
        } else if ( p.equals( "-a" ) ) {
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            numLenght = 52;
        } else if ( p.equals( "-n" ) ) {
            charset = "1234567890";
            numLenght = 10;
        } else if ( p.equals( "-ans" ) ) {
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!£()*+@#[]£$%&/=?^'|";
            numLenght = 82;
        }
        
        System.out.print( "Please insert the length of the password: " );
        n = inputInt();
        words = new String[n];
        System.out.println( "\n" );
            
        if (n > 25) {
            System.out.println( "Warning: as the password is longer, it uses more system resources!" );
            System.out.print( "Do you want to continue? " );
            
            answer = inputStr();
            
            System.out.println( "\r\n" );
            
            if ( answer.equals( "yes") || answer.equals( "y" ) ) {
                for( int j = 0 ; j < n ; j++ ){
                    int a = (int)( Math.random() * numLenght );
                    words[j] = charset.substring( a, a + 1 );
                    buffer += words[j];
                }
            } else 
                buffer = "\r\nError: too many characters!\r\n";
        }
        else {
            for( int j = 0 ; j < n ; j++ ) {
                int a = (int)( Math.random() * numLenght );
                words[j] = charset.substring( a, a + 1 );
                buffer += words[j];
            }
        }
        
        return buffer;
    }
    
    protected static int inputInt() {
        try {
            BufferedReader flussoInput = new BufferedReader( new InputStreamReader( System.in ) );
            String stringa = flussoInput.readLine();
            return ( Integer.valueOf( stringa ).intValue() );
        } catch ( IOException e ) {
            System.out.println( "Error: " + e + " in input" );
            System.exit( 0 );
            return -1;
        }
    }
    
    protected static String inputStr() {
        try {
            BufferedReader flussoInput = new BufferedReader( new InputStreamReader( System.in ) );
            String stringa = flussoInput.readLine();
            return( stringa );
        } catch ( IOException e ) {
            System.out.println( "Error: " + e + " in input" );
            System.exit(0);
            return( "");
        }
    }
    
    protected static int          n;
    protected static String       buffer  = "";
    protected static String       charset = "";
    protected static final String version = "1.2.1";
}
