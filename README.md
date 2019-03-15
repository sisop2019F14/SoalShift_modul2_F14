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

 
Lalu deklarasikan variable, disini, imgsrc dan dest mewakilkan sumber dan tujuan dari file yang akan diubah namanya, file yang akan diubah berada pada direktori /home/anwar/praktikum_2/no1/ dan nantinya akan disimpan di /home/anwar/modul2/gambar/. Karena kita akan mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png” maka  _grey.png disimpan dalam char bernama nameRule. Setelah itu lakukan pencarian file .png dalam directori / home/anwar/praktikum_2/no1/  nama file tersebut dimasukkan ke dalam char originalName. Buat susunan aturannya dalam char newName, lalu rename originalName menjadi newName.
 
Soal 2
Membuat program C untuk mendeteksi owner dan group (dengan nama www-data) dan menghapus file “elen.ku” setiap 3 detik dan juga mengubah permissionnya menjadi 777.
Catatan: Tidak boleh menggunakan crontab

Jawaban:

[soal2.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no2/hatiku/no2.c)

Program c ini menggunakan daemon process, dimana awalnya kita menentukan directory mana yang akan digunakan untuk menampung daemon process tersebut (/home/anwar/praktikum_2/no2/hatiku/)

![soal2-1](https://user-images.githubusercontent.com/47809366/54402737-bd6aab00-46ff-11e9-8d73-f43c4b1f9abe.PNG)

Lakukan pencarian file bernama elen.ku, setelah itu dapatkan owner dan group. Jika sudah mendapatkan owner dan group bernama “www-data” maka ubah permissionnya menjadi 777. Lalu hapus file tersebut. Sleep(3) adalah perintah untuk mengatur waktu, jadi ketika program berhenti, maka setelah 3 detik program akan berjalan kembali.

![soal2-2](https://user-images.githubusercontent.com/47809366/54402740-bf346e80-46ff-11e9-9e30-f42e1a55dde8.PNG)

Soal 3:
Membuat Program mengekstrak file zip campur2.zip lalu menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 

Jawaban:

[soal3.c]( https://github.com/sisop2019F14/SoalShift_modul2_F14/blob/master/no3/no3.c)

Soal 4

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

