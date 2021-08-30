void RunDauSach(){

	Window = DANH_SACH_SACH;
	
	DrawList();
	DrawDanhSachDauSach();
		
	subWindow = HIEU_CHINH;
	Book = NHAP_SACH;

	btnQLDauSach.isChoose=true;
	btnQLDauSach.isHover=true;
	btnQLDauSach.draw();
	
	btnDanhSach.isChoose = true;
	btnDanhSach.isHover = true;
	btnThemDauSach.isChoose = false;
	btnThemDauSach.isHover = false;
	btnThemDauSach.draw();
	btnDanhSach.draw();
}
 void AutoCreateMaSach(){
		if(curNhapSach == 1) startIndexSach = DSDS.mang[curDauSach]->maxSach;
		else startIndexSach++;
	
		char id[20];
		sprintf(id, "%s-%d", DSDS.mang[curDauSach]->ISBN, startIndexSach);
		strcpy(edThemMaSach.content, id);
	
}
bool CheckSoLuongSach(){
	if(strlen(edNhapSoLuongSach.content) == 0){
		strcpy(mess, "Hay nhap so luong sach them");
		return false;
	}
	return true;
}
bool CheckSach(){
	if(strlen(edThemTrangThaiSach.content) == 0 || strlen(edThemViTriSach.content) == 0){
		strcpy(mess, "Khong duoc bo trong bat ki truong nao");
		return false;	
	}
	if(edThemTrangThaiSach.toInt() == 1){
		strcpy(mess, "TT Sach ban dau khong the:DA CHO MUON");
		return false;
	}
	return true;
}
bool CheckHieuChinhSach(){
	if(strlen(edHieuChinhTrangThaiSach.content) == 0 ||
		strlen(edHieuChinhViTriSach.content) == 0){
		
		strcpy(mess, "Khong duoc bo trong bat ki truong nao");
		return false;	
	}
	if(canEditTrangThai && edHieuChinhTrangThaiSach.toInt() == 1){
		strcpy(mess, "TT Sach ban dau khong the:DA CHO MUON");
		return false;
	}
	return true;
}

bool CheckDauSach(){
	if(strlen(edThemISBN.content) == 0) {
		strcpy(mess, "ISBN khong duoc bo trong");
		Edit = &edThemISBN;
		Edit->draw();
		return false;
	}else if(strlen(edThemTenSach.content) == 0) {
		strcpy(mess, "Ten sach khong duoc bo trong");
		Edit = &edThemTenSach;
		Edit->draw();
		return false;
	}else if(strlen(edThemSoTrang.content) == 0) {
		strcpy(mess, "So trang khong duoc bo trong");
		Edit = &edThemSoTrang;
		Edit->draw();
		return false;
	}else if(strlen(edThemTacGia.content) == 0) {
		strcpy(mess, "Tac gia khong duoc bo trong");
		Edit = &edThemTacGia;
		Edit->draw();
		return false;
	}else if(strlen(edThemNXB.content) == 0) {
		strcpy(mess, "NXB khong duoc bo trong");
		Edit = &edThemNXB;
		Edit->draw();
		return false;
	}else if(strlen(edThemTheLoai.content) == 0) {
		strcpy(mess, "The loai khong duoc bo trong");
		Edit = &edThemTheLoai;
		Edit->draw();
		return false;
	}
	
	if(CheckISBN(DSDS, edThemISBN.content) != -1){
		strcpy(mess, "ISBN da ton tai");
		Edit = &edThemISBN;
		Edit->draw();
		return false;
	}
	/////////////////// kiem tra thoi gian (((( can xem lai )))
	char chDate[11];
	strcpy(chDate, GetSystemDate());
	int *d = SplitDate(chDate);
	int year = d[2];
	delete[] d;
	int y = edThemNXB.toInt();
	if(y > year){
		strcpy(mess, "NXB khong the lon hon hien tai");
		Edit = &edThemNXB;
		Edit->draw();
		return false;
	}

	return true;
}
bool CheckHieuChinhDauSach(){
	if(strlen(edHieuChinhISBN.content) == 0) {
		strcpy(mess, "ISBN khong duoc bo trong");
		Edit = &edHieuChinhISBN;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhTenSach.content) == 0) {
		strcpy(mess, "Ten sach khong duoc bo trong");
		Edit = &edHieuChinhTenSach;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhSoTrang.content) == 0) {
		strcpy(mess, "So trang khong duoc bo trong");
		Edit = &edHieuChinhSoTrang;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhTacGia.content) == 0) {
		strcpy(mess, "Tac gia khong duoc bo trong");
		Edit = &edHieuChinhTacGia;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhNXB.content) == 0) {
		strcpy(mess, "NXB khong duoc bo trong");
		Edit = &edHieuChinhNXB;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhTheLoai.content) == 0) {
		strcpy(mess, "The loai khong duoc bo trong");
		Edit = &edHieuChinhTheLoai;
		Edit->draw();
		return false;
	}
	
	char chDate[11];
	strcpy(chDate, GetSystemDate());
	int *d = SplitDate(chDate);
	int year = d[2];
	delete[] d;
	int y = edHieuChinhNXB.toInt();
	if(y > year){
		strcpy(mess, "NXB khong the lon hon nam hien tai");
		Edit = &edHieuChinhNXB;
		Edit->draw();
		return false;
	}

	return true;
}


