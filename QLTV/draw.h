// lay max width, height cua man hinh
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

Window Window;
SubWindow subWindow;
Type Book;

int curMenu = 0, curMenuMuonTra;
int curItem = -1, curItemSach = -1, curDauSach = -1, curSach = -1, curHieuChinh = -1;
int curItemDG = -1, curDG = -1;
int curItemDGMS = -1, curDGMS = -1;
int curItemMT = -1, curMT = -1;
DocGia *curDGMT = NULL;
DauSach *curDSMT = NULL;
DanhMucSach *curSachMT = NULL;
Node_ID *nodeStart = NULL;
bool isExit = false;
bool canEditTrangThai = true; 

DS_DauSach DSDS;

// toa do chuot hien tai
int mx = -1, my = -1;
int totalPageDauSach = 1, curPageDauSach = 1;
int totalPageSach = 1, curPageSach = 1;
int totalPageDG = 1, curPageDG = 1;
int totalNhapSach = 0, curNhapSach = 0;
int startIndexSach = -1;
int curMenuDocGia=-1;
int totalPageDGQuaHan = 1, curPageDGQuaHan = 1;
// hoanh do x cua Dau Sach
int XDS[6] = {400, 500, 865, 1030, 1200, 1315};
// X Danh Muc Sach
int XDMS[4] = {1120, 1350, 1600, w-20};
// X Danh sach Doc Gia
int XDG[7] = {330,460, 880,1060,1160,1420};

int XDGQH[8] = {330,460, 780,960,1060,1250,1420};
// X Muon Tra sach
int XMT[5] = {340, 430, 690, 800, 930};
int XDGMT[6] = {330,410, 660,760,1160,1420};
int XDSMT[5] = {950, 1220, 1410};
// X Top 10
int XTT[] = {330, 380, 460, 730, 830, 1010, 1100, 1270, 1420};


bool mclick = false;
bool XoaSach=false;
bool CheckAuto = true;
DS_DocGia DSDG;
NodeDocGia *TreeDocGia = NULL;
char *TrangThaiSach[15] = {"CHO MUON DUOC", "DA CHO MUON", "DA THANH LY"};
char *PhaiDocGia[5] = {"NAM", "NU"};
char *TTTDocGia[10] = {"KHOA", "HOAT DONG"};
char NhapSach[] = "NHAP SACH";
char ThemSach[] = "THEM SACH: ";
char TTMuonTra[][10] = {"DANG MUON", "DA TRA", "LAM MAT"};
// Dinh nghia cac Title
char AppTitle[] = "QUAN LY THU VIEN";
char DMS[80] = "DMS";
char DauSachTitle[] = "DANH SACH DAU SACH";
char ThemDauSach[] = "THEM DAU SACH";
char HieuChinhDauSach[] = "HIEU CHINH DAU SACH";
char HieuChinhSach[] = "HIEU CHINH SACH";
//char *TrangThaiSach[15] = {"CMD", "DCM", "DTL"};
char DocGiaTitle[] = "DANH SACH DOC GIA";
char HieuChinhDocGia[] = "HIEU CHINH DOC GIA";
char ThemDocGia[] = "THEM DOC GIA";
char ThongBao[] = "THONG BAO";
char MuonSach[] = "MUON SACH";
char TraSach[] = "TRA SACH";
char TopTen[] = "TOP 10 CUON SACH MUON NHIEU NHAT";
char DSDM[] = "CAC SACH DANG MUON";
char mess[50];
bool sortDGByName = false;
bool canMT = false; // Doc Gia co the muon sach hay khong?
//bool canEditTrangThai = true; 

EditText *Edit = NULL;
// Hoanh do cac MiniTitle
int MiniTitle_x = 600;
int MiniTitle_y = 70; 

// Hoanh do table
int Table_x1 = 330, Table_y1 = 220;
int Table_x2 = 1420, Table_y2 = 650;
int BigTable_x1 = 300, BigTable_y1 = 150;
int BigTable_x2 = 1450, BigTable_y2 = 750;

// Hoanh do line_doc_table
int LTB[7] = {330, 440, 840,960, 1160,1250,1420};
int LTBDG[6] = {330,460, 880,1060,1160,1420};

