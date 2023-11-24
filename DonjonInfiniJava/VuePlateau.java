import javax.swing.*;
import java.awt.*;

public class VuePlateau extends JPanel {

	VueCase[][] cases;
	int vpoint;
	private Case c;

	public VuePlateau(Case[][] pl,int points, int mS) {
		super();
		this.setLayout(new BorderLayout());
		JPanel jp = new JPanel();
		GridLayout g = new GridLayout(5,5);
		jp.setLayout(g);

		Dimension d = new Dimension(500,700);
		vpoint = points;
		cases = new VueCase[5][5];

		for(int i = 0; i < 25; i++){
			cases[i%5][i/5] = new VueCase(pl[i%5][i/5]);
			jp.add(cases[i%5][i/5]);
		}
		JPanel scoreboard = new JPanel();
		Dimension d2 = new Dimension(500,100);
		scoreboard.setPreferredSize(d2);
		scoreboard.setOpaque(false);

		jp.setBackground(Color.darkGray);
		this.add(scoreboard,BorderLayout.NORTH);
		this.add(jp,BorderLayout.CENTER);
	}
	
	public void upPoint(int p) {
		vpoint = p;
	}
	public void update(Case nc,int x,int y) {
		cases[x][y].setCase(nc);
	}

	@Override
	public void paintComponent(Graphics pin) {
		Graphics p = pin.create();
		p.setColor(Color.darkGray);
		p.fillRect(0,0,this.getWidth(),this.getHeight());
		
		MeilleurScore mS = new MeilleurScore();
		String s = "Score : " + vpoint;
		String best = "Meilleur score : " + mS.readBestScore();
		String table = "Table des Types : E";
				
		p.setColor(Color.black);
		Font f=new Font("Times new roman",Font.BOLD,20);

		p.setFont(f);
		p.drawString(s,50,50);
		p.drawString(best,50,70);
		p.drawString(table,750,50);

		for(int i=0;i<9;i++){
			cases[i/3][i%3].repaint();
		}
	}
}
