void RunDocGia(){
	strcpy(mess, "");
	Window = DS_DOC_GIA;
	btnSapXepTen.isChoose = sortDGByName;
	btnSapXepMaThe.isChoose = !btnSapXepTen.isChoose; 
	btnSapXepTen.isHover = sortDGByName;
	btnSapXepMaThe.isHover = !sortDGByName;
	
	btnSapXepTen.draw();
	btnSapXepMaThe.draw();

	btnTatCaDocGia.isHover = true;
	btnTatCaDocGia.isChoose = true;
	btnDocGiaQuaHan.isChoose = false;
	btnDocGiaQuaHan.isHover = false;
	
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	
	if (Window == DS_DOC_GIA) {
		DrawListDocGia(true);
		DrawDanhSachDocGia();
	}else if(Window == THEM_DOC_GIA){
		DrawThemDocGia(true);
	}else if(Window == HIEU_CHINH_DOC_GIA){
		DrawHieuChinhDocGia();
	}

	btnDSDocGia.isChoose = true;
	btnDSDocGia.isHover = true;
	btnAddDocGia.isChoose = false;
	btnAddDocGia.isHover = false;
	btnDSDocGia.draw();
	btnAddDocGia.draw();
}
void ButtonSwitchClick(){
	if (btnAddDocGia.isMouseHover(mx,my)){
		if(!btnAddDocGia.isChoose){
			btnAddDocGia.isChoose = true;
			btnDSDocGia.isChoose = false;
			Window = THEM_DOC_GIA;
			strcpy(mess, "");
			ClearDanhSachDauSach();
			DrawThemDocGia(true);
			btnAddDocGia.draw();
		}
	}else
	if (btnDSDocGia.isMouseHover(mx,my)){
		if(!btnDSDocGia.isChoose){
			btnDSDocGia.isChoose = true;
			btnAddDocGia.isChoose = false;
			Window = DS_DOC_GIA;
			strcpy(mess, "");
			ClearDanhSachDauSach();
			DrawListDocGia(true);
			DrawDanhSachDocGia();	
		}
	}
	if(btnTatCaDocGia.isMouseHover(mx, my)){
		if(!btnTatCaDocGia.isChoose){
			btnDocGiaQuaHan.isChoose = false;
			btnTatCaDocGia.isChoose = true;
			curItemDG = -1;
			// Get list docgia
			DSDG.GetAllDocGia(TreeDocGia);
			Window = DS_DOC_GIA;
			DrawListDocGia(true);
			DrawDanhSachDocGia(); 
			btnSapXepTen.draw();
			btnSapXepMaThe.draw();
			btnAddDocGia.draw();
			btnDSDocGia.draw();
		}
	}else if(btnDocGiaQuaHan.isMouseHover(mx, my)){
		if(!btnDocGiaQuaHan.isChoose){
			btnTatCaDocGia.isChoose = false;
			btnDocGiaQuaHan.isChoose = true;
			curItemDG = -1;
			Window = DOC_GIA_QUA_HAN;
			// Get list docgia qua han
			DSDG.GetDocGiaQuaHan(TreeDocGia);
			DrawListDocGia(true);
			
			btnAddDocGia.draw();
			btnDSDocGia.draw();
			btnDocGiaQuaHan.draw();
			btnTatCaDocGia.draw();
				 
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			setbkcolor(15);
			setcolor(TIPS);
			outtextxy(330, 220, "Danh sach: ");
		}
	}
	
	if(btnSapXepTen.isMouseHover(mx, my)){
		if(!sortDGByName){
			sortDGByName = true;
			DrawListDocGia(true);
			DrawDanhSachDocGia(); 
			
		}
	}else if(btnSapXepMaThe.isMouseHover(mx, my)){
		if(sortDGByName){
			sortDGByName = false;
			DrawListDocGia(true);
			DrawDanhSachDocGia(); 
			
		}
	}
	btnSapXepTen.isChoose = sortDGByName;
	btnSapXepMaThe.isChoose = !sortDGByName;
}
void AutoGenMaDocGia(){
	nodeStart = Node_ID_Random();
	if(nodeStart != NULL){
		int ranID = rand()%(nodeStart->next->id - nodeStart->id - 1) + nodeStart->id + 1;
		itoa(ranID, edThemMaTheDocGia.content, 10);
	}else{
		strcpy(edThemMaTheDocGia.content, "OVERFLOW");
	}
	
}
void DrawDanhSachDocGia(){
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 6);
	setcolor(TEXT_TITLE_COLOR);
	setfillstyle(SOLID_FILL,BG_COLOR);
	bar(500,60,1300,120);
	outtextxy((BigTable_x1+(BigTable_x2-BigTable_x1)/2-textwidth(DocGiaTitle)/2), 70, DocGiaTitle);
	setbkcolor(15);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	outtextxy(330, 220, "Danh sach: ");
	
	if(Window == DS_DOC_GIA && btnTatCaDocGia.isChoose==true ) {
		outtextxy(660, 220, "Sap xep theo:");
		btnSapXepTen.draw();
		btnSapXepMaThe.draw();
	}
	
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	btnPrevDocGia.draw();
	btnNextDocGia.draw();
	btnDSDocGia.draw();
	btnAddDocGia.draw();

}
void DrawListDocGia(bool reload){
	char chPage[20];
	if(reload && btnTatCaDocGia.isChoose) DSDG.GetAllDocGia(TreeDocGia);
	if(btnTatCaDocGia.isChoose){
		DrawBorderDSDocGia();
		setcolor(TEXT_COLOR);
		if(sortDGByName){
			DSDG.SortTenDocGia();
		}else{
			DSDG.SortMaTheDocGia();	
		}
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
	}else if(btnDocGiaQuaHan.isChoose){
		DrawBorderDSDocGiaQuaHan();
		totalPageDGQuaHan = (DSDG.n-1)/13 + 1;
		for(int i=13*(curPageDGQuaHan-1); i < 13*curPageDGQuaHan; i++){
			if(i >= DSDG.n) break;
			DrawItemDocGiaQuaHan(*DSDG.nodes[i], DSDG.soNgayQH[i], i);
		}
		// num page
		setbkcolor(15);
		sprintf(chPage, "TRANG %d / %d", curPageDGQuaHan, totalPageDGQuaHan);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy((XDGQH[0]+XDGQH[6])/2 - textwidth(chPage)/2, 715, chPage);
		
		btnPrevDocGiaQH.draw();
		btnNextDocGiaQH.draw();		
	}
}