// Main Menu
int btnHei = 100, btnWid = 200;
Button btnQLDauSach(100, 40, 200, btnWid, btnHei, "Quan Ly Sach",1,9,0);
Button btnQLDocGia(101, 40, 400, btnWid, btnHei, "Doc Gia",1,9,0);
Button btnQLSach(102, 40, 600, btnWid, btnHei, "Muon Tra Sach",1,9,0);
Button btnThoat(104, 1538-39, 0, 40, 39, "X",4,12,-1);

//	Dau Sach
Button btnClearTimDauSach(201, 1320, 170, 100, 30, "CLEAR", 1,9,0);
Button btnPrevDauSach(202,330,660,100,25,"< Prev",1,9,0);
Button btnNextDauSach(203,1320,660,100,25,"Next >",1,9,0);
Button btnThemDauSach(204,510,170,180,30,"Them Dau Danh",1,9,0);
Button btnDanhSach(205,330,170,180,30,"Danh Sach",1,9,0);
Button btnBackToDanhSachSach(400, 335, 225, 80, 30, "< BACK",8,7, 0);
EditText edTimDauSach(2000, 920, 170, 400, 30, "Tim dau sach:", "", "Nhap ten sach vao day");
//Button btnBackToDanhSachSach(206, 1120, 170, 100, 30, "< BACK", 1,9,0);
// Them Dau Sach
EditText edThemISBN(2002, Table_x1+70, 300, 550, 40, "ISBN :","","Chi nhan so va chu cai, toi da 10 ki tu");
EditText edThemTenSach(2003, Table_x1+70, 350, 550, 40, "Ten sach :","","Chi nhan chu cai va so, toi da 30 ki tu");
EditText edThemSoTrang(2004,Table_x1+70, 400, 550, 40, "So trang :","","Chi nhan so, toi da 5 ki tu");
EditText edThemTacGia(2005,Table_x1+70, 450, 550, 40, "Tac gia :","","Chi nhan chu cai, toi da 30 ki tu");
EditText edThemNXB(2006,Table_x1+70, 500, 550, 40, "Nam xuat ban :","","Chi nhan so");
EditText edThemTheLoai(2007,Table_x1+70, 550, 550, 40, "The loai :","","Chi nhan chu cai, toi da 20 ki tu");

Button btnThemDauSachMini(207, 595, 610, 150, 30, "THEM",1,9,0);	
//Hieu Chinh Dau Sach
EditText edHieuChinhISBN(2008, Table_x1+20, 295, 500, 40, "ISBN :","","Chi nhan so va chu cai, toi da 10 ki tu");
EditText edHieuChinhTenSach(2009, Table_x1+20, 345, 500, 40, "Ten sach :","","Chi nhan chu cai va so, toi da 30 ki tu");
EditText edHieuChinhSoTrang(2010, Table_x1+20, 395, 500, 40, "So trang :","","Chi nhan so, toi da 5 ki tu");
EditText edHieuChinhTacGia(2011, Table_x1+20, 445, 500, 40, "Tac gia :","","Chi nhan chu cai, toi da 30 ki tu");
EditText edHieuChinhNXB(2012, Table_x1+20, 495, 500, 40, "Nam xuat ban :","","Chi nhan so");
EditText edHieuChinhTheLoai(2013, Table_x1+20, 545, 500, 40, "The loai :","","Chi nhan chu cai, toi da 20 ki tu");

Button btnHieuChinhDauSach(208, 420, 610, 130, 30, "HIEU CHINH",1,9,0);
Button btnXoaDauSach(209,665, 610, 130, 30, "XOA",1,9,0);
Button btnXacNhanXoaDauSach(210,1000,660,100,30,"YES",1,9,0);
Button btnHuyXoaDauSach(211,Table_x2-225,660,100,30,"NO",1,9,0);
// Nhap Sach
Button btnNhapSoLuongSach(213, 1300, 550, 100, 30, "NHAP", 1,9,0);
Button btnPrevDanhMucSach(214, 890, 485, 80, 25, "PREV", 1,9,0);
Button btnNextDanhMucSach(215, 1320, 485, 80, 25, "NEXT", 1,9,0);

