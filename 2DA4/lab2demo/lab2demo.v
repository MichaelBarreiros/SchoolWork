module lab2demo(x3,x2,x1,x0,y3,y2,y1,y0,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2);
	input x3,x2,x1,x0,y3,y2,y1,y0;
	output a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2;
	
		hexdisp hex1(x3,x2,x1,x0,a1,b1,c1,d1,e1,f1,g1);
		name hex2(y3,y2,y1,y0,a2,b2,c2,d2,e2,f2,g2);
		
endmodule