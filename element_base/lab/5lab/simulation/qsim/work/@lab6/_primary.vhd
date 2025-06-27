library verilog;
use verilog.vl_types.all;
entity Lab6 is
    port(
        D2              : out    vl_logic;
        R               : in     vl_logic;
        C               : in     vl_logic;
        D4              : out    vl_logic;
        D0              : out    vl_logic;
        D6              : out    vl_logic;
        D1              : out    vl_logic;
        D3              : out    vl_logic;
        D5              : out    vl_logic;
        Test            : out    vl_logic_vector(3 downto 0)
    );
end Lab6;