EditText edNhapSoLuongSach(2015, 900, 550, 360, 30, "So luong sach :", "", "Toi da 99 sach");
// Them Sach
EditText edThemMaSach(2020, 900, 535, 500, 30, "Ma sach :", "", "Tu dong");
EditText edThemTrangThaiSach(2021, 900,570 , 500, 30, "Trang thai[0,1,2] ", "", "0:CMD d- 1:DCM- 2:DTL", TrangThaiSach);
EditText edThemViTriSach(2022, 900, 605, 500, 30, "Vi tri :", "", "Toi da 18 ki tu");
Button btnThemSach(220, Table_x2-180, 645, 100, 30, "THEM", 1,9,0);
// Hieu Chinh Sach
EditText edHieuChinhMaSach(2025,900, 535, 500, 30, "Ma sach:", "", "Auto");
EditText edHieuChinhTrangThaiSach(2026, 900,570 , 500, 30, "Trang thai[0,1,2] ", "", "0:CMD d- 1:DCM- 2:DTL", TrangThaiSach);
EditText edHieuChinhViTriSach(2027, 900, 605, 500, 30, "Vi tri :", "", "Toi da 18 ki tu");
Button btnXacNhanXoaSach(221,1000,660,100,30,"YES",1,9,0);
Button btnHuyXoaSach(222,Table_x2-225,660,100,30,"NO",1,9,0);

Button btnHieuChinhSach(225 ,875+(Table_x2-875)/2-100/2, 645, 100, 30, "EDIT", 1,9,0);
Button btnXoaSach(227 ,Table_x2-140, 645, 100, 30, "XOA", 1,9,0);
Button btnBackToNhapSach(226, 875+40, 645, 100, 30, "HUY", 1,9,0);
// Button DocGia
Button btnDSDocGia(301,330,170,180,30,"Doc Gia",1,9,0);
Button btnAddDocGia(302,510,170,180,30,"Them Doc Gia",1,9,0);
Button btnTatCaDocGia(211, 460, 220, 80, 25, "TAT CA", 8,7,0);
Button btnDocGiaQuaHan(212, 540, 220, 80, 25, "QUA HAN",8,7, 0);
Button btnSapXepTen(213, 905, 220, 80, 25, "TEN",8,7, 0);
Button btnSapXepMaThe(214, 825, 220, 80, 25, "MA THE",8,7, 0);
Button btnPrevDocGia(215, 330,715,100,25,"< Prev",1,9,0);
Button btnNextDocGia(216, 1320,715,100,25,"Next >",1,9,0);

Button btnPrevDocGiaQH(215, 330,715,100,25,"< Prev",1,9,0);
Button btnNextDocGiaQH(216, 1320,715,100,25,"Next >",1,9,0);

