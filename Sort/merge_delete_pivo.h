#include <stdlib.h>

/*
função merge para deletar o pivô do vetor
Pode ser aplicado junto com a 'binary_search' quando temos que listar todos as structs com dados em comum
*/

typedef struct{
	char name[50];
	int age;
}Item;

#define key(a) a.age
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a; a=b; b=t;}
#define cmpexch(a, b) {if(less(a, b)) exch(a, b);}

void merge_delete_pivo(Item *v, int l, int pivo, int r)
{
	Item *s = malloc(sizeof(Item)*(r-l+1));
	int ia=l, ib=pivo+1, iaux=0;

	while(ia < pivo && ib <= r){
		if(less(v[ia], v[ib]))
			s[iaux++] = v[ia++];
		else
			s[iaux++] = v[ib++];}
	while(ia < pivo)
		s[iaux++] = v[ia++];
	while(ib <= r)
		s[iaux++] = v[ib++];
	iaux=0;
	for(ia=l; ia<pivo; ia++)
		v[ia] = s[iaux++];
	for(ia=pivo+1; ia<=r; ia++)
		v[ia] = s[iaux++];
	free(s);
}