///////////////////					CLEAR
void ClearXoaISBN(){
	setfillstyle(SOLID_FILL,15);
	bar(890,620,1410,700);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TIPS);
	setbkcolor(15);
	outtextxy(1040, 650, mess);
}
void ClearDanhSachDauSach(){
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
}
void ClearContentThemDauSach(){	
	memset(edThemISBN.content, 0, sizeof(edThemISBN.content));
	memset(edThemTenSach.content, 0, sizeof(edThemTenSach.content));
	memset(edThemSoTrang.content, 0, sizeof(edThemSoTrang.content));
	memset(edThemTacGia.content, 0, sizeof(edThemTacGia.content));
	memset(edThemNXB.content, 0, sizeof(edThemNXB.content));
	memset(edThemTheLoai.content, 0, sizeof(edThemTheLoai.content));
}

void ClearContentHieuChinhDauSach(){
	memset(edHieuChinhISBN.content, 0, sizeof(edHieuChinhISBN.content));
	memset(edHieuChinhTenSach.content, 0, sizeof(edHieuChinhTenSach.content));
	memset(edHieuChinhSoTrang.content, 0, sizeof(edHieuChinhSoTrang.content));
	memset(edHieuChinhTacGia.content, 0, sizeof(edHieuChinhTacGia.content));
	memset(edHieuChinhNXB.content, 0, sizeof(edHieuChinhNXB.content));
	memset(edHieuChinhTheLoai.content, 0, sizeof(edHieuChinhTheLoai.content));
}
void ClearLayoutListDauSach(){
	setfillstyle(SOLID_FILL, 11);
	bar(Table_x1, Table_y1, Table_x2,Table_y2);
}
void ClearLayoutSach(){
	setfillstyle(SOLID_FILL, 15);
	bar(875+2, 512, Table_x2-2,Table_y2+60-2);
}
void ClearRightLayout(){
	setfillstyle(SOLID_FILL, 15);
	bar(1050, 210, 1350,690);
}
void ClearLayoutDanhMucSach(){
	setfillstyle(SOLID_FILL, 15);
	bar(880, 295, 1415, 470);
}
void ClearContentNhapSoLuongSach(){
	memset(edNhapSoLuongSach.content, 0, sizeof(edNhapSoLuongSach.content));
}
void ClearContentThemSach(){
	memset(edThemMaSach.content, 0, sizeof(edThemMaSach.content));
	memset(edThemTrangThaiSach.content, 0, sizeof(edThemTrangThaiSach.content));
	memset(edThemViTriSach.content, 0, sizeof(edThemViTriSach.content));
}
void ClearContentHieuChinhSach(){
	memset(edHieuChinhMaSach.content, 0, sizeof(edHieuChinhMaSach.content));
	memset(edHieuChinhTrangThaiSach.content, 0, sizeof(edHieuChinhTrangThaiSach.content));
	memset(edHieuChinhViTriSach.content, 0, sizeof(edHieuChinhViTriSach.content));
}
///////////////////					DRAW
void DrawXoaSach(){
	ClearLayoutSach();
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(0);
	line(875,610,Table_x2,610);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TIPS);
	outtextxy((875+(Table_x2-875)/2)-textwidth(ThongBao)/2,610-textheight(ThongBao)/2, ThongBao);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TIPS);
	setbkcolor(15);
	outtextxy((875+(Table_x2-875)/2)-textwidth(mess)/2, (580+(Table_y2+60-580)/2)-textheight(mess)/2, mess);
	
		btnXacNhanXoaSach.draw();
		btnHuyXoaSach.draw();
	
}
void DrawXoaDauSach(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TIPS);
	setbkcolor(15);
	outtextxy((875+(Table_x2-875)/2)-textwidth(mess)/2, (580+(Table_y2+60-580)/2)-textheight(mess)/2, mess);
	if (subWindow == XOA_ISBN){
		btnXacNhanXoaDauSach.draw();
		btnHuyXoaDauSach.draw();
	}
}

