#include <iostream>
using namespace std;

class Car {
    public:
        float kecepatan = 10;
        float bensin = 100;
        int bensin_max = 1000;
        int penumpang = 4;

        void jalan() {
            if(bensin >= kecepatan) {
                bensin -= kecepatan ;
                cout << "Mobil ini berjalan sejauh " << kecepatan << " km/jam" << endl;
            }
        }

};
class SuperCar : public Car {
    public:
        SuperCar() {
            kecepatan = 100;
            bensin = 1000;
            bensin_max = 1000;
        }
};

class Pickup : public Car {
    public:
     // kapasitas secara default adalah 1 (jika tidak diberi nilai pada saat inisialisasi berat objek ),
        float kapasitas;
        int kapasitas_max = 1000;
        float jarak_tempuh; // Declare jarak_tempuh here 
    ;

       Pickup() {
            kecepatan = 50;
            bensin = 500;
            bensin_max = 500;
            cout << "Masukkan berat barang: ";
            cin >> kapasitas ;
            if(kapasitas == 0) { // secara default berat kapasitas adalah 1
                kapasitas = 1;
            }
             jarak_tempuh = bensin - (kecepatan*3+ (kapasitas*0.2));
        }

        void angkut() {
            if(kapasitas  <= kapasitas_max) { 
                cout << "Berhasil mengangkut barang seberat " << kapasitas << " kg" << endl;
            } else {
                cout << "Kapasitas tidak cukup untuk mengangkut barang seberat " << kapasitas << " kg" << endl;
            }
        }

        void jalan2() {
            if (bensin >= kecepatan && kapasitas > 0) {
                

                cout << "Mobil ini berjalan sejauh " << jarak_tempuh  << " km/jam dengan kapasitas terpakai "
                     << kapasitas << " kg" << endl;
            }
        }
};

int main() {
    Car mobil;
    SuperCar mobil_super;
    Pickup mobil_pickup;

    mobil.jalan();
    mobil_super.jalan();
    

    mobil_pickup.angkut();
    mobil_pickup.jalan2();

    return 0;
}