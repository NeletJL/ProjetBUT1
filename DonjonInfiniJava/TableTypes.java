import javax.swing.*;
import javax.swing.ImageIcon;
import java.awt.*;
import java.awt.event.*;

public class TableTypes extends JFrame {

	private ImageIcon tableTypeE = new ImageIcon("./Image/TableDesTypes.png");
	private JPanel interfacePanel;
	public JLabel labelImg = new JLabel(tableTypeE);

	public TableTypes() {
		setTitle("Table des Types");
		setSize(500,350);
		setResizable(false);
		setLocation(1100,0);

		interfacePanel = new JPanel();
		interfacePanel.setBackground(Color.WHITE);
		interfacePanel.add(labelImg);

		add(interfacePanel);
		interfacePanel.setVisible(true);
	}

	public void start() {
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setVisible(true);
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			}
		});
	}
}