void DrawBorderList2(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(Table_x1, Table_y1, Table_x2, Table_y2);
	line(Table_x1 ,Table_y1 + 35, Table_x2, Table_y1 + 35);
	for(int i=1; i < 6; i++){
		line(LTB[i], Table_y1, LTB[i], Table_y2);
	}
}
void DrawBorderList(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
	rectangle(Table_x1, Table_y1, Table_x2, Table_y2);
	setfillstyle(SOLID_FILL,11);
	bar(Table_x1, Table_y1, Table_x2, Table_y2);
	
	DrawBorderList2();
	
	
}
void DrawHieuChinhDauSach(){
	ClearDanhSachDauSach();
	DrawBorderListSach();
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(Table_x1, Table_y1, Table_x2, Table_y2+60);
	line(Table_x1,260,Table_x2,260);
	setlinestyle(SOLID_LINE, 0, 3);
		setcolor(0);
		line(875,610,Table_x2,610);	
		
//	line(Table_x1,660,875,660);
	edHieuChinhISBN.draw();
	edHieuChinhTenSach.draw();
	edHieuChinhSoTrang.draw();
	edHieuChinhTacGia.draw();
	edHieuChinhNXB.draw();
	edHieuChinhTheLoai.draw();
	btnThemDauSach.draw();
	btnDanhSach.draw();
	btnBackToDanhSachSach.draw();
	btnHieuChinhDauSach.draw();
	btnXoaDauSach.draw();
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(TEXT_TITLE_COLOR);
	setbkcolor(15);
	
	outtextxy((Table_x1+(875-Table_x1)/2)-textwidth(HieuChinhDauSach)/2, (Table_y1+(260-Table_y1)/2)-textheight(HieuChinhDauSach)/2, HieuChinhDauSach);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	setfillstyle(SOLID_FILL, BG_COLOR);
	outtextxy((875+(Table_x2-875)/2)-textwidth(mess)/2, (610+(Table_y2+60-610)/2)-textheight(mess)/2, mess);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TIPS);
	outtextxy((875+(Table_x2-875)/2)-textwidth(ThongBao)/2,610-textheight(ThongBao)/2, ThongBao);
}
void DrawDanhSachDauSach(){
	setfillstyle(SOLID_FILL,BG_COLOR);
	bar(500,60,1300,120);
	settextstyle(BOLD_FONT, HORIZ_DIR, 6);
	setcolor(TEXT_TITLE_COLOR);
	setbkcolor(3);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2-textwidth(DauSachTitle)/2, 70,DauSachTitle);
	
	btnClearTimDauSach.draw();
	btnPrevDauSach.draw();
	btnNextDauSach.draw();
	btnDanhSach.draw();
	btnThemDauSach.draw();
	if (Edit != &edTimDauSach ) edTimDauSach.draw();
}
	
void DrawList(){
//	ClearLayoutListDauSach();
	DrawBorderList();
	char ch[6][20] = {"ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai"};
	
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 6; i++){
		setbkcolor(11);
		outtextxy(LTB[i] + (LTB[i+1]-LTB[i])/2 - textwidth(ch[i])/2, 225, ch[i]);
	}
	setcolor(TEXT_COLOR);
	if(strlen(edTimDauSach.content) == 0){
		totalPageDauSach = (DSDS.n-1) / 13 + 1;
		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
			if (i >= DSDS.n) break;
			DrawItemDauSach(i, -1);
		}
	}else{
		totalPageDauSach = (sizeListIndexDauSachSearch-1) / 13 + 1;
		int j = 0;
		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
			if (i >= sizeListIndexDauSachSearch) break;
			DrawItemDauSach(listIndexDauSachSearch[i], j++);
		}
	}
	
	// num page
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	char chPage[20];
	sprintf(chPage, "TRANG %d / %d", curPageDauSach, totalPageDauSach);
	outtextxy(800, 660, chPage);
	

}
void DrawItemDauSach(int i, int j){
	char chs[10];
	outtextxy(LTB[0]+10, 260 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->ISBN);
	outtextxy(LTB[1]+10, 260 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->TenSach);
	if(DSDS.mang[i]->SoTrang > 0){
		itoa(DSDS.mang[i]->SoTrang, chs, 10);
		outtextxy(LTB[2]+(LTB[3]-LTB[2])/2-textwidth(chs)/2 ,260 + (j!=-1?j:(i%13)) *30, chs);
	}
	outtextxy(LTB[3]+10, 260 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->TacGia);
	if(DSDS.mang[i]->NamXuatBan > 0){
		itoa(DSDS.mang[i]->NamXuatBan, chs, 10);
		outtextxy(LTB[4]+(LTB[5]-LTB[4])/2-textwidth(chs)/2, 260 + (j!=-1?j:(i%13)) *30, chs);
	}
	outtextxy(LTB[5]+10, 260 + (j!=-1?j:(i%13)) *30, DSDS.mang[i]->TheLoai);
}