void DrawBorderDSDocGia(){
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
void DrawItemDocGia(DocGia &docgia, int i){
	setcolor(TEXT_COLOR);
	i %= 13;
	char ch[6];
	itoa(docgia.MATHE, ch, 10);
	outtextxy(XDG[0] + (XDG[1]-XDG[0])/2-textwidth(ch)/2, 310 + i*30, ch);
	outtextxy(XDG[1] + 10, 310 + i*30, docgia.ho);
	outtextxy(XDG[2] + 10, 310 + i*30, docgia.ten);
	outtextxy(XDG[3] + 30, 310 + i*30, PhaiDocGia[docgia.phai]);
	outtextxy(XDG[4] + 70, 310 + i*30, TTTDocGia[docgia.trangthai]);
}

void DrawItemDocGiaQuaHan(DocGia &docgia, int soNgayQH, int i){
	setcolor(TEXT_COLOR);
	i %= 13;
	char ch[6];
	itoa(docgia.MATHE, ch, 10);
	outtextxy(XDG[0] + (XDG[1]-XDG[0])/2-textwidth(ch)/2, 310 + i*30, ch);
	outtextxy(XDGQH[1] + 10, 310 + i*30, docgia.ho);
	outtextxy(XDGQH[2] + 10, 310 + i*30, docgia.ten);
	outtextxy(XDGQH[3] + 30, 310 + i*30, PhaiDocGia[docgia.phai]);
	outtextxy(XDGQH[4] + 40, 310 + i*30, TTTDocGia[docgia.trangthai]);
	sprintf(ch, "%d", soNgayQH);
	outtextxy(XDGQH[5]+70, 310 + i*30, ch);
}
void DrawBorderDGList2(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	line(Table_x1 ,Table_y1 + 85, Table_x2, Table_y1 + 85);
	for(int i=1; i < 5; i++){
		line(LTBDG[i], Table_y1+50, LTBDG[i], Table_y2+50);
	}
}
void DrawBorderDSDocGiaQuaHan2(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
    line(Table_x1 ,Table_y1 + 85, Table_x2, Table_y1 + 85);
   line(Table_x1 ,Table_y1+50 , Table_x2, Table_y1 +50); 
	for(int i=0; i < 6; i++){
		line(XDGQH[i], Table_y1+50, XDGQH[i], Table_y2+50);
	}
}
void DrawBorderDSDocGiaQuaHan(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
	rectangle(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	
	setfillstyle(SOLID_FILL,11);
	bar(Table_x1, Table_y1+50, Table_x2, Table_y2+50);
	
    line(Table_x1 ,Table_y1 + 85, Table_x2, Table_y1 + 85);
    line(Table_x1 ,Table_y1+50 , Table_x2, Table_y1 +50); 
    
	for(int i=0; i < 6; i++){
		line(XDGQH[i], Table_y1+50, XDGQH[i], Table_y2+50);
	}

	char ch[7][20] = {"Ma the", "Ho", "Ten", "Phai", "Trang thai the", "So ngay qua han"};
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 6; i++){
		setbkcolor(11);
		outtextxy(XDGQH[i] + (XDGQH[i+1]-XDGQH[i])/2 - textwidth(ch[i])/2, 275, ch[i]);
	}
}

void DrawThemDocGia(bool genNewID){
	setbkcolor(15);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle(Table_x1+20, Table_y1+40, Table_x2-20, Table_y2);
	line(990,Table_y1+40,990,Table_y2);
	line(990,320,Table_x2-20,320);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((Table_x1+20)+(Table_x2-20-Table_x1-20)/2 - textwidth(ThemDocGia)/2, 245 - textheight(ThemDocGia)/2, ThemDocGia);
	setcolor(TIPS);
	outtextxy(1195-textwidth(ThongBao)/2,290-textheight(ThongBao)/2, ThongBao);
	setfillstyle(SOLID_FILL, 15);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	bar(990+2,320+2,Table_x2-20-2,Table_y2-2);
	outtextxy(1000 , 360, mess);
	
	if(genNewID) AutoGenMaDocGia();
	strcpy(edThemTrangThaiTheDocGia.content, "1");
	
	edThemMaTheDocGia.draw();
	edThemHoDocGia.draw();
	edThemTenDocGia.draw();
	edThemPhaiDocGia.draw();
	edThemTrangThaiTheDocGia.draw();
	btnThemDocGia.draw();
} 
void DrawHieuChinhDocGia(){
	setbkcolor(15);
	setfillstyle(SOLID_FILL,15);
	bar(BigTable_x1,BigTable_y1,BigTable_x2,BigTable_y2);
	rectangle(Table_x1+20, Table_y1+40, Table_x2-20, Table_y2);
	line(990,Table_y1+40,990,Table_y2);
	line(990,320,Table_x2-20,320);
	line(990,400,Table_x2-20,400);
	line(990,500,Table_x2-20,500);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((Table_x1+20)+(Table_x2-20-Table_x1-20)/2 - textwidth(HieuChinhDocGia)/2, 245 - textheight(HieuChinhDocGia)/2, HieuChinhDocGia);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TIPS);
	outtextxy(1195-textwidth(ThongBao)/2,290-textheight(ThongBao)/2, ThongBao);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(1195-textwidth(MuonSach)/2,400-textheight(MuonSach)/2, MuonSach);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(1000 , 340, mess);
	
	
	edHieuChinhMaTheDocGia.draw();
	edHieuChinhHoDocGia.draw();
	edHieuChinhTenDocGia.draw();
	edHieuChinhPhaiDocGia.draw();
	edHieuChinhTrangThaiTheDocGia.draw();
	btnHieuChinhDocGia.draw();
	btnDSDocGia.draw();
	btnAddDocGia.draw();
	btnBackToDSDocGia.draw();
	btnXoaDocGia.draw();
} 
void DrawMuonSachDG(int i){
	if(i != -1){
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
		setcolor(0);
		curDG = i;
		setbkcolor(15);
		char ch[50];
		outtextxy(1000, 420, "So sach dang muon :");
		itoa(DSDG.nodes[i]->mt.chuaTra, ch, 10);
		outtextxy(1200, 420, ch);
		
		outtextxy(1000, 460, "Tong so sach da muon :");
		itoa(DSDG.nodes[i]->mt.total, ch, 10);
		outtextxy(1230, 460, ch);	
	}
	setbkcolor(15);
	setcolor(4);
	outtextxy(1000 , 340, mess);
}




