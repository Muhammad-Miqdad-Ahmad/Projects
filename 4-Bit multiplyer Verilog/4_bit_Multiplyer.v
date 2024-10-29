`include "full_adder.v"
`include "half_adder.v"

module Bit_multiplyer(A, B, P);

input [3:0]A;
input [3:0]B;
output [7:0]P;
wire and2, and3, and4, and5, and6, and7, and8, and9, and10, and11, and12, and13, and14, and15, and16, carry1, sum2, carry2, sum3, carry3, sum4, carry4, carry5, sum6, carry6, sum7, carry7, sum8, carry8, carry9, carry10, carry11;
assign P[0]=B[0] & A[0];

assign and2=B[0] & A[1];
assign and5=B[1] & A[0];
half_adder h1(and2,and5,P[1],carry1);

assign and3=B[0] & A[2];
assign and6=B[1] & A[1];
full_adder f1(and3,and6,carry1,sum2, carry2);

assign and4=B[0] & A[3];
assign and7=B[1] & A[2];
full_adder f2(and4,and7,carry2,sum3, carry3);

assign and8=B[1] & A[3];
half_adder h2(and8,carry3,sum4, carry4);

assign and9=B[2] & A[0];
half_adder h3(and9,sum2,P[2],carry5);

assign and10=B[2] & A[1];
full_adder f3(and10, sum3, carry5, sum6, carry6);

assign and11=B[2] & A[2];
full_adder f4(and11, sum4, carry6, sum7, carry7);

assign and12=B[2] & A[3];
full_adder f5(and12, carry4, carry7, sum8, carry8);

assign and13=B[3] & A[0];
half_adder h4(and13, sum6, P[3], carry9);

assign and14=B[3] & A[1];
full_adder f6(and14, sum7, carry9, P[4], carry10);

assign and15=B[3] & A[2];
full_adder f7(and15, sum8, carry10, P[5], carry11);

assign and16=B[3] & A[3];
full_adder f8(and16, carry8, carry11, P[6], P[7]);
endmodule