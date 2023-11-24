import javax.swing.*;
import java.awt.*;

public class VueCase extends JPanel {

	private Image hero = Toolkit.getDefaultToolkit().getImage("./Image/hero.png");
	private Image potion = Toolkit.getDefaultToolkit().getImage("./Image/potion.png");
	private Image or = Toolkit.getDefaultToolkit().getImage("./Image/or.png");
	private Image arme = Toolkit.getDefaultToolkit().getImage("./Image/arme.png");
	private Image mFeu = Toolkit.getDefaultToolkit().getImage("./Image/mFeu.png");
	private Image mVent = Toolkit.getDefaultToolkit().getImage("./Image/mVent.png");
	private Image mFoudre = Toolkit.getDefaultToolkit().getImage("./Image/mFoudre.png");
	private Image mTerre = Toolkit.getDefaultToolkit().getImage("./Image/mTerre.png");
	private Image mEau = Toolkit.getDefaultToolkit().getImage("./Image/mEau.png");
	private Image mLum = Toolkit.getDefaultToolkit().getImage("./Image/mLum.png");
	private Image mTen = Toolkit.getDefaultToolkit().getImage("./Image/mTen.png");
	private Image roueElement = Toolkit.getDefaultToolkit().getImage("./Image/elements.png");
	private Image LumTen = Toolkit.getDefaultToolkit().getImage("./Image/lum_ten.png");
	private Image carotte = Toolkit.getDefaultToolkit().getImage("./Image/Carotte.png");
	private Image hache = Toolkit.getDefaultToolkit().getImage("./Image/Hache.png");
	private Case c;

	public VueCase(Case cas) {
		super();
		this.c = cas;
		this.setLayout(new BorderLayout());
		Dimension d = new Dimension(150,150);
		this.setPreferredSize(d);
	}

	public void setCase(Case cas) {
		this.c = cas;
	}

	@Override
	public void paintComponent(Graphics pin) {
		Graphics p = pin.create();
		if (c instanceof Heros){
			p.drawImage(hero,0,0,null);
			repaint();
		}
		if (c instanceof Or) {
			p.drawImage(or,0,0,null);
			repaint();
		}
		if (c instanceof Monstre) {
			Monstre m = (Monstre) c;
			String typeM = m.getType();
			switch (typeM) {
				case "Feu" :
					p.drawImage(mFeu,0,0,null);
					repaint();
					break;
				case "Vent" :
					p.drawImage(mVent,0,0,null);
					repaint();
					break;
				case "Foudre" :
					p.drawImage(mFoudre,0,0,null);
					repaint();
					break;
				case "Terre" :
					p.drawImage(mTerre,0,0,null);
					repaint();
					break;
				case "Eau" :
					p.drawImage(mEau,0,0,null);
					repaint();
					break;
				case "Lumière" :
					p.drawImage(mLum,0,0,null);
					repaint();
					break;
				case "Ténèbres" :
					p.drawImage(mTen,0,0,null);
					repaint();
					break;
			}
		}
		if (c instanceof Arme) {
			Arme a = (Arme) c;
			if (a.getLabel() == "Arme") {
				p.drawImage(arme,0,0,null);
				repaint();
			} else if (a.getLabel() == "Carotte") {
				p.drawImage(carotte,0,0,null);
				repaint();
			} else if (a.getLabel() == "Hache") {
				p.drawImage(hache,0,0,null);
				repaint();
			}
		}
		if (c instanceof Potion) {
			p.drawImage(potion,0,0,null);
			repaint();
		}
		p.setColor(Color.black);
		Font f = new Font("Times new roman",Font.BOLD,16);
		p.setFont(f);
		Font m = new Font("Times new roman",Font.BOLD,12);
		String pv = this.c.getLabelPv();

		if(pv != null) {
			if (!(c instanceof Heros)) {
				p.drawString("HP: " + pv,50, 30);
			}
		}
		String val = this.c.getLabelValeur();
		String type = this.c.getLabel();
		if (c instanceof Heros) {
			p.drawString(type,75,20);
			p.drawString("HP: " + pv,10,20);
		}

		if (val != null) {
			if (c instanceof Heros) {
				Heros herosTemp = (Heros) c;
				p.drawString("Dura: " + herosTemp.wp.dura,10,140);
				p.drawString("Deg: " + val,85,140);
				if (herosTemp.getNomArme() == "Carotte") {
					p.setFont(m);
					p.setColor(Color.ORANGE);
					p.drawString("Carotte",3,100);
				} else if (herosTemp.getNomArme() == "Hache") {
					p.setFont(m);
					p.setColor(Color.MAGENTA);
					p.drawString("Hache",3,100);
				} else if (herosTemp.getNomArme() == "Arme") {
					p.setFont(m);
					p.drawString("Arme",3,100);
				}
			} else if (c instanceof Arme) {
				Arme armeTemp = (Arme) c;
				p.drawString("Dura: " + armeTemp.dura,10,140);
				p.drawString("Deg: " + val,85,140);
			} else if (c instanceof Potion) {
				Potion potionTemp = (Potion) c;
				p.drawString("HP: " + val,50,15);
			} else if (c instanceof Or) {
				Or orTemp = (Or) c;
				p.drawString("Or: " + val,50,20);
			}
		}		
	}	

}
