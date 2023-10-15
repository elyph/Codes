#include <stdio.h>
#include <stdlib.h>

struct Yapi {
    int data;
    struct Yapi* next;
};

void diziFonksiyonu();
void diziYazdir(int boyut, int *dizi);
void pointerFonksiyonu();
void pointerYazdir(int *degisken);
void structFonksiyonu();
void structYazdir(struct Yapi* ucuncuVeri);

int main()
{
    int secim;
    printf("1-dizi\n2-pointer\n3-struck\nSeciniz ve sectiginiz sayiyi giriniz.\n");
    scanf("%d", &secim);

    if(secim==1)
    {
        diziFonksiyonu();
    }

    else if(secim==2)
    {
        pointerFonksiyonu();
    }

    else if(secim==3)
    {
        structFonksiyonu();
    }

    return 0;
}

void diziFonksiyonu()
{
    int n;

    printf("Dizi boyutunu giriniz:\n");
    scanf("%d", &n);
    int dizi[n];

    for(int i=0; i<n; i++)
    {
        printf("Dizinin %d. elemanini giriniz:\n", i+1);
        scanf("%d", &dizi[i]);
    }
    diziYazdir(n, dizi);
}

void diziYazdir(int boyut, int *dizi)
{
    for(int i=0; i<boyut; i++)
    {
        printf("Dizinin %d. elemani: %d\n", i+1, dizi[i]);
    }
}

void pointerFonksiyonu()
{
    int x;

    printf("x degiskenini giriniz:\n");
    scanf("%d", &x);

    pointerYazdir(&x);
}

void pointerYazdir(int *degisken)
{
    printf("x degiskeninin bellek adresi:%p\n", degisken);
    printf("Pointer'in gosterdigi yerdeki deger:%d\n", *degisken);
}

void structFonksiyonu()
{
    struct Yapi* mevcut = NULL;
    struct Yapi* ilk = NULL;
    struct Yapi* son = NULL;
    int sayac=0;

    while(1)
    {
        int veri;
        printf("Veri giriniz (Cikmak icin 0):");
        scanf("%d", &veri);

        if(veri==0)
        {
            break;
        }

        if(ilk==NULL)
        {
            ilk=(struct Yapi*)malloc(sizeof(struct Yapi));
            ilk->data=veri;
            ilk->next=NULL;
            son=ilk;
            mevcut=ilk;
        }
        else
        {
            son->next = (struct Yapi*)malloc(sizeof(struct Yapi));
            son=son->next;
            son->data=veri;
            son->next=NULL;
            mevcut=son;
        }
        sayac++;
    }

    if (sayac<4)
    {
        printf("En az 4 veri girmelisiniz.\n");
    }
    else
    {
        struct Yapi* ucuncuVeri = ilk;

        for (int i = 0; i < 2; i++)
        {
            ucuncuVeri->next != NULL;
            ucuncuVeri = ucuncuVeri->next;
        }
        structYazdir(ucuncuVeri);
    }
}

void structYazdir(struct Yapi* ucuncuVeri)
{
        printf("3. elemanin verisi: %d\n", ucuncuVeri->data);
}

