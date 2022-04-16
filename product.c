#include "product.h"

int createProduct(Product *p, int cnt) {
    getchar();
    printf("상품명 : ");
    scanf("%[^\n]s", p[cnt].name);
    getchar();
    printf("상품 설명 : ");
    scanf("%[^\n]s", p[cnt].info);
    getchar();
    printf("중량 : ");
    scanf("%[^\n]s", p[cnt].weight);
    getchar();
    printf("가격 : ");
    scanf("%d", &p[cnt].price);
    printf("배송 (1: 새벽배송/ 2: 택배배송) : ");
    scanf("%d", &p[cnt].type);

    return 1;
}

int readProduct(Product p) {
    printf("상품명 : %s\n", p.name);
    printf("상품 설명 : %s\n", p.info);
    printf("중량 : %s\n", p.weight);
    printf("가격 : %d\n", p.price);
    printf("배송 : ");
    if (p.type == 1) {
        printf("새벽배송");
    }
    else if (p.type == 2) {
        printf("택배배송");
    }
    printf("\n");

    return 1;
}

int updateProduct(Product *p, int cnt) {
    int num;

    listProduct(p, cnt);

    printf("수정할 상품 번호 (취소 : 0) : ");
    scanf("%d", &num);
#ifdef DEBUG
    printf("num: %d\n", num);
#endif
    if (num == 0) return 0;
    getchar();
    printf("새 상품명 : ");
    scanf("%[^\n]s", p[num-1].name);
    getchar();
    printf("새 상품 설명 : ");
    scanf(" %[^\n]s", p[num-1].info);
    getchar();
    printf("새 상품 중량 : ");
    scanf("%[^\n]s", p[num-1].weight);
    getchar();
    printf("새 상품 가격 : ");
    scanf("%d", &p[num-1].price);
    printf("배송 (1: 새벽배송/ 2: 택배배송) : ");
    scanf("%d", &p[num-1].type);
    printf("=> 수정성공!\n");

    return 1;
}

int deleteProduct(Product *p, int cnt) {
    int num, answer;

    listProduct(p, cnt);

    printf("삭제할 상품 번호 (취소 : 0) : ");
    scanf("%d", &num);
#ifdef DEBUG
    printf("num: %d\n", num);
#endif
    printf("정말로 삭제하시겠습니까? (삭제 : 1) ");
    scanf("%d", &answer);
    if (answer == 1) {
        p[num-1].price = -1;
        printf("=> 삭제됨!\n");
    }
    getchar();
    return 1;
}
