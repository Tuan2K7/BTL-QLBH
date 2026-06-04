#include "hoa_don.h"
#include "menu.h"

/* ------------------------------------------------------------------ *
 *  TINH % GIAM TU ROBUX                                               *
 *  1-100  Robux -> 1%   |  101-200 -> 2%  | ... | toi da 50%         *
 * ------------------------------------------------------------------ */
static float tinh_giam_robux(int robux) {
    if (robux <= 0)   return 0.0f;
    int phan_tram = (robux - 1) / 100 + 1;   /* moi 100 Robux = 1% */
    if (phan_tram > 50) phan_tram = 50;       /* toi da 50%         */
    return (float)phan_tram;
}

/* ------------------------------------------------------------------ *
 *  TAO HOA DON MOI                                                    *
 * ------------------------------------------------------------------ */
int tao_hoa_don(void) {
    int ma_mon, cap_do, i, tim_thay;
    HoaDon *hd;

    if (so_hoa_don >= MAX_HOA_DON) {
        printf("Da dat toi da so luong hoa don!\n");
        return -1;
    }

    hd = &ds_hoa_don[so_hoa_don];
    hd->so_hd         = so_hoa_don + 1;
    hd->so_item       = 0;
    hd->tong_tien     = 0;
    hd->robux_dung    = 0;
    hd->phan_tram_giam= 0;
    hd->thanh_toan    = 0;

    hien_thi_menu();
    printf("\n--- DAT MON CHO HOA DON #%d ---\n", hd->so_hd);

    while (1) {
        printf("\nNhap so thu tu mon (1-6), nhap 0 de ket thuc: ");
        if (scanf("%d", &ma_mon) != 1) { while(getchar()!='\n'); continue; }
        if (ma_mon == 0) break;
        if (ma_mon < 1 || ma_mon > MAX_MON) { printf("So thu tu khong hop le!\n"); continue; }

        printf("Nhap cap do cay (1-7): ");
        if (scanf("%d", &cap_do) != 1) { while(getchar()!='\n'); continue; }
        if (cap_do < 1 || cap_do > MAX_CAP_DO) { printf("Cap do khong hop le!\n"); continue; }

        tim_thay = 0;
        for (i = 0; i < hd->so_item; i++) {
            if (hd->items[i].ma_mon == ma_mon && hd->items[i].cap_do == cap_do) {
                hd->items[i].so_luong++;
                hd->items[i].thanh_tien = hd->items[i].so_luong * hd->items[i].don_gia;
                printf("  >> Tang so luong: %s Cap %d x%d\n",
                       menu[ma_mon-1].ten, cap_do, hd->items[i].so_luong);
                tim_thay = 1;
                break;
            }
        }

        if (!tim_thay) {
            if (hd->so_item >= MAX_ITEM) { printf("Hoa don da day!\n"); continue; }
            hd->items[hd->so_item].ma_mon     = ma_mon;
            hd->items[hd->so_item].cap_do     = cap_do;
            hd->items[hd->so_item].so_luong   = 1;
            hd->items[hd->so_item].don_gia    = menu[ma_mon-1].don_gia;
            hd->items[hd->so_item].thanh_tien = menu[ma_mon-1].don_gia;
            printf("  >> Da them: %s Cap %d\n", menu[ma_mon-1].ten, cap_do);
            hd->so_item++;
        }
    }

    if (hd->so_item == 0) {
        printf("Khong co mon nao duoc dat. Huy hoa don.\n");
        return -1;
    }

    /* Tinh tong tien goc */
    hd->tong_tien = 0;
    for (i = 0; i < hd->so_item; i++)
        hd->tong_tien += hd->items[i].thanh_tien;

    /* ---- ROBUX ---- */
    printf("\n------------------------------------------------------------\n");
    printf("  Tong tien: %.0f VND\n", hd->tong_tien);
    printf("  Ban co Robux khong? Nhap so Robux (0 = bo qua): ");
    int robux;
    if (scanf("%d", &robux) != 1 || robux < 0) robux = 0;
    while(getchar()!='\n');

    if (robux > 0) {
        float pct = tinh_giam_robux(robux);
        float tien_giam = hd->tong_tien * pct / 100.0f;
        hd->robux_dung     = robux;
        hd->phan_tram_giam = pct;
        hd->thanh_toan     = hd->tong_tien - tien_giam;
        printf("  >> Su dung %d Robux -> Giam %.0f%% (%.0f VND)\n",
               robux, pct, tien_giam);
        printf("  >> Thanh toan: %.0f VND\n", hd->thanh_toan);
    } else {
        hd->robux_dung     = 0;
        hd->phan_tram_giam = 0;
        hd->thanh_toan     = hd->tong_tien;
    }
    printf("------------------------------------------------------------\n");

    so_hoa_don++;
    printf(">> Da luu Hoa Don #%d thanh cong!\n", hd->so_hd);
    return 1;
}

/* ------------------------------------------------------------------ *
 *  IN NOI DUNG HOA DON (dung chung cho stdout & file)                 *
 * ------------------------------------------------------------------ */