// Them Doc Gia
EditText edThemMaTheDocGia(1002, Table_x1+70, 300, 550, 40, "Ma the:","","auto");
EditText edThemHoDocGia(1003, Table_x1+70, 350, 550, 40, "Ho va ten dem:","","Toi da 25 ki tu");
EditText edThemTenDocGia(1004, Table_x1+70, 400, 550, 40, "Ten:","","Toi da 10 ki tu");
EditText edThemPhaiDocGia(1005, Table_x1+70, 450, 550, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edThemTrangThaiTheDocGia(1006, Table_x1+70, 500, 550, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);

Button btnThemDocGia(205, 595, 570, 150, 30, "THEM",1,9,0);

// Hieu Chinh Doc Gia
EditText edHieuChinhMaTheDocGia(1002, Table_x1+70, 300, 550, 40, "Ma the:","","khong cho phep");
EditText edHieuChinhHoDocGia(1003, Table_x1+70, 350, 550, 40, "Ho va ten dem:","","Toi da 25 ki tu");
EditText edHieuChinhTenDocGia(1004, Table_x1+70, 400, 550, 40, "Ten:","","Toi da 10 ki tu");
EditText edHieuChinhPhaiDocGia(1005, Table_x1+70, 450, 550, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edHieuChinhTrangThaiTheDocGia(1006, Table_x1+70, 500, 550, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);

Button btnHieuChinhDocGia(205, 450, 570, 130, 30, "HIEU CHINH", 1,9,0);
Button btnBackToDSDocGia(210, 350, 215, 80, 30, "< BACK",8,7, 0);

// Xoa doc gia
Button btnXoaDocGia(205, 760, 570, 130, 30, "XOA", 1,9,0);
Button btnXacNhanXoaDocGia(220,1040, 580, 100, 30, "YES",1,9, 0);
Button btnHuyXoaDocGia(220, 1250, 580, 100, 30, "NO", 1,9,0);
// Muon Tra
Button btnMuonSach(231,330,170,180,30, "Muon Sach",  1,9,0);
Button btnTraSach(232, 510,170,180,30, "Tra Sach",  1,9,0);
Button btnTopTen(233, 690, 170, 180, 30, "TOP 10",  1,9,0);
// Muon sach
EditText edNhapMaDGMuonSach(1111, 340, 222, 400, 30, "Nhap ma the :", "", "Nhap ma the doc gia");
EditText edTimDauSachMT(1115, 950, 222, 370, 30, "Tim dau sach:", "", "Nhap ten sach vao day");
EditText edNhapMaSachMuonSach(1112, 960 , 535, 340, 30, "Nhap ma sach :", "", "Nhap ma sach");
EditText edNhapNgayMuonSach(1113, 960 , 620, 400, 30, "Ngay muon :", "", "01/01/2020");
Button btnTimMaDG(241, 750, 222, 80, 30, "TIM",1,9,0);
Button btnTimMaSach(242,1310, 535, 80, 30, "TIM",1,9 ,0);
Button btnXacNhanMuonSach(243, XDSMT[0]+(XDSMT[2]-XDSMT[0])/2-75, 660, 150, 30, "MUON SACH",1,9 ,0);
Button btnPrevDSMT(244, XDSMT[0]+5, Table_y2+40, 80, 25, "PREV", 1,9,0);
Button btnNextDSMT(245, XDSMT[2]-5-80, Table_y2+40, 80, 25, "NEXT", 1,9,0);
Button btnClearTimDauSachMT(246, 1330, 222, 80, 30, "CLEAR", 1,9,0);
Button btnBackToTTDG(247, 880, 222, 80, 30, "< BACK",8,7, 0);
Button btnBackToDGMT(247, 340, 260, 80, 30, "< BACK",8,7, 0);
// Tra sach
EditText edNhapNgayTraSach(1114, 960, 500, 400, 30, "Ngay tra :", "", "01/01/2020");
Button btnXacNhanTraSach(244, 960, 600, 150, 30, "TRA SACH",1,9 , 0);

Button btnLamMatSach(300, Table_x2-170, 600, 150, 30, "LAM MAT SACH?",1,9 , 0);

Button btnXacNhanLamMatSach(301, 960, 630, 150, 30, "XAC NHAN", 1,9 ,0);
Button btnHuyLamMatSach(302, Table_x2-170, 630, 150, 30, "HUY",1,9 , 0);

// Cac ham void trong chuong trinh
void Event();
void DrawMenu();
void SetMenuChinhSwitch();
void SetMenuSelect();
// DauSach
void RunDauSach();
void DauSachEvent();
void DrawDanhSachDauSach();
void ClickNode();
void ClickSwitchDauSach();
void DrawList();
void DrawThemDauSach();
void ItemEvent();
void DrawItemDauSach(int, int);
void DrawBorderListSach();
// DocGia
void RunDocGia();
void DrawDanhSachDocGia();
void DrawBorderDSDocGia();
void SetMenuDocGiaSelect(int menuID);
void DrawThemDocGia(bool genNewID);
void DrawHieuChinhDocGia();
void DrawBorderDSDocGiaQuaHan();
void ItemDocGiaEvent();
void DrawItemDocGia(DocGia &docgia, int i);
void DrawItemDocGiaQH(DocGia &docgia, int i);
void DrawItemDocGiaQuaHan(DocGia &docgia, int soNgayQH, int i);
void DrawBorderDGList2();
void DrawXoaDocGia();
void DrawListDocGia(bool reload);
void DrawMuonSach(int i);


// MuonTra
void RunQLSach();
void QLSachEvent();
void SetMenuMuonTraSelect(int menuID);
void DrawBorderMuonTra();
void DrawMuonSach();
void DrawTraSach();
void DrawTopTen();
void DrawListDocGiaMT(bool reload);
void DrawbtnDocGiaMT();
void ItemDocGiaMTEvent();
void GetMaTheDocGia(int i);
void ItemDSMTEvent();
void DrawbtnDauSachMT();
void DrawBorderDSMT();
void DrawItemMT(int i);
void DrawLamMatSach();
void DrawListDSMT();
void ItemMDSEvent();
void ItemMTEvent();	

//Thong tin
void RunThongTin();
void ThongTinEvent();

///////////////////////////////
void Scan(EditText* &txt, int maxn, ScanType type, int strartLimit = 0, int endLimit = 0);
void ScanTimDauSach(EditText* &txt, int &n, int maxn, char c);
void ScanTextNumber(EditText* &txt, int &n, char c);
void ScanTextSpace(EditText* &txt, int &n, char c);
void ScanTextOnly(EditText* &txt, int &n, char c);
void ScanNumber(EditText* &txt, int &n, char c);
void ScanNumberGreater0(EditText* &txt, int &n, char c);
void ScanDate(EditText* &txt, int &n, char c);
void ScanLimit(EditText* &txt, int &n, char c, int start, int end);
void ScanMaSach(EditText* &txt, int &n, char c);
void ClearStream();

void MoveToNextEditText();
void MoveToPrevEditText();

void ButtonEffect(Button &btn){
	if(btn.isChoose) return;
	if(btn.isMouseHover(mousex(), mousey())){
		if(btn.isHover == false){
			btn.isHover = true;
			btn.draw();
		}
	}else{
		if(btn.isHover == true){
			btn.isHover = false;
			btn.draw(); 
		} 
	} 

}
void ClearStream(){
	while(kbhit()){
		char c = getch();
	}
}
void KbEvent(){
	if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT)){
		ClearStream();
		return;
	}
	
	if(GetAsyncKeyState(VK_DOWN)){
		ClearStream();
		if(Edit != NULL){
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			MoveToNextEditText();
		}
		return;
	}else if(GetAsyncKeyState(VK_UP)){
		ClearStream();
		if(Edit != NULL){
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			MoveToPrevEditText();
		}
		return;
	}
	
	if(Edit != NULL){
		int n = strlen(Edit->content);
		Edit->content[n] = '_';
		Edit->draw();
		Edit->content[n] = '\0';	
		
		if(curMenu == btnQLDauSach.id){
			if(Edit == &edTimDauSach){
				Scan(Edit, 20, FIND_DS);
				DrawDanhSachDauSach();
			}
			if(Window == THEM_DAU_SACH){
				if(Edit == &edThemISBN){
					Scan(Edit, 10, ISBN);
				}else if(Edit == &edThemTenSach){
					Scan(Edit, 30, TEXT_NUMBER);
				}else if(Edit == &edThemSoTrang){
					Scan(Edit, 5, ONLY_NUMBER_GREATER_0);
				}else if(Edit == &edThemTacGia){
					Scan(Edit, 30, SPACE_TEXT);
				}else if(Edit == &edThemNXB){
					Scan(Edit, 4, ONLY_NUMBER_GREATER_0);
				}else if(Edit == &edThemTheLoai){
					Scan(Edit, 20, SPACE_TEXT);
				}
			} 
			if(Window == HIEU_CHINH_DAU_SACH){
				if(Edit == &edHieuChinhISBN){
					Scan(Edit, 5, ISBN);
				}else if(Edit == &edHieuChinhTenSach){
					Scan(Edit, 30, TEXT_NUMBER);
				}else if(Edit == &edHieuChinhSoTrang){
					Scan(Edit, 5, ONLY_NUMBER_GREATER_0);
				}else if(Edit == &edHieuChinhTacGia){
					Scan(Edit, 30, SPACE_TEXT);
				}else if(Edit == &edHieuChinhNXB){
					Scan(Edit, 4, ONLY_NUMBER_GREATER_0);
				}else if(Edit == &edHieuChinhTheLoai){
					Scan(Edit, 20, SPACE_TEXT);
				}	
			}
			if(Window == HIEU_CHINH_DAU_SACH){
				if(Book == NHAP_SACH){
					if(Edit == &edNhapSoLuongSach){
						Scan(Edit, 2, ONLY_NUMBER_GREATER_0);
					}
				}
				else if(Book== THEM_SACH){
					if(Edit == &edThemTrangThaiSach){
						Scan(Edit, 1, LIMIT_CHARACTER, '0', '2');
					}else if(Edit == &edThemViTriSach){
						Scan(Edit, 20, TEXT_NUMBER);
					}
				}else if(Book == HIEU_CHINH_SACH){
					if(Edit == &edHieuChinhTrangThaiSach){
						Scan(Edit, 1, LIMIT_CHARACTER, '0', '2');
					}else if(Edit == &edHieuChinhViTriSach){
						Scan(Edit, 20, TEXT_NUMBER);
					}
				}
				
			}
				
			
		}else if(curMenu == btnQLDocGia.id){
			if(Window == THEM_DOC_GIA){
				if(Edit == &edThemHoDocGia){
					Scan(Edit, 25, SPACE_TEXT);
				}else if(Edit == &edThemTenDocGia){
					Scan(Edit, 10, ONLY_TEXT);
				}else if(Edit == &edThemPhaiDocGia){
					Scan(Edit, 1, LIMIT_CHARACTER, '0', '1');
				}else if(Edit == &edThemTrangThaiTheDocGia){
					Scan(Edit, 1, LIMIT_CHARACTER, '0', '1');
				}
			}	
			else if(Window == HIEU_CHINH_DOC_GIA){
				if(Edit == &edHieuChinhHoDocGia){
					Scan(Edit, 25, SPACE_TEXT);
				}else if(Edit == &edHieuChinhTenDocGia){
					Scan(Edit, 10, ONLY_TEXT);
				}else if(Edit == &edHieuChinhPhaiDocGia){
					Scan(Edit, 1, LIMIT_CHARACTER, '0', '1');
				}else if(Edit == &edHieuChinhTrangThaiTheDocGia){
					Scan(Edit, 1, LIMIT_CHARACTER, '0', '1');
				}
			}
			 
		}else if(curMenu == btnQLSach.id){
			if(Edit == &edNhapMaDGMuonSach){
				Scan(Edit, 5, ONLY_NUMBER);
			}else if(Edit == &edNhapMaSachMuonSach){
				Scan(Edit, 15, MASACH);
			}else if(Edit == &edNhapNgayMuonSach){
				Scan(Edit, 10, DATE_TIME);
			}
			
			if(Edit == &edNhapNgayTraSach){
				Scan(Edit, 10, DATE_TIME);
			}
			if(Edit == &edTimDauSachMT){
				Scan(Edit, 20, FIND_DSMT);
				//DrawDanhSachDauSachMT();
			}
		}
	}else{
		ClearStream();
	}
}
void MoveToNextEditText(){
	if(Edit == &edThemISBN) Edit = &edThemTenSach;
	else if(Edit == &edThemTenSach) Edit = &edThemSoTrang;
	else if(Edit == &edThemSoTrang) Edit = &edThemTacGia;
	else if(Edit == &edThemTacGia) Edit = &edThemNXB;
	else if(Edit == &edThemNXB) Edit = &edThemTheLoai;
//	else if(Edit == &edThemTheLoai) Edit = NULL;
	
	if(Edit == &edHieuChinhTenSach) Edit = &edHieuChinhSoTrang;
	else if(Edit == &edHieuChinhSoTrang) Edit = &edHieuChinhTacGia;
	else if(Edit == &edHieuChinhTacGia) Edit = &edHieuChinhNXB;
	else if(Edit == &edHieuChinhNXB) Edit = &edHieuChinhTheLoai;
//	else if(Edit == &edHieuChinhTheLoai) Edit = NULL;

	if(Edit == &edThemMaTheDocGia) Edit = &edThemHoDocGia;
	else if(Edit == &edThemHoDocGia) Edit = &edThemTenDocGia;
	else if(Edit == &edThemTenDocGia) Edit = &edThemPhaiDocGia;
	else if(Edit == &edThemPhaiDocGia) Edit = &edThemTrangThaiTheDocGia;
//	else if(Edit == &edThemTrangThaiTheDocGia) Edit = NULL;
	
	if(Edit == &edHieuChinhHoDocGia) Edit = &edHieuChinhTenDocGia;
	else if(Edit == &edHieuChinhTenDocGia) Edit = &edHieuChinhPhaiDocGia;
	else if(Edit == &edHieuChinhPhaiDocGia) Edit = &edHieuChinhTrangThaiTheDocGia;
//	else if(Edit == &edHieuChinhTrangThaiTheDocGia) Edit = NULL;
}

