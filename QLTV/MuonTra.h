

struct MuonTra{
	char MASACH[15];
	char ngaymuon[10];
	char ngaytra[10];
	int trangthai;
//		  0: Dang muon
//		  1: Da tra
//		  2: Lam mat
	MuonTra(){
	}
	MuonTra(char* ms, char* muon, char* tra, int tt){
		strcpy(MASACH, ms);
		strcpy(ngaymuon, muon);
		strcpy(ngaytra, tra);
		trangthai = tt;
	}
};

struct NodeMuonTra{
	MuonTra muontra;
	NodeMuonTra *next;
};

struct DS_MuonTra{
	NodeMuonTra *First = NULL;
	NodeMuonTra *Last = NULL;
	
	int total;	// tong so luong sach da muon
	int chuaTra;	// so luong sach dang muon + lam mat
	
	DS_MuonTra(){
		First = NULL;
		Last = NULL;
		total = 0;
		chuaTra = 0;
	}
	~DS_MuonTra(){
	}
};
 
NodeMuonTra* CreateNewNode_MuonTra(MuonTra &mt){
	NodeMuonTra *newNode = new NodeMuonTra;
	newNode->muontra = mt;
	newNode->next = NULL;
	return newNode;
}
string GetMaSach(char s[]){
	int n = strlen(s);
	string txt;
	for (int i=0;i<n;i++){
		if(s[i]!='-')  txt+=s[i];
		else break;
	}
	return txt;
}
int CheckMaSach(char *ms1, char *ms2){
	if (strcmp(GetMaSach(ms1).c_str(),GetMaSach(ms2).c_str())==0) return 0; 
	else return -1;
	
}

void InsertLast_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	NodeMuonTra *newNode = CreateNewNode_MuonTra(mt);
	if(DSMT.First == NULL){
		DSMT.First = newNode;
		DSMT.Last = newNode;
	}else{
		DSMT.Last->next = newNode;
		DSMT.Last = newNode;
	}
	DSMT.total++;
	if(mt.trangthai != 1) DSMT.chuaTra++;
}

// Tra sach + lam mat sach
void Update_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	for(NodeMuonTra *node = DSMT.First; node != NULL; node = node->next){
		if(strcmp(node->muontra.MASACH, mt.MASACH) == 0 && strlen(node->muontra.ngaytra) == 0){
			node->muontra = mt;
			if(mt.trangthai == 1) DSMT.chuaTra--;
			return;
		}
	}	
}

//Xoa tat ca muon tra
void DeleteAllMuonTra(DS_MuonTra &DSMT){
	NodeMuonTra *removeNode;
	while(DSMT.First != NULL){
		removeNode = DSMT.First;
		DSMT.First = DSMT.First->next;
		delete removeNode;
	}
}

