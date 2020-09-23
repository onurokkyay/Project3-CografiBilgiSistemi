#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sehir{
    char isim[20];
    int plaka;
    int ksayi;
    char bolge[2];
    struct sehir *sonraki;
    struct komsu *komsular;
};
struct komsu{
int plaka1;
struct komsu *sonraki;
};

void basa_ekle(struct sehir** birinci_ref,char isim[20],int plaka,char bolge[2])
{
struct sehir* yeni_sehir = (struct sehir*) malloc(sizeof(struct sehir));
strcpy(yeni_sehir->isim,isim);
yeni_sehir->plaka = plaka;
strcpy(yeni_sehir->bolge,bolge);
yeni_sehir->sonraki = (*birinci_ref);
(*birinci_ref) = yeni_sehir;
}

void sona_ekle(struct sehir** yeni_ref,char isx[20],int plaka,char bolge[2])
{
struct sehir* yeni_sehir = (struct sehir*) malloc(sizeof(struct sehir));
struct sehir *sonuncu = *yeni_ref;
strcpy(yeni_sehir->isim,isx);
yeni_sehir->plaka = plaka;
strcpy(yeni_sehir->bolge,bolge);
yeni_sehir->sonraki = NULL;
if (*yeni_ref == NULL)
{
*yeni_ref = yeni_sehir;
return;
}
while (sonuncu->sonraki != NULL){
    sonuncu = sonuncu->sonraki;
}
sonuncu->sonraki = yeni_sehir;
return;
}
int b=0;
int m=0;
void komsekle(struct sehir* bas,int plakalar[100][100]){
    while(bas!=NULL){
        struct komsu *komsu1=(struct komsu*)malloc(sizeof(struct komsu));
        komsu1->sonraki=NULL;
struct komsu *sonuncu=bas->komsular;
    for(int j=0;j<15;j++){
        if(plakalar[m][j]!=0){
            komsu1->plaka1=plakalar[m][j];
          //  printf("%d ",komsu1->plaka1);
        }
       // printf("\n");
    }
m++;
printf("m artti");
printf("  %d   ",bas->komsular);
while(bas->komsular==NULL){
printf("null oldu \n");
    bas->komsular=komsu1;
    printf("girdi %d \n",b++);
    printf("%d",bas->komsular->plaka1);
    bas=bas->sonraki;
    printf("geldi \n");
    komsekle(bas,plakalar);
    printf("yazdi");
    return;
}
while(sonuncu->sonraki!=NULL){
    sonuncu=sonuncu->sonraki;
    printf("sa");
}
printf("sa");
sonuncu->sonraki=komsu1;
bas=bas->sonraki;
komsekle(bas,plakalar);
    }

}
void komsyazdir(struct komsu *bas){
     FILE* dos=fopen("cikti.txt","a");
while(bas!=NULL){
    printf("%d ",bas->plaka1);
        fprintf(dos,"%d",bas->plaka1);
         fprintf(dos,"%s"," ");
    bas=bas->sonraki;
}
 fprintf(dos,"%s","\n");
}
void yazdir(struct sehir*bas){

    while(bas!=NULL){
 FILE* dos=fopen("cikti.txt","a");
        printf("%s ",bas->isim);
        fprintf(dos,"%s",bas->isim);
        fprintf(dos,"%s"," ");
        printf("%d ",bas->plaka);
        fprintf(dos,"%d",bas->plaka);
        fprintf(dos,"%s"," ");
        printf("%s ",bas->bolge);
        fprintf(dos,"%s",bas->bolge);
        fprintf(dos,"%s"," ");
        printf("%d ",bas->ksayi);
        fprintf(dos,"%d",bas->ksayi);
        fprintf(dos,"%s"," ");
        fprintf(dos,"%s","\n");
        komsyazdir(bas->komsular);
        printf("\n");
         bas=bas->sonraki;
         fclose(dos);
    }

}
void guncelle(struct sehir*bas){
    FILE* dos=fopen("cikti.txt","w");
    while(bas!=NULL){

        printf("%s ",bas->isim);
        fprintf(dos,"%s",bas->isim);
        fprintf(dos,"%s"," ");
        printf("%d ",bas->plaka);
        fprintf(dos,"%d",bas->plaka);
        fprintf(dos,"%s"," ");
        printf("%s ",bas->bolge);
        fprintf(dos,"%s",bas->bolge);
        fprintf(dos,"%s"," ");
        printf("%d ",bas->ksayi);
        fprintf(dos,"%d",bas->ksayi);
        fprintf(dos,"%s"," ");
        komsyazdir(bas->komsular);
        printf("\n");
         bas=bas->sonraki;
    }
    fclose(dos);

}


