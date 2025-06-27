
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
public class MainWindow extends JFrame {
    private LineContainer lineContainer = new LineContainer();
    private MainPanel mainPanel = new MainPanel(lineContainer.getPointList()); 
    private JButton button = new JButton("Touch");
    MainWindow(){
        add(mainPanel);
        add(button);
        setTitle("lab4");
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setLocationRelativeTo(null);
        setVisible(true);
        setResizable(false);

        button.setBounds(0, 0, 100, 35);
        button.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                lineContainer.CohenSutherlandAlgorithm(mainPanel);
                mainPanel.setChecked(true);
                button.setEnabled(false);
                mainPanel.repaint();
            }
        });
    }
}
