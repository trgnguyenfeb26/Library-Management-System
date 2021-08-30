struct SachMT{
	char MASACH[15];
	char TenSach[30];
	char NgayMuon[10];
	int TrangThai;
};
struct DSMuonTra{
	int n;
	SachMT *mt = new SachMT[3];
	DSMuonTra(){
		n = 0;
	}
	~DSMuonTra(){
		delete[] mt;
	}
};
DSMuonTra DSMT;
void RunQLSach(){
	strcpy(mess, "");
	Window = MUON_SACH;
//	DrawBorderMuonTra();
	if (Window == MUON_SACH){
		
		DrawBorderMuonTra();
		curMenuMuonTra = -1;
		DrawTraSach();
	}	
	btnMuonSach.isHover = true;
	btnMuonSach.isChoose = true;
	SetMenuMuonTraSelect(btnMuonSach.id);	
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();	
}
void SetMenuButtonSwitch(int menuID){
	btnMuonSach.isChoose = false;
	btnTraSach.isChoose = false;
	btnTopTen.isChoose = false;
	
	if(menuID == btnMuonSach.id){
		btnMuonSach.isChoose = true;
	}else if(menuID == btnTraSach.id){
		btnTraSach.isChoose = true;
	}else if(menuID == btnTopTen.id){
		btnTopTen.isChoose = true;
	}
}
void SetMenuMuonTraSelect(int menuID){
	if(curMenuMuonTra != menuID){
		curMenuMuonTra = menuID;
		curDGMT = NULL;
		curDSMT = NULL;
		Edit = NULL;
		strcpy(mess, "");
		SetMenuButtonSwitch(curMenuMuonTra);
		if(curMenuMuonTra == btnMuonSach.id){
			Window=MUON_SACH;
			DrawMuonSach();
		}else if(curMenuMuonTra == btnTraSach.id){
			Window=TRA_SACH;
			DrawTraSach();
		}else if(curMenuMuonTra == btnTopTen.id){
			Window=TOP_TEN;
			DrawTopTen();
		}	
	}
}
void DrawBorderMuonTra(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
	rectangle(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	setfillstyle(SOLID_FILL,11);
	bar(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
//	line(878 ,Table_y1+50 , 878, Table_y2 +50);
}

void DrawMuonSach(){
	DrawBorderMuonTra();
//	line((w+250)/2, 100, 250+(w-250)/2, h);
//	
	settextstyle(BOLD_FONT, HORIZ_DIR, 6);
	setcolor(TEXT_TITLE_COLOR);
	setfillstyle(SOLID_FILL,BG_COLOR);
	bar(500,60,1300,120);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(MuonSach)/2, 70, MuonSach);
	DrawListDocGiaMT(true);
	DrawbtnDocGiaMT();
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
}

void DrawBorderDSDocGiaMT(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
	rectangle(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	
	setfillstyle(SOLID_FILL,11);
	bar(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	
	DrawBorderDGList2();
	
	char ch[6][20] = {"Ma the", "Ho", "Ten", "Phai", "Trang thai the"};
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	line(Table_x1 ,Table_y1 + 85, Table_x2, Table_y1 + 85);
	
	for(int i=0; i < 5; i++){
		setbkcolor(11);
		outtextxy(LTBDG[i] + (LTBDG[i+1]-LTBDG[i])/2 - textwidth(ch[i])/2, 275, ch[i]);
	}
}
void DrawListDocGiaMT(bool reload){
	char chPage[20];
	if(reload ) DSDG.GetAllDocGia(TreeDocGia);
	DrawBorderDSDocGia();
	setcolor(TEXT_COLOR);
	totalPageDG = (DSDG.n-1)/13 + 1;
	for(int i=13*(curPageDG-1); i < 13*curPageDG; i++){
		if(i >= DSDG.n) break;
		DrawItemDocGia(*DSDG.nodes[i], i);
	}
	// num page
	setbkcolor(15);
	sprintf(chPage, "TRANG %d / %d", curPageDG, totalPageDG);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy((XDGQH[0]+XDGQH[6])/2 - textwidth(chPage)/2, 715, chPage);
	btnPrevDocGia.draw();	
	btnNextDocGia.draw();
	edNhapMaDGMuonSach.draw();	
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
}
void DrawbtnDocGiaMT(){
	btnPrevDocGia.draw();
	btnNextDocGia.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
}

void DrawThongTinDocGia(){
	Window = TT_DOC_GIA;
	DrawBorderDSMT();
//	ClearLayoutRightMuonTra();
	ClearDanhSachDauSach();
	setcolor(BORDER_COLOR);
	setbkcolor(15);
	setfillstyle(SOLID_FILL, 15);
	bar(350,590, 929, 720);
	setbkcolor(15);
	setlinestyle(SOLID_FILL, 0, 3);
	setfillstyle(SOLID_FILL, 0);
	rectangle(Table_x1, Table_y1, Table_x2, Table_y2+80);
	line(940,Table_y1,940,Table_y2+80);
//	line(990,320,Table_x2-20,320);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	edNhapMaDGMuonSach.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
	btnTimMaDG.draw();

	btnBackToDGMT.draw();
	if(curDGMT == NULL){
		setcolor(TIPS);
		setbkcolor(15);
		//DrawMuonSach();
		outtextxy(440, 260, "Khong tim thay doc gia nay");
	}else{	
		char ch[30];
	
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setcolor(0);
		setbkcolor(15);
		outtextxy(340, 300, "Doc gia :");
		sprintf(ch, "%s %s", curDGMT->ho, curDGMT->ten);
		outtextxy(540, 300, ch);
		
		outtextxy(340, 350, "Ma the :");
		sprintf(ch, "%d", curDGMT->MATHE);
		outtextxy(540, 350, ch);

		outtextxy(340, 400, "Phai :");
		outtextxy(540, 400, PhaiDocGia[curDGMT->phai]);
		
		outtextxy(340, 450, "Trang thai the :");
		outtextxy(540, 450, TTTDocGia[curDGMT->trangthai]);
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		setcolor(TEXT_TITLE_COLOR);
		outtextxy((XMT[0]+XMT[4])/2 - textwidth(DSDM)/2, 500, DSDM);
			
		DSMT.n = 0;
		DauSach *ds;
		char chNow[15];
		strcpy(chNow, GetSystemDate());
		bool isQH = false;
		if(curDGMT->mt.chuaTra > 0){
			DSMT.n = curDGMT->mt.chuaTra;
			int i = DSMT.n-1;
			for(NodeMuonTra *mt = curDGMT->mt.First; mt != NULL; mt = mt->next){
				if(mt->muontra.trangthai != 1){
					ds = GetDauSach(DSDS, mt->muontra.MASACH);
					strcpy(DSMT.mt[i].MASACH, mt->muontra.MASACH);
					strcpy(DSMT.mt[i].TenSach, ds->TenSach);
					strcpy(DSMT.mt[i].NgayMuon, mt->muontra.ngaymuon);
					DSMT.mt[i].TrangThai = mt->muontra.trangthai;
					DrawItemMT(i--);
				}
				if(mt->muontra.trangthai == 0){
					if(DiffTime(chNow, mt->muontra.ngaymuon) > 7*24*60*60){
						isQH = true;
					}
				}
			}
		} 
		
		DrawBorderDSMT();
		if(curMenuMuonTra == btnMuonSach.id){
			
			setcolor(TIPS);
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			subWindow = MT_KHOA;
		
			if(curDGMT->trangthai == 0){
				// the bi khoa
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("THE DOC GIA DANG BI KHOA")/2, 250, "THE DOC GIA DANG BI KHOA");
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("KHONG THE MUON SACH")/2, 280, "KHONG THE MUON SACH");
				return;
			}
			if(DSMT.n >= 3){
					
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("SO LUONG SACH MUON DA DAT GIOI HAN!")/2, 250, "SO LUONG SACH MUON DA DAT GIOI HAN !");
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("TRA SACH TRUOC KHI MUON SACH MOI")/2, 280, "TRA SACH TRUOC KHI MUON SACH MOI");
				return;
			}
			if(isQH){
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("DOC GIA DA MUON SACH QUA 7 NGAY")/2, 250, "DOC GIA DA MUON SACH QUA 7 NGAY ");
				outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("TRA SACH TRUOC KHI MUON SACH MOI")/2, 280, "TRA SACH TRUOC KHI MUON SACH MOI");
				return;
			}
			subWindow = MT_NHAP_SACH;
			if (subWindow == MT_NHAP_SACH) edTimDauSachMT.draw();
			btnClearTimDauSachMT.draw();
			DrawListDSMT();
			btnNextDSMT.draw();
			btnPrevDSMT.draw();
		}else if(curMenuMuonTra == btnTraSach.id){
			
		}
	}
}
void DrawBorderDSMT(){
		
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(BORDER_COLOR);
	setbkcolor(15);
	char t[4][15] = {"Ma sach", "Ten sach", "Ngay muon", "Trang thai"};
	setfillstyle(SOLID_FILL, 0);
	rectangle(XMT[0], 550, XMT[4], 725);
	int yline = 580;
//	setcolor(TEXT_COLOR);
	line(XMT[0], yline, XMT[4], yline);
	for(int i=0; i<4; i++){
		line(XMT[i], 550, XMT[i], 725);
		outtextxy((XMT[i]+XMT[i+1])/2 - textwidth(t[i])/2, (550+yline)/2-textheight(t[i])/2, t[i]);
	}
}
void DrawBorderList2DSMT(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDSMT[0], Table_y1+40, XDSMT[2], Table_y2+30);
	line(Table_x1 ,Table_y1 + 34, Table_x2, Table_y1 + 34);
	line(XDSMT[0] ,Table_y1 + 70, XDSMT[2], Table_y1 + 70);
	for(int i=0; i <2 ; i++){
		line(XDSMT[i], Table_y1+40, XDSMT[i], Table_y2+30);
	}
}
void DrawBorderListDSMT(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	setfillstyle(SOLID_FILL,15);
//	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
//	rectangle(Table_x1, Table_y1, Table_x2, Table_y2);
	setfillstyle(SOLID_FILL,11);
	bar(XDSMT[0], Table_y1+40, XDSMT[2], Table_y2+30);
	DrawBorderList2DSMT();
}
void DrawItemDauSachMT(int i, int j){
	char chs[10];
	outtextxy(XDSMT[0]+10, Table_y1+75 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->TenSach);
	outtextxy(XDSMT[1]+10, Table_y1+75 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->TacGia);
}
void DrawItemMT(int i){
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	setcolor(TEXT_COLOR);
	
	outtextxy(XMT[0]+10, 600+i*40, DSMT.mt[i].MASACH);
	outtextxy(XMT[1]+10, 600+i*40, DSMT.mt[i].TenSach);
	outtextxy(XMT[2]+10, 600+i*40, DSMT.mt[i].NgayMuon);
	outtextxy(XMT[3]+10, 600+i*40, TTMuonTra[DSMT.mt[i].TrangThai]);
}

