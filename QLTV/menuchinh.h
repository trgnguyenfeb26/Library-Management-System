void SetMenuChinhSwitch(int menuID){
	btnQLDauSach.isChoose = false;
	btnQLDocGia.isChoose = false;
	btnQLSach.isChoose = false;
	if (menuID == btnQLDauSach.isChoose){
		btnQLDauSach.isChoose = true;
	}else 
	if (menuID == btnQLDocGia.isChoose){
		btnQLDocGia.isChoose = true;
	}else
	if (menuID == btnQLSach.isChoose){
		btnQLSach.isChoose = true;
	}else
	if (menuID == btnThoat.isChoose){
		btnThoat.isChoose = true;
	}
}
void SetMenuSelect(int menuID){
	if(curMenu != menuID){
		curMenu = menuID;
		curDGMT = NULL;
		curDSMT = NULL;
		Edit = NULL;
		strcpy(mess, "");
		SetMenuChinhSwitch(curMenu);
		if(curMenu == 0){
			DrawMenu();
		}else if(curMenu == btnQLDauSach.id){
			RunDauSach();
		}else if(curMenu == btnQLDocGia.id){
			RunDocGia();
		}else if(curMenu == btnQLSach.id){
			RunQLSach();
		}
	}
}
