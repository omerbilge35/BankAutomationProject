#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
/*
HAZIRLAYANLAR:OMER FURKAN BILGE 182803052
              SAMED KAZANIR 182803053
              BEKIR AKINCI 182803009
*/
struct Hesap
    {
    char isim[20];
    char soyisim[20];
    int musteri_no;
    int hesap_no;
    int yas;
    long long int tc_no;
    long long int tel_no;
    float bakiye;
    };
void musteri_ekle();
void hesap_ekle();
void para_cekme();
void kontrol_et();
void para_yatirma();
void hesap_kapat();


struct Hesap ekle;
struct Hesap hesap_ac;
struct Hesap para_cek;
struct Hesap kontrol;
struct Hesap para_yatir;
struct Hesap hesap_kapa;


void hesap_kapat()
{
   int hesap_no,secim,k=0;
   FILE *fp11;
   FILE *fp12;
   hata1:
   printf("\n Kapatmak istediginiz hesap numarasini giriniz:");
   scanf("%d",hesap_no);
   system("cls");

   if(hesap_no<20000)
   {
      if((fp11=fopen("Bireysel.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp12=fopen("Bireysel2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
   }
   else if(hesap_no>20000)
   {
       if((fp11=fopen("Ticari.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp12=fopen("Ticari2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
   }

   while (fread(&hesap_kapa,sizeof(hesap_kapa),1,fp11)==1)
        {

             if(hesap_no==hesap_kapa.hesap_no)
                {
                    if(hesap_kapa.bakiye!=0)
                    {

                       printf("\n\tHesabinizi kapatmak icin bakiyenizin 0 Tl olmasi gerekmektedir...");

                       fwrite(&hesap_kapa, sizeof(hesap_kapa), 1, fp12);

                    }
                    else
                    {
                        printf("\n\n\tHesabiniz Basariyla Silinmistir....");
                    }
                    k++;
                }
            else
            {
                fwrite(&hesap_kapa, sizeof(hesap_kapa), 1, fp12);
            }
        }
        if(k==0)
        {
           printf("\nHesap No Bulunamadi.");
        }

        fclose(fp11);
        fclose(fp12);
        if(hesap_no<20000)
          {
             remove("Bireysel.txt");
             rename("Bireysel2.txt","Bireysel.txt");
          }
        if(hesap_no>20000)
          {
             remove("Ticari.txt");
             rename("Ticari2.txt","Ticari.txt");
          }





}


void para_yatirma()
{
  int hesap_no,secim;
  float miktar=0;

  printf("Para yatirmak istediginiz hesap numarasini giriniz:");
  scanf("%d",&hesap_no);
   if(hesap_no<20000)
  {

      FILE *fp7;
      FILE *fp8;
      if((fp7=fopen("Bireysel.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp8=fopen("Bireysel2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }

        while (fread(&para_yatir,sizeof(para_yatir),1,fp7)==1)
        {
            if(hesap_no==para_yatir.hesap_no)
            {

                 printf("\n Isim:%s",para_yatir.isim);
                 printf("\n Soyisim:%s",para_yatir.soyisim);
                 printf("\n Yas:%d",para_yatir.yas);
                 printf("\n TC No:%lld",para_yatir.tc_no);
                 printf("\n Telefon No:%lld",para_yatir.tel_no);
                 printf("\n Musteri No:%d",para_yatir.musteri_no);
                 printf("\n Bakiye:%.2f",para_yatir.bakiye);

                 printf("\n\n Yatirmak istediginiz miktari giriniz:");
                 scanf("%f",&miktar);

                 para_yatir.bakiye+=miktar;
                 fwrite(&para_yatir, sizeof(para_yatir), 1, fp8);
                 printf("\n\n Islem basariyla gerceklestirildi.");
                 printf("\n\n Yeni bakiyeniz:%.2f",para_yatir.bakiye);


               }

            else
            {
                fwrite(&para_yatir, sizeof(para_yatir), 1, fp8);
            }

          }
        printf("\n\n\tIsleminiz Basariyla Gerceklesmistir.");
        fclose(fp7);
        fclose(fp8);
        remove("Bireysel.txt");
        rename("Bireysel2.txt","Bireysel.txt");


  }
  else if(hesap_no>20000)
  {
       FILE *fp9;
       FILE *fp10;
      if((fp9=fopen("Ticari.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp10=fopen("Ticari2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }

        while (fread(&para_yatir, sizeof(para_yatir), 1, fp9)==1)
        {
            if(para_yatir.hesap_no==hesap_no)
            {

                 printf("\n Isim:%s",para_yatir.isim);
                 printf("\n Soyisim:%s",para_yatir.soyisim);
                 printf("\n Yas:%d",para_yatir.yas);
                 printf("\n TC No:%lld",para_yatir.tc_no);
                 printf("\n Telefon No:%lld",para_yatir.tel_no);
                 printf("\n Musteri No:%d",para_yatir.musteri_no);
                 printf("\n Bakiye:%.2f",para_yatir.bakiye);

                 printf("\n\n Yatirmak istediginiz miktari giriniz:");
                 scanf("%f",&miktar);

                 para_yatir.bakiye+=miktar;
                 fwrite(&para_yatir, sizeof(para_yatir), 1, fp10);
                 printf("\n\n Islem basariyla gerceklestirildi.");
                 printf("\n\n Yeni bakiyeniz:%.2f",para_yatir.bakiye);


               }

            else
            {
                fwrite(&para_yatir, sizeof(para_yatir), 1, fp10);
            }

          }
        printf("\n\n\tIsleminiz Basariyla Gerceklesmistir.");
        fclose(fp9);
        fclose(fp10);
        remove("Ticari.txt");
        rename("Ticari2.txt","Ticari.txt");

  }




        int menu_sec;
        menusecim6:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim6;
        }

}


void para_cekme()
{

  int hesap_no,secim;
  float miktar=0,tempmiktar1,tempmiktar2;

  printf("\n Para cekmek istediginiz hesap numarasini giriniz:");
  scanf("%d",&hesap_no);

  if(hesap_no<20000)
  {

      FILE *fp5;
      FILE *fp6;
      if((fp5=fopen("Bireysel.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp6=fopen("Bireysel2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }

        while (fread(&para_cek,sizeof(para_cek),1,fp5)==1)
        {
            if(para_cek.hesap_no==hesap_no)
            {

                 printf("\n Isim:%s",para_cek.isim);
                 printf("\n Soyisim:%s",para_cek.soyisim);
                 printf("\n Yas:%d",para_cek.yas);
                 printf("\n TC No:%lld",para_cek.tc_no);
                 printf("\n Telefon No:%lld",para_cek.tel_no);
                 printf("\n Musteri No:%d",para_cek.musteri_no);
                 printf("\n Bakiye:%.2f",para_cek.bakiye);
                 tekrar5:
                 printf("\n\n Cekmek istediginiz miktari giriniz:");
                 scanf("%f",&miktar);

                 if(miktar>750)
                 {   system("cls");
                     printf("\n Hata!Bireysel musterilerin gunde maksimum cekebilecegi miktar 750 TL'dir.");
                     goto tekrar5;
                 }
                 if(miktar>para_cek.bakiye)
                 {
                    system("cls");
                    printf(" Hata!Hesabinizda yeterli bakiye bulunmamaktadir.\n");
                    printf("\n\n\t1.Yeni bir miktar girmek istiyorum.\n\t2.Farkli bir hesap kullanmak istiyorum.\n\t3.Ana Menuye Don\n\n\tSecim:");
                    scanf("%d",&secim);
                    system("cls");
                    if(secim==3)
                        menu();

                    if(secim==1)
                    {
                          miktar=0;
                          goto tekrar5;
                    }


                    else if(secim==2)
                    {
                        tempmiktar1=para_cek.bakiye;
                        miktar-=tempmiktar1;
                        int musteri_no1;
                        musteri_no1=para_cek.musteri_no;
                        para_cek.bakiye=0;
                        fwrite(&para_cek, sizeof(para_cek), 1, fp6);
                        bakiyesorunu:
                        printf("\n Para cekmek istediginiz hesap numarasini giriniz:");
                        scanf("%d",&hesap_no);
                        rewind(fp5);
                        while (fread(&para_cek,sizeof(para_cek),1,fp5)==1)
                        {
                            if(para_cek.musteri_no==musteri_no1)
                            {
                                if(para_cek.hesap_no==hesap_no)
                                {
                                    tempmiktar2=para_cek.bakiye;
                                    if(tempmiktar2<miktar)
                                    {
                                        system("cls");
                                        printf("\n\n\tHata!Yetersiz Bakiye.Ne yapmak istersiniz?");
                                        printf("\n\n\t1.Baska hesaptan para cekmek\n\t2.");
                                        goto bakiyesorunu;
                                        //SONRA DOLDUR:
                                    }
                                    tempmiktar2-=miktar;
                                    para_cek.bakiye=tempmiktar2;
                                    printf("Yeni Bakiye:%.2f",para_cek.bakiye);

                                    fwrite(&para_cek, sizeof(para_cek), 1, fp6);


                                }

                            }
                            else
                            {
                                fwrite(&para_cek, sizeof(para_cek), 1, fp6);
                            }


                        }


                    }

                }
                else
                {

                    float kalan=0;
                    kalan=para_cek.bakiye-miktar;
                    para_cek.bakiye=kalan;
                    printf("\n\nKalan Bakiye:%.2f",para_cek.bakiye);
                    fwrite(&para_cek, sizeof(para_cek), 1, fp6);

                }


            }
            else
            {
                fwrite(&para_cek, sizeof(para_cek), 1, fp6);
            }
        }

        printf("\n Isleminiz Basariyla Gerceklesmistir.");
        fclose(fp5);
        fclose(fp6);
        remove("Bireysel.txt");
        rename("Bireysel2.txt","Bireysel.txt");
        fflush(stdin);
        int menu_sec;
        menusecim5:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim5;
        }
  }
  if(hesap_no>20000)
  {

      FILE *fp7;
      FILE *fp8;
      if((fp7=fopen("Ticari.txt","r"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }
        if((fp8=fopen("Ticari2.txt","a"))==NULL)
        {
        printf("Dosya Acilamadi!\n");
        exit(1);
        }

        while (fread(&para_cek,sizeof(para_cek),1,fp7)==1)
        {
            if(para_cek.hesap_no==hesap_no)
            {

                 printf("\n Isim:%s",para_cek.isim);
                 printf("\n Soyisim:%s",para_cek.soyisim);
                 printf("\n Yas:%d",para_cek.yas);
                 printf("\n TC No:%lld",para_cek.tc_no);
                 printf("\n Telefon No:%lld",para_cek.tel_no);
                 printf("\n Musteri No:%d",para_cek.musteri_no);
                 printf("\n Bakiye:%.2f",para_cek.bakiye);
                 tekrar6:
                 printf("\n\n Cekmek istediginiz miktari giriniz:");
                 scanf("%f",&miktar);

                 if(miktar>1500)
                 {   system("cls");
                     printf("\n Hata!Ticari musterilerin gunde maksimum cekebilecegi miktar 1500 TL'dir.");
                     goto tekrar6;
                 }
                 if(miktar>para_cek.bakiye)
                 {
                    system("cls");
                    printf("Hata!Hesabinizda yeterli bakiye bulunmamaktadir.\n");
                    printf("\n\n\t1.Yeni bir miktar girmek istiyorum.\n\t2.Farkli bir hesap kullanmak istiyorum.\n\t3.Ana Menuye Don\n\n\tSecim:");
                    scanf("%d",&secim);
                    system("cls");
                    if(secim==3)
                        menu();

                    if(secim==1)
                    {
                          miktar=0;
                          goto tekrar5;
                    }


                    else if(secim==2)
                    {
                        float tempmiktar1;
                        tempmiktar1=para_cek.bakiye;
                        miktar-=tempmiktar1;
                        int musteri_no1;
                        musteri_no1=para_cek.musteri_no;
                        para_cek.bakiye=0;
                        fwrite(&para_cek, sizeof(para_cek), 1, fp8);
                        bakiyesorunu2:
                        printf("\n Para cekmek istediginiz hesap numarasini giriniz:");
                        scanf("%d",&hesap_no);
                        rewind(fp7);
                        while (fread(&para_cek,sizeof(para_cek),1,fp7)==1)
                        {
                            if(para_cek.musteri_no==musteri_no1)
                            {
                                if(para_cek.hesap_no==hesap_no)
                                {
                                    float tempmiktar2;
                                    tempmiktar2=para_cek.bakiye;
                                    if(tempmiktar2<miktar)
                                    {
                                        system("cls");
                                        printf("\n\n\tHata!Yetersiz Bakiye.Ne yapmak istersiniz?");
                                        printf("\n\n\t1.Baska hesaptan para cekmek\n\t2.");
                                        goto bakiyesorunu2;
                                        //SONRA DOLDUR:
                                    }
                                    tempmiktar2-=miktar;
                                    para_cek.bakiye=tempmiktar2;
                                    printf("Yeni Bakiye:%.2f",para_cek.bakiye);

                                    fwrite(&para_cek, sizeof(para_cek), 1, fp8);


                                }

                            }
                        }


                    }

                }
                else
                {

                    float kalan=0;
                    kalan=para_cek.bakiye-miktar;
                    para_cek.bakiye=kalan;
                    printf("\n\nKalan Bakiye:%.2f",para_cek.bakiye);
                    fwrite(&para_cek, sizeof(para_cek), 1, fp8);

                }


            }
            else
            {
                fwrite(&para_cek, sizeof(para_cek), 1, fp8);
            }
        }

        printf("\n Isleminiz Basariyla Gerceklesmistir.");
        fclose(fp7);
        fclose(fp8);
        remove("Ticari.txt");
        rename("Ticari2.txt","Ticari.txt");
        int menu_sec;
        menusecim6:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim6;
        }
  }
}

void hesap_ekle()
{
    int secim;
    int musteri_no;
    tekrar2:
    printf("\n\n\t\t1.Bireysel Musteri\n\t\t2.Ticari Musteri");
    printf("\n\n\t\tSecim:");
    scanf("%d",&secim);
    system("cls");
    if(secim==1)
    {
        FILE *fp;
        if((fp=fopen("Bireysel.txt","r"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }
        yeniden:
        printf("\n\n\t\tMusteri No giriniz:");
        scanf("%d",&musteri_no);
        int hesap_no;
        int x=0;
        srand(time(0));
        hesap_no=10000+rand()%10000;
        hesap_ac.hesap_no=hesap_no;
        while (fread(&hesap_ac,sizeof(hesap_ac),1,fp)==1)
        {
            if(musteri_no==hesap_ac.musteri_no)
            {
                 printf("\n Isim:%s",hesap_ac.isim);
                 printf("\n Soyisim:%s",hesap_ac.soyisim);
                 printf("\n Yas:%d",hesap_ac.yas);
                 printf("\n TC No:%lld",hesap_ac.tc_no);
                 printf("\n Telefon No:%lld",hesap_ac.tel_no);
                 printf("\n Musteri No:%d\n",hesap_ac.musteri_no);
                 x++;
                 break;
            }
        }
        if(x==0)
        {
            system("cls");
            printf("\n\n\tYanlis ya da eksik musteri numarasi girdiniz....");
            printf("\n\tLutfen tekrar deneyiniz\n");
            goto yeniden;
        }
        fclose(fp);
        FILE *fp3;
        if((fp3=fopen("Bireysel.txt","a"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }

        hesap_ac.hesap_no=hesap_no;
        printf("\n Hesabiniza yatirmak istediginiz miktari giriniz:");
        scanf("%f",&hesap_ac.bakiye);
        fwrite(&hesap_ac, sizeof(hesap_ac), 1, fp3);
        fclose(fp3);
        system("cls");
        printf("\n\n Hesabiniz Basariyla Acilmistir....\n\n\n");
        printf("\n Isim:%s",hesap_ac.isim);
        printf("\n Soyisim:%s",hesap_ac.soyisim);
        printf("\n Yas:%d",hesap_ac.yas);
        printf("\n TC No:%lld",hesap_ac.tc_no);
        printf("\n Telefon No:%lld",hesap_ac.tel_no);
        printf("\n Musteri No:%d",hesap_ac.musteri_no);
        printf("\n Bakiye:%.2f",hesap_ac.bakiye);
        printf("\n Hesap No:%d",hesap_ac.hesap_no);

        int menu_sec;
        menusecim3:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim3;
        }

    }
    else if (secim==2)
    {
        FILE *fp2;
        if((fp2=fopen("Ticari.txt","r"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }
        yeniden2:
        printf("\n\n\t\tMusteri No giriniz:");
        scanf("%d",&musteri_no);
        int hesap_no;
        int x=0;
        srand(time(0));
        hesap_no=20000+rand()%10000;
        hesap_ac.hesap_no=hesap_no;
        while (fread(&hesap_ac,sizeof(hesap_ac),1,fp2)==1)
        {
            if(musteri_no==hesap_ac.musteri_no)
            {
                 printf("\n Isim:%s",hesap_ac.isim);
                 printf("\n Soyisim:%s",hesap_ac.soyisim);
                 printf("\n Yas:%d",hesap_ac.yas);
                 printf("\n TC No:%lld",hesap_ac.tc_no);
                 printf("\n Telefon No:%lld",hesap_ac.tel_no);
                 printf("\n Musteri No:%d",hesap_ac.musteri_no);
                 printf("\n Hesap No:%d\n",hesap_ac.hesap_no);
                 x++;
                 break;
            }
        }
         if(x==0)
        {
            system("cls");
            printf("\n\n\tYanlis ya da eksik musteri numarasi girdiniz....");
            printf("\n\tLutfen tekrar deneyiniz\n");
            goto yeniden2;
        }
        fclose(fp2);
        FILE *fp4;
        if((fp4=fopen("Ticari.txt","a"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }

        hesap_ac.hesap_no=hesap_no;
        printf("\n Hesabiniza yatirmak istediginiz miktari giriniz:");
        scanf("%f",&hesap_ac.bakiye);
        fwrite(&hesap_ac, sizeof(hesap_ac), 1, fp4);
        fclose(fp4);
        system("cls");
        printf("\n\n Hesabiniz Basariyla Acilmistir....\n\n\n");
        printf("\n Isim:%s",hesap_ac.isim);
        printf("\n Soyisim:%s",hesap_ac.soyisim);
        printf("\n Yas:%d",hesap_ac.yas);
        printf("\n TC No:%lld",hesap_ac.tc_no);
        printf("\n Telefon No:%lld",hesap_ac.tel_no);
        printf("\n Musteri No:%d",hesap_ac.musteri_no);
        printf("\n Bakiye:%.2f",hesap_ac.bakiye);
        printf("\n Hesap No:%d",hesap_ac.hesap_no);

        int menu_sec;
        menusecim4:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim4;
        }

    }
    else
    {
        system("cls");
        printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
        goto tekrar2;
    }

}


void musteri_ekle()
{
    int secim;
    tekrar:
    printf("\n\n\t\t1.Bireysel Musteri\n\t\t2.Ticari Musteri\n");
    printf("\n\n\n\t\tSeciminizi Giriniz:");
    scanf("%d",&secim);

    system("cls");
    if(secim==1)
    {

        FILE *BireyselTxt;

        int hesap_no;
        srand(time(0));
        hesap_no=10000+rand()%10000;
        ekle.hesap_no=hesap_no;

        int musteri_no;
        srand(time(0));
        musteri_no=1000+rand()%1000;
        ekle.musteri_no=musteri_no;

        printf("Isim:");
        scanf("%s",&ekle.isim);

        printf("Soyisim:");
        scanf("%s",&ekle.soyisim);

        printf("Yas:");
        scanf("%d",&ekle.yas);

        printf("TC No:");
        scanf("%lld",&ekle.tc_no);

        printf("Telefon No:");
        scanf("%lld",&ekle.tel_no);

        printf("Hesabiniza yatirmak istediginiz miktari giriniz:");
        scanf("%f",&ekle.bakiye);

        BireyselTxt=fopen("Bireysel.txt","a");

        fwrite(&ekle, sizeof(ekle), 1, BireyselTxt);
        fclose(BireyselTxt);
        system("cls");
        printf("\n\n Hesabiniz Basariyla Acilmistir....\n\n\n");
        printf("\n Isim:%s",ekle.isim);
        printf("\n Soyisim:%s",ekle.soyisim);
        printf("\n Yas:%d",ekle.yas);
        printf("\n TC No:%lld",ekle.tc_no);
        printf("\n Telefon No:%lld",ekle.tel_no);
        printf("\n Musteri No:%d",ekle.musteri_no);
        printf("\n Bakiye:%.2f",ekle.bakiye);
        printf("\n Hesap No:%d",ekle.hesap_no);

        int menu_sec1;
        menusecim1:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec1);
        if(menu_sec1==1)
            menu();

        else if (menu_sec1==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim1;
        }


    }
    else if (secim==2)
    {
        FILE *TicariTxt;

        int hesap_no;
        srand(time(0));
        hesap_no=20000+rand()%10000;
        ekle.hesap_no=hesap_no;

        int musteri_no;
        srand(time(0));
        musteri_no=2000+rand()%1000;
        ekle.musteri_no=musteri_no;

        printf("Isim:");
        scanf("%s",&ekle.isim);

        printf("Soyisim:");
        scanf("%s",&ekle.soyisim);

        printf("Yas:");
        scanf("%d",&ekle.yas);

        printf("TC No:");
        scanf("%lld",&ekle.tc_no);

        printf("Telefon No:");
        scanf("%lld",&ekle.tel_no);

        printf("Hesabiniza yatirmak istediginiz miktari giriniz:");
        scanf("%f",&ekle.bakiye);

        TicariTxt=fopen("Ticari.txt","a");

        fwrite(&ekle, sizeof(ekle), 1, TicariTxt);
        fclose(TicariTxt);
        system("cls");
        printf("\n\n Hesabiniz Basariyla Acilmistir....\n\n\n");
        printf("\n Isim:%s",ekle.isim);
        printf("\n Soyisim:%s",ekle.soyisim);
        printf("\n Yas:%d",ekle.yas);
        printf("\n TC No:%lld",ekle.tc_no);
        printf("\n Telefon No:%lld",ekle.tel_no);
        printf("\n Musteri No:%d",ekle.musteri_no);
        printf("\n Bakiye:%.2f",ekle.bakiye);
        printf("\n Hesap No:%d",ekle.hesap_no);

        int menu_sec1;
        menusecim2:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec1);
        if(menu_sec1==1)
            menu();

        else if (menu_sec1==2)
            exit(1);
        else
        {   system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim2;
        }
    }
     else
    {
        system("cls");
        printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
        goto tekrar;
    }
}
void kontrol_et()
{
    FILE *kntrl;
    int secim;
    geridon:
    printf("\n\n\t\t1.Bireysel Musteri\n\t\t2.Ticari Musteri\n");
    printf("\n\n\n\t\tSeciminizi Giriniz:");
    scanf("%d",&secim);
    if(secim==1)
    {



    if((kntrl=fopen("Bireysel.txt","r"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }
    }
    else if(secim==2)
    {

        if((kntrl=fopen("Ticari.txt","r"))==NULL)
        {
            printf("Dosya Acilamadi!\n");
            exit(1);
        }
    }
    else
        goto geridon;
          system("cls");
    while (fread(&kontrol,sizeof(kontrol),1,kntrl)==1)
        {
            printf("--------------------\n");
            printf("Isim:%s\n",kontrol.isim);
            printf("Soyisim:%s\n",kontrol.soyisim);
            printf("Musteri No:%d\n",kontrol.musteri_no);
            printf("Hesap No:%d\n",kontrol.hesap_no);
            printf("Yas:%d\n",kontrol.yas);
            printf("Tc No:%lld\n",kontrol.tc_no);
            printf("Tel No:%lld\n",kontrol.tel_no);
            printf("Bakiye:%.2f\n",kontrol.bakiye);
            fflush(stdin);


        }
        fclose(kntrl);
        int menu_sec;
        menusecim6:
        printf("\n\n\t1.Menuye Don\n\t2.Cikis");
        printf("\n\tSecim:");
        scanf("%d",&menu_sec);
        if(menu_sec==1)
            menu();

        else if (menu_sec==2)
            exit(1);
        else
        {
            system("cls");
            printf("\n\n\tHatali Giris!!!\n\tLutfen Tekrar Seciniz...");
            goto menusecim6;
        }
}





 void menu()
{
    int secim;
    system("cls");
    printf("\n\n\n\t\t\t------- ANA MENUYE HOS GELDINIZ -------");
    printf("\n\n\t\t1.Musteri Kayit\n\t\t2.Hesap Acma\n\t\t3.Para Cekme\n\t\t4.Para Yatirma\n\t\t5.Havale Yapma\n\t\t6.Hesap Bilgilerini Goruntule\n\t\t7.Banka Gelir-Gider Raporu\n\t\t8.Hesap Kapatma\n\t\t9.Veri Tabani\n\t\t10.Cikis");
    printf("\n\n\n\t\tSeciminizi Giriniz:");
    scanf("%d",&secim);

    system("cls");
    switch(secim)
    {
        case 1:musteri_ekle();
        break;
        case 2:hesap_ekle();
        break;
        case 3:para_cekme();
        break;
        case 4:para_yatirma();
        break;
        case 5:;
        break;
        case 6:;
        break;
        case 7:;
        break;
        case 8:hesap_kapat();
        break;
        case 9:kontrol_et();
        break;
        case 10:exit(1);
        break;

    }
}


int main()
{
  menu();
}






/*
 while (fread(&ekle,sizeof(ekle),1,BireyselTxt)==1)
        {
            printf("Isim:%s\n",ekle.isim);
            printf("Soyisim:%s\n",ekle.soyisim);
            printf("Musteri No:%d\n",ekle.musteri_no);
            printf("Hesap No:%d\n",ekle.hesap_no);
            printf("Yas:%d\n",ekle.yas);
            printf("Tc No:%s\n",ekle.tc_no);
            printf("Tel No:%s\n",ekle.tel_no);
            printf("Bakiye:%.2f\n",ekle.bakiye);

        }

*/

/*
  else
                {
                    hata3:
                printf("\n Eksik ya da hatali bir musteri no girdiniz.");
                printf("\n\n\t1.Farkli bir musteri no girmek istiyorum.\n\t2.Ana menuye donmek istiyorum.");
                scanf("%d",secim);

                if(secim==1)
                {
                    fclose(fp11);
                    fclose(fp12);
                    goto hata1;
                }

                else if(secim==2)
                    menu();
                else
                    goto hata3;
                }
                */

