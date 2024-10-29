module full_adder(a,b,Cin,sum,carry);
output sum,carry;
input a,b, Cin;
assign sum = (a^b)^Cin;
assign carry = (a&b)|((a^b)&Cin);
endmodule;