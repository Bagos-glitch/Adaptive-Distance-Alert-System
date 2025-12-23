/* * Proyek: Adaptive Distance Alert System
 *  Dibuat oleh: [Saniscara Bagos Naya
 *  tanggal:23 Desember 2025
 *  Fungsi: Sistem peringatan jarak mengunakan sensor HC-SR04 dengan
 *  indikator LED yang ritmenya berubah secara dinamis (map function).
 */

const int trig = 9;
const int echo = 10;
const int ledMerah = 12;
const int ledHijau = 11;

void setup(){
  Serial.begin (9600); //Komunikasi ke monitor laptop
  pinMode(trig,OUTPUT); // pin trig
  pinMode(echo,INPUT); // pin Echo
  pinMode(ledMerah,OUTPUT);// pin led merah
  pinMode(ledHijau,OUTPUT);//pin led hijau
}

void loop(){
 // pembersihan sinyal
 digitalWrite(trig,LOW);
 delayMicroseconds(2);

 // Menghitung sinyal ultasonik
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 //Minghitung waktu pantulan
 long durasi = pulseIn(echo,HIGH);
 int jarak = durasi * 0.034 / 2;

 Serial.print("jarak: ");
 Serial.print(jarak);
 Serial.println(" cm");

 if (jarak > 0 && jarak < 15) {
  //Memetakan jarak (2-15cm) ke rentang delay (50ms - 300ms)
  //semakin kecil jarak, semakin kecil delay (kedip makin cepat)
  int jedaDinamis = map(jarak, 2, 15, 50, 300);
  
  digitalWrite(ledMerah, HIGH);
  digitalWrite(ledHijau, LOW);

  delay(jedaDinamis);
  digitalWrite(ledMerah, LOW);
  delay(jedaDinamis);

  Serial.print("JARAK KRITIS!!!: ");
  Serial.print(jarak);
  Serial.print(" cm | Delay: ");
  Serial.println(jedaDinamis);
 }
 else{
  // KONDISI AMAN:hijau nyala, merah mati
  digitalWrite(ledMerah, LOW);
  digitalWrite(ledHijau, HIGH);
  Serial.println("STATUS AMAN");
  delay(500);
 }
}
