#include "common.h"
#include "menu.h"
#include "hoa_don.h"

void hien_thi_menu_chinh(void) {
    printf("\n");
    printf("************************************************************\n");
    printf("*      QUAN LY BAN HANG - QUAN MI CAY UPTOmyCAY           *\n");
    printf("************************************************************\n");
    printf("*  1. Dat mon / Tao hoa don moi                           *\n");
    printf("*  2. Xem tat ca hoa don                                  *\n");
    printf("*  3. In hoa don ra file (.txt)                           *\n");
    printf("*  4. Xoa hoa don                                         *\n");
    printf("*  0. Thoat                                               *\n");
    printf("************************************************************\n");
    printf("Chon chuc nang: ");
}

int main(void) {
    int lua_chon, so_hd;

    khoi_tao_menu();
    printf("\n  Chao mung den voi Quan Mi Cay UpTomyCay!\n");

    do {
        hien_thi_menu_chinh();

        if (scanf("%d", &lua_chon) != 1) {
            while (getchar() != '\n');
            lua_chon = -1;
        }

        switch (lua_chon) {
        case 1:
            tao_hoa_don();
            break;
        case 2:
            printf("\n--- XEM TAT CA HOA DON ---\n");
            in_tat_ca_hoa_don();
            break;
        case 3:
            if (so_hoa_don == 0) { printf("\nChua co hoa don nao!\n"); break; }
            printf("Nhap so hoa don muon in ra file (1 - %d): ", so_hoa_don);
            if (scanf("%d", &so_hd) == 1)
                xuat_hoa_don_ra_file(so_hd);
            break;
        case 4:
            xoa_hoa_don();
            break;
        case 0:
            printf("\nCam on da su dung chuong trinh. Tam biet!\n\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }

    } while (lua_chon != 0);

    return 0;
}
