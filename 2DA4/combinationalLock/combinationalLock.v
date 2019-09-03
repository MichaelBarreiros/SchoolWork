module combinationalLock(X, Enter, Change, Clock, Reset, leds);
	input [3:0] X;
	input Enter, Change, Clock, Reset;
	output [1:7] leds;
	reg [3:1] y, Y;
	parameter [3:1] Default = 3'b000, New = 3'b001, Open = 3'b010, Fault = 3'b011, Alarm = 3'b100; 
	reg [4:1] combo = 4'b0110;
	wire EnterP, ChangeP, ResetP;
	
	inputConditioning (Enter, Clock, EnterP);
	inputConditioning (Change, Clock, ChangeP);
	
	
	always @(*)
	begin
		case(y)
			Default: if (EnterP)
						begin
							if(X == combo)
								Y = Open;
							else
								Y = Fault;
						end
						else if (ChangeP) 
						begin
							if (X == combo)
								Y = New;
							else
								Y = Default;
						end
						else
							Y = Default;

			Open: 	if (EnterP) 
						begin
							Y = Default;
						end
						else
							Y = Open;
						
			Fault: 	if (EnterP) 
						begin
							if (X == combo)
								Y = Open;
							else
								Y = Alarm;
						end
						else if (ChangeP) 
						begin
							if (X == combo)
								Y = New;
							else
								Y = Fault;
						end
						else
							Y = Fault;
	
			New: 		Y = New;
			
			Alarm: 	Y = Alarm;
						
			default: Y = Default;
		endcase
	end
	
	
	
	always @(posedge Clock, negedge Reset)
	begin
		if(~Reset) 
		begin
			combo = 4'b0110;
			y <= Default;
		end
		else if (y == New)
		begin
			if (EnterP)
			begin
				combo = X;
				y <= Default;
			end
			else if (ChangeP)
			begin
				combo = X;
				y <= Default;
			end
		end
		else y <= Y;
	end
	
	hex7seg hex(y,leds);
	
endmodule