void ClearContentThemDocGia(){
	memset(edThemMaTheDocGia.content, 0, sizeof(edThemMaTheDocGia.content));	
	memset(edThemHoDocGia.content, 0, sizeof(edThemHoDocGia.content));	
	memset(edThemTenDocGia.content, 0, sizeof(edThemTenDocGia.content));	
	memset(edThemPhaiDocGia.content, 0, sizeof(edThemPhaiDocGia.content));	
	memset(edThemTrangThaiTheDocGia.content, 0, sizeof(edThemTrangThaiTheDocGia.content));	
}
void ClearContentHieuChinhDocGia(){
	memset(edHieuChinhMaTheDocGia.content, 0, sizeof(edHieuChinhMaTheDocGia.content));	
	memset(edHieuChinhHoDocGia.content, 0, sizeof(edHieuChinhHoDocGia.content));	
	memset(edHieuChinhTenDocGia.content, 0, sizeof(edHieuChinhTenDocGia.content));	
	memset(edHieuChinhPhaiDocGia.content, 0, sizeof(edHieuChinhPhaiDocGia.content));	
	memset(edHieuChinhTrangThaiTheDocGia.content, 0, sizeof(edHieuChinhTrangThaiTheDocGia.content));	
}

bool CheckThemDocGia(){
	if(strcmp(edThemMaTheDocGia.content, "OVERFLOW") == 0){
		strcpy(mess, "So luong doc gia dat gioi han");
		return false;
	}
	if(strlen(edThemHoDocGia.content) == 0){
		strcpy(mess, "Ho va ten dem khong duoc bo trong");
		Edit = &edThemHoDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edThemTenDocGia.content) == 0){
		strcpy(mess, "Ten khong duoc bo trong");
		Edit = &edThemTenDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edThemPhaiDocGia.content) == 0){
		strcpy(mess, "Phai khong duoc bo trong");
		Edit = &edThemPhaiDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edThemTrangThaiTheDocGia.content) == 0){
		strcpy(mess, "TT the khong duoc bo trong");
		Edit = &edThemTrangThaiTheDocGia;
		Edit->draw();
		return false;
	}else if(edThemTrangThaiTheDocGia.toInt() == 0){
		strcpy(mess, "TT the ban dau khong the:KHOA");
		Edit = &edThemTrangThaiTheDocGia;
		Edit->draw();
		return false;
	}
	return true;
}
bool CheckHieuChinhDocGia(){
	if(strlen(edHieuChinhHoDocGia.content) == 0){
		strcpy(mess, "Ho va ten dem khong duoc bo trong");
		Edit = &edHieuChinhHoDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhTenDocGia.content) == 0){
		strcpy(mess, "Ten khong duoc bo trong");
		Edit = &edHieuChinhTenDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhPhaiDocGia.content) == 0){
		strcpy(mess, "Phai khong duoc bo trong");
		Edit = &edHieuChinhPhaiDocGia;
		Edit->draw();
		return false;
	}else if(strlen(edHieuChinhTrangThaiTheDocGia.content) == 0){
		strcpy(mess, "Trang thai the khong duoc bo trong");
		Edit = &edHieuChinhTrangThaiTheDocGia;
		Edit->draw();
		return false;
	}
	return true;
}
int GetItemDocGiaPosition(int y){
	int pos = (y-316+8)/30;
	int i;
	if(btnTatCaDocGia.isChoose){
		i = 13*(curPageDG-1) + pos;
	}else{
		i = 13*(curPageDGQuaHan-1) + pos;
	}
	if(i >= DSDG.n) return -1;
	return pos;
}
void GetHieuChinhDocGia(int i){
	curDG = i;
	ClearContentHieuChinhDocGia();
	char ch[10];
	itoa(DSDG.nodes[i]->MATHE, ch, 10);
	strcpy(edHieuChinhMaTheDocGia.content, ch);
	strcpy(edHieuChinhHoDocGia.content, DSDG.nodes[i]->ho);
	strcpy(edHieuChinhTenDocGia.content, DSDG.nodes[i]->ten);
	itoa(DSDG.nodes[i]->phai, ch, 10);
	strcpy(edHieuChinhPhaiDocGia.content, ch);
	itoa(DSDG.nodes[i]->trangthai, ch, 10);
	strcpy(edHieuChinhTrangThaiTheDocGia.content, ch);
	DrawHieuChinhDocGia();
}
void ItemDGLeftMouseClick(){
	if(curItemDG != -1){
		strcpy(mess, "");
		Window = HIEU_CHINH_DOC_GIA;
		if(btnTatCaDocGia.isChoose)
			GetHieuChinhDocGia(13*(curPageDG-1) + curItemDG);
		else
			GetHieuChinhDocGia(13*(curPageDGQuaHan-1) + curItemDG);
		btnAddDocGia.draw();
		btnDSDocGia.draw();
	}
}