void ksayigir(struct sehir*bas,int dizi[]){
    while(bas!=NULL){
            for(int i=0;i<81;i++){
                bas->ksayi=dizi[i];
                bas=bas->sonraki;
            }
    }
}

void sirala(struct sehir*bas,int plakalar[100][100]){
   for(int i=0;i<81;i++){
        for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                     if(plakalar[i][k]>plakalar[i][k+1]){
                    int degisim=plakalar[i][k];
                    plakalar[i][k]=plakalar[i][k+1];
                    plakalar[i][k+1]=degisim;
                   //  printf("%d ",plakalar[i][k]);
                   //  printf("%d \n",plakalar[i][k+1]);
                }
                }

        }
    }
}

int esitmi(struct sehir*bas,char *ko){
   while(strcmp(bas->isim,ko)!=0){
    bas=bas->sonraki;
   }
   return bas->plaka;
}

void kata(struct sehir*bas,int plakalar[100][100]){
    for(int i=0;i<81;i++){
    for(int j=0;j<15;j++){
        if(plakalar[i][j]!=0){

        struct komsu *komsu1=(struct komsu*)malloc(sizeof(struct komsu));
            komsu1->plaka1=plakalar[i][j];
            plakalar[i][j]=0;
            bas->komsular=komsu1;
         //   printf("%d ",bas->komsular->plaka1);
            bas->komsular->sonraki=NULL;
            break;
                }
        }

   // printf("isim %s \n",bas->isim);
    bas=bas->sonraki;
 }
 return;
}
void komsyolla(struct sehir*bas,int plakalar[100][100]){
while(bas!=NULL)
{
    kosonaekle(bas->komsular,plakalar[100][100]);
    bas=bas->sonraki;
}
}


int i=0;
void kosonaekle(struct komsu*bas,int plakalar[100][100]){

            for(int p=0;p<11;p++){
                    struct komsu *komsu1=(struct komsu*)malloc(sizeof(struct komsu));
                    bas->sonraki=komsu1;
                    if(plakalar[i][p]!=0){
                            bas->sonraki->plaka1=plakalar[i][p];
                        //    printf("%d \n",bas->sonraki->plaka1);
                            plakalar[i][p]=0;
                            bas=bas->sonraki;
                            bas->sonraki=NULL;

                                        }
                                }
                                i++;
}

void ksayibul(struct sehir*bas,int sayi){
while(bas!=NULL){
    if(bas->ksayi>=sayi){
    printf("\n %d tane veya daha fazla komsusu olan il:%s \n",sayi,bas->isim);
}
bas=bas->sonraki;
}
}

void araya_ekle(struct sehir* yeni_ref,char isx[20],int plaka,char bolge[2])
{
/*1. onceki dugum NULL mu? */
if (yeni_ref == NULL)
{
printf("onceki dugum NULL olmamalı");
return;
}
/* 2. yeni dugum için yer al */
struct sehir* yeni_dugum =(struct sehir*) malloc(sizeof(struct sehir));
/* 3. yeni dugume yeni veri */
yeni_dugum->plaka = plaka;
strcpy(yeni_dugum->isim,isx);
strcpy(yeni_dugum->bolge,bolge);
/* 4. yeni dugum araya al */
yeni_dugum->sonraki = yeni_ref->sonraki;
yeni_ref->sonraki = yeni_dugum;
}

struct Dugum* sil(struct sehir* dugum,int silVeri){
if(dugum->plaka==silVeri){
    struct sehir* gecici=dugum;
    dugum=dugum->sonraki;
    return dugum;
}
struct sehir* silVeriOnce=dugum;
while(silVeriOnce->sonraki!=NULL && silVeriOnce->sonraki->plaka!=silVeri){
    silVeriOnce=silVeriOnce->sonraki;

}
if(silVeriOnce->sonraki==NULL){
    printf("Silinecek sehir yok.\n");
    return;
}
struct sehir* gecici=silVeriOnce->sonraki;
silVeriOnce->sonraki=silVeriOnce->sonraki->sonraki;
free(gecici);
return dugum;

}

void bonus(struct sehir*bas,int sayi1,int sayi2,int a,int b){
while(bas!=NULL){
        printf("sa \n");
    if(bas->ksayi>sayi1 && bas->ksayi<sayi2){
   // printf("\n %d ile %d arasinda komsusu olan il:%s \n",sayi1,sayi2,bas->isim);
   // printf("%d",bas->komsular->plaka1);
    while(bas->komsular!=NULL){
    if(bas->komsular->plaka1==a || bas->komsular->plaka1==b){
            printf(" %s=>%d ",bas->isim,bas->komsular->plaka1);
printf("as\n");
        bas->komsular=bas->komsular->sonraki;
        printf("%d",bas->komsular->plaka1);
        if(bas->komsular->plaka1==a || bas->komsular->plaka1==b){
                printf("d");
            printf(" %s  %d ",bas->isim,bas->komsular->plaka1);
             }
        }
     bas->komsular=bas->komsular->sonraki;
    }
}
bas=bas->sonraki;
}
}
void bolgeyazdir(struct sehir*bas,char bolge2[2]){
    while(bas!=NULL){
            if(!strcmp(bas->bolge,bolge2)){
        printf("%s ",bas->isim);
        printf("%d ",bas->plaka);
        printf("%s ",bas->bolge);
        printf("%d ",bas->ksayi);
        komsyazdir(bas->komsular);
        printf("\n");
    }
         bas=bas->sonraki;
    }
}

