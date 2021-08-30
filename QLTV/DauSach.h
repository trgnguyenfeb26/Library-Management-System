struct DauSach{
	char ISBN[10];
	char TenSach[30];
	int SoTrang;
	char TacGia[30];
	int NamXuatBan;
	char TheLoai[20];
	NodeSach *dms = NULL;
	int SoLuotMuon; 	
	int SoLuong;	
	int maxSach;
		DauSach(){
	}
	DauSach(char *isbn, char* ten, int st, char *tg, int xb, char* tl){
		strcpy(ISBN, isbn);
		strcpy(TenSach, ten);
		SoTrang = st;
		strcpy(TacGia, tg);
		NamXuatBan  = xb;
		strcpy(TheLoai, tl);
		dms = NULL;
		SoLuong = 0;
		SoLuotMuon = 0;
		maxSach=0;
	}
};
struct DS_DauSach{
	int n;
	DauSach *mang[MAX_DAU_SACH];	
		DS_DauSach(){
		n = 0;
	}
	~DS_DauSach(){
		printf("Free memory dau sach + dms \n");
		while(n) {
			DeleteAllNodeSach(mang[n-1]->dms);
			delete mang[--n];
		}
	}
};
int listIndexDauSachSearch[MAX_DAU_SACH];
int sizeListIndexDauSachSearch = 0;
void InsertLastDauSach(DS_DauSach &DSDS, DauSach *dausach){
	if(DSDS.n > 300)
		printf("DSDS day \n");
	else{
		DSDS.mang[DSDS.n++] = dausach;
	}
}
int CheckISBN(DS_DauSach &DSDS, char* ISBN){			
	for(int i=0; i<DSDS.n; i++){
		if(strcmp(DSDS.mang[i]->ISBN, ISBN) == 0){
			return i;
		}
	}
	return -1;
}
void InsertDauSach(DS_DauSach &DSDS, DauSach *dausach, int position){
	if(position < 0){
		printf("Vi tri them dau sach khong hop le \n");
		return;
	}
	// neu position >= DSDS.n thi se Insert vao cuoi danh sach
	for(int i=DSDS.n; i>position; i--){
		DSDS.mang[i] = DSDS.mang[i-1];
	}
	DSDS.mang[position] = dausach;
	DSDS.n++; 
}

void AddDauSach(DS_DauSach &DSDS, DauSach *dausach){					
	if(DSDS.n > MAX_DAU_SACH)
		printf("DSDS day \n");						
	else if (DSDS.n==0){
		InsertLastDauSach(DSDS,dausach);
	}
	else {
		for(int i=0; i<DSDS.n; i++){
			if(strcmp(dausach->TheLoai, DSDS.mang[i]->TheLoai) < 0){
				InsertDauSach(DSDS, dausach, i);
				return;
			}
		
			if(strcmp(dausach->TheLoai, DSDS.mang[i]->TheLoai) == 0){
				if(strcmp(dausach->TenSach, DSDS.mang[i]->TenSach) <= 0){
					InsertDauSach(DSDS, dausach, i);
					return;
				}
			}
		}
		DSDS.mang[DSDS.n++] = dausach;
	}
}

void UpdateDauSach(DS_DauSach &DSDS, DauSach *dausach, int i){
	if(i >= DSDS.n || i < 0) printf("Khong the update dau sach");
	else {
		// Gan dia chi con tro DMS  vao dausach moi
		dausach->dms = DSDS.mang[i]->dms;
		dausach->SoLuong = DSDS.mang[i]->SoLuong;
		dausach->maxSach = DSDS.mang[i]->maxSach;
		dausach->SoLuotMuon = DSDS.mang[i]->SoLuotMuon;
		
		delete DSDS.mang[i];
		for(int j=i; j<DSDS.n; j++){
			DSDS.mang[j] = DSDS.mang[j+1];
		}
		DSDS.n--;
		AddDauSach(DSDS, dausach);
	}
}

void DeleteISBN(DS_DauSach &DSDS, int i){
	if(i >= DSDS.n || i < 0) printf("Khong the xoa dau sach");
	else {
		delete DSDS.mang[i];
		for(int j=i; j<DSDS.n; j++){
			DSDS.mang[j] = DSDS.mang[j+1];
		}
		DSDS.n--;
	}

}

void GetListNodes(DS_DauSach &DSDS, const char* strFind, int &m){
	m = 0;
	for(int i=0; i<DSDS.n; i++){
		if(strstr( DSDS.mang[i]->TenSach,strFind)>0){
			listIndexDauSachSearch[m++] = i;
		}
	}
}

int GetSepPosition(char *s){
	int n = strlen(s);
	for(int i=0; i<n; i++){
		if(s[i] == '-') return i;
	}
	return -1;
}

DauSach* GetDauSach(DS_DauSach &DSDS, char* masach){
	NodeSach *node;
	
	int sepPos = GetSepPosition(masach);
	char isbn[sepPos+1];
	int indexSach=0;
	for(int i=0; i<sepPos; i++) isbn[i] = masach[i];
	isbn[sepPos] = '\0';
	for(int i=sepPos+1; i<strlen(masach); i++){
		indexSach = indexSach*10 + (masach[i]-'0');
	}
	
	for(int i=0; i<DSDS.n; i++){
		if(strcmp(DSDS.mang[i]->ISBN, isbn) == 0){
			if(indexSach < DSDS.mang[i]->maxSach) return DSDS.mang[i];
			else break;
		}
	
	}
	return NULL;
}

/*
 * Struct thong ke so luot muon sach cua moi Dau Sach
 */
struct LuotMuonSach{
	int indexDS;	// vi tri cua DauSach
	int cnt;		// so luot muon
};	

struct TopSach{
	int n;
	LuotMuonSach *list;
	
	TopSach(DS_DauSach &DSDS){
		n = DSDS.n;
		list = new LuotMuonSach[n];
		for(int i=0; i<n; i++){
			list[i].indexDS = i;
			list[i].cnt = DSDS.mang[i]->SoLuotMuon;
		}
		sort();
	}
	~TopSach(){
		delete[] list;
	}
	
	// Phan doan
	void partition(int low, int high){
		int i = low, j = high;
		LuotMuonSach tmp;
		int pivot = list[(low+high)/2].cnt;
		do{
			while(list[i].cnt > pivot) i++;
			while(list[j].cnt < pivot) j--;
			if(i <= j){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				i++; j--;
			}
		}while(i <= j);
		
		if(low < j) partition(low, j);
		if(i < high) partition(i, high);
	}
	void sort(){
		// Sap xep theo thu tu cnt giam dan
		// Su dung QuickSort
		partition(0, n-1);
	}
};



