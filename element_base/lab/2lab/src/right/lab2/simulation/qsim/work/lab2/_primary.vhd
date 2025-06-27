library verilog;
use verilog.vl_types.all;
entity lab2 is
    port(
        Qut_DC          : out    vl_logic;
        X               : in     vl_logic_vector(4 downto 1);
        Qut_lr1         : out    vl_logic;
        Qut_MUX         : out    vl_logic
    );
end lab2;