void DrawListDSMT(){
//	ClearLayoutListDauSach();
	DrawBorderListDSMT();
	char ch[6][20] = {"Ten Dau sach", "Tac gia"};
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);	
	for(int i=0; i < 2; i++){
		setbkcolor(11);
		outtextxy(XDSMT[i] + (XDSMT[i+1]-XDSMT[i])/2 - textwidth(ch[i])/2, Table_y1+45, ch[i]);
	}
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	setcolor(TEXT_COLOR);
	setbkcolor(11);
	if(strlen(edTimDauSachMT.content) == 0){
		totalPageDauSach = (DSDS.n-1) / 13 + 1;
		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
			if (i >= DSDS.n) break;
			DrawItemDauSachMT(i, -1);
		}
	}else{
		totalPageDauSach = (sizeListIndexDauSachSearch-1) / 13 + 1;
		int j = 0;
		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
			if (i >= sizeListIndexDauSachSearch) break;
			DrawItemDauSachMT(listIndexDauSachSearch[i], j++);
		}
	}
	
	// num page
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	char chPage[20];
	sprintf(chPage, "TRANG %d / %d", curPageDauSach, totalPageDauSach);
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth(chPage)/2, Table_y2+40,chPage);
	
}
void DrawThongTinSach(){
	setfillstyle(SOLID_FILL, 15);
	bar(950,590,1400,720);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	setbkcolor(15);
	
	if(curSachMT != NULL){
		if(curSachMT->TrangThai == 0){
			outtextxy(960, 585, "DOC GIA CO THE MUON CUON SACH NAY !");
			canMT = true;	// Co the muon sach
		}else if(curSachMT->TrangThai == 1){
			setcolor(4);
			outtextxy(960, 585, "DA CO NGUOI MUON CUON SACH NAY !");
			canMT = false;
			return;
		}else if(curSachMT->TrangThai==2){
			setcolor(4);
			outtextxy(960, 585, "SACH DA THANH LY, KHONG THE MUON !");
			canMT = false;
			return;
		} 

//		strcpy(edNhapNgayMuonSach.content, GetSystemDate());
		if (canMT) {
		edNhapNgayMuonSach.draw();
		btnXacNhanMuonSach.draw();
		edNhapMaSachMuonSach.draw();
		}
		
		
		setfillstyle(SOLID_FILL, BG_COLOR);
	//	bar(1200, 740, w, h);
		setcolor(TIPS);
		setbkcolor(15);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth(mess)/2, 700, mess);
//		outtextxy(1200 + textwidth(ThongBao) + 40, 750, mess);
	}else{
		setcolor(TIPS);
		outtextxy(960, 585, "Khong tim thay sach nay!");
	}
}


