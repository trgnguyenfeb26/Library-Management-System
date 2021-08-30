void RunThongTin(){
	
	// ve giao dien
	setcolor(0);	// chon mau chu
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);		// chon font chu, huong ve chu (direction), size chu
	
	char *uni = "Hoc vien Cong nghe Buu Chinh Vien Thong - TPHCM";
	char *nam = "-- 2021 --";
	char *title2 = "Cau Truc Du Lieu & Giai Thuat";
	char *gv2 = "Luu Nguyen Ky Thu";
	char *doan2 = "Quan Ly Thu Vien";
	char *author1 = "1. Nguyen Trung Nguyen - N19DCCN124 - D19CQCN02-N";
	char *author2 = "2. Nguyen Lam Truong - N19DCCN218 - D19CQCN02-N";
	w=w+300;h=h+200; int t=100;
	settextstyle(6, HORIZ_DIR, 3);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(uni)/2, 100+t, uni);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(nam)/2, 150+t, nam);
	settextstyle(6, HORIZ_DIR, 3);

	
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(title2)/2, 200+t, title2);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(gv2)/2, 280+t, gv2);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(doan2)/2, 360+t, doan2);
	
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(author1)/2, 440+t, author1);
	outtextxy(Table_x1+(Table_x2-Table_x1)/2 - textwidth(author2)/2, 520+t, author2);
}


