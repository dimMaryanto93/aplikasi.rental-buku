#include <stdio.h>
#include <conio.h>

//deklarasi Global
int x,j,i,a[3],jmlbuku,jumlahnya,jenis_b[10],qty[10],h_buku[100],bayar[100],diskon[100],jml;
char nami[25],dafbuku[25][25],kode[10][100];


//untuk keterangan dalam table
char ket[7][25]={"No","No buku","Judul buku","Jml sewa","Hrg sewa","Disc/buku","Hrg stl disc"};

//definisi fungsi selain main()
void masukan(void);
void keluaran(void);
void rumus(void);

//deklarasi fungsi masukan
void masukan(void)
{
     puts("PROGRAM MENGHITUNG RENTAL BUKU KOMIC");
     puts("___________________________________________________________________________");
     puts("DATA PRIBADI");
     puts("   "); 
     printf("Nama peminjam               : ");scanf("%s",nami);
     puts("   ");
     printf("Jumlah buku yang dipijam    : ");scanf("%d",&jmlbuku);
     puts("_________________________________________________________________________");
                    
     //perulangan untuk memasukan buku
     i=1;
     do
     {
                    printf("Nama Buku Komic ke %d adalah : ",i);scanf("%s",dafbuku[i]);
                    printf("\n");
                    printf("Masukan serial number komic : ");scanf("%s",kode[i]);
                    printf("\n");
                    printf("1.Action \n2.Animation \n3.Horor \n4.Sport \n");
                    printf("\n");
                    printf("pilih jenis buku             : ");scanf("%d",&jenis_b[i]);
                    printf("                          qty: ");scanf("%d",&qty[i]); 
                    if (jenis_b[i]==1)
                    {
                         h_buku[i] = 3500;
                         diskon[i] = 350;
                         bayar[i]=(qty[i]*h_buku[i]) - (qty[i]*diskon[i]);  
                    }
                    else if (jenis_b[i]==2)
                    {
                         h_buku[i]=3000;
                         diskon[i] =300;
                         bayar[i]=(qty[i]*h_buku[i]) - (qty[i]*diskon[i]); 
                    }
                    else if (jenis_b[i]==3)
                    {
                         h_buku[i]=2500;
                         diskon[i]=0;
                         bayar[i]=(qty[i]*h_buku[i]) - (qty[i]*diskon[i]); 
                    }
                    else 
                    {
                         h_buku[i]=2000;             
                         diskon[i]=0;
                         bayar[i]=(qty[i]*h_buku[i]) - (qty[i]*diskon[i]); 
                    }
                    puts("_________________________________________________________");             
     
     i++;
     }while(i<=jmlbuku);
}

//deklarasi fungsi keluara
void keluaran(void)
{
     printf("\n");
     puts("HASIL");    
     puts("____________________________________________________________________________");    
     printf("Nama peminjam  : %s \n",nami);    
     puts("____________________________________________________________________________");    
    
     //perulangan untuk menampilkan table
     for (j=0;j<=6;j++)
     {        
     printf(" %s |",ket[j]);
     }
     puts(" ");
     puts("_____________________________________________________________________________");
     //perulangan untuk menampilkan no
     for (x=1;x<=jmlbuku;x++)
     {
         printf("\n %d  | %-7s | %-10s | %-8d | %-8d | %-9d | %-12d |",x,kode[x],dafbuku[x],qty[x],qty[x]*h_buku[x],qty[x]*diskon[x],bayar[x]);
         jml+=bayar[x];
     }
     puts(" ");
     puts("_____________________________________________________________________________");
     printf("                                                 total bayar = %d",jml);   
}
     
main()
{

      //panggil fungsi masukan dan keluaran
      masukan();
      keluaran();
     
getch();      
}
