module name(x3,x2,x1,x0,a,b,c,d,e,f,g);
	input x3,x2,x1,x0;
	output a,b,c,d,e,f,g;
	
	assign a = (x2 | ~x0) & (~x2 | ~x1);
	assign b = (x2 | x1 | ~x0) & (~x3);
	assign c = (~x2 & x1) | (x1 & x0);
	assign d = (x3 | x2 | x1 | x0) & (~x2 | ~x0) & (~x1 | ~x0) & (~x2 | ~x1); 
	assign e = (~x3 & x2 & ~x0);
	assign f = (~x3 & x2 & ~x1) | (~x2 & x1 & ~x0);
	assign g = (x2 & ~x1 & ~x0) | (x2 & x1 & x0);
	
endmodule
