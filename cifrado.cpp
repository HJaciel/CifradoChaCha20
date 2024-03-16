#include <sodium.h> 
#include <iostream>
#include <string>

void cifrar_y_descifrar(const std::string& mensaje) {
    if (sodium_init() < 0) {
        return;
    }

 
    const unsigned char clave[crypto_stream_chacha20_KEYBYTES] = { /* tu clave aquí */ };
    const unsigned char nonce[crypto_stream_chacha20_NONCEBYTES] = { /* tu nonce aquí */ };

    unsigned char cifrado[mensaje.size()];
    unsigned char descifrado[mensaje.size()];

    // Cifrado
    crypto_stream_chacha20_xor(cifrado, reinterpret_cast<const unsigned char*>(mensaje.c_str()), mensaje.size(), nonce, clave);

    // Descifrado
    crypto_stream_chacha20_xor(descifrado, cifrado, mensaje.size(), nonce, clave);

    
    std::cout << "Mensaje cifrado: " << cifrado << std::endl;
    std::cout << "Mensaje descifrado: " << descifrado << std::endl;
}

int main() {
    std::string mensaje = "Este es un mensaje secreto que quiero cifrar.";
    cifrar_y_descifrar(mensaje);
    return 0;
}

