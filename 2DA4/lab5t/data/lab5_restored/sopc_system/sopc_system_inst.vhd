	component sopc_system is
		port (
			clk_clk           : in    std_logic                     := 'X';             -- clk
			reset_reset_n     : in    std_logic                     := 'X';             -- reset_n
			dram_addr_export  : out   std_logic_vector(12 downto 0);                    -- export
			dram_ba_export    : out   std_logic_vector(1 downto 0);                     -- export
			dram_cas_n_export : out   std_logic;                                        -- export
			dram_cke_export   : out   std_logic;                                        -- export
			dram_cs_n_export  : out   std_logic;                                        -- export
			dram_dq_export    : inout std_logic_vector(15 downto 0) := (others => 'X'); -- export
			dram_ldqm_export  : out   std_logic;                                        -- export
			dram_ras_n_export : out   std_logic;                                        -- export
			dram_udqm_export  : out   std_logic;                                        -- export
			dram_we_n_export  : out   std_logic;                                        -- export
			sdram_clk_clk     : out   std_logic                                         -- clk
		);
	end component sopc_system;

	u0 : component sopc_system
		port map (
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			reset_reset_n     => CONNECTED_TO_reset_reset_n,     --      reset.reset_n
			dram_addr_export  => CONNECTED_TO_dram_addr_export,  --  dram_addr.export
			dram_ba_export    => CONNECTED_TO_dram_ba_export,    --    dram_ba.export
			dram_cas_n_export => CONNECTED_TO_dram_cas_n_export, -- dram_cas_n.export
			dram_cke_export   => CONNECTED_TO_dram_cke_export,   --   dram_cke.export
			dram_cs_n_export  => CONNECTED_TO_dram_cs_n_export,  --  dram_cs_n.export
			dram_dq_export    => CONNECTED_TO_dram_dq_export,    --    dram_dq.export
			dram_ldqm_export  => CONNECTED_TO_dram_ldqm_export,  --  dram_ldqm.export
			dram_ras_n_export => CONNECTED_TO_dram_ras_n_export, -- dram_ras_n.export
			dram_udqm_export  => CONNECTED_TO_dram_udqm_export,  --  dram_udqm.export
			dram_we_n_export  => CONNECTED_TO_dram_we_n_export,  --  dram_we_n.export
			sdram_clk_clk     => CONNECTED_TO_sdram_clk_clk      --  sdram_clk.clk
		);

