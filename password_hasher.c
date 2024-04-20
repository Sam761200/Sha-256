#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    // Le mot de passe à hasher
    char password[] = "monSuperMotDePasse123";

    // Buffer pour stocker le hash en sortie
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    // Initialiser la librairie OpenSSL
    OpenSSL_add_all_digests();

    // Créer un pointeur pour le contexte de digest
    EVP_MD_CTX *mdctx;

    // Créer et initialiser le contexte
    if ((mdctx = EVP_MD_CTX_new()) == NULL)
    {
        perror("EVP_MD_CTX_new failed");
        return 1;
    }

    // Initialiser le contexte pour calculer le hash
    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL))
    {
        perror("EVP_DigestInit_ex failed");
        return 1;
    }

    // Fournir le mot de passe à hasher
    if (1 != EVP_DigestUpdate(mdctx, password, strlen(password)))
    {
        perror("EVP_DigestUpdate failed");
        return 1;
    }

    // Obtenir le hash final
    if (1 != EVP_DigestFinal_ex(mdctx, hash, &hash_len))
    {
        perror("EVP_DigestFinal_ex failed");
        return 1;
    }

    // Nettoyer
    EVP_MD_CTX_free(mdctx);

    // Afficher le hash
    printf("Hashed password: ");
    for (int i = 0; i < hash_len; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
