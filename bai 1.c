#include <stdio.h>
#include <string.h>

// Khoi tao doi tuong sach
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    double giaTien;
    char theLoai[50];
} Sach;
// Ham hien thi thong tin sach
void hienThiThongTinSach(Sach *arr, int size) {
    printf("Danh sach cac cuon sach:\n");
    for (int i = 0; i < size; i++) {
        printf("Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n",
               arr[i].maSach, arr[i].tenSach, arr[i].tacGia, arr[i].giaTien, arr[i].theLoai);
    }
    printf("\n");
}
// Ham nhap thong tin sach
void nhapThongTinSach(Sach *arr, int *size, int maxSize) {
    int n;
    printf("Nhap so luong sach can nhap: ");
    scanf("%d", &n);

    if (*size + n > maxSize) {
        printf("Khong du cho trong mang de nhap them sach.\n\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sach thu %d:\n", *size + 1);
        printf("Ma sach: ");
        scanf(" %[^\n]", arr[*size].maSach);
        printf("Ten sach: ");
        scanf(" %[^\n]", arr[*size].tenSach);
        printf("Tac gia: ");
        scanf(" %[^\n]", arr[*size].tacGia);
        printf("Gia tien: ");
        scanf("%lf", &arr[*size].giaTien);
        printf("The loai: ");
        scanf(" %[^\n]", arr[*size].theLoai);
        (*size)++;
    }
    printf("Nhap thong tin thanh cong.\n\n");
}
// Ham them sach vao vi tri
void themSach(Sach *arr, int *size, int maxSize) {
    if (*size >= maxSize) {
        printf("Danh sach da day, khong the them sach.\n\n");
        return;
    }
    int viTri;
    printf("Nhap vi tri can them sach (0 - %d): ", *size);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > *size) {
        printf("Vi tri khong hop le.\n\n");
        return;
    }
    for (int i = *size; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    printf("Nhap thong tin sach:\n");
    printf("Ma sach: ");
    scanf(" %[^\n]", arr[viTri].maSach);
    printf("Ten sach: ");
    scanf(" %[^\n]", arr[viTri].tenSach);
    printf("Tac gia: ");
    scanf(" %[^\n]", arr[viTri].tacGia);
    printf("Gia tien: ");
    scanf("%lf", &arr[viTri].giaTien);
    printf("The loai: ");
    scanf(" %[^\n]", arr[viTri].theLoai);

    (*size)++;
    printf("Them sach thanh cong.\n\n");
}
// Ham xoa sach theo ma sach
void xoaSach(Sach *arr, int *size) {
    char maSach[20];
    int found = 0;
    printf("Nhap ma sach can xoa: ");
    scanf(" %[^\n]", maSach);

    for (int i = 0; i < *size; i++) {
        if (strcmp(arr[i].maSach, maSach) == 0) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            printf("Xoa sach thanh cong.\n\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay ma sach %s.\n\n", maSach);
    }
}
// Ham cap nhat thong tin sach theo ma sach
void capNhatSach(Sach *arr, int size) {
    char maSach[20];
    int found = 0;
    printf("Nhap ma sach can cap nhat: ");
    scanf(" %[^\n]", maSach);

    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].maSach, maSach) == 0) {
            found = 1;
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", arr[i].tenSach);
            printf("Nhap tac gia moi: ");
            scanf(" %[^\n]", arr[i].tacGia);
            printf("Nhap gia tien moi: ");
            scanf("%lf", &arr[i].giaTien);
            printf("Nhap the loai moi: ");
            scanf(" %[^\n]", arr[i].theLoai);
            printf("Cap nhat thong tin thanh cong.\n\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay ma sach %s.\n\n", maSach);
    }
}
// Ham sap xep sach theo gia
void sapXepSach(Sach *arr, int size, int tangDan) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((tangDan && arr[i].giaTien > arr[j].giaTien) ||
                (!tangDan && arr[i].giaTien < arr[j].giaTien)) {
                Sach temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n\n");
}
// Ham tim kiem sach theo ten
void timKiemSach(Sach *arr, int size) {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", tenSach);
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].tenSach, tenSach) != NULL) {
            printf("Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n",
                   arr[i].maSach, arr[i].tenSach, arr[i].tacGia, arr[i].giaTien, arr[i].theLoai);
        }
    }
    printf("\n");
}
// Ham chinh
int main() {
    Sach danhSach[50];
    int soLuong = 0;

    while (1) {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSach(danhSach, &soLuong, 50);
                break;
            case 2:
                hienThiThongTinSach(danhSach, soLuong);
                break;
            case 3:
                themSach(danhSach, &soLuong, 50);
                break;
            case 4:
                xoaSach(danhSach, &soLuong);
                break;
            case 5:
                capNhatSach(danhSach, soLuong);
                break;
            case 6: {
                int tangDan;
                printf("Chon sap xep (1: Tang dan, 0: Giam dan): ");
                scanf("%d", &tangDan);
                sapXepSach(danhSach, soLuong, tangDan);
                break;
            }
            case 7:
                timKiemSach(danhSach, soLuong);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n\n");
        }
    }
}

