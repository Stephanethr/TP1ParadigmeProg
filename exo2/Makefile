CC = gcc
CFLAGS = -Wall -Wextra -g  # Options de compilation

# Liste des fichiers sources
SRCS = main.c pile.c

# Liste des fichiers objets correspondant aux fichiers sources
OBJS = $(SRCS:.c=.o)

# Nom de l'exécutable à générer
EXEC = pile

# Règle pour générer l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Règle générique pour la compilation des fichiers sources en fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)
