library verilog;
use verilog.vl_types.all;
entity t_trig_vlg_sample_tst is
    port(
        R               : in     vl_logic;
        T               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end t_trig_vlg_sample_tst;
