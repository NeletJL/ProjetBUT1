import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

public class Controleur implements KeyListener {
	
	private Case[][] plateau;
	private VuePlateau vp;
	private int xHeros;
	private int yHeros;
	private int points;
	public int valMS = 0;

	public Controleur() {
		plateau = new Case[5][5];
		points = 0;
		for (int i = 0; i < 25; i++) {
			plateau[i%5][i/5] = Case.newCase();
		}
		xHeros=2;
		yHeros=2;
		plateau[2][2] = new Heros();
		MeilleurScore mS = new MeilleurScore();
		this.valMS = mS.readBestScore();
		vp = new VuePlateau(plateau, points, this.valMS);
	}

	public int getPoints() {
		return points;
	}

	public VuePlateau getVP() {
		return vp;
	}

	private void rencontre(int xNew,int yNew) {
		Heros h = (Heros) plateau[xHeros][yHeros];
		try {
			if (h.rencontrer(plateau[xNew][yNew])) {
				points+=plateau[xNew][yNew].getValeur();
				vp.upPoint(points);
				plateau[xNew][yNew] = h;
				plateau[xHeros][yHeros] = Case.newCase();
				vp.update(plateau[xHeros][yHeros],xHeros,yHeros);
				vp.update(plateau[xNew][yNew],xNew,yNew);
				xHeros = xNew;
				yHeros = yNew;
			} else {
				Monstre m = (Monstre) plateau[xNew][yNew];
				if (m.getPv() <= 0) {
					plateau[xNew][yNew] = new Or(m.getValeur());
					vp.update(plateau[xNew][yNew],xNew,yNew);
				}
			}
		} catch (IllegalStateException e) {
			throw e;
		}
	}

	public void end() {
		Container fenetre = this.vp.getParent();
		MeilleurScore mS = new MeilleurScore();
		while(!(fenetre instanceof JFrame)) {
			fenetre = fenetre.getParent();
		}
		((JFrame) fenetre).dispose();
		if (points > this.valMS) {
			mS.saveBestScore(points);
			this.valMS = points;
		}
		System.out.println("Score final : " + points);
		System.out.println("");
		System.out.println("Veuillez fermer manuellement la page de la Table des Types.");
		System.out.println("Merci de votre compréhension.");
	}

	public void keyPressed(KeyEvent e) {
		int touche = e.getKeyCode();
		int xNew = xHeros;
		int yNew = yHeros;
		switch(touche) {
			case KeyEvent.VK_Q :
				this.end();
				break;
			case KeyEvent.VK_LEFT :
				xNew = Math.max(0,xHeros-1);
				break;
			case KeyEvent.VK_RIGHT :
				xNew = Math.min(xHeros+1,4);
				break;
			case KeyEvent.VK_UP :
				yNew = Math.max(0,yHeros-1);
				break;
			case KeyEvent.VK_DOWN :
				yNew = Math.min(yHeros+1,4);				
				break;
			case KeyEvent.VK_E :
				TableTypes tT = new TableTypes();
				tT.start();
			default : break;
		}
		if(xHeros != xNew || yHeros != yNew) {
			try {
				this.rencontre(xNew, yNew);
			} catch (IllegalStateException ev){
		 		System.out.println("Vous etes mort !");
		 		this.end();
		 	}
		}
		vp.repaint();
	}

	public void keyReleased(KeyEvent e){}
	public void keyTyped(KeyEvent e){}

}
