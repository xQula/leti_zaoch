library verilog;
use verilog.vl_types.all;
entity lab_4_multireg_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        D               : in     vl_logic_vector(0 to 3);
        S               : in     vl_logic_vector(1 downto 0);
        sampler_tx      : out    vl_logic
    );
end lab_4_multireg_vlg_sample_tst;
