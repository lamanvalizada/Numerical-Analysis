#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,j,x,h,m;
	float A[100][100],C[100],a[100][100],y,K[100];
	printf("Katsayilar matrisinin boyutunu giriniz: ");
	scanf("%d",&n);

	printf("Katsayilar matrisini giriniz : \n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%f",&A[i][j]);
		}
	}

	printf("Esitlik sonuclari vektorunu giriniz: \n");
	for (i=0;i<n;i++){
		scanf("%f",&C[i]);
	}
     printf("\n");

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf(" %.2f ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i=0;i<n;i++){
		printf(" %.2f ",C[i]);
	}
	printf("\n");


	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			a[i][j]=A[i][j];
		}
		a[i][n]=C[i];
	}
	printf("\n");

	for(i=0;i<n;i++){
		for (j=i;j<n;j++){
			y=a[j][i];
			for(x=0;x<=n;x++){
				a[j][x]=a[j][x]/y;
			}
		}
		for (j=(i+1) ; j<n ; j++){
			for (x=0 ; x<=n ; x++){
				a[j][x] = a[j][x] - a[i][x];
			}
		}
       for(h=0;h<n;h++){
         for(m=0;m<n;m++){
            printf("%.2f\t",a[h][m]);
         }
        printf("\n");
	   }
        printf("\n");
    }

	K[n-1]=a[n-1][n];

	for (i=(n-2);i>=0;i--){
		K[i]=a[i][n];
		for (j=(i+1);j<n;j++){
			K[i]=K[i]-a[i][j]*K[j];
		}
	}

	printf("Bulunan degerler: \n");
	for (i=0;i<n;i++){
		printf(" %.2f \n",K[i]);
	}
	return 0;
}
