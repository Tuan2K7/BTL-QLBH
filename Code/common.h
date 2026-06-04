#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//define
#define MAX_MON       6
#define MAX_CAP_DO    7
#define MAX_HOA_DON   50
#define MAX_ITEM      30

//MENU DATA 
typedef struct {
    int    stt;
    char   ten[60];
    float  don_gia;
} MonAn;

// HOA DON ITEM 
typedef struct {
    int   ma_mon;      // nhập 1 ,2,.. hợac 6  
    int   cap_do;        // 1 tới 7
    int   so_luong;
    float don_gia;
    float thanh_tien;
} ItemHoaDon;

// HOA DON 
typedef struct {
    int        so_hd;
    int        so_item;
    ItemHoaDon items[MAX_ITEM];
    float      tong_tien;
    int        robux_dung;    /* so Robux da su dung */
    float      phan_tram_giam;/* % giam tuong ung   */
    float      thanh_toan;    /* so tien thuc tra   */
} HoaDon;

// khai bao bien hoac ham o noi khac ,đã được định nghĩa ở nơi khác,ở đây chỉ gọi lại để dùng 
extern MonAn  menu[MAX_MON];
extern HoaDon ds_hoa_don[MAX_HOA_DON];
extern int    so_hoa_don;

#endif //common.h
