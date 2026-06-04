#include "menu.h"

void khoi_tao_menu(void) {
     menu[0].stt = 1; strcpy(menu[0].ten, "Mi Kim Chi Thap Cam");   
                                                                    menu[0].don_gia = 65000; //1
     menu[1].stt = 2; strcpy(menu[1].ten, "Mi Kim Chi Dui Ga");     
                                                                    menu[1].don_gia = 55000;   //2
     menu[2].stt = 3; strcpy(menu[2].ten, "Mi Kim Chi Bo");         
                                                                    menu[2].don_gia = 55000; //3
     menu[3].stt = 4; strcpy(menu[3].ten, "Mi Kim Chi Bach Tuoc");  
                                                                    menu[3].don_gia = 55000; // 4
     menu[4].stt = 5; strcpy(menu[4].ten, "Mi Kim Chi Xuc Xich");    
                                                                    menu[4].don_gia = 45000;//5
     menu[5].stt = 6; strcpy(menu[5].ten, "Mi Kim Chi Hai San");    
                                                                    menu[5].don_gia = 55000; //6
}

void hien_thi_menu(void) {
    int i;
    printf("\n");
    printf("============================================================\n");
    printf("        QUAN MI CAY UPTOmyCAY - THUC DON                   \n");
    printf("============================================================\n");
    printf("  STT  %-35s  DON GIA\n", "TEN MON");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < MAX_MON; i++) {
        printf("  %d.   %-35s  %.0f VND\n",menu[i].stt, menu[i].ten, menu[i].don_gia);
    }
    printf("============================================================\n");
    printf("  Cap do (1->7) \n");
    printf("  Nhap 0 de ket thuc dat mon\n");
    printf("============================================================\n");
}
