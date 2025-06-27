library verilog;
use verilog.vl_types.all;
entity t_trig is
    port(
        Q_dlatch        : out    vl_logic;
        R               : in     vl_logic;
        T               : in     vl_logic;
        Q_dff           : out    vl_logic
    );
end t_trig;