void sehirplakabul(struct sehir*bas,int veri){
    int count=0;
    int tercih;
    int i;
    struct sehir* kok3;
    kok3=bas;
    char isim[20];
    char bolge[20];
    int plaka;
    while(bas!=NULL){
            if(bas->plaka==veri){
        printf("%s ",bas->isim);
        printf("%d ",bas->plaka);
        printf("%s ",bas->bolge);
        printf("%d ",bas->ksayi);
        komsyazdir(bas->komsular);
        count++;
        printf("\n");
    }
         bas=bas->sonraki;
    }
    if(count==0){
        printf("Yazdiginiz plaka ya ait sehir bulunamadi... Yeni sehir olarak eklemek ister misiniz? \n 1.Evet \n 2.Hayir");
        scanf("%d",&tercih);
        switch(tercih){
    case 1:
        printf("Sehrin ismini giriniz:\n");
        scanf("%s",&isim);
        printf("Bolge ismini giriniz:\n");
        scanf("%s",&bolge);
        for(i=0;i<veri-1;i++){
        kok3=kok3->sonraki;
    }

    araya_ekle(kok3,isim,veri,bolge);



        break;
    case 2:
        printf("Eklenmedi");
        break;
        }

    }

}
void sehirisimbul(struct sehir*bas,char isim2[20]){
    int count=0;
    int tercih;
    int i;
    struct sehir* kok4;
    kok4=bas;
    char isim[20];
    char bolge[20];
    int plaka;
    while(bas!=NULL){
            if(!strcmp(bas->isim,isim2)){
        printf("%s ",bas->isim);
        printf("%d ",bas->plaka);
        printf("%s ",bas->bolge);
        printf("%d ",bas->ksayi);
        komsyazdir(bas->komsular);
        count++;
        printf("\n");
    }
         bas=bas->sonraki;
    }
    if(count==0){
        printf("Yazdiginiz sehir ismine ait sehir bulunamadi... Yeni sehir olarak eklemek ister misiniz ?\n 1.Evet \n 2.Hayir");
        scanf("%d",&tercih);
        switch(tercih){
    case 1:
        printf("Bolge ismini giriniz");
        scanf("%s",&bolge);
        printf("Plakasini giriniz:");
        scanf("%d",&plaka);

        for(i=0;i<plaka-1;i++){
        kok4=kok4->sonraki;
            }

    araya_ekle(kok4,isim2,plaka,bolge);

        break;
    case 2:
        printf("Eklenmedi");
        break;
        }

    }
}

