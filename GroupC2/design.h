void SetColor(int ForgC){

     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;


}

int GetFontSize(HANDLE windowHandle, COORD *size){

    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }

    *size = font.dwFontSize;

    return 1;
    }

int SetFontSize(HANDLE windowHandle, COORD size){

    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font)){
        return 0;
        }

    font.dwFontSize = size;

    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font)){
        return 0;
        }

    return 1;
}





void loading(){

    SetColor(9);
    printf("\n\n\t\t\t\t\t\t\tLoading.....\n");
    printf("\t\t\t\t\t\t  ");

    for(int i=0; i<=20; i++){
        SetColor(9);
        Sleep(50);
        printf("%c",219);
        SetColor(9);
    }
    printf("\n\n\n\t\t\t\t       ");
    system("pause");
}

void header(char head[50]){
    SetColor(5);
    //printf("\n\n\t\t\t\t----------------------------------------------------------");SetColor(5);
      printf("\n\n\t\t\t\t                               \n");

    if(strlen(head)>=14){
        printf("\n\n");
        printf("\n\t\t\t\t\t\t      %s            \t\t",head);
    }
    else{
        printf("\n\t\t\t\t\t\t      %s           \t\t\t",head);
    }
    SetColor(5);
    //printf("\n\t\t\t\t----------------------------------------------------------\n");SetColor(5);
      printf("\n\n\t\t\t\t                               \n");

}

int choice(char option[20][50],char head[50],int m){
    int n=1;
    int ch1, ch2,j;
    SetColor(3);
    //printf("\n\n\t\t\t\t----------------------------------------------------------");SetColor(3);
    printf("\n\n\t\t\t\t                                \n");
    if(strlen(head)>14){
        printf("\n\n");
        printf("\n\t\t\t\t\t        %s             \t\t",head);
    }
    else{
        printf("\n\t\t\t\t\t\t      %s           \t\t\t",head);
    }
    SetColor(3);
    //printf("\n\t\t\t\t----------------------------------------------------------\n");SetColor(3);
      printf("\n\n\t\t\t\t                               \n");

    SetColor(3);
    printf("\n\t\t\t\t   -->\t\t%s",option[0]);SetColor(3);

    for( j=1;j<m ;j++ ){
        printf("\n\t\t\t\t\t\t%s",option[j]);
    }
    SetColor(2);
    printf("\n\n\n\t\t\t\tREMARK:");
    SetColor(2);
    printf(" USE  \"UP\" AND \"DOWN\" TO SCROLL.\n\t\t\t\t\tUSE  \"ENTER\"  TO CHOOSE THE OPTION");
    while(1){

        ch1 = getch();
        ch2 = 0;
        if( ch1 == 13){
            return n;
            break;
        }
        else if (ch1 == 0xE0) {    // a scroll key was pressed
            ch2 = getch();          // determine what it was
            system("cls");

            switch(ch2){
            case 80:     //DOWN
                if( n==m ){
                    SetColor(3);
                   // printf("\n\n\t\t\t\t---------------------------------------------------------");
                     printf("\n\n\t\t\t\t                               \n");
                    if(strlen(head)>14){
                        printf("\n\t\t\t\t\t        %s        \t\t",head);
                    }
                    else{
                        printf("\n\t\t\t\t\t\t      %s      \t\t\t",head);
                    }
                   // printf("\n\t\t\t\t----------------------------------------------------------\n");SetColor(3);
                      printf("\n\n\t\t\t\t                               \n");

                    for( j=0;j<m-1;j++ ){
                        printf("\n\t\t\t\t\t\t%s",option[j]);
                    }
                    SetColor(3);
                    printf("\n\t\t\t\t   -->\t\t%s",option[m-1]);SetColor(3);//SetColor(0);
                    break;
                }
                else{
                    n+=1;
                    SetColor(3);
                    //printf("\n\n\t\t\t\t----------------------------------------------------------");
                      printf("\n\n\t\t\t\t                               \n");
                    if(strlen(head)>14){
                        printf("\n\t\t\t\t\t       %s          \t\t",head);
                    }
                    else{
                        printf("\n\t\t\t\t\t\t      %s       \t\t\t",head);
                    }
                    //printf("\n\t\t\t\t-----------------------------------------------------------\n");SetColor(3);
                      printf("\n\n\t\t\t\t                               \n");

                    for(j=0;j<m;j++){
                        if( j!= n-1 ){
                            printf("\n\t\t\t\t\t\t%s",option[j]);
                        }
                        else{
                            SetColor(3);
                            printf("\n\t\t\t\t   -->\t\t%s",option[j]);SetColor(3);
                        }
                    }
                    break;
                }
            case 72:    //UP
                if(n==1){
                    SetColor(3);
                  //  printf("\n\n\t\t\t\t-----------------------------------------------------------");
                      printf("\n\n\t\t\t\t                               \n");
                    if(strlen(head)>14){
                        printf("\n\n");
                        printf("\n\t\t\t\t\t        %s          \t\t",head);
                    }
                    else{
                        printf("\n\t\t\t\t\t\t      %s        \t\t\t",head);
                    }
                    SetColor(3);
                    //printf("\n\t\t\t\t-----------------------------------------------------------\n");SetColor(3);
                      printf("\n\n\t\t\t\t                               \n");

                    SetColor(3);
                    printf("\n\t\t\t\t   -->\t\t%s",option[0]);SetColor(3);
                    for( j=1;j<m;j++ ){
                        printf("\n\t\t\t\t\t\t%s",option[j]);
                    }
                    break;
                }
                else{
                    n-=1;
                    SetColor(3);
                    //printf("\n\n\t\t\t\t-----------------------------------------------------------");SetColor(3);
                      printf("\n\n\t\t\t\t                               \n");
                    if(strlen(head)>14){
                        printf("\n\n");
                        printf("\n\t\t\t\t\t        %s          \t\t",head);
                    }
                    else{
                        printf("\n\t\t\t\t\t\t      %s        \t\t\t",head);
                    }
                    SetColor(3);
                    //printf("\n\t\t\t\t-----------------------------------------------------------\n");SetColor(3);
                      printf("\n\n\t\t\t\t                               \n");

                    for(j=0;j<m;j++){
                        if( j!= n-1 ){
                            printf("\n\t\t\t\t\t\t%s",option[j]);
                        }
                        else{
                            SetColor(3);
                            printf("\n\t\t\t\t   -->\t\t%s",option[j]);SetColor(3);
                        }
                    }
                    break;
                }
            }
        }
    }
}

