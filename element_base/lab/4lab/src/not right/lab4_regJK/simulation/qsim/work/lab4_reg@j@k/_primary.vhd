library verilog;
use verilog.vl_types.all;
entity lab4_regJK is
    port(
        Q0              : out    vl_logic;
        OE_L            : in     vl_logic;
        Set             : in     vl_logic;
        D0              : in     vl_logic;
        clk             : in     vl_logic;
        Q1              : out    vl_logic;
        D1              : in     vl_logic;
        Q2              : out    vl_logic;
        D2              : in     vl_logic;
        Q3              : out    vl_logic;
        D3              : in     vl_logic
    );
end lab4_regJK;