void DrawBorderListSachMT(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(875, Table_y1, Table_x2, 475);
//	line(875,610,Table_x2,610);
	line(875,475,Table_x2,475);
	line(875,255,Table_x2,255);
	line(875,290,Table_x2,290);

	line(990, 260, 990, 475);
	line(1180, 260, 1180, 475);
	
	setcolor(TEXT_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	char ch[3][20] = {"Ma sach", "Trang thai", "Vi tri"};
	outtextxy(930-textwidth(ch[0])/2, 263, ch[0]);
	outtextxy(1075-textwidth(ch[1])/2, 263, ch[1]);
	outtextxy(1300-textwidth(ch[2])/2, 263, ch[2]);
}
void DrawDanhMucSachMT(){
	setfillstyle(SOLID_FILL,15);
	bar(XDSMT[0]-15, Table_y1, XDSMT[2]+5, Table_y2+79);
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(TEXT_TITLE_COLOR);
	setbkcolor(15);
	char t[50];
	sprintf(t, "%s: %s", DMS, DSDS.mang[curDauSach]->TenSach);	
	outtextxy((875+(Table_x2-875)/2)-textwidth(t)/2, (Table_y1+(260-Table_y1)/2)-textheight(t)/2, t);
	DrawBorderListSachMT();
	totalPageSach = (DSDS.mang[curDauSach]->SoLuong - 1) / 8 + 1;
	setcolor(TIPS);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	NodeSach* node = GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1));
	for(int i = 0; node != NULL && i < 8; node = node->next){
		DrawItemSach(node->data, i++);
	}
//	// num page
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TIPS);
	setbkcolor(15);
	char chPage[20];
	sprintf(chPage, "Trang %d / %d", curPageSach, totalPageSach);
	outtextxy(1070, 485, chPage);
	btnPrevDanhMucSach.draw();
	btnNextDanhMucSach.draw();
	edNhapMaSachMuonSach.draw();
	btnTimMaSach.draw();
}

void DrawbtnDauSachMT(){
	btnPrevDSMT.draw();
	btnNextDSMT.draw();
}

void DrawTraSach(){
	DrawBorderMuonTra();
//	line((w+250)/2, 100, 250+(w-250)/2, h);
	settextstyle(BOLD_FONT, HORIZ_DIR, 6);
	setcolor(TEXT_TITLE_COLOR);
	setfillstyle(SOLID_FILL,BG_COLOR);
	bar(500,60,1300,120);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(TraSach)/2, 70, TraSach);
	DrawListDocGiaMT(true);
	DrawbtnDocGiaMT();
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
}

