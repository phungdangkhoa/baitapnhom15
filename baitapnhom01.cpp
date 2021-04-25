#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee_st{
	char  name[30];
	char  province[30];
	int   year;
	float luong;
	float Giolamviec;
	float Luongtrongmotgio;
	float Giokhonglamviec;
	float Luongbitru;
};
void Nhap(employee_st &e){
	printf("Nhap ten cua nhan vien : ");
	fflush(stdin);
	gets(e.name);
	printf("Nhap tinh : ");
	gets(e.province);
	//fflush(stdin);
	printf("Nhap nam sinh : ");
	scanf("%d",&e.year);
	//fflush(stdin);
	printf("Nhap so gio lam viec: ");
	scanf("%f",&e.Giolamviec);
	printf("Nhap luong duoc tra trong mot gio: ");
	scanf("%f",&e.Luongtrongmotgio);
	printf("Nhap so gio khong lam viec: ");
	scanf("%f",&e.Giokhonglamviec);
	printf("Nhap luong bi tru trong mot gio: ");
	scanf("%f",&e.Luongbitru);
	e.luong= e.Giolamviec*e.Luongtrongmotgio - e.Giokhonglamviec*e.Luongbitru;
}
void NhapDS(employee_st a[], int &n){
	for (int i=0;i<n;i++){
		printf("nhap nhan vien thu %d:\n",i);
		Nhap(a[i]);
	}
}
void Sapxeptinh(employee_st a[], int n){
	employee_st l;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(a[i].province,a[j].province)<0){
				l=a[i];
				a[i]=a[j];
				a[j]=l;
			}
		}
	}
	printf("\n name   \tprovincne        \tyear     \tluong ");
	for(int i=0;i<n;i++){
		printf("\n%s      \t%s       \t%2d      \t%.2f", a[i].name,a[i].province,a[i].year,a[i].luong);
	}
}
void Xuat(employee_st e){
	printf("Name %3s\n",e.name);
	printf("Province %10s\n",e.province );
	printf("Year %15d\n",e.year);
	printf("Luong %.2f\n",e.luong);
}
void XuatDS(employee_st a[],int n){
	for(int i=0;i<n;i++){
		Xuat(a[i]);
	}
}

void themnv(employee_st a[], employee_st x,int k,int n){
for(int i=n;i>k;i--){
    a[i]=a[i-1];
}
a[k]=x;
n++;
printf("\nDanh sach nhan vien sau khi them \n");
XuatDS(a,n);
}
void Xoanv(employee_st a[],int h,int n ){


	for(int i=0;i<n;i++)
		a[h]=a[h+1];
		n=n-1;
		printf("Danh sach nhan vien sau khi xoa mot nhan vien \n");
    XuatDS(a,n);
}
void timtheoten(employee_st a[],int n, char ten[]){
	int dem=0;
	for(int i=0;i<n;i++){
		if(strcmp(ten,a[i].name)==0){
	        printf("\n name   \tprovincne        \tyear     \tluong ");
	     	printf("\n%s      \t%s       \t%2d      \t%.2f", a[i].name,a[i].province,a[i].year,a[i].luong);
	     	dem++;
		}
	}
	if(dem==0)
		printf("Khong co nhan vien %s trong danh sach!\n", ten);
}
void ghifile(employee_st a[], int n, char fName[]){
	FILE *fOut;
	fOut = fopen(fName,"w");
	fprintf(fOut,"%-10s%-20s%-10s%-10s\n", "Ten", "Tinh", "Nam sinh", "Luong");
	for(int i=0;i<n;i++){
		fprintf(fOut,"%-10s%-20s%-10d%-10.2f\n",a[i].name,a[i].province,a[i].year,a[i].luong);
	}
	fclose(fOut);
}
void Menu(){
	char fName[] = "program.txt";
	int chon, key=1;
	int k,h;
	employee_st x;
		while(key){
			printf("*******************************MENU*****************************************\n");
			printf("**             1. Nhap danh sach nhan vien                                ** \n");
			printf("**             2. Xuat danh sach nhan vien                                ** \n");
			printf("**             3. Sap xep danh sach nhan vien theo tinh (Z->A).           ** \n");
			printf("**             4. Them vao mot han vien                                   ** \n");
			printf("**             5. Xoa mot nhan vien                                       ** \n");
			printf("**             6. Tim kiem nhan vien theo ten                             ** \n");
			printf("**             7. Ghi file vao tep                                        ** \n");
			printf("**             8. Thoat .                                                 ** \n");
			printf("****************************************************************************\n");
			printf("Moi ban chon chuc nang: ");
			scanf("%d", &chon);
			switch(chon){
				case 1: 
					struct  employee_st   employeeList[10];
					int n;
					printf ("Nhap n: ");
					scanf ("%d", &n);
					NhapDS(employeeList,n);
					break;
				case 2:
					printf("\nThong tin nhan vien da nhap vao la: \n");
					XuatDS(employeeList,n);
					break;
				case 3:
					Sapxeptinh(employeeList,n);
					break;
				case 4:
					printf("\n \t vi tri them: ");
					scanf("%d",&k);
					Nhap(x);
					themnv(employeeList,x,k,n);
					break;				
				case 5:
					printf("\nnhap vi tri van xoa: ");
	            	scanf("%d",&h);
					Xoanv(employeeList,h,n);
					break;
				case 6:
					char ten[30];
					fflush(stdin);
					printf("\nNhap ten can tim la :");
					gets(ten);
					timtheoten(employeeList, n, ten);
					break;
				case 7:
					ghifile(employeeList, n, fName);
					printf("\nBan da xuat file thanh cong vao %s!", fName);
				case 0:
				key=0;	
				
			}
		}
	}	
	
int main (){
	Menu();
}

