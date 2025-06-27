library verilog;
use verilog.vl_types.all;
entity lab_4_multireg is
    port(
        Q0              : out    vl_logic;
        clk             : in     vl_logic;
        Q1              : out    vl_logic;
        Q2              : out    vl_logic;
        Q3              : out    vl_logic;
        D               : in     vl_logic_vector(0 to 3);
        S               : in     vl_logic_vector(1 downto 0)
    );
end lab_4_multireg;