void DocGiaEvent(){
	ButtonEffect(btnQLDauSach);
	ButtonEffect(btnQLSach);
	ButtonEffect(btnThoat);	
	ButtonEffect(btnDSDocGia);
	ButtonEffect(btnAddDocGia);
	if(GetAsyncKeyState(VK_LBUTTON)){
		if(btnQLDauSach.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLDauSach.id);
		}else if(btnQLSach.isMouseHover(mx, my)){
			SetMenuSelect(0);
			SetMenuSelect(btnQLSach.id);
		}else if(btnThoat.isMouseHover(mx, my)){
			isExit = true;
		}
	}
	if (Window == DS_DOC_GIA){
		ButtonEffect(btnAddDocGia);
		ButtonEffect(btnTatCaDocGia);
		ButtonEffect(btnDSDocGia);
		ButtonEffect(btnDocGiaQuaHan);
		ButtonEffect(btnPrevDocGia);
		ButtonEffect(btnNextDocGia);
		ButtonEffect(btnSapXepTen);
		ButtonEffect(btnSapXepMaThe);
	}else if (Window == THEM_DOC_GIA){
		ButtonEffect(btnAddDocGia);
		ButtonEffect(btnDSDocGia);
		ButtonEffect(btnThemDocGia);
		
	}else if(Window == HIEU_CHINH_DOC_GIA){
		ButtonEffect(btnAddDocGia);
		ButtonEffect(btnDSDocGia);
		ButtonEffect(btnHieuChinhDocGia);
		ButtonEffect(btnBackToDSDocGia);
		ButtonEffect(btnXoaDocGia);
	
	}else if(Window == DOC_GIA_QUA_HAN){
		ButtonEffect(btnAddDocGia);
		ButtonEffect(btnDSDocGia);
		ButtonEffect(btnTatCaDocGia);
		ButtonEffect(btnDocGiaQuaHan);
		ButtonEffect(btnPrevDocGiaQH);
		ButtonEffect(btnNextDocGiaQH);
	} else if(Window == XOA_DOC_GIA){
		ButtonEffect(btnXacNhanXoaDocGia);
		ButtonEffect(btnHuyXoaDocGia);
		ButtonEffect(btnBackToDSDocGia);
	}
	
	ItemDocGiaEvent();

	if(GetAsyncKeyState(VK_LBUTTON)){
		ButtonSwitchClick();
		ItemDGLeftMouseClick();		
		if(Window == THEM_DOC_GIA){
			if(btnThemDocGia.isMouseHover(mx, my)){
				if(CheckThemDocGia()){
					DocGia docgia(edThemMaTheDocGia.toInt(), 
								edThemHoDocGia.trim(), 
								edThemTenDocGia.trim(), 
								edThemPhaiDocGia.toInt(), 
								edThemTrangThaiTheDocGia.toInt());
					InsertDocGia(TreeDocGia, docgia);
					insertAfter_ID(nodeStart, edThemMaTheDocGia.toInt());
					strcpy(mess, "Them doc gia thanh cong!");
					ClearContentThemDocGia();
					DrawThemDocGia(true);
				}else{
					DrawThemDocGia(false);
				}	
			}
			if(edThemHoDocGia.isMouseHover(mx, my)){
				Edit = &edThemHoDocGia;
			}else if(edThemTenDocGia.isMouseHover(mx, my)){
				Edit = &edThemTenDocGia;
			}else if(edThemPhaiDocGia.isMouseHover(mx, my)){
				Edit = &edThemPhaiDocGia;
			}else if(edThemTrangThaiTheDocGia.isMouseHover(mx, my)){
				Edit = &edThemTrangThaiTheDocGia;
			}
		}
		else if(Window == HIEU_CHINH_DOC_GIA){
			if(btnHieuChinhDocGia.isMouseHover(mx, my)){
				if(curDG != -1){
				 if(CheckHieuChinhDocGia()){
					DocGia docgia(edHieuChinhMaTheDocGia.toInt(), 
									edHieuChinhHoDocGia.trim(), 
									edHieuChinhTenDocGia.trim(), 
									edHieuChinhPhaiDocGia.toInt(), 
									edHieuChinhTrangThaiTheDocGia.toInt());
					UpdateDocGia(TreeDocGia, docgia);
					strcpy(mess, "Hieu chinh doc gia thanh cong!");
					ClearContentHieuChinhDocGia();
					curDG = -1;
				 }
				}else {
					strcpy(mess, "Doc gia khong ton tai!");
				}
				DrawHieuChinhDocGia();
			} 
			if(curDG != -1){
				if(edHieuChinhHoDocGia.isMouseHover(mx, my)){
					Edit = &edHieuChinhHoDocGia;
				}else if(edHieuChinhTenDocGia.isMouseHover(mx, my)){
					Edit = &edHieuChinhTenDocGia;
				}else if(edHieuChinhPhaiDocGia.isMouseHover(mx, my)){
					Edit = &edHieuChinhPhaiDocGia;
				}else if(edHieuChinhTrangThaiTheDocGia.isMouseHover(mx, my)){
					Edit = &edHieuChinhTrangThaiTheDocGia;
				}	
			}
			strcpy(mess, "");
			DrawMuonSachDG(curDG);
			if (btnXoaDocGia.isMouseHover(mx,my)){
				if (curDG !=-1){
					strcpy(mess, "");
					Window = XOA_DOC_GIA;
					settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
					setcolor(TIPS);
					setbkcolor(15);
					outtextxy(1195-textwidth("Xac nhan xoa Doc Gia?")/2,540-textheight("Xac nhan xoa Doc Gia?")/2, "Xac nhan xoa Doc Gia?");
					btnXacNhanXoaDocGia.draw();
					btnHuyXoaDocGia.draw();
					DrawMuonSachDG(curDG);
				}else {
					strcpy(mess, "Doc gia khong ton tai!");
					DrawHieuChinhDocGia();
				}
			}
		}
		if(Window == XOA_DOC_GIA){	
			if(btnXacNhanXoaDocGia.isMouseHover(mx, my) && curDG != -1)
				// neu doc gia k muon sach nao thi co the xoa
				if(DSDG.nodes[curDG]->mt.chuaTra == 0){
					ClearContentHieuChinhDocGia();
					delete_ID(DSDG.nodes[curDG]->MATHE);
					RemoveDocGia(TreeDocGia, DSDG.nodes[curDG]->MATHE);
					strcpy(mess, "Xoa doc gia thanh cong!");
					curDG = -1;
					Window = HIEU_CHINH_DOC_GIA;
					DrawHieuChinhDocGia();
				}else{
					// Doc gia dang muon sach -> k the xoa
					Window = HIEU_CHINH_DOC_GIA;
					DrawHieuChinhDocGia();
					strcpy(mess, "Doc gia dang muon sach nen khong the xoa!");
					DrawMuonSachDG(curDG);
				}
				if(btnHuyXoaDocGia.isMouseHover(mx, my) && Window != HIEU_CHINH_DOC_GIA){
					strcpy(mess, "");
					Window = HIEU_CHINH_DOC_GIA;
					DrawHieuChinhDocGia();
					DrawMuonSachDG(curDG);
				}
			}
		if(btnBackToDSDocGia.isMouseHover(mx, my) && Window != DS_DOC_GIA){
			strcpy(mess, "");
			Window = DS_DOC_GIA;
			DrawListDocGia(true);
			DrawDanhSachDocGia();
		}
		if(btnTatCaDocGia.isChoose){
			// Tat ca Doc gia - MODE
			if(btnPrevDocGia.isMouseHover(mx, my)){
				if(curPageDG > 1){
					curPageDG--;
					DrawListDocGia(true);
					DrawDanhSachDocGia();
				}
			}else if(btnNextDocGia.isMouseHover(mx, my)){
				if(curPageDG < totalPageDG){
					curPageDG ++;
					DrawListDocGia(true);
					DrawDanhSachDocGia();
				}
			}
		}else{
		//	 Doc Gia Qua Han - MODE
			if(btnPrevDocGiaQH.isMouseHover(mx, my)){
				if(curPageDGQuaHan > 1){
					curPageDGQuaHan--;
					DrawListDocGia(true);
				}
			}else if(btnNextDocGiaQH.isMouseHover(mx, my)){
				if(curPageDGQuaHan < totalPageDGQuaHan){
					curPageDGQuaHan ++;
					DrawListDocGia(true);
				}
			}	
		}
	}
}