void DrawThemDauSach(){
	ClearDanhSachDauSach();
	setbkcolor(15);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle(Table_x1+20, Table_y1+40, Table_x2-20, Table_y2);
	line(990,Table_y1+40,990,Table_y2);
	line(990,320,Table_x2-20,320);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((Table_x1+20)+(Table_x2-20-Table_x1-20)/2 - textwidth(ThemDauSach)/2, 245 - textheight(ThemDauSach)/2, ThemDauSach);
	
	setcolor(TIPS);
	outtextxy(1195-textwidth(ThongBao)/2,290-textheight(ThongBao)/2, ThongBao);
	
	setfillstyle(SOLID_FILL, 15);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	bar(990+2,320+2,Table_x2-20-2,Table_y2-2);
	
	outtextxy(1000 , 360, mess);

	btnThemDauSach.draw();
	btnDanhSach.draw();
	btnThemDauSach.isChoose=true;
	btnThemDauSach.isHover=true;
	edThemISBN.draw();
	edThemTenSach.draw();
	edThemSoTrang.draw();
	edThemTacGia.draw();
	edThemNXB.draw();
	edThemTheLoai.draw();
	btnThemDauSach.draw();
	btnThemDauSachMini.draw();	
	
}
//////////////////////////////////
void DrawItemSach(DanhMucSach &sach, int i){
	outtextxy(932-textwidth(sach.MaSach)/2, 295 + (i%8)*22, sach.MaSach);
	outtextxy(1085-textwidth(TrangThaiSach[sach.TrangThai])/2, 295 + (i%8)*22, TrangThaiSach[sach.TrangThai]);
	outtextxy(1300-textwidth(sach.ViTri)/2, 295 + (i%8)*22, sach.ViTri);
}
void DrawBorderListSach(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(875, Table_y1, Table_x2, Table_y2+60);
//	line(875,610,Table_x2,610);
	line(875,475,Table_x2,475);
	line(875,260,Table_x2,260);
	line(875,290,Table_x2,290);

	line(990, 260, 990, 475);
	line(1180, 260, 1180, 475);
	
	setcolor(TEXT_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	char ch[3][20] = {"Ma sach", "Trang thai", "Vi tri"};
	outtextxy(930-textwidth(ch[0])/2, 263, ch[0]);
	outtextxy(1085-textwidth(ch[1])/2, 263, ch[1]);
	outtextxy(1300-textwidth(ch[2])/2, 263, ch[2]);
} 
void DrawDanhMucSach(){
	
//	setfillstyle(SOLID_FILL,15);
//	bar(1050,Table_y1-5,1340,690);
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(TEXT_TITLE_COLOR);
	setbkcolor(15);
	char t[50];
	sprintf(t, "%s: %s", DMS, DSDS.mang[curDauSach]->TenSach);
	
	outtextxy((875+(Table_x2-875)/2)-textwidth(t)/2, (Table_y1+(260-Table_y1)/2)-textheight(t)/2, t);
	DrawBorderListSach();
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
}
 
void DrawNhapSach(){
	if(Book == NHAP_SACH){
		ClearLayoutSach();
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setbkcolor(15);
			setlinestyle(SOLID_LINE, 0, 3);
		setcolor(0);
		line(875,610,Table_x2,610);
		setcolor(TEXT_TITLE_COLOR);
		outtextxy(1080, 520, NhapSach);
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TIPS);
	outtextxy((875+(Table_x2-875)/2)-textwidth(ThongBao)/2,610-textheight(ThongBao)/2, ThongBao);
	
		edNhapSoLuongSach.draw();
		btnNhapSoLuongSach.draw();
		
		
		
	}
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TIPS);
	setbkcolor(15);
	outtextxy((875+(Table_x2-875)/2)-textwidth(mess)/2, (610+(Table_y2+60-610)/2)-textheight(mess)/2, mess);
	strcpy(mess, "");
}

void DrawThemSach(){
	ClearLayoutSach();
	if(CheckAuto) AutoCreateMaSach();
	strcpy(edThemTrangThaiSach.content, "0");
	btnThemSach.draw();
	edThemMaSach.draw();
	edThemTrangThaiSach.draw();
	edThemViTriSach.draw();
	btnBackToNhapSach.draw();
	
	char ch[30], c[3];
	sprintf(ch, "%s %d / %d", ThemSach, curNhapSach, totalNhapSach);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(TEXT_TITLE_COLOR);
	setbkcolor(15);
	outtextxy(1057, 513, ch);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(0);
	line(875,680,Table_x2,680);
	outtextxy(890, 685, "Thong bao:");
	setcolor(TIPS);
//	rectangle(XDMS[0], 800, XDMS[3], 850);
//	
//	setfillstyle(SOLID_FILL, BG_COLOR);
//	bar(XDMS[0]+5, 805, XDMS[3]-5, 845);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
//	outtextxy(XDMS[0]+20, 825-textheight(ThongBao)/2, ThongBao);
//	
	// Draw mess
	outtextxy((1000+(Table_x2-1000)/2)-textwidth(mess)/2, (680+(Table_y2+60-680)/2)-textheight(mess)/2, mess);
	strcpy(mess, "");
}
  
void DrawHieuChinhSach(){
	ClearLayoutSach();
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setbkcolor(15);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((875+(Table_x2-875)/2)-textwidth(HieuChinhSach)/2, 510, HieuChinhSach);
	
	btnHieuChinhSach.draw();
	edHieuChinhMaSach.draw();
	edHieuChinhTrangThaiSach.draw();
	edHieuChinhViTriSach.draw();
	btnBackToNhapSach.draw();
	btnXoaSach.draw();
	setcolor(TIPS);
	setbkcolor(15);

	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
//	// Draw mess
	outtextxy((1000+(Table_x2-1000)/2)-textwidth(mess)/2, (680+(Table_y2+60-680)/2)-textheight(mess)/2, mess);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setbkcolor(15);
	setcolor(0);
	setlinestyle(SOLID_LINE, 0, 3);
	line(875,680,Table_x2,680);
	outtextxy(890, 685, "Thong bao:");
	strcpy(mess, "");
}
void GetHieuChinhDauSach(int i){
	curDauSach = i;
	ClearContentHieuChinhDauSach();
	
	char ch[10];
	strcpy(edHieuChinhISBN.content, DSDS.mang[i]->ISBN);
	strcpy(edHieuChinhTenSach.content, DSDS.mang[i]->TenSach);
	itoa(DSDS.mang[i]->SoTrang, ch, 10);
	strcpy(edHieuChinhSoTrang.content, ch);
	strcpy(edHieuChinhTacGia.content, DSDS.mang[i]->TacGia);
	itoa(DSDS.mang[i]->NamXuatBan ,ch, 10);
	strcpy(edHieuChinhNXB.content, ch);
	strcpy(edHieuChinhTheLoai.content, DSDS.mang[i]->TheLoai);
	
	DrawHieuChinhDauSach();
}

