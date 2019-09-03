module registerReset(D,Clock,Resetn,Q);
	input [2:0]D;
	input Clock,Resetn;
	output reg [2:0]Q;
	
	always@(posedge Clock, negedge Resetn)
		if(Resetn == 0)
			Q<= 3'b00;
		else
			Q<=D;
endmodule
