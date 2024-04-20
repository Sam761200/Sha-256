### Hashage de Mot de Passe avec SHA-256 et OpenSSL
Ce projet illustre comment hacher un mot de passe en utilisant l'algorithme SHA-256 avec la bibliothèque OpenSSL. C'est un exemple basique destiné à l'apprentissage et ne doit pas être utilisé tel quel dans un environnement de production.

## Prérequis
Vous aurez besoin d'OpenSSL installé sur votre système. Pour l'installation d'OpenSSL, consultez la documentation officielle.

## Compilation
Compilez le code avec la commande suivante (remplacez sha256_hash.c par le nom de votre fichier source) :
```bash
gcc sha256_hash.c -o sha256_hash -lcrypto
```
## Exécution
Exécutez le programme compilé :
```bash
./sha256_hash
```
Cela affichera le hachage SHA-256 du mot de passe codé en dur (monSuperMotDePasse123).

## Exemple de Sortie
```bash 
Hashed password: 6f2e3382df07b03c72c5a53e29e84b4344f48e271e084b2b2b4aed09a9a6e33b
```
##Considérations de Sécurité

Mot de passe en dur: Le mot de passe est stocké directement dans le code source. En production, les mots de passe doivent être obtenus de manière sécurisée à partir de l'utilisateur et jamais stockés en clair.

Absence de sel: Ce code n'implémente pas l'usage de sel. Un sel aléatoire devrait être généré et combiné avec le mot de passe avant le hachage pour renforcer la sécurité contre les attaques par dictionnaire.

Nombre d'itérations: Ce code utilise un nombre d'itérations par défaut pour SHA-256. Un nombre plus élevé d'itérations devrait être utilisé pour augmenter le coût et le temps de calcul nécessaires pour craquer le hachage.

## Avertissement
Ce code est uniquement à des fins d'apprentissage et ne doit pas être utilisé dans un environnement de production sans mettre en œuvre des mesures de sécurité appropriées. Envisagez d'utiliser une bibliothèque ou un framework de hachage de mot de passe sécurisé pour le stockage des mots de passe dans le monde réel.

## Licence
Ce projet est distribué sous la licence MIT. Voir le fichier LICENSE pour plus d'informations.
