library verilog;
use verilog.vl_types.all;
entity seven_seg_vlg_sample_tst is
    port(
        X               : in     vl_logic_vector(4 downto 1);
        sampler_tx      : out    vl_logic
    );
end seven_seg_vlg_sample_tst;
