#include <stdio.h>
#include <string.h>

// Khoi tao doi tuong san pham
typedef struct {
    char maSP[20];
    char tenSP[100];
    double giaNhap;
    double giaBan;
    int soLuong;
} SanPham;
// Ham hien thi danh sach san pham
void hienThiSanPham(SanPham *arr, int size) {
    printf("Danh sach san pham:\n");
    for (int i = 0; i < size; i++) {
        printf("Ma SP: %s, Ten SP: %s, Gia Nhap: %.2f, Gia Ban: %.2f, So Luong: %d\n",
               arr[i].maSP, arr[i].tenSP, arr[i].giaNhap, arr[i].giaBan, arr[i].soLuong);
    }
    printf("\n");
}
// Ham tim vi tri san pham theo ma
int timSanPham(SanPham *arr, int size, char *maSP) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].maSP, maSP) == 0) {
            return i;
        }
    }
    return -1;
}
// Ham nhap thong tin san pham
void nhapSanPham(SanPham *arr, int *size, double *doanhThu, int maxSize) {
    char maSP[20];
    int soLuongNhap;
    printf("Nhap ma san pham: ");
    scanf(" %[^\n]", maSP);

    int viTri = timSanPham(arr, *size, maSP);
    if (viTri != -1) { // Neu san pham da ton tai
        printf("San pham da ton tai. Nhap so luong them: ");
        scanf("%d", &soLuongNhap);
        arr[viTri].soLuong += soLuongNhap;
        *doanhThu -= soLuongNhap * arr[viTri].giaNhap;
        printf("Cap nhat so luong thanh cong.\n\n");
    } else { // San pham moi
        if (*size >= maxSize) {
            printf("Danh sach da day, khong the them san pham moi.\n\n");
            return;
        }

        printf("Nhap ten san pham: ");
        scanf(" %[^\n]", arr[*size].tenSP);
        printf("Nhap gia nhap: ");
        scanf("%lf", &arr[*size].giaNhap);
        printf("Nhap gia ban: ");
        scanf("%lf", &arr[*size].giaBan);
        printf("Nhap so luong: ");
        scanf("%d", &soLuongNhap);

        strcpy(arr[*size].maSP, maSP);
        arr[*size].soLuong = soLuongNhap;
        *doanhThu -= soLuongNhap * arr[*size].giaNhap;
        (*size)++;
        printf("Them san pham thanh cong.\n\n");
    }
}
// Ham cap nhat thong tin san pham
void capNhatSanPham(SanPham *arr, int size) {
    char maSP[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf(" %[^\n]", maSP);

    int viTri = timSanPham(arr, size, maSP);
    if (viTri == -1) {
        printf("Khong tim thay san pham.\n\n");
        return;
    }
    printf("Nhap ten moi: ");
    scanf(" %[^\n]", arr[viTri].tenSP);
    printf("Nhap gia nhap moi: ");
    scanf("%lf", &arr[viTri].giaNhap);
    printf("Nhap gia ban moi: ");
    scanf("%lf", &arr[viTri].giaBan);
    printf("Nhap so luong moi: ");
    scanf("%d", &arr[viTri].soLuong);

    printf("Cap nhat thong tin thanh cong.\n\n");
}
// Ham sap xep san pham theo gia
void sapXepSanPham(SanPham *arr, int size, int tangDan) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((tangDan && arr[i].giaBan > arr[j].giaBan) ||
                (!tangDan && arr[i].giaBan < arr[j].giaBan)) {
                SanPham temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n\n");
}
// Ham tim kiem san pham theo ten
void timKiemSanPham(SanPham *arr, int size) {
    char tenSP[100];
    printf("Nhap ten san pham can tim: ");
    scanf(" %[^\n]", tenSP);

    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].tenSP, tenSP) != NULL) {
            printf("Ma SP: %s, Ten SP: %s, Gia Nhap: %.2f, Gia Ban: %.2f, So Luong: %d\n",
                   arr[i].maSP, arr[i].tenSP, arr[i].giaNhap, arr[i].giaBan, arr[i].soLuong);
        }
    }
    printf("\n");
}
// Ham ban san pham
void banSanPham(SanPham *arr, int *size, double *doanhThu) {
    char maSP[20];
    int soLuongBan;
    printf("Nhap ma san pham can ban: ");
    scanf(" %[^\n]", maSP);

    int viTri = timSanPham(arr, *size, maSP);
    if (viTri == -1) {
        printf("Khong tim thay san pham.\n\n");
        return;
    }

    if (arr[viTri].soLuong == 0) {
        printf("San pham da het hang.\n\n");
        return;
    }

    printf("Nhap so luong can ban: ");
    scanf("%d", &soLuongBan);

    if (soLuongBan > arr[viTri].soLuong) {
        printf("Khong du so luong hang.\n\n");
    } else {
        arr[viTri].soLuong -= soLuongBan;
        *doanhThu += soLuongBan * arr[viTri].giaBan;
        printf("Ban hang thanh cong.\n\n");
    }
}
int main() {
    SanPham danhSach[50];
    int soLuong = 0;
    double doanhThu = 0.0;

    while (1) {
        printf("MENU\n");
        printf("1. Nhap san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham (cap nhat hoac them moi)\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Xem doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapSanPham(danhSach, &soLuong, &doanhThu, 50);
                break;
            case 2:
                hienThiSanPham(danhSach, soLuong);
                break;
            case 3:
                nhapSanPham(danhSach, &soLuong, &doanhThu, 50);
                break;
            case 4:
                capNhatSanPham(danhSach, soLuong);
                break;
            case 5: {
                int tangDan;
                printf("Chon sap xep (1: Tang dan, 0: Giam dan): ");
                scanf("%d", &tangDan);
                sapXepSanPham(danhSach, soLuong, tangDan);
                break;
            }
            case 6:
                timKiemSanPham(danhSach, soLuong);
                break;
            case 7:
                banSanPham(danhSach, &soLuong, &doanhThu);
                break;
            case 8:
                printf("Doanh thu hien tai: %.2f\n\n", doanhThu);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n\n");
        }
    }
}