void DrawThongTinSachTra(int itemMT){
	if(itemMT != -1){
		curMT = itemMT;
		Window==TRA_SACH;
		setfillstyle(SOLID_FILL, 15);
		bar(940+2,Table_y1+2,Table_x2-2,Table_y2+80-2);
		setbkcolor(15);
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		setcolor(TEXT_TITLE_COLOR);
		outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("THONG TIN SACH")/2, 260, "THONG TIN SACH");
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setcolor(TEXT_COLOR);
		setbkcolor(15);
		outtextxy(960, 300, "Ma sach :");	
		outtextxy(1100, 300, DSMT.mt[curMT].MASACH);
		
		outtextxy(960, 340, "Ten sach : ");
		outtextxy(1100, 340, DSMT.mt[curMT].TenSach);
		
		outtextxy(960, 380, "Ngay muon :");
		outtextxy(1100, 380, DSMT.mt[curMT].NgayMuon);
		
//		setfillstyle(SOLID_FILL, BG_COLOR);
//		bar(1100, 400, w,h);
		
		if(subWindow == XAC_NHAN_TRA_SACH){
//			strcpy(edNhapNgayTraSach.content, GetSystemDate());
			edNhapNgayTraSach.draw();
			btnXacNhanTraSach.draw();
			btnLamMatSach.draw();
			setbkcolor(15);
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			setcolor(TIPS);
			outtextxy(960, 700, mess);
			
		}else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
			DrawLamMatSach();
		}
		
	}
}
void DrawLamMatSach(){
	setcolor(TEXT_TITLE_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("LAM MAT SACH ?")/2, 450, "LAM MAT SACH ?");
	setcolor(TIPS);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("The doc gia se bi khoa")/2, 480, "The doc gia se bi khoa");
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("Sach se chuyen qua trang thai: DA THANH LY")/2, 510, "Sach se chuyen qua trang thai: DA THANH LY");
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("Doc gia den sach moi de tiep tuc muon sach")/2, 540, "Doc gia den sach moi de tiep tuc muon sach");
	outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("Xac nhan lam mat sach ??")/2, 580, "Xac nhan lam mat sach ??");
	
	btnXacNhanLamMatSach.draw();
	btnHuyLamMatSach.draw();
}

void DrawTopTen(){
	DrawBorderMuonTra();
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	setfillstyle(SOLID_FILL,BG_COLOR);
	bar(500,60,1300,120);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(TopTen)/2, 80, TopTen);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	
	char t[][20] = {"STT", "ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai", "So luot muon"};
	setbkcolor(15);
	setlinestyle(SOLID_LINE,0, 3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(BORDER_COLOR);
	rectangle(XTT[0], 230, XTT[8], Table_y2+50);
	line(XTT[0], 270, XTT[8], 270);
	for(int i=0; i<8; i++){
		line(XTT[i], 230, XTT[i], Table_y2+50);
		outtextxy((XTT[i+1]+XTT[i])/2 - textwidth(t[i])/2, 250-textheight(t[i])/2, t[i]);
	}
	setbkcolor(11);
	TopSach topsach(DSDS);
//	DuyetDocGia(TreeDocGia, topsach);
//	topsach.sort();
	char ch[20];
	for(int i=0; i < (topsach.n < 10 ? topsach.n : 10); i++){
		itoa(i+1, ch, 10);
		outtextxy((XTT[0]+XTT[1])/2-textwidth(ch)/2, 300 + i*40, ch);
		outtextxy(XTT[1]+10, 300 + i*40, DSDS.mang[topsach.list[i].indexDS]->ISBN);
		outtextxy(XTT[2]+10, 300 + i*40, DSDS.mang[topsach.list[i].indexDS]->TenSach);
		itoa(DSDS.mang[topsach.list[i].indexDS]->SoTrang, ch, 10);
		outtextxy(XTT[3]+20, 300 + i*40, ch);
		outtextxy(XTT[4]+10, 300 + i*40, DSDS.mang[topsach.list[i].indexDS]->TacGia);
		itoa(DSDS.mang[topsach.list[i].indexDS]->NamXuatBan, ch, 10);
		outtextxy((XTT[5]+XTT[6])/2-textwidth(ch)/2, 300 + i*40, ch);
		outtextxy(XTT[6]+10, 300 + i*40, DSDS.mang[topsach.list[i].indexDS]->TheLoai);
		itoa(topsach.list[i].cnt, ch, 10);
		outtextxy((XTT[7]+XTT[8])/2-textwidth(ch)/2, 300 + i*40, ch);
	} 
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
}

