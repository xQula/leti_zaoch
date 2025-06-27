library verilog;
use verilog.vl_types.all;
entity lab2_vlg_check_tst is
    port(
        Qut_DC          : in     vl_logic;
        Qut_lr1         : in     vl_logic;
        Qut_MUX         : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end lab2_vlg_check_tst;
