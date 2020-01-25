#include<stdio.h>
#include<stdlib.h>

struct 
{
	float total_amount;
	float amount;
	float sub_total;
	float discount_amount;
	float tax_amount;
	float quantity;
	float value;
	float discount;
	float tax; 
}product;

FILE *productlist;
main()
{
password();
printf("\n\n\n\t\t\t\t\t   GOODS AND SALES CALCULATOR");
int choice=0,i;	
do
{
    printf("\n\nPRESS 1 TO ENTER THE PRODUCTS\nPRESS 2 TO PRINT THE BILL\nPRESS 0 TO EXIT\nYOUR CHOICE\t");
    scanf("%i",&choice);
    switch (choice)
    {    
        case 0:
            Exit(); 
            break;
        case 1:
            EnterProduct();
            break;
        case 2:
        	PrintBill();
        	break;
        default:
            printf("Invalid Input!\n");
    }
}while(choice!=0);
 return (0);
}
int EnterProduct()
{
  productlist=fopen("ProductList.doc","a+"); 
  printf("\nEnter the specifications of the product");
  printf("\nEnter the quantity of item sold: ");
  scanf ("%f", &product.quantity);
  printf("\nEnter the value of item: "); 
  scanf("%f", &product.value); 
  printf("\nEnter the discount percentage: "); 
  scanf("%f", &product.discount); 
  printf (" \nGST(%%): ") ; 
  scanf ("%f", &product.tax) ; 
  product.amount = product.quantity * product.value; 
  product.discount_amount = (product.amount* product.discount)/100.0; 
  product.sub_total =product.amount - product.discount_amount; 
  product.tax_amount= (product.sub_total*product.tax) /100.0; 
  product.total_amount =product.sub_total+ product.tax_amount;
  fprintf(productlist,"\n%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",product.quantity,product.value,product.discount,product.tax,product.amount,product.discount,product.sub_total,product.tax_amount,product.total_amount);
  fclose(productlist);
  printf("The product information had been added successfully"); 
}
int PrintBill()
{
float sum=0;
printf (" \n\n\n--------------------------------------------------BILL----------------------------------------------------------") ; 
printf("\nQuantitySold\tPrice per item\t  Amount\t Discount(%%)\tDiscounted Total       GST(%%)\t Total Amount");
if((productlist=fopen("ProductList.doc","r"))==NULL)
        printf("\nThe File is Empty!!\n\n");
else
{
  while(!feof(productlist))
  {
  fscanf(productlist,"%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",&product.quantity,&product.value,&product.discount,&product.tax,&product.amount,&product.discount,&product.sub_total,&product.tax_amount,&product.total_amount);
  printf("\n %.2f     \t   %.2f \t  %.2f  \t   %.2f       \t     %.2f\t       %.2f\t    %.2f",product.quantity,product.value,product.amount,product.discount,product.sub_total,product.tax,product.total_amount);
  sum=sum+product.total_amount;
  }
  printf("\n----------------------------------------------------------------------------------------------------------------");
  printf("\nTOTAL\t\t\t\t\t\t%f",sum);
  printf("\n----------------------------------------------------------------------------------------------------------------");
  getch();
}
}
int password()
{
char d[25]="PASSWORD PROTECTED";
char ch,pass[10],password[10]="Ankit";
int i=0,j;
printf("\t\t\t  ");
for(j=0;j<20;j++)
    {
    printf("*");
    }
for(j=0;j<18;j++)
   {
   printf("%c",d[j]);
   }
for(j=0;j<20;j++)
   {
   printf("*");
   }
printf("\n\n\n\t\t\t\t\t\tEnter Password:\n\t\t\t\t\t\t    ");
while(ch!=13)
   {
	ch=getch();
	if(ch!=13)
	{
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {
	printf("\n\n\t\t\t\t\t\tPassword match");
	printf("\n\t\t\t\t\tPress any key to countinue.....");
	getch();
   }
   else
   {
	 printf("\n\t\t\tWarning!Incorrect Password!");
	 exit(0);
   }
}
int Exit()
{
  exit(0);
}
