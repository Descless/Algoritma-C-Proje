#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyonlar ve kullanici ve bilgisayarin puanlari

int kp = 0, bp = 0;
void yazdirma(int secilen, char dizi[10]);
int bilgisayar();
void kazanma();
void beraberlik();
void kaybetme();

int main()
{
    int kullanici;
    char pcsecim[10], ksecim[10];
    srand(time(0));
    printf("Tas kagit makas oyununa hos geldin. \n\n1- Tas \n2- Kagit \n3- Makas \n\n");

    // Oyunun genel dongusu, bir taraf 5 puan oldugunda biter

    while(kp<5 && bp<5) {
        printf("Secimini yap:");
        scanf("%d", &kullanici);

        //Kullanici 1, 2, 3 disinda bir sayi girdigi durumda yeni sayi ister

        if(kullanici<1 || kullanici>3)
        printf("lutfen gecerli bir sayi gir\n\n");

        //Kazanma durumlari, secim dizisini buralarda kullaniyorum

        else if(kullanici==1 && bilgisayar()==3 || kullanici==2 && bilgisayar()==1 || kullanici==3 && bilgisayar()==2){
        yazdirma(kullanici, ksecim);
        printf("\nSen %s sectin ve...\n", ksecim);
        yazdirma(bilgisayar(), pcsecim);
        printf("Bilgisayar %s secti \n", pcsecim);
        kazanma();
        }

        //Beraberlik

        else if(kullanici==bilgisayar()){
        yazdirma(kullanici, ksecim);
        printf("\nSen %s sectin ve...\n", ksecim);
        yazdirma(bilgisayar(), pcsecim);
        printf("Bilgisayar %s secti \n", pcsecim);
        beraberlik();
        }

        //Kalan durumlar da kaybetme durumlaridir

        else{

        yazdirma(kullanici, ksecim);
        printf("\nSen %s sectin ve...\n", ksecim);
        yazdirma(bilgisayar(), pcsecim);
        printf("Bilgisayar %s secti \n", pcsecim);
        kaybetme();
        }
    }

    //Oyunun sonunda toplam skorlari gösterir ve kimin kazandigini soyler

    printf("Sonuc:\nSen - %d  Bilgisayar - %d\n", kp, bp);

    if(kp>bp)
        printf("Sen kazandin");

    else
        printf("Bilgisayar kazandi");

    return 0;

}

// Bilgisayarin 1-3 arasinda rastgele bir sayi olusturdugu fonksiyon

int bilgisayar(){
    return rand()%3 + 1;
}

// Bu fonksiyon kullanicinin ve bilgisayarin sectigi sayiya gore "secim" dizisine tas, kagit veya makas yazdiriyor, o diziye de printf ile yazdiriyorum

void yazdirma(int secilen, char dizi[10]){
    if(secilen==1)
    strcpy(dizi, "tas");
    if(secilen==2)
    strcpy(dizi, "kagit");
    if(secilen==3)
    strcpy(dizi, "makas");
}

//Kazanma durumunda kazandin yazdirip kullanicinin puanini 1 arttiran fonksiyon

void kazanma(){
    printf("Kazandin!\n\n");
    kp++;
}

//Beraberlik durumunda puan artisi olmaz ve sadece berabere yazdirir

void beraberlik(){
    printf("Berabere!\n\n");
}

//Kaybetme durumunda kaybettin yazdirir ve bilgisayarin puanini 1 arttirir

void kaybetme(){
    printf("Kaybettin!\n\n");
    bp++;
}
