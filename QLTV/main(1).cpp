using namespace std;

#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>

#include "define.h"
#include "datetime.h"
#include "queue.h"

#include "DanhMucSach.h"
#include "DauSach.h"
#include "MuonTra.h"
#include "DocGia.h"



#include "view.h"
#include "draw.h"
#include "menuchinh.h"

#include "DrawDauSach.h"
#include "DrawDocGia.h"
#include "DrawMuonTra.h"
#include "drawThongTin.h"

void ReadDauSachFromFile(DS_DauSach &DSDS){
	fstream fileDauSach, fileDMS;
	
	fileDauSach.open("data_dsds.txt", ios::in);
	fileDMS.open("data_dms.txt", ios::in);
	
	if(!fileDauSach.is_open() || ! fileDMS.is_open()){
		printf("Loi mo file de doc \n");
		return;
	}
	string line, lineDMS;
	DauSach dausach;
	int n;
	fileDauSach >> n;
	fileDauSach.ignore();
	int m, slm,key;
		
	for(int i=0; i<n; i++){
		DauSach *dausach = new DauSach;
		
		getline(fileDauSach, line);		strcpy(dausach->ISBN, line.c_str());
		getline(fileDauSach, line);		strcpy(dausach->TenSach, line.c_str());
		getline(fileDauSach, line);		dausach->SoTrang = atoi(line.c_str());
		getline(fileDauSach, line);		strcpy(dausach->TacGia, line.c_str());
		getline(fileDauSach, line);		dausach->NamXuatBan = atoi(line.c_str());
		getline(fileDauSach, line);		strcpy(dausach->TheLoai, line.c_str());
		
		getline(fileDMS, lineDMS);
		slm = atoi(lineDMS.c_str());
		dausach->SoLuotMuon = slm;
				
		getline(fileDMS, lineDMS);
		m = atoi(lineDMS.c_str());
		dausach->SoLuong = m;
		
		getline(fileDMS, lineDMS);
		key = atoi(lineDMS.c_str());
		dausach->maxSach = key;
			
			
		
		for(int j=0; j<m; j++){
			DanhMucSach sach;
			
			getline(fileDMS, lineDMS);		strcpy(sach.MaSach, lineDMS.c_str());	
			getline(fileDMS, lineDMS);		sach.TrangThai = atoi(lineDMS.c_str());
			getline(fileDMS, lineDMS);		strcpy(sach.ViTri, lineDMS.c_str()); 
			
			InsertLast_NodeSach(dausach->dms, sach);
		}
		AddDauSach(DSDS, dausach);
	}
	
	fileDauSach.close();
	fileDMS.close();
}

