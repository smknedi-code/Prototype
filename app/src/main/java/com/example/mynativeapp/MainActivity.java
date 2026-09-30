package com.example.mynativeapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.graphics.Color;

public class MainActivity extends AppCompatActivity {

    static {
        // Memuat library .so C++
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // =========================================================================
        // === BISA KAMU UBAH DI SINI (TAMPILAN & KUSTOMISASI LAYAR) ===============
        // =========================================================================
        TextView tv = new TextView(this);
        
        // Mengatur ukuran teks
        tv.setTextSize(18);
        
        // Mengatur jarak/padding (kiri, atas, kanan, bawah)
        tv.setPadding(50, 50, 50, 50);
        
        // Mengatur warna teks (misal: Hitam/Dark Grey)
        tv.setTextColor(Color.DKGRAY);

        // Mengambil string aman langsung dari fungsi native C++
        String pesanDariNative = stringFromJNI();
        tv.setText(pesanDariNative);

        setContentView(tv);
        // =========================================================================
    }

    // Deklarasi fungsi JNI C++
    public native String stringFromJNI();
}