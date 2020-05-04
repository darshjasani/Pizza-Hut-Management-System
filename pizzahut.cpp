#include<stdio.h>
#include<string.h>
void DisplayOrder(struct PizzaTypes pizzaCart[100],struct PizzaCost costOnSize[12],char itemNames[12][100],int sidesCost[4]);
struct PizzaTypes{
 int smallQuantity,mediumQuantity,largeQuantity,others,freshPan,cheeseBurst,wheatThinCrust;
};
struct PizzaCost{
 int smallCost,mediumCost,largeCost,freshPanCost,cheeseBurstCost,wheatThinCrustCost;
};
main()
{
 int i=0,c=1,j=0,mainChoice,cost[24]={99,195,395,155,295,445,155,295,445,195,365,545,155,295,445,225,425,635,235,455,685,235,455,685},totalCost=0,a[10];
 char name[20];
 char itemNames[12][100]={
  "Margherita(Veg)",
  "Spicy Triple Tango(Veg)",
  "Double Cheese Margherita(Veg)",
  "Farm House(Veg)",
  "Cheese and Barbeque Chicken(Non Veg)",
  "Chicken Fiesta(Non Veg)",
  "Chicken Mexican(Non Veg)",
  "Chicken Golden Delight(Non Veg)",
  "Zingy Parcel Veg",
  "Zingy Parcel Non Veg",
  "Taco Mexicana Veg",
  "Taco Mexicana Non Veg"
 };
 int sidesCost[4]={29,35,119,129};
// int zingyParcelVeg=29,zingyParcelNonVeg=35,tacoMexicanaVeg=119,tacoMexicanaNonVeg=129;
 struct PizzaTypes pizzaCart[100];
 struct PizzaCost costOnSize[12];
 for(i=0;i<12;i++)
 {
  pizzaCart[i].smallQuantity=0;
  pizzaCart[i].mediumQuantity=0;
  pizzaCart[i].largeQuantity=0;
  pizzaCart[i].freshPan=0;
  pizzaCart[i].wheatThinCrust=0;
  pizzaCart[i].cheeseBurst=0;
  pizzaCart[i].others=0;

 }
 i=0;
 while(i<24)
 {
  costOnSize[j].smallCost=cost[i++];
  costOnSize[j].mediumCost=cost[i++];
  costOnSize[j].largeCost=cost[i++];
  costOnSize[j].freshPanCost=30;
  costOnSize[j].cheeseBurstCost=95;
  costOnSize[j].wheatThinCrustCost=40;
  j++;
 }
 do{
  if(c==1){
   printf("Enter\n1 - Veg Pizzas\n2 - Chicken Pizzas\n3 - Sides\n4 - Exit\n");
         scanf("%d",&mainChoice);
   switch(mainChoice)
   {
    case 1:
    {
     int subChoice;
     printf("Enter\n1 - Margherita\n2 - Spicy Triple Tango\n3 - Double Cheese Margherita\n4 - Farm House\n5 - Exit\n");
     scanf("%d",&subChoice);
     if(subChoice!=5){
      int sizeChoice;
              printf("Enter\n1 - Small\n2 - Medium\n3 - Large\n");
              scanf("%d",&sizeChoice);
      if(sizeChoice==1)
       pizzaCart[subChoice-1].smallQuantity++;
      if(sizeChoice==2)
                   pizzaCart[subChoice-1].mediumQuantity++;
         if(sizeChoice==3)
       pizzaCart[subChoice-1].largeQuantity++;
      printf("Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat thin Crust\n4 - No Need\n");
      int extraCrust;
      scanf("%d",&extraCrust);
      if(extraCrust==1)
      pizzaCart[subChoice-1].freshPan++;
      else if(extraCrust==2)
      pizzaCart[subChoice-1].cheeseBurst++;
      else if(extraCrust==3)
      pizzaCart[subChoice-1].wheatThinCrust++;

      if(subChoice!=5)
      printf("Pizza Added to Cart Successfully\n");
     }

     break;
     }
    case 2:
    {
     int subChoice;
     printf("Enter\n1 - Cheese and Barbeque Chicken\n2 - Chicken Fiesta\n3 - Chicken Mexican\n4 - Chicken Golden Delight\n5 - Exit\n");
     scanf("%d",&subChoice);
     if(subChoice!=5){
      int sizeChoice;
              printf("Enter\n1 - Small\n2 - Medium\n3 - Large\n");
              scanf("%d",&sizeChoice);
      if(sizeChoice==1)
       pizzaCart[subChoice+4-1].smallQuantity++;
      if(sizeChoice==2)
                   pizzaCart[subChoice+4-1].mediumQuantity++;
         if(sizeChoice==3)
       pizzaCart[subChoice+4-1].largeQuantity++;
      printf("Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat thin Crust\n4 - No Need\n");
      int extraCrust;
      scanf("%d",&extraCrust);
      if(extraCrust==1)
      pizzaCart[subChoice+4-1].freshPan++;
      else if(extraCrust==2)
      pizzaCart[subChoice+4-1].cheeseBurst++;
      else if(extraCrust==3)
      pizzaCart[subChoice+4-1].wheatThinCrust++;
      if(subChoice!=5)
      printf("Pizza Added to Cart Successfully\n");
     }

     break;
    }
    case 3:
    {
     int subChoice;
     printf("Enter\n1 - Zingy Parcel Veg\n2 - Zingy Parcel Non Veg\n3 - Taco Mexican Veg\n4 - Taco Mexican Non Veg\n5 - Exit\n");
     scanf("%d",&subChoice);
     if(subChoice<5 && subChoice>0)
         pizzaCart[subChoice+8-1].others++;
        if(subChoice!=5)
      printf("Added to Cart Successfully\n");
     break;
     }
     default:
     {
      printf("Invalid Choice\n");
      break;
     }
     }
  }
  if(c==2)
  {
   int id,quantityPizza,quantityCrust,quantity,wrongIdFlag=1;
   printf("Enter Id to change Quantity\n");
   scanf("%d",&id);
   if(id>=0 && id<=11)
   {
    if(id>=0&&id<=7)
    {
     if(pizzaCart[i].smallQuantity>0||pizzaCart[i].mediumQuantity>0||pizzaCart[i].largeQuantity||pizzaCart[i].others>0||pizzaCart[i].freshPan>0||pizzaCart[i].cheeseBurst||pizzaCart[i].wheatThinCrust>0){
      printf("Enter\n1 - To Change Small Pizza Quantity\n2 -Change Quantity for Medium Pizza\n3 -Change Quantity for Large Pizza\n4 -Change Quantity for Crust\n5 - Exit\n");
      scanf("%d",&quantityPizza);
      printf("Enter quantity to change and to delete Enter 0\n");
      scanf("%d",&quantity);
      if(quantity>=0){
          if(quantityPizza==1)
          pizzaCart[id].smallQuantity=quantity;
          if(quantityPizza==2)
          pizzaCart[id].mediumQuantity=quantity;
          if(quantityPizza==3)
          pizzaCart[id].largeQuantity=quantity;
          if(quantityPizza==4)
          {
           printf("Enter\n1 - To Change Fresh Pan\n2 - Cheese Burst\n3 - Wheat Thin Crust\n4 - Exit\n");
           scanf("%d",&quantityCrust);
           if(quantityCrust==1)
           pizzaCart[id].freshPan=quantity;
           if(quantityCrust==2)
           pizzaCart[id].cheeseBurst=quantity;
           if(quantityCrust==3)
           pizzaCart[id].wheatThinCrust=quantity;
          }
      }
      else{
       printf("Enter Quantity greater than or equal to zero\n");
      }
     }
     else{
      printf("Id Not Found\n");
      wrongIdFlag=0;
     }
    }
    else{
     printf("Enter\n1 - To Change Quantity of Zingy Parcel(Veg)\n2 - To Change Quantity of Zingy Parcel(Non Veg)\n3 - To Change Quantity of Taco Mexicana(Veg)\n4 - To Change Quantity of Taco Mexicana(Non Veg)\n5 - To Change Quantity of  - Exit\n");
     scanf("%d",&quantityPizza);
     if(quantityPizza>=1 && quantityPizza<=4)
     {
      printf("Enter quantity\n");
      scanf("%d",&quantity);
      pizzaCart[id].others=quantity;
     }

    }
    if(wrongIdFlag==1)
    {
                   printf("Quantity Changed Successfully\nRearranged Order is\n");
                   DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
    }

   }
   else{
    printf("Please Enter Valid Id\n");
   }
  }
  if(c==4)
  {
   int id;
   printf("Enter Id to delete from Cart\n");
   scanf("%d",&id);
   pizzaCart[id].smallQuantity=0;
   pizzaCart[id].mediumQuantity=0;
   pizzaCart[id].largeQuantity=0;
   pizzaCart[id].others=0;
   pizzaCart[id].freshPan=0;
   pizzaCart[id].cheeseBurst=0;
   pizzaCart[id].wheatThinCrust=0;
    printf("Item Deleted Successfully\nRearranged Order is\n");
     DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
  }
  if(c==3)
  {
   DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
  }

      printf("Enter\n1 - Add Item\n2 - Change Quantity\n3 - View Cart\n4 - Delete from Cart\n Else any number to Calculate Cost\n");
      scanf("%d",&c);
 }while(c==1 || c==2 || c==3 || c==4);
 printf("Final Order \n");
DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
printf("Thanks for Shopping with us\n");
}

