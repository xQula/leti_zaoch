library verilog;
use verilog.vl_types.all;
entity t_trig_vlg_check_tst is
    port(
        Q_dff           : in     vl_logic;
        Q_dlatch        : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end t_trig_vlg_check_tst;
