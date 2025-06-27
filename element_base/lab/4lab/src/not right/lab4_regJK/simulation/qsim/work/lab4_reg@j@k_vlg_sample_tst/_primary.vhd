library verilog;
use verilog.vl_types.all;
entity lab4_regJK_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        D0              : in     vl_logic;
        D1              : in     vl_logic;
        D2              : in     vl_logic;
        D3              : in     vl_logic;
        OE_L            : in     vl_logic;
        Set             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end lab4_regJK_vlg_sample_tst;
