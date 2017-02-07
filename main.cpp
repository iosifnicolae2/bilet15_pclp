#include<stdio.h>

int divizori(int n){
	int i;
	int div=0;
	for(i=1;i<=n/2;i++){
		if(n%i==0){
			div++;
			//printf("Divizorii lui %d sunt %d",n,i);
		}


	}
	return div;
}
int prim(int n){
	int i;
	for(i=2;i<=n/2;i++){
		if(n%i==0)
			return 0;
	}

		return 1;
}


int verific_tab(int n,int *tab,int c){
	int i;
	for(i=0;i<n;i++){
		if(tab[i]==c)
			return 1;
	}
	return 0;
}

void citire(int &n,int *&tab){
	int i,c;
	printf("Introdu dim tablou");
	scanf("%d",&n);
	tab=new int[n];
	for(i=0;i<n;i++){
		printf("tab[%d]=",i);

			scanf("%d",&tab[i]);

		while(verific_tab(i,tab,tab[i])){
			printf("Valoarea introdusa este prezenta in tab[]");
			scanf("%d",tab+i);
		}
	}


}

int main(){
	int n;
	int *tab = NULL;
	int i;
	citire(n,tab);
	FILE *f1,*f2;

//am schimbat ordinea parametrilor
    f1=fopen("nrprime.txt","w+");
    f2=fopen("restu.txt","w+");

	if(f1==NULL){
		printf("Imposibil de deschis fisierul 1");

	}
		if(f2==NULL){
		printf("Imposibil de deschis fisierul 2");

	}
		for(i=0;i<n;i++){
			if(prim(tab[i])==0)
				fprintf(f2,"%d ",tab[i]);
			else
				fprintf(f1,"%d",tab[i]);
		}
		fclose(f1);
		fclose(f2);

		int max=0,val;

		for(i=0;i<n;i++){
			if(max<divizori(tab[i]))
			{
            max=divizori(tab[i]);
            val=tab[i];
			}

		}

	printf("Nr cu cei mai multi divizori este %d",val);

    return 0;
}