int main()
{
    int i=0,k;
    int j=0;
    int p=0;
    int o=0;
    int plakalar[100][100];
    int sayac=0;
    struct sehir *kok=NULL;
    FILE* dosya=fopen("sehirler.txt","r");
    char cumle[100];
    int plk;
    char ism[20];
    char bolg[20];
    char ayrik[50];
    char ozellik[100];
    int dizi[81];
    char *farkli;
    while(!feof(dosya)){
    fscanf(dosya,"%s",cumle);
     plk=atoi(strtok(cumle,","));
     sayac=0;
    while(ayrik!=NULL){
            if(sayac==0){
                 strcpy(ism,strtok(NULL,","));
    sayac++;
            }
            if(sayac==1){
                 strcpy(bolg,strtok(NULL,","));
  sayac++;
    break;
            }
    }
    sona_ekle(&kok,ism,plk,bolg);
    }
    fclose(dosya);
    dosya=fopen("sehirler.txt","r");

while(!feof(dosya)){
        k=0;
        fscanf(dosya,"%s",ozellik);//satir tutar
        farkli=strtok(ozellik,",");
        while(farkli!=NULL){
           // printf("%s \n",farkli);
            farkli=strtok(NULL,",");

            k++;
        }
        dizi[i]=k-3;
        //printf("%d \n",k-3);
        i++;
    }
    ksayigir(kok,dizi); //komsu sayilarini gönderir
    //yazdir(kok);
    fclose(dosya);

    dosya=fopen("sehirler.txt","r");

while(!feof(dosya)){
        fscanf(dosya,"%s",ozellik);//satir tutar
        farkli=strtok(ozellik,",");
         farkli=strtok(NULL,",");
          farkli=strtok(NULL,",");
           farkli=strtok(NULL,",");
        while(farkli!=NULL){
           // printf("%s ",farkli);
             plakalar[o][p++]=esitmi(kok,farkli);
          //  printf("%d \n",plakalar[o][p-1]);
            farkli=strtok(NULL,",");
        }
        o++;
        p=0;

    }
    fclose(dosya);

    sirala(kok,plakalar);

    for(i=0;i<81;i++){
        for(j=0;j<11;j++){
          //  printf("%d %d  %d \n",plakalar[i][j],i,j);
        }
    }

    //komsekle(kok,plakalar);
    kata(kok,plakalar);
    //komsuyolla(kok,plakalar);
    //kosonaekle(kok->komsular,plakalar);
    struct sehir* kok1;
    kok1=kok;
    while(kok1!=NULL){
        kosonaekle(kok1->komsular,plakalar);
        kok1=kok1->sonraki;
    }
    free(kok1);
   // yazdir(kok);
    //ksayibul(kok,3);
    //bonus(kok,3,7,6,42);
//  printf("1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n");
 struct sehir* kok2=kok;
     int hangi_il=0;
  //  printf("hangi il silinecek: \n",hangi_il);
   // scanf("%d",&hangi_il);
    //sil(kok,hangi_il);
   // yazdir(kok);
int secim=0;
int x=0;
int secim_b=0;
int bolgeiste=0;
char sehir_bul[20];
int plaka_bul=0;
  a:      printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
   scanf("%d",&secim);
   if(secim==0){
    printf("Cikiliyor");
   }
   while(secim!=0){
    if(secim < 0 || secim>7){
    printf("Lutfen 0 ile 7 arasinda[0,7] bir sayi giriniz...\n");
    goto a;
    }

   switch(secim){
       case 7:
           printf("case 7 girdi");
        printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
       printf("case 7 girdi");
        guncelle(kok);
        break;
   case 1:
       yazdir(kok);
   printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
       break;
   case 2:
       kok2=kok;
    int hangi_araya=0;
    char ekisim[20];
    char ekbolge[20];
    int ekplaka;
    printf("Hangi araya eklenecek\n");
    scanf("%d",&hangi_araya);
    printf("Sehirin ismini yaziniz\n");
    scanf("%s",&ekisim);
    printf("Plakasini giriniz\n");
    scanf("%d",&ekplaka);
    printf("Bolgesini giriniz\n");
    scanf("%s",&ekbolge);
    for(i=0;i<hangi_araya-1;i++){
        kok2=kok2->sonraki;
    }
    araya_ekle(kok2,ekisim,ekplaka,ekbolge);
    printf("Eklendi \n");
        printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
    break;
   case 3:
        printf("Silinecek sehirin plakasini giriniz\n");
        scanf("%d",&hangi_il);
        sil(kok,hangi_il);
          printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
        break;
   case 4:
    printf("Kac tane komsusu olanlari listeleyelim?\n");
    scanf("%d",&x);
    ksayibul(kok,x);
    printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
        break;
   case 5:
    printf("Listelemek istediginiz bolgeyi seciniz:\n 1.AK\n 2.GA\n 3.EG \n 4.DA\n 5.KA \n 6.IA \n 7.MA\n");
    scanf("%d",&bolgeiste);
    switch(bolgeiste){
        case 1:
            bolgeyazdir(kok,"AK");
        break;
        case 2:bolgeyazdir(kok,"GA");
        break;
        case 3:bolgeyazdir(kok,"EG");
        break;
        case 4:bolgeyazdir(kok,"DA");
        break;
        case 5:bolgeyazdir(kok,"KA");
        break;
        case 6:bolgeyazdir(kok,"IA");
        break;
        case 7:bolgeyazdir(kok,"MA");
    }
    printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Kadar veya x ten fazla komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
        break;
        case 6:
            printf("Sehri nasil bulacaksiniz;\n 1.Sehir isminden \n 2.Plakadan\n");
scanf("%d",&secim_b);

switch(secim_b){

case 1:
printf("Sehir ismini giriniz:\n");
scanf("%s",&sehir_bul);
sehirisimbul(kok,sehir_bul);
break;
case 2:
    printf("Plaka no yu giriniz\n");
    scanf("%d",&plaka_bul);
    sehirplakabul(kok,plaka_bul);
    break;
}
printf("0-Cikis\n1-Sehirleri yazdir \n2-Sehir ekleme\n3-Sehir silme\n4-x Tane komsusu olan sehirleri listele\n5-x Bolgesindeki sehirleri listele\n6-Sehir ara\n7-Guncelle\n");
        scanf("%d",&secim);
break;

   case 0:
    printf("Cikis yapiliyor.");
    break;


   }

}

    }


