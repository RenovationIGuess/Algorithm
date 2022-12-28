 
void Init(Queue *Q)
{
	Q->Front = Q->Rear = NULL;
    Q->count = 0;
}
int Isempty (Queue Q) //kiem tra Queue rong
{
	if (Q.count == 0) //so phan tu = 0 => rong
		return 1;
	return 0;
}
 
Node *MakeNode(item x) //tao 1 Node
{
	Node *P = (Node*) malloc(sizeof(Node));
	P->Next = NULL;
	P->Data = x;
	return P;
}

void MakeNull(Queue *q)
{
    q->Front = NULL;
    q->Rear = NULL;
}
 
void Push(Queue *Q, item x) //them phan tu vao cuoi Queue
{
	Node *P = MakeNode(x); //Neu Q rong
	if (Isempty(*Q))
	{
		Q->Front = Q->Rear = P; //dau va cuoi deu tro den P
	}
	else //Khong rong
	{ 
		Q->Rear->Next = P;
		Q->Rear = Q->Rear->Next;
	}

	Q->count++ ; //tang so phan tu len
}
 
item Pop(Queue *Q) //Loai bo phan tu khoi dau hang doi
{
	item x = Q->Front->Data;
		
	if (Isempty(*Q)) 
	{
		printf("Hang doi rong !");
	}
	else
	{
		Node *tmp = Q->Front;
		//item x = Q->Front->Data;
		if (Q->count == 1) //neu co 1 phan tu
		{ 
			free(tmp);
			free(Q->Rear);
			Init(Q);
		}
		else
		{
			Q->Front = Q->Front->Next;
			free(tmp);
		}
		Q->count --;
		//return x; //tra ve phan tu lay ra
	}
	return x;
}

void Output(Queue *Q)
{
	Node *P = Q->Front;
	if(P == NULL)
	{
		printf("\nNo running process!\n");
		return;
	}
	while (P != Q->Rear)
	{
		printf("%d       %d\n", P->Data.ID, P->Data.m);
		P = P->Next;
	}
	printf("%d       %d\n", P->Data.ID, P->Data.m);
	printf("\n");
}

item Top(Queue *q)
{
	return q->Front->Data; 
}

int size(Queue *q)
{
	int cnt = 0;
	Node *P = q->Front;
	while (P != q->Rear)
	{
		cnt++;
		P = P->Next;
	}
	return cnt + 1;
}
 
/*void Input(Queue *Q) //nhap hang doi
{
    int i=0; 
    item x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Push(Q,x);
    } while(x != 0); //nhap 0 de ket thuc
}*/
 