void ItemLeftMouseClick(){
	if(curItem != -1){
		//HIEU CHINH DAU SACH
		Window = HIEU_CHINH_DAU_SACH;
		curHieuChinh = 0;
		strcpy(mess, "");
		if(strlen(edTimDauSach.content) == 0) GetHieuChinhDauSach(13*(curPageDauSach-1) + curItem);
		else GetHieuChinhDauSach(listIndexDauSachSearch[13*(curPageDauSach-1) + curItem]);
		
		//DANH MUC SACH
		curPageSach = 1;
		Edit = NULL;
		ClearContentNhapSoLuongSach();
//		if (CheckSach()) AutoCreateMaSach();
		DrawNhapSach();
		DrawDanhMucSach();
	}
	if(Window == HIEU_CHINH_DAU_SACH){
		if(curItemSach != -1){
			Book = HIEU_CHINH_SACH;
			curSach = curItemSach;
			strcpy(mess, "");
			ClearContentHieuChinhSach();
			NodeSach *nodeSelect = GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curSach);
			strcpy(edHieuChinhMaSach.content, nodeSelect->data.MaSach);
			char ch[2];
			itoa(nodeSelect->data.TrangThai, ch, 10);
			strcpy(edHieuChinhTrangThaiSach.content, ch);
			strcpy(edHieuChinhViTriSach.content, nodeSelect->data.ViTri);
			
			if(nodeSelect->data.TrangThai == 0){
				canEditTrangThai = true;
			}else{
				canEditTrangThai = false;
			}
	
			DrawHieuChinhSach();
		}
	}
}