void ReadDocGiaFromFile(NodeDocGia* &TreeDG){
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::in);
	fileMuonTra.open("data_muontra.txt", ios::in);
	if(!fileDocGia.is_open() || !fileMuonTra.is_open()){
		printf("Loi mo file doc gia \n");
		AddRangeListID();
		return;
	}
	string line, lineMT;
	int n;
	fileDocGia >> n;
	fileDocGia.ignore();
	int m;
	for(int i=0; i<n; i++){
		DocGia dg;
		
		getline(fileDocGia, line);		dg.MATHE = atoi(line.c_str());
		getline(fileDocGia, line);		strcpy(dg.ho, line.c_str());
		getline(fileDocGia, line);		strcpy(dg.ten, line.c_str());
		getline(fileDocGia, line);		dg.phai = atoi(line.c_str());
		getline(fileDocGia, line);		dg.trangthai = atoi(line.c_str());
		
		getline(fileMuonTra, lineMT);
		m = atoi(lineMT.c_str());
		for(int j=0; j<m; j++){
			MuonTra mt;
			getline(fileMuonTra, lineMT); 	strcpy(mt.MASACH, lineMT.c_str());
			getline(fileMuonTra, lineMT);	strcpy(mt.ngaymuon, lineMT.c_str());
			getline(fileMuonTra, lineMT);	strcpy(mt.ngaytra, lineMT.c_str());
			getline(fileMuonTra, lineMT);	mt.trangthai = atoi(lineMT.c_str());
			InsertLast_MuonTra(dg.mt, mt);
		}
		InsertDocGia(TreeDG, dg);
	}

	Duyet_DG_ID(TreeDG);
	AddRangeListID();
	
	fileMuonTra.close();
	fileDocGia.close();
}
void WriteDauSachToFile(DS_DauSach &DSDS){
	fstream fileDauSach, fileDMS;
	fileDauSach.open("data_dsds.txt", ios::out | ios::trunc);	
	fileDMS.open("data_dms.txt", ios::out | ios::trunc);
	
	fileDauSach << DSDS.n << endl;
	for(int i=0; i<DSDS.n; i++){
		fileDauSach << DSDS.mang[i]->ISBN << endl;
		fileDauSach << DSDS.mang[i]->TenSach << endl;
		fileDauSach << DSDS.mang[i]->SoTrang << endl;
		fileDauSach << DSDS.mang[i]->TacGia << endl;
		fileDauSach << DSDS.mang[i]->NamXuatBan << endl;
		fileDauSach << DSDS.mang[i]->TheLoai << endl;
		
//		fileDMS << SizeListmangach(DSDS.mang[i]->First) << endl;
		fileDMS << DSDS.mang[i]->SoLuotMuon << endl;
		fileDMS << DSDS.mang[i]->SoLuong << endl;
		fileDMS << DSDS.mang[i]->maxSach << endl;
		for(NodeSach* node = DSDS.mang[i]->dms; node != NULL; node = node->next){
			fileDMS << node->data.MaSach << endl;
			fileDMS << node->data.TrangThai << endl;
			fileDMS << node->data.ViTri << endl;
		}
	}
	fileDauSach.close();
	fileDMS.close();
}
void WriteDocGiaToFile(NodeDocGia* &TreeDG){
	if(TreeDocGia== NULL) return;
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::out | ios::trunc);
	fileMuonTra.open("data_muontra.txt", ios::out | ios::trunc);

	int i=0;
	Queue<NodeDocGia*> q;
	NodeDocGia *node;
	NodeMuonTra *nodeMT;
	q.push(TreeDG);
	
	fileDocGia << TotalDocGia(TreeDocGia) << endl;
	while(!q.empty()){
		// Lay tung doc gia ra - ghi du lieu
		node = q.front();	q.pop();
		
		fileDocGia << node->docgia.MATHE << endl;
		fileDocGia << node->docgia.ho << endl;
		fileDocGia << node->docgia.ten << endl;
		fileDocGia << node->docgia.phai << endl;
		fileDocGia << node->docgia.trangthai << endl;
		
		// ghi danh sach cac sach da muon 
		fileMuonTra << node->docgia.mt.total << endl;
		for(nodeMT = node->docgia.mt.First; nodeMT != NULL; nodeMT = nodeMT->next){
			fileMuonTra << nodeMT->muontra.MASACH << endl;
			fileMuonTra << nodeMT->muontra.ngaymuon << endl;
			fileMuonTra << nodeMT->muontra.ngaytra << endl;
			fileMuonTra << nodeMT->muontra.trangthai << endl;
		}
		
		if(node->left != NULL) q.push(node->left);
		if(node->right != NULL) q.push(node->right);
	}
	
	fileMuonTra.close();
	fileDocGia.close();
}


struct Writer{
	Writer(){
	}	
	~Writer(){
		printf("Write file\n");
		WriteDauSachToFile(DSDS);
		WriteDocGiaToFile(TreeDocGia);
		
		printf("Free memory doc gia + ds muon tra\n");
		DeleteMemoryDocGia(TreeDocGia);
	}
};
Writer writer;
void FreeMemory();
void DrawMenu(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(2);
	outtextxy(40, 40, AppTitle);
	btnQLDauSach.draw();
	btnQLDocGia.draw();
	btnQLSach.draw();
	btnThoat.draw();
	while(true){
		Event();
		if(isExit) break;
		delay(50);
	}	
}


void MenuEvent(){
	ButtonEffect(btnQLDauSach);
	ButtonEffect(btnQLDocGia);
	ButtonEffect(btnQLSach);
	ButtonEffect(btnThoat);	
	
	
//	Menu Click Event
	if(GetAsyncKeyState(VK_LBUTTON)){
		if(btnQLDauSach.isMouseHover(mx, my)){
			SetMenuSelect(btnQLDauSach.id);
		}else if(btnQLDocGia.isMouseHover(mx, my)){
			SetMenuSelect(btnQLDocGia.id);
		}else if(btnQLSach.isMouseHover(mx, my)){
			SetMenuSelect(btnQLSach.id);
		}else if(btnThoat.isMouseHover(mx, my)){
			isExit = true;
		}
	}
}


void Event(){
	mx = mousex(); my = mousey();
	KbEvent();
	if(curMenu == 0){
		MenuEvent();
	}else if(curMenu == btnQLDauSach.id){
		DauSachEvent();
	}else if(curMenu == btnQLDocGia.id	){
		DocGiaEvent();
	}else if(curMenu == btnQLSach.id){	
		QLSachEvent();
	}
} 
int main(int argc, char *argv[]){
	srand(time(NULL));
	initwindow(w,h,AppTitle);			// init window graphics
	setbkcolor(3);
   	cleardevice();

	ReadDauSachFromFile(DSDS);
	ReadDocGiaFromFile(TreeDocGia);	
	RunThongTin();
	DrawMenu();
	return 0;
}