void ItemMTLeftMouseClick(){
	if(curItemDG != -1){
		strcpy(mess, "");
		Window = TT_DOC_GIA;
		GetMaTheDocGia(13*(curPageDG-1) + curItemDG);
	//	if (subWindow==MT_NHAP_SACH) btnTimMaSach.draw(); 
		DrawThongTinDocGia();	
	}
}
void ItemDMSLeftMouseClick(){
	if (subWindow==DMS_MT){
		btnBackToTTDG.draw();
	}
	if(curItemSach != -1){
		Book = HIEU_CHINH_SACH;
		curSach = curItemSach;
		strcpy(mess, "");
		NodeSach *nodeSelect = GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1)+curSach );
		strcpy(edNhapMaSachMuonSach.content, nodeSelect->data.MaSach);
		if(strlen(edNhapMaSachMuonSach.content) > 0){
			// tim Dau Sach co chua Ma Sach can tim
			curDSMT = GetDauSach(DSDS, edNhapMaSachMuonSach.content);
			if(curDSMT == NULL){
				curSachMT = NULL;
			}else{
				// curSachMT != NULL : always
				curSachMT = GetSach(curDSMT->dms, edNhapMaSachMuonSach.content);
				}		
			strcpy(edNhapNgayMuonSach.content, GetSystemDate());
			DrawThongTinSach();
		}				
	}
}
void ItemMTClick(){
	if(curItemMT != -1){
		//Window=TRA_SACH;
		subWindow = XAC_NHAN_TRA_SACH;
		strcpy(edNhapNgayTraSach.content, GetSystemDate());
		DrawThongTinSachTra(curItemMT);
	}
}
void ItemDSLeftMouseClick(){
	if(curItem != -1){	
		subWindow = DMS_MT;
		curHieuChinh = 0;
		strcpy(mess, "");
		if(strlen(edTimDauSachMT.content) == 0) curDauSach=13*(curPageDauSach-1) + curItem;
		else curDauSach=listIndexDauSachSearch[13*(curPageDauSach-1) + curItem];
		//DANH MUC SACH
		curPageSach = 1;
		DrawDanhMucSachMT();
	}
}
void GetMaTheDocGia(int i){
	char ch[10];
	itoa(DSDG.nodes[i]->MATHE, ch, 10);
	strcpy(edNhapMaDGMuonSach.content, ch);
	curDGMT = &SearchDocGia(TreeDocGia, edNhapMaDGMuonSach.toInt())->docgia;
	DrawThongTinDocGia();
}
int GetItemDocGiaMTPosition(int y){
	int pos = (y-316+8)/30;
	int i;
	i = 13*(curPageDG-1) + pos;
	if(i >= DSDG.n) return -1;
	return pos;
}
int GetItemDSMTPosition(int y){
	int pos = (y-290)/30;                               
	int i = 13*(curPageDauSach-1) + pos;				
	if(strlen(edTimDauSachMT.content) == 0){
		if(i >= DSDS.n) return -1;
	}else{
		if(i >= sizeListIndexDauSachSearch) return -1;
	}
	return pos;
}
int GetItemMTPosition(int y){
	int pos = (y-600+8)/40;
	if(pos >= DSMT.n) return -1;
	return pos;
}

bool CheckDaMuon(DanhMucSach *curSachMT){
	DSMT.n = 0;
//	DauSach *ds;
	if(curDGMT->mt.chuaTra > 0){
		DSMT.n = curDGMT->mt.chuaTra;
		int i = DSMT.n-1;
		for(NodeMuonTra *mt = curDGMT->mt.First; mt != NULL; mt = mt->next){
			if(mt->muontra.trangthai != 1){
			//	ds = GetDauSach(DSDS, mt->muontra.MASACH);
				strcpy(DSMT.mt[i].MASACH, mt->muontra.MASACH);
				if (CheckMaSach(DSMT.mt[i].MASACH,curSachMT->MaSach)==0) return false; 
				i--;
			}
		}
	}
	return true;
}

