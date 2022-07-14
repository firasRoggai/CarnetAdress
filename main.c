#include <stdio.h>
#include <stdlib.h>
FILE *d​ata;
FILE *d​ata2;
struct person{
    char nom[100];
    char prenom[100];
    char adress[100];
    char tel[100];
    char mobile[100];
    char email[100];
}currentPerson;
void ajouter(){
    data = fopen("CarnetAdress.txt","a");
    if(data == NULL){printf("File doesn't exist");return 0;};
    printf("svp entrer le nom: ");    gets(currentPerson.nom);
    printf("svp entrer le prenom: "); gets(currentPerson.prenom);
    printf("svp entrer le adress: "); gets(currentPerson.adress);
    printf("svp entrer le tel: ");    gets(currentPerson.tel);
    printf("svp entrer le mobile: "); gets(currentPerson.mobile);
    printf("svp entrer le email: ");  gets(currentPerson.email);
    fprintf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    fclose(data);
    printf("================================\n");
}
void aficher(){
    data = fopen("CarnetAdress.txt","r");
    if(data == NULL){printf("File doesn't exist");return 0;};
    int emptyCheck = 0; //if the variable == 0 then the file has no names in it.
    while(!feof(data)){
    fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    if(strcmp(currentPerson.nom,"") != 0){emptyCheck++;}//if the file is NOT empty , emptycheck++;
    printf("\nNom:          %s   \nPrenom:       %s   \nAdress:       %s   \nTel:          %s   \nNumber:       %s    \nEmail:        %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    printf("=====================================");
    }
    if(emptyCheck == 0){printf("\nThe file is empty");}
    fclose(data);
}
void search(){
    data = fopen("carnetAdress.txt","r");
    if(data == NULL){printf("File doesn't exist");}
    int found = 0; //if the name was found this will turn to 1
    printf("Enter the name you want to find : ");
    char userSearch[100];
    gets(userSearch);
    while(!feof(data)){
    fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    if(strcmp(userSearch,currentPerson.nom) == 0){
    found++;
    printf("\n%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    }
    }
    if(found == 0){printf("\nName not found.");}
    fclose(data);
}
void edit(){
    data = fopen("CarnetAdress.txt","r");
    data2 = fopen("altcarnet.txt","w");
    if(data == NULL){printf("File doesn't exist");}
    int found = 0; // if there is a matching name this will turn to 1;
    char  userSearch[100]; // the name that the user wants to delete.
    printf("Entrez le nom de person que vous souhaitez modifier: ");
    scanf("%s",&userSearch);
    while(!feof(data)){
    fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    if(strcmp(currentPerson.nom,userSearch) == 0){
    printf("Entrer le nauveau nom:");    scanf("%s",currentPerson.nom);
    printf("Entrer le nauveau prenom:"); scanf("%s",currentPerson.prenom);
    printf("Entrer le nauveau adress:"); scanf("%s",currentPerson.adress);
    printf("Entrer le nauveau tel:");    scanf("%s",currentPerson.tel);
    printf("Entrer le nauveau mobile:"); scanf("%s",currentPerson.mobile);
    printf("Entrer le nauveau email:");  scanf("%s",currentPerson.email);
    fprintf(data2,"%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    found++;
    }
    else{
    fprintf(data2,"%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);

    }
    }
    fclose(data2);
    fclose(data);
    if(found == 0){printf("\nName you searched for doesn't exist.");}
    remove("CarnetAdress.txt");
    rename("altcarnet.txt","CarnetAdress.txt");
}
void suprimer(){
    data = fopen("CarnetAdress.txt","r");
    data2 = fopen("altcarnet.txt","w");
    if(data == NULL){printf("File doesn't exist");}
    int check = 0;//if a matching name were found , this will turn to 1.
    char  userSearch[100];
    printf("Entrez le nom que vous souhaitez supprimer:");
    scanf("%s",&userSearch);
    do{
        fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);

        if(strcmp(currentPerson.nom,userSearch) == 0){
            check++;
        }
        else{
        fprintf(data2,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);

}
}
while(!feof(data));
if(check > 0){printf("\nDeletion completed!");}
else{printf("\nThe person you wanted to delete does not exist .");}
fclose(data2);
fclose(data);
if(check == 1){
 data2 = fopen("altcarnet.txt","w");
 fprintf(data2," ");
 fclose(data2);
}
remove("CarnetAdress.txt");
rename("altcarnet.txt","CarnetAdress.txt");
}

int main()
{
     while (1){
    char no[1];
    system("cls");
    int choix;
    printf("Bienvenu dans votre carnet adress.\n");
    printf("\n");
    printf("[1] Ajoute     : ajoute une person dans le carnet\n\n");
    printf("[2] rechercher : rechercher une person dans le carnet\n\n");
    printf("[3] modifier   : modifier une person dans le carnet\n\n");
    printf("[4] Aficher    : aficher les persons dans le carnet\n\n");
    printf("[5] supprimer  : supprimer une person dans le carnet\n\n");
    scanf("%d",&choix);
    switch(choix){
    case 1:
    scanf("%c",&no);
    ajouter();
    printf("\n");
    break;
    case 2:
    scanf("%c",&no);
    search();
    printf("\n");
    break;
    case 3:
    scanf("%c",&no);
    edit();
    printf("\n");
    break;
    case 4:
    aficher();
    printf("\n");
    break;

    case 5:
    scanf("%c",&no);
    suprimer();
    printf("\n");
    break;
    default:
    printf("This command does not exist");
    break;
    }
    printf("\nPress 1 to go back to the main menu\n");
    char exit[10];
    scanf("%s",&exit);
    while(strcmp(exit,"1") != 0){printf("\nPress 1 to go back to the main menu\n");scanf("%s",&exit);}
    }
    return 0;
}

