#include <stdio.h>
#include <stdlib.h>
FILE *data;
FILE *data2;
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
    printf("svp entrer le nom: "); gets(currentPerson.nom);
    printf("svp entrer le prenom: "); gets(currentPerson.prenom);
    printf("svp entrer le adress: "); gets(currentPerson.adress);
    printf("svp entrer le tel: "); gets(currentPerson.tel);
    printf("svp entrer le mobile: "); gets(currentPerson.mobile);
    printf("svp entrer le email: "); gets(currentPerson.email);
    fprintf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    fclose(data);
    printf("================================\n");
}
void aficher(){
    data = fopen("CarnetAdress.txt","r");
    if(data == NULL){printf("File doesn't exist");return 0;};
    printf("Nom     Prenom   Adress Tel  Mobile  email\n\n");
    while(!feof(data)){
    fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    printf("%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    }
    fclose(data);
}
void search(){
    int found = 0; //if the name was found this will turn to 1
    data = fopen("carnetAdress.txt","r");
    if(data == NULL){printf("File doesn't exist");}
    printf("Enter the name you want to find : ");
    char userSearch[100];
    gets(userSearch);
    while(!feof(data)){
    fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    if(strcmp(userSearch,currentPerson.nom) == 0){
    found++;
    printf("%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    }
    }
    if(found == 0){printf("Name not found.");}
    fclose(data);
}
void edit(){
    data = fopen("CarnetAdress.txt","r");
    data2 = fopen("carnet2.alt","w");
    char  userSearch[100];
    printf("Entrer le nom aue vous rechercher:");
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
    }
    else{
    fprintf(data2,"%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);

    }
    }
    fclose(data2);
    fclose(data);
    // the new data is in a permanent file
    data = fopen("carnetAdress.txt","w");
    data2 = fopen("carnet2.alt","r");
    while(!feof(data2)){
        fscanf(data2,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
        fprintf(data,"%s   %s   %s   %s   %s    %s\n\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    }
    fclose(data);
    fclose(data2);
    data2 = fopen("carnet2.alt","w");
    fprintf(data2," ");
    fclose(data2);
}
void supr(){
    int check = 0;
    data = fopen("CarnetAdress.txt","r");
    data2 = fopen("carnet2.txt","w");
    char  userSearch[100];
    printf("Entrer le nom aue vous suprrumer:");
    scanf("%s",&userSearch);
    do{
        fscanf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);

        if(strcmp(currentPerson.nom,userSearch) != 0){
        fprintf(data2,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
        }
}
while(!feof(data));
    fclose(data);
    fclose(data2);

    data = fopen("carnetAdress.txt","w");
    data2 = fopen("carnet2.txt","r");
    do{
        fscanf(data2,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
        fprintf(data,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
    }
    while(!feof(data2));
    fclose(data2);
    fclose(data);
}
void test(){
data2 = fopen("carnet2.txt","r");
if(data2 == NULL){printf("NULL");};
        fscanf(data2,"%s  %s  %s  %s  %s  %s\n",currentPerson.nom,currentPerson.prenom,currentPerson.adress,currentPerson.tel,currentPerson.mobile,currentPerson.email);
        printf("hi%slo",currentPerson.nom);
fclose(data2);
}
int main()
{
    while (1){
    char no[1];
    system("cls");
    int choix;
    printf("Welcom to your Notebook , please enter one of the numbers to choose an action:\n\n");
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
    supr();
    printf("\n");
    break;
    default:
    printf("This command does not exist");
    break;
    }
    printf("\nPress 1 to go back to the main menu\n");
    scanf("%d",&choix);
    while(choix != 1){printf("\nPress 1 to go back to the main menu\n");scanf("%d",&choix);}
    }
    return 0;
}
