{
	TFile * f = TFile::Open("/Disk/speyside8/lhcb/gcowan1/MC2012_sim08e_Bs2JpsiPhi_minimal_truth_with_IPz_weights.root");
	TTree * ft = (TTree*)f->Get("DecayTree");
	TFile * g = TFile::Open("../../fits/4D/XMLFOLDER/new/sim08e/test_DG_neq_0.root");
	TTree * gt = (TTree*)g->Get("dataNTuple");

	const int b = 30;
	const int nbins = 5;
	double bins[nbins+1];
	const double t_min(0.3);
	const double t_max(14.);
	const double tau_PDG(1.5);
	double A(TMath::Exp(-t_max/tau_PDG));
	double B(TMath::Exp(-t_min/tau_PDG));
	bins[0] = t_min;
	bins[nbins] = t_max;
	for(int i(1); i < nbins; i++){
		bins[i] = -TMath::Log(((double)i*(A-B)/(double)nbins+B))*tau_PDG;
	}

	for (int i = 0; i < nbins + 1; i++) cout << bins[i] << endl;

	TH1D * fh = new TH1D("time_detached","time_detached", b, -1., 1.);
	TH1D * gh = new TH1D("time_unbiased","time_unbiased", b, -1., 1.);
	TH1D * rh = new TH1D("time_acc", "time_acc", b, -1., 1.);
	fh->Sumw2();
	gh->Sumw2();
	rh->Sumw2();

	TString detached = "(30. > TMath::Abs(phi_1020_M - 1020.)) && (16. > phi_1020_ENDVERTEX_CHI2/phi_1020_ENDVERTEX_NDOF) && (0.12 > B_s0_LOKI_DTF_CTAUERR/0.299792458) && (B_s0_LOKI_DTF_CHI2NDOF > 0) && (B_s0_LOKI_DTF_VCHI2NDOF > 0) && (5. > B_s0_LOKI_DTF_CHI2NDOF) && (10. > B_s0_ENDVERTEX_CHI2/B_s0_ENDVERTEX_NDOF) && (25. > B_s0_IPCHI2_OWNPV) && (B_s0_MINIPCHI2NEXTBEST > 50 || 0 > B_s0_MINIPCHI2NEXTBEST) && (60 > TMath::Abs(J_psi_1S_MM - 3090))&& (Kplus_PIDK > 0.) && (Kminus_PIDK > 0.)&&(B_s0_Hlt1DiMuonHighMassDecision_TOS==1) && (B_s0_Hlt2DiMuonDetachedJPsiDecision_TOS==1)";

	gt->Draw("helcosthetaL>>time_unbiased", "", "goff");
	TCanvas * d3 = new TCanvas();
	d3->Divide(2,3);
	for (int i = 0; i < nbins; i++)
	{
		d3->cd(i+1);
		TString cut = detached + "&&B_s0_TRUETAU*1000.>" + Form("%g", bins[i]) + "&&B_s0_TRUETAU*1000.<" + Form("%g",bins[i+1]);
		std::cout << cut << std::endl;

		ft->Draw("helcosthetaL>>time_detached", cut, "goff");
		rh->Divide(fh, gh, 1, 1, "b");

		rh->SetMarkerColor(i+1);
		rh->SetLineColor(i+1);
		rh->Draw();	
      
		rh->GetXaxis()->SetTitle("cos#theta_{K}");
        	rh->GetYaxis()->SetTitle("Efficiency");
		d3->Update();
	}
	d3->SaveAs("cosThetaL_efficiency.pdf");
}