void ItemDocGiaEvent(){
	if(mx > Table_x1 && mx < Table_x2 && my > 307 && my < 692 && (Window == DS_DOC_GIA||Window == DOC_GIA_QUA_HAN)){	
		if(curItemDG != GetItemDocGiaPosition(my)){
			if(curItemDG != -1&& (Window == DS_DOC_GIA||Window == DOC_GIA_QUA_HAN)){
				// khoi phuc item
				setfillstyle(SOLID_FILL, 11);
				bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
				setbkcolor(11);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setcolor(TEXT_COLOR);
				if(btnTatCaDocGia.isChoose){
					DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
					DrawBorderDGList2();
				}
				else{
					DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
					DrawBorderDSDocGiaQuaHan2();
				}
			}
			// Ve item hien tai
			curItemDG = GetItemDocGiaPosition(my);
			if(curItemDG != -1 && (Window == DS_DOC_GIA||Window == DOC_GIA_QUA_HAN)){
				setfillstyle(SOLID_FILL, 10);
				bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
				setbkcolor(10);
				setcolor(TEXT_COLOR);
				if(btnTatCaDocGia.isChoose){
					DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
					DrawBorderDGList2();
				}
				else{
					DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
					DrawBorderDSDocGiaQuaHan2();
				}
			}
		}
	}else{
		if(curItemDG != -1 && (Window == DS_DOC_GIA||Window == DOC_GIA_QUA_HAN)){
			// khoi phuc item
			setfillstyle(SOLID_FILL, 11);
			bar(Table_x1, 316 + curItemDG*30 - 8, Table_x2, 316+(curItemDG+1)*30-8);
			setbkcolor(11);
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
			setcolor(TEXT_COLOR);
			if(btnTatCaDocGia.isChoose){
				DrawItemDocGia(*DSDG.nodes[(curPageDG-1)*13 + curItemDG], (curPageDG-1)*13 + curItemDG);
				DrawBorderDGList2();
			}
			else{
				DrawItemDocGiaQuaHan(*DSDG.nodes[(curPageDGQuaHan-1)*13 + curItemDG], DSDG.soNgayQH[(curPageDGQuaHan-1)*13 + curItemDG], (curPageDGQuaHan-1)*13 + curItemDG);
				DrawBorderDSDocGiaQuaHan2();
			}			
			curItemDG = -1;
		} else 	curItemDG = -1;
	}
}





