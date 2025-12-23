# Adaptive Distance Alert System (Arduino)

Sistem peringatan jarak pintar menggunakan sensor ultrasonik HC-SR04. Proyek ini mengimplementasikan logika responsif di mana frekuensi peringatan visual (LED) berubah secara dinamis berdasarkan tingkat kedekatan objek.

## 🚀 Fitur Utama
- *Real-time Monitoring*: Pembacaan jarak melalui Serial Monitor.
- *Adaptive Alert*: Menggunakan fungsi map() untuk mengatur kecepatan kedipan LED sesuai jarak (semakin dekat, semakin cepat).
- *Error Handling*: Logika pengaman untuk mencegah pembacaan data palsu/nol.

## 🛠️ Komponen
- Arduino Uno / Nano
- Sensor Ultrasonik HC-SR04
- LED Merah (Indikator Bahaya)
- LED Hijau (Indikator Aman)
- Resistor 220 Ohm & Kabel Jumper

## 🔌 Konfigurasi Pin
| Komponen | Pin Arduino |
|---|---|
| Trig (HC-SR04) | 9 |
| Echo (HC-SR04) | 10 |
| LED Merah | 12 |
| LED Hijau | 11 |

## 🧠 Logika Kode
Inti dari proyek ini terletak pada pemetaan jarak ke durasi waktu (delay):
```cpp
int jeda = map(jarak, 2, 15, 50, 300);

Nilai jarak antara 2cm hingga 15cm dikonversi secara linear menjadi delay 50ms hingga 300ms, memberikan feedback yang intuitif bagi pengguna.
​📁 Cara Penggunaan
​Clone repositori ini.
​Buka file .ino menggunakan Arduino IDE.
​Hubungkan perangkat sesuai tabel konfigurasi pin.
​Upload kode dan buka Serial Monitor (9600 baud).