void QLSachEvent(){
	ButtonEffect(btnQLDocGia);
	ButtonEffect(btnQLDauSach);
	ButtonEffect(btnThoat);	
	ButtonEffect(btnMuonSach);
	ButtonEffect(btnTraSach);
	ButtonEffect(btnTopTen);
			
	if(curMenuMuonTra == btnMuonSach.id){
		ButtonEffect(btnTimMaDG);
		ItemDocGiaMTEvent();
		ItemDSMTEvent();
		if (Window==MUON_SACH){
			ButtonEffect(btnPrevDocGia);
			ButtonEffect(btnNextDocGia);
		} else if (Window==TT_DOC_GIA){
				ButtonEffect(btnBackToDGMT);
				if (subWindow==DMS_MT){
					ButtonEffect(btnPrevDanhMucSach);
					ButtonEffect(btnNextDanhMucSach);
					ButtonEffect(btnBackToTTDG);
					ButtonEffect(btnTimMaSach);	
					if(canMT) ButtonEffect(btnXacNhanMuonSach);
				}
				if (subWindow==MT_NHAP_SACH){
					ButtonEffect(btnPrevDSMT);
					ButtonEffect(btnNextDSMT);
					ButtonEffect(btnClearTimDauSachMT);
				}
			}
			if (Window==TRA_SACH&&subWindow!=XAC_NHAN_LAM_MAT_SACH){
			ButtonEffect(btnLamMatSach);
			ButtonEffect(btnXacNhanTraSach);
			} if (subWindow==XAC_NHAN_LAM_MAT_SACH){
				ButtonEffect(btnHuyLamMatSach);
				ButtonEffect(btnXacNhanLamMatSach);
			}
		}else if(curMenuMuonTra == btnTraSach.id){
				ButtonEffect(btnTimMaDG);
					ItemDocGiaMTEvent();
				//	ItemDSMTEvent();
				if (Window==TT_DOC_GIA)	{
					ButtonEffect(btnBackToDGMT);
					ItemMTEvent();	
				}
				if(curMT != -1) {
					if(subWindow == XAC_NHAN_TRA_SACH){
					ButtonEffect(btnXacNhanTraSach);
					ButtonEffect(btnLamMatSach);
				}else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
						ButtonEffect(btnXacNhanLamMatSach);
						ButtonEffect(btnHuyLamMatSach);
					}
				}
				 }else if(curMenuMuonTra == btnTopTen.id){

					}
	if(GetAsyncKeyState(VK_LBUTTON)){
	
		if(btnQLDauSach.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLDauSach.id);
		}else if(btnQLDocGia.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLDocGia.id);
		}else if(btnThoat.isMouseHover(mx, my)){
			isExit = true;
		}

		if(btnMuonSach.isMouseHover(mx, my)){
			SetMenuMuonTraSelect(btnMuonSach.id);
		}else if(btnTraSach.isMouseHover(mx, my)){
			SetMenuMuonTraSelect(btnTraSach.id);
		}else if(btnTopTen.isMouseHover(mx, my)){
			SetMenuMuonTraSelect(btnTopTen.id);
		}
		
		if (Window == TT_DOC_GIA){
			if(btnPrevDSMT.isMouseHover(mx, my) ){
				if(curPageDauSach > 1){
					--curPageDauSach;
					//ClearDanhSachDauSach();
					DrawListDSMT();
					DrawbtnDauSachMT();
				}
			}else if(btnNextDSMT.isMouseHover(mx, my)){
				if(curPageDauSach < totalPageDauSach){
					++curPageDauSach;
				//	ClearDanhSachDauSach();
					DrawListDSMT();
					DrawbtnDauSachMT();
				}
			}
		}	
		if(btnPrevDanhMucSach.isMouseHover(mx, my)){	
			if(curPageSach > 1){
				--curPageSach;
				ClearLayoutDanhMucSach();
				DrawDanhMucSachMT();
			}
		}else if(btnNextDanhMucSach.isMouseHover(mx, my)){
			if(curPageSach < totalPageSach){
				++curPageSach;
				ClearLayoutDanhMucSach();
				DrawDanhMucSachMT();	
			}
		}
		if (subWindow==MT_NHAP_SACH)  ItemDSLeftMouseClick();
	
		if (Window == MUON_SACH){
			if(btnPrevDocGia.isMouseHover(mx, my)){
				if(curPageDG > 1){
					curPageDG--;
					DrawMuonSach();
				}
			}else if(btnNextDocGia.isMouseHover(mx, my)){
				if(curPageDG < totalPageDG){
					curPageDG ++;
					DrawMuonSach();
				}
			}
		}
	
		if(curMenuMuonTra == btnMuonSach.id){	
			ItemDMSLeftMouseClick();
			ItemMTLeftMouseClick();
			if(btnTimMaDG.isMouseHover(mx, my)){
				curDGMT = &SearchDocGia(TreeDocGia, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia();
			}
			if(edNhapMaDGMuonSach.isMouseHover(mx, my)){
				Edit = &edNhapMaDGMuonSach;
			}
			if(edTimDauSachMT.isMouseHover(mx, my)){
				Edit = &edTimDauSachMT;
			}else if(btnClearTimDauSachMT.isMouseHover(mx, my) ){
					memset(edTimDauSachMT.content, 0 , sizeof(edTimDauSachMT.content));
					//ClearDanhSachDauSach();
					edTimDauSachMT.draw();
					DrawListDSMT();	
				}
				if(btnBackToDGMT.isMouseHover(mx, my) && Window != MUON_SACH&&Window==TT_DOC_GIA){
					strcpy(mess, "");
					Window = MUON_SACH;
					curDGMT == NULL;
					DrawMuonSach();
				}
			if(curDGMT != NULL){
				
				if(btnBackToTTDG.isMouseHover(mx, my) && subWindow != MT_NHAP_SACH){
					strcpy(mess, "");
					subWindow = MT_NHAP_SACH;
					//curDGMT == NULL;
					DrawThongTinDocGia();
				}
				if(edNhapMaSachMuonSach.isMouseHover(mx, my)){
					Edit = &edNhapMaSachMuonSach;
				}
			
				if(btnTimMaSach.isMouseHover(mx, my)){	
					if(strlen(edNhapMaSachMuonSach.content) > 0){
						// tim Dau Sach co chua Ma Sach can tim
						curDSMT = GetDauSach(DSDS, edNhapMaSachMuonSach.content);
						if(curDSMT == NULL){
							curSachMT = NULL;
						}else{
							// curSachMT != NULL : always
							curSachMT = GetSach(curDSMT->dms, edNhapMaSachMuonSach.content);
						}
						strcpy(edNhapNgayMuonSach.content, GetSystemDate());
						DrawThongTinSach();	
					}
				}
				if(curSachMT != NULL && canMT){
					if(edNhapNgayMuonSach.isMouseHover(mx, my)){
						Edit = &edNhapNgayMuonSach;
					}
					if(btnXacNhanMuonSach.isMouseHover(mx, my)){
						// Muon sach
						
						if (CheckDaMuon(curSachMT)==false){
							Window=TT_DOC_GIA;
							subWindow=DMS_MT;
							strcpy(mess, "THONG BAO: Ban da muon Sach nay!");
							DrawThongTinSach();
						}else
						if(!CheckDate(edNhapNgayMuonSach.content)){
							Window=TT_DOC_GIA;
							subWindow=DMS_MT;
							strcpy(mess, "THONG BAO : Ngay muon khong hop le");
							DrawThongTinSach();
						}else if(CompareDate(edNhapNgayMuonSach.content, GetSystemDate()) > 0){
							Window=TT_DOC_GIA;
							subWindow=DMS_MT;
							strcpy(mess, "THONG BAO : Ngay muon khong the muon hon ngay hien tai");
							DrawThongTinSach();
						}else{
							// 0: DANG MUON
							MuonTra muon(curSachMT->MaSach, edNhapNgayMuonSach.content, "", 0);
							InsertLast_MuonTra(curDGMT->mt, muon);	
							NodeSach *nodeSach = GetNodeSach(curDSMT->dms, curSachMT->MaSach);
							DanhMucSach sach = nodeSach->data;
							sach.TrangThai = 1; 	// DA CHO MUON
							UpdateNodeSach(nodeSach, sach);
							
							// Tang so luot muon sach cua Dau Sach
							curDSMT->SoLuotMuon ++;
							curDSMT = NULL;
							curSachMT = NULL;
							canMT = false;
							Window=TT_DOC_GIA;
							subWindow=DMS_MT;
							memset(edNhapMaSachMuonSach.content, 0, sizeof(edNhapMaSachMuonSach.content));
							DrawThongTinDocGia();
						}
					}
				}
			}
		} if(curMenuMuonTra == btnTraSach.id){
			ItemMTClick();
			if (Window == TRA_SACH){
				ItemMTLeftMouseClick();	
				if(btnPrevDocGia.isMouseHover(mx, my)){
					if(curPageDG > 1){
						curPageDG--;
						DrawMuonSach();
					}
				}else if(btnNextDocGia.isMouseHover(mx, my)){
					if(curPageDG < totalPageDG){
						curPageDG ++;
						DrawMuonSach();
					}
				}		
			}	
			if(btnBackToDGMT.isMouseHover(mx, my) && Window != TRA_SACH&&Window == TT_DOC_GIA){
				strcpy(mess, "");
				Window = TRA_SACH;
				curDGMT == NULL;
				DrawTraSach();
			}
			if(btnTimMaDG.isMouseHover(mx, my)){
				curDGMT = &SearchDocGia(TreeDocGia, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia();
			}
			if(edNhapMaDGMuonSach.isMouseHover(mx, my)){
				Edit = &edNhapMaDGMuonSach;
			}
			if(curMT != -1 && curDGMT != NULL){
				if(edNhapNgayTraSach.isMouseHover(mx, my)){
			//		Edit = &edNhapNgayTraSach;
				}
				if(subWindow == XAC_NHAN_TRA_SACH){
					if(btnXacNhanTraSach.isMouseHover(mx, my)){
						if(!CheckDate(edNhapNgayTraSach.content)){
							strcpy(mess, "THONG BAO : Ngay nhap vao khong hop le");
							DrawThongTinSachTra(curMT);
						} else if(CompareDate(edNhapNgayTraSach.content, DSMT.mt[curMT].NgayMuon) < 0){
						
							strcpy(mess, "THONG BAO : Ngay tra sach khong the som hon ngay muon sach");
							DrawThongTinSachTra(curMT);
						} else if (CompareDate(edNhapNgayTraSach.content, GetSystemDate()) > 0){
						
							strcpy(mess, "THONG BAO : Ngay tra khong the muon hon ngay hien tai");
							DrawThongTinSach();
						} else {
							MuonTra tra(DSMT.mt[curMT].MASACH, DSMT.mt[curMT].NgayMuon, edNhapNgayTraSach.content, 1);
							Update_MuonTra(curDGMT->mt, tra);
							
							curDSMT = GetDauSach(DSDS, DSMT.mt[curMT].MASACH);
							NodeSach *nodeSach = GetNodeSach(curDSMT->dms, DSMT.mt[curMT].MASACH);
							DanhMucSach sach = nodeSach->data;
							sach.TrangThai = 0; 	// CHO MUON DUOC
							UpdateNodeSach(nodeSach, sach);
							curDSMT = NULL;
							curMT = -1;
								
							memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
							DrawThongTinDocGia();
							settextstyle(BOLD_FONT, HORIZ_DIR, 4);
							setcolor(0);
							setbkcolor(15);
							line(XDSMT[0], 280, XDSMT[2], 280);
							outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("THONG BAO")/2, 260, "THONG BAO");
							setcolor(TIPS);
							settextstyle(BOLD_FONT, HORIZ_DIR, 3);
							outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("Tra sach thanh cong")/2, 350, "Tra sach thanh cong");
						}
						
					}else if(btnLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_LAM_MAT_SACH;
						DrawThongTinSachTra(curMT);
					}	
				}else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
					if(btnXacNhanLamMatSach.isMouseHover(mx, my)){
						MuonTra tra(DSMT.mt[curMT].MASACH, DSMT.mt[curMT].NgayMuon, "", 2);
						Update_MuonTra(curDGMT->mt, tra);
						curDSMT = GetDauSach(DSDS, DSMT.mt[curMT].MASACH);
						NodeSach *nodeSach = GetNodeSach(curDSMT->dms, DSMT.mt[curMT].MASACH);
						DanhMucSach sach = nodeSach->data;
						sach.TrangThai = 2; 	// DA THANH LY
						UpdateNodeSach(nodeSach, sach);
								
						curDSMT = NULL;
						curMT = -1;
						
						curDGMT->trangthai = 0; // KHOA THE DOC GIA
						UpdateDocGia(TreeDocGia, *curDGMT);
								
						memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
						DrawThongTinDocGia();
						
						settextstyle(BOLD_FONT, HORIZ_DIR, 4);
						setcolor(0);
						setbkcolor(15);
						line(XDSMT[0], 280, XDSMT[2], 280);
						outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("THONG BAO")/2, 260, "THONG BAO");
						setcolor(TIPS);
						settextstyle(BOLD_FONT, HORIZ_DIR, 3);
						outtextxy(XDSMT[0] + (XDSMT[2]-XDSMT[0])/2 - textwidth("THE DOC GIA DA BI KHOA")/2, 350, "THE DOC GIA DA BI KHOA");
					}else if(btnHuyLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_TRA_SACH;
						DrawThongTinSachTra(curMT);
					}
				}
				
			}
		}
	}
}
void ItemDocGiaMTEvent(){
	if(mx > Table_x1 && mx < Table_x2 && my > 307 && my < 692 && (Window == MUON_SACH||Window == TRA_SACH)){	
		if(curItemDG != GetItemDocGiaMTPosition(my)){
			if(curItemDG != -1&& (Window == MUON_SACH||Window == TRA_SACH)){
				// khoi phuc item
				setfillstyle(SOLID_FILL, 11);
				bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setcolor(TEXT_COLOR);
				DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
				DrawBorderDGList2();
			}
			// Ve item hien tai
			curItemDG = GetItemDocGiaMTPosition(my);
			if(curItemDG != -1 && (Window == MUON_SACH||Window == TRA_SACH)){
				setfillstyle(SOLID_FILL, 10);
				bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setbkcolor(10);
				setcolor(TEXT_COLOR);
				DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
				DrawBorderDGList2();	
			}
		}
	}else{
		if(curItemDG != -1 && (Window == MUON_SACH||Window == TRA_SACH)){
			// khoi phuc item
			setfillstyle(SOLID_FILL, 11);
			bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
			setbkcolor(11);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
			setcolor(TEXT_COLOR);
			DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
			DrawBorderDGList2();			
			curItemDG = -1;
		} else 	curItemDG = -1;
	}
}

