library verilog;
use verilog.vl_types.all;
entity jk_trig_vlg_check_tst is
    port(
        C               : in     vl_logic;
        J               : in     vl_logic;
        K               : in     vl_logic;
        Q               : in     vl_logic;
        QQ              : in     vl_logic;
        X               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end jk_trig_vlg_check_tst;