void ClickSwitchHieuChinh(){
		if (btnXoaDauSach.isMouseHover(mx,my)&&(Book!=HIEU_CHINH_SACH&&Book!=THEM_SACH)){
			subWindow = XOA_ISBN;
			if (curMenu == btnQLDauSach.id){			
				strcpy(mess, "Xac nhan xoa Dau Sach?");
			}else {
				strcpy(mess, "Xac nhan xoa Doc Gia?");
			}
			DrawXoaDauSach();		
		}		
}
void DauSachEvent(){

	ItemEvent();
	
	ButtonEffect(btnQLDocGia);
	ButtonEffect(btnQLSach);
	ButtonEffect(btnThoat);	
	
	if(GetAsyncKeyState(VK_LBUTTON)){
		if(btnQLDocGia.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLDocGia.id);
		}else if(btnQLSach.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLSach.id);
		}else if(btnThoat.isMouseHover(mx, my)){
			isExit = true;
		}
	}


	if (Window == DANH_SACH_SACH){
		ButtonEffect(btnClearTimDauSach);
		ButtonEffect(btnPrevDauSach);
		ButtonEffect(btnNextDauSach);
		ButtonEffect(btnThemDauSach);
	}else if (Window == THEM_DAU_SACH){
		ButtonEffect(btnDanhSach);
		ButtonEffect(btnThemDauSachMini);
	}else if(Window == HIEU_CHINH_DAU_SACH){
		
		if (subWindow == HIEU_CHINH){
			ButtonEffect(btnBackToDanhSachSach);
			ButtonEffect(btnHieuChinhDauSach);
			ButtonEffect(btnXoaDauSach);
			ButtonEffect(btnPrevDanhMucSach);
			ButtonEffect(btnNextDanhMucSach);
		}else if (subWindow == XOA_ISBN ){
			ButtonEffect(btnXacNhanXoaDauSach);
			ButtonEffect(btnHuyXoaDauSach);			
		}
		if (Book == HIEU_CHINH_SACH){
			ButtonEffect(btnHieuChinhSach);
			ButtonEffect(btnBackToNhapSach);
			ButtonEffect(btnXoaSach);
		}else if(Book == NHAP_SACH){
			ButtonEffect(btnNhapSoLuongSach);
		}else if(Book == THEM_SACH){
			ButtonEffect(btnThemSach);
			ButtonEffect(btnBackToNhapSach);
		}else if(Book == XOA_SACH){
			ButtonEffect(btnXacNhanXoaSach);
			ButtonEffect(btnHuyXoaSach);
		}
	}


	// Su kien Click chuot trai 
	if(GetAsyncKeyState(VK_LBUTTON)){
		ClickSwitchDauSach();
		ItemLeftMouseClick();
		
		if(Edit != NULL ){
			int n = strlen(Edit->content);
			Edit->content[n] = ' ';
			Edit->draw();
			Edit->content[n] = '\0';
		}
		
		if(curMenu == btnQLDauSach.id){
			if (Window == DANH_SACH_SACH){
				if(edTimDauSach.isMouseHover(mx, my) ){
					Edit = &edTimDauSach;
				}else if(btnPrevDauSach.isMouseHover(mx, my) ){
					if(curPageDauSach > 1){
						--curPageDauSach;
					//	ClearDanhSachDauSach();
						DrawList();
						DrawDanhSachDauSach();
					}
				}else if(btnNextDauSach.isMouseHover(mx, my)){
					if(curPageDauSach < totalPageDauSach){
						++curPageDauSach;
					//	ClearDanhSachDauSach();
						DrawList();
						DrawDanhSachDauSach();
					}
				}else if(btnClearTimDauSach.isMouseHover(mx, my) ){
					memset(edTimDauSach.content, 0 , sizeof(edTimDauSach.content));
					//ClearDanhSachDauSach();
					DrawList();
					DrawDanhSachDauSach();
				}
			}
			
			// 																			man hinh Them dau sach
			if(Window == THEM_DAU_SACH){
				if(btnThemDauSachMini.isMouseHover(mx, my)){
					// Them dau sach
					// check truoc khi add
					if(CheckDauSach()){
						DauSach *dausach = new DauSach(edThemISBN.trim(), 
									edThemTenSach.trim(), 
									edThemSoTrang.toInt(), 
									edThemTacGia.trim(), 
									edThemNXB.toInt(), 
									edThemTheLoai.trim());
					
						AddDauSach(DSDS, dausach);
						ClearContentThemDauSach();
						strcpy(mess, "Them dau sach thanh cong!");
					}
					DrawThemDauSach();
				}
				
				if(edThemISBN.isMouseHover(mx, my)){
					Edit = &edThemISBN;
				}else if(edThemTenSach.isMouseHover(mx, my)){
					Edit = &edThemTenSach;
				}else if(edThemSoTrang.isMouseHover(mx, my)){
					Edit = &edThemSoTrang;
				}else if(edThemTacGia.isMouseHover(mx, my)){
					Edit = &edThemTacGia;
				}else if(edThemNXB.isMouseHover(mx, my)){
					Edit = &edThemNXB;
				}else if(edThemTheLoai.isMouseHover(mx, my)){
					Edit = &edThemTheLoai;
				}
			}		
			//																Hieu Chinh Dau Sach	
			if(Window == HIEU_CHINH_DAU_SACH){		
				ClickSwitchHieuChinh();
				if (subWindow == HIEU_CHINH){
					if(btnHieuChinhDauSach.isMouseHover(mx, my)){					
						if(curDauSach != -1){
							if(CheckHieuChinhDauSach()){
									DauSach *dausach = new DauSach(edHieuChinhISBN.trim(), 
									edHieuChinhTenSach.trim(), 
									edHieuChinhSoTrang.toInt(), 
									edHieuChinhTacGia.trim(), 
									edHieuChinhNXB.toInt(), 
									edHieuChinhTheLoai.trim());	
															
								UpdateDauSach(DSDS, dausach, curDauSach);
								curDauSach = -1;
								strcpy(mess, "Hieu chinh dau sach thanh cong!");
								ClearContentHieuChinhDauSach();
								Book = NONE;
								DrawHieuChinhDauSach();
															
						}else{
							DrawHieuChinhDauSach();						 	
							Book = NHAP_SACH;
					 		DrawDanhMucSach();
					 		DrawNhapSach();
					 		} 
						}else{
							strcpy(mess, "Dau Sach khong ton tai!");
							DrawHieuChinhDauSach();
						}
					}
					if (curDauSach != -1){
						if(edHieuChinhISBN.isMouseHover(mx, my)){						
							// khong cho phep chinh sua ISBN
							//	Edit = &edHieuChinhISBN;
						}else if(edHieuChinhTenSach.isMouseHover(mx, my)){
							Edit = &edHieuChinhTenSach;
						}else if(edHieuChinhSoTrang.isMouseHover(mx, my)){
							Edit = &edHieuChinhSoTrang;
						}else if(edHieuChinhTacGia.isMouseHover(mx, my)){
							Edit = &edHieuChinhTacGia;
						}else if(edHieuChinhNXB.isMouseHover(mx, my)){
							Edit = &edHieuChinhNXB;
						}else if(edHieuChinhTheLoai.isMouseHover(mx, my)){							
							Edit = &edHieuChinhTheLoai;
						}
					}
					if(btnBackToDanhSachSach.isMouseHover(mx, my) ){
						Window = DANH_SACH_SACH;
						Book = NHAP_SACH;
						ClearDanhSachDauSach();
						ClearContentHieuChinhDauSach();
						strcpy(mess, "");
						DrawList();
						DrawDanhSachDauSach();
					}		
					/////////////////////////////										Danh-Muc-Sach		
					if (Book != NONE){
						if(btnPrevDanhMucSach.isMouseHover(mx, my)){	
							if(curPageSach > 1){
								--curPageSach;
								ClearLayoutDanhMucSach();
								DrawDanhMucSach();
								DrawNhapSach();
							}
						}else if(btnNextDanhMucSach.isMouseHover(mx, my)){
							if(curPageSach < totalPageSach){
								++curPageSach;
								ClearLayoutDanhMucSach();
								DrawDanhMucSach();
								DrawNhapSach();
							}
						}
						if(Book == NHAP_SACH){
							if(btnNhapSoLuongSach.isMouseHover(mx, my)){
								if(CheckSoLuongSach()){
									totalNhapSach = edNhapSoLuongSach.toInt();
									curNhapSach = 1;
									Book = THEM_SACH;
									memset(edThemViTriSach.content, 0, sizeof(edThemViTriSach.content));
									strcpy(mess, "");
									DrawThemSach();
								}
								else DrawNhapSach();
							}					
							if(edNhapSoLuongSach.isMouseHover(mx, my)){
								Edit = &edNhapSoLuongSach;
							}					
						}else if(Book == THEM_SACH){
							if(btnThemSach.isMouseHover(mx, my)){
								// Check them sach
								if(CheckSach()){
									DanhMucSach sach(edThemMaSach.content, edThemTrangThaiSach.toInt(), edThemViTriSach.content);
									InsertLast_NodeSach(DSDS.mang[curDauSach]->dms, sach);
									DSDS.mang[curDauSach]->SoLuong ++;
									DSDS.mang[curDauSach]->maxSach ++;							
								//	ClearContentThemSach();
									ClearRightLayout();
									++curNhapSach;								
									strcpy(mess, "Them sach thanh cong!");
									CheckAuto = true;
									DrawThemSach();
																	
									if(curNhapSach > totalNhapSach){
										ClearContentNhapSoLuongSach();
										Book = NHAP_SACH;
										curNhapSach = -1;
										totalNhapSach = 0;
										DrawNhapSach();
									}							
								}else{
									CheckAuto = false;
									DrawThemSach();
								}						
								DrawDanhMucSach();
							}else if(btnBackToNhapSach.isMouseHover(mx, my)){
								Book = NHAP_SACH;
								DrawNhapSach();
							}		
							if(edThemTrangThaiSach.isMouseHover(mx, my)){
								Edit = &edThemTrangThaiSach;
							}else if(edThemViTriSach.isMouseHover(mx, my)){
								Edit = &edThemViTriSach;
							}	
						}else if(Book == HIEU_CHINH_SACH){
							if(btnHieuChinhSach.isMouseHover(mx, my)){
								if(CheckHieuChinhSach()){
							// update
									NodeSach *nodeSelect = GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curSach);
									DanhMucSach sach(edHieuChinhMaSach.content, edHieuChinhTrangThaiSach.toInt(), edHieuChinhViTriSach.content);
									UpdateNodeSach(nodeSelect, sach);
									ClearRightLayout();
									strcpy(mess, "Hieu chinh sach thanh cong!");
									DrawDanhMucSach();
								}
								DrawHieuChinhSach();
							}else if(btnBackToNhapSach.isMouseHover(mx, my)){
								Book = NHAP_SACH;
								DrawNhapSach();
							}else if(btnXoaSach.isMouseHover(mx,my)){
								Book = XOA_SACH;
								strcpy(mess,"Xac nhan xoa Sach ?");
								DrawXoaSach();								
							}
											
							if(edHieuChinhTrangThaiSach.isMouseHover(mx, my) && canEditTrangThai){
								Edit = &edHieuChinhTrangThaiSach;
							}else if(edHieuChinhViTriSach.isMouseHover(mx, my)){
								Edit = &edHieuChinhViTriSach;
							}
						}else if(Book == XOA_SACH){
							if(btnXacNhanXoaSach.isMouseHover(mx,my)){
								DanhMucSach sach(edHieuChinhMaSach.content, edHieuChinhTrangThaiSach.toInt(), edHieuChinhViTriSach.content);
								if (sach.TrangThai!=1){
									if (curSach==0)	DSDS.mang[curDauSach]->dms=DSDS.mang[curDauSach]->dms->next; else					
									DelSach(DSDS.mang[curDauSach]->dms,8*(curPageSach-1) + curSach);
									DSDS.mang[curDauSach]->SoLuong-- ;
									ClearLayoutDanhMucSach();
									DrawBorderListSach();
									DrawDanhMucSach();
									strcpy(mess,"Xoa Sach thanh cong!");
								}else  strcpy(mess,"Sach DA CHO MUON, khong the xoa");
								Book=NHAP_SACH;
								DrawNhapSach();
								curSach = -1;
							//	XoaSach=false;
							} else if(btnHuyXoaSach.isMouseHover(mx,my)){
									strcpy(mess,"");
								//	Window = HIEU_CHINH_DAU_SACH;
								//	subWindow = HIEU_CHINH_SACH;
									Book = HIEU_CHINH_SACH;
									DrawHieuChinhSach();
							//		XoaSach=false;
							}					
						}
					}						
				}
					//																			 Xoa
				else 
				if (subWindow == XOA_ISBN){				
					if (btnXacNhanXoaDauSach.isMouseHover(mx, my)&&curDauSach != -1){
						if (DSDS.mang[curDauSach]->dms == NULL){
							DeleteISBN(DSDS,  curDauSach);
							strcpy(mess,"Ban da xoa thanh cong!");
							ClearContentHieuChinhDauSach();
							curDauSach = -1;
							subWindow = HIEU_CHINH;
							Book = NONE;
							ClearXoaISBN();
						}else{
							subWindow = HIEU_CHINH;
							strcpy(mess, "Dau Sach da co DMS nen khong the xoa!");
							DrawHieuChinhDauSach();
							DrawDanhMucSach();
						 	DrawNhapSach();
						 	strcpy(mess, "");
						}
						
					}else
					if(btnHuyXoaDauSach.isMouseHover(mx,my)){
						strcpy(mess,"");
						subWindow = HIEU_CHINH;
						DrawHieuChinhDauSach;
						DrawDanhMucSach();
						DrawNhapSach();
					}
				}	
			}
		}
	}
}				