void MoveToPrevEditText(){
//	if(Edit == &edThemISBN) Edit = &edThemTenSach;
	if(Edit == &edThemTenSach) Edit = &edThemISBN;
	else if(Edit == &edThemSoTrang) Edit = &edThemTenSach;
	else if(Edit == &edThemTacGia) Edit = &edThemSoTrang;
	else if(Edit == &edThemNXB) Edit = &edThemTacGia;
	else if(Edit == &edThemTheLoai) Edit = &edThemNXB;
	
//	if(Edit == &edHieuChinhTenSach) Edit = &edHieuChinhSoTrang;
	if(Edit == &edHieuChinhSoTrang) Edit = &edHieuChinhTenSach;
	else if(Edit == &edHieuChinhTacGia) Edit = &edHieuChinhSoTrang;
	else if(Edit == &edHieuChinhNXB) Edit = &edHieuChinhTacGia;
	else if(Edit == &edHieuChinhTheLoai) Edit = &edHieuChinhNXB;

//	if(Edit == &edThemMaTheDocGia) Edit = &edThemHoDocGia;
//	if(Edit == &edThemHoDocGia) Edit = &edThemMaTheDocGia;
	if(Edit == &edThemTenDocGia) Edit = &edThemHoDocGia;
	else if(Edit == &edThemPhaiDocGia) Edit = &edThemTenDocGia;
	else if(Edit == &edThemTrangThaiTheDocGia) Edit = &edThemPhaiDocGia;
	
//	if(Edit == &edHieuChinhHoDocGia) Edit = &edHieuChinhTenDocGia;
	if(Edit == &edHieuChinhTenDocGia) Edit = &edHieuChinhHoDocGia;
	else if(Edit == &edHieuChinhPhaiDocGia) Edit = &edHieuChinhTenDocGia;
	else if(Edit == &edHieuChinhTrangThaiTheDocGia) Edit = &edHieuChinhPhaiDocGia;
}
void ScanTimDauSachMT(EditText* &txt, int &n, int maxn, char c){
	if(c == BACKSPACE){
		if(n > 0){
			txt->content[n--] = ' ';
			txt->content[n] = ' ';
		}
	}
	if(n < maxn){
		if(c == SPACE){
			if(n > 0 && txt->content[n-1] != ' ')
				txt->content[n++] = ' ';
		}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			txt->content[n++] = toupper(c);
		}else if(c >= '0' && c <= '9'){
			txt->content[n++] = c;
		}
	} 
	
	txt->content[n] = '\0';
	GetListNodes(DSDS, txt->content, sizeListIndexDauSachSearch);
	curPageDauSach = 1;
	DrawListDSMT();

}
void Scan(EditText* &txt, int maxn, ScanType type, int startLimit, int endLimit){
	if(txt == NULL) return;
	int mx = -1, my = -1, mrx = -1, mry = -1;
	int n = strlen(txt->content);
	getmouseclick(WM_LBUTTONDOWN, mx, my);
	clearmouseclick(WM_LBUTTONDOWN);
	getmouseclick(WM_RBUTTONDOWN, mrx, mry);
	clearmouseclick(WM_RBUTTONDOWN);
				
	if(((mx != -1 && my != -1) || (mrx != -1 && mry != -1)) && (!txt->isMouseHover(mx, my))){
		txt->content[n] = '\0';
		txt->draw();
		txt = NULL;
		return;
	}
		
	if(kbhit()){
		char c = getch();
		if(c == BACKSPACE && type != FIND_DS){
			if(n > 0){
				txt->content[n--] = ' ';
				txt->content[n] = ' ';
			}
		}else if(c == ENTER){
			txt->draw();
			txt->content[n] = '\0';
//			txt = NULL;
			
			// animation
			MoveToNextEditText();
			
			return;
		}else if(n < maxn){
			if(type == ONLY_NUMBER){
				ScanNumber(txt, n, c);
			}else if(type == ONLY_NUMBER_GREATER_0){
				ScanNumberGreater0(txt, n, c);
			}else if(type == ONLY_TEXT){
				ScanTextOnly(txt, n, c);
			}else if(type == SPACE_TEXT){
				ScanTextSpace(txt, n, c);
			}else if(type == TEXT_NUMBER){
				ScanTextNumber(txt, n, c);
			}else if(type == DATE_TIME){
				ScanDate(txt, n, c);
			}else if(type == LIMIT_CHARACTER){
				ScanLimit(txt, n, c, startLimit, endLimit);
			}else if(type == ISBN){
				ScanNumber(txt, n, c);
				ScanTextOnly(txt, n, c);
			}else if(type == MASACH){
				ScanMaSach(txt, n, c);
			}
		}
		if(type == FIND_DSMT) ScanTimDauSachMT(txt, n, maxn, c);
		if(type == FIND_DS) ScanTimDauSach(txt, n, maxn, c);
		
		txt->content[n] = '_';
		txt->draw();
		txt->content[n] = '\0';
	}
}