void in_noi_dung_hoa_don(FILE *fp, HoaDon *hd) {
    int i, stt = 1;

    fprintf(fp, "============================================================\n");
    fprintf(fp, "        QUAN MI CAY UPTOmyCAY\n");
    fprintf(fp, "        HOA DON #%d\n", hd->so_hd);
    fprintf(fp, "============================================================\n");
    fprintf(fp, "  %-3s  %-28s  %-4s  %-7s  %s\n",
            "STT","Ten san pham","SL","Don Gia","Thanh Tien");
    fprintf(fp, "------------------------------------------------------------\n");

    for (i = 0; i < hd->so_item; i++) {
        char ten_day_du[80];
        sprintf(ten_day_du, "%s Cap %d",
                menu[hd->items[i].ma_mon - 1].ten,
                hd->items[i].cap_do);
        fprintf(fp, "  %-3d  %-28s  %-4d  %7.0f  %9.0f\n",
                stt++, ten_day_du,
                hd->items[i].so_luong,
                hd->items[i].don_gia,
                hd->items[i].thanh_tien);
    }

    fprintf(fp, "------------------------------------------------------------\n");
    fprintf(fp, "  %-37s  %9.0f VND\n", "Tong tien:", hd->tong_tien);

    if (hd->robux_dung > 0) {
        fprintf(fp, "  Robux su dung: %-5d  Giam: %.0f%%  (-%.0f VND)\n",
                hd->robux_dung,
                hd->phan_tram_giam,
                hd->tong_tien * hd->phan_tram_giam / 100.0f);
        fprintf(fp, "  %-37s  %9.0f VND\n", "Thanh toan:", hd->thanh_toan);
    }

    fprintf(fp, "============================================================\n");
    fprintf(fp, "       Cam on quy khach! Hen gap lai.\n");
    fprintf(fp, "============================================================\n");
}

/* ------------------------------------------------------------------ *
 *  IN TAT CA HOA DON                                                  *
 * ------------------------------------------------------------------ */
void in_tat_ca_hoa_don(void) {
    int i;
    if (so_hoa_don == 0) { printf("\nChua co hoa don nao!\n"); return; }
    for (i = 0; i < so_hoa_don; i++) {
        printf("\n");
        in_noi_dung_hoa_don(stdout, &ds_hoa_don[i]);
    }
}

/* ------------------------------------------------------------------ *
 *  XOA HOA DON + DANH LAI SO                                          *
 * ------------------------------------------------------------------ */
void xoa_hoa_don(void) {
    int i, so_hd;

    if (so_hoa_don == 0) { printf("\nChua co hoa don nao!\n"); return; }

    /* Hien danh sach nhanh */
    printf("\n--- DANH SACH HOA DON ---\n");
    for (i = 0; i < so_hoa_don; i++)
        printf("  Hoa Don #%d | %d mon | Thanh toan: %.0f VND\n",
               ds_hoa_don[i].so_hd,
               ds_hoa_don[i].so_item,
               ds_hoa_don[i].thanh_toan > 0
                   ? ds_hoa_don[i].thanh_toan
                   : ds_hoa_don[i].tong_tien);

    printf("\nNhap so hoa don muon xoa (1 - %d), 0 de huy: ", so_hoa_don);
    if (scanf("%d", &so_hd) != 1) { while(getchar()!='\n'); return; }
    while(getchar()!='\n');

    if (so_hd == 0) { printf("Da huy.\n"); return; }
    if (so_hd < 1 || so_hd > so_hoa_don) {
        printf("So hoa don khong hop le!\n"); return;
    }

    /* Tim vi tri trong mang (so_hd - 1 neu danh so lien tuc) */
    int vi_tri = -1;
    for (i = 0; i < so_hoa_don; i++)
        if (ds_hoa_don[i].so_hd == so_hd) { vi_tri = i; break; }

    if (vi_tri < 0) { printf("Khong tim thay hoa don #%d!\n", so_hd); return; }

    printf("Xac nhan xoa Hoa Don #%d? (y/n): ", so_hd);
    char c; scanf(" %c", &c); while(getchar()!='\n');
    if (c != 'y' && c != 'Y') { printf("Da huy.\n"); return; }

    /* Dich cac hoa don phia sau len truoc */
    for (i = vi_tri; i < so_hoa_don - 1; i++)
        ds_hoa_don[i] = ds_hoa_don[i + 1];

    so_hoa_don--;

    /* Danh lai so hoa don lien tuc tu 1 */
    for (i = 0; i < so_hoa_don; i++)
        ds_hoa_don[i].so_hd = i + 1;

    printf(">> Da xoa Hoa Don #%d. Cac hoa don da duoc danh lai so.\n", so_hd);
}

/* ------------------------------------------------------------------ *
 *  XUAT HOA DON RA FILE .TXT                                          *
 * ------------------------------------------------------------------ */
void xuat_hoa_don_ra_file(int so_hd) {
    int  i;
    char ten_file[40];
    FILE *fp;
    HoaDon *hd = NULL;

    for (i = 0; i < so_hoa_don; i++)
        if (ds_hoa_don[i].so_hd == so_hd) { hd = &ds_hoa_don[i]; break; }

    if (hd == NULL) { printf("Khong tim thay hoa don #%d!\n", so_hd); return; }

    sprintf(ten_file, "hoadon_%d.txt", so_hd);
    fp = fopen(ten_file, "w");
    if (fp == NULL) { printf("Khong the mo file %s!\n", ten_file); return; }

    in_noi_dung_hoa_don(fp, hd);
    fclose(fp);
    printf(">> Da xuat hoa don #%d ra file: %s\n", so_hd, ten_file);
}
