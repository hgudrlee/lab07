#include "manager.h"

int main(void) {
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
    Product *plist;
    plist = (Product *)malloc(sizeof(Product) * 100);
    int count = 0, menu;
    count = loadData(plist);

    while (1) {
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5) {
            if (count == 0) {
                printf("=> 상품 없음\n");
                continue;
            }
        }
        if (menu == 1) {
            createProduct(plist, count);
            count++;
        }
        else if (menu == 2) {
            listProduct(plist, count);
        }
        else if (menu == 3) {
            updateProduct(plist, count);
        }
        else if (menu == 4) {
            deleteProduct(plist, count);
        }
        else if (menu == 5) {
            searchProduct(plist, count);
        }
        else if (menu == 6) {
            saveProduct(plist, count);
        }
    }

    return 0;
}
