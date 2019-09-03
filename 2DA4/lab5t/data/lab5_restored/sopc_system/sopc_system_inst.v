	sopc_system u0 (
		.clk_clk           (<connected-to-clk_clk>),           //        clk.clk
		.reset_reset_n     (<connected-to-reset_reset_n>),     //      reset.reset_n
		.dram_addr_export  (<connected-to-dram_addr_export>),  //  dram_addr.export
		.dram_ba_export    (<connected-to-dram_ba_export>),    //    dram_ba.export
		.dram_cas_n_export (<connected-to-dram_cas_n_export>), // dram_cas_n.export
		.dram_cke_export   (<connected-to-dram_cke_export>),   //   dram_cke.export
		.dram_cs_n_export  (<connected-to-dram_cs_n_export>),  //  dram_cs_n.export
		.dram_dq_export    (<connected-to-dram_dq_export>),    //    dram_dq.export
		.dram_ldqm_export  (<connected-to-dram_ldqm_export>),  //  dram_ldqm.export
		.dram_ras_n_export (<connected-to-dram_ras_n_export>), // dram_ras_n.export
		.dram_udqm_export  (<connected-to-dram_udqm_export>),  //  dram_udqm.export
		.dram_we_n_export  (<connected-to-dram_we_n_export>),  //  dram_we_n.export
		.sdram_clk_clk     (<connected-to-sdram_clk_clk>)      //  sdram_clk.clk
	);

