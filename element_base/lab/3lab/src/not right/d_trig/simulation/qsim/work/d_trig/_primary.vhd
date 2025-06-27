library verilog;
use verilog.vl_types.all;
entity d_trig is
    port(
        C               : out    vl_logic;
        clk             : in     vl_logic;
        D               : out    vl_logic;
        Q_dlanch        : out    vl_logic;
        Q_dff           : out    vl_logic;
        X               : out    vl_logic_vector(3 downto 0)
    );
end d_trig;
