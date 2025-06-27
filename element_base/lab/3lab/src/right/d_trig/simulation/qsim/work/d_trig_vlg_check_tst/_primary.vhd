library verilog;
use verilog.vl_types.all;
entity d_trig_vlg_check_tst is
    port(
        C               : in     vl_logic;
        D               : in     vl_logic;
        Q_dff           : in     vl_logic;
        Q_dlanch        : in     vl_logic;
        X               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end d_trig_vlg_check_tst;
