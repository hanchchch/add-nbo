#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

uint32_t my_ntohl(uint32_t n) {
    return (n<<24)|((n&0xff00)<<8)|((n>>8)&0xff00)|(n>>24);
}

int main(int argc, char* argv[]) {
    FILE *fp1, *fp2;
    uint32_t n1;
    uint32_t n2;

    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\nsample : add-nbo a.bin c.bin");
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("No such file \"%s\"", argv[1]);
        return 0;
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("No such file \"%s\"", argv[2]);
        return 0;
    }

    fread(&n1, 4, 1, fp1);
    fread(&n2, 4, 1, fp2);

    n1 = my_ntohl(n1);
    n2 = my_ntohl(n2);

    printf("%d(%x)", n1, n1);
    printf(" + %d(%x)", n2, n2);
    printf(" = %d(%x)\n", n1+n2, n1+n2);

    return 0;
    

}