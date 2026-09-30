#include <jni.h>
#include <string>
#include <unistd.h>
#include <sys/ptrace.h>

// Fungsi sederhana untuk obfuscation / dekripsi string (Keamanan Dasar)
std::string xorEncryptDecrypt(std::string toEncrypt, char key) {
    std::string output = toEncrypt;
    for (size_t i = 0; i < toEncrypt.size(); i++) {
        output[i] = toEncrypt[i] ^ key;
    }
    return output;
}

// Cek keamanan sederhana (mencegah ptrace / debugger terhubung)
bool checkAntiDebug() {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
        return true; // Ada debugger aktif (berbahaya)
    }
    return false;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mynativeapp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    // 1. Proteksi Keamanan
    if (checkAntiDebug()) {
        return env->NewStringUTF("Sistem Keamanan: Debugger terdeteksi! Aplikasi dihentikan.");
    }

    // =========================================================================
    // === BISA KAMU UBAH DI SINI (LOGIKA KODE C++ UTAMA) ======================
    // =========================================================================

    // Contoh: String terenkripsi sederhana (XOR dengan key 'K')
    // String asli: "Halo dari C++ Secure Engine! Kode kamu aman di sini."
    std::string pesanPemberitahuan = "Halo dari C++ Secure Engine! Kode kamu aman di sini.";

    // Kamu bisa menuliskan algoritma, matematika, pengolahan data, atau fungsi C++
    // milikmu sendiri di area ini secara bebas.
    int a = 10;
    int b = 20;
    int hasilPenjumlahan = a + b;

    std::string responAkhir = pesanPemberitahuan + "\nHasil hitungan C++: " + std::to_string(hasilPenjumlahan);

    // =========================================================================

    return env->NewStringUTF(responAkhir.c_str());
}