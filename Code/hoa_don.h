#ifndef HOA_DON_H
#define HOA_DON_H

#include "common.h"

/* Tao hoa don moi, tra ve so hoa don vua tao */
int  tao_hoa_don(void);

/* In tat ca hoa don ra man hinh */
void in_tat_ca_hoa_don(void);

/* Xoa hoa don theo so thu tu, danh lai so cho cac HD con lai */
void xoa_hoa_don(void);

/* In hoa don ra file .txt */
void xuat_hoa_don_ra_file(int so_hd);

/* Ham phu: in noi dung 1 hoa don (dung chung cho man hinh & file) */
void in_noi_dung_hoa_don(FILE *fp, HoaDon *hd);

#endif /* HOA_DON_H */
