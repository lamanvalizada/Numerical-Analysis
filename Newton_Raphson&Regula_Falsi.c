#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a4,a3,a2,a1,a0,k,iterasyon,x0;
    float yM,xL,xR,xM,yL,yR;
    int i=0;


    printf("Katsayilari giriniz:\n");
    printf("a0:");
    scanf("%d",&a0);
    printf("a1:");
    scanf("%d",&a1);
    printf("a2:");
    scanf("%d",&a2);
    printf("a3:");
    scanf("%d",&a3);
    printf("a4:");
    scanf("%d",&a4);
    printf("%d*x^4+%d*x^3+%d*x^2+%d*x^1+%d*x^0\n",a4,a3,a2,a1,a0);
    printf("Epsilon degerini girin:");
    scanf("%f",&yM);
    printf("Maksimum iterasyon sayisini giriniz:");
    scanf("%d",&iterasyon);
    printf("Newton Raphson yontemi icin 1e basin\nRegula Falsi icin 2ye basin\n");
    scanf("%d",&k);

    if(k==1)
    {
        printf("x0 baslangic degeri giriniz:");
        scanf("%d",&x0);
        double x=x0;
        while(x>yM && i<iterasyon )
        {
            x=x-(a4*pow(x,4)+a3*pow(x,3)+a2*pow(x,2)+a1*pow(x,1)+a0)/(a4*4*pow(x,3)+a3*3*pow(x,2)+a2*2*pow(x,1)+a1);
            printf("x%d=%f\n",i,x);
            i+=1;
        }

    }
    if (k==2)
    {
        printf("xL baslangic tahminini giriniz:");
        scanf("%f",&xL);
        printf("xR baslangic tahminini giriniz:");
        scanf("%f",&xR);
         xM=xL;
        while(xM>yM && i<iterasyon){
            yL=(a4*pow(xL,4)+a3*pow(xL,3)+a2*pow(xL,2)+a1*xL+a0);
            yR=(a4*pow(xR,4)+a3*pow(xR,3)+a2*pow(xR,2)+a1*xR+a0);
            xM=((xL*yR)-(xR*yL))/(yR-yL);
            printf("%d.Iterasyon:",i);
            printf("xM=%f\t yL=%f\t yR=%f\n",xM,yL,yL,yR);
            xL=xM;
            i=i+1;
        }
    }


    return 0;
}
