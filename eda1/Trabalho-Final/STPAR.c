#include <stdio.h>

void eduardo()
{
	int queue[100010], stack[100010];
	int n_carros, stack_ind=-1, prox=1;

	scanf("%d", &n_carros);
	if(n_carros==0) return;

	for(int i=1; i<=n_carros; i++)
		scanf("%d", &queue[i]);

	for(int i=1; i<=n_carros; i++){
		while(stack_ind >= 0 && stack[stack_ind]==prox){
			stack_ind--;
			prox++;
		}
		if(queue[i] == prox){
			prox++;
			continue;
		}
		stack[++stack_ind] = queue[i];
	}
	while(stack_ind>=0 && stack[stack_ind] == prox){
		stack_ind--;
		prox++;
	}
	printf(stack_ind == -1 ? "yes\n" : "no\n");
	eduardo();
}

int main()
{
	eduardo();
    return 0;
}