void Ascii_Art(){

    //Loop for print first layer
    SetColor(1);
    printf("\n\n\n\t\t\t");
    printf(" ******    ***      *****   *****   *****   *****  *****    ***    **  **  \n");
    Sleep(5);
    printf("\n\n\n\t\t\t");
    printf(" _____    ___      _____   _____   _____   _____   _____    ___    __  __  \n");
    Sleep(100);
    //Loop will print second layer
    printf("\t\t\t");
    printf("|  ___|  / _ \\    | ___ \\ | ___ \\ |  _  | |  __ \\ | ___ \\  / _ \\  |  \\/  | \n");
    Sleep(100);
    //Loop will print third layer
    printf("\t\t\t");
    printf("| |_    / /_\\ \\   | |_/ / | |_/ / | | | | | |  \\/ | |_/ / / /_\\ \\ | .  . | \n");
    Sleep(100);
    //Loop will print fourth layer
    printf("\t\t\t");
    printf("|  _|   |  _  |   |  __/  |    /  | | | | | | __  |    /  |  _  | | |\\/| | \n");
    Sleep(100);
    //loop will print fifth layer
    printf("\t\t\t");
    printf("| |     | | | |   | |     | |\\ \\  \\ \\_/ / | |_\\ \\ | |\\ \\  | | | | | |  | | \n");
    Sleep(100);
    //Loop will print sixth layer
    printf("\t\t\t");
    printf("\\_|     \\_| |_/   \\_|     \\_| \\_|  \\___/   \\____/ \\_| \\_| \\_| |_/ \\_|  |_/ \n\n");
    printf("\n\n\n\t\t\t");
    printf(" ******    ***      *****   *****   *****   *****  *****    ***    **  **  \n");
    Sleep(100);
    SetColor(5);
}

//void displayHeader(){
//
//     SetColor(7);
//     Sleep(50);
//     printf("\n\n\n\n\n\t\t\t\t\t\t\t\t");
//     printf("\n\n--------------------\n");
//     printf("\n=======FA PROGRAM=======");
//     printf("\n\n--------------------\n");
//     printf("\n\n\n\n\n\t\t\t\t\t\t\t\t");
//     Sleep(50);
//     SetColor(7);
//
//}
