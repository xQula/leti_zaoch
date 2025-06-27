library verilog;
use verilog.vl_types.all;
entity seven_seg is
    port(
        D0              : out    vl_logic;
        X               : in     vl_logic_vector(4 downto 1);
        D1              : out    vl_logic;
        D2              : out    vl_logic;
        D3              : out    vl_logic;
        D4              : out    vl_logic;
        D5              : out    vl_logic;
        D6              : out    vl_logic;
        DP              : out    vl_logic
    );
end seven_seg;
