#include<stdio.h>
#include<stdlib.h>
typedef struct Node *PtrToNode;
struct Node{
	int coe;
	int exp;
	PtrToNode Next;
};
typedef PtrToNode List;
List read();//�������Ա�
void Print(List L);//�������Ա�
List add(List L1,List L2);
List mul(List L1,List L2);
int main()
{
	List L1,L2,LA,LM;
	//L1,L2�����û���Ҫ���������
	//LA�����û���һԪ����ʽ�ӷ�
	//LB�����û���һԪ����ʽ�˷�,�������
	L1 = read();
	L2 = read();
	LA = add(L1,L2);
	LM = mul(L1,L2);
	Print(LM);
	Print(LA);
	
}
//һ�����ĸ�����Ҫʵ��
//��һ���������� �ڶ������� ���� 
//���������� �ӷ� �����������˷�
List read()
{
	int n;
	List s = (List)malloc(sizeof(struct Node));//s�����Ҫ˦��ȥ������
	s->Next = NULL;//��ͷ��������
	scanf("%d",&n);
	if(n){
		List m = s;
		for(int i=0;i<n;i++){
			List p =(List)malloc(sizeof(struct Node));
			scanf("%d%d",&(p->coe),&(p->exp));
			m->Next = p;
			m = p;
		}
		m->Next = NULL;
	}
	return s;	
}
//�ڶ�������
//void Print(List L){
//	List r = L->Next;
//	if(r){
//		List p = (List)malloc(sizeof(struct Node));
//		p = L;
//		if(p->Next){
//			p = p->Next;
//			printf("%d %d",p->coe,p->exp);//��Ŀ��ʽҪ��
//			while(p->Next){
//				p = p->Next;
//				printf(" %d %d",p->coe,p->exp);
//			}
//		}
//	}else{
//		printf("0 0");
//	}
//	printf("\n");
//}
void Print(List L){
	List r = L->Next;
    if(r){
        printf("%d %d",r->coe,r->exp);
        r = r->Next;
    	while(r){
        printf(" %d %d",r->coe,r->exp);
        r = r->Next;
    	}
	}else{
        printf("0 0");
    }
    printf("\n");
}

List add(List L1,List L2){
	List pa,pb,pc,L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	pa = L1->Next;
	pb = L2->Next;
	pc = L;
	while(pa && pb)
	{
		if(pa->exp<pb->exp){
			List temp = (List)malloc(sizeof(struct Node));
			temp->Next = NULL;
			temp->coe = pb->coe;
			temp->exp = pb->exp;
			pc->Next = temp;
			pc = temp;
			pb = pb->Next;
		}
		else if(pa->exp == pb->exp){
			int a = pa->coe+pb->coe;
			if(a!=0){
				List temp = (List)malloc(sizeof(struct Node));
				temp->Next = NULL;
				temp->coe = a;
				temp->exp = pa->exp;//������ָ���������ʱ����ָ��˭��ʵ��һ��
				pc->Next = temp;
				pc = temp;				
			}
			pb=pb->Next;
			pa=pa->Next;
		}else{
			List temp = (List)malloc(sizeof(struct Node));
			temp->Next = NULL;
			temp->coe = pa->coe;
			temp->exp = pa->exp;
			pc->Next = temp;
			pc = temp;
			pa = pa->Next;			
		}
		
	}
	if(pa){
		while(pa){
			List temp = (List)malloc(sizeof(struct Node));
			temp->Next = NULL;
			temp->coe = pa->coe;
			temp->exp = pa->exp;
			pc->Next = temp;
			pc = temp;
			pa = pa->Next;	
		}
	}else{
		while(pb){
			List temp = (List)malloc(sizeof(struct Node));
			temp->Next = NULL;
			temp->coe = pb->coe;
			temp->exp = pb->exp;
			pc->Next = temp;
			pc = temp;
			pb = pb->Next;			
		}
	}
	pc->Next = NULL;
	return L;
}
List mul(List L1,List L2){
	List p1,p2,p3,L,Lm;
	L = (List)malloc(sizeof(struct Node));
	p1 = L1->Next;
	p2 = L2->Next;
	L->Next = NULL;
	if(p1&&p2){
		for(p1=L1->Next;p1;p1=p1->Next){
			Lm = (List)malloc(sizeof(struct Node));
			Lm->Next = NULL;
			p3 = Lm;
			for(p2=L2->Next;p2;p2=p2->Next){
				List p4=(List)malloc(sizeof(struct Node));
				p4->coe = p1->coe*p2->coe;
				p4->exp = p1->exp+p2->exp;
				p3->Next = p4;
				p3=p4;
			}
			p3->Next = NULL;
			L=add(L,Lm);
			free(Lm);
		}
	}
	return L;
}
