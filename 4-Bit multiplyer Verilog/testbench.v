`include "4_bit_Multiplyer.v"
module test;
reg [3:0]a;
reg [3:0]b;
wire [7:0]d;
Bit_multiplyer two(a,b,d);
initial begin
    $dumpfile("testbench.vcd");
    $dumpvars(0,test);
a=4'b1011;b=4'b1001;#10;
    $display(a[3]," ",a[2]," ",a[1]," ",a[0],"    ",b[3]," ",b[2]," ",b[1]," ",b[0],"    ",d[7]," ",d[6]," ",d[5]," ",d[4]," ",d[3]," ",d[2]," ",d[1]," ",d[0]);
end
endmodule

