
module sopc_system (
	clk_clk,
	reset_reset_n,
	dram_addr_export,
	dram_ba_export,
	dram_cas_n_export,
	dram_cke_export,
	dram_cs_n_export,
	dram_dq_export,
	dram_ldqm_export,
	dram_ras_n_export,
	dram_udqm_export,
	dram_we_n_export,
	sdram_clk_clk);	

	input		clk_clk;
	input		reset_reset_n;
	output	[12:0]	dram_addr_export;
	output	[1:0]	dram_ba_export;
	output		dram_cas_n_export;
	output		dram_cke_export;
	output		dram_cs_n_export;
	inout	[15:0]	dram_dq_export;
	output		dram_ldqm_export;
	output		dram_ras_n_export;
	output		dram_udqm_export;
	output		dram_we_n_export;
	output		sdram_clk_clk;
endmodule