void ScanLimit(EditText* &txt, int &n, char c, int start, int end){
	if(c >= start && c <= end){
		txt->content[n++] = c;
	}
}

void ScanDate(EditText* &txt, int &n, char c){
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(txt->content[i] == '/') cnt++;
	}
	
	if(c >= '0' && c <= '9'){
		txt->content[n++] = c;
	}else if(c == '/' && cnt < 2 && n> 0 && txt->content[n-1] != '/'){
		txt->content[n++] = c;
	}
}

void ScanNumber(EditText* &txt, int &n, char c){
	if(c >= '0' && c <= '9'){
		txt->content[n++] = c;
	}
}
void ScanMaSach(EditText* &txt, int &n, char c)
{
	if(c >= '0' && c <= '9'){
		txt->content[n++] = c;
	}
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		txt->content[n++] = toupper(c);
	}
	if(c == '-'){
		txt->content[n++] = c;
	}
}

void ScanNumberGreater0(EditText* &txt, int &n, char c){
	if(c >= '0' && c <= '9'){
		if(n == 0 && c == '0') return;
		txt->content[n++] = c;
	}
}

void ScanTextOnly(EditText* &txt, int &n, char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		txt->content[n++] = toupper(c);
	}
}

void ScanTextSpace(EditText* &txt, int &n, char c){
	if(c == SPACE){
		if(n > 0 && txt->content[n-1] != ' ')
			txt->content[n++] = ' ';
	}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		txt->content[n++] = toupper(c);
	}else if(Edit == &edThemTacGia || Edit == &edHieuChinhTacGia) {
		txt->content[n++] = ',';
	}
}

void ScanTextNumber(EditText* &txt, int &n, char c){
	// Chu cai, so, dau cach, dau phay
	if(c == SPACE){
		if(n > 0 && txt->content[n-1] != ' ')
			txt->content[n++] = ' ';
	}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		txt->content[n++] = toupper(c);
	}else if(c >= '0' && c <= '9'){
		txt->content[n++] = c;
	}else if(c == ','){
		txt->content[n++] = c;
	}
}

void ScanTimDauSach(EditText* &txt, int &n, int maxn, char c){
	if(c == BACKSPACE){
		if(n > 0){
			txt->content[n--] = ' ';
			txt->content[n] = ' ';
		}
	}
	if(n < maxn){
		if(c == SPACE){
			if(n > 0 && txt->content[n-1] != ' ')
				txt->content[n++] = ' ';
		}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			txt->content[n++] = toupper(c);
		}else if(c >= '0' && c <= '9'){
			txt->content[n++] = c;
		}
	} 
	
	txt->content[n] = '\0';
	GetListNodes(DSDS, txt->content, sizeListIndexDauSachSearch);
	curPageDauSach = 1;
	DrawList();
}
