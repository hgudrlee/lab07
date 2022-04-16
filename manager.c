#include "manager.h"

int selectMenu() {
    	int menu;
	printf("\nOSS 마켓에 방문해주셔서 감사합니다!\n\n");
    	printf("\n*** OSS마켓 ***\n");
    	printf("0. 종료\n");
    	printf("1. 상품 추가\n");
    	printf("2. 모든 상품 조회\n");
    	printf("3. 상품 수정\n");
    	printf("4. 상품 삭제\n");
    	printf("5. 상품 검색\n");
    	printf("6. 저장\n");
    	printf("\n=> 선택할 메뉴 : ");
    	scanf("%d", &menu);
    
    	return menu;
}

int loadData(Product *p) {
    int i = 0;
    char address[20];
    FILE *fp;

    fp = fopen("product.dat", "rt");

    if (fp == NULL) {
        printf("=> 파일 없음\n");
        
	return 0;
    }

    for (; i < 100; i++) {
        fscanf(fp, "%s", p[i].name);
        if (feof(fp)) break;
        fscanf(fp, "%s", p[i].info);
        fscanf(fp, "%s", p[i].weight);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%s", address);
        if (strcmp(address, "새벽배송") == 0) p[i].type = 1;
        else p[i].type = 2;
    }

    fclose(fp);
    printf("=> 불러오기 완료\n");
    printf("=> 총 %d개의 제품을 불러옴\n", i);
    
    return i;
}

int listProduct(Product *p, int cnt) {
    int count = 0;
    for (int i = 0; i < cnt; i++) {
        if (p[i].price == -1) continue;
	count++;
        printf("-----------------------------\n");
        printf("- %d번 상품\n", i+1);
        printf("상품명 : %s\n", p[i].name);
        printf("상품 설명 : %s\n", p[i].info);
        printf("중량 : %s\n", p[i].weight);
        printf("가격 : %d\n", p[i].price);
        printf("배송 : ");
        if (p[i].type == 1) {
            printf("새벽배송");
        }
        else if (p[i].type == 2) {
            printf("택배배송");
        }
        printf("\n");
    }
    printf("-----------------------------\n");
    printf("현재 총 상품의 개수 : %d\n", count);
    printf("-----------------------------\n");
    return 1;
}

void saveProduct(Product *p, int cnt) {
    FILE *fp;
    fp = fopen("product.dat", "wt");

    for (int i = 0; i < cnt; i++) {
	if (p[i].price == -1) continue;
        fprintf(fp, "%s\n", p[i].name);
        fprintf(fp, "%s\n", p[i].info);
        fprintf(fp, "%s\n", p[i].weight);
        fprintf(fp, "%d\n", p[i].price);
        if (p[i].type == 1) {
            fprintf(fp, "%s\n", "새벽배송");
        }
        else if (p[i].type == 2) {
            fprintf(fp, "%s\n", "택배배송");
        }
    }

    fclose(fp);
    printf("=> 저장됨\n");
}

void searchProduct(Product *p, int cnt) {
    int search;

    printf("검색 유형 (1. 상품 정보 2. 상품 가격 3. 배송 유형): ");
    scanf("%d", &search);

    if (search == 1) searchInfo(p, cnt);
    else if (search == 2) searchPrice(p, cnt);
    else if (search == 3) searchAddress(p, cnt);
    else printf("해당 번호에 맞는 검색 유형이 존재하지 않습니다\n");
}

void searchInfo(Product *p, int cnt) {
    int scnt = 0;
    char search[30];
    
    printf("=> 검색할 상품의 설명 키워드 : ");
    scanf("%s", search);

    for (int i = 0; i < cnt; i++) {
        if (p[i].price == -1) continue;
        else if (strstr(p[i].info, search)) {
            printf("%d번 메뉴 : %s (상품 설명: %s)\n", i+1, p[i].name, p[i].info);
            scnt++;
        }
    }
    
    if (scnt == 0) printf("=> 검색한 상품이 없습니다");
    printf("\n");
}

void searchPrice(Product *p, int cnt) {
    int scnt;
    int price1, price2;

    printf("=> 검색할 상품의 가격 범위(최소, 최대) : ");
    scanf("%d %d", &price1, &price2);

    for (int i = 0; i < cnt; i++) {
        if (p[i].price == -1) continue;
        else if (p[i].price <= price2 && p[i].price >= price1) {
            printf("%d번 메뉴 : %s (가격: %d 원)\n", i+1, p[i].name, p[i].price);
            scnt++;
        }
    }
    
    if (scnt == 0) printf("=> 검색한 범위에 해당하는 상품이 없습니다");
    printf("\n");
}

void searchAddress(Product *p, int cnt) {
    int scnt = 0;
    int search;

    printf("=> 1. 새벽배송 / 2. 택배배송 : ");
    scanf("%d", &search);

    for (int i = 0; i < cnt; i++) {
        if (p[i].price == -1) continue;
        if(p[i].type == search) {
            if (search == 1) {
                printf("%d번 메뉴 : %s (새벽배송)\n", i+1, p[i].name);
                scnt++;
            }
            else if (search == 2) {
                printf("%d번 메뉴 : %s (택배배송)\n", i+1, p[i].name);
                scnt++;
            }
        }
    }
    
    if (scnt == 0) printf("=> 검색한 상품이 없습니다");
    printf("\n");
}