void DisplayOrder(struct PizzaTypes pizzaCart[100],struct PizzaCost costOnSize[12],char itemNames[12][100],int sidesCost[4])
{
 int totalCost=0,i;
 printf("---------------------List in Cart-------------------------\n");
 for(i=0;i<11;i++)
 {
  if(pizzaCart[i].smallQuantity>0||pizzaCart[i].mediumQuantity>0||pizzaCart[i].largeQuantity||pizzaCart[i].others>0||pizzaCart[i].freshPan>0||pizzaCart[i].cheeseBurst||pizzaCart[i].wheatThinCrust>0)
  {
   if(i>=0&&i<=7){
   printf("Id : %d\n",i);
      printf("Item Name : %s\n",itemNames[i]);
   if(pizzaCart[i].smallQuantity>0)
   printf("Small Size Quantity: %d -> Cost : %d\n",pizzaCart[i].smallQuantity,costOnSize[i].smallCost*pizzaCart[i].smallQuantity);
   if(pizzaCart[i].mediumQuantity>0)
   printf("Medium Size Quantity: %d -> Cost : %d\n",pizzaCart[i].mediumQuantity,costOnSize[i].mediumCost*pizzaCart[i].mediumQuantity);
   if(pizzaCart[i].largeQuantity>0)
   printf("Large Size Quantity: %d -> Cost : %d\n",pizzaCart[i].largeQuantity,costOnSize[i].largeCost*pizzaCart[i].largeQuantity);
   if(pizzaCart[i].freshPan>0)
   printf("Fresh Pan Quantity: %d -> Cost : %d\n",pizzaCart[i].freshPan,costOnSize[i].freshPanCost*pizzaCart[i].freshPan);
   if(pizzaCart[i].wheatThinCrust>0)
   printf("Wheat Thin Crust Quantity: %d -> Cost : %d\n",pizzaCart[i].wheatThinCrust,costOnSize[i].wheatThinCrustCost*pizzaCart[i].wheatThinCrust);
   if(pizzaCart[i].cheeseBurst>0)
   printf("Cheese Burst Quantity: %d -> Cost : %d\n",pizzaCart[i].cheeseBurst,costOnSize[i].cheeseBurstCost*pizzaCart[i].cheeseBurst);
   totalCost+=pizzaCart[i].smallQuantity*costOnSize[i].smallCost;
   totalCost+=pizzaCart[i].mediumQuantity*costOnSize[i].mediumCost;
   totalCost+=pizzaCart[i].largeQuantity*costOnSize[i].largeCost;
   totalCost+=pizzaCart[i].freshPan*costOnSize[i].freshPanCost;
   totalCost+=pizzaCart[i].cheeseBurst*costOnSize[i].cheeseBurstCost;
   totalCost+=pizzaCart[i].wheatThinCrust*costOnSize[i].wheatThinCrustCost;
  }
  else{
   printf("Id : %d\n",i);
   printf("Item Name : %s\n",itemNames[i]);
   printf("Quantity : %d\n",pizzaCart[i].others);
   printf("Cost : %d\n",pizzaCart[i].others*sidesCost[i-8]);
   totalCost+=(pizzaCart[i].others)*sidesCost[i-8];
  }
 }
  }
   printf("-------------------Total Cost : %d-----------------------\n",totalCost);
}
