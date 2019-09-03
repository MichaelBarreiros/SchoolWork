module hex7seg(x,leds);

	input [2:0]x;
	output reg [1:7]leds;
	always @(x)
	begin
		case (x) //abcdefg
			0: leds = 7'b1111110; //'-'
			1: leds = 7'b1101010; //'n'
			2: leds = 7'b0000001; //'O'
			3: leds = 7'b1111110; //'-'
			4: leds = 7'b0001000; //'A'
			default: leds = 7'b1111110; //'-'
		endcase
	end

endmodule
