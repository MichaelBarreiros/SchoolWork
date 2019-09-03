module register(D,Clock,Q);
	input [2:0]D;
	input Clock;
	output reg [2:0]Q;
	
	always@(posedge Clock)
			Q<=D;
			
endmodule
