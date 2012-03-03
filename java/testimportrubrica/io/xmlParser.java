package testimportrubrica.io;

import java.io.File;
import java.io.IOException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;

import org.w3c.dom.*;

import org.xml.sax.SAXException;

/**
 * XML parser grabbed from evilsocket's code
 * ( http://www.evilsocket.net ) and adapted by me! :-P
 * 
 * I would like to create a database from the imported address
 * book's contacts, so we have two options: XML or Derby.
 * You'll know the answer in the next episode! xD
 * 
 * @author evilsocket
 */

public class xmlParser {
    public xmlParser() { /* Costruttore */ }
    public static String getValue( Element entry, String tag ){
        NodeList tmplist  = entry.getElementsByTagName(tag);
        Element  tmpelem  = (Element)tmplist.item(0);
        NodeList tmpvalue = tmpelem.getChildNodes();

        return tmpvalue.item(0).getNodeValue();
    }
    public String getReturnValue( String file, String MainTag, String tagContent ) throws ParserConfigurationException, SAXException, IOException, Exception {
        this.filename        = file;
        this.docfactory      = DocumentBuilderFactory.newInstance();
        this.docbuilder      = this.docfactory.newDocumentBuilder();
        this.document        = this.docbuilder.parse(new File(this.filename));

        this.document.getDocumentElement().normalize();
        
        NodeList mainlist = this.document.getElementsByTagName(MainTag);
        
        for( int i = 0; i < mainlist.getLength(); i++ ){
            Element entry = (Element)mainlist.item(i);
            
            ReturnTagContent = xmlParser.getValue(entry, tagContent);
        }
        return ReturnTagContent;
    }
    
    private String                 ReturnTagContent;
    private String                 filename;
    private DocumentBuilderFactory docfactory;
    private DocumentBuilder        docbuilder;
    private Document               document;
}