void ItemDSMTEvent(){
	if(mx > XDSMT[0] && mx < XDSMT[2] && my > Table_y1+45 && my < Table_y2+25 && Window == TT_DOC_GIA&&subWindow == MT_NHAP_SACH){
		if(curItem != GetItemDSMTPosition(my)){
			if(curItem != -1){
				// khoi phuc item
				setfillstyle(SOLID_FILL,11);
				bar(XDSMT[0], 290 + curItem*30 , XDSMT[2], 290+(curItem+1)*30);		
				DrawBorderList2DSMT();
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setcolor(TEXT_COLOR);
				if(strlen(edTimDauSachMT.content) == 0){
					DrawItemDauSachMT((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSachMT(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
				
			}
			// Ve item hien tai
			curItem = GetItemDSMTPosition(my);
			if(curItem != -1){

				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setbkcolor(10);
				setcolor(TEXT_COLOR);
				
				setfillstyle(SOLID_FILL, 10);
				bar(XDSMT[0], 290 + curItem*30 ,XDSMT[2], 290+(curItem+1)*30);
				if(strlen(edTimDauSachMT.content) == 0){
					DrawItemDauSachMT((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSachMT(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
				
				 DrawBorderList2DSMT();
			}
		}
	}else{
		if(curItem != -1 && Window == TT_DOC_GIA&&subWindow == MT_NHAP_SACH){
			// khoi phuc item
			setfillstyle(SOLID_FILL,11);
				bar(XDSMT[0], 290 + curItem*30 , XDSMT[2], 290+(curItem+1)*30);
								
				DrawBorderList2DSMT();
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setcolor(TEXT_COLOR);
				if(strlen(edTimDauSachMT.content) == 0){
					DrawItemDauSachMT((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSachMT(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
			curItem = -1;
		} else curItem = -1;
	}

if((subWindow != DMS_MT ||Book==NONE)) return;

		if(mx > 875 && mx < Table_x2 && my > 295&& my < 470&&Window!=MUON_SACH){
		
		if(curItemSach != GetItemSachPosition(my)){
			if(curItemSach != -1&&Window!=MUON_SACH){
				setfillstyle(SOLID_FILL, 15);
				bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				
				setbkcolor(15);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setcolor(TIPS);
				DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
				DrawBorderListSachMT();
			}
			curItemSach = GetItemSachPosition(my);
			if(curItemSach != -1&&Window!=MUON_SACH){
				setfillstyle(SOLID_FILL, 11);
				bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setbkcolor(11);
				setcolor(TIPS);
				DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
				DrawBorderListSachMT();
			}
		}
	}else{
		if(curItemSach != -1&&Window!=MUON_SACH){
			// khoi phuc item
			setfillstyle(SOLID_FILL, 15);
			bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				
			setbkcolor(15);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			setcolor(TIPS);
			DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
			DrawBorderListSachMT();
			curItemSach = -1;
		}
	}
}
void ItemMTEvent(){
	if(mx > XMT[0] && mx < XMT[4] && my > 600-8 && my < 720-8){
		
		if(curItemMT != GetItemMTPosition(my)){
			if(curItemMT != -1){
				// khoi phuc item
				setfillstyle(SOLID_FILL, 15);
				bar(XMT[0], 600 + curItemMT*40 - 8, XMT[4], 600+(curItemMT+1)*40-8);
				setbkcolor(15);
				DrawItemMT(curItemMT);
				DrawBorderDSMT();
			}
			// Ve item hien tai
			curItemMT = GetItemMTPosition(my);
			if(curItemMT != -1){
				setfillstyle(SOLID_FILL, 11);
				bar(XMT[0], 600 + curItemMT*40 - 8, XMT[4], 600+(curItemMT+1)*40-8);
				setbkcolor(11);
				DrawItemMT(curItemMT);
				DrawBorderDSMT();
			}
		}
	}else{
		if(curItemMT != -1){
			// khoi phuc item
			setfillstyle(SOLID_FILL, 15);
			bar(XMT[0], 600 + curItemMT*40 - 8, XMT[4], 600+(curItemMT+1)*40-8);
			setbkcolor(15);
			DrawItemMT(curItemMT);
			DrawBorderDSMT();
			curItemMT = -1;
		}
	}
}
