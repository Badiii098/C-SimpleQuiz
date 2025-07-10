#include <stdio.h>

typedef struct {
    char pertanyaan[100];
    char pilihanA[50];
    char pilihanB[50];
    char pilihanC[50];
    char pilihanD[50];
    char jawaban;
} Soal;

int tampilkanSoal(int nomorSoal) {
    Soal soal[10] = {      
       	{"Bagaimana cara mendeklarasikan array dalam bahasa pemrograman C dengan panjang 5?","int array[5];","array[5];","array = int[5];","int[5] array;",'A'},		
		{"Apa hasil dari operasi sizeof(int) dalam bahasa pemrograman C?","2","4","8","Tergantung pada implementasi compiler",'B'},		
		{"Apa fungsi dari operator ++ dalam bahasa pemrograman C?","Increment","Decrement","Addition","Subtraction",'A'},		
		{"Bagaimana cara mendeklarasikan fungsi dengan nilai kembali bertipe double dalam bahasa C?","double function();","function double();","function: double();","function() double;",'A'},			
        {"Apa bentuk bumi?", "Bulat", "Datar", "Oblate Spheroid", "Persegi", 'A'},
        {"Berapa hasil dari 12 x 4?", "48", "36", "24", "60", 'A'},
        {"Siapakah penemu bola lampu?", "Alexander Graham Bell", "Nikola Tesla", "Thomas A Edison", "Albert Einstein", 'C'},
        {"Apa singkatan dari CPU?", "Central Programming Unit", "Central Processing Unit", "Central Peripheral Unit", "Central Power Unit", 'B'},
		{"Bagaimana cara menginisialisasi array dengan nilai awal dalam bahasa C?","{1, 2, 3, 4, 5}","array(1, 2, 3, 4, 5)","array = {1, 2, 3, 4, 5}","array = [1, 2, 3, 4, 5]",'A'},		
		{"Apa hasil dari operasi 5 / 2 dalam bahasa pemrograman C?","2.5","2","2.0","2.2",'B'}
    };

    printf("\n============================================");
    printf("\n\nSoal %d: %s\n", nomorSoal + 1, soal[nomorSoal].pertanyaan);
    printf("A. %s\n", soal[nomorSoal].pilihanA);
    printf("B. %s\n", soal[nomorSoal].pilihanB);
    printf("C. %s\n", soal[nomorSoal].pilihanC);
    printf("D. %s\n", soal[nomorSoal].pilihanD);

    char jawabanPengguna;
    printf("Jawaban (A/B/C/D): ");
    scanf(" %c", &jawabanPengguna);

    if (jawabanPengguna == soal[nomorSoal].jawaban) {
        printf("Jawaban benar! Anda mendapatkan 10 poin.\n\n");
        return 10;  // Mengembalikan nilai 10 jika jawaban benar
    } else {
        printf("Jawaban salah.\n");
        return 0;
    }
}

int main() {
    int nomorSoal = 0;
    int skor = 0;
    int pilihanMenu = 0;

    while (pilihanMenu != 3) {
        printf("Menu:\n");
        printf("1. Mulai permainan\n");
        printf("2. Tampilkan Skor\n");
        printf("3. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanMenu);

        switch (pilihanMenu) {
case 1:
    while (nomorSoal < 10) {
        int skorSoal = tampilkanSoal(nomorSoal);
        skor += skorSoal;
        nomorSoal++;

        if (skorSoal == 0) {
            // Jika jawaban salah, keluar dari loop dan akhiri permainan
            nomorSoal = 10;
            break;
        }
    }

    printf("Permainan selesai. Skor total: %d\n\n", skor);
    printf("============================================\n\n");
    nomorSoal = 0;  //mereset nomorSoal setelah permainan selesai
    break;


            case 2:
                printf("Skor Anda saat ini: %d\n\n", skor);
                    printf("============================================\n\n");
                break;

            case 3:
                printf("Terima kasih telah bermain!\n");
                break;

            default:
                printf("Pilihan menu tidak valid. Silakan pilih lagi.\n");
                	printf("\n============================================\n\n");
                break;
        }
    }

    return 0;
}


