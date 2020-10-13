#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "salsa20.h"
#include "sodium.h"

/*Este ejemplo encripta y desencripta un bloque de texto de 64 bytes
utilizando key y nonce aleatorios a través de la librería sodium.h

Codigo basado en implementación de https://github.com/alexwebr */

int main()
{

	uint8_t result_init;
	uint8_t data[] = { "Este es un ejemplo de encriptacion de datos utilizando  SALSA20" };

	result_init = sodium_init();

	uint8_t key[16] = { 0 };
	uint8_t nonce[8] = { 0 };

	randombytes_buf(key, sizeof(key));
	randombytes_buf(nonce, sizeof(nonce));

	if (result_init == -1) {
		return 1;
	}

	printf("Plaintext: %s \r\r\n", data);
	printf("Tamano: %i \r\r\n", sizeof(data));

	if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, sizeof(data)) == S20_SUCCESS)
	{
		printf("Encriptado: %s \r\r\n", data);
	}
		

	if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, sizeof(data)) == S20_SUCCESS)
	{
		printf("Desencriptado: %s \r\n", data);
	}		

	gets();

	//return 0;
}
