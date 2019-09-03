module ripple(x,y,z);
	input [2:0]x,y;
	output [3:0]z;
	wire [2:1]c;
	
	fulladder stage0(0,x[0],y[0],z[0],c[1]);
	fulladder stage1(c[1],x[1],y[1],z[1],c[2]);
	fulladder stage2(c[2],x[2],y[2],z[2],z[3]);

endmodule

module fulladder(Cin, x, y, s, Cout);
	input Cin, x, y;
	output s, Cout;
	wire z1,z2,z3,z4;
	
	and (z1,x,y);
	and (z2,x,Cin);
	and (z3,y,Cin);
	or (Cout,z1,z2,z3);
	xor (z4,x,y);
	xor (s,z4,Cin);
	
endmodule