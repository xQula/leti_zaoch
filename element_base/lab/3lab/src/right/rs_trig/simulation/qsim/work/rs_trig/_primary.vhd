library verilog;
use verilog.vl_types.all;
entity rs_trig is
    port(
        Q_rs            : out    vl_logic;
        clk             : in     vl_logic;
        PRN             : out    vl_logic;
        CLRN            : out    vl_logic;
        S               : out    vl_logic;
        R               : out    vl_logic;
        C               : out    vl_logic;
        X               : out    vl_logic_vector(3 downto 0)
    );
end rs_trig;
