import javax.swing.*;

public class DonjonInfini {

	public static void main(String[] args) {

	    Controleur c = new Controleur();
	    JFrame donjon = new JFrame("Donjon Infini");

        donjon.setLocation(50,0);
        donjon.setSize(1000,1000);
        donjon.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
        donjon.add(c.getVP());
        donjon.addKeyListener(c);

        donjon.setVisible(true);
        
    }

}
