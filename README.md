# SoalShift_modul2_F14

Soal 1

Program mengubah nama file ekstensi .png menjadi “[namafile]_grey.png” Secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawaban:

[soal1.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no1/no1.c)

![soal1-1](https://user-images.githubusercontent.com/47809366/54402654-5947e700-46ff-11e9-8050-b59d9725befc.PNG)

Program c ini menggunakan daemon process, dimana awalnya kita menentukan directory mana yang akan digunakan untuk menampung daemon process tersebut(/home/anwar/praktikum_2/no1)

![soal1-2](https://user-images.githubusercontent.com/47809366/54402682-78467900-46ff-11e9-8541-642b07c41124.PNG)

![soal1-3](https://user-images.githubusercontent.com/47809366/54402685-7977a600-46ff-11e9-98b2-a5a6132d4845.PNG)

 
Lalu deklarasikan variable, disini, imgsrc dan dest mewakilkan sumber dan tujuan dari file yang akan diubah namanya, file yang akan diubah berada pada direktori /home/anwar/praktikum_2/no1/ dan nantinya akan disimpan di /home/anwar/modul2/gambar/. Karena kita akan mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png” maka  _grey.png disimpan dalam char bernama nameRule. lakukan looping pada direktori /home/anwar/praktikum_2/no1/, ambil judul dan gabungkan dengan string /home/anwar/praktikum_2/no1/ pada array originalName, lalu ambil judul dan masukkan dalam filename, setelah itu ambil ekstensi file dan cek apakah file tersebut berekstensi png, jika iya maka ambil string /home/anwar/modul2/gambar/ masukkan ke string newname, lalu ambil filename dan gabungkan dengan namerule, lalu gabungkan dengan string newname dan rename originalname dengan newname.

Hasil: 

![no1](https://user-images.githubusercontent.com/47809366/54416091-f2dbbc80-4730-11e9-8371-c698e875a1c9.png)
 
Soal 2

Membuat program C untuk mendeteksi owner dan group (dengan nama www-data) dan menghapus file “elen.ku” setiap 3 detik dan juga mengubah permissionnya menjadi 777.
Catatan: Tidak boleh menggunakan crontab

Jawaban:

[soal2.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no2/hatiku/no2.c)

Program c ini menggunakan daemon process, dimana awalnya kita menentukan directory mana yang akan digunakan untuk menampung daemon process tersebut (/home/anwar/praktikum_2/no2/hatiku/)

![soal2-1](https://user-images.githubusercontent.com/47809366/54402737-bd6aab00-46ff-11e9-8d73-f43c4b1f9abe.PNG)

Lakukan pencarian file bernama elen.ku, setelah itu dapatkan owner dan group. Jika sudah mendapatkan owner dan group bernama “www-data” maka ubah permissionnya menjadi 777. Lalu hapus file tersebut. Sleep(3) adalah perintah untuk mengatur waktu, jadi ketika program berhenti, maka setelah 3 detik program akan berjalan kembali.

![soal2-2](https://user-images.githubusercontent.com/47809366/54402740-bf346e80-46ff-11e9-9e30-f42e1a55dde8.PNG)

Hasil:

![no2](https://user-images.githubusercontent.com/47809366/54416095-f53e1680-4730-11e9-9719-b771045b9f39.png)

Soal 3

Membuat Program mengekstrak file zip campur2.zip lalu menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 

Jawaban:

[soal3.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no3/true3.c)

lakukan unzip file menggunakan fork dan exec, lalu lakukan pemindahan dari folder campur2 untuk di extensikan ke .txt lalu dimasukkan kedalam file data.txt

![Capture1](https://user-images.githubusercontent.com/47809366/54431193-50cfca80-4758-11e9-8cc5-8cf5f7a76aba.PNG)

![Capture2](https://user-images.githubusercontent.com/47809366/54431194-5200f780-4758-11e9-9d88-af97a5737560.PNG)

Hasil:

![no3](https://user-images.githubusercontent.com/47809366/54416101-f7a07080-4730-11e9-8f33-af8577269774.png)

![no3_p2](https://user-images.githubusercontent.com/47809366/54416103-f96a3400-4730-11e9-97fb-9d2d97a2ec47.png)


Soal 4

membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).

Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga.

Jawaban:

[soal4.c](https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no4/no4.c)

gunakan looping dalam mengambil waktu untuk mengetahui waktu akses dari file home/anwar/documents/makanan/makan_enak.txt, lalu cek apakah file tersebut diakses kurang dari 30 detik atau tidak, jika kurang dari 30 detik maka dibuatlah file /home/anwar/documents/makanan/makanan_sehat dengan eksistensi .txt

![no4---1](https://user-images.githubusercontent.com/47809366/54431755-d2742800-4759-11e9-8db8-3c5f01dbef97.PNG)

Hasil:

![no4](https://user-images.githubusercontent.com/47809366/54416108-fb33f780-4730-11e9-947c-4cb0c4b7901a.png)


Soal 5

a. Membuat program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:

•	Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]

•	Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1

b. Membuat program untuk menghentikan program tersebut

Jawaban:

[soal5a.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no5/no5a.c)

[soal5b.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no5/no5b.c)

a. yang pertama dilakukan adalah mengambil waktu sekarang, lalu setelah itu ambil isi file syslog pada /var/log/syslog untuk dimasukkan kedalam direktori baru. setelah itu buat file baru sesuai dengan ketentuan (sleep diatur 60 detik)

![5a-1](https://user-images.githubusercontent.com/47809366/54432315-6abedc80-475b-11e9-9b49-5f313802a828.PNG)

![5a-2](https://user-images.githubusercontent.com/47809366/54432317-6bf00980-475b-11e9-8a77-f7c6d580e03a.PNG)

b. buka direktori tempat file yang dibuat tadi dan ambil pidnya(menggunakan popen, pidof pada direktori (/home/anwar/log/no5a)), lalu kirim sinyal untuk membunuh proses tersebut.

![5b](https://user-images.githubusercontent.com/47809366/54432681-71018880-475c-11e9-90de-82ff75299f52.PNG)

Hasil

![no5a](https://user-images.githubusercontent.com/47809366/54416299-93ca7780-4731-11e9-8438-1f8909d5976d.png)

![no5b](https://user-images.githubusercontent.com/47809366/54416320-9e850c80-4731-11e9-9ca7-171b3a1afc6e.png)


