#!/usr/bin/python3


"""
    Calcule le nombre minimal d'opérations de copie et de collage
    pour décomposer
    un nombre entier positif n, et affiche chaque
    opération effectuée.
"""


def minOperations(n):
    # Vérifie si n est inférieur ou égal à zéro
    if  n <= 0:
        return 0

    # Initialise le nombre total d'opérations et le facteur courant à 2
    operations = 0
    current_factor = 2

    # Boucle principale : continue tant que n est supérieur à 1
    while n > 1:
        # Boucle interne : recherche le plus petit facteur premier de n
        while n % current_factor == 0:
            # Effectue une opération de copie et colle avec le facteur courant
            n //= current_factor
            operations += current_factor

        # Passe au facteur suivant
        current_factor += 1

    # Retourne le nombre total d'opérations effectuées
    return operations
