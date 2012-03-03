package testimportrubrica;

import javax.swing.JOptionPane;

/**
 *
 * @author hawake
 * @version 0.1
 * 
 * Just a simple tool meant to replace Nokia PC Suite's address book so
 * that you can import contacts just analyzing VCF files. This code is 
 * just a concept and needs to be cleaned.
 * 
 * IDE used: Netbeans 7.0.1
 */
public class TestImportRubrica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            (new mainFrame()).setVisible(true);
        }
        catch( Exception ex ) {
            JOptionPane.showMessageDialog( 
                    null,
                    "Error: an exception has been caught!\nDetails:\n" + ex.getMessage()
                    );
        }
    }
}
