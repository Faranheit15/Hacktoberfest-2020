// The program draws and house with a small animation of the car moving.

import java.awt.*;
import java.applet.*;

public class House extends Applet{
	
	private static final long serialVersionUID = 1L;

	public void paint(Graphics g){
		//road
		g.setColor(Color.black);
		g.fillRect(0, 500, 1500, 100);
		g.setColor(Color.yellow);
		for(int i=0; i<1500; i+=100){
			g.fillRect(i, 550, 50, 5);
		}
		//tree
		g.setColor(Color.black);
		g.fillRect(300, 400, 20, 100);
		g.setColor(Color.green);
		g.fillArc(260,300,100,100,0,360);
		//house
		g.setColor(Color.orange);
		g.fillRect(900, 350, 150, 150);
		int[] x={900,1050,975};
		int[] y={350,350,275};
		Polygon p=new Polygon(x,y,3);
		g.fillPolygon(p);
		g.setColor(Color.blue);
		g.fillRect(910, 360, 50, 50);
		g.fillRect(990, 360, 50, 50);
		g.fillRect(950, 430, 50, 70);
		//fence
		g.setColor(Color.red);
		for(int i=885;i<1065;i+=40){
			int[] a = {i,i,i+15,i+30,i+30};
			int[] b = {500,475,465,475,500};
			Polygon f = new Polygon(a,b,5);
			g.fillPolygon(f);
		}
		//flower
		g.setColor(Color.green);
		g.fillRect(200, 450, 10, 50);
		g.setColor(Color.red);
		g.fillOval(195, 400, 20, 20);
		g.fillOval(215, 410, 20, 20);
		g.fillOval(215, 430, 20, 20);
		g.fillOval(195, 440, 20, 20);
		g.fillOval(175, 430, 20, 20);
		g.fillOval(175, 410, 20, 20);
		g.setColor(Color.yellow);
		g.fillOval(195, 420, 20, 20);
		
		//sun
		g.setColor(Color.yellow);
		g.fillArc(50,50,100,100,0,360);
		//animation
		//animation
		//animation
		g.setColor(Color.red);
		int x1=0,x2=500,x3=50,x4=30;
		for(int i=0; i<100; i++){
			g.fillRect(x1, x2, x3, x4);
			x1+=5;
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	
	}
}
