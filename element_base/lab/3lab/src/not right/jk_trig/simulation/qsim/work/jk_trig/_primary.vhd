library verilog;
use verilog.vl_types.all;
entity jk_trig is
    port(
        C               : out    vl_logic;
        clk             : in     vl_logic;
        J               : out    vl_logic;
        K               : out    vl_logic;
        Q               : out    vl_logic;
        X               : out    vl_logic_vector(3 downto 0)
    );
end jk_trig;