int GetItemPosition(int y){
	int pos = (y-260+8)/30;                                
	int i = 13*(curPageDauSach-1) + pos;				
	if(strlen(edTimDauSach.content) == 0){
		if(i >= DSDS.n) return -1;
	}else{
		if(i >= sizeListIndexDauSachSearch) return -1;
	}
	return pos;
}
int GetItemSachPosition(int y){
	int pos = (y-295)/22;
	int i = 8*(curPageSach-1) + pos;
	if(i >= DSDS.mang[curDauSach]->SoLuong) return -1;
	else return pos;
}

void ItemEvent(){
	if(mx > Table_x1 && mx < Table_x2 && my > 257 && my < 640 && Window == DANH_SACH_SACH){
		if(curItem != GetItemPosition(my)){
			if(curItem != -1){
				// khoi phuc item
				setfillstyle(SOLID_FILL,11);
				bar(Table_x1, 265 + curItem*30 - 8, Table_x2, 265+(curItem+1)*30-8);
								
				DrawBorderList2();
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setcolor(TEXT_COLOR);
				if(strlen(edTimDauSach.content) == 0){
					DrawItemDauSach((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSach(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
				
			}
			
			
			// Ve item hien tai
			curItem = GetItemPosition(my);
			if(curItem != -1){

				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setbkcolor(10);
				setcolor(TEXT_COLOR);
				
				setfillstyle(SOLID_FILL, 10);
				bar(Table_x1, 265 + curItem*30 - 8, Table_x2, 265+(curItem+1)*30-8);
				if(strlen(edTimDauSach.content) == 0){
					DrawItemDauSach((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSach(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
				
				 DrawBorderList2();
			}
		}
	}else{
		if(curItem != -1 && Window == DANH_SACH_SACH){
			// khoi phuc item
			setfillstyle(SOLID_FILL,11);
				bar(Table_x1, 265 + curItem*30 - 8, Table_x2, 265+(curItem+1)*30-8);
								
				DrawBorderList2();
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setcolor(TEXT_COLOR);
				if(strlen(edTimDauSach.content) == 0){
					DrawItemDauSach((curPageDauSach-1)*13 + curItem, -1);
				}else{
					DrawItemDauSach(listIndexDauSachSearch[(curPageDauSach-1)*13 + curItem], curItem);
				}
			curItem = -1;
		} else curItem = -1;
	}
	
if(Window != HIEU_CHINH_DAU_SACH||Book==NONE) return;

		if(mx > 875 && mx < Table_x2 && my > 295&& my < 470){
		
		if(curItemSach != GetItemSachPosition(my)){
			if(curItemSach != -1){
				setfillstyle(SOLID_FILL, 15);
				bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				
				setbkcolor(15);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setcolor(TIPS);
				DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
				DrawBorderListSach();
			}
			curItemSach = GetItemSachPosition(my);
			if(curItemSach != -1){
				setfillstyle(SOLID_FILL, 11);
				bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				setbkcolor(11);
				setcolor(TIPS);
				DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
				DrawBorderListSach();
			}
		}
	}else{
		if(curItemSach != -1){
			// khoi phuc item
			setfillstyle(SOLID_FILL, 15);
			bar(875, 295 + curItemSach*22 , Table_x2, 295+(curItemSach+1)*22+3);
				
			setbkcolor(15);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			setcolor(TIPS);
			DrawItemSach(GetNodeSach(DSDS.mang[curDauSach]->dms, 8*(curPageSach-1) + curItemSach)->data, curItemSach);
			DrawBorderListSach();
			curItemSach = -1;
		}
	}
}

void ClickSwitchDauSach(){
	if (btnThemDauSach.isMouseHover(mx,my)&& Window == DANH_SACH_SACH){
		if(!btnThemDauSach.isChoose){
			btnThemDauSach.isChoose = true;
			btnDanhSach.isChoose = false;
			Window = THEM_DAU_SACH;
			ClearDanhSachDauSach();
			DrawThemDauSach();			
		}
	}else
	if (btnDanhSach.isMouseHover(mx,my)){
		if(!btnDanhSach.isChoose){
			btnDanhSach.isChoose = true;
			btnThemDauSach.isChoose = false;
			Window = DANH_SACH_SACH;
			ClearDanhSachDauSach();
			DrawList();
			DrawDanhSachDauSach();	
			
			
		}
	}
		

}
