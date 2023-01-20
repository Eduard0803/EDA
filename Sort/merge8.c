#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(a) a
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t=a;a=b;b=t;}
#define cmpexch(a, b) {if(less(b, a))exch(a, b);}

Item* merge2(Item *v1, int l1, int r1, Item *v2, int l2, int r2)
{
	Item *s = malloc(sizeof(Item)*((r1-l1+1)+(r2-l2+1)));
	int ia=l1, ib=l2, iaux=0;

	while(ia <= r1 && ib <= r2){
		if(less(v1[ia], v2[ib]))
			s[iaux++] = v1[ia++];
		else
			s[iaux++] = v2[ib++];
	}
	while(ia <= r1)
		s[iaux++] = v1[ia++];
	while(ib <= r2)
		s[iaux++] = v2[ib++];
	return s;
}

Item* merge4(Item *v1, int l1, int r1, Item *v2, int l2, int r2, Item *v3, int l3, int r3, Item *v4, int l4, int r4)
{
	Item *s1 = merge2(v1, l1, r1, v2, l2, r2);
	Item *s2 = merge2(v3, l3, r3, v4, l4, r4);
	return merge2(s1, 0, ((r1-l1+1)+(r2-l2+1)), s2, 0, ((r3-l3+1)+(r4-l4+1)));
}

Item* merge8(Item *v1, int l1, int r1, Item *v2, int l2, int r2, Item *v3, int l3, int r3, Item *v4, int l4, int r4, 
Item *v5, int l5, int r5, Item *v6, int l6, int r6, Item *v7, int l7, int r7, Item *v8, int l8, int r8)
{
	Item *s1 = merge4(v1, l1, r1, v2, l2, r2, v3, l3, r3, v4, l4, r4);
	Item *s2 = merge4(v5, l5, r5, v6, l6, r6, v7, l7, r7, v8, l8, r8);
	int tam_s1 = ((r1-l1+1)+(r2-l2+1)+(r3-l3+1)+(r4-l4+1));
	int tam_s2 = ((r5-l5+1)+(r6-l6+1)+(r7-l7+1)+(r8-l8+1));
	return merge2(s1, 0, tam_s1, s2, 0, tam_s2);
}
