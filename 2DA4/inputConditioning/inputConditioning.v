module inputConditioning(a, Clock, A_pulse);
	input a, Clock;
	output reg A_pulse;
	reg [2:1] y, Y;
	parameter [2:1] A = 2'b00, B = 2'b01, C = 2'b10;
	
	//Define the next state and output combinational circuits
	always @(a,y)
	begin 
		case(y)
			A: if (~a) Y = B;
				else Y = A;
			B: if (~a) Y = C;
				else Y = A;
			C: if (~a) Y = C;
				else Y = A;
		endcase
	
		A_pulse = (y == B);
	end
	
	//Define the sequential block
	always@(posedge Clock)
		y <= Y;
	
endmodule
