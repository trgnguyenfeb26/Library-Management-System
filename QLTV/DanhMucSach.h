struct DanhMucSach{
	char MaSach[15];
	int TrangThai;
		/*
		 * 0: Cho muon duoc
		 * 1: Da co doc gia muon
		 * 2: Sach da thanh ly
		 */
	char ViTri[20];
	DanhMucSach(){
	}
	DanhMucSach(char ms[15], int tt, char vt[20]){
		strcpy(MaSach, ms);
		TrangThai = tt;
		strcpy(ViTri, vt);
	}
};
struct NodeSach{
	DanhMucSach data;
	struct NodeSach *next;
};

NodeSach* CrNodeSach(DanhMucSach Value){
	NodeSach* p = new NodeSach;
	p->data = Value;
	p->next = NULL;
	return p;
}
void InsertFirst_NodeSach(NodeSach* &First, DanhMucSach &sach){
	NodeSach *newNode = CrNodeSach(sach);
	
	newNode->next = First;
	First = newNode;
}
void InsertAfter_NodeSach(NodeSach* &node, DanhMucSach &sach){
	NodeSach *newNode = CrNodeSach(sach);
	
	newNode->next = node->next;
	node->next = newNode;
}
void InsertLast_NodeSach(NodeSach* &First, DanhMucSach &sach){
	if(First == NULL) InsertFirst_NodeSach(First, sach);
	else{
		NodeSach *last;
		for(last = First; last->next != NULL; last = last->next);
		InsertAfter_NodeSach(last, sach);
	}
}
NodeSach* DelHead(NodeSach* head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
        
    }
    return head;
}
NodeSach* DelTail(NodeSach* head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    NodeSach* p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = NULL; 
    return head;
}
NodeSach* DelSach(NodeSach* head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head);  
    }else{
        
        int k = 1;
        NodeSach* p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
        if(k != position){
            
            head = DelTail(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}

void DeleteAllNodeSach(NodeSach* &dms){
	NodeSach *removeNode;
	while(dms != NULL){
		removeNode = dms;
		dms = dms->next;
		delete removeNode;
	}
}

// Lay NodeSach tai vi tri position
NodeSach* GetNodeSach(NodeSach* First, int position){
	NodeSach* node = First;
	for(int i=0; node != NULL; node = node->next){
		if(i == position) break;
		++i;
	}
	return node;
}
// Lay NodeSach theo masach
NodeSach* GetNodeSach(NodeSach *First, char* masach){
	for(NodeSach *node = First; node != NULL; node = node->next){
		if(strcmp(node->data.MaSach, masach) == 0) return node;
	}
	return NULL;
}
void UpdateNodeSach(NodeSach* &node, DanhMucSach &sach){
	if(node == NULL) printf("K the update");
	else{
		node->data = sach;
	}
}
DanhMucSach* GetSach(NodeSach *First, char* masach){
	for(NodeSach *node = First; node != NULL; node = node->next){
		if(strcmp(node->data.MaSach, masach) == 0) return &node->data;
	}
	return NULL;
}
DanhMucSach* GetSach(NodeSach *First, int position){
	NodeSach *node = First;
	for(int i=0; node != NULL; node = node->next){
		if(i==position) break;
		++i;
	}
	return &node->data;
}
