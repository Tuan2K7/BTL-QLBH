# BÀI TẬP LỚN ỨNG DỤNG QUẢN LÝ BÁN HÀNG
CÁC THÀNH VIÊN NHÓM:
1. NGUYỄN ANH TUẤN
2. TRẦN VĂN THÔNG
3. CAO VIỆT CƯỜNG
4. NGUYỄN HỮU DŨNG
5. TRẦN KHÁNH DƯƠNG
# XÂY DỰNG ỨNG DỤNG QUẢN LÝ BÁN MỲ CAY
# Cấu trúc dữ liệu:
- Món ăn gồm 3 dữ liệu : int số thứ tự, char tên món, float đơn giá.
- Thành phần hóa đơn : int mã món, int cấp độ, int số lượng, float đơn giá, float thành tiền. 
- Hóa đơn gồm : int số hóa đơn (mã hóa đơn), int so_item số lượng món, ItemHoaDon items[MAX_ITEM] giới hạn số lượng món trong hóa đơn, float tong_tien (tính tổng số tiền các món trong hóa đơn đấy). 
- Global menu.
# Chức năng: 
- Đặt món / tạo hóa đơn
- Xem tất cả hóa đơn
- Thêm hóa đơn
- Xóa món
- Giảm giá
- In hóa đơn.
# Yêu cầu: Định nghĩa struct và biến toàn cục.
- Khởi tạo và hiển thị thực đơn: .c và .h
 + .h (Header File) chứa: Khai báo hàm, khai báo struct, khai báo hằng số, thư viện dùng chung.
 + .c là file thực thi.
# Dữ liệu đầu vào:
- Gồm 6 món mì cay: thập cẩm, đùi gà, bò, bạch tuộc, xúc xích, hải sản.
- Mã món ăn: 1->6.
- Cấp độ cay: 1->7.
Mã giảm giá(Robux): >=0.
Lựa chọn chức năng(hàm main): 1->4.
# Các hàm:
- main.c : Điều khiển chương trình chính.
- menu.h : Khai báo hàm và cấu trúc thực đơn.
- menu.c : Khởi tạo thực đơn, hiển thị thực đơn, hiển thị menu chức năng.
- hoa_don.h : Khai báo cấu trúc hóa đơn, khai báo các hàm xử lý hóa đơn.
- hoa_don.c : Tạo hóa đơn, tính giảm giá Robux, in hóa đơn, xuất hóa đơn ra file, xóa hóa đơn.
- common.h : Khai báo hằng số dùng chung, khai báo cấu trúc dữ liệu.
- global.c : Lưu biến toàn cục, quản lý danh sách món ăn, quản lý danh sách hóa đơn.
