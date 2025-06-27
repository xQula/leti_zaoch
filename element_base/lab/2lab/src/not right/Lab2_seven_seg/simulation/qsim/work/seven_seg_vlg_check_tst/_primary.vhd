library verilog;
use verilog.vl_types.all;
entity seven_seg_vlg_check_tst is
    port(
        D0              : in     vl_logic;
        D1              : in     vl_logic;
        D2              : in     vl_logic;
        D3              : in     vl_logic;
        D4              : in     vl_logic;
        D5              : in     vl_logic;
        D6              : in     vl_logic;
        DP              : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end seven_seg_vlg_check_tst;
